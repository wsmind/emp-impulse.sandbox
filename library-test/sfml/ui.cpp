#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>


void makeRoundedRectangle(sf::Shape *shape, float x1, float y1, float x2, float y2, float radius)
{
	float innerDistance =  sqrt(2.0f);
	float cornerX[4] = {x1 + innerDistance, x2 - innerDistance, x2 - innerDistance, x1 + innerDistance};
	float cornerY[4] = {y1 + innerDistance, y1 + innerDistance, y2 - innerDistance, y2 - innerDistance};
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			float angle = M_PI + (float)i * M_PI * 0.5f + (float)j * M_PI * 0.5f / 3.0f;
			shape->AddPoint(cornerX[i] + cosf(angle) * radius, cornerY[i] + sinf(angle) * radius, sf::Color(i * 255 / 4, i * 255 / 4, 255 - i * 255 / 4), sf::Color(255, 0, 0));
		}
	}
}

int main()
{
	std::cout << "Plop the graphic world !" << std::endl;
	
	// Create the main rendering window
	sf::RenderWindow rendy(sf::VideoMode(1024, 768, 32), "SFML Graphics");
	
	// Create the sprite
	/*sf::Sprite flyingMushroom;
	flyingMushroom.SetImage(mush);
	flyingMushroom.Resize(400, 300);
	flyingMushroom.SetPosition(200.f, 150.f);*/
	
	sf::Shape shape;
	makeRoundedRectangle(&shape, 100.0f, 100.0f, 400.0f, 500.0f, 10.0f);
	shape.SetOutlineWidth(10.0f);
	
	sf::Font font;
	font.LoadFromFile("FreeSans.ttf");
	
	sf::String str("ploooop", font, 100.0f);
	str.SetPosition(250.0f - str.GetCharacterPos(7).x * 0.5f, 200.0f);
	std::cout << "chr pos: " << str.GetCharacterPos(2).x << std::endl;
	
	sf::Clock clock;
	int fps = 0;
	
	// Start game loop
	while (rendy.IsOpened())
	{
		float elapsedTime = rendy.GetFrameTime();
		
		// FPS
		fps++;
		if (clock.GetElapsedTime() >= 1.0f)
		{
			clock.Reset();
			std::cout << "FPS: " << fps << std::endl;
			fps = 0;
		}
		
		// Process events
		sf::Event event;
		while (rendy.GetEvent(event))
		{
			// Close window : exit
			if (event.Type == sf::Event::Closed)
				rendy.Close();
		}
		
		//Move the sprite
		/*if (rendy.GetInput().IsKeyDown(sf::Key::Left)) 	flyingMushroom.Move(-200 * elapsedTime, 0);
		if (rendy.GetInput().IsKeyDown(sf::Key::Right))	flyingMushroom.Move( 200 * elapsedTime, 0);
		if (rendy.GetInput().IsKeyDown(sf::Key::Up))	flyingMushroom.Move(0, -200 * elapsedTime);
		if (rendy.GetInput().IsKeyDown(sf::Key::Down))	flyingMushroom.Move(0,  200 * elapsedTime);
		flyingMushroom.Rotate(10 * elapsedTime);*/
		
		// Clear the screen (fill it with black color)
		rendy.Clear(sf::Color(100, 100, 200));
		
		rendy.Draw(shape);
		rendy.Draw(str);
		
		// Display window contents on screen
		rendy.Display();
	}
	
	return EXIT_SUCCESS;
}

