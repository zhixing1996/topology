#ifndef TOPOANA_H
#define TOPOANA_H

// Begin the declaration of the topoana class

#include <vector>
#include <string>
#include <list>
#include <map>
#include <climits>
#include <unordered_map>
#include "TTree.h"
#include "TChain.h"
using namespace std;

class topoana
{
  private:
    string m_pkgPath;
    string m_verNum;
    string m_cardFlNm0;
    string m_cardFlNm;

    map<int,int> m_pid3PchrgMap;
    map<int,string> m_pidTxtPnmMap;
    map<int,string> m_pidTexPnmMap;
    map<int,int> m_pidIccPMap;

    vector<string> m_nmsOfIptRootFls;
    string m_trNm;
    string m_brNmOfNps;
    string m_brNmOfPid;
    string m_brNmOfMidx;
    string m_strgTpOfRawIptTopoDat;
    unsigned long m_nEtrsMax;
    string m_cut;
    bool m_cutMethod;
    unsigned long m_hHdDcyBrsMax;
    vector<int> m_vIdPid;
    vector<int> m_vIddPid;
    bool m_ignoreGISR;
    bool m_ignoreGFSR;

    bool m_compAnaOfDcyTrs;
    unsigned long m_nDcyTrsToBePrtdMax;
    bool m_adjDcyIFStsIntoACol;
    bool m_compAnaOfDcyIFSts;
    unsigned long m_nDcyIFStsToBePrtdMax;
    vector<int> m_vPid_compDcyBrP;
    vector<unsigned long> m_vNDcyBrsToBePrtdMax;
    vector<string> m_vNm_compDcyBrP;
    vector<int> m_vPid_compProdBrP;
    vector<unsigned long> m_vNProdBrsToBePrtdMax;
    vector<string> m_vNm_compProdBrP;
    vector<int> m_vPid_compMP;
    vector<unsigned long> m_vNMsToBePrtdMax;
    vector<string> m_vNm_compMP;
    vector< vector<int> > m_vVPid_compIncDcyBr;
    vector<unsigned long> m_vNExcCompsToBePrtdMax;
    vector<string> m_vNm_compIncDcyBr;
    vector< vector<int> > m_vVPid_compIRADcyBr;
    vector<unsigned long> m_vNIntStrusToBePrtdMax;
    vector<string> m_vNm_compIRADcyBr;

    vector< vector<int> > m_vVPid_sigDcyTr;
    vector< vector<int> > m_vVMidx_sigDcyTr;
    vector<string> m_vNm_sigDcyTr;
    vector< vector<int> > m_vVPid_sigDcyIFSts2;
    vector<string> m_vNm_sigDcyIFSts2;
    vector<int> m_vPid_sigP;
    vector<string> m_vNm_sigP;
    vector< vector<int> > m_vVPid_sigDcyBr;
    vector<string> m_vNm_sigDcyBr;
    vector< vector<int> > m_vVPid_sigIncDcyBr;
    vector<string> m_vNm_sigIncDcyBr;
    vector< vector<int> > m_vVPid_sigCascDcyBrs;
    vector< vector<int> > m_vVMidx_sigCascDcyBrs;
    vector<string> m_vNm_sigCascDcyBrs;
    vector< vector<int> > m_vVPid_sigIncCascDcyBrs;
    vector< vector<int> > m_vVMidx_sigIncCascDcyBrs;
    vector<string> m_vNm_sigIncCascDcyBrs;
    vector< vector<int> > m_vVPid_sigIRADcyBr;
    vector<string> m_vNm_sigIRADcyBr;
    vector< vector<int> > m_vVPid_sigIncOrIRACascDcyBrs;
    vector< vector<int> > m_vVMidx_sigIncOrIRACascDcyBrs;
    vector<string> m_vNm_sigIncOrIRACascDcyBrs;

    bool m_ccSwitch;
    string m_anaTasksForSigIds;
    bool m_sortTheToposForSigIds;
    bool m_initEpEmSwitch;

    string m_mainNmOfOptFls;
    bool m_centDcyObjs;
    bool m_oneOptRootFlByOneIptRootFl;
    unsigned long m_nEtrsMaxInASngOptRootFl;
    bool m_useArrayBrsOpt;
    bool m_rmIptBrs;

    vector<int> m_vIdCcPid;
    vector<int> m_vIdICcPid;
    vector<int> m_vIddCcPid;
    vector<int> m_vIddICcPid;

