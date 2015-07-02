#include <SFML/Graphics.hpp>

namespace SFHelper {
    
    //Center a SFML component in its window. width/height are of window
    template <typename T>
    sf::Vector2f centerW(T comp, int width, int height) {
        
        float newX = (width / 2) - (comp.getLocalBounds().width / 2);
        float newY = (height / 2) - (comp.getLocalBounds().height / 2);
        
        sf::Vector2f position(newX, newY);
        return position;
    }
}
