#pragma once

#ifndef MASTER_BOX_H
#define MASTER_BOX_H

#include "box.h"

class MasterBox : public Box
{
    public:
        explicit MasterBox(int type, float lat, float lon, float alt);
        ~MasterBox();
    private:
};

#endif