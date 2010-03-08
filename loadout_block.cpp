#include "loadout_block.h"

using namespace std;

LoadoutBlock::LoadoutBlock() {
  name = NULL;
  row = 0;
  column = 0;
};

LoadoutBlock::LoadoutBlock( String name_to_use, int row_to_use, int column_to_use ) {
  name = name_to_use;
  row = row_to_use;
  column = column_to_use;
};

void LoadoutBlock::draw_cursor( unsigned char *screen_buffer, int cursor_row, int cursor_column ) {
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( cursor_row + 0 ) + cursor_column], "x", 1 );
  memcpy( &screen_buffer[AUTO_EQUIP_UI_LINE_SIZE * ( cursor_row + 1 ) + cursor_column], "x", 1 );
}
