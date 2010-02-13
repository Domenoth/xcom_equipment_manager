#ifndef xcom_file_parser_h_included
#define xcom_file_parser_h_included

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <cctype>
#include <math.h>
#include <strings.h>
#include <time.h>
#include <fstream>

class XcomFile {
  public:
    XcomFile( char *name );
    void copy_data_out( unsigned char *&data, int &size );
    void push_data_in( unsigned char *new_data, int new_size );
    void write_to_disk();
  protected:
    void file_open_error();
    char *file_name;
    unsigned char *file_data;
    int file_size;
};
#endif
