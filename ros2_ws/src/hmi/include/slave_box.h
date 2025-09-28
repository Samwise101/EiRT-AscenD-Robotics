#pragma once

#ifndef SLAVE_BOX_H
#define SLAVE_BOX_H

#include "box.h"

class SlaveBox : public Box
{
    public:
        explicit SlaveBox(Coordinates coord, int id, int number);
        ~SlaveBox();
    private:
};

#endif