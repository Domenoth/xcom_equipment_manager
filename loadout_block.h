#ifndef loadout_block_h_included
#define loadout_block_h_included

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
#include "master_soldier_items.h"
#include "loadout_slot.h"

class LoadoutBlock {
  public:
    LoadoutBlock();
    LoadoutBlock( String, int, int );
    virtual void draw( unsigned char * ) = 0;
  protected:
    void draw_cursor( unsigned char *, int, int );
    String name;
    int row, column;
};
#endif
