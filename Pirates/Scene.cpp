#include "Scene.h"

using namespace std;

Scene::Scene() {

	animeSprite = "none";
	bounded = false;

	bounds = new sf::ConvexShape(4);;
    bounds->setPosition(sf::Vector2f(0,0));
    bounds->setPoint(0, sf::Vector2f(0,0));
    bounds->setPoint(1, sf::Vector2f(0,600));
    bounds->setPoint(3, sf::Vector2f(800,600));
    bounds->setPoint(2, sf::Vector2f(800,0));
}