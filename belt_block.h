#ifndef belt_block_h_included
#define belt_block_h_included

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

class BeltBlock: public LoadoutBlock {
  public:
    BeltBlock();
    BeltBlock( String, int, int );
    virtual void draw( unsigned char * );
    void place_cursor( unsigned char *, int );
};
#endif
