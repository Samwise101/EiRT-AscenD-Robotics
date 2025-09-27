#pragma once

#ifndef MASTER_BOX_H
#define MASTER_BOX_H

#include "box.h"

class MasterBox : public Box
{
    public:
        explicit MasterBox(int type, Coordinates coord, int id, int number);
        ~MasterBox();
    private:
};

#endif