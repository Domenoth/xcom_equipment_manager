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
  inventory_controller->set_sibling_controller( soldiers_controller );
  soldiers_controller->set_sibling_controller( inventory_controller );
  action_token = NULL;
  loadout_cursor = 0;
  loadout_block = "right_shoulder";
}

void AutoEquipUi::reset_screen_buffer() {
  for( int i = 0; i < AUTO_EQUIP_UI_MAX_SCREEN_SIZE; i++ ) {
    screen_buffer[i] = ' ';
  }
}

void AutoEquipUi::display_loadout_blocks() {
  action_category = "loadout_blocks_category";
  display_loadout();
}

void AutoEquipUi::display_loadout_slots() {
  action_category = "loadout_slots_category";
  display_loadout();
}

void AutoEquipUi::display_loadout() {
  draw_right_shoulder();
  draw_left_shoulder();
  draw_right_leg();
  draw_left_leg();
  draw_right_hand();
  draw_left_hand();
  draw_backpack();
  draw_belt();
  draw_loadout_cursor();
}

void AutoEquipUi::draw_right_shoulder() {
  draw_two_box( SHOULDER_ROW, RIGHT_SHOULDER_COLUMN );
}

void AutoEquipUi::draw_left_shoulder() {
  draw_two_box( SHOULDER_ROW, LEFT_SHOULDER_COLUMN );
}

void AutoEquipUi::draw_right_leg() {
  draw_two_box( LEG_ROW, RIGHT_LEG_COLUMN );
}

void AutoEquipUi::draw_left_leg() {
  draw_two_box( LEG_ROW, LEFT_LEG_COLUMN );
}

void AutoEquipUi::draw_right_hand() {
  draw_hand( HAND_ROW, RIGHT_HAND_COLUMN );
}

void AutoEquipUi::draw_left_hand() {
  draw_hand( HAND_ROW, LEFT_HAND_COLUMN );
}

void AutoEquipUi::draw_backpack() {
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( BACKPACK_ROW + 0 ) + BACKPACK_COLUMN], " ----------- ", 13 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( BACKPACK_ROW + 1 ) + BACKPACK_COLUMN], "|   |   |   |", 13 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( BACKPACK_ROW + 2 ) + BACKPACK_COLUMN], "|   |   |   |", 13 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( BACKPACK_ROW + 3 ) + BACKPACK_COLUMN], " ----------- ", 13 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( BACKPACK_ROW + 4 ) + BACKPACK_COLUMN], "|   |   |   |", 13 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( BACKPACK_ROW + 5 ) + BACKPACK_COLUMN], "|   |   |   |", 13 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( BACKPACK_ROW + 6 ) + BACKPACK_COLUMN], " ----------- ", 13 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( BACKPACK_ROW + 7 ) + BACKPACK_COLUMN], "|   |   |   |", 13 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( BACKPACK_ROW + 8 ) + BACKPACK_COLUMN], "|   |   |   |", 13 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( BACKPACK_ROW + 9 ) + BACKPACK_COLUMN], " ----------- ", 13 );
}

void AutoEquipUi::draw_belt() {
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( BELT_ROW + 0 ) + BELT_COLUMN], " --------------- ", 17 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( BELT_ROW + 1 ) + BELT_COLUMN], "|   |   |   |   |", 17 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( BELT_ROW + 2 ) + BELT_COLUMN], "|   |   |   |   |", 17 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( BELT_ROW + 3 ) + BELT_COLUMN], " --------------- ", 17 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( BELT_ROW + 4 ) + BELT_COLUMN], "|   |       |   |", 17 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( BELT_ROW + 5 ) + BELT_COLUMN], "|   |       |   |", 17 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( BELT_ROW + 6 ) + BELT_COLUMN], " ---         --- ", 17 );
}

void AutoEquipUi::draw_two_box( int starting_row, int starting_column ) {
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( starting_row + 0 ) + starting_column], " ------- ", 9 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( starting_row + 1 ) + starting_column], "|   |   |", 9 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( starting_row + 2 ) + starting_column], "|   |   |", 9 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( starting_row + 3 ) + starting_column], " ------- ", 9 );
}

