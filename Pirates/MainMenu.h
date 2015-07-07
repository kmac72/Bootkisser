#include "SFHelper.cpp"
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>   //for debugging purposes

using namespace std;

class MainMenu {
    
    sf::RenderWindow* window;
    
    int width, height;

    vector<sf::Text> texts;
   
    vector<sf::Font> fonts;
 
    //Maps which manage buttons (string keys correspond to filenames)
    map<string, sf::RectangleShape> buttons;
    map<string, sf::Texture> btnTexts;
   
    //Maps which manage animated sprites (string keys correspond to filenames)
    map<string, sf::Sprite> sprites;
    map<string, vector<sf::Texture> > animeTexts;
    
    //Maps which manage image sprites (background, objects, etc.)
    map<string, sf::Sprites> images;
    map<string, sf::Texture> imageTexts;
    //vector<sf::Texture> textures;
    //vector<sf::Sprite> images;

    string animeSprite;

public:
    
    MainMenu();
    
    void initComponents();
    
    void display();
    
    void run();
    
    void close();
   
    void addSprite(string n); 
};
