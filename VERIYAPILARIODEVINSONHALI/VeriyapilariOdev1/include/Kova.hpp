/**
* @file Kova.hpp
* @description Kova classını tanımlıyor
* @course 1. ÖĞRETİM C GRUBU
* @assignment 1. ÖDEV
* @date 12.10.2019
* @author Kutay Yaman kutay.yaman@ogr.sakarya.edu.tr veya yamankutay1@gmail.com
*/
#ifndef Kova_HPP
#define Kova_HPP
#include "Top.hpp"
#include<iostream>
#include<string>
using namespace std;

class Kova
{
	private:
	Top* tasidigiTop=NULL;
	int renk;
	//char harf;
	Kova* kendiAdresi;
	
	
	public:
	Kova(int);
	int getRenk()const;
	char getHarf()const;
	void setHarf(char);
	void TopKoy(Top*,char);
	void TopuSil();
	void KendiAdresiniKoy(Kova*);
	void getKendiAdresi();
	Top* getTasidigiTopAdresi()const;
	void setTasidigiTopAdresi(Top*);
	void KovayiEkranaYaz();
	~Kova();
};



#endif