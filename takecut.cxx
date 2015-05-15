

void ReadNtuple(){

  TFile *f = new TFile("MuGe.root","READ");
  TFile *cuts = new TFile("cuts.root","READ");
  TFile *newfile = new TFile("hist.root","RECREATE");
  TH1F *seenpions = new TH1F("seenpions","seenpions",250,0,150);
  TH1F *seenpionsdecay = new TH1F("seenpionsdecay","seenpionsdecay",250,0,150);
  cuts->cd();
  TCutG *pioncut = (TCutG *)gDirectory->Get("pioncut");

  f->cd();
  float ed1,ed2,ed3,ed4,ed5,ed6,ed7,ed8,ecount,afterpulse;
  MuGe->SetBranchAddress("edep1",&ed1);
  MuGe->SetBranchAddress("edep2",&ed2);
  MuGe->SetBranchAddress("edep3",&ed3);
  MuGe->SetBranchAddress("edep4",&ed4);
  MuGe->SetBranchAddress("edep5",&ed5);
  MuGe->SetBranchAddress("edep6",&ed6);
  MuGe->SetBranchAddress("edep7",&ed7);
  MuGe->SetBranchAddress("edep8",&ed8);
  MuGe->SetBranchAddress("Ecount",&ecount);
  MuGe->SetBranchAddress("afterpulse",&afterpulse);
  for( int i=0; i<MuGe->GetEntries(); i++){
    MuGe->GetEntry(i);
    if (pioncut->IsInside(ed1+ed2+ed3+ed4+ed5+ed6, ed7+ed8)==1)
      {
	seenpions->Fill(ecount);
	if(afterpulse != 0)
	  {
	    seenpionsdecay->Fill(ecount);
	  }
      }
    
  }
  
  newfile->cd();
  seenpions->Write();
  seenpionsdecay->Write();
  f->Close();
  newfile->Close();
  cuts->Close();
}
