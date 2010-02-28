#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <cctype>
#include <math.h>
#include <strings.h>
#include <time.h>
#include <fstream>

#include "auto_equip_ui.h"

using namespace std;

AutoEquipUi::AutoEquipUi() {
  action_category = "loadout_blocks_category";
  master_soldier_list = MasterSoldierItems();
  inventory_controller = new InventoryController( master_soldier_list );
  soldiers_controller = new SoldiersController( master_soldier_list );
  loadout_blocks_controller = new LoadoutBlocksController( master_soldier_list );
  loadout_slots_controller = new LoadoutSlotsController( master_soldier_list );
  inventory_controller->set_sibling_controller( soldiers_controller );
  soldiers_controller->set_sibling_controller( loadout_blocks_controller );
  loadout_blocks_controller->set_sibling_controller( loadout_slots_controller );
  loadout_slots_controller->set_sibling_controller( inventory_controller );
  action_token = NULL;
}

void AutoEquipUi::reset_screen_buffer() {
  for( int i = 0; i < AUTO_EQUIP_UI_MAX_SCREEN_SIZE; i++ ) {
    screen_buffer[i] = ' ';
  }
}

void AutoEquipUi::route_category() {
  reset_screen_buffer();
  if( action_category == "inventory_category" ) {
    inventory_controller->choose_action( action_token, screen_buffer, action_category );
  } else if ( action_category == "soldier_category" ) {
    soldiers_controller->choose_action( action_token, screen_buffer, action_category );
  } else if ( action_category == "loadout_blocks_category" ) {
    loadout_blocks_controller->choose_action( action_token, screen_buffer, action_category );
  } else if ( action_category == "loadout_slots_category" ) {
    loadout_slots_controller->choose_action( action_token, screen_buffer, action_category );
  } else {
    loadout_blocks_controller->choose_action( action_token, screen_buffer, action_category );
  }
}

int AutoEquipUi::take_over() {
  while( action_token != 'q' ) {
    route_category();
    cout << screen_buffer;
    fflush(stdout);
    action_token = getch();
    system("cls");
  }
  return EXIT_SUCCESS;
}
