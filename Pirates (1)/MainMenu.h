#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>   //for debugging purposes
#include "FirstIsland.cpp"

using namespace std;

class MainMenu {
    
    sf::RenderWindow* window;
    
    int width, height;

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

    string animeSprite;

public:
    
    MainMenu();
    
    void initComponents();
    
    void display();
    
    void run();
    
    void close();
   
    void move(sf::Vector2i position);
};
