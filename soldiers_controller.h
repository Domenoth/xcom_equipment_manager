#ifndef soldiers_controller_h_included
#define soldiers_controller_h_included

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

class SoldiersController: public ListController {
  public:
    SoldiersController( MasterSoldierItems );
    void display( unsigned char *screen_buffer, String &action_category );
};
#endif
