#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <cctype>
#include <math.h>
#include <strings.h>
#include <time.h>
#include <fstream>

#include "master_items.h"
#include "inventory_item.h"
#include "xcom_file.h"

using namespace std;

MasterItems::MasterItems() {
  file_name = "GEODATA\\OBDATA.DAT";
  xcom_file = new XcomFile( file_name );
  xcom_file->copy_data_out( file_data, file_size );
  master_list = new InventoryItem*[NUMBER_OF_ITEMS_IN_OBDATA_FILE];
  unsigned char temp_data[INVENTORY_ITEM_BYTES];
  for( unsigned char i = 0; i < NUMBER_OF_ITEMS_IN_OBDATA_FILE; i++ ) {
    memcpy( temp_data, &file_data[i*INVENTORY_ITEM_BYTES], INVENTORY_ITEM_BYTES ); 
    master_list[i] = new InventoryItem ( temp_data, i );
  }
}

InventoryItem * MasterItems::get_item( unsigned char id_to_get ) {
  return master_list[id_to_get];
}
