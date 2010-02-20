#ifndef ui_controller_h_included
#define ui_controller_h_included

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

#include "master_soldier_items.h"
#include "constants.h"

class UiController {
  public:
    virtual void display( unsigned char *screen_buffer, String &action_category ) = 0;
    virtual void choose_action( const char action_token, unsigned char *screen_buffer, String &action_category ) = 0;
    void set_sibling_controller( UiController *controller );
  protected:
    MasterSoldierItems master_soldier_list;
    UiController *sibling_controller;
};
#endif
