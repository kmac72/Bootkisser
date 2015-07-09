#include "MainMenu.h"

//construct window and adjust settings
MainMenu::MainMenu() {
    
    width = 800;
    height = 600;
   
    animeSprite = "none";
 
    window = new sf::RenderWindow(sf::VideoMode(width, height), "Pirates!");
    window->setKeyRepeatEnabled(true);
    window->setFramerateLimit(25);
}

//initializes and stores graphical components of window
void MainMenu::initComponents() {

    SFHelper::addSprite("naruto", animeTexts, sprites);
    animeSprite = "naruto";

    SFHelper::addSprite("astro", animeTexts, sprites);
    animeSprite = "astro";

    //create background image
    SFHelper::addImage("main_menu_bck", imageTexts, images);
 
    //add title to screen with loaded font 
    SFHelper::addText("title", "FFF_Tusj", "PIRATES!", 50, sf::Color::Green, fonts, texts);
    texts["title"].setPosition(sf::Vector2f(0, 50));
    SFHelper::centerW(texts["title"], 800, 600);
    
    SFHelper::addButton("exit", 200, 80, buttons, btnTexts);
    buttons["exit"].setPosition(sf::Vector2f(0, 500));
    SFHelper::centerW(buttons["exit"], 800, 600);

    SFHelper::addButton("load", 200, 80, buttons, btnTexts); 
    buttons["load"].setPosition(sf::Vector2f(0, 400));
    SFHelper::centerW(buttons["load"], 800, 600);

    SFHelper::addButton("play", 200, 80, buttons, btnTexts); 
    buttons["play"].setPosition(sf::Vector2f(0, 300));
    SFHelper::centerW(buttons["play"], 800, 600);
}

//called from run() draws graphics
void MainMenu::display() {
    
    window->clear();
    window->draw(images["main_menu_bck"]);
    window->draw(texts["title"]);
    window->draw(buttons["load"]);
    window->draw(buttons["exit"]);
    window->draw(buttons["play"]);
    window->draw(sprites["naruto"]);
    window->draw(sprites["astro"]);
    window->display();
}

//function which loops and controls open window
//should be the same for all windows and not be modified
void MainMenu::run() {
    
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

                    if(it->first == "exit" && it->second.getGlobalBounds().contains(position.x, position.y)) {
                        close();
                    }

                    if(it->first == "load" && it->second.getGlobalBounds().contains(position.x, position.y)) {
                        close();
                    }

                    if(it->first == "play" && it->second.getGlobalBounds().contains(position.x, position.y)) {

                        FirstIsland island;
                        island.move(window->getPosition());
                        island.initComponents();
                        island.run();

                        //SFHelper::changeScene("FirstIsland")

                        close();
                    }

                    // ADD MORE BUTTONS HERE BY COPYING IF STATEMENT ABOVE
                }
            }
        }
        display();
    }
}

void MainMenu::close() {
    
    window->close();
}
