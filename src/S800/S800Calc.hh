#ifndef __S800CALC_HH
#define __S800CALC_HH

#include <iostream>
#include <vector>
#include <cmath>
#include "TObject.h"
using namespace std;
class S800;
class S800Calibration;

class CRDC : public TObject {
public:
   CRDC(){    
      fid = -1;
      fx = sqrt(-1.0);
      fy = sqrt(-1.0);
      fx_cog = sqrt(-1.0);
      fx_fit = sqrt(-1.0);
      ftac = sqrt(-1.0);
      fanode = sqrt(-1.0);
      fcathode = sqrt(-1.0);
      fcal.clear();
      fchan.clear();
      fxpad.clear();
      fypad.clear();
      fmaxpad =-1;
      fmaxchg = sqrt(-1.0);
      ffitprm.resize(3);
   }
   ~CRDC(){
      Clear();
   };

   void Clear(Option_t * /*option*/ ="") { // modified to suppress warnings
      fid = -1;
      fx = sqrt(-1.0);
      fy = sqrt(-1.0);
      fx_cog = sqrt(-1.0);
      fx_fit = sqrt(-1.0);
      ftac = sqrt(-1.0);
      fanode = sqrt(-1.0);
      fcathode = sqrt(-1.0);
      fcal.clear();
      fchan.clear();
      fxpad.clear();
      fypad.clear();
      fmaxpad =-1;
      fmaxchg = sqrt(-1.0);
      ffitprm.resize(3);
   }
   void SetCal(const std::vector<Float_t> & cal){
     fcal=cal;

      // for(UShort_t i=0;i<cal.size();i++){
      // 	 if(!std::isnan(cal[i])){
      // 	    fcal.push_back(cal[i]);
      // 	    fchan.push_back(i);
      // 	 }
      // }
   }
   void SetXpad(Double_t xpad[300], Int_t j) {
      for (Int_t i = 0; i < j; i++) {
	 fxpad.push_back((Int_t)xpad[i]);
      }
   }
   void SetYpad(Double_t ypad[300], Int_t j) {
      for (Int_t i = 0; i < j; i++) {
	 fypad.push_back((Float_t)ypad[i]);
      }
   }
   void SetID(int id){fid = id;}
   void SetX(Float_t x){fx = x;}
   void SetY(Float_t y){fy = y;}
   void SetXcog(Float_t x_cog){fx_cog = x_cog;}
   void SetXfit(Float_t x_fit){fx_fit = x_fit;}
   void SetTAC(float tac){ftac = tac;}
   void SetAnode(float anode){fanode = anode;}
   void SetCathode(float cathode){fcathode = cathode;}
   void SetMaxPad(Short_t maxpad){fmaxpad = maxpad;}
   void SetMaxChg(Float_t maxchg) {fmaxchg = maxchg;}
   void SetFitPrm(Short_t i, Float_t prm){ffitprm[i] = prm;}
   void SetFnorm(Float_t fnorm){ffnorm = fnorm;}
   void SetNumClusters(Int_t n){fNumClusters=n;}
   void SetMaxClusterWidth(Float_t w){fMaxClusterWidth=w;}

   Int_t GetNumClusters(){return fNumClusters;}
   Float_t GetMaxClusterWidth(){return fMaxClusterWidth;}
   
   Int_t GetID(){return fid;}
   Float_t GetX(){return fx;}
   Float_t GetY(){return fy;}
   Float_t GetXcog(){return fx_cog;}
   Float_t GetXfit(){return fx_fit;}
   Float_t GetTAC(){return ftac;}
   Float_t GetAnode(){return fanode;}
   Float_t GetCathode(){return fcathode;}
   std::vector<Float_t> GetCal(){return fcal;}
   std::vector<Int_t> GetChan(){return fchan;}
   Short_t GetMaxPad(){return fmaxpad;}
   Float_t GetMaxChg() {return fmaxchg;}
   std::vector<Float_t> GetFitPrm(){return ffitprm;}
   Float_t GetFnorm(){return ffnorm;}
   std::vector<Int_t> GetXpad(){return fxpad;}
   std::vector<Float_t> GetYpad(){return fypad;}

protected:
   Int_t fid; 
   Float_t fx;
   Float_t fy;
   Float_t fx_cog;
   Float_t fx_fit;
   Float_t ftac;
   Float_t fanode;
   Float_t fcathode;
   std::vector<Float_t> fcal;      //!
   std::vector<Int_t> fchan;       //!   
   std::vector<Float_t> fypad;     //!
   std::vector<Int_t> fxpad;       //!
   Short_t fmaxpad;              
   Float_t fmaxchg;              
   std::vector<Float_t> ffitprm;   
   Float_t ffnorm;                 
   Int_t fNumClusters;		   
   Float_t fMaxClusterWidth;       
   ClassDef(CRDC, 1);
};

