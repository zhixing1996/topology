#include "../include/topoana.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <sstream>

void topoana::readCard(string cardFlNm)
{
  ifstream fin(cardFlNm.c_str(),ios::in);
  if(!fin)
    {
      cerr<<"Error: Can't open the card file \""<<m_cardFlNm<<"\"!"<<endl;
      if(m_cardFlNm=="topoana.card")
        {
          cerr<<"Infor: The card file name is the default one."<<endl;
          cerr<<"Infor: Do you forget to append the name of your own card file to the end of the executable?"<<endl;
          cerr<<"Infor: If yes, please specify it along with the executable by the command line \"(pathOfTheExecutable/)topoana.exe nameOfYourOwnCardFile\""<<endl;
        }
      else
        {
          cerr<<"Infor: Please check it."<<endl;
        }
      exit(-1);
    }  

  cout<<endl<<"Reading the card file: "<<cardFlNm<<" ..."<<endl<<endl;

  string line="";
  while(!fin.eof())      
    {
      while(!fin.eof())
        {
          getline(fin,line);
          trim(line);
          if(!line.empty()&&line[0]!='#') break;
        }
      if(line.empty()||line[0]=='#')
        {
          break;
        }
      else if(line=="% Names of input root files")
        {
          readOpenCurly(fin,line,"% Names of input root files");
          read1stLineOrCloseCurly(fin,line,true,"No root file names are found in the item with the prompt \"% Names of input root files");
          m_nmsOfIptRootFls.push_back(line);
          while(1)
            {
              readExtraLinesOrCloseCurly(fin,line,"% Names of input root files");
              if(line=="}")
                {
                  break;
                }
              else 
                {
                  m_nmsOfIptRootFls.push_back(line);
                }
            }
	}
      else if(line=="% Tree name")
        {
          readOpenCurly(fin,line,"% Tree name");
          read1stLineOrCloseCurly(fin,line,true,"No tree name is found in the item with the prompt \"% Tree name");
          m_trNm=line;
          readCloseCurly(fin,line,"% Tree name");
        }
      else if(line=="% Storage type of the raw input topology data (Four options: AI, VI, MIV, and MDV. Default: AI)")
        {
          readOpenCurly(fin,line,"% Storage type of the raw input topology data (Four options: AI, VI, MIV, and MDV. Default: AI)");
          m_strgTpOfRawIptTopoDat="AI";
          read1stLineOrCloseCurly(fin,line,false,"% Storage type of the raw input topology data (Four options: AI, VI, MIV, and MDV. Default: AI)");
          if(line!="}")
            {
              if(line=="AI"||line=="VI"||line=="MIV"||line=="MDV")
                {
                  m_strgTpOfRawIptTopoDat=line;
                }
              else
                {
                  cerr<<"Error: The input \""<<line<<"\" for the item \"Storage type of the raw input topology data\" is invalid!"<<endl;
                  cerr<<"Infor: It should be \"AI\", \"VI\", \"MIV\" or \"MDV\"."<<endl;
                  cerr<<"Infor: Please check it."<<endl;
                  exit(-1);
                }
              readCloseCurly(fin,line,"% Storage type of the raw input topology data (Four options: AI, VI, MIV, and MDV. Default: AI)");
            }
        }
      else if(line=="% Branch name of the number of particles (Default: nMCGen)")
        {
          readOpenCurly(fin,line,"% Branch name of the number of particles (Default: nMCGen)");
          read1stLineOrCloseCurly(fin,line,false,"No branch name of the number of particles is found in the item with the prompt \"% Branch name of the number of particles (Default: nMCGen)");
          if(line!="}")
            {
              m_brNmOfNps=line;
              readCloseCurly(fin,line,"% Branch name of the number of particles (Default: nMCGen)");
            }
        }
      else if(line=="% Branch name of the PDG codes of particles (Default: MCGenPDG)")
        {
          readOpenCurly(fin,line,"% Branch name of the PDG codes of particles (Default: MCGenPDG)");
          read1stLineOrCloseCurly(fin,line,false,"No branch name of the PDG codes of particles is found in the item with the prompt \"% Branch name of the PDG codes of particles (Default: MCGenPDG)");
          if(line!="}")
            {
              m_brNmOfPid=line;
              readCloseCurly(fin,line,"% Branch name of the PDG codes of particles (Default: MCGenPDG)");     
            }
        }
      else if(line=="% Branch name of the mother indeces of particles (Default: MCGenMothIndex)")
        {
          readOpenCurly(fin,line,"% Branch name of the mother indeces of particles (Default: MCGenMothIndex)");
          read1stLineOrCloseCurly(fin,line,false,"No branch name of the mother indeces of particles is found in the item with the prompt \"% Branch name of the mother indeces of particles (Default: MCGenMothIndex)");
          if(line!="}")
            {
              m_brNmOfMidx=line;
              readCloseCurly(fin,line,"% Branch name of the mother indeces of particles (Default: MCGenMothIndex)");  
            }
        }
      else if(line=="% Maximum number of entries to be processed")
        {
          readNumItem(fin, line, "% Maximum number of entries to be processed", m_nEtrsMax);
        }
      else if(line=="% Cut to select entries")
        {
          readOpenCurly(fin,line,"% Cut to select entries");
          read1stLineOrCloseCurly(fin,line,false,"% Cut to select entries");
          if(line!="}")
            {
              m_cut=line;
              readCloseCurly(fin,line,"% Cut to select entries");
            }
        }
      else if(line=="% Method to apply cut to array variables (Two options: T and F. Default: F)")
        {
          readOpenCurly(fin,line,"% Method to apply cut to array variables (Two options: T and F. Default: F)");
          read1stLineOrCloseCurly(fin,line,false,"% Method to apply cut to array variables (Two options: T and F. Default: F)");
          if(line!="}")
            {
              if(line=="T")
                {
                  m_cutMethod=true;
                }
              else if(line=="F")
                {
                  m_cutMethod=false;
                }
              else
                {
                  cerr<<"Error: The input \""<<line<<"\" for the item \"Method to apply cut to array variables\" is invalid!"<<endl;
                  cerr<<"Infor: It should be \"T\" or \"F\"."<<endl;
                  cerr<<"Infor: Please check it."<<endl;
                  exit(-1);
                } 
              readCloseCurly(fin,line,"% Method to apply cut to array variables (Two options: T and F. Default: F)");
            }
        }
      else if(line=="% Maximum hierarchy of heading decay branches to be processed in each event")
        {
          readNumItem(fin, line, "% Maximum hierarchy of heading decay branches to be processed in each event", m_hHdDcyBrsMax);
        }
      else if(line=="% Ignore the decay of the following particles")
        {
          readVPItem(fin, line, "% Ignore the decay of the following particles", m_vIdPid);
        }
      else if(line=="% Ignore the decay of the daughters of the following particles")
        {
          readVPItem(fin, line, "% Ignore the decay of the daughters of the following particles", m_vIddPid);
        }
      else if(line=="% Ignore gISR photons (Two options: Y and N. Default: N)")
        {
          readYNItem(fin, line, "% Ignore gISR photons (Two options: Y and N. Default: N)", m_ignoreGISR);
        }
      else if(line=="% Ignore gFSR photons (Two options: Y and N. Default: N)")
        {
          readYNItem(fin, line, "% Ignore gFSR photons (Two options: Y and N. Default: N)", m_ignoreGFSR);
        }
      else if(line=="% Component analysis --- decay trees")
        {
          readOpenCurly(fin,line,"% Component analysis --- decay trees");
          read1stLineOrCloseCurly(fin,line,false,"% Component analysis --- decay trees");
          if(line!="}")
            {
              istringstream iss;
              iss.clear();
              iss.str(line);
              iss>>line;
              if(line=="Y")
                {
                  m_compAnaOfDcyTrs=true;
                }
              else if(line=="N")
                {
                  m_compAnaOfDcyTrs=false;
                }
              else
                {
                  cerr<<"Error: The first input parameter \""<<line<<"\" for the item \"Component analysis --- decay trees\" is invalid!"<<endl;
                  cerr<<"Infor: It should be \"Y\" or \"N\"."<<endl;
                  cerr<<"Infor: Please check it."<<endl;
                  exit(-1);
                }
              if(!iss.eof())
                {
                  iss>>line;
                  if(line.find_first_not_of("0123456789")==string::npos) m_nDcyTrsToBePrtdMax=strtoul(line.c_str(),NULL,10);
                  else if(line=="-") m_nDcyTrsToBePrtdMax=ULONG_MAX;
                  else
                    {
                      cerr<<"Error: The second input parameter \""<<line<<"\" for the item \"Component analysis --- decay trees\" is invalid!"<<endl;
                      cerr<<"Infor: It should be an unsigned long integer at which you want to set."<<endl;
                      cerr<<"Infor: It can also be \"-\" as a place holder if there is a third input parameter following it."<<endl;
                      cerr<<"Infor: Please check it."<<endl;
                      exit(-1);
                    }
                }
              else m_nDcyTrsToBePrtdMax=ULONG_MAX;
              if(!iss.eof()) 
                {
                  iss>>line;
                  if(line.find_first_not_of("0123456789")==string::npos) m_nDcyIFStsToBePrtdMax=strtoul(line.c_str(),NULL,10);        
                  else if(line=="-") m_nDcyIFStsToBePrtdMax=ULONG_MAX;
                  else
                    { 
                      cerr<<"Error: The third input parameter \""<<line<<"\" for the item \"Component analysis --- decay trees\" is invalid!"<<endl;
                      cerr<<"Infor: It should be an unsigned long integer at which you want to set."<<endl;
                      cerr<<"Infor: It can also be \"-\" as a place holder if there is a fourth input parameter following it."<<endl;
                      cerr<<"Infor: Please check it."<<endl;
                      exit(-1);
                    }
                }
              else m_nDcyIFStsToBePrtdMax=ULONG_MAX;
              if(!iss.eof()) 
                {
                  iss>>line;
                  if(line=="Y")
                    {
                      m_adjDcyIFStsIntoACol=true;
                    }
                  else if(line=="N")
                    {
                      m_adjDcyIFStsIntoACol=false;
                    }
                  else
                    {
                      cerr<<"Error: The fourth input parameter \""<<line<<"\" for the item \"Component analysis --- decay trees\" is invalid!"<<endl;
                      cerr<<"Infor: It should be \"Y\" or \"N\"."<<endl;
                      cerr<<"Infor: Please check it."<<endl;
                      exit(-1);
                    }                  
                }
              readCloseCurly(fin,line,"% Component analysis --- decay trees");
            }
        }
      else if(line=="% Component analysis --- decay initial-final states")
        {
          readOpenCurly(fin,line,"% Component analysis --- decay initial-final states");
          read1stLineOrCloseCurly(fin,line,false,"% Component analysis --- decay initial-final states");
          if(line!="}")
            {
              istringstream iss;
              iss.clear();
              iss.str(line);
              iss>>line;
              if(line=="Y")
                {
                  m_compAnaOfDcyIFSts=true;
                }
              else if(line=="N")
                {
                  m_compAnaOfDcyIFSts=false;
                }
              else
                {
                  cerr<<"Error: The first input parameter \""<<line<<"\" for the item \"Component analysis --- decay initial-final states\" is invalid!"<<endl;
                  cerr<<"Infor: It should be \"Y\" or \"N\"."<<endl;
                  cerr<<"Infor: Please check it."<<endl;
                  exit(-1);
                }
              if(!iss.eof())
                {
                  iss>>line;
                  if(line.find_first_not_of("0123456789")==string::npos) m_nDcyIFStsToBePrtdMax=strtoul(line.c_str(),NULL,10);
                  else
                    {
                      cerr<<"Error: The second input parameter \""<<line<<"\" for the item \"Component analysis --- decay initial-final states\" is invalid!"<<endl;
                      cerr<<"Infor: It should be an unsigned long integer if it is not left empty."<<endl;
                      cerr<<"Infor: Please check it."<<endl;
                      exit(-1);
                    }
                }
              else m_nDcyIFStsToBePrtdMax=ULONG_MAX;
              readCloseCurly(fin,line,"% Component analysis --- decay initial-final states");
            }
        }
      else if(line=="% Component analysis --- decay branches of particles")
        {
          readPItem(fin,line, "% Component analysis --- decay branches of particles", m_vPid_compDcyBrP, m_vNm_compDcyBrP, &m_vNDcyBrsToBePrtdMax);
        }
      else if(line=="% Component analysis --- production branches of particles")
        {
          readPItem(fin, line, "% Component analysis --- production branches of particles", m_vPid_compProdBrP, m_vNm_compProdBrP, &m_vNProdBrsToBePrtdMax);
        }
      else if(line=="% Component analysis --- mothers of particles")
        {
          readPItem(fin, line, "% Component analysis --- mothers of particles", m_vPid_compMP, m_vNm_compMP, &m_vNMsToBePrtdMax);
        }
      else if(line=="% Component analysis --- inclusive decay branches")
        {
          readSmpDcyItem(fin, line, "% Component analysis --- inclusive decay branches", m_vVPid_compIncDcyBr, m_vNm_compIncDcyBr, &m_vNExcCompsToBePrtdMax);
	}
      else if(line=="% Component analysis --- intermediate-resonance-allowed decay branches")
        {
          readSmpDcyItem(fin, line, "% Component analysis --- intermediate-resonance-allowed decay branches", m_vVPid_compIRADcyBr, m_vNm_compIRADcyBr, &m_vNIntStrusToBePrtdMax);
	}
      else if(line=="% Signal identification --- decay trees")
        {
          readCmplxDcyItem(fin, line, "% Signal identification --- decay trees", m_vVPid_sigDcyTr, m_vVMidx_sigDcyTr, m_vNm_sigDcyTr);
	}
      else if(line=="% Signal identification --- decay initial-final states")
        {
          readSmpDcyItem(fin, line, "% Signal identification --- decay initial-final states", m_vVPid_sigDcyIFSts2, m_vNm_sigDcyIFSts2);
	}
      else if(line=="% Signal identification --- particles")
        {
          readPItem(fin, line, "% Signal identification --- particles", m_vPid_sigP, m_vNm_sigP);
	}
      else if(line=="% Signal identification --- decay branches")
        {
          readSmpDcyItem(fin, line, "% Signal identification --- decay branches", m_vVPid_sigDcyBr, m_vNm_sigDcyBr);
	} 
      else if(line=="% Signal identification --- inclusive decay branches")
        {
          readSmpDcyItem(fin, line, "% Signal identification --- inclusive decay branches", m_vVPid_sigIncDcyBr, m_vNm_sigIncDcyBr);
	}
      else if(line=="% Signal identification --- cascade decay branches")
        {
          readCmplxDcyItem(fin, line, "% Signal identification --- cascade decay branches", m_vVPid_sigCascDcyBrs, m_vVMidx_sigCascDcyBrs, m_vNm_sigCascDcyBrs);
	}
      else if(line=="% Signal identification --- inclusive cascade decay branches")
        {
          readCmplxDcyItem(fin, line, "% Signal identification --- inclusive cascade decay branches", m_vVPid_sigIncCascDcyBrs, m_vVMidx_sigIncCascDcyBrs, m_vNm_sigIncCascDcyBrs, true);
	}
      else if(line=="% Signal identification --- intermediate-resonance-allowed decay branches")
        {
          readSmpDcyItem(fin, line, "% Signal identification --- intermediate-resonance-allowed decay branches", m_vVPid_sigIRADcyBr, m_vNm_sigIRADcyBr);
	}
      else if(line=="% Signal identification --- inclusive or intermediate-resonance-allowed cascade decay branches")
        {
          readCmplxDcyItem(fin, line, "% Signal identification --- inclusive or intermediate-resonance-allowed cascade decay branches", m_vVPid_sigIncOrIRACascDcyBrs, m_vVMidx_sigIncOrIRACascDcyBrs, m_vNm_sigIncOrIRACascDcyBrs, true);
	}
      else if(line=="% Process charge conjugate objects together (Two options: Y and N. Default: N)")
        {
          readYNItem(fin, line, "% Process charge conjugate objects together (Two options: Y and N. Default: N)", m_ccSwitch);
        }
      else if(line=="% Analysis tasks for signal identifications (Three options: TC, T and C. Default: TC)")
        {
          readOpenCurly(fin,line,"% Analysis tasks for signal identifications (Three options: TC, T and C. Default: TC)");
          read1stLineOrCloseCurly(fin,line,false,"% Analysis tasks for signal identifications (Three options: TC, T and C. Default: TC)");
          if(line!="}")
            {
              if(line=="TC"||line=="T"||line=="C")
                {
                  m_anaTasksForSigIds=line;
                }
              else
                {
                  cerr<<"Error: The input \""<<line<<"\" for the item \"Analysis tasks for signal identifications\" is invalid!"<<endl;
                  cerr<<"Infor: It should be \"TC\", \"T\" or \"C\"."<<endl;
                  cerr<<"Infor: Please check it."<<endl;
                  exit(-1);
                }
              readCloseCurly(fin,line,"% Analysis tasks for signal identifications (Three options: TC, T and C. Default: TC)");
            }
        }
      else if(line=="% Sort the topology structures for signal identifications (Two options: Y and N. Default: N)")
        {
          readYNItem(fin, line, "% Sort the topology structures for signal identifications (Two options: Y and N. Default: N)", m_sortTheToposForSigIds);
        }
      else if(line=="% Involve the initial e+ and e- uniformly in all the events (Two options: Y and N. Default: N)")
        {
          readYNItem(fin, line, "% Involve the initial e+ and e- uniformly in all the events (Two options: Y and N. Default: N)", m_initEpEmSwitch);
        }
      else if(line=="% Main name of output files (Default: Main name of the card file)")
        {
          readOpenCurly(fin,line,"% Main name of output files (Default: Main name of the card file)");
          read1stLineOrCloseCurly(fin,line,false,"No main file name is found in the item with the prompt \"% Main name of output files (Default: Main name of the card file)");
          if(line!="}")
            {
              m_mainNmOfOptFls=line;
              readCloseCurly(fin,line,"% Main name of output files (Default: Main name of the card file)");
            }
        }
      else if(line=="% Center decay objects in the output pdf files (Two options: Y and N. Default: N)")
        {
          readYNItem(fin, line, "% Center decay objects in the output pdf files (Two options: Y and N. Default: N)", m_centDcyObjs);
        }
      else if(line=="% One output root file by one input root file (Two options: Y and N. Default: N)")
        {
          readYNItem(fin, line, "% One output root file by one input root file (Two options: Y and N. Default: N)", m_oneOptRootFlByOneIptRootFl);
        }
      else if(line=="% Maximum number of entries to be saved in a single output root file")
        {
          readNumItem(fin, line, "% Maximum number of entries to be saved in a single output root file", m_nEtrsMaxInASngOptRootFl);
        }
      else if(line=="% Use array branches to store topology tags in the output root files when possible (Two options: Y and N. Default: N)")
        {
          readYNItem(fin, line, "% Use array branches to store topology tags in the output root files when possible (Two options: Y and N. Default: N)", m_useArrayBrsOpt);
        }
      else if(line=="% Remove the input branches from the output root files (Two options: Y and N. Default: N)")
        {
          readYNItem(fin, line, "% Remove the input branches from the output root files (Two options: Y and N. Default: N)", m_rmIptBrs);
        }
      else
        {
          cerr<<"Error: The input line "<<line<<"\" is invalid!"<<endl;
          exit(-1);
        }
    }
}
