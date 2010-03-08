#ifndef loadout_controller_h_included
#define loadout_controller_h_included

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

#define SHOULDER_ROW                  1
#define RIGHT_SHOULDER_COLUMN         5
#define LEFT_SHOULDER_COLUMN          18
#define LEG_ROW                       15
#define RIGHT_LEG_COLUMN              1
#define LEFT_LEG_COLUMN               22
#define HAND_ROW                      5
#define RIGHT_HAND_COLUMN             1
#define LEFT_HAND_COLUMN              22
#define BACKPACK_ROW                  1
#define BACKPACK_COLUMN               38
#define BELT_ROW                      12
#define BELT_COLUMN                   36

#include "master_soldier_items.h"
#include "ui_controller.h"
#include "two_slot_block.h"
#include "hand_block.h"
#include "backpack_block.h"
#include "belt_block.h"

class LoadoutController: public UiController {
  public:
    LoadoutController( MasterSoldierItems );
    virtual void display( unsigned char *screen_buffer, String &action_category ) = 0;
    void choose_action( const char action_token, unsigned char *screen_buffer, String &action_category );
  protected:
    void display_loadout( unsigned char *screen_buffer );
    void draw_loadout_cursor( unsigned char *screen_buffer );
    virtual void update_left() = 0;
    virtual void update_right() = 0;
    virtual void update_up() = 0;
    virtual void update_down() = 0;
    static int cursor;
    static String block;
    TwoSlotBlock right_shoulder, left_shoulder, right_leg, left_leg;
    HandBlock right_hand, left_hand;
    BackpackBlock backpack;
    BeltBlock belt;
    MasterSoldierItems master_soldier_list;
};
#endif
