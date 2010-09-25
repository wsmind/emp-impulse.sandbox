#include <scene/Scene.hpp>

namespace scene {

Scene::Scene()
{
	this->postProcess = true;
}

Scene::~Scene()
{
}

void Scene::activatePostProcessing(bool enable)
{
	this->postProcess = enable;
}

void Scene::setFadeFactor(float factor)
{
}

} // scene namespace
