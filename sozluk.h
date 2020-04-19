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
		int KelimeAra();								//sozlükte kelime arýyor
		int KelimeAra(string aranacakkelime);			//overloaded kelime arama	
		int KelimeEkle();								//sözlüðe kelime ekliyor
		int KelimeSay();								//sözlükte kaç kelime olduðunu sayýyor
		bool isNumber(string s);
		void menu();
		void listele();
		private:
			string aranacakkelime;
			string kelime;
		
};

#endif

