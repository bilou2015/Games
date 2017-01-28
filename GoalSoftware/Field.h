#ifndef FIELD_H
#define FIELD_H
#include "Entity.h"

class Field : public Entity
{
public:
    Field();

    QPixmap getPixMap();

private:
    int m_height;
    int m_width;
    QPixmap pixField;
};

#endif // FIELD_H
