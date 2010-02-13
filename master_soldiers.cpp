#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <cctype>
#include <math.h>
#include <strings.h>
#include <time.h>
#include <fstream>

#include "master_soldiers.h"
#include "battle_scape_soldier.h"
#include "xcom_file.h"

using namespace std;

MasterSoldiers::MasterSoldiers() {
  file_name = "MISSDAT\\UNIREF.DAT";
  xcom_file = new XcomFile( file_name );
  xcom_file->copy_data_out( file_data, file_size );
  master_list = new BattleScapeSoldier*[NUMBER_OF_SOLDIERS_IN_UNITREF_FILE];
  unsigned char current_soldier_id = 0;
  unsigned char temp_data[BYTES_PER_BATTLE_SCAPE_SOLDIER];
  BattleScapeSoldier *temp_soldier;
  operative_count = 0;
  while( current_soldier_id < NUMBER_OF_SOLDIERS_IN_UNITREF_FILE ) {
    memcpy( temp_data, &file_data[current_soldier_id*BYTES_PER_BATTLE_SCAPE_SOLDIER], BYTES_PER_BATTLE_SCAPE_SOLDIER ); 
    temp_soldier = new BattleScapeSoldier ( temp_data, current_soldier_id );
    if( temp_soldier->is_xcom_unit() ) {
      master_list[current_soldier_id] = temp_soldier;
      operative_count++;
      current_soldier_id++;
    } else {
      current_soldier_id = NUMBER_OF_SOLDIERS_IN_UNITREF_FILE;
    }
  }
}

int MasterSoldiers::get_operative_count() {
  return operative_count;
}

BattleScapeSoldier * MasterSoldiers::get_soldier( unsigned char id_to_get ) {
  return master_list[id_to_get];
}
