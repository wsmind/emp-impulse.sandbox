#ifndef __SCENE_HPP__
#define __SCENE_HPP__

#include <list>

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
		
	private:
		//std::list<Node *> nodes;
		
		bool postProcess;
};

} // scene namespace

#endif // __SCENE_HPP__
