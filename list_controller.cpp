#include "list_controller.h"

using namespace std;

ListController::ListController( MasterSoldierItems list ) {
  selected_id = 0;
  cursor = 1;
  offset = 0;
  master_soldier_list = list;
}

void ListController::choose_action( const char action_token, unsigned char *screen_buffer, String &action_category ) {
  switch( action_token ) {
    case 's': increment_cursor_and_offset(); display( screen_buffer, action_category ); break;
    case 'w': decrement_cursor_and_offset(); display( screen_buffer, action_category ); break;
    case 't': sibling_controller->display( screen_buffer, action_category ); break;
    default: display( screen_buffer, action_category ); break;
  }
}

void ListController::increment_cursor_and_offset() {
  int total_objects = master_soldier_list.get_number_of_unique_items();
  int last_line_index = AUTO_EQUIP_UI_NUMBER_OF_LINES - 1;
  if( cursor == last_line_index && offset + last_line_index < total_objects ) {
    offset++;
  }
  if( cursor < total_objects && cursor < last_line_index ) {
    cursor++;
  }
}

void ListController::decrement_cursor_and_offset() {
  if( offset > 0 && cursor == 1 ) {
    offset--;
  }
  if( cursor > 1 ) {
    cursor--;
  }
}
