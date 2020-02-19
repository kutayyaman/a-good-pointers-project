/**
* @file KovaKontrol.cpp
* @description KovaKontrol.hpp'yi gerçekliyor.
* @course 1. ÖĞRETİM C GRUBU
* @assignment 1. ÖDEV
* @date 12.10.2019
* @author Kutay Yaman kutay.yaman@ogr.sakarya.edu.tr veya yamankutay1@gmail.com
*/
#include "KovaKontrol.hpp"
#include <iostream>
using namespace std;

KovaKontrol::KovaKontrol(int kovaSayisi)
{
	this->kovaSayisi=kovaSayisi;
}
void KovaKontrol::KovalariOlustur()
{
	Kova** kovalar=new Kova*[this->kovaSayisi]; //new Kova*[sayi] burdaki * önemli!!
	for(int i=0;i<this->kovaSayisi;i++)
	{	
		int renk=i+1;
		kovalar[i]=new Kova(renk);
		kovalar[i]->KendiAdresiniKoy(kovalar[i]);
	}
	this->kovalar=kovalar;
}
void KovaKontrol::ToplariYerlestir()
{
	int harf=65;

	for(int i=0;i<this->kovaSayisi;i++)
	{
		Kova** kovalar=this->kovalar;
		Top* top=new Top();
		kovalar[i]->TopKoy(top,harf);
		harf++;
	}
	this->toplarYerlestiMi=true;
}
void KovaKontrol::ToplariYokEt()
{
	for(int i=0;i<this->kovaSayisi;i++)
	{
		Kova** kovalar=this->kovalar;
		kovalar[i]->TopuSil();
	}
	this->toplarYerlestiMi=false;
}
void KovaKontrol::KovaDegistir()
{
	int kova1,kova2;
	cout<<"Hangi Kova :";
	cin>>kova1;
	cout<<endl;
	cout<<"Hangi Kova ile :";
	cin>>kova2;
	cout<<endl;
	Kova** kovalar=this->kovalar;
	Kova* temp=NULL;
	temp=kovalar[kova1-1];
	kovalar[kova1-1]=kovalar[kova2-1];
	kovalar[kova2-1]=temp;
	
	KovaKontrol::EkranaBas();
	
}
void KovaKontrol::TopDegistir()
{
	int top1,top2;
	cout<<"Hangi Top :";
	cin>>top1;
	cout<<endl;
	cout<<"Hangi Top ile :";
	cin>>top2;
	cout<<endl;
	Kova** kovalar=this->kovalar;
	Top* top1P=NULL;
	Top* top2P=NULL;
	top1P=kovalar[top1-1]->getTasidigiTopAdresi();
	top2P=kovalar[top2-1]->getTasidigiTopAdresi();
	kovalar[top1-1]->setTasidigiTopAdresi(top2P);
	kovalar[top2-1]->setTasidigiTopAdresi(top1P);
	/*char temp=kovalar[top1-1]->getHarf();
	kovalar[top1-1]->setHarf(kovalar[top2-1]->getHarf());
	kovalar[top2-1]->setHarf(temp);*/
	
	
	
	KovaKontrol::EkranaBas();
}
void KovaKontrol::KovalariTerstenYerlestir()
{
	Kova** kovalar=this->kovalar;
	Kova* temp=NULL;
	if((this->kovaSayisi)%2==0)
	{
		int bas=0;
		int son=(this->kovaSayisi)-1;
		for(int i=0;i<kovaSayisi/2;i++)
		{
			temp=kovalar[bas];
			kovalar[bas]=kovalar[son];
			kovalar[son]=temp;
			bas++;
			son--;
		}
	}
	else
	{
		int bas=0;
		int son=(this->kovaSayisi)-1;
		for(int i=0;i<(kovaSayisi-1)/2;i++)
		{
			temp=kovalar[bas];
			kovalar[bas]=kovalar[son];
			kovalar[son]=temp;
			bas++;
			son--;
		}
	}
	KovaKontrol::EkranaBas();
}
void KovaKontrol::ToplariTerstenYerlestir()
{
	Kova** kovalar=this->kovalar;
	Top* temp;
	//char ctemp;
	if((this->kovaSayisi)%2==0)
	{
		int bas=0;
		int son=(this->kovaSayisi)-1;
		for(int i=0;i<kovaSayisi/2;i++)
		{
			temp=kovalar[bas]->getTasidigiTopAdresi();
			kovalar[bas]->setTasidigiTopAdresi(kovalar[son]->getTasidigiTopAdresi());
			kovalar[son]->setTasidigiTopAdresi(temp);
			
			/*ctemp=kovalar[bas]->getHarf();
			kovalar[bas]->setHarf(kovalar[son]->getHarf());
			kovalar[son]->setHarf(ctemp);*/
			
			bas++;
			son--;
		}
	}
	 else
	{
		int bas=0;
		int son=(this->kovaSayisi)-1;
		for(int i=0;i<(kovaSayisi-1)/2;i++)
		{
			temp=kovalar[bas]->getTasidigiTopAdresi();
			kovalar[bas]->setTasidigiTopAdresi(kovalar[son]->getTasidigiTopAdresi());
			kovalar[son]->setTasidigiTopAdresi(temp);
			
			/*ctemp=kovalar[bas]->getHarf();
			kovalar[bas]->setHarf(kovalar[son]->getHarf());
			kovalar[son]->setHarf(ctemp);*/
			
			bas++;
			son--;
		}
	}
	KovaKontrol::EkranaBas();
}

