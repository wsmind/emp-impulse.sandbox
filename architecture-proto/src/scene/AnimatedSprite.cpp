#include <scene/AnimatedSprite.hpp>
#include <iostream>

namespace scene {

AnimatedSprite::AnimatedSprite(std::string filename)
{
	this->image = new sf::Image;
	this->image->LoadFromFile(filename);
	
	this->sprite = new sf::Sprite(*this->image);
}

AnimatedSprite::~AnimatedSprite() 
{
	delete this->sprite;
	delete this->image;
}

void AnimatedSprite::drawSprite(sf::RenderWindow *window)
{
	window->Draw(*this->sprite);
}

void AnimatedSprite::setPosition(float x, float y)
{
	this->sprite->SetPosition(x, y);
}

} // scene namespace
