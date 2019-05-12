#ifndef BAR_OVERALLPROGRESS_H
#define BAR_OVERALLPROGRESS_H

#include "Observer.h"
#include "SingleProgress.h"

//this is used as concrete observer

//OverallProgress represents the advancement of the transfer of the whole directory

class OverallProgress : public Observer {
public:

    OverallProgress(SingleProgress *s, sf::RenderWindow *w);

    virtual void update(sf::RectangleShape &rs, int count) override;

    virtual ~OverallProgress();


private:
    sf::RectangleShape rectangleShape;
    sf::RenderWindow *window;
    sf::Event event;
    SingleProgress *subject;

};

#endif //BAR_OVERALLPROGRESS_H