#include "inventory_controller.h"

using namespace std;

InventoryController::InventoryController( MasterSoldierItems list ) : ListController( list ) {
}

void InventoryController::display( unsigned char *screen_buffer, String &action_category ) {
  action_category = "inventory_category";
  memcpy( &screen_buffer[0], "    QTY EQP AVL     ITEM NAME", 29 );
  int line_number = 1;
  int beginning_of_line;
  int current_item_id = 0;
  int skipped = 0;
  int temp_total_count = 0;
  int temp_assigned_count = 0;
  while( line_number < AUTO_EQUIP_UI_NUMBER_OF_LINES ) {
    while( current_item_id < NUMBER_OF_ITEMS_IN_OBDATA_FILE ) {
      beginning_of_line = line_number * AUTO_EQUIP_UI_LINE_SIZE;
      temp_total_count = master_soldier_list.get_item_total_count( current_item_id );
      temp_assigned_count = master_soldier_list.get_item_assigned_count( current_item_id );
      if( temp_total_count > 0 && ++skipped > offset ) {
        memcpy( &screen_buffer[beginning_of_line], "[ ]", 3 );
        if( cursor == line_number ) {
          selected_id = current_item_id;
          screen_buffer[beginning_of_line + 1] = 'x';
        }
        screen_buffer[beginning_of_line + 5] = char( ( temp_total_count / 10 + 0x30 ) );
        screen_buffer[beginning_of_line + 6] = char( temp_total_count % 10 + 0x30);
        screen_buffer[beginning_of_line + 9] = char( temp_assigned_count / 10 + 0x30);
        screen_buffer[beginning_of_line + 10] = char( temp_assigned_count % 10 + 0x30);
        screen_buffer[beginning_of_line + 13] = char( ( temp_total_count - temp_assigned_count ) / 10 + 0x30);
        screen_buffer[beginning_of_line + 14] = char( ( temp_total_count - temp_assigned_count ) % 10 + 0x30);
        char const *name = master_soldier_list.get_inventory_item(current_item_id)->get_char_name();
        memcpy( &screen_buffer[beginning_of_line + 17], name, strlen( name ) );
        line_number++;
      }
      current_item_id++;
    }
    line_number++;
  }
  screen_buffer[AUTO_EQUIP_UI_MAX_SCREEN_SIZE] = NULL;
}