void AutoEquipUi::draw_hand( int starting_row, int starting_column ) {
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( starting_row + 0 ) + starting_column], " ------- ", 9 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( starting_row + 1 ) + starting_column], "|       |", 9 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( starting_row + 2 ) + starting_column], "|       |", 9 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( starting_row + 3 ) + starting_column], "|       |", 9 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( starting_row + 4 ) + starting_column], "|       |", 9 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( starting_row + 5 ) + starting_column], "|       |", 9 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( starting_row + 6 ) + starting_column], "|       |", 9 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( starting_row + 7 ) + starting_column], "|       |", 9 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( starting_row + 8 ) + starting_column], "|       |", 9 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( starting_row + 9 ) + starting_column], " ------- ", 9 );
}

void AutoEquipUi::draw_loadout_cursor() {
  if( loadout_block == "right_shoulder" ) {
    place_cursor_in_right_shoulder();
  } else if( loadout_block == "left_shoulder" ) {
    place_cursor_in_left_shoulder();
  } else if( loadout_block == "right_leg" ) {
    place_cursor_in_right_leg();
  } else if( loadout_block == "left_leg" ) {
    place_cursor_in_left_leg();
  } else if( loadout_block == "right_hand" ) {
    place_cursor_in_right_hand();
  } else if( loadout_block == "left_hand" ) {
    place_cursor_in_left_hand();
  } else if( loadout_block == "backpack" ) {
    place_cursor_in_backpack();
  } else if( loadout_block == "belt" ) {
    place_cursor_in_belt();
  } else {
    loadout_block = "right_shoulder";
    loadout_cursor = 0;
    place_cursor_in_right_shoulder();
  }
}

void AutoEquipUi::place_cursor_in_right_shoulder() {
  place_cursor( SHOULDER_ROW + 1, RIGHT_SHOULDER_COLUMN + 2 + loadout_cursor * 4 );
}

void AutoEquipUi::place_cursor_in_left_shoulder() {
  place_cursor( SHOULDER_ROW + 1, LEFT_SHOULDER_COLUMN + 2 + loadout_cursor * 4 );
}

void AutoEquipUi::place_cursor_in_right_leg() {
  place_cursor( LEG_ROW + 1, RIGHT_LEG_COLUMN + 2 + loadout_cursor * 4 );
}

void AutoEquipUi::place_cursor_in_left_leg() {
  place_cursor( LEG_ROW + 1, LEFT_LEG_COLUMN + 2 + loadout_cursor * 4 );
}

void AutoEquipUi::place_cursor_in_right_hand() {
  place_cursor( HAND_ROW + 4, RIGHT_HAND_COLUMN + 4 );
}

void AutoEquipUi::place_cursor_in_left_hand() {
  place_cursor( HAND_ROW + 4, LEFT_HAND_COLUMN + 4 );
}

void AutoEquipUi::place_cursor_in_backpack() {
  place_cursor( BACKPACK_ROW + 1 + ( loadout_cursor / 3 * 3 ), BACKPACK_COLUMN + 2 + loadout_cursor % 3 * 4 );
}

void AutoEquipUi::place_cursor_in_belt() {
  int column = BELT_COLUMN + 2;
  if( loadout_cursor < 4 ) {
    place_cursor( BELT_ROW + 1, column + loadout_cursor * 4 );
  } else {
    if( loadout_cursor == 5 ) {
      column += 12;
    }
    place_cursor( BELT_ROW + 4, column );
  }
}

void AutoEquipUi::place_cursor( int row, int column ) {
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( row + 0 ) + column], "x", 1 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( row + 1 ) + column], "x", 1 );
}

void AutoEquipUi::route_category() {
  reset_screen_buffer();
  if( action_category == "inventory_category" ) {
    inventory_controller->choose_action( action_token, screen_buffer, action_category );
  } else if ( action_category == "soldier_category" ) {
    soldiers_controller->choose_action( action_token, screen_buffer, action_category );
  } else if ( action_category == "loadout_blocks_category" ) {
    choose_loadout_blocks_action();
  } else if ( action_category == "loadout_slots_category" ) {
    choose_loadout_slots_action();
  } else {
    choose_loadout_blocks_action();
  }
}

void AutoEquipUi::choose_loadout_blocks_action() {
  switch( action_token ) {
    case 'a': update_loadout_block_left(); display_loadout_blocks(); break;
    case 'd': update_loadout_block_right(); display_loadout_blocks(); break;
    case 'w': update_loadout_block_up(); display_loadout_blocks(); break;
    case 's': update_loadout_block_down(); display_loadout_blocks(); break;
    case 't': display_loadout_slots(); break;
    default: display_loadout_blocks(); break;
  }
}

