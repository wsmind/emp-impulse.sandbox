#ifndef __ELEMENT_HPP__
#define __ELEMENT_HPP__

#include <game/GameObject.hpp>

namespace game {

class World;

class Element: public GameObject
{
	public:
		Element(World *world, std::string name);
		~Element();
		
		virtual void update(float elapsedTime);
		virtual void executeAction(std::string action);
	
	private:
		World *world;
		std::string name;
		
		float time;
};

} // game namespace

#endif // __ELEMENT_HPP__
