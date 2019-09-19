#include "../include/topoana.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

void topoana::readNumItem(ifstream & fin, string & line, string prompt, unsigned long & ulvar)
{
  readOpenCurly(fin,line,prompt);
  m_nEtrsMax=ULONG_MAX;
  read1stLineOrCloseCurly(fin,line,false,prompt);
  if(line!="}")
    {
      if(line.find_first_not_of("0123456789")==string::npos) m_nEtrsMax=strtoul(line.c_str(),NULL,10);
      else
        {
          cerr<<"Error: The input \""<<line<<"\" for the item with the prompt \""<<prompt<<"\" is invalid!"<<endl;
          cerr<<"Infor: It should be an unsigned long integer if it is not left empty."<<endl;
          cerr<<"Infor: Please check it."<<endl;
          exit(-1);
        }
      readCloseCurly(fin,line,prompt);
    }
}
