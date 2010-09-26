#include <game/World.hpp>
#include <game/GameObject.hpp>
#include <game/Element.hpp>
#include <game/Event.hpp>
#include <scene/Scene.hpp>
#include <SFML/System.hpp> // shouldn't be there
#include <iostream>

using namespace scene;

namespace game {

World::World()
{
	this->gameScene = new Scene;
	this->running = true;
}

World::~World()
{
	delete this->gameScene;
}

void World::run()
{
	sf::Clock clock;
	
	while (this->running)
	{
		float elapsedTime = clock.GetElapsedTime();
		clock.Reset();
		
		if (this->gameScene->pollEvents())
			this->running = false;
		
		GameObjectMap::iterator i;
		for (i = this->objects.begin(); i != this->objects.end(); i++)
		{
			std::string name = i->first;
			GameObject *object = i->second;
			object->update(elapsedTime);
		}
		
		this->gameScene->redraw();
		//this->running = false;
	}
}

void World::loadMap()
{
	// create element game object
	Element *element = new Element(this, "water");
	this->objects["water"] = element;
}

scene::Scene *World::getScene()
{
	return this->gameScene;
}

void World::sendEvent(std::string sender, std::string target, Event *event)
{
	//std::cout << "World: sending event '" << event->name << "' from " << sender << " to " << target << std::endl;
	GameObjectMap::iterator i = this->objects.find(target);
	if (i != this->objects.end())
	{
		GameObject *targetObject = i->second;
		targetObject->handleEvent(sender, event);
	}
}

} // game namespace

