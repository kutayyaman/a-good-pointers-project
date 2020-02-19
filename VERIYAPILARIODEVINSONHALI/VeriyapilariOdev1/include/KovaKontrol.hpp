/**
* @file KovaKontrol.hpp
* @description KovaKontrol classını tanımlıyor
* @course 1. ÖĞRETİM C GRUBU
* @assignment 1. ÖDEV
* @date 12.10.2019
* @author Kutay Yaman kutay.yaman@ogr.sakarya.edu.tr veya yamankutay1@gmail.com
*/
#include "Kova.hpp"
#include "Top.hpp"
#include <iostream>
using namespace std;

class KovaKontrol
{
	private:
		int kovaSayisi;
		Kova** kovalar;
		int islem;
		bool toplarYerlestiMi=false;
		void IslemiAl();
		void IslemiUygula();
		void ToplariYerlestir();
		void ToplariYokEt();
		void KovaDegistir();
		void TopDegistir();
		void KovalariTerstenYerlestir();
		void ToplariTerstenYerlestir();
	public:
		KovaKontrol(int);
		void KovalariOlustur();
		void EkranaBas();
		
		~KovaKontrol();
};
