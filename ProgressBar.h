#ifndef BAR_OVERALLPROGRESS_H
#define BAR_OVERALLPROGRESS_H

#include <iostream>
#include "Observer.h"
#include "FileTransfer.h"

//this is used as concrete observer

class ProgressBar : public Observer {
public:

    //type can be overall or single
    ProgressBar(FileTransfer *s, sf::RenderWindow *w, std::string type);

    virtual void update(int filesTransferred, int bytesTransferred) override;

    virtual ~ProgressBar();


private:
    sf::RectangleShape rectangleShape;
    sf::RenderWindow *window;
    FileTransfer *subject;
    std::string type;
};

#endif //BAR_OVERALLPROGRESS_H