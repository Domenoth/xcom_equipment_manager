#ifndef loadout_blocks_controller_h_included
#define loadout_blocks_controller_h_included

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

#include "loadout_controller.h"

class LoadoutBlocksController: public LoadoutController {
  public:
    LoadoutBlocksController( MasterSoldierItems );
    void display( unsigned char *screen_buffer, String &action_category );
  protected:
    void update_left();
    void update_right();
    void update_up();
    void update_down();
};
#endif
