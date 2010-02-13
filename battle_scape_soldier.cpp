#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <cctype>
#include <math.h>
#include <strings.h>
#include <time.h>
#include <fstream>

#include "battle_scape_soldier.h"

using namespace std;

BattleScapeSoldier::BattleScapeSoldier( unsigned char *data, unsigned char soldier_id ) {
  soldier_data = new unsigned char[BYTES_PER_BATTLE_SCAPE_SOLDIER];
  memcpy( soldier_data, data, BYTES_PER_BATTLE_SCAPE_SOLDIER );
  id = soldier_id;
  name = new unsigned char[BATTLE_SCAPE_SOLDIER_NAME_LENGTH + 1];
  name[BATTLE_SCAPE_SOLDIER_NAME_LENGTH] = NULL;
  memcpy( name, &soldier_data[BATTLE_SCAPE_SOLDIER_NAME], BATTLE_SCAPE_SOLDIER_NAME_LENGTH );
  xcom_unit = soldier_data[BATTLE_SCAPE_SOLDIER_TYPE] < 4;
  not_a_tank = soldier_data[BATTLE_SCAPE_SOLDIER_TYPE] < 3;
}

unsigned char BattleScapeSoldier::get_id() {
  return id;
}

unsigned char * BattleScapeSoldier::get_name() {
  unsigned char *name_to_return = new unsigned char[BATTLE_SCAPE_SOLDIER_NAME_LENGTH + 1];
  memcpy( name_to_return, name, BATTLE_SCAPE_SOLDIER_NAME_LENGTH + 1 );
  name_to_return[BATTLE_SCAPE_SOLDIER_NAME_LENGTH] = NULL;
  return name_to_return;
}

char * BattleScapeSoldier::get_char_name() {
  char *name_to_return = new char[BATTLE_SCAPE_SOLDIER_NAME_LENGTH + 1];
  memcpy( name_to_return, name, BATTLE_SCAPE_SOLDIER_NAME_LENGTH );
  name_to_return[BATTLE_SCAPE_SOLDIER_NAME_LENGTH] = NULL;
  return name_to_return;
}

bool BattleScapeSoldier::is_xcom_unit() {
  return xcom_unit;
}

bool BattleScapeSoldier::is_xcom_operative() {
  return xcom_unit && not_a_tank;
}
