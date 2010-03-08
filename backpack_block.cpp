#include "backpack_block.h"

using namespace std;

BackpackBlock::BackpackBlock() : LoadoutBlock() {
}

BackpackBlock::BackpackBlock( String name_to_use, int row_to_use, int column_to_use ) : LoadoutBlock( name_to_use, row_to_use, column_to_use ) {
}

void BackpackBlock::draw( unsigned char *screen_buffer ) {
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( row + 0 ) + column], " ----------- ", 13 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( row + 1 ) + column], "|   |   |   |", 13 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( row + 2 ) + column], "|   |   |   |", 13 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( row + 3 ) + column], " ----------- ", 13 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( row + 4 ) + column], "|   |   |   |", 13 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( row + 5 ) + column], "|   |   |   |", 13 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( row + 6 ) + column], " ----------- ", 13 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( row + 7 ) + column], "|   |   |   |", 13 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( row + 8 ) + column], "|   |   |   |", 13 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( row + 9 ) + column], " ----------- ", 13 );
}

void BackpackBlock::place_cursor( unsigned char *screen_buffer, int cursor ) {
  draw_cursor( screen_buffer, row + 1 + ( cursor / 3 * 3 ), column + 2 + cursor % 3 * 4 );
}
