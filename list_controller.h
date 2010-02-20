#ifndef list_controller_h_included
#define list_controller_h_included

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

#include "ui_controller.h"

class ListController: public UiController {
  public:
    ListController( MasterSoldierItems );
    virtual void display( unsigned char *screen_buffer, String &action_category ) = 0;
    void choose_action( const char action_token, unsigned char *screen_buffer, String &action_category );
    int selected_id;
  protected:
    void increment_cursor_and_offset();
    void decrement_cursor_and_offset();
    int cursor, offset;
};
#endif
