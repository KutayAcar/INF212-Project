#ifndef  __KELIME__H__
#define  __KELIME__H__
#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
using namespace std;
class Sozluk{
		public:
		string sozlukismi;
		Sozluk();										//default constructor   							
		Sozluk(string name);							//constructor
		Sozluk(const Sozluk &object);					//copy constructor
		Sozluk& operator = (const Sozluk &object);		//assignment constructor
		string setSozlukIsmi();
		int SozlukOlustur();
		int SozlukAc(string sozlukismi);
		int KelimeAra();								//sozl�kte kelime ar�yor
		int KelimeAra(string aranacakkelime);			//overloaded kelime arama	
		int KelimeEkle();								//s�zl��e kelime ekliyor
		int KelimeSay();								//s�zl�kte ka� kelime oldu�unu say�yor
		bool isNumber(string s);
		void menu();
		void listele();
		private:
			string aranacakkelime;
			string kelime;
		
};

#endif

