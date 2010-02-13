#ifndef master_soldier_items_h_included
#define master_soldier_items_h_included

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
#include "soldier_item.h"

#define NUMBER_OF_ITEMS_IN_OBPOSREF_FILE 170

class MasterSoldiers;
class BattleScapeSoldier;
class XcomFile;

class MasterSoldierItems {
  public:
    MasterSoldierItems();
    int get_item_total_count( int id_to_get );
    int get_operative_count();
    int get_item_assigned_count( int id_to_get );
    int get_number_of_unique_items();
    SoldierItem * get_soldier_item( unsigned char id_to_get );
    InventoryItem * get_inventory_item( unsigned char id_to_get );
    BattleScapeSoldier * get_soldier( unsigned char id_to_get );
  private:
    int file_size;
    int hashed_item_counts[NUMBER_OF_ITEMS_IN_OBDATA_FILE];
    int assigned_item_counts[NUMBER_OF_ITEMS_IN_OBDATA_FILE];
    int number_of_unique_items;
    char *file_name;
    MasterItems *master_items;
    MasterSoldiers *master_soldiers;
    XcomFile *xcom_file;
    SoldierItem ** master_list;
    unsigned char *file_data;
};
#endif

