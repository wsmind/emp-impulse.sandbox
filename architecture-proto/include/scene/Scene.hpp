#ifndef __SCENE_HPP__
#define __SCENE_HPP__

#include <list>
#include <string>
#include <SFML/Graphics.hpp>
#include <scene/AnimatedSprite.hpp>

namespace scene {

class Scene
{
	public:
		Scene();
		~Scene();
		
		// node managemnt
		// everything technical with a position/rotation/scale
		// by technical i mean non-gameplay objects: sprites, sounds, etc., as
		// opposed to player, elements, tree, etc. which will go to higher level
		// packages (i.e game).
		
		// other parameters (here trivial post-processing)
		void activatePostProcessing(bool enable);
		void setFadeFactor(float factor); // 0 is not faded, 1 is full black
		
		scene::AnimatedSprite *createSprite(std::string filename);
		void deleteSprite(scene::AnimatedSprite *sprite);
		
		// Redraw scene
		void redraw();
		
	private:
		//std::list<Node *> nodes;
		std::list<scene::AnimatedSprite *> sprites;
		sf::RenderWindow *window;
		bool postProcess;
};

} // scene namespace

#endif // __SCENE_HPP__
