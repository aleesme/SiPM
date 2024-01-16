// c++ -o draw2 draw2.cpp `root-config --glibs --cflags`

#include <iostream>

#include <TStyle.h>
#include <TApplication.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TGraphErrors.h>
#include <TMultiGraph.h>
#include <TAxis.h>
#include <cmath>

using namespace std;


int main (int argc, char ** argv)
{
	if (argc < 3)
    	{
	      	cout << "Not enough parameters: ./v_br dati.txt fondo.txt" << endl;
	      	return 1;
    	}
    	
    	gStyle->SetOptFit(1112);	
    	
    	TApplication* myApp = new TApplication("myApp", NULL, NULL);
  	TCanvas* myC = new TCanvas("myC","myC",0,0,700,500);
  	
  	TMultiGraph *mg = new TMultiGraph();
  	mg -> SetTitle ("LYSO ^{57}Co");
  	
  	
  	// grafico con gli errori
  	TGraphErrors* myGraph1 = new TGraphErrors(argv[1]);
  	myGraph1->SetMarkerStyle(6);
  	myGraph1->SetLineStyle(1);
  	myGraph1->SetMarkerColor(9);
  	myGraph1->SetLineColor(9);  
  	
  	
  	
  	// grafico con gli errori
  	TGraphErrors* myGraph2 = new TGraphErrors(argv[2]);
  	myGraph2->SetMarkerStyle(6);
  	myGraph2->SetLineStyle(1);
  	myGraph2->SetMarkerColor(92);
  	myGraph2->SetLineColor(92);   	
  	

	// disegno
	myC->cd();
	mg->Add(myGraph1);
	mg->Add(myGraph2);
	mg->GetXaxis()->SetTitle("ADC channel");
  	mg->GetYaxis()->SetTitle("Counts");
  	mg->Draw("ALP");
  	
  	
  	myC->Modified();
  	myC->Update();
  	
    
    
  	myApp->Run();

	return 0;
}
