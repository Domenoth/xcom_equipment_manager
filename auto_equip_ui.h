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
//#define AUTO_EQUIP_UI_MAX_SCREEN_SIZE 1999
//#define AUTO_EQUIP_UI_NUMBER_OF_LINES 25

#include "master_soldier_items.h"
#include "inventory_controller.h"
#include "soldiers_controller.h"
#include "loadout_blocks_controller.h"
#include "loadout_slots_controller.h"

class AutoEquipUi {
  public:
    AutoEquipUi();
    int take_over();
  protected:
    void reset_screen_buffer();
    void route_category();
    String action_category;
    char action_token;
    MasterSoldierItems master_soldier_list;
    InventoryController *inventory_controller;
    SoldiersController *soldiers_controller;
    LoadoutBlocksController *loadout_blocks_controller;
    LoadoutSlotsController *loadout_slots_controller;
    unsigned char screen_buffer[AUTO_EQUIP_UI_MAX_SCREEN_SIZE + 1];
};
#endif
