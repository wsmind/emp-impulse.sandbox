#include <SFML/Graphics.hpp>
#include <iostream>


int main()
{
	std::cout << "Plop the graphic world !" << std::endl;

    // Create the main rendering window
    sf::RenderWindow rendy(sf::VideoMode(800, 600, 32), "SFML Graphics");
    
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
        }

		//Move the sprite
		if (rendy.GetInput().IsKeyDown(sf::Key::Left)) 	flyingMushroom.Move(-200 * elapsedTime, 0);
		if (rendy.GetInput().IsKeyDown(sf::Key::Right))	flyingMushroom.Move( 200 * elapsedTime, 0);
		if (rendy.GetInput().IsKeyDown(sf::Key::Up))	flyingMushroom.Move(0, -200 * elapsedTime);
		if (rendy.GetInput().IsKeyDown(sf::Key::Down))	flyingMushroom.Move(0,  200 * elapsedTime);
		flyingMushroom.Rotate(100 * elapsedTime);

        // Clear the screen (fill it with black color)
        rendy.Clear(sf::Color(100, 100, 200));

		rendy.Draw(flyingMushroom);

        // Display window contents on screen
        rendy.Display();
    }

    return EXIT_SUCCESS;
}

