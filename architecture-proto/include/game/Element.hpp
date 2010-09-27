#ifndef __ELEMENT_HPP__
#define __ELEMENT_HPP__

#include <game/GameObject.hpp>

namespace scene { class AnimatedSprite; }

namespace game {

class World;
class FieldDescriptorList;

class Element: public GameObject
{
	public:
		Element(World *world, std::string name);
		~Element();
		
		virtual void declareFields(FieldDescriptorList *list);
		virtual void update(float elapsedTime);
		virtual void handleEvent(std::string sender, Event *event);
	
	private:
		World *world;
		std::string name;
		scene::AnimatedSprite *sprite;
		
		float time; // just for regular event sending
		
		float x;
		float y;
		float yspeed;
};

} // game namespace

#endif // __ELEMENT_HPP__

