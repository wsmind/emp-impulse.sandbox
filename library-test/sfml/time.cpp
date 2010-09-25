#include <SFML/Window.hpp>
#include <iostream>

int main()
{
    std::cout << "Plop !" << std::endl;

	sf::Clock clock1;
	clock1.Reset();
    
    sf::Clock clock2;
    clock2.Reset();
    
    sf::Window windy(sf::VideoMode(800, 600, 32), "Plop");
	while (windy.IsOpened())
	{
		sf::Event event;
		while (windy.GetEvent(event))
		{
			if (event.Type == sf::Event::Closed)
				windy.Close();
			
			if ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::Escape))
				windy.Close();
		}

		std::cout << "\nElapsed time since the start of the application: " << clock1.GetElapsedTime() << "s" << std::endl;
		std::cout << "Elapsed time since the last frame: " << clock2.GetElapsedTime() << "s" << std::endl;
		clock2.Reset();
		
		windy.Display();
	}

    return EXIT_SUCCESS;
}

