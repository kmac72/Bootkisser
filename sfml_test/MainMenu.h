#include "SFHelper.cpp"
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

class MainMenu {
    
    sf::RenderWindow* window;
    
    int width, height;
    
    vector<sf::Text*> texts;
    
    vector<sf::IntRect*> buttons;
    
    vector<sf::RectangleShape*> rects;
    
    vector<sf::Sprite*> sprites;
    
public:
    
    MainMenu();
    
    void initComponents();
    
    void display();
    
    void run();
    
    void close();
    
};
