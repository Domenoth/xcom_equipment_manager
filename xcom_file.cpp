#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <cctype>
#include <math.h>
#include <strings.h>
#include <time.h>
#include <fstream>

#include "xcom_file.h"

using namespace std;

XcomFile::XcomFile( char *name ) {
  int copy_length = strlen(name) + 1;
  file_name = new char[copy_length];
  memcpy( file_name, name, copy_length );
  FILE *fp = fopen( file_name, "rb" );

  if (fp == NULL) {
    file_open_error();
  }
  
  fseek(fp, 0, SEEK_END);
  file_size = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  file_data = new unsigned char[file_size];
  
  fread( file_data, 1, file_size, fp );
  fclose(fp);
}

void XcomFile::copy_data_out( unsigned char *&data, int &size ) {
  size = file_size;
  data = new unsigned char[size];
  memcpy( data, file_data, size );
}

void XcomFile::push_data_in( unsigned char *new_data, int new_size ) {
  file_size = new_size;
  file_data = new unsigned char[new_size];
  memcpy( file_data, new_data, new_size );
}

void XcomFile::write_to_disk() {
  FILE *fp = fopen(file_name, "wb");

  if(fp == NULL) {
    file_open_error();
  }

  fwrite( file_data, 1, file_size, fp );
  fclose(fp);
}

void XcomFile::file_open_error() {
  cout << "failed to open " << file_name << endl;
  system("PAUSE");
  abort();
}
