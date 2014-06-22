#include "../headers/Scene.h"

Scene::Scene()
{

}

Scene::~Scene()
{

}

Scene::Status Scene::get_status()
{
	return my_status;
}

Scene *Scene::get_scene_to_switch_to()
{
	return switch_to;
}
