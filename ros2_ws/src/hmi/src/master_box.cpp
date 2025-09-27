#include <iostream>
#include "master_box.h"

MasterBox::MasterBox(int type, Coordinates coord, int id, int number) : Box(type, coord, id, number){}

MasterBox::~MasterBox(){};