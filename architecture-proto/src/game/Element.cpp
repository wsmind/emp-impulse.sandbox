#include <game/Element.hpp>
#include <game/World.hpp>
#include <game/Variant.hpp>
#include <game/Event.hpp>
#include <scene/AnimatedSprite.hpp>
#include <scene/Scene.hpp>
#include <scene/InputState.hpp>
#include <iostream>

using namespace scene;

namespace game {

Element::Element(World *world, std::string name)
{
	this->world = world;
	this->name = name;
	this->time = 0.0f;
	
	// creating water sprite
	Scene *gameScene = world->getScene();
	this->sprite = gameScene->createSprite("water.png"); // use a 32x32px image
	
	this->x = 0.0f;
	this->y = 0.0f;
}

Element::~Element()
{
}

void Element::update(float elapsedTime)
{
	// test event every second
	this->time += elapsedTime;
	if (this->time >= 1.0f)
	{
		this->time -= 1.0f;
		Event e("yop");
		this->world->sendEvent(this->name, "test", &e);
	}
	
	// input test
	const InputState *input = this->world->getScene()->getInputState();
	if (input->left)
		this->x -= elapsedTime * 400.0f;
	if (input->right)
		this->x += elapsedTime * 400.0f;
	
	// gravity
	this->yspeed += 2.0f * elapsedTime;
	this->y += this->yspeed;
	
	// fake collision test
	bool collision = false;
	if (this->y >= 600.0f)
	{
		collision = true;
		this->y = 600.0f;
	}
	
	if (input->jump && collision)
	{
		this->yspeed = -1.0f;
	}
	
	// move sprite
	this->sprite->setPosition(this->x, this->y);
}

void Element::handleEvent(std::string sender, Event *event)
{
	if (event->name == "explode")
	{
		Event e("plop");
		e.data["damage"] = Variant::fromNumber(42.0);
		this->world->sendEvent(this->name, "rock", &e);
	}
}

} // game namespace

