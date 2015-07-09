#include "MainWindow.h"

MainWindow::MainWindow() {
    
    width = 800;
    height = 600;
   
    s.animeSprite = "none";
 
    window = new sf::RenderWindow(sf::VideoMode(width, height), "Pirates!");
    window->setKeyRepeatEnabled(true);
    window->setFramerateLimit(25);
}

void MainWindow::loadScene(string name, Scene scene) {

    scenes.insert(pair<string, Scene>(name, scene));
}

void MainWindow::setScene(Scene &newScene) {

    s.texts = newScene.texts;
    s.fonts = newScene.fonts;
 
    s.buttons = newScene.buttons;
    s.btnTexts = newScene.btnTexts;
   
    s.sprites = newScene.sprites;
    s.animeTexts = newScene.animeTexts;
    
    s.images = newScene.images;
    s.imageTexts = newScene.imageTexts;

    s.animeSprite = newScene.animeSprite;

    if(newScene.bounded) {
        cout << "Setting New s.bounds" << endl;
        s.bounds = newScene.bounds;
    }
}

void MainWindow::display() {
    
    window->clear();

    for (std::map<string, sf::Sprite>::iterator it = s.images.begin(); it != s.images.end(); ++it)
        window->draw(it->second);

    for (std::map<string, sf::Text>::iterator it = s.texts.begin(); it != s.texts.end(); ++it)
        window->draw(it->second);

    for (std::map<string, sf::RectangleShape>::iterator it = s.buttons.begin(); it != s.buttons.end(); ++it)
        window->draw(it->second);

    for (std::map<string, sf::Sprite>::iterator it = s.sprites.begin(); it != s.sprites.end(); ++it)
        window->draw(it->second);

    window->display();
}

void MainWindow::run() {
    
    int step = 0;
    bool leg = false;

    while (window->isOpen()) {
    
        sf::Event event;
        while (window->pollEvent(event)) {
            
	        //close button defined
            if (event.type == sf::Event::Closed)
                close();
                
	        //keyboard controllers
            if(event.type == sf::Event::KeyPressed) {
                
                sf::Vector2f spritePos = s.sprites[s.animeSprite].getPosition();
                spritePos.x += s.sprites[s.animeSprite].getTextureRect().width / 2;
                spritePos.y += s.sprites[s.animeSprite].getTextureRect().height / 2;
                //cout << "Sprite at " << spritePos.x << "," << spritePos.y << endl;

                if(s.animeSprite != "none") {

                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && s.bounds->getGlobalBounds().contains(spritePos.x - 20, spritePos.y)) {
                         s.sprites[s.animeSprite].move(-10,0);
                         if(step == 0) {
                            s.sprites[s.animeSprite].setTexture(s.animeTexts[s.animeSprite][7]);
                            step += 1;
                         } else if(step == 1) {
                            s.sprites[s.animeSprite].setTexture(s.animeTexts[s.animeSprite][6]);
                            if(leg) {
                                step += 1;
                                leg = false;
                            }
                            else {
                                step -= 1;
                                leg = true;
                            }
                         } else {
                            s.sprites[s.animeSprite].setTexture(s.animeTexts[s.animeSprite][8]);
                            step -= 1;
                         }
                     }
                     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && s.bounds->getGlobalBounds().contains(spritePos.x + 20, spritePos.y)) {
                         s.sprites[s.animeSprite].move(10,0); 
                         if(step == 0) {
                            s.sprites[s.animeSprite].setTexture(s.animeTexts[s.animeSprite][4]);
                            step += 1;
                         } else if(step == 1) {
                            s.sprites[s.animeSprite].setTexture(s.animeTexts[s.animeSprite][3]);
                            if(leg) {
                                step += 1;
                                leg = false;
                            }
                            else {
                                step -= 1;
                                leg = true;
                            }
                         } else {
                            s.sprites[s.animeSprite].setTexture(s.animeTexts[s.animeSprite][5]);
                            step -= 1;
                         }
                     }
                     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && s.bounds->getGlobalBounds().contains(spritePos.x, spritePos.y - 20)) {
                         s.sprites[s.animeSprite].move(0,-10);
                         if(step == 0) {
                            s.sprites[s.animeSprite].setTexture(s.animeTexts[s.animeSprite][10]);
                            step += 1;
                         } else if(step == 1) {
                            s.sprites[s.animeSprite].setTexture(s.animeTexts[s.animeSprite][9]);
                            if(leg) {
                                step += 1;
                                leg = false;
                            }
                            else {
                                step -= 1;
                                leg = true;
                            }
                         } else {
                            s.sprites[s.animeSprite].setTexture(s.animeTexts[s.animeSprite][11]);
                            step -= 1;
                         }
                     }
                     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && s.bounds->getGlobalBounds().contains(spritePos.x, spritePos.y + 20)) {
                         s.sprites[s.animeSprite].move(0,10);
                         if(step == 0) {
                            s.sprites[s.animeSprite].setTexture(s.animeTexts[s.animeSprite][1]);
                            step += 1;
                         } else if(step == 1) {
                            s.sprites[s.animeSprite].setTexture(s.animeTexts[s.animeSprite][0]);
                            if(leg) {
                                step += 1;
                                leg = false;
                            }
                            else {
                                step -= 1;
                                leg = true;
                            }
                         } else {
                            s.sprites[s.animeSprite].setTexture(s.animeTexts[s.animeSprite][2]);
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


                for (std::map<string, sf::RectangleShape>::iterator it = s.buttons.begin(); it != s.buttons.end(); ++it) {

                    if(it->first == "exit" && it->second.getGlobalBounds().contains(position.x, position.y)) {
                        close();
                    }

                    if(it->first == "load" && it->second.getGlobalBounds().contains(position.x, position.y)) {
                        close();
                    }

                    if(it->first == "play" && it->second.getGlobalBounds().contains(position.x, position.y)) {

                        this->setScene(scenes["first"]);
                        this->run();

                        close();
                    }

                    // ADD MORE s.buttons HERE BY COPYING IF STATEMENT ABOVE
                }
            }
        }
        display();
    }
}

void MainWindow::close() {
    
    window->close();
}
