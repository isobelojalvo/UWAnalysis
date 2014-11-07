/*
 *HHKinFit.h
 *
 *  Created on: Jun 17, 2014
 */

#ifndef HHKINFIT_H_
#define HHKINFIT_H_

#include "HHV4Vector.h"
#include "HHEventRecord.h"
#include <Rtypes.h>
#include <TH1F.h>


class HHKinFit{
public:
  HHKinFit(HHEventRecord* recrecord);
  ~HHKinFit();

  
  void FitNew();
  void Fit();
  void ConstrainE2(Int_t iv4, Int_t iv41, Int_t iv42);
  Double_t Chi2V4(Int_t iv4);
  Double_t Chi2Balance();

  //Getters
  Double_t GetChi2();
  Double_t GetChi2_b1();
  Double_t GetChi2_b2();
  Double_t GetChi2_balance();

  Double_t GetConvergence();
  Double_t GetFittedMH();

  HHEventRecord* GetFitrecord();
  double GetPullE(Int_t iv4);
  double GetPullBalance();

  
  //Setters
  void SetPrintLevel(Int_t level);
  void SetGraphicsLevel(Int_t level);
  void SetMaxLoops(Int_t loops);

  void SetAdvancedBalance(Bool_t flag);
  void SetLogLevel(Int_t level);


private:
  Double_t m_chi2;
  Double_t m_chi2_b1;
  Double_t m_chi2_b2;
  Double_t m_chi2_balance;
  Int_t m_convergence;
  Double_t m_fittedmH;

  Int_t m_printlevel;
  Int_t m_graphicslevel;

  Int_t m_maxloops;
  Bool_t m_advancedBalance;
  Int_t m_logLevel;

  HHEventRecord* m_recrecord;
  HHEventRecord* m_fitrecord;
  HHParticleList* m_particlelist;

};



#endif /* HHKINFIT_H_ */
