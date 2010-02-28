#include "loadout_blocks_controller.h"

using namespace std;

LoadoutBlocksController::LoadoutBlocksController( MasterSoldierItems list ) : LoadoutController( list ) {
}

void LoadoutBlocksController::display( unsigned char *screen_buffer, String &action_category ) {
  action_category = "loadout_blocks_category";
  display_loadout( screen_buffer );
}

void LoadoutBlocksController::update_left() {
  if( block == "right_shoulder" ) {
    block = "right_shoulder";
  } else if( block == "left_shoulder" ) {
    block = "right_shoulder";
  } else if( block == "right_leg" ) {
    block = "right_leg";
  } else if( block == "left_leg" ) {
    block = "right_leg";
  } else if( block == "right_hand" ) {
    block = "right_hand";
  } else if( block == "left_hand" ) {
    block = "right_hand";
  } else if( block == "backpack" ) {
    block = "left_shoulder";
  } else if( block == "belt" ) {
    block = "left_leg";
  } else {
    block = "right_shoulder";
  }
  cursor = 0;
}

void LoadoutBlocksController::update_right() {
  if( block == "right_shoulder" ) {
    block = "left_shoulder";
  } else if( block == "left_shoulder" ) {
    block = "backpack";
  } else if( block == "right_leg" ) {
    block = "left_leg";
  } else if( block == "left_leg" ) {
    block = "belt";
  } else if( block == "right_hand" ) {
    block = "left_hand";
  } else if( block == "left_hand" ) {
    block = "backpack";
  } else if( block == "backpack" ) {
    block = "backpack";
  } else if( block == "belt" ) {
    block = "belt";
  } else {
    block = "right_shoulder";
  }
  cursor = 0;
}

void LoadoutBlocksController::update_up() {
  if( block == "right_shoulder" ) {
    block = "right_shoulder";
  } else if( block == "left_shoulder" ) {
    block = "left_shoulder";
  } else if( block == "right_leg" ) {
    block = "right_hand";
  } else if( block == "left_leg" ) {
    block = "left_hand";
  } else if( block == "right_hand" ) {
    block = "right_shoulder";
  } else if( block == "left_hand" ) {
    block = "left_shoulder";
  } else if( block == "backpack" ) {
    block = "backpack";
  } else if( block == "belt" ) {
    block = "backpack";
  } else {
    block = "right_shoulder";
  }
  cursor = 0;
}

void LoadoutBlocksController::update_down() {
  if( block == "right_shoulder" ) {
    block = "right_hand";
  } else if( block == "left_shoulder" ) {
    block = "left_hand";
  } else if( block == "right_leg" ) {
    block = "right_leg";
  } else if( block == "left_leg" ) {
    block = "left_leg";
  } else if( block == "right_hand" ) {
    block = "right_leg";
  } else if( block == "left_hand" ) {
    block = "left_leg";
  } else if( block == "backpack" ) {
    block = "belt";
  } else if( block == "belt" ) {
    block = "belt";
  } else {
    block = "right_shoulder";
  }
  cursor = 0;
}