//Time of flight of the beam/beam-like particle
class TOF : public TObject {
public:
   TOF(){
      frf = sqrt(-1.0);
      fobj = sqrt(-1.0);
      fxfp = sqrt(-1.0);
      frfc = sqrt(-1.0);
      ftac_obj = sqrt(-1.0);
      ftac_xfp = sqrt(-1.0);
   }
   ~TOF(){
      Clear();
   };
   void Clear(Option_t * /*option*/ ="") { // modified to suppress warnings
      //  void Clear(){
      frf = sqrt(-1.0);
      fobj = sqrt(-1.0);
      fxfp = sqrt(-1.0);
      frfc = sqrt(-1.0);
      ftac_obj = sqrt(-1.0);
      ftac_xfp = sqrt(-1.0);
   }
   void Set(Float_t rf, Float_t obj, Float_t xfp){
      frf  = rf;
      fobj = obj;
      fxfp = xfp;
   }  
   void SetTAC(Float_t obj, Float_t xfp){
      ftac_obj = obj;
      ftac_xfp = xfp;
   }  
   Float_t GetRF(){return frf;}
   Float_t GetOBJ(){return fobj;}
   Float_t GetXFP(){return fxfp;}
   Float_t GetTACOBJ(){return ftac_obj;}
   Float_t GetTACXFP(){return ftac_xfp;}

protected:
   Float_t frf;
   Float_t fobj;
   Float_t fxfp;
   Float_t frfc;
   Float_t ftac_obj;
   Float_t ftac_xfp;

   ClassDef(TOF, 1);
};

class MultiHitTOF  : public TObject {
public:
  MultiHitTOF(){
    Clear();
  }
  ~MultiHitTOF(){
    Clear();
  }

  void Clear(){
    fE1Up.clear();
    fE1Down.clear();
    fXf.clear();
    fObj.clear();
    fGalotte.clear();
    fRf.clear();
    fHodoscope.clear();
  }

  Float_t GetFirstE1UpHit(){
    if (fE1Up.size() !=0){
      return fE1Up[0];
    }else {
      return sqrt(-1.0);
    }
  }
  
  Float_t GetFirstE1DownHit(){
    if (fE1Down.size() !=0 ){
      return fE1Down[0];
    }else {
      return sqrt(-1.0);
    }
  }
  Float_t GetFirstXfHit(){
    if (fXf.size()!=0){
      return fXf[0];
    }else {
      return sqrt(-1.0);
    }
  }

  Float_t GetFirstObjHit(){
    if ( fObj.size()!=0){
      return fObj[0];
    }else {
      return sqrt(-1.0);
    }
  }

  Float_t GetFirstRfHit(){
    if ( fRf.size()!=0){
      return fRf[0];
    }else {
      return sqrt(-1.0);
    }
  }
  
  Float_t GetFirstHodoscopeHit(){
    if ( fHodoscope.size()!=0){
      return fHodoscope[0];
    }else{
      return sqrt(-1.0);
    }
  }


  vector <Float_t> fE1Up;
  vector <Float_t> fE1Down;
  vector <Float_t> fXf;
  vector <Float_t> fObj;
  vector <Float_t> fGalotte;
  vector <Float_t> fRf;
  vector <Float_t> fHodoscope;
  

  ClassDef(MultiHitTOF,1);
};


//Scintillator fp trigger scint e1/e2/e3
class SCINT : public TObject {
public:
   SCINT(){
      ftime = 0.0;
      fde = 0.0;
      fdeup = 0.0;
      fdedown = 0.0;
   }
   ~SCINT(){
      Clear();
   };
   void Clear(Option_t * /*option*/ ="") { // modified to suppress warnings
      ftime = 0.0;
      fde = 0.0;
      fdeup = 0.0;
      fdedown = 0.0;
   }
   void Set(Float_t time, Float_t de){
      ftime = time;
      fde = de;
   }
   void SetTime(Float_t tup, Float_t tdown){
      ftimeup = tup;
      ftimedown = tdown;
      ftime = (tup+tdown)/2.;
   }
   void SetDE(Float_t de_up,Float_t de_down){
      fdeup = de_up;
      fdedown = de_down;
      fde = sqrt(de_up * de_down);
   }
   Float_t GetTime(){return ftime;}
   Float_t GetTimeup(){return ftimeup;}
   Float_t GetTimedown(){return ftimedown;}
   Float_t GetDE(){return fde;}
   Float_t GetDEup(){return fdeup;}
   Float_t GetDEdown(){return fdedown;}

protected:
   Float_t ftime;
   Float_t ftimeup;
   Float_t ftimedown;
   Float_t fde;
   Float_t fdeup;
   Float_t fdedown;
   ClassDef(SCINT, 1);
};

