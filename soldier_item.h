#ifndef soldier_item_h_included
#define soldier_item_h_included

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
#include "battle_scape_soldier.h"

#define SOLDIER_ITEM_TYPE              0
#define Y_COORDINATE                   1
#define X_COORDINATE                   2
#define Z_COORDINATE                   3
#define ITEM_OWNER                     4
#define INVENTORY_SLOT                 5
#define OBJECT_ITEM_IS_LOADED_INTO     6
#define LOADED_OR_NOT_LOADED           7
#define QUANTITY_1                     8
#define QUANTITY_2                     9
#define QUANTITY_3                     10
#define TERRAIN_TILE                   11
#define INVENTORY_BIT_FLAG             12

#define RIGHT_HAND                     0
#define LEFT_HAND                      1
#define RIGHT_LEG_LEFT                 2
#define RIGHT_LEG_RIGHT                3
#define LEFT_LEG_LEFT                  4
#define LEFT_LEG_RIGHT                 5
#define RIGHT_SHOULDER_LEFT            6
#define RIGHT_SHOULDER_RIGHT           7
#define LEFT_SHOULDER_LEFT             8
#define LEFT_SHOULDER_RIGHT            9
#define BACK_PACK_0_0                  10
#define BACK_PACK_0_1                  11
#define BACK_PACK_0_2                  12
#define BACK_PACK_1_0                  13
#define BACK_PACK_1_1                  14
#define BACK_PACK_1_2                  15
#define BACK_PACK_2_0                  16
#define BACK_PACK_2_1                  17
#define BACK_PACK_2_2                  18

#define BYTES_PER_SOLDIER_ITEM         16

class MasterItems;
class MasterSoldiers;

class SoldierItem {
  public:
    SoldierItem( unsigned char *data, unsigned char item_id, MasterItems *item_list, MasterSoldiers *soldier_list );
    unsigned char * coordinates();
    bool belongs_to_xcom();
    void set_owner( BattleScapeSoldier soldier );
    BattleScapeSoldier * get_owner();
    unsigned char get_id();
    unsigned char get_owner_id();
    unsigned char get_type_id();
    InventoryItem * get_type();
    void set_inventory_slot( unsigned char slot );
    unsigned char get_inventory_slot();
    void load_into( SoldierItem item );
    void unload();
  protected:
    bool belongs_to_aliens();
    bool is_elerium();
    bool is_a_corpse();
    unsigned char id, inventory_slot, loaded;
    unsigned char *item_data;
    BattleScapeSoldier *owner;
    InventoryItem *type;
    SoldierItem *loaded_into;
};
#endif
