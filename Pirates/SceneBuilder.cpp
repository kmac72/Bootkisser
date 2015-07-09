#include <SFML/Graphics.hpp>
#include <iostream>
#include "Scene.cpp"

using namespace std;

namespace SceneBuilder {
    
    //Used to center a SFML component in its window. width/height are of window
    template <typename T>
    sf::Vector2f center(T &comp, int width, int height) {
        
        float newX = (width / 2) - (comp.getLocalBounds().width / 2);
        float newY = (height / 2) - (comp.getLocalBounds().height / 2);
        
        sf::Vector2f position(newX, newY);
        comp.setPosition(position);
        return position;
    }

    //Used to center the width of component
    template <typename T>
    sf::Vector2f centerW(T &comp, int width, int height) {
        
        float newX = (width / 2) - (comp.getLocalBounds().width / 2);
        
        sf::Vector2f position(newX, comp.getGlobalBounds().top);
        comp.setPosition(position);
        return position;
    }

    //Used to center the height of component
    template <typename T>
    sf::Vector2f centerH(T &comp, int width, int height) {
        
        float newY = (height / 2) - (comp.getLocalBounds().height / 2);
        
        sf::Vector2f position(comp.getGlobalBounds().left, newY);
        comp.setPosition(position);
        return position;
    }

    //Used to add a new animateable sprite to a window.
    void addSprite(string name, Scene &s) {

        sf::Sprite newSprite;
        vector<sf::Texture> texts;
        sf::Texture text;

	    //The order that we push on the images does matter. Used by animating code in windows run().
        text.loadFromFile("images/" + name + "_front.png");
        texts.push_back(text);
        text.loadFromFile("images/" + name + "_front_1.png");
        texts.push_back(text);
        text.loadFromFile("images/" + name + "_front_2.png");
        texts.push_back(text);

        text.loadFromFile("images/" + name + "_right.png");
        texts.push_back(text);
        text.loadFromFile("images/" + name + "_right_1.png");
        texts.push_back(text);
        text.loadFromFile("images/" + name + "_right_2.png");
        texts.push_back(text);

        text.loadFromFile("images/" + name + "_left.png");
        texts.push_back(text);
        text.loadFromFile("images/" + name + "_left_1.png");
        texts.push_back(text);
        text.loadFromFile("images/" + name + "_left_2.png");
        texts.push_back(text); 

        text.loadFromFile("images/" + name + "_back.png");
        texts.push_back(text);   
        text.loadFromFile("images/" + name + "_back_1.png");
        texts.push_back(text);
        text.loadFromFile("images/" + name + "_back_2.png");
        texts.push_back(text);

        s.animeTexts.insert(pair<string, vector<sf::Texture> >(name, texts));
        s.sprites.insert(pair<string, sf::Sprite>(name, newSprite)); 
        s.sprites[name].setTexture(s.animeTexts[name][0]);
    }

    void addButton(string name, int width, int height, Scene &s) {

	    sf::Texture newText;
        newText.loadFromFile("images/" + name + "_btn.png");
	    s.btnTexts.insert(pair<string, sf::Texture>(name, newText));

        sf::RectangleShape newBtn(sf::Vector2f(width, height));
        newBtn.setTexture(&s.btnTexts[name], true);
	    s.buttons.insert(pair<string, sf::RectangleShape>(name, newBtn));
    }

    void addImage(string name, Scene &s) {

        sf::Texture newText;
        newText.loadFromFile("images/" + name + "_img.png");
        s.imageTexts.insert(pair<string, sf::Texture>(name, newText));
         
        sf::Sprite newImage;
        newImage.setTexture(s.imageTexts[name]);
	    s.images.insert(pair<string, sf::Sprite>(name, newImage));
    }

    void addText(string name, string font, string text, int size, sf::Color color, Scene &s) {

        sf::Font newFont;
        if(!newFont.loadFromFile("fonts/" + font + ".ttf"))
            cerr << "Error loading font from file.\n";
        s.fonts.insert(pair<string, sf::Font>(name, newFont));
        sf::Text newText(text, s.fonts[name], size);
        newText.setColor(color);
        s.texts.insert(pair<string, sf::Text>(name, newText));
    }

    void restrictMovement(sf::ConvexShape bound, Scene &s) {

        s.bounded = true;

        int points = bound.getPointCount();
        s.bounds = new sf::ConvexShape(points);

        for(int i = 0; i < points; ++i)
            s.bounds->setPoint(i, bound.getPoint(i));
    }
}
