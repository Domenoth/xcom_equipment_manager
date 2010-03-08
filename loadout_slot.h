#ifndef loadout_slot_h_included
#define loadout_slot_h_included

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <string.hpp>
#include <cctype>
#include <math.h>
#include <strings.h>
#include <time.h>
#include <fstream>

#include "master_soldier_items.h"

class LoadoutSlot {
  public:
    LoadoutSlot( int, int );
    void set_item( InventoryItem *, LoadoutSlot * );
    InventoryItem * get_item();
  protected:
    int id, soldier_inventory_id;
    InventoryItem *item;
    LoadoutSlot *primary_slot;
};
#endif
