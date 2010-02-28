#include "loadout_slots_controller.h"

using namespace std;

LoadoutSlotsController::LoadoutSlotsController( MasterSoldierItems list ) : LoadoutController( list ) {
}

void LoadoutSlotsController::display( unsigned char *screen_buffer, String &action_category ) {
  action_category = "loadout_slots_category";
  display_loadout( screen_buffer );
}

void LoadoutSlotsController::update_left() {
  if( block == "right_shoulder" ) {
    cursor = 0;
  } else if( block == "left_shoulder" ) {
    cursor = 0;
  } else if( block == "right_leg" ) {
    cursor = 0;
  } else if( block == "left_leg" ) {
    cursor = 0;
  } else if( block == "right_hand" ) {
    cursor = 0;
  } else if( block == "left_hand" ) {
    cursor = 0;
  } else if( block == "backpack" ) {
    if( cursor % 3 > 0 ) {
      cursor--;
    } else {
      cursor = cursor;
    }
  } else if( block == "belt" ) {
    if( cursor >= 4 ) {
      cursor = 4;
    } else if( cursor > 0 ) {
      cursor --;
    } else {
      cursor = 0;
    }
  } else {
    block = "right_shoulder";
    cursor = 0;
  }
}

void LoadoutSlotsController::update_right() {
  if( block == "right_shoulder" ) {
    cursor = 1;
  } else if( block == "left_shoulder" ) {
    cursor = 1;
  } else if( block == "right_leg" ) {
    cursor = 1;
  } else if( block == "left_leg" ) {
    cursor = 1;
  } else if( block == "right_hand" ) {
    cursor = 0;
  } else if( block == "left_hand" ) {
    cursor = 0;
  } else if( block == "backpack" ) {
    if( cursor % 3 < 2 ) {
      cursor++;
    } else {
      cursor = cursor;
    }
  } else if( block == "belt" ) {
    if( cursor > 3 ) {
      cursor = 5;
    } else if( cursor < 3 ) {
      cursor ++;
    } else {
      cursor = 3;
    }
  } else {
    block = "right_shoulder";
    cursor = 0;
  }
}

void LoadoutSlotsController::update_up() {
  if( block == "right_shoulder" ) {
    cursor = cursor;
  } else if( block == "left_shoulder" ) {
    cursor = cursor;
  } else if( block == "right_leg" ) {
    cursor = cursor;
  } else if( block == "left_leg" ) {
    cursor = cursor;
  } else if( block == "right_hand" ) {
    cursor = 0;
  } else if( block == "left_hand" ) {
    cursor = 0;
  } else if( block == "backpack" ) {
    if( cursor > 2 ) {
      cursor -= 3;
    } else {
      cursor = cursor;
    }
  } else if( block == "belt" ) {
    if( cursor == 4 ) {
      cursor -= 4;
    } else if( cursor == 5) {
      cursor -= 2;
    } else {
      cursor = cursor;
    }
  } else {
    block = "right_shoulder";
    cursor = 0;
  }
}

void LoadoutSlotsController::update_down() {
  if( block == "right_shoulder" ) {
    cursor = cursor;
  } else if( block == "left_shoulder" ) {
    cursor = cursor;
  } else if( block == "right_leg" ) {
    cursor = cursor;
  } else if( block == "left_leg" ) {
    cursor = cursor;
  } else if( block == "right_hand" ) {
    cursor = 0;
  } else if( block == "left_hand" ) {
    cursor = 0;
  } else if( block == "backpack" ) {
    if( cursor < 6 ) {
      cursor += 3;
    } else {
      cursor = cursor;
    }
  } else if( block == "belt" ) {
    if( cursor == 0 ) {
      cursor += 4;
    } else if( cursor == 3) {
      cursor += 2;
    } else {
      cursor = cursor;
    }
  } else {
    block = "right_shoulder";
    cursor = 0;
  }
}
