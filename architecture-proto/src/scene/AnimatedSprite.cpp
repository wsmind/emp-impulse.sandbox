#include <scene/AnimatedSprite.hpp>
#include <iostream>

namespace scene {

AnimatedSprite::AnimatedSprite(std::string filename)
{
	this->sprite = new sf::Sprite;
	
	sf::Image image;
	image.LoadFromFile(filename);
	this->sprite->SetImage(image);
}

AnimatedSprite::~AnimatedSprite() 
{
	delete this->sprite;
}

void AnimatedSprite::drawSprite(sf::RenderWindow *window)
{
	window->Draw(*this->sprite);
}

} // scene namespace
