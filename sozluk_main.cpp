#include <iostream>
#include "sozluk.h"

int main(){
	setlocale(LC_ALL, "Turkish");
	Sozluk Bir;
	Bir.menu();
	Sozluk Iki(Bir);
	Sozluk Uc=Iki;

}