    vector< vector< list<int> > > m_vDcyTr, m_vCcDcyTr;
    vector<int> m_vIDcyTr, m_vICcDcyTr;
    vector<int> m_vNDcyTr, m_vNCcDcyTr;
    unordered_map<string,int> m_uomDcyTr, m_uomCcDcyTr;
    vector< list<int> > m_vDcyIFSts, m_vCcDcyIFSts;
    vector<int> m_vIDcyIFSts, m_vICcDcyIFSts;
    vector<int> m_vNDcyIFSts, m_vNCcDcyIFSts;
    unordered_map<string,int> m_uomDcyIFSts, m_uomCcDcyIFSts;
    map<int,int> m_iDcyTrIDcyIFStsMap, m_iDcyTrICcDcyIFStsMap;
    vector<int> m_vPid_ccCompDcyBrP;
    vector<int> m_vICcCompDcyBrP;
    // Pay attention to that m_vVDcyBrCcP, m_vVIDcyBrCcP and m_vVNDcyBrCcP equate to m_vVCcDcyBrP, m_vVICcDcyBrP and m_vVNCcDcyBrP for self-charge-conjugate particles.
    vector< vector< list<int> > > m_vVDcyBrP, m_vVDcyBrCcP;
    vector< vector<int> > m_vVIDcyBrP, m_vVIDcyBrCcP;
    vector< vector<int> > m_vVNDcyBrP, m_vVNDcyBrCcP;
    vector<int> m_vPid_ccCompProdBrP;
    vector<int> m_vICcCompProdBrP;
    // Pay attention to that m_vVProdBrCcP, m_vVIProdBrCcP and m_vVNProdBrCcP equate to m_vVCcProdBrP, m_vVICcProdBrP and m_vVNCcProdBrP for self-charge-conjugate particles.
    vector< vector< list<int> > > m_vVProdBrP, m_vVProdBrCcP;
    vector< vector<int> > m_vVIProdBrP, m_vVIProdBrCcP;
    vector< vector<int> > m_vVNProdBrP, m_vVNProdBrCcP;
    vector<int> m_vPid_ccCompMP;
    vector<int> m_vICcCompMP;
    // Pay attention to that m_vVMCcP, m_vVIMCcP and m_vVNMCcP equate to m_vVCcMP, m_vVICcMP and m_vVNCcMP for self-charge-conjugate particles.
    vector< vector<int> > m_vVMpidP, m_vVMpidCcP;
    vector< vector<int> > m_vVIMP, m_vVIMCcP;
    vector< vector<int> > m_vVNMP, m_vVNMCcP;
    vector< list<int> > m_vCompIncDcyBr,m_vCompCcIncDcyBr;
    vector<int> m_vCompICcIncDcyBr;
    // Pay attention to that m_vVDcyBrCcIncDcyBr, m_vVIDcyBrCcIncDcyBr and m_vVNDcyBrCcIncDcyBr equate to m_vVCcDcyBrIncDcyBr, m_vVICcDcyBrIncDcyBr and m_vVNCcDcyBrIncDcyBr for self-charge-conjugate inclusive decays.
    vector< vector< list<int> > > m_vVDcyBrIncDcyBr, m_vVDcyBrCcIncDcyBr;
    vector< vector<int> > m_vVIDcyBrIncDcyBr, m_vVIDcyBrCcIncDcyBr;
    vector< vector<int> > m_vVNDcyBrIncDcyBr, m_vVNDcyBrCcIncDcyBr;
    vector< list<int> > m_vCompIRADcyBr,m_vCompCcIRADcyBr;
    vector<int> m_vCompICcIRADcyBr;
    // Pay attention to that m_vVDcyBrCcIRADcyBr, m_vVIDcyBrCcIRADcyBr and m_vVNDcyBrCcIRADcyBr equate to m_vVCcDcyBrIRADcyBr, m_vVICcDcyBrIRADcyBr and m_vVNCcDcyBrIRADcyBr for self-charge-conjugate inclusive decays.
    vector< vector< vector< list<int> > > > m_vVDcyBrIRADcyBr, m_vVDcyBrCcIRADcyBr;
    vector< vector<int> > m_vVIDcyBrIRADcyBr, m_vVIDcyBrCcIRADcyBr;
    vector< vector<int> > m_vVNDcyBrIRADcyBr, m_vVNDcyBrCcIRADcyBr;