void AutoEquipUi::choose_loadout_slots_action() {
  switch( action_token ) {
    case 'a': update_loadout_cursor_left(); display_loadout_slots(); break;
    case 'd': update_loadout_cursor_right(); display_loadout_slots(); break;
    case 'w': update_loadout_cursor_up(); display_loadout_slots(); break;
    case 's': update_loadout_cursor_down(); display_loadout_slots(); break;
    case 'r': display_loadout_blocks(); break;
    case 't': inventory_controller->display( screen_buffer, action_category ); break;
    default: display_loadout_slots(); break;
  }
}

void AutoEquipUi::update_loadout_block_left() {
  if( loadout_block == "right_shoulder" ) {
    loadout_block = "right_shoulder";
  } else if( loadout_block == "left_shoulder" ) {
    loadout_block = "right_shoulder";
  } else if( loadout_block == "right_leg" ) {
    loadout_block = "right_leg";
  } else if( loadout_block == "left_leg" ) {
    loadout_block = "right_leg";
  } else if( loadout_block == "right_hand" ) {
    loadout_block = "right_hand";
  } else if( loadout_block == "left_hand" ) {
    loadout_block = "right_hand";
  } else if( loadout_block == "backpack" ) {
    loadout_block = "left_shoulder";
  } else if( loadout_block == "belt" ) {
    loadout_block = "left_leg";
  } else {
    loadout_block = "right_shoulder";
  }
  loadout_cursor = 0;
}

void AutoEquipUi::update_loadout_block_right() {
  if( loadout_block == "right_shoulder" ) {
    loadout_block = "left_shoulder";
  } else if( loadout_block == "left_shoulder" ) {
    loadout_block = "backpack";
  } else if( loadout_block == "right_leg" ) {
    loadout_block = "left_leg";
  } else if( loadout_block == "left_leg" ) {
    loadout_block = "belt";
  } else if( loadout_block == "right_hand" ) {
    loadout_block = "left_hand";
  } else if( loadout_block == "left_hand" ) {
    loadout_block = "backpack";
  } else if( loadout_block == "backpack" ) {
    loadout_block = "backpack";
  } else if( loadout_block == "belt" ) {
    loadout_block = "belt";
  } else {
    loadout_block = "right_shoulder";
  }
  loadout_cursor = 0;
}

void AutoEquipUi::update_loadout_block_up() {
  if( loadout_block == "right_shoulder" ) {
    loadout_block = "right_shoulder";
  } else if( loadout_block == "left_shoulder" ) {
    loadout_block = "left_shoulder";
  } else if( loadout_block == "right_leg" ) {
    loadout_block = "right_hand";
  } else if( loadout_block == "left_leg" ) {
    loadout_block = "left_hand";
  } else if( loadout_block == "right_hand" ) {
    loadout_block = "right_shoulder";
  } else if( loadout_block == "left_hand" ) {
    loadout_block = "left_shoulder";
  } else if( loadout_block == "backpack" ) {
    loadout_block = "backpack";
  } else if( loadout_block == "belt" ) {
    loadout_block = "backpack";
  } else {
    loadout_block = "right_shoulder";
  }
  loadout_cursor = 0;
}

void AutoEquipUi::update_loadout_block_down() {
  if( loadout_block == "right_shoulder" ) {
    loadout_block = "right_hand";
  } else if( loadout_block == "left_shoulder" ) {
    loadout_block = "left_hand";
  } else if( loadout_block == "right_leg" ) {
    loadout_block = "right_leg";
  } else if( loadout_block == "left_leg" ) {
    loadout_block = "left_leg";
  } else if( loadout_block == "right_hand" ) {
    loadout_block = "right_leg";
  } else if( loadout_block == "left_hand" ) {
    loadout_block = "left_leg";
  } else if( loadout_block == "backpack" ) {
    loadout_block = "belt";
  } else if( loadout_block == "belt" ) {
    loadout_block = "belt";
  } else {
    loadout_block = "right_shoulder";
  }
  loadout_cursor = 0;
}

