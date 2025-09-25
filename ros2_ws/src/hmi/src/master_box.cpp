#include <iostream>
#include "master_box.h"

MasterBox::MasterBox(int type, float lat, float lon, float alt) : Box(type, lat, lon, alt){}

MasterBox::~MasterBox(){};