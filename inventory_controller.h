#ifndef inventory_controller_h_included
#define inventory_controller_h_included

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

#include "list_controller.h"

class InventoryController: public ListController {
  public:
    InventoryController( MasterSoldierItems );
    void display( unsigned char *screen_buffer, String &action_category );
};
#endif
