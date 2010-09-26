#ifndef __FADER_HPP__
#define __FADER_HPP__

#include <game/GameObject.hpp>

namespace game {

class World;

class Fader: public GameObject
{
	public:
		Fader(World *world, std::string name);
		~Fader();
		
		virtual void update(float elapsedTime);
		virtual void handleEvent(std::string sender, Event *event);
	
	private:
		World *world;
		std::string name;
		
		float fade;
		float speed;
};

} // game namespace

#endif // __FADER_HPP__

