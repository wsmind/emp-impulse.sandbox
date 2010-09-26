#include <scene/Scene.hpp>
#include <scene/InputState.hpp>
#include <SFML/Graphics.hpp>

namespace scene {

Scene::Scene()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1024, 768), "Implop");
	this->postProcess = true;
	
	this->inputState = new InputState;
}

Scene::~Scene()
{
	delete this->inputState;
	delete this->window;
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
	delete sprite;
}

void Scene::activatePostProcessing(bool enable)
{
	this->postProcess = enable;
}

void Scene::setFadeFactor(float factor)
{
}

bool Scene::pollEvents()
{
	// Process events
	sf::Event event;
	while (this->window->GetEvent(event))
	{
		// Close window : exit
		if (event.Type == sf::Event::Closed)
		{
			this->window->Close();
			return true;
		}
	}
	
	// Update input state
	const sf::Input &input = this->window->GetInput();
	this->inputState->left = input.IsKeyDown(sf::Key::Left);
	this->inputState->right = input.IsKeyDown(sf::Key::Right);
	this->inputState->jump = input.IsKeyDown(sf::Key::Up);
	this->inputState->action = input.IsKeyDown(sf::Key::Space);
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

const InputState *Scene::getInputState() const
{
	return this->inputState;
}

} // scene namespace
