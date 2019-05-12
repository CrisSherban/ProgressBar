#ifndef BAR_OBSERVER_H
#define BAR_OBSERVER_H

#include "SFML/Graphics.hpp"

class Observer {
public:
    virtual void update(sf::RectangleShape& rs, int count) = 0;

    virtual ~Observer() {}
};


#endif //BAR_OBSERVER_H
