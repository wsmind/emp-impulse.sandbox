#include <SFML/Graphics.hpp>
#include <iostream>


int main()
{

	//speed coefficient
	float levelSpeed = 200.0f;

	// Create the main rendering window
	sf::RenderWindow rendy(sf::VideoMode::GetMode(0), "SFML Graphics", sf::Style::Fullscreen);
	
	// Load the sprite images from files
	sf::Image back;
	back.LoadFromFile("background.jpg");
	sf::Image belt;
	belt.LoadFromFile("belt.png");
	
	// Create the sprites
	sf::Sprite background;
	background.SetImage(back);
	sf::Sprite belt1;
	belt1.SetImage(belt);
	sf::Sprite belt2;
	belt2.SetImage(belt);
	sf::Sprite belt3;
	belt3.SetImage(belt);
	sf::Sprite belt4;
	belt4.SetImage(belt);
	
	// Sprites configuration
	background.SetPosition(0.0f, -750.0f);
	belt1.SetPosition(100.0f, 500.0f);
	belt2.SetPosition(500.0f, 100.0f);
	belt3.SetPosition(1300.0f, 700.0f);
	belt4.SetPosition(1800.0f, 0.0f);
	
	// Create a view
	sf::Vector2f center(720.0f, 450.0f);
	sf::Vector2f halfSize(720.0f, 450.0f);
	sf::View view(center, halfSize);
	rendy.SetView(view);
	
	// Start game loop
	while (rendy.IsOpened())
	{
		float elapsedTime = rendy.GetFrameTime();
		
		// Process events
		sf::Event event;
		while (rendy.GetEvent(event))
		{
			// Close window : exit
			if (event.Type == sf::Event::Closed)
				rendy.Close();
			if ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::Escape))
				rendy.Close();
		}

		//Move the view and the background
		if (rendy.GetInput().IsKeyDown(sf::Key::Left))
		{
			view.Move(-levelSpeed * elapsedTime, 0.0f);
			background.Move((-levelSpeed / 2) * elapsedTime, 0.0f);
		}
		if (rendy.GetInput().IsKeyDown(sf::Key::Right))
		{
			view.Move( levelSpeed * elapsedTime, 0.0f);
			background.Move((levelSpeed / 2) * elapsedTime, 0.0f);
		}
		
		// Clear the screen (fill it with black color)
		rendy.Clear(sf::Color(100.0f, 100.0f, 200.0f));

		// Draw the sprites
		rendy.Draw(background);
		rendy.Draw(belt1);
		rendy.Draw(belt2);
		rendy.Draw(belt3);
		rendy.Draw(belt4);
		

		// Display window contents on screen
		rendy.Display();
	}

	return EXIT_SUCCESS;
}

