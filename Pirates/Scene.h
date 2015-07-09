#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

struct Scene {
	
	//Maps which manage text in the scene
	map<string, sf::Text> texts;
    map<string, sf::Font> fonts;
 
    //Maps which manage buttons (string keys correspond to filenames)
    map<string, sf::RectangleShape> buttons;
    map<string, sf::Texture> btnTexts;
   
    //Maps which manage animated sprites (string keys correspond to filenames)
    map<string, sf::Sprite> sprites;
    map<string, vector<sf::Texture> > animeTexts;
    
    //Maps which manage image sprites (background, objects, etc.)
    map<string, sf::Sprite> images;
    map<string, sf::Texture> imageTexts;

   	//Name of sprite currently being animated
    string animeSprite;

    bool bounded;
    sf::ConvexShape* bounds;

    Scene();
};