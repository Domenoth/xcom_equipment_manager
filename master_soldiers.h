#ifndef master_soldiers_h_included
#define master_soldiers_h_included

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <cctype>
#include <math.h>
#include <strings.h>
#include <time.h>
#include <fstream>

#define NUMBER_OF_SOLDIERS_IN_UNITREF_FILE 80

class BattleScapeSoldier;
class XcomFile;

class MasterSoldiers {
  public:
    MasterSoldiers();
    int get_operative_count();
    BattleScapeSoldier * get_soldier( unsigned char id_to_get );
  private:
    int file_size, operative_count;
    char *file_name;
    BattleScapeSoldier ** master_list;
    XcomFile *xcom_file;
    unsigned char *file_data;
};
#endif
