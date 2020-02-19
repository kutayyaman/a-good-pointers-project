/**
* @file TestProgrami.cpp
* @description Programı burda çalısmaya başlıyor ve gerekli nesne olusturuluyor.
* @course 1. ÖĞRETİM C GRUBU
* @assignment 1. ÖDEV
* @date 12.10.2019
* @author Kutay Yaman kutay.yaman@ogr.sakarya.edu.tr veya yamankutay1@gmail.com
*/
#include "Top.hpp"
#include "Kova.hpp"
#include "KovaKontrol.hpp"
#include<iostream>
using namespace std;
int main()
{
	int kovaSayisi;
	cout<<"Kova Sayisi:";
	cin>>kovaSayisi;
	
	KovaKontrol* kovaKontrol1=new KovaKontrol(kovaSayisi);
	
	kovaKontrol1->KovalariOlustur();
	kovaKontrol1->EkranaBas();
	
	if(kovaKontrol1!=NULL)
	delete kovaKontrol1;
	
	

	return 0;
}