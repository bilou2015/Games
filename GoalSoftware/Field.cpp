#include "Field.h"

Field::Field(){
    this->m_width = 1680 ;
    this->m_height = 1050;
    this->setPix(QPixmap(":/Other/field.png"));
}

