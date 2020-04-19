#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include "sozluk.h"
using namespace std;
Sozluk::Sozluk(){
	int i=250, j=10;
	cout<<"T�rk�e S�zl��� a�mak istiyorsan�z 1' bas�n, ba�ka s�zl�k i�in 0'"<<endl;
	cin>>i;
	if(i==1){
	sozlukismi="anlamlar.txt";
	cout<<"T�rk�e S�zl��e ho�geldiniz!"<<endl;
	SozlukAc(sozlukismi);}
	if(i==0){
		getchar();
		sozlukismi=setSozlukIsmi();
		
	}
	if(SozlukAc(sozlukismi)==0){
		cout<<"S�zl��� olu�turmak istiyorsan�z 1'e bas�n"<<endl;
		cin>>j;
		getchar();
		if(j==1)
		SozlukOlustur();
		cout<<"S�zl���n�z olu�turuldu!"<<endl;
	}
}
Sozluk::Sozluk(string name){
	int j;
	sozlukismi=name;
	if(SozlukAc(sozlukismi)==0){
		cout<<"S�zl��� olu�turmak istiyorsan�z 1'e bas�n"<<endl;
		cin>>j;
		getchar();
		if(j==1)
		SozlukOlustur();
		cout<<"S�zl���n�z olu�turuldu!"<<endl;
	}
	SozlukAc(sozlukismi);
	cout<<sozlukismi<<" S�zl��e Ho�geldiniz!"<<endl;
}
Sozluk::Sozluk(const Sozluk &object){
	sozlukismi=object.sozlukismi;
}
Sozluk& Sozluk::operator=(const Sozluk &object){
	sozlukismi=object.sozlukismi;
	return *this;
} 


int Sozluk::KelimeAra(){
	ifstream myfile;
	myfile.open(sozlukismi.c_str());
	cout<<"L�tfen aranacak kelimeyi giriniz:"<<endl;
	getline(cin,aranacakkelime);
	for(int i =0; i< Sozluk::aranacakkelime.length(); i++){
		Sozluk::aranacakkelime[i]=tolower(Sozluk::aranacakkelime[i]);
	}
	while(getline(myfile, Sozluk::kelime)){
			int yer=Sozluk::kelime.find("*");
			string alt=Sozluk::kelime.substr(0,yer);
			if(alt==Sozluk::aranacakkelime)
				{
				string sub = Sozluk::kelime.substr(yer + 2); 
				//cout<<kelime<<endl;
				cout<<sub<<endl;
				return 1;
				}
		}
		myfile.close();
		return 0;
}

int Sozluk::KelimeAra(string aranacakkelime){
	ifstream myfile;
	myfile.open(sozlukismi.c_str());
	for(int i =0; i< Sozluk::aranacakkelime.length(); i++){
		Sozluk::aranacakkelime[i]=tolower(Sozluk::aranacakkelime[i]);
	}
	while(getline(myfile, Sozluk::kelime)){
			int yer=Sozluk::kelime.find("*");
			string alt=Sozluk::kelime.substr(0,yer);
			if(alt==Sozluk::aranacakkelime)
				{
				return 1;
				}
		}
		myfile.close();
		return 0;
}



int Sozluk::KelimeEkle(){
	ofstream outfile;
	string kelime;
	string anlam;
	outfile.open(sozlukismi.c_str(), ios_base::app);
	try{
	
	cout<<"L�tfen ekleyece�iniz kelimeyi giriniz:"<<endl;
	getline(cin,kelime);
	if(isNumber(kelime))
	{
		throw "HATA!";
	}
			if(KelimeAra(kelime)){
		cout<<"Eklemeye �al��t���n�z kelime zaten s�zl�kte mevcut ! ! !"<<endl;	//burada bir hata oldu�u i�in devre d��� b�rakt�m
		return 0;
	}
	kelime+="**";
	cout<<"L�tfen ekledi�iniz kelimenin anlam�n� giriniz:"<<endl;
	getline(cin,anlam);
	kelime+=anlam;
	outfile<<'\n'<<kelime<<'\n';
	cout<<"Kelime ba�ar�yla eklendi!"<<endl;}
	catch(string kell){
		cout<<kell;
	}
}
int Sozluk::KelimeSay(){
	ifstream myfile;
	int sayac=0;
	myfile.open(sozlukismi.c_str());
	while(getline(myfile, kelime) ){
			if(kelime.find("**")!= std::string::npos)
			sayac++;
		}
		myfile.close();
		return sayac;
}
int Sozluk::SozlukOlustur(){
	cout<<"L�tfen olu�turaca��n�z s�zl���n ismini sonuna .txt koyarak giriniz!"<<endl;
	getline(cin,sozlukismi);
	ofstream myfile;
	myfile.open(sozlukismi.c_str());
	if(myfile.is_open())
	return 1;
	else
	return 0;
}
int Sozluk::SozlukAc(string sozlukismi){
	ifstream myfile;
	myfile.open(sozlukismi.c_str());
	if(myfile.fail()){
	cout<<sozlukismi<<" A��lamad�!"<<endl;
	return 0;}

	if(myfile.is_open()){
	cout<<sozlukismi<<" A��ld�!"<<endl;
}
}
string Sozluk::setSozlukIsmi(){
	string isim;
	cout<<"A�mak istedi�iniz s�zl���n ismini sonuna .txt koyarak yaz�n"<<endl;
	getline(cin,isim);
	return isim;
}
void Sozluk::menu(){
	int i;
	cout<<"1. Kelime Ara"<<endl;
	cout<<"2.Kelime Ekle"<<endl;
	cout<<"3. Kelimeleri Say"<<endl;
	cout<<"4. S�zl���n t�m kelimelerini listele!"<<endl;
	cout<<"Men�den ��kmak i�in ba�ka bir say� gir"<<endl;
	cout<<"Yapmak istedi�in i�lemi se� ve numaras�n� gir:"<<endl;
	cin>>i;
	getchar();
	getchar();
	switch(i){
		case 1:
			
			if(!KelimeAra())
			cout<<"Arad���n kelime s�zl�kte yok!"<<endl;
			menu();
			break;		
		case 2:
			KelimeEkle();
			menu();
			break;
		case 3:
			cout<<"S�zl���n�zde "<<KelimeSay()<<" adet s�zc�k vard�r!"<<endl;
			menu();
			break;
		case 4:
			listele();
		default:
			cout<<"Men�den ��k�ld�!";
			break;
	}	
	
}
void Sozluk::listele(){
	ifstream myfile;
	myfile.open(sozlukismi.c_str());
	while(getline(myfile,kelime))
	cout<<endl<<kelime<<endl;
}
bool Sozluk::isNumber(string s) 
{ 	bool i=true;
    for (int i = 0; i < s.length(); i++) 
        if (isdigit(s[i]) == false) 
            i=false; 
  	if(i=true)
   	throw "Sadece say� giremezsiniz!";
} 

