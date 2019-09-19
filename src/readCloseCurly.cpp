#include "../include/topoana.h"
#include <fstream>
#include <iostream>
#include <cstdlib>

void topoana::readCloseCurly(ifstream & fin, string & line, string prompt)
{
  line="";
  while(!fin.eof())
    {
      getline(fin,line);
      trim(line);
      if(!line.empty()&&line[0]!='#') break;
    }
  if(line!="}")
    {
      cerr<<"Error: The close curly bracket \"}\" related to the prompt \""<<prompt<<"\" is missing!"<<endl;
      exit(-1);
    }
}
