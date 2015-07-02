#include "MainMenu.h"

//construct window and adjust settings
MainMenu::MainMenu() {
    
    width = 800;
    height = 600;
    
    window = new sf::RenderWindow(sf::VideoMode(width, height), "Pirates!");
    window->setKeyRepeatEnabled(true);
}

//initializes and stores graphical components of window
void MainMenu::initComponents() {
   
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
    title.setPosition(SFHelper::centerW(title, 800, 600));
    texts.push_back(title);
    
    //add a sprite to screen with loaded texture
    sf::Texture pirateImg;
    pirateImg.loadFromFile("sprite1.png");
    textures.push_back(pirateImg);
    sf::Sprite pirateSprite;
    pirateSprite.setTexture(textures[0]);
    sprites.push_back(pirateSprite);
    
    //add rectangle and shape to screen to create button
    sf::RectangleShape load(sf::Vector2f(100, 40));
    load.setPosition(sf::Vector2f(100, 100));
    sf::IntRect loadButton(100, 100, 100, 40);
    buttons.push_back(loadButton);
    rects.push_back(load);
}

//called from run() draws graphics
void MainMenu::display() {
    
    window->clear();
    window->draw(texts[0]);
    window->draw(sprites[0]);
    window->draw(rects[0]);
    window->display();
}

//function which loops and controls open window
void MainMenu::run() {
    
    while (window->isOpen()) {
    
        sf::Event event;
        while (window->pollEvent(event)) {
            
	    //close button defined
            if (event.type == sf::Event::Closed)
                window->close();
                
	    //keyboard controllers
            if(event.type == sf::Event::KeyPressed) {
                
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                     sprites[0].move(-10,0);
                 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                     sprites[0].move(10,0);
                 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                     sprites[0].move(0,-10);
                 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                     sprites[0].move(0,10);
            }
            
            //right mouse click controller
            if(event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                
		cout << "Mouse clicked ";
                sf::Vector2i position = sf::Mouse::getPosition(*window);
                cout << "at " << position.x << "," << position.y << endl;
                if(buttons[0].contains(position.x, position.y)) {
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
