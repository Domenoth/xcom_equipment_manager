#include "belt_block.h"

using namespace std;

BeltBlock::BeltBlock() : LoadoutBlock() {
}

BeltBlock::BeltBlock( String name_to_use, int row_to_use, int column_to_use ) : LoadoutBlock( name_to_use, row_to_use, column_to_use ) {
}

void BeltBlock::draw( unsigned char *screen_buffer ) {
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( row + 0 ) + column], " --------------- ", 17 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( row + 1 ) + column], "|   |   |   |   |", 17 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( row + 2 ) + column], "|   |   |   |   |", 17 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( row + 3 ) + column], " --------------- ", 17 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( row + 4 ) + column], "|   |       |   |", 17 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( row + 5 ) + column], "|   |       |   |", 17 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( row + 6 ) + column], " ---         --- ", 17 );
}

void BeltBlock::place_cursor( unsigned char *screen_buffer, int cursor ) {
  int cursor_column = column + 2;
  if( cursor < 4 ) {
    draw_cursor( screen_buffer, row + 1, cursor_column + cursor * 4 );
  } else {
    if( cursor == 5 ) {
      cursor_column += 12;
    }
    draw_cursor( screen_buffer, row + 4, cursor_column );
  }
}
