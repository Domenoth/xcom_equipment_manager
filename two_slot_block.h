#ifndef two_slot_block_h_included
#define two_slot_block_h_included

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <string.hpp>
#include <cctype>
#include <math.h>
#include <strings.h>
#include <time.h>
#include <fstream>

#include "constants.h"
#include "loadout_block.h"

class TwoSlotBlock: public LoadoutBlock {
  public:
    TwoSlotBlock();
    TwoSlotBlock( String, int, int );
    virtual void draw( unsigned char * );
    void place_cursor( unsigned char *, int );
};
#endif
