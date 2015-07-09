#include "WindowTemplate.h"

//consWindowTemplatetruct window and adjust settings
WindowTemplate::WindowTemplate() {
    
    //MODIFY MAIN WINDOW PROPERTIES HERE
    width = 800;
    height = 600;
   
    animeSprite = "none";
 
    window = new sf::RenderWindow(sf::VideoMode(width, height), "Pirates!");
    window->setKeyRepeatEnabled(true);
    window->setFramerateLimit(25);
}

//initializes and stores graphical components of window
void WindowTemplate::initComponents() {

    //BUILD WINDOW USING SFHELPER CALLS HERE
    
}

//called from run() draws graphics
void WindowTemplate::display() {
    
    window->clear();
    //DRAW ITEMS BUILT FROM INITCOMPONENTS HERE
    // window->draw(images[""]);
    // window->draw(texts[""]);
    // window->draw(sprites[""]);
    // window->draw(sprites[""]);
    // window->draw(buttons[""]);
    window->display();
}

//function which loops and controls open window
//should be the same for all windows and not be modified
void WindowTemplate::run() {
    
    int step = 0;
    bool leg = false;

    while (window->isOpen()) {
    
        sf::Event event;
        while (window->pollEvent(event)) {
            
	        //close button defined
            if (event.type == sf::Event::Closed)
                window->close();
                
	        //keyboard controllers
            if(event.type == sf::Event::KeyPressed) {
                
                if(animeSprite != "none") {

                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                         sprites[animeSprite].move(-10,0);
                         if(step == 0) {
                            sprites[animeSprite].setTexture(animeTexts[animeSprite][7]);
                            step += 1;
                         } else if(step == 1) {
                            sprites[animeSprite].setTexture(animeTexts[animeSprite][6]);
                            if(leg) {
                                step += 1;
                                leg = false;
                            }
                            else {
                                step -= 1;
                                leg = true;
                            }
                         } else {
                            sprites[animeSprite].setTexture(animeTexts[animeSprite][8]);
                            step -= 1;
                         }
                     }
                     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                         sprites[animeSprite].move(10,0); 
                         if(step == 0) {
                            sprites[animeSprite].setTexture(animeTexts[animeSprite][4]);
                            step += 1;
                         } else if(step == 1) {
                            sprites[animeSprite].setTexture(animeTexts[animeSprite][3]);
                            if(leg) {
                                step += 1;
                                leg = false;
                            }
                            else {
                                step -= 1;
                                leg = true;
                            }
                         } else {
                            sprites[animeSprite].setTexture(animeTexts[animeSprite][5]);
                            step -= 1;
                         }
                     }
                     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                         sprites[animeSprite].move(0,-10);
                         if(step == 0) {
                            sprites[animeSprite].setTexture(animeTexts[animeSprite][10]);
                            step += 1;
                         } else if(step == 1) {
                            sprites[animeSprite].setTexture(animeTexts[animeSprite][9]);
                            if(leg) {
                                step += 1;
                                leg = false;
                            }
                            else {
                                step -= 1;
                                leg = true;
                            }
                         } else {
                            sprites[animeSprite].setTexture(animeTexts[animeSprite][11]);
                            step -= 1;
                         }
                     }
                     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                         sprites[animeSprite].move(0,10);
                         if(step == 0) {
                            sprites[animeSprite].setTexture(animeTexts[animeSprite][1]);
                            step += 1;
                         } else if(step == 1) {
                            sprites[animeSprite].setTexture(animeTexts[animeSprite][0]);
                            if(leg) {
                                step += 1;
                                leg = false;
                            }
                            else {
                                step -= 1;
                                leg = true;
                            }
                         } else {
                            sprites[animeSprite].setTexture(animeTexts[animeSprite][2]);
                            step -= 1;
                         }
                     }
                }
            }
            
            //right mouse click controller
            if(event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                
		cout << "Mouse clicked ";
                sf::Vector2i position = sf::Mouse::getPosition(*window);
                cout << "at " << position.x << "," << position.y << endl;


                for (std::map<string, sf::RectangleShape>::iterator it = buttons.begin(); it != buttons.end(); ++it) {

                    //CREATE BUTTON FUNCTIONALITIES HERE
                    
                    // if(it->first == "" && it->second.getGlobalBounds().contains(position.x, position.y)) {
                    //     window->close();
                    // }

                    // if(it->first == "" && it->second.getGlobalBounds().contains(position.x, position.y)) {
                    //     window->close();
                    // }

                    // if(it->first == "" && it->second.getGlobalBounds().contains(position.x, position.y)) {
                    //     window->close();
                    // }

                    // ADD MORE BUTTONS HERE BY COPYING IF STATEMENT ABOVE
                }
            }
        }
        display();
    }
}

void WindowTemplate::close() {
    
    window->close();
}

void WindowTemplate::move(sf::Vector2i position) {

    window->setPosition(position);
}
