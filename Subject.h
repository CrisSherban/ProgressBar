#ifndef BAR_SUBJECT_H
#define BAR_SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual void addObserver(Observer *o) = 0;

    virtual void removeObserver(Observer *o) = 0;

    virtual void notify() = 0;

    virtual ~Subject() {};

};

#endif //BAR_SUBJECT_H
