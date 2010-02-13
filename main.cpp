#include "auto_equip_ui.h"

using namespace std;

int main()
{
  system("cls");
//  SoldierItem *temp_soldier_item;
  AutoEquipUi *ui = new AutoEquipUi();
  return ui->take_over();
//  for( unsigned char i = 0; i < NUMBER_OF_ITEMS_IN_OBPOSREF_FILE; i++ ) {
//    temp_soldier_item = master_soldier_list->get_soldier_item( i );
//    if( temp_soldier_item->belongs_to_xcom() ) {
//      cout << int(i) << ": " << temp_soldier_item->get_type()->get_name() << " - " << temp_soldier_item->get_owner()->get_name() << endl;
//    }
//  }
}
