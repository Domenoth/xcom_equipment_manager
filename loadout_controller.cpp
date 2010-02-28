#include "loadout_controller.h"

using namespace std;

LoadoutController::LoadoutController( MasterSoldierItems list ) {
  master_soldier_list = list;
}

void LoadoutController::display_loadout( unsigned char *screen_buffer ) {
  draw_right_shoulder( screen_buffer );
  draw_left_shoulder( screen_buffer );
  draw_right_leg( screen_buffer );
  draw_left_leg( screen_buffer );
  draw_right_hand( screen_buffer );
  draw_left_hand( screen_buffer );
  draw_backpack( screen_buffer );
  draw_belt( screen_buffer );
  draw_loadout_cursor( screen_buffer );
}

void LoadoutController::choose_action( const char action_token, unsigned char *screen_buffer, String &action_category ) {
  switch( action_token ) {
    case 'a': update_left(); display( screen_buffer, action_category ); break;
    case 'd': update_right(); display( screen_buffer, action_category ); break;
    case 'w': update_up(); display( screen_buffer, action_category ); break;
    case 's': update_down(); display( screen_buffer, action_category ); break;
//    case 'r': sibling->display(); break;
    case 't': sibling_controller->display( screen_buffer, action_category ); break;
    default: display( screen_buffer, action_category ); break;
  }
}

void LoadoutController::draw_right_shoulder( unsigned char *screen_buffer ) {
  draw_two_box( screen_buffer, SHOULDER_ROW, RIGHT_SHOULDER_COLUMN );
}

void LoadoutController::draw_left_shoulder( unsigned char *screen_buffer ) {
  draw_two_box( screen_buffer, SHOULDER_ROW, LEFT_SHOULDER_COLUMN );
}

void LoadoutController::draw_right_leg( unsigned char *screen_buffer ) {
  draw_two_box( screen_buffer, LEG_ROW, RIGHT_LEG_COLUMN );
}

void LoadoutController::draw_left_leg( unsigned char *screen_buffer ) {
  draw_two_box( screen_buffer, LEG_ROW, LEFT_LEG_COLUMN );
}

void LoadoutController::draw_right_hand( unsigned char *screen_buffer ) {
  draw_hand( screen_buffer, HAND_ROW, RIGHT_HAND_COLUMN );
}

void LoadoutController::draw_left_hand( unsigned char *screen_buffer ) {
  draw_hand( screen_buffer, HAND_ROW, LEFT_HAND_COLUMN );
}

void LoadoutController::draw_backpack( unsigned char *screen_buffer ) {
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

void LoadoutController::draw_belt( unsigned char *screen_buffer ) {
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( BELT_ROW + 0 ) + BELT_COLUMN], " --------------- ", 17 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( BELT_ROW + 1 ) + BELT_COLUMN], "|   |   |   |   |", 17 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( BELT_ROW + 2 ) + BELT_COLUMN], "|   |   |   |   |", 17 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( BELT_ROW + 3 ) + BELT_COLUMN], " --------------- ", 17 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( BELT_ROW + 4 ) + BELT_COLUMN], "|   |       |   |", 17 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( BELT_ROW + 5 ) + BELT_COLUMN], "|   |       |   |", 17 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( BELT_ROW + 6 ) + BELT_COLUMN], " ---         --- ", 17 );
}

void LoadoutController::draw_two_box( unsigned char *screen_buffer, int starting_row, int starting_column ) {
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( starting_row + 0 ) + starting_column], " ------- ", 9 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( starting_row + 1 ) + starting_column], "|   |   |", 9 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( starting_row + 2 ) + starting_column], "|   |   |", 9 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( starting_row + 3 ) + starting_column], " ------- ", 9 );
}

void LoadoutController::draw_hand( unsigned char *screen_buffer, int starting_row, int starting_column ) {
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

void LoadoutController::draw_loadout_cursor( unsigned char *screen_buffer ) {
  if( block == "right_shoulder" ) {
    place_cursor_in_right_shoulder( screen_buffer );
  } else if( block == "left_shoulder" ) {
    place_cursor_in_left_shoulder( screen_buffer );
  } else if( block == "right_leg" ) {
    place_cursor_in_right_leg( screen_buffer );
  } else if( block == "left_leg" ) {
    place_cursor_in_left_leg( screen_buffer );
  } else if( block == "right_hand" ) {
    place_cursor_in_right_hand( screen_buffer );
  } else if( block == "left_hand" ) {
    place_cursor_in_left_hand( screen_buffer );
  } else if( block == "backpack" ) {
    place_cursor_in_backpack( screen_buffer );
  } else if( block == "belt" ) {
    place_cursor_in_belt( screen_buffer );
  } else {
    block = "right_shoulder";
    cursor = 0;
    place_cursor_in_right_shoulder( screen_buffer );
  }
}

void LoadoutController::place_cursor_in_right_shoulder( unsigned char *screen_buffer ) {
  place_cursor( screen_buffer, SHOULDER_ROW + 1, RIGHT_SHOULDER_COLUMN + 2 + cursor * 4 );
}

void LoadoutController::place_cursor_in_left_shoulder( unsigned char *screen_buffer ) {
  place_cursor( screen_buffer, SHOULDER_ROW + 1, LEFT_SHOULDER_COLUMN + 2 + cursor * 4 );
}

void LoadoutController::place_cursor_in_right_leg( unsigned char *screen_buffer ) {
  place_cursor( screen_buffer, LEG_ROW + 1, RIGHT_LEG_COLUMN + 2 + cursor * 4 );
}

void LoadoutController::place_cursor_in_left_leg( unsigned char *screen_buffer ) {
  place_cursor( screen_buffer, LEG_ROW + 1, LEFT_LEG_COLUMN + 2 + cursor * 4 );
}

void LoadoutController::place_cursor_in_right_hand( unsigned char *screen_buffer ) {
  place_cursor( screen_buffer, HAND_ROW + 4, RIGHT_HAND_COLUMN + 4 );
}

void LoadoutController::place_cursor_in_left_hand( unsigned char *screen_buffer ) {
  place_cursor( screen_buffer, HAND_ROW + 4, LEFT_HAND_COLUMN + 4 );
}

void LoadoutController::place_cursor_in_backpack( unsigned char *screen_buffer ) {
  place_cursor( screen_buffer, BACKPACK_ROW + 1 + ( cursor / 3 * 3 ), BACKPACK_COLUMN + 2 + cursor % 3 * 4 );
}

void LoadoutController::place_cursor_in_belt( unsigned char *screen_buffer ) {
  int column = BELT_COLUMN + 2;
  if( cursor < 4 ) {
    place_cursor( screen_buffer, BELT_ROW + 1, column + cursor * 4 );
  } else {
    if( cursor == 5 ) {
      column += 12;
    }
    place_cursor( screen_buffer, BELT_ROW + 4, column );
  }
}

void LoadoutController::place_cursor( unsigned char *screen_buffer, int row, int column ) {
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( row + 0 ) + column], "x", 1 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( row + 1 ) + column], "x", 1 );
}