    vector< vector< list<int> > > m_vSigDcyTr, m_vCcSigDcyTr;
    vector<int> m_vISigDcyTr, m_vICcSigDcyTr;
    vector<int> m_vNSigDcyTr, m_vNCcSigDcyTr;
    vector< list<int> > m_vSigDcyIFSts, m_vCcSigDcyIFSts;
    vector<int> m_vISigDcyIFSts, m_vICcSigDcyIFSts;
    vector<int> m_vNSigDcyIFSts, m_vNCcSigDcyIFSts;
    map<int,int> m_iSigDcyTrISigDcyIFStsMap, m_iSigDcyTrICcSigDcyIFStsMap;
    vector< list<int> > m_vSigDcyIFSts2, m_vCcSigDcyIFSts2;
    vector<int> m_vISigDcyIFSts2, m_vICcSigDcyIFSts2;
    vector<int> m_vNSigDcyIFSts2, m_vNCcSigDcyIFSts2;
    map<int,int> m_iSigDcyTrIDcyTrMap, m_iSigDcyTrICcDcyTrMap;
    map<int,int> m_iSigDcyIFStsIDcyIFStsMap, m_iSigDcyIFStsICcDcyIFStsMap;
    map<int,int> m_iSigDcyIFSts2IDcyIFStsMap, m_iSigDcyIFSts2ICcDcyIFStsMap;
    vector<int> m_vPid_ccSigP;
    vector<int> m_vISigP, m_vICcSigP;              
    vector<int> m_vNSigP, m_vNCcSigP;
    vector< list<int> > m_vSigDcyBr, m_vCcSigDcyBr;
    vector<int> m_vISigDcyBr, m_vICcSigDcyBr;
    vector<int> m_vNSigDcyBr, m_vNCcSigDcyBr;
    vector< list<int> > m_vSigIncDcyBr, m_vCcSigIncDcyBr;
    vector<int> m_vISigIncDcyBr, m_vICcSigIncDcyBr;
    vector<int> m_vNSigIncDcyBr, m_vNCcSigIncDcyBr;
    vector< vector< list<int> > > m_vSigCascDcyBrs, m_vCcSigCascDcyBrs;
    vector< vector<int> > m_vVSigCascDcyBrsIdxOfHead, m_vVCcSigCascDcyBrsIdxOfHead;
    vector< vector<int> > m_vVSigCascDcyBrsMidxOfHead, m_vVCcSigCascDcyBrsMidxOfHead;
    vector<int> m_vISigCascDcyBrs, m_vICcSigCascDcyBrs;
    vector<int> m_vNSigCascDcyBrs, m_vNCcSigCascDcyBrs;
    vector< vector< list<int> > > m_vSigIncCascDcyBrs, m_vCcSigIncCascDcyBrs;
    vector< vector<int> > m_vVSigIncCascDcyBrsIdxOfHead, m_vVCcSigIncCascDcyBrsIdxOfHead;
    vector< vector<int> > m_vVSigIncCascDcyBrsMidxOfHead, m_vVCcSigIncCascDcyBrsMidxOfHead;
    vector< vector<int> > m_vVIIncSigIncCascDcyBrs;
    vector<int> m_vISigIncCascDcyBrs, m_vICcSigIncCascDcyBrs;
    vector<int> m_vNSigIncCascDcyBrs, m_vNCcSigIncCascDcyBrs;
    vector< list<int> > m_vSigIRADcyBr, m_vCcSigIRADcyBr;
    vector<int> m_vISigIRADcyBr, m_vICcSigIRADcyBr;
    vector<int> m_vNSigIRADcyBr, m_vNCcSigIRADcyBr;
    vector< vector< list<int> > > m_vSigIncOrIRACascDcyBrs, m_vCcSigIncOrIRACascDcyBrs;
    vector< vector<int> > m_vVSigIncOrIRACascDcyBrsIdxOfHead, m_vVCcSigIncOrIRACascDcyBrsIdxOfHead;
    vector< vector<int> > m_vVSigIncOrIRACascDcyBrsMidxOfHead, m_vVCcSigIncOrIRACascDcyBrsMidxOfHead;
    vector< vector<int> > m_vVIIncSigIncOrIRACascDcyBrs;
    vector< vector<int> > m_vVIIRASigIncOrIRACascDcyBrs;
    vector<int> m_vISigIncOrIRACascDcyBrs, m_vICcSigIncOrIRACascDcyBrs;
    vector<int> m_vNSigIncOrIRACascDcyBrs, m_vNCcSigIncOrIRACascDcyBrs;

