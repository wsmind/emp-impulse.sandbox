#include <game/Element.hpp>
#include <game/World.hpp>

namespace game {

Element::Element(World *world, std::string name)
{
	this->world = world;
	this->name = name;
	this->time = 0.0f;
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
