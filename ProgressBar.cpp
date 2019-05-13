#include "ProgressBar.h"

ProgressBar::ProgressBar(FileTransfer *s, sf::RenderWindow *w, std::string type) :
        window(w), subject(s), type(type) {

    subject->addObserver(this);

    if (type == "overall")
        rectangleShape.setPosition(sf::Vector2f(0, 0));
    else if (type == "single")
        rectangleShape.setPosition(sf::Vector2f(0, 20));
    else
        throw std::invalid_argument("Invalid bar type");

    rectangleShape.setFillColor(sf::Color::Green);
}


ProgressBar::~ProgressBar() {
    subject->removeObserver(this);
}


void ProgressBar::update(int filesTransferred, int bytesTransferred) {

    if (type == "overall") {
        window->clear();
        rectangleShape.setSize(sf::Vector2f(filesTransferred * 10, 10));
    }

    if (type == "single")
        rectangleShape.setSize(sf::Vector2f(bytesTransferred, 10));

    window->draw(rectangleShape);
    window->display();
}