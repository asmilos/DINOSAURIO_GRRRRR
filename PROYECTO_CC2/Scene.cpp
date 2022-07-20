#include "Scene.h"

Scene::Scene(RenderWindow * window) {
	this->window = window;
	event = new Event;
}

Scene::Scene() {

}

Scene::~Scene() {

}

void Scene::loop(){}
void Scene::events(){}