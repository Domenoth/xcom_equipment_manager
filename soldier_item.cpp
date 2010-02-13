#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <cctype>
#include <math.h>
#include <strings.h>
#include <time.h>
#include <fstream>

#include "soldier_item.h"
#include "battle_scape_soldier.h"
#include "inventory_item.h"
#include "master_items.h"
#include "master_soldiers.h"

using namespace std;

SoldierItem::SoldierItem( unsigned char *data, unsigned char item_id, MasterItems *item_list, MasterSoldiers *soldier_list ) {
  item_data = new unsigned char[BYTES_PER_SOLDIER_ITEM];
  memcpy( item_data, data, BYTES_PER_SOLDIER_ITEM );
  id = item_id;
  if( item_data[ITEM_OWNER] != 255 ) {
    owner = soldier_list->get_soldier( item_data[ITEM_OWNER] );
  } else {
    owner = NULL;
  }
  type = item_list->get_item( item_data[SOLDIER_ITEM_TYPE] );
}

unsigned char * SoldierItem::coordinates() {
  unsigned char *coordinates_to_return = new unsigned char[3];
  coordinates_to_return[0] = item_data[X_COORDINATE];
  coordinates_to_return[1] = item_data[Y_COORDINATE];
  coordinates_to_return[2] = item_data[Z_COORDINATE];
  return coordinates_to_return;
}

bool SoldierItem::belongs_to_aliens() {
  unsigned char alien_equipment_coordinates[3] = { 0, 0, 0 };
  bool are_they_equal = memcmp( coordinates(), alien_equipment_coordinates, 3 ) == 0;
  return are_they_equal;
}

bool SoldierItem::is_elerium() {
  unsigned char elerium_name[20] = "ELERIUM-115";
  bool they_are_equal = memcmp( type->get_name(), elerium_name, 20 ) == 0;
  return they_are_equal;
}

bool SoldierItem::is_a_corpse() {
  unsigned char type_id = get_type_id();
  return type_id > 46 || type_id == 31 || type_id == 32 || type_id == 33;
}

bool SoldierItem::belongs_to_xcom() {
  return !belongs_to_aliens() && !is_elerium() && !is_a_corpse();
}

void SoldierItem::set_owner( BattleScapeSoldier soldier ) {
  item_data[ITEM_OWNER] = soldier.get_id();
  owner = &soldier;
}

BattleScapeSoldier * SoldierItem::get_owner() {
  return owner;
}

unsigned char SoldierItem::get_id() {
  return id;
}

unsigned char SoldierItem::get_owner_id() {
  return owner->get_id();
}

unsigned char SoldierItem::get_type_id() {
  return item_data[SOLDIER_ITEM_TYPE];
}

InventoryItem * SoldierItem::get_type() {
  return type;
}

void SoldierItem::set_inventory_slot( unsigned char slot ) {
  item_data[INVENTORY_SLOT] = slot;
}

unsigned char SoldierItem::get_inventory_slot() {
  return item_data[INVENTORY_SLOT];
}

void SoldierItem::load_into( SoldierItem item) {
  loaded_into = &item;
  item_data[OBJECT_ITEM_IS_LOADED_INTO] = item.get_id();
  item_data[LOADED_OR_NOT_LOADED] = 0;
}

void SoldierItem::unload() {
  item_data[LOADED_OR_NOT_LOADED] = 255;
}