    int m_pidOfGISRGam;
    int m_pidOfGFSRGam;
    int m_pidOfISt;
    int m_pidOfAnything;
    int m_pidOfIRAFlag;
  public:
    topoana()
    {
      m_pkgPath="PKGPATH";
      m_verNum="PKGVERSION";
      m_cardFlNm0=m_pkgPath+"share/topoana.card_with_preconfigured_items";

      m_nmsOfIptRootFls.clear();
      m_brNmOfNps="nMCGen";
      m_brNmOfPid="MCGenPDG";
      m_brNmOfMidx="MCGenMothIndex";
      m_strgTpOfRawIptTopoDat="AI";
      m_nEtrsMax=ULONG_MAX; // ULONG_MAX=9223372036854775807 is the maximum unsigned long int number. 
      m_cutMethod=false;
      m_hHdDcyBrsMax=ULONG_MAX;
      m_vIdPid.clear();
      m_vIddPid.clear();
      m_ignoreGISR=false;
      m_ignoreGFSR=false;

      m_compAnaOfDcyTrs=false;
      m_nDcyTrsToBePrtdMax=ULONG_MAX;
      m_adjDcyIFStsIntoACol=false;
      m_compAnaOfDcyIFSts=false;
      m_nDcyIFStsToBePrtdMax=ULONG_MAX;

      m_vPid_compDcyBrP.clear();
      m_vNDcyBrsToBePrtdMax.clear();
      m_vNm_compDcyBrP.clear();
      m_vPid_compProdBrP.clear();
      m_vNProdBrsToBePrtdMax.clear();
      m_vNm_compProdBrP.clear();
      m_vPid_compMP.clear();
      m_vNMsToBePrtdMax.clear();
      m_vNm_compMP.clear();
      m_vVPid_compIncDcyBr.clear();
      m_vNExcCompsToBePrtdMax.clear();
      m_vNm_compIncDcyBr.clear();
      m_vVPid_compIRADcyBr.clear();
      m_vNIntStrusToBePrtdMax.clear();
      m_vNm_compIRADcyBr.clear();

      m_vVPid_sigDcyTr.clear();
      m_vVMidx_sigDcyTr.clear();
      m_vNm_sigDcyTr.clear();
      m_vVPid_sigDcyIFSts2.clear();
      m_vNm_sigDcyIFSts2.clear();
      m_vPid_sigP.clear();
      m_vNm_sigP.clear();
      m_vVPid_sigDcyBr.clear();
      m_vNm_sigDcyBr.clear();
      m_vVPid_sigIncDcyBr.clear();
      m_vNm_sigIncDcyBr.clear();
      m_vVPid_sigCascDcyBrs.clear();
      m_vVMidx_sigCascDcyBrs.clear();
      m_vNm_sigCascDcyBrs.clear();
      m_vVPid_sigIncCascDcyBrs.clear();
      m_vVMidx_sigIncCascDcyBrs.clear();
      m_vNm_sigIncCascDcyBrs.clear();
      m_vVPid_sigIRADcyBr.clear();
      m_vNm_sigIRADcyBr.clear();
      m_vVPid_sigIncOrIRACascDcyBrs.clear();
      m_vVMidx_sigIncOrIRACascDcyBrs.clear();
      m_vNm_sigIncOrIRACascDcyBrs.clear();

      m_ccSwitch=false;
      m_anaTasksForSigIds="TC";
      m_sortTheToposForSigIds=false;
      m_initEpEmSwitch=false;

      m_centDcyObjs=false;
      m_oneOptRootFlByOneIptRootFl=false;
      m_nEtrsMaxInASngOptRootFl=ULONG_MAX;
      m_useArrayBrsOpt=false;
      m_rmIptBrs=false;

      m_pidOfGISRGam=22222222;
      m_pidOfGFSRGam=-22222222;
      m_pidOfISt=99999999;
      m_pidOfAnything=-99999999;
      m_pidOfIRAFlag=100000000;
    }
    ~topoana(){}
    string         getCardFlNm0() {return m_cardFlNm0;};
    void           setCardFlNmAndDftMainNmOfOptFls(string cardFlNm);
    string         getCardFlNm() {return m_cardFlNm;};
    string &       trim(string & line);
    void           makeMapsOnPdata();
    int 	   getPidFromTxtPnm(string pnm);
    void           writeErrInfOnPid3PchrgMap(int pid);
    void           writePnmFromPid(ostream & out,string pnmType,int pid);
    void           reviseIptQts(double & Npsd, double Pidd[], double Midxd[], int & Nps, int Pid[], int Midx[]);
    void           sortByPidAndPchrg(vector<int> &via,vector<int> &vib,vector<int> &vic,vector<int> &vid);
    void           sortBySzPidAndPchrg(vector< vector<int> > &vVia,vector< vector<int> > &vVib,vector< vector<int> >&vVic,vector< vector<int> > &vVid);
    bool           cmprBySzPidAndPchrg(vector<int> & via, vector<int> & vib);
    void           recurHigherHierExchOrd(vector<int> & vNewIdx, vector<int> & vOldIdx, vector<int> & vPid, vector<int> & vMidx);
    void           recurHighHierExchOrd(vector<int> & vIdxYngi, vector<int> & vIdxYngj, vector<int> & vPid, vector<int> & vMidx);
    void           sortPs(vector<int> & vPid, vector<int> & vMidx);
    int		   getCcPid(int pid);
    void           getDcyTr(vector<int> vPid, vector<int> vMidx, vector< list<int> > & dcyTr, vector<int> * vIdxOfHead=0, vector<int> * vMidxOfHead=0, vector<int> * vIIncIncOrIRACascDcyBrs=0, vector<int> * vIIRAIncOrIRACascDcyBrs=0);
    void           sortByPidAndPchrg(list<int> &lia);
    void           getDcyIFSts(vector<int> & vPid,vector<int> & vMidx,list<int> & dcyIFSts);
    unsigned int   countIRADcyBr(vector<int> & vPid, vector<int> & vMidx, list<int> IRADcyBr, bool areHeadsRequiredToBeMatched=false,vector< vector< list<int> > > * vDcyBrIRADcyBr=0);
    void           readOpenCurly(ifstream & fin, string & line, string prompt);
    void           read1stLineOrCloseCurly(ifstream & fin, string & line, bool essential, string errinforprompt);
    void           readExtraLinesOrCloseCurly(ifstream & fin, string & line, string prompt);
    void           readCloseCurly(ifstream & fin, string & line, string prompt);
    void           readNumItem(ifstream & fin, string & line, string prompt, unsigned long & ulvar);
    void 	   readVPItem(ifstream & fin, string & line, string prompt, vector<int> & vPid);
    void 	   readYNItem(ifstream & fin, string & line, string prompt, bool & bvar);
    int 	   countSubstr(const std::string & str, const std::string & substr);
    void           readP(string & line, string prompt, vector<int> & vPid, vector<string> & vNm, vector<unsigned long> * vNMax);
    void           readPItem(ifstream & fin, string & line, string prompt, vector<int> & vPid, vector<string> & vNm, vector<unsigned long> * vNMax=0);
    void           readSmpDcyOld(string & line, string prompt, vector<int> & vPid, vector< vector<int> > & vVPid, vector<string> & vNm, vector<unsigned long> * vNMax);
    void           readSmpDcyNew(string & line, string prompt, vector< vector<int> > & vVPid, vector<string> & vNm, vector<unsigned long> * vNMax);
    void           readSmpDcyItem(ifstream & fin, string & line, string prompt, vector< vector<int> > & vVPid, vector<string> & vNm, vector<unsigned long> * vNMax=0);
    void	   getVPidandVMidx(vector< vector<int> > & vDcyBr, vector<int> & vIMDcyBr, vector<int> & vPid, vector<int> & vMidx);
    void           readCmplxDcyOld(string & line, string prompt, vector<int> & vPid, vector< vector<int> > & vVPid, vector<int> & vMidx, vector< vector<int> > & vVMidx, vector<string> & vNm, bool useAsterisk=false);
    void           readCmplxDcyNew(string & line, string prompt, vector< vector<int> > & vDcyBr, vector<int> & vIMDcyBr, vector<int> & vPid, vector<int> & vMidx, vector<string> & vNm, bool useAsterisk=false);
    void           readCmplxDcyItem(ifstream & fin, string & line, string prompt, vector< vector<int> > & vVPid, vector< vector<int> > & vVMidx, vector<string> & vNm, bool useAsterisk=false);
    void           readCard(string cardFlNm);
    void	   checkInput();
    void 	   createBrs(unsigned int size, string NM1, string NM2, string NM3, string NM4, string NM5, vector<string> vNm, vector<int> vICc, TTree * tr, unsigned int nMax, int * nq, int * iq, int * iCcq, int * nCcq, int * iqCc, int * nTotq);
    void           createBrs(unsigned int size, string NM, vector<string> vNm, vector<int> vICc, TTree * tr, int * nq, int * nCcq, int * nTotq);
    unsigned int   countIncLiaInVlib(list<int> & lia, vector< list<int> > & Vlib);
    bool	   isLiaMatchedWithLib(list<int> & lia, list<int> & lib);
    unsigned int   countCascDcyBrsInDcyTr(vector< list<int> > & cascDcyBrs, vector<int> vIdxOfHead1, vector<int> vMidxOfHead1, vector< list<int> > & dcyTr, vector<int> vIdxOfHead2, vector<int> vMidxOfHead2);
    unsigned int   countIncCascDcyBrsInDcyTr(vector<int> vIIncIncCascDcyBrs, vector< list<int> > & incCascDcyBrs, vector<int> vIdxOfHead1, vector<int> vMidxOfHead1, vector< list<int> > & dcyTr, vector<int> vIdxOfHead2, vector<int> vMidxOfHead2);
    void           getSubsetsOfVPidandVMidxFromAP(vector<int> & vPid,vector<int> & vMidx, int idx);
    bool	   isPaADescendantOfPb(vector<int> vMidx, int idxA, int idxB);
    unsigned int   countIncOrIRACascDcyBrsInDcyTr(vector<int> vIIncIncOrIRACascDcyBrs, vector<int> vIIRAIncOrIRACascDcyBrs, vector< list<int> > & incOrIRACascDcyBrs, vector<int> vIdxOfHead1, vector<int> vMidxOfHead1, vector< list<int> > & dcyTr, vector<int> vIdxOfHead2, vector<int> vMidxOfHead2, vector<int> vPid, vector<int> vMidx);
    // The following four functions will be used in the flatArrayBrs function.
    void 	   disableBrs(unsigned int size, string NM1, string NM2, string NM3, string NM4, string NM5, vector<string> vNm, vector<int> vICc, TTree * tr);
    void           activateBrs(unsigned int size, string NM1, string NM2, string NM3, string NM4, string NM5, vector<string> vNm, vector<int> vICc, TTree * tr, unsigned int * nMax, unsigned int & nMax_Max, unsigned int * nCcMax, unsigned int & nCcMax_Max);
    void           createBrs(unsigned int size, string NM1, string NM2, string NM3, string NM4, string NM5, vector<string> vNm, vector<int> vICc, TTree * tr_old, TTree * tr_new, unsigned int * nMax, unsigned int nMax_Max, unsigned int * nCcMax, unsigned int nCcMax_Max, int * nq, int * iq, int * iCcq, int * nCcq, int * iqCc);
    void           assignDftVals(unsigned int size, vector<int> vICc, unsigned int * nMax, unsigned int nMax_Max, unsigned int * nCcMax, unsigned int nCcMax_Max, int * nq, int * iq, int * iCcq, int * nCcq, int * iqCc, bool isForMoth=false);
    void           flatArrayBrs(string nmOfOptRootFl);
    void           rmIptBrs(string nmOfOptRootFl);
    template < typename T >
    void           sortBySumOf1stAnd2ndFromLrgToSml(vector<int> & via1, vector<int> & via2, vector<T> & vib1, vector<T> & vib2, vector<int> & vic1, vector<int> & vic2, vector< vector<int> > * vVid1=0, vector< vector<int> > * vVid2=0, vector< vector<int> > * vVie1=0, vector< vector<int> > * vVie2=0);
    template < typename T >
    void           sortBy1stFromLrgToSml(vector<int> & via, vector< T > & vib, vector<int> & vic, vector< vector<int> > * vVid=0, vector< vector<int> > * vVie=0);
    template < typename T >
    void           countAndSort(TChain * chn, const unsigned int size, string NM, vector<string> vNm, vector<int> vN, vector<int> vNCc, vector<T> v, vector<T> vCc, vector<int> vI, vector<int> vICc, vector< vector<int> > * vVIdxOfHead=0, vector< vector<int> > * vVCcIdxOfHead=0, vector< vector<int> > * vVMidxOfHead=0, vector< vector<int> > * vVCcMidxOfHead=0);
    void           getRslt();
    void           writeRsltIntoTxtFl();
    void           writeRsltIntoTexFl();
    void           getPdfFlFromTexFl();
    void           writeInfOnRslt();
};

