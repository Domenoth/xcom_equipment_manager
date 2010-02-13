#ifndef auto_equip_ui_h_included
#define auto_equip_ui_h_included

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

#define AUTO_EQUIP_UI_LINE_SIZE       80
#define AUTO_EQUIP_UI_MAX_SCREEN_SIZE 1599
#define AUTO_EQUIP_UI_NUMBER_OF_LINES 20
//#define AUTO_EQUIP_UI_MAX_SCREEN_SIZE 1999
//#define AUTO_EQUIP_UI_NUMBER_OF_LINES 25
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

class AutoEquipUi {
  public:
    AutoEquipUi();
    void display_inventory();
    void display_soldiers();
    void display_loadout();
    int take_over();
  protected:
    void reset_screen_buffer();
    void increment_cursor_and_offset( int &cursor, int &offset, int total_objects );
    void decrement_cursor_and_offset( int &cursor, int &offset );
    void route_category();
    void choose_inventory_action();
    void choose_soldier_action();
    void choose_loadout_action();
    void draw_right_shoulder();
    void draw_left_shoulder();
    void draw_right_leg();
    void draw_left_leg();
    void draw_right_hand();
    void draw_left_hand();
    void draw_backpack();
    void draw_belt();
    void draw_two_box( int starting_row, int starting_column );
    void draw_hand( int starting_row, int starting_column );
    void draw_loadout_cursor();
    void place_cursor_in_right_shoulder();
    void place_cursor_in_left_shoulder();
    void place_cursor_in_right_leg();
    void place_cursor_in_left_leg();
    void place_cursor_in_right_hand();
    void place_cursor_in_left_hand();
    void place_cursor_in_backpack();
    void place_cursor_in_belt();
    void place_cursor( int row, int column );
    int selected_item_id, selected_soldier_id;
    int item_cursor, soldier_cursor, loadout_cursor;
    int items_offset, soldiers_offset;
    String action_category, loadout_block;
    char action_token;
    MasterSoldierItems master_soldier_list;
    unsigned char screen_buffer[AUTO_EQUIP_UI_MAX_SCREEN_SIZE + 1];
};
#endif
