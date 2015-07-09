#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>   //for debugging purposes
#include "SceneBuilder.cpp"

using namespace std;

class MainWindow {
    
    //Main window object
    sf::RenderWindow* window;
    
    //Dimensions of window
    int width, height;

    //Map of scenes which can be loaded
    map<string, Scene> scenes;

    //Current scene loaded into window
    Scene s;

public:
    
    //construct window
    MainWindow();

    //add scene to window
    void loadScene(string name, Scene scene);
    
    //change scene that the window displays
    void setScene(Scene &newScene);
    
    //called from run() and draws graphics
    void display();
    
    //function which loops and controls open window
    //should be the same for all scenes and not be modified
    void run();
    
    //closes window
    void close();
};
