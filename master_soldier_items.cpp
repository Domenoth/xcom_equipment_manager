#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <cctype>
#include <math.h>
#include <strings.h>
#include <time.h>
#include <fstream>

#include "master_soldier_items.h"
#include "master_items.h"
#include "master_soldiers.h"
#include "inventory_item.h"
#include "battle_scape_soldier.h"
#include "soldier_item.h"
#include "xcom_file.h"

using namespace std;

MasterSoldierItems::MasterSoldierItems() {
  for( int i = 0; i < NUMBER_OF_ITEMS_IN_OBDATA_FILE; i++ ) {
    hashed_item_counts[i] = 0;
    assigned_item_counts[i] = 0;
  }
  file_name = "MISSDAT\\OBPOSREF.DAT";
  xcom_file = new XcomFile( file_name );
  xcom_file->copy_data_out( file_data, file_size );
  master_items = new MasterItems;
  master_soldiers = new MasterSoldiers;
  master_list = new SoldierItem*[NUMBER_OF_ITEMS_IN_OBPOSREF_FILE];
  unsigned char temp_data[BYTES_PER_SOLDIER_ITEM];
  for( unsigned char i = 0; i*BYTES_PER_SOLDIER_ITEM < file_size; i++ ) {
    memcpy( temp_data, &file_data[i*BYTES_PER_SOLDIER_ITEM], BYTES_PER_SOLDIER_ITEM ); 
    master_list[i] = new SoldierItem ( temp_data, i, master_items, master_soldiers );
    if( master_list[i]->belongs_to_xcom() ) {
      hashed_item_counts[ master_list[i]->get_type()->get_id() ]++;
      if( master_list[i]->get_owner() != NULL ) {
        assigned_item_counts[ master_list[i]->get_type()->get_id() ]++;
      }
    }
  }
  number_of_unique_items = 0;
  for( int i = 0; i < NUMBER_OF_ITEMS_IN_OBDATA_FILE; i++ ) {
    if( hashed_item_counts[i] > 0 ) {
      number_of_unique_items++;
    }
  }
}

int MasterSoldierItems::get_item_total_count( int id_to_get ) {
  return hashed_item_counts[id_to_get];
}

int MasterSoldierItems::get_operative_count() {
  return master_soldiers->get_operative_count();
}

int MasterSoldierItems::get_item_assigned_count( int id_to_get ) {
  return assigned_item_counts[id_to_get];
}

int MasterSoldierItems::get_number_of_unique_items() {
  return number_of_unique_items;
}

SoldierItem * MasterSoldierItems::get_soldier_item( unsigned char id_to_get ) {
  return master_list[id_to_get];
}

InventoryItem * MasterSoldierItems::get_inventory_item( unsigned char id_to_get ) {
  return master_items->get_item( id_to_get );
}

BattleScapeSoldier * MasterSoldierItems::get_soldier( unsigned char id_to_get ) {
  return master_soldiers->get_soldier( id_to_get );
}
