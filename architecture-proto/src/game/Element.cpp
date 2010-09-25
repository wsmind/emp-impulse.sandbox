#include <game/Element.hpp>
#include <game/World.hpp>
#include <scene/Scene.hpp>
//#include <scene/AnimatedSprite.hpp>

using namespace scene;

namespace game {

Element::Element(World *world, std::string name)
{
	this->world = world;
	this->name = name;
	this->time = 0.0f;
	
	// creating water sprite
	Scene *gameScene = world->getScene();
	//AnimatedSprice *sprite = gameScene->createSprite("water.png");
}

Element::~Element()
{
}

void Element::update(float elapsedTime)
{
	this->time += elapsedTime;
	if (this->time > 1.0f)
	{
		this->time -= 1.0f;
		this->world->sendEvent(this->name, "test");
	}
}

void Element::executeAction(std::string action)
{
	if (action == "explode")
		this->world->sendEvent(this->name, "test");
}

} // game namespace
