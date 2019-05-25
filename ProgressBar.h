#ifndef BAR_OVERALLPROGRESS_H
#define BAR_OVERALLPROGRESS_H

#include "Observer.h"
#include "FileTransfer.h"

//this is used as concrete observer

class ProgressBar : public Observer {
public:

    //type can be overall or single
    ProgressBar(FileTransfer *s, sf::RenderWindow *w, std::string type,
                unsigned int x, unsigned int y, sf::Color color = sf::Color::Green);

    virtual void update() override;

    virtual ~ProgressBar();

    const sf::RectangleShape &getRectangleShape() const;

    const std::string &getType() const;

    void setType(const std::string &type);

    unsigned int getMaxWidth() const;

    void setMaxWidth(unsigned int maxWidth);

    unsigned int getMaxHeight() const;

    void setMaxHeight(unsigned int maxHeight);

private:
    sf::RectangleShape rectangleShape;
    sf::RenderWindow *window;
    FileTransfer *subject;
    std::string type;
    unsigned int maxWidth;
    unsigned int maxHeight;
};


#endif //BAR_OVERALLPROGRESS_H