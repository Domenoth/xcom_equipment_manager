#include "loadout_slot.h"

using namespace std;

LoadoutSlot::LoadoutSlot( int self_id, int inventory_id ) {
  id = self_id;
  soldier_inventory_id = inventory_id;
  item = NULL;
}

void LoadoutSlot::set_item( InventoryItem *new_item, LoadoutSlot *slot ) {
  item = new_item;
  primary_slot = slot;
}

InventoryItem * LoadoutSlot::get_item() {
  return item;
}
