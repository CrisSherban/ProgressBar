#ifndef BAR_SINGLEPROGRESS_H
#define BAR_SINGLEPROGRESS_H

#include "Subject.h"
#include "SFML/Graphics.hpp"


//this is used as concrete subject

//usually a directory contains multiple files
//SingleProgress represents the transfer progress of a file of the directory

class SingleProgress : public Subject {

public:
    explicit SingleProgress();

    virtual void addObserver(Observer *o) override;

    virtual void removeObserver(Observer *o) override;

    virtual void notify() override;

    bool transfer();

    virtual ~SingleProgress() {}

private:
    sf::RectangleShape rectangleShape;
    Observer *o;
    int count;

};


#endif //BAR_SINGLEPROGRESS_H