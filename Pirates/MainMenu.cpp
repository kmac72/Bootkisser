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
  
    //save all textures used in window 
    sf::Texture newPirateBtn, background;
    newPirateBtn.loadFromFile("images/exit_btn.png");
    textures.push_back(newPirateBtn);
    background.loadFromFile("images/main_menu_bck.jpg");
    textures.push_back(background);

    SFHelper::addSprite("naruto", animeTexts, sprites);
    animeSprite = "naruto";

    SFHelper::addSprite("astro", animeTexts, sprites);
    animeSprite = "astro";

    //create background image
    sf::Sprite back;
    back.setTexture(textures[1]);
    images.push_back(back); 
 
    //add title to screen with loaded font 
    sf::Font titleFont;
    if(!titleFont.loadFromFile("fonts/FFF_Tusj.ttf"))
	cerr << "Error loading font from file.\n";
    fonts.push_back(titleFont);
    sf::Text title("PIRATES!", fonts[0], 50);
    //sf::Text title;
    //title.setFont(fonts[0]);
    //title.setString("PIRATES!");
    //title.setCharacterSize(50);
    title.setColor(sf::Color::Green);
    title.setPosition(SFHelper::center(title, 800, 600));
    texts.push_back(title); 
    
    SFHelper::addButton("exit", 200, 80, buttons, btnTexts);
    buttons["exit"].setPosition(sf::Vector2f(0, 500));
    buttons["exit"].setPosition(SFHelper::centerW(buttons["exit"], 800, 600));

    SFHelper::addButton("load", 200, 80, buttons, btnTexts); 
    buttons["load"].setPosition(sf::Vector2f(0, 400));
    buttons["load"].setPosition(SFHelper::centerW(buttons["load"], 800, 600));
}

//called from run() draws graphics
void MainMenu::display() {
    
    window->clear();
    window->draw(images[0]);
    window->draw(texts[0]);
    window->draw(sprites["naruto"]);
    window->draw(sprites["astro"]);
    window->draw(buttons["load"]);
    window->draw(buttons["exit"]);
    //window->draw(rects[0]);
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
                if(buttons["exit"].getGlobalBounds().contains(position.x, position.y)) {
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
