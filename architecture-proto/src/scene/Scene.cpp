#include <scene/Scene.hpp>
#include <scene/InputState.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>

namespace scene {

Scene::Scene()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1024, 768), "Implop");
	
	this->postProcess = true;
	this->postFx = new sf::PostFX;
	std::string shader =
		"texture framebuffer\n"
		"float multiplier\n"
		"\n"
		"effect\n"
		"{\n"
		"	vec4 color = framebuffer(_in);\n"
		"	_out = vec4(color.r * multiplier, color.g * multiplier, color.b * multiplier, 1.0);\n"
		"}\n";
	this->postFx->LoadFromMemory(shader);
	this->postFx->SetTexture("framebuffer", NULL);
	this->setFadeFactor(0.0f);
	
	this->inputState = new InputState;
}

Scene::~Scene()
{
	delete this->postFx;
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
	this->fadeFactor = factor;
	//std::cout << "changing fade value to " << factor << std::endl;
	this->postFx->SetParameter("multiplier", 1.0f - fadeFactor);
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
	
	return false;
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
	
	// post-process
	if (this->postProcess)
		this->window->Draw(*this->postFx);

	// Display window
	this->window->Display();
}

const InputState *Scene::getInputState() const
{
	return this->inputState;
}

} // scene namespace