void KovaKontrol::IslemiUygula()
{
	
	
	 if(this->islem==1)
	 {
		 if(this->toplarYerlestiMi==false)
		 {
		KovaKontrol::ToplariYerlestir();
		KovaKontrol::EkranaBas();
		 }
		 else
		 {
			 cout<<"Toplar Zaten Yerlestirilmis Bu Islemi Suan Yapamazsiniz"<<endl;
			 KovaKontrol::IslemiAl();
		 }
	 }
	else if(this->islem==2)
	{
		if(this->toplarYerlestiMi==true)
		{
		KovaKontrol::ToplariYokEt();
		KovaKontrol::EkranaBas();
		}
		else
		{
			cout<<"Toplar Zaten YokEdilmis Bu Islemi Suan Yapamazsiniz"<<endl;
			KovaKontrol::IslemiAl();
		}
	}
	else if(this->islem==3)
		KovaKontrol::KovaDegistir();
	else if(this->islem==4)
	{
		if(this->toplarYerlestiMi==true)
		KovaKontrol::TopDegistir();
		else
		{
			cout<<"Toplar Henuz Yerlestirilmemis O Yuzden Yerlerini Degistiremezsiz"<<endl;
			KovaKontrol::IslemiAl();
		}
	}
	else if(this->islem==5)
		KovaKontrol::KovalariTerstenYerlestir();
	else if(this->islem==6)
	{
		if(this->toplarYerlestiMi==true)
		KovaKontrol::ToplariTerstenYerlestir(); 
		else 
		  {
				cout<<"Toplar Henuz Yerlestirilmemis O Yuzden Tersten Yerlestiremezsiniz Henuz Top Yok"<<endl;
				KovaKontrol::IslemiAl();
		  }
	}
	
	else if(this->islem==7)
	{
		return;
	}
	else
	{
		cout<<"GECERSIZ BIR ISLEM GIRDINIZ"<<endl;
		KovaKontrol::IslemiAl();
	}
		
	
	
}

void KovaKontrol::IslemiAl()
{
	int islem;
	cout<<">>";
	cin>>islem;
	this->islem=(int)islem;
	KovaKontrol::IslemiUygula();
}

void KovaKontrol::EkranaBas()
{
	for(int i=0;i<this->kovaSayisi;i++)
	{
		cout<<i+1<<". Kova"<<endl;
		this->kovalar[i]->KovayiEkranaYaz();
		cout<<endl;
	}
	cout<<endl;
	cout<<"[1] Toplari Yerlestir"<<endl;
	cout<<"[2] Toplari Yoket"<<endl;
	cout<<"[3] Kova Degistir"<<endl;
	cout<<"[4] Top Degistir"<<endl;
	cout<<"[5] Kovalari Tersten Yerlestir"<<endl;
	cout<<"[6] Toplari Tersten Yerlestir"<<endl;
	cout<<"[7] Cikis"<<endl;
	KovaKontrol::IslemiAl();
}
KovaKontrol::~KovaKontrol()
{
	if(toplarYerlestiMi==true)
	{
		for(int i=0;i<this->kovaSayisi;i++)
		{
			this->kovalar[i]->TopuSil();
		}
	}
	for(int i=0;i<this->kovaSayisi;i++)
	{
		if(kovalar[i]!=NULL)
		{
			delete this->kovalar[i];
			this->kovalar[i]=NULL;
		}
	}
	if(this->kovalar!=NULL)
	{
		delete[] this->kovalar;
		this->kovalar=NULL;
	}
}