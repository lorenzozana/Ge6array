/////////////////////////////////////////////////////////////////////////
//   This class has been automatically generated 
//   (at Tue Mar 27 12:59:14 2007 by ROOT version 5.10/00)
//   from TTree MuGe/MuGeillator Output
//   found on file: MuGe.root
/////////////////////////////////////////////////////////////////////////


#ifndef generatedSel_h
#define generatedSel_h

// System Headers needed by the proxy
#if defined(__CINT__) && !defined(__MAKECINT__)
   #define ROOT_Rtypes
   #define ROOT_TError
#endif
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelectorDraw.h>
#include <TPad.h>
#include <TH1.h>
#include <TBranchProxy.h>
#include <TBranchProxyDirector.h>
#include <TBranchProxyTemplate.h>
#include <TFriendProxy.h>
#include <TMethodCall.h>

using namespace ROOT;

// forward declarations needed by this particular proxy


// Header needed by this particular proxy


class generatedSel : public TSelector {
   public :
   TTree          *fChain;    //!pointer to the analyzed TTree or TChain
   TSelectorDraw  *fHelper;   //!helper class to create the default histogram
   TList          *fInput;    //!input list of the helper
   TH1            *htemp;     //!pointer to the histogram
   TBranchProxyDirector  fDirector; //!Manages the proxys

   // Optional User methods
   TClass         *fClass;    // Pointer to this class's description
   TMethodCall     fBeginMethod;
   TMethodCall     fSlaveBeginMethod;
   TMethodCall     fNotifyMethod;
   TMethodCall     fProcessMethod;
   TMethodCall     fSlaveTerminateMethod;
   TMethodCall     fTerminateMethod;

   // Proxy for each of the branches, leaves and friends of the tree
   TFloatProxy   Ecount;
   TFloatProxy   edep1;
   TFloatProxy   edep2;
   TFloatProxy   edep3;
   TFloatProxy   edep4;
   TFloatProxy   edep5;
   TFloatProxy   edep6;
   TFloatProxy   edep7;
   TFloatProxy   edep8;
   TFloatProxy   afterpulse;


   generatedSel(TTree *tree=0) : 
      fChain(0),
      fHelper(0),
      fInput(0),
      htemp(0),
      fDirector(tree,-1),
      fClass                (gROOT->GetClass("generatedSel")),
      fBeginMethod          (fClass,"Ecount_Begin","(TTree*)0"),
      fSlaveBeginMethod     (fClass,"Ecount_SlaveBegin","(TTree*)0"),
      fNotifyMethod         (fClass,"Ecount_Notify",""),
      fProcessMethod        (fClass,"Ecount_Process","0"),
      fSlaveTerminateMethod (fClass,"Ecount_SlaveTerminate",""),
      fTerminateMethod      (fClass,"Ecount_Terminate",""),
      Ecount       (&fDirector,"Ecount"),
      edep1        (&fDirector,"edep1"),
      edep2        (&fDirector,"edep2"),
      edep3        (&fDirector,"edep3"),
      edep4        (&fDirector,"edep4"),
      edep5        (&fDirector,"edep5"),
      edep6        (&fDirector,"edep6"),
      edep7        (&fDirector,"edep7"),
      edep8        (&fDirector,"edep8"),
      afterpulse   (&fDirector,"afterpulse")
      { }
   ~generatedSel();
   Int_t   Version() const {return 1;}
   void    Begin(::TTree *tree);
   void    SlaveBegin(::TTree *tree);
   void    Init(::TTree *tree);
   Bool_t  Notify();
   Bool_t  Process(Long64_t entry);
   void    SetOption(const char *option) { fOption = option; }
   void    SetObject(TObject *obj) { fObject = obj; }
   void    SetInputList(TList *input) {fInput = input;}
   TList  *GetOutputList() const { return fOutput; }
   void    SlaveTerminate();
   void    Terminate();

   ClassDef(generatedSel,0);


//inject the user's code
#include "Ecount.root"
};

#endif


#ifdef __MAKECINT__
#pragma link C++ class generatedSel;
#endif


generatedSel::~generatedSel() {
   // destructor. Clean up helpers.

   delete fHelper;
   delete fInput;
}

void generatedSel::Init(TTree *tree)
{
//   Set branch addresses
   if (tree == 0) return;
   fChain = tree;
   fDirector.SetTree(fChain);
   fHelper = new TSelectorDraw();
   fInput  = new TList();
   fInput->Add(new TNamed("varexp","0.0")); // Fake a double size histogram
   fInput->Add(new TNamed("selection",""));
   fHelper->SetInputList(fInput);
}

Bool_t generatedSel::Notify()
{
   // Called when loading a new file.
   // Get branch pointers.
   fDirector.SetTree(fChain);
   if (fNotifyMethod.IsValid()) fNotifyMethod.Execute(this);
   
   return kTRUE;
}
   

void generatedSel::Begin(TTree *tree)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
   if (fBeginMethod.IsValid()) fBeginMethod.Execute(this,Form("0x%x",tree));

}

void generatedSel::SlaveBegin(TTree *tree)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   Init(tree);

   TString option = GetOption();
   fHelper->SetOption(option);
   fHelper->Begin(tree);
   htemp = (TH1*)fHelper->GetObject();
   htemp->SetTitle("Ecount.root");
   fObject = htemp;
   if (fSlaveBeginMethod.IsValid()) {
      fSlaveBeginMethod.Execute(this,Form("0x%x",tree));
   }

}

Bool_t generatedSel::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either TTree::GetEntry() or TBranch::GetEntry()
   // to read either all or the required parts of the data. When processing
   // keyed objects with PROOF, the object is already loaded and is available
   // via the fObject pointer.
   //
   // This function should contain the "body" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.

   // WARNING when a selector is used with a TChain, you must use
   //  the pointer to the current TTree to call GetEntry(entry).
   //  The entry is always the local entry number in the current tree.
   //  Assuming that fChain is the pointer to the TChain being processed,
   //  use fChain->GetTree()->GetEntry(entry).


   fDirector.SetReadEntry(entry);
   htemp->Fill(Ecount());
   if (fProcessMethod.IsValid()) fProcessMethod.Execute(this,Form("%d",entry));
   return kTRUE;

}

void generatedSel::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.
   if (fSlaveTerminateMethod.IsValid()) fSlaveTerminateMethod.Execute(this);
}

void generatedSel::Terminate()
{
   // Function called at the end of the event loop.
   Int_t drawflag = (htemp && htemp->GetEntries()>0);
   
   if (!drawflag && !fOption.Contains("goff") && !fOption.Contains("same")) {
      gPad->Clear();
   } else {
      if (fOption.Contains("goff")) drawflag = false;
      if (drawflag) htemp->Draw(fOption);
   }
   if (fTerminateMethod.IsValid()) fTerminateMethod.Execute(this);

}