// End the declaration of the topoana class

// Pay attention to that all of the template statements above and below are indispensable.

// Begin the definitions of the template member functions of the topoana class

#include <iostream>
#include <cstdlib>
#include "TBranch.h"

template < typename T >
void topoana::sortBy1stFromLrgToSml(vector<int> & via, vector<T> & vib, vector<int> & vic, vector< vector<int> > * vVid, vector< vector<int> > * vVie)
{
  if(via.size()!=vib.size()||vib.size()!=vic.size()||((vVid!=0&&vVie!=0)&&(vic.size()!=(*vVid).size()||(*vVid).size()!=(*vVie).size())))
    {
      if(vVid!=0&&vVie!=0) cerr<<"Error: The five vectors have different sizes!"<<endl;
      else cerr<<"Error: The three vectors have different sizes!"<<endl;
      cerr<<"Infor: The size of the first vector is "<<via.size()<<"."<<endl;
      cerr<<"Infor: The size of the second vector is "<<vib.size()<<"."<<endl;
      cerr<<"Infor: The size of the third vector is "<<vic.size()<<"."<<endl;
      if(vVid!=0&&vVie!=0)
        {
          cerr<<"Infor: The size of the fourth vector is "<<(*vVid).size()<<"."<<endl;
          cerr<<"Infor: The size of the fifth vector is "<<(*vVie).size()<<"."<<endl;
        }
      cerr<<"Infor: Please check them."<<endl;
      exit(-1);
    }
   
  if(via.size()==0)
    {
      if(vVid!=0&&vVie!=0) cerr<<"Infor: The sizes of the five vectors are zero!"<<endl<<endl;
      else cerr<<"Infor: The sizes of the three vectors are zero!"<<endl<<endl;
      return;
    }
  int iaTmp; T ibTmp; int icTmp; vector<int> vidTmp,vieTmp;
  for(unsigned int i=0;i<(via.size()-1);i++)
    for(unsigned int j=i+1;j<via.size();j++)
      if(via[i]<via[j])
        {
          iaTmp=via[i];
          via[i]=via[j];
          via[j]=iaTmp;
          ibTmp=vib[i];
          vib[i]=vib[j];
          vib[j]=ibTmp;
          icTmp=vic[i];
          vic[i]=vic[j];
          vic[j]=icTmp;
          if(vVid!=0&&vVie!=0)
            {
              vidTmp=(*vVid)[i];
              (*vVid)[i]=(*vVid)[j];
              (*vVid)[j]=vidTmp;
              vieTmp=(*vVie)[i];
              (*vVie)[i]=(*vVie)[j];
              (*vVie)[j]=vieTmp;
            }
        } 
}

