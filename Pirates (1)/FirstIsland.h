#include "SFHelper.cpp"
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>   //for debugging purposes

using namespace std;

class FirstIsland {
    
    sf::RenderWindow* window;
    
    int width, height;

    //Maps which manage text in window
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

    //Determines which sprite is currently animated
    string animeSprite;

public:
    
    FirstIsland();
    
    void initComponents();
    
    void display();
    
    void run();
    
    void close();

    void move(sf::Vector2i position);
};
