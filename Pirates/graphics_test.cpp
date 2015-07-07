#include <SFML/Graphics.hpp>



int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "Pirates!");
    
    sf::Font titleFont;
    titleFont.loadFromFile("fonts/ADRESACK.TTF");
    sf::Text title("PIRATES", titleFont, 50);
    
    sf::Texture pirateImg;
    pirateImg.loadFromFile("sprite1.png");
    sf::Sprite pirateSprite;
    pirateSprite.setTexture(pirateImg);
    
    //sf::Vector2f v1(16.5f, 24.f);
    sf::IntRect loadPirate(200, 200, 40, 100);
    //loadPirate.setPosition(v1);
    
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    
    window.setKeyRepeatEnabled(false);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyPressed) {
                
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                     pirateSprite.move(-10,0);
                 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                     pirateSprite.move(10,0);
                 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                     pirateSprite.move(0,-10);
                 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                     pirateSprite.move(0,10);
            }
            if(event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                
                sf::Vector2i position = sf::Mouse::getPosition();
                
                if(loadPirate.contains(position.x, position.y)) {
                    window.close();
                }

                // ADD MORE BUTTONS HERE BY COPYING IF STATEMENT ABOVE
            }
        }

        window.clear();
        window.draw(shape);
        window.draw(title);
        window.draw(pirateSprite);
        window.draw(loadPirate);
        window.display();
    }

    return 0;
}