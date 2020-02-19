/**
* @file Top.cpp
* @description Top.hpp'yi gerçekliyor.
* @course 1. ÖĞRETİM C GRUBU
* @assignment 1. ÖDEV
* @date 12.10.2019
* @author Kutay Yaman kutay.yaman@ogr.sakarya.edu.tr veya yamankutay1@gmail.com
*/

#include "Top.hpp"
#include <iostream>
using namespace std;

Top::Top()
{
	
	
}
char Top::getHarf() const
{
	return this->harf;
}
void Top::setHarf(char ch)
{
	this->harf=ch;
}