template < typename T >
void topoana::sortBySumOf1stAnd2ndFromLrgToSml(vector<int> & via1, vector<int> & via2, vector<T> & vib1, vector<T> & vib2, vector<int> & vic1, vector<int> & vic2, vector< vector<int> > * vVid1, vector< vector<int> > * vVid2, vector< vector<int> > * vVie1, vector< vector<int> > * vVie2)
{
  if(via1.size()!=via2.size()||via2.size()!=vib1.size()||vib1.size()!=vib2.size()||vib2.size()!=vic1.size()||vic1.size()!=vic2.size()||((vVid1!=0&&vVid2!=0&&vVie1!=0&&vVie2!=0)&&(vic2.size()!=(*vVid1).size()||(*vVid1).size()!=(*vVid2).size()||(*vVid2).size()!=(*vVie1).size()||(*vVie1).size()!=(*vVie2).size())))
    {
      if(vVid1!=0&&vVid2!=0&&vVie1!=0&&vVie2!=0) cerr<<"Error: The ten vectors have different sizes!"<<endl;
      else cerr<<"Error: The six vectors have different sizes!"<<endl;
      cerr<<"Infor: The size of the first vector is "<<via1.size()<<"."<<endl;
      cerr<<"Infor: The size of the second vector is "<<via2.size()<<"."<<endl;
      cerr<<"Infor: The size of the third vector is "<<vib1.size()<<"."<<endl;
      cerr<<"Infor: The size of the fourth vector is "<<vib2.size()<<"."<<endl;
      cerr<<"Infor: The size of the fifth vector is "<<vic1.size()<<"."<<endl;
      cerr<<"Infor: The size of the sixth vector is "<<vic2.size()<<"."<<endl;
      if(vVid1!=0&&vVid2!=0&&vVie1!=0&&vVie2!=0)
        {
          cerr<<"Infor: The size of the seventh vector is "<<(*vVid1).size()<<"."<<endl;
          cerr<<"Infor: The size of the eighth vector is "<<(*vVid2).size()<<"."<<endl;
          cerr<<"Infor: The size of the ninth vector is "<<(*vVie1).size()<<"."<<endl;
          cerr<<"Infor: The size of the tenth vector is "<<(*vVie2).size()<<"."<<endl;
        }
      cerr<<"Infor: Please check them."<<endl;
      exit(-1);
    }
  if(via1.size()==0)
    {
      if(vVid1!=0&&vVid2!=0&&vVie1!=0&&vVie2!=0) cerr<<"Infor: The sizes of the ten vectors are zero!"<<endl<<endl;
      else cerr<<"Infor: The sizes of the six vectors are zero!"<<endl<<endl;
      return;
    }
  int iaTmp1,iaTmp2; T ibTmp1,ibTmp2; int icTmp1,icTmp2; vector<int> vidTmp1,vidTmp2,vieTmp1,vieTmp2;
  for(unsigned int i=0;i<(via1.size()-1);i++)
    for(unsigned int j=i+1;j<via1.size();j++)
      if(via1[i]+via2[i]<via1[j]+via2[j])
        {
          iaTmp1=via1[i];
          via1[i]=via1[j];
          via1[j]=iaTmp1;
          iaTmp2=via2[i];
          via2[i]=via2[j];
          via2[j]=iaTmp2;
          ibTmp1=vib1[i];
          vib1[i]=vib1[j];
          vib1[j]=ibTmp1;
          ibTmp2=vib2[i];
          vib2[i]=vib2[j];
          vib2[j]=ibTmp2;
          icTmp1=vic1[i];
          vic1[i]=vic1[j];
          vic1[j]=icTmp1;
          icTmp2=vic2[i];
          vic2[i]=vic2[j];
          vic2[j]=icTmp2;
          if(vVid1!=0&&vVid2!=0&&vVie1!=0&&vVie2!=0)
            {
              vidTmp1=(*vVid1)[i];
              (*vVid1)[i]=(*vVid1)[j];
              (*vVid1)[j]=vidTmp1;
              vidTmp2=(*vVid2)[i];
              (*vVid2)[i]=(*vVid2)[j];
              (*vVid2)[j]=vidTmp2;
              vieTmp1=(*vVie1)[i];
              (*vVie1)[i]=(*vVie1)[j];
              (*vVie1)[j]=vieTmp1;
              vieTmp2=(*vVie2)[i];
              (*vVie2)[i]=(*vVie2)[j];
              (*vVie2)[j]=vieTmp2;
            }
        }
}

