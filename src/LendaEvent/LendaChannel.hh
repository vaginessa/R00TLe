

////////////////////////////////////////////////////
// This is the header for the lenda channel class //
// Will hold the actual information of the event  //
////////////////////////////////////////////////////


#ifndef __LENDACHANNEL_HH
#define __LENDACHANNEL_HH

#include "TObject.h"
#include <vector>

using namespace std;

class LendaChannel : public TObject {
public:
  LendaChannel();
  ~LendaChannel();

  void Clear();
  
  inline Int_t GetChannel(){return _channel;}
  inline Int_t GetSlot(){return _slot;}
  inline Int_t GetGlobalID(){return _globalID;}

  inline Bool_t GetOverFlow(){return _overFlow;}
  inline Int_t GetNumZeroCrossings(){return _numZeroCrossings;}

  inline Double_t GetCorrectedEnergy(){return _correctedEnergy;}
  inline Double_t GetEnergy(){return _energy;}
  inline Double_t GetInternalEnergy(){return _internalEnergy;}
  inline Int_t GetPulseHeight(){return _pulseHeight;}

  inline Double_t GetTime(){return _time;}
  inline Double_t GetSoftTime(){return _softTime;}
  inline Double_t GetCubicTime(){return _cubicTime;}
  inline Double_t GetCubicFitTime(){return _cubicFitTime;}
    
  inline Double_t GetSoftwareCFD(){return _softwareCFD;}
  inline Double_t GetCubicCFD(){return _cubicCFD;}
  inline Double_t GetCubicFitCFD(){return _cubicFitCFD;}
  inline Double_t GetInternalCFD(){return _internalCFD;}

  inline Double_t GetShortGate(){return _shortGate;}
  inline Double_t GetLongGate() {return _longGate;}

  vector <UShort_t> GetTrace(){return _trace;}
  vector <Double_t> GetFilter(){return _filter;}
  vector <Double_t> GetCFD(){return _CFD;}


  void SetChannel(Int_t v){_channel=v;}
  void SetSlot(Int_t v){_slot=v;}
  void SetGlobalID(Int_t v){_globalID=v;}

  void SetOverFlow(Bool_t v){_overFlow=v;}
  void SetNumZeroCrossings(Int_t v){ _numZeroCrossings=v;}
  
  void SetCorrectedEnergy(Double_t v){ _correctedEnergy=v;}
  void SetEnergy(Double_t v){ _energy=v;}
  void SetInternalEnergy(Double_t v){_internalEnergy=v;}
  void SetPulseHeight(Int_t v){ _pulseHeight=v;}

  void SetTime(Double_t v){ _time=v;}
  void SetSoftTime(Double_t v){_softTime=v;}
  void SetCubicTime(Double_t v){_cubicTime=v;}
  void SetCubicFitTime(Double_t v){_cubicFitTime=v;}
    
  void SetSoftwareCFD(Double_t v){_softwareCFD=v;}
  void SetCubicCFD(Double_t v){_cubicCFD=v;}
  void SetCubicFitCFD(Double_t v){_cubicFitCFD=v;}
  void SetInternalCFD(Double_t v){_internalCFD=v;}

  void SetShortGate(Double_t v){_shortGate=v;}
  void SetLongGate(Double_t v) {_longGate=v;}
  
  void SetTrace(vector<UShort_t> v){_trace=v;}
  void SetFilter(vector <Double_t> v){_filter=v;}
  void SetCFD(vector <Double_t> v){_CFD=v;}



private:
  Int_t _channel;
  Int_t _slot;
  Int_t _globalID;
  
  Bool_t _overFlow;
  Int_t _numZeroCrossings;
  
  Double_t _correctedEnergy;
  Double_t _energy;
  Double_t _internalEnergy;
  Int_t _pulseHeight;

  Double_t _time;
  Double_t _softTime;
  Double_t _cubicTime;
  Double_t _cubicFitTime;
  
  Double_t _softwareCFD;
  Double_t _cubicCFD;
  Double_t _cubicFitCFD;
  Double_t _internalCFD;
  UInt_t _CFDTrigBit;

  Double_t _shortGate;
  Double_t _longGate;

  vector <UShort_t> _trace;
  vector <Double_t> _filter;
  vector <Double_t> _CFD;

public:
  ClassDef(LendaChannel,1);
};




#endif 