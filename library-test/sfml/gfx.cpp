#include <SFML/Graphics.hpp>
#include <iostream>


int main()
{
	std::cout << "Plop the graphic world !" << std::endl;

	// Create the main rendering window
	sf::RenderWindow rendy(sf::VideoMode(800, 600, 32), "SFML Graphics");
	//sf::RenderWindow rendy(sf::VideoMode::GetMode(0), "SFML Graphics", sf::Style::Fullscreen);
	
	// Load the sprite image from a file
	sf::Image mush;
	if(!mush.LoadFromFile("mushroom.jpg"))
	{
		std::cout << "Error loading the mushroom" << std::endl;
	}
	
	// Create the sprite
	sf::Sprite flyingMushroom;
	flyingMushroom.SetImage(mush);
	flyingMushroom.Resize(400, 300);
	flyingMushroom.SetPosition(200.f, 150.f);
	
	sf::PostFX fx;
	sf::PostFX fx2;
	if (!fx.LoadFromFile("fx/blur_horizontal.sfx"))
		std::cout << "You shall not load (the effect) !" << std::endl;
	if (!fx2.LoadFromFile("fx/blur_vertical.sfx"))
		std::cout << "You shall not load (the effect) !" << std::endl;
	fx.SetTexture("framebuffer", NULL);
	fx2.SetTexture("framebuffer", NULL);
	
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
		if (rendy.GetInput().IsKeyDown(sf::Key::Left)) 	flyingMushroom.Move(-200 * elapsedTime, 0);
		if (rendy.GetInput().IsKeyDown(sf::Key::Right))	flyingMushroom.Move( 200 * elapsedTime, 0);
		if (rendy.GetInput().IsKeyDown(sf::Key::Up))	flyingMushroom.Move(0, -200 * elapsedTime);
		if (rendy.GetInput().IsKeyDown(sf::Key::Down))	flyingMushroom.Move(0,  200 * elapsedTime);
		flyingMushroom.Rotate(10 * elapsedTime);
		
		// Clear the screen (fill it with black color)
		rendy.Clear(sf::Color(100, 100, 200));
		
		rendy.Draw(flyingMushroom);
		
		// apply post-effect
		rendy.Draw(fx);
		rendy.Draw(fx2);
		/*rendy.Draw(fx);
		rendy.Draw(fx2);
		rendy.Draw(fx);
		rendy.Draw(fx2);
		rendy.Draw(fx);
		rendy.Draw(fx2);
		rendy.Draw(fx);
		rendy.Draw(fx2);*/
		
		// Display window contents on screen
		rendy.Display();
	}
	
	return EXIT_SUCCESS;
}

