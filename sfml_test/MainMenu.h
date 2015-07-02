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
 
    vector<sf::IntRect> buttons;
    
    vector<sf::RectangleShape> rects;
    
    vector<sf::Sprite> sprites;
    
    vector<sf::Texture> textures;

public:
    
    MainMenu();
    
    void initComponents();
    
    void display();
    
    void run();
    
    void close();
    
};
