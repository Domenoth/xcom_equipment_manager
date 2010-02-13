#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <cctype>
#include <math.h>
#include <strings.h>
#include <time.h>
#include <fstream>

#include "auto_equip_ui.h"

using namespace std;

LoadoutNeighbors::LoadoutNeighbors( String left, String right, String up, String down ) {
  left_neighbor = left;
  right_neighbor = right;
  up_neighbor = up;
  down_neighbor = down;
}
