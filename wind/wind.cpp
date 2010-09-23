#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>

#define SCREEN_WIDTH 60
#define SCREEN_HEIGHT 20

struct Vector2
{
	float x;
	float y;
	Vector2() {}
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

struct Particle
{
	sf::Sprite sprite;
	Vector2 position;
	Vector2 gravitySpeed;
};

static float gravity = 50.0f;

int main(int argc, char **argv)
{
	windFields.push_back(Field(Vector2(100, 500), Vector2(600, -200), M_PI / 8.0f, 1000.0f));

	// Create the main rendering window
	sf::RenderWindow window(sf::VideoMode(800, 600, 32), "SFML Graphics");

	// Load the sprite image from a file
	sf::Image particleImage;
	if (!particleImage.LoadFromFile("particle.png"))
	{
		std::cout << "Error loading the particle." << std::endl;
	}

	std::list<Particle> particles;

	float timeout = 0;

	// Start game loop
	while (window.IsOpened())
	{
		float elapsedTime = window.GetFrameTime();
		
		// Process events
		sf::Event event;
		while (window.GetEvent(event))
		{
			// Close window : exit
			if (event.Type == sf::Event::Closed)
			{
				window.Close();
			}
		}

		timeout += elapsedTime;
		if (timeout > 1.0f)
		{
			Particle particle;
			particle.sprite.SetImage(particleImage);
			particle.position.x = rand() / (float)RAND_MAX * 800.0f;
			particle.position.y = 0;
			particle.gravitySpeed.x = 0;
			particle.gravitySpeed.y = gravity * (0.9f + 0.2f * rand() / (float)RAND_MAX);
			particles.push_back(particle);
			timeout = 0;
		}

		// Clear the screen (fill it with zhite color)
		window.Clear(sf::Color(255, 255, 255));

		for (std::list<Particle>::iterator it = particles.begin(); it != particles.end(); ++it)
		{
			Vector2 wind = getWind(it->position);
			it->position.x += (it->gravitySpeed.x + wind.x) * elapsedTime;
			it->position.y += (it->gravitySpeed.y + wind.y) * elapsedTime;
			
			it->sprite.SetPosition(it->position.x, it->position.y);
			window.Draw(it->sprite);
		}
		
		// Display window contents on screen
		window.Display();
	}

	return EXIT_SUCCESS;
}
