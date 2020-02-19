/**
* @file Kova.cpp
* @description Kova.hpp'yi gerçekliyor.
* @course 1. ÖĞRETİM C GRUBU
* @assignment 1. ÖDEV
* @date 12.10.2019
* @author Kutay Yaman kutay.yaman@ogr.sakarya.edu.tr veya yamankutay1@gmail.com
*/
#include "Kova.hpp"
#include<iostream>
#include<windows.h>
using namespace std;

Kova::Kova(int renk)
{
	this->renk=renk;
	//this->harf='-';
}
int Kova::getRenk()const
{
	return this->renk;
}
char Kova::getHarf()const
{
	return (this->tasidigiTop)->getHarf();
}
void Kova::setHarf(char c)
{
	(this->tasidigiTop)->setHarf(c);
}
void Kova::TopKoy(Top* top,char harf)
{
	this->tasidigiTop=top;
	(this->tasidigiTop)->setHarf(harf);
}
void Kova::TopuSil()
{
	delete this->tasidigiTop;
	this->tasidigiTop=NULL;
	
}
void Kova::KendiAdresiniKoy(Kova* kendiAdresi)
{
	this->kendiAdresi=kendiAdresi;
}
void Kova::getKendiAdresi()
{
	cout<<"Kova adresi:"<<kendiAdresi<<endl;
}
Top* Kova::getTasidigiTopAdresi()const
{
	return this->tasidigiTop;
}
void Kova::setTasidigiTopAdresi(Top* yeniAdres)
{
	this->tasidigiTop=yeniAdres;
	
}
void Kova::KovayiEkranaYaz()
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, this->renk);
	for (int i = 0; i < 7; i++)
	{
		
		for (int j = 0; j < 7; j++)
		{
			if (i < 3 && j > 3)
			{
				if (j - 4 == i)
					cout << ".";
				else
					cout << " ";
			}
			else if (i < 3 && j < 3)
			{
				if (i + j == 2)
					cout << ".";
				else
					cout << " ";
			}
			else if (i == 0 && j == 3)
				cout << "|";
			else if (i >= 3 && (j == 0 || j == 6))
				cout << "#";
			else if (i == 6)
				cout << "#";
			else if (i == 4 && j == 3)
			{
				if(tasidigiTop==NULL)
						cout<<"-";
					else
						cout<<(this->tasidigiTop)->getHarf();
			}
			else
				cout << " ";

		}
		cout << endl;
	}
	this->getKendiAdresi(); //bu fonksiyon zaten direkt ekrana yaziyor
	if(this->tasidigiTop==NULL)
		cout<<"Topun adresi: NULL"<<endl;
	else
		cout<<"Topun adresi:"<<this->getTasidigiTopAdresi()<<endl;
	
	SetConsoleTextAttribute(hConsole, 7);
	
	
	
	
	
}
Kova::~Kova()
{
	
	
	
	
	
	/*if(this->tasidigiTop!=NULL)
	{
		delete tasidigiTop;
		this->tasidigiTop=NULL;
	}
	if(this->kendiAdresi!=NULL)
	{
		delete kendiAdresi;
		this->kendiAdresi=NULL;
	}
	*/
	
}