template < typename T >
void topoana::countAndSort(TChain * chn, const unsigned int size, string NM, vector<string> vNm, vector<int> vN, vector<int> vNCc, vector<T> v, vector<T> vCc, vector<int> vI, vector<int> vICc, vector< vector<int> > * vVIdxOfHead, vector< vector<int> > * vVCcIdxOfHead, vector< vector<int> > * vVMidxOfHead, vector< vector<int> > * vVCcMidxOfHead)
{
  if(m_anaTasksForSigIds=="C")
    { 
      int nq[size],nCcq[size];
      char specifier[100];
      if(m_useArrayBrsOpt==true)
        {
          sprintf(specifier, "n%s", NM.c_str()); 
          chn->SetBranchAddress(specifier, &nq);
          if(m_ccSwitch==true)
            {
              sprintf(specifier, "nCc%s", NM.c_str());
              chn->SetBranchAddress(specifier, &nCcq);
            }
        }
      else
        { 
          for(unsigned int i=0;i<size;i++)
            { 
              sprintf(specifier, "n%s_%s", NM.c_str(), vNm[i].c_str());
              chn->SetBranchAddress(specifier, &nq[i]);
              if(m_ccSwitch==true)
                { 
                  sprintf(specifier, "nCc%s_%s", NM.c_str(), vNm[i].c_str());
                  chn->SetBranchAddress(specifier, &nCcq[i]);
                }
            }
        }
      for(unsigned int i=0;i<chn->GetEntries();i++)
        { 
          chn->GetEntry(i);
          for(unsigned int j=0;j<size;j++)
            { 
              vN[j]=vN[j]+nq[j];
              if(m_ccSwitch==true) vNCc[j]=vNCc[j]+nCcq[j];
            }
        }
    }
  if(m_sortTheToposForSigIds==true)
    {
      if(m_ccSwitch==true)
        {
          if(vVIdxOfHead==0&&vVCcIdxOfHead==0&&vVMidxOfHead==0&&vVCcMidxOfHead==0) sortBySumOf1stAnd2ndFromLrgToSml(vN, vNCc, v, vCc, vI, vICc);
          else sortBySumOf1stAnd2ndFromLrgToSml(vN, vNCc, v, vCc, vI, vICc, vVIdxOfHead, vVCcIdxOfHead, vVMidxOfHead, vVCcMidxOfHead);
        }
      else
        {
          if(vVIdxOfHead==0&&vVCcIdxOfHead==0&&vVMidxOfHead==0&&vVCcMidxOfHead==0) sortBy1stFromLrgToSml(vN, v, vI);
          else sortBy1stFromLrgToSml(vN, v, vI, vVIdxOfHead, vVMidxOfHead);
        }
    }
}

// End the definitions of the template member functions of the topoana class

#endif
