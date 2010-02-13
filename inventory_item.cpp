#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <cctype>
#include <math.h>
#include <strings.h>
#include <time.h>
#include <fstream>
#include <cstring>

#include "inventory_item.h"

using namespace std;

InventoryItem::InventoryItem( unsigned char *data, unsigned char item_id ) {
  item_data = new unsigned char[INVENTORY_ITEM_BYTES];
  memcpy( item_data, data, INVENTORY_ITEM_BYTES );
  id = item_id;
  name = new unsigned char[INVENTORY_ITEM_NAME_LENGTH];
  memcpy( name, data, INVENTORY_ITEM_NAME_LENGTH );
}

unsigned char * InventoryItem::get_name() {
  unsigned char *name_to_return = new unsigned char[INVENTORY_ITEM_NAME_LENGTH + 1];
  memcpy( name_to_return, name, INVENTORY_ITEM_NAME_LENGTH );
  name_to_return[INVENTORY_ITEM_NAME_LENGTH] = NULL;
  return name_to_return;
}

char * InventoryItem::get_char_name() {
  char *name_to_return = new char[INVENTORY_ITEM_NAME_LENGTH + 1];
  memcpy( name_to_return, name, INVENTORY_ITEM_NAME_LENGTH );
  name_to_return[INVENTORY_ITEM_NAME_LENGTH] = NULL;
  return name_to_return;
}

unsigned char InventoryItem::get_id() {
  return id;
}
