#ifndef master_items_h_included
#define master_items_h_included

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <cctype>
#include <math.h>
#include <strings.h>
#include <time.h>
#include <fstream>

#include "inventory_item.h"

#define NUMBER_OF_ITEMS_IN_OBDATA_FILE 80

class InventoryItem;
class XcomFile;

class MasterItems {
  public:
    MasterItems();
    InventoryItem * get_item( unsigned char id_to_get );
  private:
    int file_size;
    char *file_name;
    InventoryItem ** master_list;
    XcomFile *xcom_file;
    unsigned char *file_data;
};
#endif

