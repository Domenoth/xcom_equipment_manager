#ifndef battle_scape_soldier_h_included
#define battle_scape_soldier_h_included

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <cctype>
#include <math.h>
#include <strings.h>
#include <time.h>
#include <fstream>

#define BATTLE_SCAPE_SOLDIER_LEFT_HAND_IMAGE  53
#define BATTLE_SCAPE_SOLDIER_RIGHT_HAND_IMAGE 54
#define BATTLE_SCAPE_SOLDIER_TYPE             0
#define BATTLE_SCAPE_SOLDIER_NAME             86

#define BYTES_PER_BATTLE_SCAPE_SOLDIER        124
#define BATTLE_SCAPE_SOLDIER_NAME_LENGTH      25

class BattleScapeSoldier {
  public:
    BattleScapeSoldier( unsigned char *data, unsigned char soldier_id );
    bool is_xcom_unit();
    bool is_xcom_operative();
    unsigned char get_id();
    unsigned char * get_name();
    char * get_char_name();
  protected:
    bool xcom_unit, not_a_tank;
    unsigned char id;
    unsigned char *name, *soldier_data;
};
#endif
