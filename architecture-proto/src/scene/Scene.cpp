#include <scene/Scene.hpp>
#include <SFML/Graphics.hpp>

namespace scene {

Scene::Scene()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1024, 768), "Implop");
	this->postProcess = true;
}

Scene::~Scene()
{
	delete this->window;
}

void Scene::activatePostProcessing(bool enable)
{
	this->postProcess = enable;
}

void Scene::setFadeFactor(float factor)
{
}

scene::AnimatedSprite *Scene::createSprite(std::string filename)
{
	scene::AnimatedSprite *sprite = new scene::AnimatedSprite(filename);
	this->sprites.push_back(sprite);
	return sprite;
}

void Scene::deleteSprite(scene::AnimatedSprite * sprite)
{
	this->sprites.remove(sprite);
}

void Scene::redraw()
{
	// Clear the screen
	this->window->Clear();

	std::list<scene::AnimatedSprite *>::iterator i; 
	for(i=this->sprites.begin(); i != this->sprites.end(); ++i)
	{
		(*i)->drawSprite(this->window);
	}

	// Display window
	this->window->Display();
}

} // scene namespace
