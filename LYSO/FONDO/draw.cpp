// c++ -o draw draw.cpp `root-config --glibs --cflags`

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
	if (argc < 2)
    	{
	      	cout << "Not enough parameters: ./v_br dati.txt" << endl;
	      	return 1;
    	}
    	
    	gStyle->SetOptFit(1112);	
    	
    	TApplication* myApp = new TApplication("myApp", NULL, NULL);
  	TCanvas* myC = new TCanvas("myC","myC",0,0,700,500);  	
  	
  	// grafico con gli errori
  	TGraphErrors* myGraph = new TGraphErrors(argv[1]);
  	myGraph->SetMarkerStyle(kFullCircle);
  	myGraph->SetMarkerStyle(6);
  	myGraph->SetLineStyle(1);
  	//myGraph->SetMarkerSize(2.5);
  	myGraph->SetMarkerColor(9);
  	myGraph->SetLineColor(9);
  	myGraph->SetTitle("LYSO BACKGROUND SPECTRUM");
  	myGraph->GetXaxis()->SetTitle("ADC channel");
  	myGraph->GetYaxis()->SetTitle("Counts"); 	
  	

	// disegno
	myC->cd();
	myGraph->Draw("ALP");  	
  	myC->Modified();
  	myC->Update();    
    
  	myApp->Run();

	return 0;
}
