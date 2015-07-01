#include "MainMenu.h"

MainMenu::MainMenu() {
    
    width = 800;
    height = 600;
    
    window = new sf::RenderWindow(sf::VideoMode(width, height), "Pirates!");
    window->setKeyRepeatEnabled(false);
}

void MainMenu::initComponents() {
    
    sf::Font titleFont;
    titleFont.loadFromFile("fonts/ADRESACK.TTF");
    sf::Text* title = new sf::Text("PIRATES", titleFont, 50);
    title->setPosition(SFHelper::centerW(title, width, height));
    texts.push_back(title);
    
    sf::Texture pirateImg;
    pirateImg.loadFromFile("sprite1.png");
    sf::Sprite* pirateSprite = new sf::Sprite();
    pirateSprite->setTexture(pirateImg);
    sprites.push_back(pirateSprite);
    
    sf::RectangleShape* load = new sf::RectangleShape(sf::Vector2f(100, 40));
    load->setPosition(sf::Vector2f(100, 100));
    sf::IntRect* loadButton = new sf::IntRect(100, 100, 100, 40);
    buttons.push_back(loadButton);
    rects.push_back(load);
}

void MainMenu::display() {
    
    window->clear();
    window->draw(*texts[0]);
    window->draw(*sprites[0]);
    window->draw(*rects[0]);
    window->display();
}

void MainMenu::run() {
    
    while (window->isOpen()) {
    
        sf::Event event;
        while (window->pollEvent(event)) {
            
            if (event.type == sf::Event::Closed)
                window->close();
                
            if(event.type == sf::Event::KeyPressed) {
                
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                     sprites[0]->move(-10,0);
                 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                     sprites[0]->move(10,0);
                 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                     sprites[0]->move(0,-10);
                 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                     sprites[0]->move(0,10);
            }
            
            if(event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                
                sf::Vector2i position = sf::Mouse::getPosition();
                
                if(buttons[0]->contains(position.x, position.y)) {
                    window->close();
                }

                // ADD MORE BUTTONS HERE BY COPYING IF STATEMENT ABOVE
            }
        }
        display();
    }
}

void MainMenu::close() {
    
    window->close();
}