void AutoEquipUi::update_loadout_cursor_left() {
  if( loadout_block == "right_shoulder" ) {
    loadout_cursor = 0;
  } else if( loadout_block == "left_shoulder" ) {
    loadout_cursor = 0;
  } else if( loadout_block == "right_leg" ) {
    loadout_cursor = 0;
  } else if( loadout_block == "left_leg" ) {
    loadout_cursor = 0;
  } else if( loadout_block == "right_hand" ) {
    loadout_cursor = 0;
  } else if( loadout_block == "left_hand" ) {
    loadout_cursor = 0;
  } else if( loadout_block == "backpack" ) {
    if( loadout_cursor % 3 > 0 ) {
      loadout_cursor--;
    } else {
      loadout_cursor = loadout_cursor;
    }
  } else if( loadout_block == "belt" ) {
    if( loadout_cursor >= 4 ) {
      loadout_cursor = 4;
    } else if( loadout_cursor > 0 ) {
      loadout_cursor --;
    } else {
      loadout_cursor = 0;
    }
  } else {
    loadout_block = "right_shoulder";
    loadout_cursor = 0;
  }
}

void AutoEquipUi::update_loadout_cursor_right() {
  if( loadout_block == "right_shoulder" ) {
    loadout_cursor = 1;
  } else if( loadout_block == "left_shoulder" ) {
    loadout_cursor = 1;
  } else if( loadout_block == "right_leg" ) {
    loadout_cursor = 1;
  } else if( loadout_block == "left_leg" ) {
    loadout_cursor = 1;
  } else if( loadout_block == "right_hand" ) {
    loadout_cursor = 0;
  } else if( loadout_block == "left_hand" ) {
    loadout_cursor = 0;
  } else if( loadout_block == "backpack" ) {
    if( loadout_cursor % 3 < 2 ) {
      loadout_cursor++;
    } else {
      loadout_cursor = loadout_cursor;
    }
  } else if( loadout_block == "belt" ) {
    if( loadout_cursor > 3 ) {
      loadout_cursor = 5;
    } else if( loadout_cursor < 3 ) {
      loadout_cursor ++;
    } else {
      loadout_cursor = 3;
    }
  } else {
    loadout_block = "right_shoulder";
    loadout_cursor = 0;
  }
}

void AutoEquipUi::update_loadout_cursor_up() {
  if( loadout_block == "right_shoulder" ) {
    loadout_cursor = loadout_cursor;
  } else if( loadout_block == "left_shoulder" ) {
    loadout_cursor = loadout_cursor;
  } else if( loadout_block == "right_leg" ) {
    loadout_cursor = loadout_cursor;
  } else if( loadout_block == "left_leg" ) {
    loadout_cursor = loadout_cursor;
  } else if( loadout_block == "right_hand" ) {
    loadout_cursor = 0;
  } else if( loadout_block == "left_hand" ) {
    loadout_cursor = 0;
  } else if( loadout_block == "backpack" ) {
    if( loadout_cursor > 2 ) {
      loadout_cursor -= 3;
    } else {
      loadout_cursor = loadout_cursor;
    }
  } else if( loadout_block == "belt" ) {
    if( loadout_cursor == 4 ) {
      loadout_cursor -= 4;
    } else if( loadout_cursor == 5) {
      loadout_cursor -= 2;
    } else {
      loadout_cursor = loadout_cursor;
    }
  } else {
    loadout_block = "right_shoulder";
    loadout_cursor = 0;
  }
}

void AutoEquipUi::update_loadout_cursor_down() {
  if( loadout_block == "right_shoulder" ) {
    loadout_cursor = loadout_cursor;
  } else if( loadout_block == "left_shoulder" ) {
    loadout_cursor = loadout_cursor;
  } else if( loadout_block == "right_leg" ) {
    loadout_cursor = loadout_cursor;
  } else if( loadout_block == "left_leg" ) {
    loadout_cursor = loadout_cursor;
  } else if( loadout_block == "right_hand" ) {
    loadout_cursor = 0;
  } else if( loadout_block == "left_hand" ) {
    loadout_cursor = 0;
  } else if( loadout_block == "backpack" ) {
    if( loadout_cursor < 6 ) {
      loadout_cursor += 3;
    } else {
      loadout_cursor = loadout_cursor;
    }
  } else if( loadout_block == "belt" ) {
    if( loadout_cursor == 0 ) {
      loadout_cursor += 4;
    } else if( loadout_cursor == 3) {
      loadout_cursor += 2;
    } else {
      loadout_cursor = loadout_cursor;
    }
  } else {
    loadout_block = "right_shoulder";
    loadout_cursor = 0;
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
