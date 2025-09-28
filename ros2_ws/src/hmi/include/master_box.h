#pragma once

#ifndef MASTER_BOX_H
#define MASTER_BOX_H

#include "box.h"

class MasterBox : public Box
{
    public:
        explicit MasterBox(Coordinates coord, int id, int number);
        ~MasterBox();
    private:
};

#endif