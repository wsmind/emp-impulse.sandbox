#ifndef __ANIMATEDSPRITE_HPP__
#define __ANIMATEDSPRITE_HPP__

#include <string>
#include <SFML/Graphics.hpp>

namespace scene {

class AnimatedSprite
{
	public:
		AnimatedSprite(std::string filename);
		~AnimatedSprite();
		void drawSprite(sf::RenderWindow *window);
	
	private:
		sf::Image *image;
		sf::Sprite *sprite;
};

} // scene namespace

#endif // __ANIMATEDSPRITE_HPP__
