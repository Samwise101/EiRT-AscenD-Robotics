#include <iostream>
#include "master_box.h"

MasterBox::MasterBox(Coordinates coord, int id, int number) : Box(MASTER, coord, id, number){}

MasterBox::~MasterBox(){};