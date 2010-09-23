#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>

#define SCREEN_WIDTH 60
#define SCREEN_HEIGHT 20

struct Vector2
{
	float x;
	float y;
	Vector2(float x, float y) : x(x), y(y) {}
};

struct Field
{
	Vector2 emitter;
	Vector2 orientation;
	float angle;
	float power;
	Field(Vector2 emitter, Vector2 orientation, float angle, float power) : emitter(emitter), orientation(orientation), angle(angle), power(power) {}
};

static std::list<Field> windFields;

static Vector2 getWind(Vector2 point)
{
	Vector2 ret(0, 0);
	for (std::list<Field>::iterator it = windFields.begin(); it != windFields.end(); ++it)
	{
		Vector2 distance(point.x - it->emitter.x, point.y - it->emitter.y);
		float angle = atan2(distance.y, distance.x) - atan2(it->orientation.y, it->orientation.x);
		while (angle < - M_PI)
		{
			angle += 2.0f * M_PI;
		}
		while (angle > M_PI)
		{
			angle -= 2.0f * M_PI;
		}
		
		if (fabs(angle) < it->angle)
		{
			float distanceNorm2 = distance.x * distance.x + distance.y * distance.y;
			float coefficient = (1 - fabs(angle / it->angle)) * (1 - (distanceNorm2) / (it->orientation.x * it->orientation.x + it->orientation.y * it->orientation.y));
			
			if (coefficient > 0)
			{
				ret.x += distance.x / sqrtf(distanceNorm2) * it->power * coefficient;
				ret.y += distance.y / sqrtf(distanceNorm2) * it->power * coefficient;
			}
		}
	}
	return ret;
};

int main(int argc, char **argv)
{
	windFields.push_back(Field(Vector2(5, 10), Vector2(50, 0), M_PI / 16.0f, 9));
	
	for (int i = 0; i < SCREEN_HEIGHT; ++i)
	{
		for (int j = 0; j < SCREEN_WIDTH; ++j)
		{
			Vector2 wind = getWind(Vector2(j, i));
			int norm = sqrtf(wind.x * wind.x + wind.y * wind.y);
			if (norm < 0)
			{
				norm = 0;
			}
			else if (norm > 9)
			{
				norm = 9;
			}
			std::cout << (char)('0' + norm);
		}
		std::cout << std::endl;
	}
	
	return EXIT_SUCCESS;
}
