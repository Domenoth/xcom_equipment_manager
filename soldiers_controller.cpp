#include "soldiers_controller.h"

using namespace std;

SoldiersController::SoldiersController( MasterSoldierItems list ) : ListController( list ) {
}

void SoldiersController::display( unsigned char *screen_buffer, String &action_category ) {
  action_category = "soldier_category";
  int number_of_operatives = master_soldier_list.get_operative_count();
  memcpy( &screen_buffer[0], "    NAME", 8 );
  int line_number = 1;
  int beginning_of_line;
  int current_soldier_id = 0;
  int skipped = 0;
  while( line_number < AUTO_EQUIP_UI_NUMBER_OF_LINES ) {
    while( current_soldier_id < number_of_operatives ) {
      beginning_of_line = line_number * AUTO_EQUIP_UI_LINE_SIZE;
      if( ++skipped > offset ) {
        if( master_soldier_list.get_soldier( current_soldier_id )->is_xcom_operative() ) {
          memcpy( &screen_buffer[beginning_of_line], "[ ]", 3 );
        } else if( cursor == line_number ) {
          cursor++;
        }
        if( cursor == line_number ) {
          selected_id = current_soldier_id;
          screen_buffer[beginning_of_line + 1] = 'x';
        }
        char const *name = master_soldier_list.get_soldier(current_soldier_id)->get_char_name();
        memcpy( &screen_buffer[beginning_of_line + 4], name, strlen( name ) );
        line_number++;
      }
      current_soldier_id++;
    }
    line_number++;
  }
  screen_buffer[AUTO_EQUIP_UI_MAX_SCREEN_SIZE] = NULL;
}
