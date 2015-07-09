#include "MainWindow.cpp"

int main() {
    
    MainWindow start;

    //MAIN MENU SCENE ======================================

    Scene menu;

    //create background image
    SceneBuilder::addImage("main_menu_bck", menu);
 
    //add title to screen with loaded font 
    SceneBuilder::addText("title", "FFF_Tusj", "PIRATES!", 50, sf::Color::Green, menu);
    menu.texts["title"].setPosition(sf::Vector2f(0, 50));
    SceneBuilder::centerW(menu.texts["title"], 800, 600);
    
    SceneBuilder::addButton("exit", 200, 80, menu);
    menu.buttons["exit"].setPosition(sf::Vector2f(0, 500));
    SceneBuilder::centerW(menu.buttons["exit"], 800, 600);

    SceneBuilder::addButton("load", 200, 80, menu); 
    menu.buttons["load"].setPosition(sf::Vector2f(0, 400));
    SceneBuilder::centerW(menu.buttons["load"], 800, 600);

    SceneBuilder::addButton("play", 200, 80, menu); 
    menu.buttons["play"].setPosition(sf::Vector2f(0, 300));
    SceneBuilder::centerW(menu.buttons["play"], 800, 600);

    SceneBuilder::addSprite("astro", menu);
    menu.animeSprite = "astro";
    SceneBuilder::center(menu.sprites["astro"], 800, 600);

    //========================================================
    //FIRST ISLAND SCENE =====================================

    Scene first;
    SceneBuilder::addSprite("naruto", first);
    first.animeSprite = "naruto";
    SceneBuilder::center(first.sprites["naruto"], 800, 600);

    SceneBuilder::addImage("first_island_bck", first);

    sf::ConvexShape firstBound(4);
    firstBound.setPoint(0, sf::Vector2f(291, 213));
    firstBound.setPoint(1, sf::Vector2f(595, 222));
    firstBound.setPoint(2, sf::Vector2f(303, 509));
    firstBound.setPoint(3, sf::Vector2f(572, 512));
    SceneBuilder::restrictMovement(firstBound, first);

    //========================================================

    start.loadScene("menu", menu);
    start.loadScene("first", first);

    start.setScene(menu);
    start.run();
    
    return 0;
}
