#ifndef inventory_item_h_included
#define inventory_item_h_included

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <cctype>
#include <math.h>
#include <strings.h>
#include <time.h>
#include <fstream>

#define INVENTORY_ITEM_NAME                   0
#define GRAPHIC_FOR_INVENTORY                 20
#define GRAPHIC_FOR_GROUND                    21
#define AVERAGE_WEAPON_STRENGTH               22
#define DISPLAY_PRIORITY                      23
#define INVENTORY_X_SIZE_WIDTH                24
#define INVENTORY_Y_SIZE_HEIGHT               25
#define FIRST_AMMO_TYPE                       26
#define SECOND_AMMO_TYPE                      27
#define THIRD_AMMO_TYPE                       28
#define GRAPHIC_FOR_IN_THE_HAND               30
#define AMMO_DAMAGE_TYPE                      31
#define AUTO_SHOT_ACCURACY                    32
#define SNAP_SHOT_ACCURACY                    33
#define AIMED_SHOT_ACCURACY                   34
#define PERCENT_TUS_USED_AUTO_SHOT            35
#define PERCENT_TUS_USED_SNAP_SHOT            36
#define PERCENT_TUS_USED_AIMED_SHOT           37
#define CLIP_SIZE_MELEE_STRENGTH_GRENADE_FUSE 38
#define MELEE_DAMAGE_TYPE                     39
#define MELEE_ACCURACY                        40
#define PERCENT_TUS_USED_MELEE                41
#define EXPLOSIVE_STRENGTH_NEEDED_TO_DESTROY  42
#define ITEM_WEIGHT                           43
#define GRENADE_TYPE                          44
#define WEAPON_THAT_SHOOTS                    46
#define IS_A_WEAPON                           47
#define IS_A_NON_WAYPOINT_WEAPON              48
#define IS_AMMO                               49
#define IS_TWO_HANDED                         50
#define IS_BLASTER_LAUNCHER                   51
#define IS_ALIEN                              52
#define ITEM_SCORING                          53

#define INVENTORY_ITEM_BYTES                  54
#define INVENTORY_ITEM_NAME_LENGTH            20

class InventoryItem {
  public:
    InventoryItem( unsigned char *data, unsigned char item_id );
    unsigned char get_id();
    unsigned char * get_name();
    char * get_char_name();
  protected:
    unsigned char id;
    unsigned char *name, *item_data;
    InventoryItem *first_ammo, *second_ammo, *third_ammo;
};
#endif
