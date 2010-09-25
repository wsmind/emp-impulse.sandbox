// entry point

#include <scene/Scene.hpp>
#include <scene/AnimatedSprite.hpp>

using namespace scene;

int main()
{
	//SceneWindow *window = new SceneWindow(1024, 768, false);
	
	scene::Scene plopScene;
	scene::AnimatedSprite *sprite1;
	sprite1 = plopScene.createSprite("sprite1.png");
	scene::AnimatedSprite *sprite2;
	sprite2 = plopScene.createSprite("sprite2.png");
	
	plopScene.redraw();
	
	plopScene.deleteSprite(sprite1);
	
	plopScene.redraw();
	
	plopScene.deleteSprite(sprite2);
	
	//delete window;
	
	return 0;
}

