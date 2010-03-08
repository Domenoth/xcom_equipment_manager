#include "loadout_controller.h"

using namespace std;

LoadoutController::LoadoutController( MasterSoldierItems list ) {
  master_soldier_list = list;
  left_shoulder = TwoSlotBlock( "left_shoulder", SHOULDER_ROW, LEFT_SHOULDER_COLUMN );
  right_shoulder = TwoSlotBlock( "right_shoulder", SHOULDER_ROW, RIGHT_SHOULDER_COLUMN );
  left_leg = TwoSlotBlock( "left_leg", LEG_ROW, LEFT_LEG_COLUMN );
  right_leg = TwoSlotBlock( "right_leg", LEG_ROW, RIGHT_LEG_COLUMN );
  left_hand = HandBlock( "left_hand", HAND_ROW, LEFT_HAND_COLUMN );
  right_hand = HandBlock( "right_hand", HAND_ROW, RIGHT_HAND_COLUMN );
  backpack = BackpackBlock( "backpack", BACKPACK_ROW, BACKPACK_COLUMN );
  belt = BeltBlock( "belt", BELT_ROW, BELT_COLUMN );
}

void LoadoutController::display_loadout( unsigned char *screen_buffer ) {
  right_shoulder.draw( screen_buffer );
  left_shoulder.draw( screen_buffer );
  right_leg.draw( screen_buffer );
  left_leg.draw( screen_buffer );
  right_hand.draw( screen_buffer );
  left_hand.draw( screen_buffer );
  backpack.draw( screen_buffer );
  belt.draw( screen_buffer );
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

void LoadoutController::draw_loadout_cursor( unsigned char *screen_buffer ) {
  if( block == "right_shoulder" ) {
    right_shoulder.place_cursor( screen_buffer, cursor );
  } else if( block == "left_shoulder" ) {
    left_shoulder.place_cursor( screen_buffer, cursor );
  } else if( block == "right_leg" ) {
    right_leg.place_cursor( screen_buffer, cursor );
  } else if( block == "left_leg" ) {
    left_leg.place_cursor( screen_buffer, cursor );
  } else if( block == "right_hand" ) {
    right_hand.place_cursor( screen_buffer, cursor );
  } else if( block == "left_hand" ) {
    left_hand.place_cursor( screen_buffer, cursor );
  } else if( block == "backpack" ) {
    backpack.place_cursor( screen_buffer, cursor );
  } else if( block == "belt" ) {
    belt.place_cursor( screen_buffer, cursor );
  } else {
    block = "right_shoulder";
    cursor = 0;
    right_shoulder.place_cursor( screen_buffer, cursor );
  }
}
