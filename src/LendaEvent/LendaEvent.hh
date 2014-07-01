#ifndef __LENDA_EVENT_HH
#define __LENDA_EVENT_HH
 
#include "TObject.h" //Include ROOT
#include <vector>
#include <map>
#include "LendaSettings.hh"
#include "LendaBar.hh"
using namespace std;

class LendaEvent :  public TObject  {
public:

  LendaEvent(); //Constructor 

  void Clear(); //Clear the Event.  Should be called after every write to a tree

  void Finalize(); //Calculates convient Branches/leaves

  vector <LendaBar> Bars; //The vector of LendaBars that contains the real event information
  void PushABar(LendaBar aBar){Bars.push_back(aBar);NumBars++;}

  vector <LendaChannel> UnMappedChannels;
  void PushUnMappedChannel(LendaChannel c){UnMappedChannels.push_back(c);NumUnMappedChannels++;}

  Int_t NumOfChannelsInEvent; //The Number of channels associated with this event  
  Int_t N;//Same thing as NumOfChannelsInEvent
  Int_t NumBars;//Number of bars in event.  Due to pileup could be different from N/2

  Int_t NumUnMappedChannels;//Number of DDAS channels in the event that were not in the map file
  
  Int_t NumObjectScintillators;//Number of ObjectScintillators


  vector <LendaChannel> TheObjectScintillators;

  void Fatal();//Overload this stupid inherited method
  void WriteSettings(LendaSettings * theSettings);


private:


  
public:
  ClassDef(LendaEvent, 21);
};
#endif



