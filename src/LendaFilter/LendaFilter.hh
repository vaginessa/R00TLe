#ifndef __FILTER_HH
#define __FILTER_HH


#include <vector>
#include <iostream>

#include "TMatrixT.h"
#include "TObject.h"

using namespace std;

class LendaFilter : public TObject{

public:

  LendaFilter();
  ~LendaFilter();

  
  void FastFilter(std::vector <UShort_t> &trace,
		  std::vector <Double_t> &thisEventsFF,Double_t FL,Double_t FG);

  void FastFilterOp(std::vector <UShort_t> &trace,
		  std::vector <Double_t> &thisEventsFF,Double_t FL,Double_t FG);
  
  void FastFilterFull(std::vector <UShort_t> &trace,
		      std::vector <Double_t> &thisEventsFF,
		      Double_t FL,Double_t FG,Double_t decayTime);


  
  std::vector <Double_t> CFD( std::vector <Double_t> &,Double_t,Double_t);
  std::vector <Double_t> CFDOp( std::vector <Double_t> &,Double_t,Double_t);

  
  Double_t GetZeroCrossing(std::vector <Double_t> &,Int_t &,Double_t&);
  Double_t GetZeroCrossingImproved(std::vector <Double_t> &,Int_t &,Double_t&);
  Double_t GetZeroCrossingOp(std::vector <Double_t> &,Int_t &);

  Double_t GetZeroCubic(std::vector <Double_t> &);
  Double_t GetZeroFitCubic(std::vector <Double_t> &);   
  
  Double_t fitTrace(std::vector <UShort_t> &,Double_t, Double_t );
  
  Double_t GetEnergyOld(std::vector <UShort_t> &trace);
  Double_t GetEnergy(std::vector <UShort_t> &trace,Int_t MaxSpot);

  Double_t GetGate(std::vector <UShort_t> &trace,int start,int L);
  
  Int_t GetMaxPulseHeight(std::vector <UShort_t> &trace,Int_t &MaxSpot);
  Int_t GetMaxPulseHeight(std::vector <Double_t> &trace,Int_t &MaxSpot);

  double getFunc(TMatrixT<Double_t>, double);
  double getFunc(vector<double>&, double );

  Double_t numOfBadFits;

  Int_t GetStartForPulseShape(Int_t MaxSpot);


  Int_t CalculateCFD(vector<UShort_t> trace,vector <Double_t> & );
  vector <Double_t> GetNewFirmwareCFD(const vector<UShort_t> & trace, Int_t FL, Int_t FG, Int_t d, Int_t w);
  Double_t GetNewFirmwareCFDWeight(Int_t CFDScaleFactor);

private:


public:
  ClassDef(LendaFilter,0);
};
#endif
