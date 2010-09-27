#include <game/Fader.hpp>

#include <iostream>

#include <game/Event.hpp>
#include <game/FieldDescriptorList.hpp>
#include <game/World.hpp>
#include <scene/Scene.hpp>

namespace game {

Fader::Fader(World *world, std::string name)
{
	this->world = world;
	this->name = name;
	
	this->fade = 0.0f;
	this->speed = 0.0f;
}

Fader::~Fader()
{
}

void Fader::declareFields(FieldDescriptorList *list)
{
	list->declareNumber("fade", &this->fade, 0.0f);
	list->declareNumber("speed", &this->speed, 0.0f);
}

void Fader::update(float elapsedTime)
{
	this->fade += this->speed * elapsedTime;
	if (this->fade < 0.0f)
		this->fade = 0.0f;
	if (this->fade > 1.0f)
		this->fade = 1.0f;
	
	// scene update
	this->world->getScene()->setFadeFactor(this->fade);
}

void Fader::handleEvent(std::string sender, Event *event)
{
	if (event->name == "fade")
		this->speed = 1.0f / (float)event->data["duration"].toNumber();
	
	if (event->name == "unfade")
		this->speed = -1.0f / (float)event->data["duration"].toNumber();
}

} // game namespace

