#include "hand_block.h"

using namespace std;

HandBlock::HandBlock() : LoadoutBlock() {
}

HandBlock::HandBlock( String name_to_use, int row_to_use, int column_to_use ) : LoadoutBlock( name_to_use, row_to_use, column_to_use ) {
}

void HandBlock::draw( unsigned char *screen_buffer ) {
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( row + 0 ) + column], " ------- ", 9 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( row + 1 ) + column], "|       |", 9 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( row + 2 ) + column], "|       |", 9 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( row + 3 ) + column], "|       |", 9 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( row + 4 ) + column], "|       |", 9 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( row + 5 ) + column], "|       |", 9 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( row + 6 ) + column], "|       |", 9 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( row + 7 ) + column], "|       |", 9 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( row + 8 ) + column], "|       |", 9 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( row + 9 ) + column], " ------- ", 9 );
}

void HandBlock::place_cursor( unsigned char *screen_buffer, int cursor ) {
  draw_cursor( screen_buffer, row + 4, column + 4 );
}
