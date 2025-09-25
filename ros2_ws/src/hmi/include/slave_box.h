#pragma once

#ifndef SLAVE_BOX_H
#define SLAVE_BOX_H

#include "box.h"

class SlaveBox : public Box
{
    public:
        explicit SlaveBox(int type, float lat, float lon, float alt);
        ~SlaveBox();
    private:
};

#endif