class HODOSCOPE : public TObject {
public:
   HODOSCOPE() {
      fenergy = 0.0;
   }
   ~HODOSCOPE() {
      Clear();
   }
   void Clear(Option_t * /*option*/ ="") { // modified to suppress warnings
      fenergy = 0.0;
   }
   void SetEnergy(Float_t energy) {
      fenergy = energy;
   }
   Float_t GetEnergy() {
      return fenergy;
   }

protected:
   Float_t fenergy;
   ClassDef(HODOSCOPE,1);
};

//IONCHAMBER
class IC : public TObject {
public:
  IC(){
    fcal.clear();
    fchan.clear();
    fsum = sqrt(-1.0);
    fde = sqrt(-1.0);
  }
  ~IC(){
    Clear();
  };
  void Clear(Option_t * /*option*/ ="") { // modified to suppress warnings
    fcal.clear();
    fchan.clear();
    fsum = sqrt(-1.0);
    fde = sqrt(-1.0);
  }
   void SetCal(std::vector<Float_t> cal){
    fcal.clear();
    fchan.clear();    
    for(UShort_t i=0;i<cal.size();i++){
      if(!isnan(cal[i])&&cal[i]>0.0){
	fcal.push_back(cal[i]);
	fchan.push_back(i);
      }
    }
  }  
  void SetSum(Float_t sum){fsum = sum;}
  void SetDE(Float_t de){fde = de;}
  Float_t GetSum(){return fsum;}
  Float_t GetDE(){return fde;}

  std::vector<Float_t> GetCal(){return fcal;}
  std::vector<Int_t> GetChan(){return fchan;}

protected:
  std::vector<Float_t> fcal;
  std::vector<Int_t> fchan;
  //std::vector<Float_t> fcal; //! transient data member
  //std::vector<Int_t> fchan;  //! transient data member
  Float_t fsum;
  Float_t fde;
  ClassDef(IC, 1);
};


/**Calibrated S800 Data Structure. Contains instances of the calibrated data 
structure for each of the S800s detectors.  They are called 'CRDC', 'IC',
'TOF', 'SCINT', 'HODOSCOPE' and 'MultiHitTOF'
 */
class S800Calc : public TObject {
public:
   S800Calc(){}

   void Clear(Option_t * /*option*/ ="") { // modified to suppress warnings
      ftimes800 =0;
      fCRDC[0].Clear();
      fCRDC[1].Clear();
      fTOF.Clear();
      fSCINT[0].Clear();
      fSCINT[1].Clear();
      fSCINT[2].Clear();
      fIC.Clear();
   }

   void ApplyCalibration(S800* s800, S800Calibration* cal);

   void SetTimeS800(Float_t time){ftimes800 = time;}
   void SetCRDC(CRDC crdc, int id){fCRDC[id] = crdc;}
   void SetTOF(TOF tof){fTOF = tof;}
   void SetIC(IC ic){fIC = ic;}
   void SetSCINT(SCINT scint, int id){fSCINT[id] = scint;}
   void SetHODOSCOPE(HODOSCOPE hodoscope, int id) {fHODOSCOPE[id] = hodoscope;}
  
   void SetMultiHitTOF(MultiHitTOF f){fMultiHitTOF=f;}

   Float_t GetTimeS800(){return ftimes800;};
   CRDC* GetCRDC(int id){return &fCRDC[id];}
   TOF* GetTOF(){return &fTOF;}
   SCINT* GetSCINT(int id){return &fSCINT[id];}
   HODOSCOPE* GetHODOSCOPE(Int_t id) {return &fHODOSCOPE[id];}
   IC* GetIC(){return &fIC;}
  
   MultiHitTOF * GetMultiHitTOF(){return &fMultiHitTOF;}

   // timestamp
   void SetTS(long long int ts){fts = ts;}
   void SetInternalTS(long long int ts){fits = ts;}
   long long int GetTS(){return fts;}
   long long int GetInternalTS(){return fits;}

protected:  
   CRDC      fCRDC[2];
   IC fIC;
   TOF       fTOF;
   SCINT     fSCINT[3];
   HODOSCOPE fHODOSCOPE[32];
   Float_t       ftimes800;
   long long int fts;  //timestamp global
   long long int fits; //timestamp internal
  
  MultiHitTOF fMultiHitTOF;

   ClassDef(S800Calc, 1);
};

#endif
