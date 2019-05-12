#include "SingleProgress.h"

SingleProgress::SingleProgress() {
    rectangleShape.setPosition(0, 20);
    rectangleShape.setFillColor(sf::Color::Green);
    count = 1;
}

void SingleProgress::addObserver(Observer *o) {
    this->o = o;
}

void SingleProgress::removeObserver(Observer *o) {
    //in this case we have 1 subject and 1 observer so we just need to
    //deallocate the pointer to the actual observer
    if (this->o == o) {
        this->o = nullptr;
    }
}

void SingleProgress::notify() {
    o->update(rectangleShape, count);
};

bool SingleProgress::transfer() {
    //simulates the file transfer
    for (int i = 1; i <= 30; i++) {
        //this 'if' explains why progress bars get stuck at the end   \ (•◡•) /
        if (i > 27)
            sf::sleep(sf::seconds(0.08));
        else
            sf::sleep(sf::seconds(static_cast<float >(rand() % 10) / 200));
        rectangleShape.setSize(sf::Vector2f(i * 10, 10));

        this->notify();
        if (this->o == nullptr)
            return false;
    }
    count++;

    if (count <= 30)
        this->transfer(); //transfers the next subfile
    else {
        count = 1;
        return true;
    }
}
