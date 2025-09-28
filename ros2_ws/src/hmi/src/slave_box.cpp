#include <iostream>
#include "slave_box.h"

SlaveBox::SlaveBox(Coordinates coord, int id, int number) : Box(SLAVE, coord, id, number){}

SlaveBox::~SlaveBox(){}