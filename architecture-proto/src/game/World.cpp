#include <game/World.hpp>
#include <game/GameObject.hpp>
#include <game/Element.hpp>
#include <game/Event.hpp>
#include <game/Fader.hpp>
#include <game/FieldDescriptorList.hpp>
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
	
	// test print object state
	GameObjectMap::iterator i;
	for (i = this->objects.begin(); i != this->objects.end(); i++)
	{
		std::string name = i->first;
		GameObject *object = i->second;
		
		FieldDescriptorList list;
		list.empty();
		object->declareFields(&list);
		
		std::cout << "Object '" << name << "'" << std::endl;
		
		const FieldDescriptorList::FieldDescriptorMap *descriptors = list.getDescriptors();
		FieldDescriptorList::FieldDescriptorMap::const_iterator j;
		for (j = descriptors->begin(); j != descriptors->end(); j++)
		{
			const FieldDescriptor &desc = j->second;
			Variant value;
			switch (desc.type)
			{
				case Variant::BOOLEAN: value = Variant::fromBoolean(*(bool *)desc.location); break;
				case Variant::NUMBER: value = Variant::fromNumber(*(float *)desc.location); break;
				case Variant::STRING: value = Variant::fromString(*(std::string *)desc.location); break;
			}
			std::cout << j->first << " = " << value.toString() << std::endl;
		}
		
		std::cout << std::endl;
	}
}

void World::loadMap()
{
	// create element game object
	Element *element = new Element(this, "water");
	this->objects["water"] = element;
	
	// create fader game object
	Fader *fader = new Fader(this, "fader");
	this->objects["fader"] = fader;
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

