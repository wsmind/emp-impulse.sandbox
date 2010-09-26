#ifndef __SCENE_HPP__
#define __SCENE_HPP__

#include <list>
#include <string>
#include <scene/AnimatedSprite.hpp>

#include <SFML/Graphics.hpp>

namespace scene {

class InputState;

class Scene
{
	public:
		Scene();
		~Scene();
		
		// node management
		// everything technical with a position/rotation/scale
		// by technical i mean non-gameplay objects: sprites, sounds, etc., as
		// opposed to player, elements, tree, etc. which will go to higher level
		// packages (i.e game).
		scene::AnimatedSprite *createSprite(std::string filename);
		void deleteSprite(scene::AnimatedSprite *sprite);
		
		// other parameters (here trivial post-processing)
		void activatePostProcessing(bool enable);
		void setFadeFactor(float factor); // 0 is not faded, 1 is full black
		
		// window-level actions
		bool pollEvents(); // update input state; return true if the window was closed
		void redraw();
		
		const InputState *getInputState() const;
		
	private:
		std::list<scene::AnimatedSprite *> sprites;
		
		sf::RenderWindow *window;
		
		// post effects
		bool postProcess;
		float fadeFactor;
		sf::PostFX *postFx;
		
		InputState *inputState;
};

} // scene namespace

#endif // __SCENE_HPP__
