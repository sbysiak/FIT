#include "Riostream.h"

// fname = "2019MuonTestData.root"
int ReadTree2_nocuts(TString fname,
                    TString nameTop1="2159", TString nameTop2="2158",  TString nameBottom1="2156", TString nameBottom2="2154",
                    TString quadrant="1", TString fout_core="mytmp_nocuts", TString MODE="single",
                    float ftop2_cut1 = 0.0, float ftop2_cut2 = 50.0, float ftop2_cut3 = 5.0, float ftop1_cut1 = 20.0, float fbottom2_cut1 = 5.0)
{
  using namespace std;

  gStyle->SetTitleOffset(1.4,"Y");
  TFile *f = new TFile(fname);
  TTree *t1 = (TTree*)f->Get("RawDataTree");
  struct main{
    float Amplitude;
    float Time;
    float Time_pol1;
    float Time_pol3;
    float ZeroLevel;
    float ZeroLevelRMS;
    float time_peak;
    float time_begin;
    float time_end;
    float time_front_end;
    float time_back_begin;
    float Charge_GATE;
  };
  main main_top1_1;
  main main_top1_2;
  main main_top1_3;
  main main_top1_4;
  main main_top2_1;
  main main_top2_2;
  main main_top2_3;
  main main_top2_4;
  main main_bottom1_1;
  main main_bottom1_2;
  main main_bottom1_3;
  main main_bottom1_4;
  main main_bottom2_1;
  main main_bottom2_2;
  main main_bottom2_3;
  main main_bottom2_4;
  main main_top1_1_main_bottom2_1;
  main main_top1_1_main_bottom1_1;
  main main_top2_1_main_bottom2_1;
  main main_top2_1_main_bottom1_1;
  main main_top2_1_Time_pol1;
  main main_top2_2_Time_pol1;
  main main_top2_3_Time_pol1;
  main main_top2_4_Time_pol1;


  int n_bins = 125;
  t1->SetBranchAddress("main_"+nameTop1+"_1",&main_top1_1);
  TH1F *hmain_top1_1 = new TH1F("hmain_"+nameTop1+"_1","amplitude "+nameTop1+".1",n_bins,0.0,500);
  t1->SetBranchAddress("main_"+nameTop1+"_2",&main_top1_2);
  TH1F *hmain_top1_2 = new TH1F("hmain_"+nameTop1+"_2","amplitude "+nameTop1+".2",n_bins,0.0,500);
  t1->SetBranchAddress("main_"+nameTop1+"_3",&main_top1_3);
  TH1F *hmain_top1_3 = new TH1F("hmain_"+nameTop1+"_3","amplitude "+nameTop1+".3",n_bins,0.0,500);
  t1->SetBranchAddress("main_"+nameTop1+"_4",&main_top1_4);
  TH1F *hmain_top1_4 = new TH1F("hmain_"+nameTop1+"_4","amplitude "+nameTop1+".4",n_bins,0.0,500);
  t1->SetBranchAddress("main_"+nameTop2+"_1",&main_top2_1);
  TH1F *hmain_top2_1 = new TH1F("hmain_"+nameTop2+"_1","amplitude "+nameTop2+".1",n_bins,0.0,500);
  t1->SetBranchAddress("main_"+nameTop2+"_2",&main_top2_2);
  TH1F *hmain_top2_2 = new TH1F("hmain_"+nameTop2+"_2","amplitude "+nameTop2+".2",n_bins,0.0,500);
  t1->SetBranchAddress("main_"+nameTop2+"_3",&main_top2_3);
  TH1F *hmain_top2_3 = new TH1F("hmain_"+nameTop2+"_3","amplitude "+nameTop2+".3",n_bins,0.0,500);
  t1->SetBranchAddress("main_"+nameTop2+"_4",&main_top2_4);
  TH1F *hmain_top2_4 = new TH1F("hmain_"+nameTop2+"_4","amplitude "+nameTop2+".4",n_bins,0.0,500);
  t1->SetBranchAddress("main_"+nameBottom1+"_1",&main_bottom1_1);
  TH1F *hmain_bottom1_1 = new TH1F("hmain_"+nameBottom1+"_1","amplitude "+nameBottom1+".1",n_bins,0.0,500);
  t1->SetBranchAddress("main_"+nameBottom1+"_2",&main_bottom1_2);
  TH1F *hmain_bottom1_2 = new TH1F("hmain_"+nameBottom1+"_2","amplitude "+nameBottom1+".2",n_bins,0.0,500);
  t1->SetBranchAddress("main_"+nameBottom1+"_3",&main_bottom1_3);
  TH1F *hmain_bottom1_3 = new TH1F("hmain_"+nameBottom1+"_3","amplitude "+nameBottom1+".3",n_bins,0.0,500);
  t1->SetBranchAddress("main_"+nameBottom1+"_4",&main_bottom1_4);
  TH1F *hmain_bottom1_4 = new TH1F("hmain_"+nameBottom1+"_4","amplitude "+nameBottom1+".4",n_bins,0.0,500);
  t1->SetBranchAddress("main_"+nameBottom2+"_1",&main_bottom2_1);
  TH1F *hmain_bottom2_1 = new TH1F("hmain_"+nameBottom2+"_1","amplitude "+nameBottom2+".1",n_bins,0.0,500);
  t1->SetBranchAddress("main_"+nameBottom2+"_2",&main_bottom2_2);
  TH1F *hmain_bottom2_2 = new TH1F("hmain_"+nameBottom2+"_2","amplitude "+nameBottom2+".2",n_bins,0.0,500);
  t1->SetBranchAddress("main_"+nameBottom2+"_3",&main_bottom2_3);
  TH1F *hmain_bottom2_3 = new TH1F("hmain_"+nameBottom2+"_3","amplitude "+nameBottom2+".3",n_bins,0.0,500);
  t1->SetBranchAddress("main_"+nameBottom2+"_4",&main_bottom2_4);
  TH1F *hmain_bottom2_4 = new TH1F("hmain_"+nameBottom2+"_4","amplitude "+nameBottom2+".4",n_bins,0.0,500);

  TH2F *hmain_top1_main_bottom2 = new TH2F("hmain_"+nameTop1+"_"+quadrant+"_main_"+nameBottom2+"_"+quadrant+"","amplitude "+nameTop1+"."+quadrant+" v. "+nameBottom2+"."+quadrant,150,0.0,300,150,0.0,300);
  TH2F *hmain_top1_main_bottom1 = new TH2F("hmain_"+nameTop1+"_"+quadrant+"_main_"+nameBottom1+"_"+quadrant+"","amplitude "+nameTop1+"."+quadrant+" v. "+nameBottom1+"."+quadrant,150,0.0,300,150,0.0,300);
  TH2F *hmain_top2_main_bottom2 = new TH2F("hmain_"+nameTop2+"_"+quadrant+"_main_"+nameBottom2+"_"+quadrant+"","amplitude "+nameTop2+"."+quadrant+" v. "+nameBottom2+"."+quadrant,150,0.0,300,150,0.0,300);
  TH2F *hmain_top2_main_bottom1 = new TH2F("hmain_"+nameTop2+"_"+quadrant+"_main_"+nameBottom1+"_"+quadrant+"","amplitude "+nameTop2+"."+quadrant+" v. "+nameBottom1+"."+quadrant,150,0.0,300,150,0.0,300);

  TH2F *hmain_top2_1_Time_pol1 = new TH2F("hmain_"+nameTop2+"_1_Time_pol1","amplitude "+nameTop2+".1 v. Time Pol_1",150,0.0,300,150,0.0,300);
  TH2F *hmain_top2_2_Time_pol1 = new TH2F("hmain_"+nameTop2+"_2_Time_pol1","amplitude "+nameTop2+".2 v. Time Pol_1",150,0.0,300,150,0.0,300);
  TH2F *hmain_top2_3_Time_pol1 = new TH2F("hmain_"+nameTop1+"_3_Time_pol1","amplitude "+nameTop2+".3 v. Time Pol_1",150,0.0,300,150,0.0,300);
  TH2F *hmain_top2_4_Time_pol1 = new TH2F("hmain_"+nameTop1+"_4_Time_pol1","amplitude "+nameTop2+".4 v. Time Pol_1",150,0.0,300,150,0.0,300);

  bool  bbottom2_cut_1 = 0; // if _1 >
  bool  btop2_cut_1    = 0; // if _1 >
  bool  btop2_cut_2    = 0; // if _3 <
  bool  btop2_cut_3    = 0; // if _2 and _4 >
  bool  btop1_cut_1    = 0; // if _1-4 <


  t1->Print();

  Int_t nentries = (Int_t)t1->GetEntries();
  /********************* CUTS CHANGES ******************************/

  for (Int_t i=0; i<nentries; i++) {

    bbottom2_cut_1 = 0;
    btop2_cut_1    = 0;
    btop2_cut_2    = 0;
    btop2_cut_3    = 0;
    btop1_cut_1    = 0;

    t1->GetEntry(i);

    if((main_top1_1.Amplitude < ftop1_cut1)&&(main_top1_2.Amplitude < ftop1_cut1)&&(main_top1_3.Amplitude < ftop1_cut1)&&(main_top1_4.Amplitude < ftop1_cut1))
      btop1_cut_1 = 1;


    if (quadrant.EqualTo("1")){
      // same below
      if(main_bottom2_1.Amplitude > fbottom2_cut1)
        bbottom2_cut_1 = 1;

      // quadrant under study
      if(main_top2_1.Amplitude > ftop2_cut1)
        btop2_cut_1 = 1;

      // diagonal
      if(main_top2_3.Amplitude < ftop2_cut2)
        btop2_cut_2 = 1;

      // neighbours
      if((main_top2_2.Amplitude > ftop2_cut3)&&(main_top2_4.Amplitude > ftop2_cut3))
        btop2_cut_3 = 1;
    }

    if (quadrant.EqualTo("2")){
        // same below
        if(main_bottom2_2.Amplitude > fbottom2_cut1)
          bbottom2_cut_1 = 1;

        // quadrant under study
        if(main_top2_2.Amplitude > ftop2_cut1)
          btop2_cut_1 = 1;

        // diagonal
        if(main_top2_4.Amplitude < ftop2_cut2)
          btop2_cut_2 = 1;

        // neighbours
        if((main_top2_1.Amplitude > ftop2_cut3)&&(main_top2_3.Amplitude > ftop2_cut3))
          btop2_cut_3 = 1;
      }

    if (quadrant.EqualTo("3")){
        // same below
        if(main_bottom2_3.Amplitude > fbottom2_cut1)
          bbottom2_cut_1 = 1;

        // quadrant under study
        if(main_top2_3.Amplitude > ftop2_cut1)
          btop2_cut_1 = 1;

        // diagonal
        if(main_top2_1.Amplitude < ftop2_cut2)
          btop2_cut_2 = 1;

        // neighbours
        if((main_top2_2.Amplitude > ftop2_cut3)&&(main_top2_4.Amplitude > ftop2_cut3))
          btop2_cut_3 = 1;
      }

    if (quadrant.EqualTo("4")){
        // same below
        if(main_bottom2_4.Amplitude > fbottom2_cut1)
          bbottom2_cut_1 = 1;

        // quadrant under study
        if(main_top2_4.Amplitude > ftop2_cut1)
          btop2_cut_1 = 1;

        // diagonal
        if(main_top2_2.Amplitude < ftop2_cut2)
          btop2_cut_2 = 1;

        // neighbours
        if((main_top2_1.Amplitude > ftop2_cut3)&&(main_top2_3.Amplitude > ftop2_cut3))
          btop2_cut_3 = 1;
      }
  /********************* CUTS CHANGES ******************************/

  // if(btop2_cut_1 && btop2_cut_2 && btop1_cut_1 && btop2_cut_3 && bbottom2_cut_1)
   {
    hmain_top1_1->Fill(main_top1_1.Amplitude);
    hmain_top1_2->Fill(main_top1_2.Amplitude);
    hmain_top1_3->Fill(main_top1_3.Amplitude);
    hmain_top1_4->Fill(main_top1_4.Amplitude);
    hmain_top2_1->Fill(main_top2_1.Amplitude);
    hmain_top2_2->Fill(main_top2_2.Amplitude);
    hmain_top2_3->Fill(main_top2_3.Amplitude);
    hmain_top2_4->Fill(main_top2_4.Amplitude);
    hmain_bottom1_1->Fill(main_bottom1_1.Amplitude);
    hmain_bottom1_2->Fill(main_bottom1_2.Amplitude);
    hmain_bottom1_3->Fill(main_bottom1_3.Amplitude);
    hmain_bottom1_4->Fill(main_bottom1_4.Amplitude);
    hmain_bottom2_1->Fill(main_bottom2_1.Amplitude);
    hmain_bottom2_2->Fill(main_bottom2_2.Amplitude);
    hmain_bottom2_3->Fill(main_bottom2_3.Amplitude);
    hmain_bottom2_4->Fill(main_bottom2_4.Amplitude);

    if (quadrant.EqualTo("1")){
      hmain_top1_main_bottom2->Fill(main_bottom2_1.Amplitude,main_top1_1.Amplitude);
      hmain_top1_main_bottom1->Fill(main_bottom1_1.Amplitude,main_top1_1.Amplitude);
      hmain_top2_main_bottom2->Fill(main_bottom2_1.Amplitude,main_top2_1.Amplitude);
      hmain_top2_main_bottom1->Fill(main_bottom1_1.Amplitude,main_top2_1.Amplitude);
    }

    if (quadrant.EqualTo("2")){
      hmain_top1_main_bottom2->Fill(main_bottom2_2.Amplitude,main_top1_2.Amplitude);
      hmain_top1_main_bottom1->Fill(main_bottom1_2.Amplitude,main_top1_2.Amplitude);
      hmain_top2_main_bottom2->Fill(main_bottom2_2.Amplitude,main_top2_2.Amplitude);
      hmain_top2_main_bottom1->Fill(main_bottom1_2.Amplitude,main_top2_2.Amplitude);
    }

    if (quadrant.EqualTo("3")){
      hmain_top1_main_bottom2->Fill(main_bottom2_3.Amplitude,main_top1_3.Amplitude);
      hmain_top1_main_bottom1->Fill(main_bottom1_3.Amplitude,main_top1_3.Amplitude);
      hmain_top2_main_bottom2->Fill(main_bottom2_3.Amplitude,main_top2_3.Amplitude);
      hmain_top2_main_bottom1->Fill(main_bottom1_3.Amplitude,main_top2_3.Amplitude);
    }

    if (quadrant.EqualTo("4")){
      hmain_top1_main_bottom2->Fill(main_bottom2_4.Amplitude,main_top1_4.Amplitude);
      hmain_top1_main_bottom1->Fill(main_bottom1_4.Amplitude,main_top1_4.Amplitude);
      hmain_top2_main_bottom2->Fill(main_bottom2_4.Amplitude,main_top2_4.Amplitude);
      hmain_top2_main_bottom1->Fill(main_bottom1_4.Amplitude,main_top2_4.Amplitude);
    }


    hmain_top2_1_Time_pol1->Fill(main_top2_1.Amplitude,main_top2_1.Time_pol1);
    hmain_top2_2_Time_pol1->Fill(main_top2_2.Amplitude,main_top2_2.Time_pol1);
    hmain_top2_3_Time_pol1->Fill(main_top2_3.Amplitude,main_top2_3.Time_pol1);
    hmain_top2_4_Time_pol1->Fill(main_top2_4.Amplitude,main_top2_4.Time_pol1);
    }

  }

  //
  // /******** FITTING ******/
  //
  // TH1F* h_to_fit = 0;
  // if(quadrant.EqualTo("1")) h_to_fit = hmain_top2_1;
  // if(quadrant.EqualTo("2")) h_to_fit = hmain_top2_2;
  // if(quadrant.EqualTo("3")) h_to_fit = hmain_top2_3;
  // if(quadrant.EqualTo("4")) h_to_fit = hmain_top2_4;
  //
  //
  // // TString MODE = "LR";
  //
  // int n_fit_iter = 0;
  // float offset_magn = 0;
  // TString fname_suffix = "";
  // int high_sign = -1;
  //
  // if(MODE.EqualTo("single")){  // single fit
  //    n_fit_iter = 1;
  //    offset_magn = 0;
  //    fname_suffix = "";
  // }
  // if(MODE.EqualTo("LR")){     // fits on range moved left and right
  //    n_fit_iter = 3;
  //    offset_magn = 10;
  //    fname_suffix = "LR";
  //    high_sign = +1;
  // }
  // if(MODE.EqualTo("WN")){     // fits on wider and more narrow range
  //    n_fit_iter = 3;
  //    offset_magn = 10;
  //    fname_suffix = "WN";
  //    high_sign = -1;
  // }
  // for(int iter=0; iter<n_fit_iter; ++iter){
  //     int n = 6;
  //     // Double_t q[n]  = {0.05, 0.1, 0.25, 0.5, 0.75, 0.9, 0.95, 0.97, 0.98, 0.99};
  //     // const char qt[n][10] = {"0.05", "0.10", "0.25", "0.5", "0.75", "0.90", "0.95", "0.97", "0.98", "0.99"};
  //     TH1F* h_quantiles = (TH1F*) h_to_fit->Clone();
  //     for(int i=1; i<h_quantiles->GetNbinsX(); i++){
  //         if(h_quantiles->GetBinCenter(i) < 30) h_quantiles->SetBinContent(i,0);
  //     }
  //
  //
  //     Double_t q[6]  = {0.10, 0.20, 0.5, 0.75, 0.9, 0.95};
  //     const char qt[6][10] = {"0.25", "0.5", "0.75", "0.90", "0.95"};
  //     Double_t qv[6];
  //     h_quantiles->GetQuantiles(n, qv, q);
  //
  //     gStyle->SetOptFit(1111);
  //     gStyle->SetOptLogy(1);
  //
  //     // for perturbing fit range
  //     // low and high with same sign = move left - right
  //     // low and high different sign = more narrow - wider
  //     // change file names accordingly
  //     float offset = (iter-1)*offset_magn;
  //     float low = TMath::Max(qv[1], 30.0) + offset;
  //     float high = qv[4] + high_sign*offset;
  //     TFitResultPtr fit = h_to_fit->Fit("gaus", "IS", "", low, high);
  //     // fit = ptr.Get();
  //
  //     TCanvas* c_fit = new TCanvas("c_fit", "c_fit", 600, 600);
  //     h_to_fit->Draw();
  //
  //     TLine *l = new TLine();
  //     TText *t = new TText();
  //     t->SetTextSize(50);
  //     for(int i=0; i<n; i++){
  //         Double_t v = qv[i];
  //         l->DrawLine(v, 20, v, 30);
  //         t->DrawText(v-10, 10 + TMath::Power(-1,i)*5, qt[i]);
  //         // l.Draw();
  //         // t.Draw();
  //     }
  //     l->DrawLine(low, 25, low, 35);
  //     l->DrawLine(high, 25, high, 35);
  //
  //     // c_fit->SaveAs("fit.png");
  //     c_fit->SaveAs("fits/cfit_"+fout_core+"_"+nameTop1+"_"+nameTop2+"_"+nameBottom1+"_"+nameBottom2+"_q"+quadrant+"_"+fname_suffix+to_string(iter)+".pdf");
  //     c_fit->SaveAs("fits/cfit_"+fout_core+"_"+nameTop1+"_"+nameTop2+"_"+nameBottom1+"_"+nameBottom2+"_q"+quadrant+"_"+fname_suffix+to_string(iter)+".png");
  //     gStyle->SetOptLogy(0);
  // }
  //
  // /******** FITTING ******/

  hmain_top1_1->GetXaxis()->SetTitle("amplitude [mV]");
  hmain_top1_1->GetYaxis()->SetTitle("counts");
  hmain_top1_2->GetXaxis()->SetTitle("amplitude [mV]");
  hmain_top1_2->GetYaxis()->SetTitle("counts");
  hmain_top1_3->GetXaxis()->SetTitle("amplitude [mV]");
  hmain_top1_3->GetYaxis()->SetTitle("counts");
  hmain_top1_4->GetXaxis()->SetTitle("amplitude [mV]");
  hmain_top1_4->GetYaxis()->SetTitle("counts");
  hmain_top2_1->GetXaxis()->SetTitle("amplitude [mV]");
  hmain_top2_1->GetYaxis()->SetTitle("counts");
  hmain_top2_2->GetXaxis()->SetTitle("amplitude [mV]");
  hmain_top2_2->GetYaxis()->SetTitle("counts");
  hmain_top2_3->GetXaxis()->SetTitle("amplitude [mV]");
  hmain_top2_3->GetYaxis()->SetTitle("counts");
  hmain_top2_4->GetXaxis()->SetTitle("amplitude [mV]");
  hmain_top2_4->GetYaxis()->SetTitle("counts");
  hmain_bottom1_1->GetXaxis()->SetTitle("amplitude [mV]");
  hmain_bottom1_1->GetYaxis()->SetTitle("counts");
  hmain_bottom1_2->GetXaxis()->SetTitle("amplitude [mV]");
  hmain_bottom1_2->GetYaxis()->SetTitle("counts");
  hmain_bottom1_3->GetXaxis()->SetTitle("amplitude [mV]");
  hmain_bottom1_3->GetYaxis()->SetTitle("counts");
  hmain_bottom1_4->GetXaxis()->SetTitle("amplitude [mV]");
  hmain_bottom1_4->GetYaxis()->SetTitle("counts");
  hmain_bottom2_1->GetXaxis()->SetTitle("amplitude [mV]");
  hmain_bottom2_1->GetYaxis()->SetTitle("counts");
  hmain_bottom2_2->GetXaxis()->SetTitle("amplitude [mV]");
  hmain_bottom2_2->GetYaxis()->SetTitle("counts");
  hmain_bottom2_3->GetXaxis()->SetTitle("amplitude [mV]");
  hmain_bottom2_3->GetYaxis()->SetTitle("counts");
  hmain_bottom2_4->GetXaxis()->SetTitle("amplitude [mV]");
  hmain_bottom2_4->GetYaxis()->SetTitle("counts");

  hmain_top1_main_bottom2->GetXaxis()->SetTitle(""+nameBottom2+"."+quadrant);
  hmain_top1_main_bottom2->GetYaxis()->SetTitle(""+nameTop1+"."+quadrant);
  hmain_top1_main_bottom1->GetXaxis()->SetTitle(""+nameBottom1+"."+quadrant);
  hmain_top1_main_bottom1->GetYaxis()->SetTitle(""+nameTop1+"."+quadrant);
  hmain_top2_main_bottom2->GetXaxis()->SetTitle(""+nameBottom2+"."+quadrant);
  hmain_top2_main_bottom2->GetYaxis()->SetTitle(""+nameTop2+"."+quadrant);
  hmain_top2_main_bottom1->GetXaxis()->SetTitle(""+nameBottom1+"."+quadrant);
  hmain_top2_main_bottom1->GetYaxis()->SetTitle(""+nameTop2+"."+quadrant);

  gStyle->SetOptFit(1111);
  gStyle->SetOptLogy(1);
  //Begin->SetOptLogy();
  TCanvas *c1 = new TCanvas("c1","c1",1500,1500);

  c1->Divide(4,4);
  c1->cd(1);
  hmain_top1_1->Draw();
  c1->cd(2);
  hmain_top1_2->Draw();
  c1->cd(3);
  hmain_top1_3->Draw();
  c1->cd(4);
  hmain_top1_4->Draw();
  c1->cd(5);
  hmain_top2_1->Draw();
  c1->cd(6);
  hmain_top2_2->Draw();
  c1->cd(7);
  hmain_top2_3->Draw();
  c1->cd(8);
  hmain_top2_4->Draw();
  c1->cd(9);
  hmain_bottom1_1->Draw();
  c1->cd(10);
  hmain_bottom1_2->Draw();
  c1->cd(11);
  hmain_bottom1_3->Draw();
  c1->cd(12);
  hmain_bottom1_4->Draw();
  c1->cd(13);
  hmain_bottom2_1->Draw();
  c1->cd(14);
  hmain_bottom2_2->Draw();
  c1->cd(15);
  hmain_bottom2_3->Draw();
  c1->cd(16);
  hmain_bottom2_4->Draw();
  c1->SaveAs("c1_"+fout_core+"_"+nameTop1+"_"+nameTop2+"_"+nameBottom1+"_"+nameBottom2+"_q"+quadrant+".pdf");
  c1->SaveAs("c1_"+fout_core+"_"+nameTop1+"_"+nameTop2+"_"+nameBottom1+"_"+nameBottom2+"_q"+quadrant+".png");
  //End->SetOptLogy();


  gStyle->SetOptLogy(0);

  gStyle->SetOptLogz(1);
  //Begin->SetOptLogz();
  TCanvas *c2 = new TCanvas("c2","c2",1500,1500);

  c2->Divide(2,2);
  c2->cd(1);
  hmain_top1_main_bottom2->Draw("colz");
  c2->cd(2);
  hmain_top1_main_bottom1->Draw("colz");
  c2->cd(3);
  hmain_top2_main_bottom2->Draw("colz");
  c2->cd(4);
  hmain_top2_main_bottom1->Draw("colz");
  c2->SaveAs("c2_"+fout_core+"_"+nameTop1+"_"+nameTop2+"_"+nameBottom1+"_"+nameBottom2+"_q"+quadrant+".pdf");
  c2->SaveAs("c2_"+fout_core+"_"+nameTop1+"_"+nameTop2+"_"+nameBottom1+"_"+nameBottom2+"_q"+quadrant+".png");
  //End->SetOptLogz();
  gStyle->SetOptLogz(0);

  gStyle->SetOptLogz(1);
  //Begin->SetOptLogz();
  TCanvas *c3 = new TCanvas("c3","c3",1500,1500);

  c3->Divide(2,2);
  c3->cd(1);
  hmain_top2_1_Time_pol1->Draw("colz");
  c3->cd(2);
  hmain_top2_2_Time_pol1->Draw("colz");
  c3->cd(3);
  hmain_top2_3_Time_pol1->Draw("colz");
  c3->cd(4);
  hmain_top2_4_Time_pol1->Draw("colz");
  c3->SaveAs("c3_"+fout_core+"_"+nameTop1+"_"+nameTop2+"_"+nameBottom1+"_"+nameBottom2+"_q"+quadrant+".pdf");
  c3->SaveAs("c3_"+fout_core+"_"+nameTop1+"_"+nameTop2+"_"+nameBottom1+"_"+nameBottom2+"_q"+quadrant+".png");
  //End->SetOptLogz();
  gStyle->SetOptLogz(0);


return(0);
// return fit;
}
