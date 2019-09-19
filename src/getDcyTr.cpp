#include "../include/topoana.h"
#include <cstdlib>

void topoana::getDcyTr(vector<int> vPid, vector<int> vMidx, vector< list<int> > & dcyTr, vector <int> * vIdxOfHead, vector<int> * vMidxOfHead, vector<int> * vIIncIncOrIRACascDcyBrs, vector<int> * vIIRAIncOrIRACascDcyBrs)
{
  dcyTr.clear();
  if(vIdxOfHead!=0) (*vIdxOfHead).clear();
  if(vMidxOfHead!=0) (*vMidxOfHead).clear();
  if(vIIncIncOrIRACascDcyBrs!=0) (*vIIncIncOrIRACascDcyBrs).clear();
  if(vIIRAIncOrIRACascDcyBrs!=0) (*vIIRAIncOrIRACascDcyBrs).clear();
  list<int> dcyBr;

  dcyBr.clear();
  int iIncIncOrIRACascDcyBrs=0;
  int iIRAIncOrIRACascDcyBrs=0;
  for(unsigned int i=0;i<vPid.size();i++)
    {
      if(i==0&&vPid[0]==m_pidOfISt)
        {
          for(unsigned int j=i+1;j<vPid.size();j++)
            {   
              if(((unsigned int) vMidx[j])==i)
                { 
                  if(vPid[j]==m_pidOfAnything) iIncIncOrIRACascDcyBrs=1;
                  else if(vPid[j]==m_pidOfIRAFlag) iIRAIncOrIRACascDcyBrs=1;
                  else dcyBr.push_back(vPid[j]);
                }
              else if(dcyBr.size()>0) break; // The statement is specially added here to save computing because the function sortPs has been run over vPid and vMidx.
            }
          break;
        }
      if(((unsigned int) vMidx[i])==i)
        {
          if(vPid[i]==m_pidOfAnything) iIncIncOrIRACascDcyBrs=1;
          else if(vPid[i]==m_pidOfIRAFlag) iIRAIncOrIRACascDcyBrs=1;
          else dcyBr.push_back(vPid[i]);
        }
      else break; // The statement is specially added here to save computing because the function sortPs has been run over vPid and vMidx.
    }
  if(dcyBr.size()>1||m_initEpEmSwitch==true||vPid[0]==m_pidOfISt)
    {
      dcyBr.push_front(11);
      dcyBr.push_front(-11);
      dcyTr.push_back(dcyBr);
      if(vIdxOfHead!=0) (*vIdxOfHead).push_back(-1);
      if(vMidxOfHead!=0) (*vMidxOfHead).push_back(-1);
      if(vIIncIncOrIRACascDcyBrs!=0) (*vIIncIncOrIRACascDcyBrs).push_back(iIncIncOrIRACascDcyBrs);
      if(vIIRAIncOrIRACascDcyBrs!=0) (*vIIRAIncOrIRACascDcyBrs).push_back(iIRAIncOrIRACascDcyBrs);
    }

  for(unsigned int i=0;i<vPid.size();i++)
    {
      if(i==0&&vPid[i]==m_pidOfISt) continue;
      dcyBr.clear();
      iIncIncOrIRACascDcyBrs=0;
      iIRAIncOrIRACascDcyBrs=0;
      for(unsigned int j=i+1;j<vPid.size();j++)
        {
          if(((unsigned int) vMidx[j])==i)
            {
              if(vPid[j]==m_pidOfAnything) iIncIncOrIRACascDcyBrs=1;
              else if(vPid[j]==m_pidOfIRAFlag) iIRAIncOrIRACascDcyBrs=1;
              else dcyBr.push_back(vPid[j]);
            }
          else if(dcyBr.size()>0) break; // The statement is specially added here to save computing because the function sortPs has been run over vPid and vMidx.
        }
      if(dcyBr.size()==0) continue; 
      if(abs(vPid[i])!=1&&abs(vPid[i])!=2&&abs(vPid[i])!=3&&abs(vPid[i])!=4&&abs(vPid[i])!=5&&abs(vPid[i])!=6)
        {
          dcyBr.push_front(vPid[i]);
        }
      else
        {
          dcyBr.push_front(-abs(vPid[i]));
          dcyBr.push_front(abs(vPid[i]));
        }
      dcyTr.push_back(dcyBr);
      if(vIdxOfHead!=0) (*vIdxOfHead).push_back(i);
      if(vMidxOfHead!=0) (*vMidxOfHead).push_back(vMidx[i]);
      if(vIIncIncOrIRACascDcyBrs!=0) (*vIIncIncOrIRACascDcyBrs).push_back(iIncIncOrIRACascDcyBrs);
      if(vIIRAIncOrIRACascDcyBrs!=0) (*vIIRAIncOrIRACascDcyBrs).push_back(iIRAIncOrIRACascDcyBrs);
    }
}
