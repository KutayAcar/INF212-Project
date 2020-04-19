#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include "sozluk.h"
using namespace std;
Sozluk::Sozluk(){
	int i=250, j=10;
	cout<<"Türkçe Sözlüðü açmak istiyorsanýz 1' basýn, baþka sözlük için 0'"<<endl;
	cin>>i;
	if(i==1){
	sozlukismi="anlamlar.txt";
	cout<<"Türkçe Sözlüðe hoþgeldiniz!"<<endl;
	SozlukAc(sozlukismi);}
	if(i==0){
		getchar();
		sozlukismi=setSozlukIsmi();
		
	}
	if(SozlukAc(sozlukismi)==0){
		cout<<"Sözlüðü oluþturmak istiyorsanýz 1'e basýn"<<endl;
		cin>>j;
		getchar();
		if(j==1)
		SozlukOlustur();
		cout<<"Sözlüðünüz oluþturuldu!"<<endl;
	}
}
Sozluk::Sozluk(string name){
	int j;
	sozlukismi=name;
	if(SozlukAc(sozlukismi)==0){
		cout<<"Sözlüðü oluþturmak istiyorsanýz 1'e basýn"<<endl;
		cin>>j;
		getchar();
		if(j==1)
		SozlukOlustur();
		cout<<"Sözlüðünüz oluþturuldu!"<<endl;
	}
	SozlukAc(sozlukismi);
	cout<<sozlukismi<<" Sözlüðe Hoþgeldiniz!"<<endl;
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
	cout<<"Lütfen aranacak kelimeyi giriniz:"<<endl;
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
	
	cout<<"Lütfen ekleyeceðiniz kelimeyi giriniz:"<<endl;
	getline(cin,kelime);
	if(isNumber(kelime))
	{
		throw "HATA!";
	}
			if(KelimeAra(kelime)){
		cout<<"Eklemeye çalýþtýðýnýz kelime zaten sözlükte mevcut ! ! !"<<endl;	//burada bir hata olduðu için devre dýþý býraktým
		return 0;
	}
	kelime+="**";
	cout<<"Lütfen eklediðiniz kelimenin anlamýný giriniz:"<<endl;
	getline(cin,anlam);
	kelime+=anlam;
	outfile<<'\n'<<kelime<<'\n';
	cout<<"Kelime baþarýyla eklendi!"<<endl;}
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
	cout<<"Lütfen oluþturacaðýnýz sözlüðün ismini sonuna .txt koyarak giriniz!"<<endl;
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
	cout<<sozlukismi<<" Açýlamadý!"<<endl;
	return 0;}

	if(myfile.is_open()){
	cout<<sozlukismi<<" Açýldý!"<<endl;
}
}
string Sozluk::setSozlukIsmi(){
	string isim;
	cout<<"Açmak istediðiniz sözlüðün ismini sonuna .txt koyarak yazýn"<<endl;
	getline(cin,isim);
	return isim;
}
void Sozluk::menu(){
	int i;
	cout<<"1. Kelime Ara"<<endl;
	cout<<"2.Kelime Ekle"<<endl;
	cout<<"3. Kelimeleri Say"<<endl;
	cout<<"4. Sözlüðün tüm kelimelerini listele!"<<endl;
	cout<<"Menüden çýkmak için baþka bir sayý gir"<<endl;
	cout<<"Yapmak istediðin iþlemi seç ve numarasýný gir:"<<endl;
	cin>>i;
	getchar();
	getchar();
	switch(i){
		case 1:
			
			if(!KelimeAra())
			cout<<"Aradýðýn kelime sözlükte yok!"<<endl;
			menu();
			break;		
		case 2:
			KelimeEkle();
			menu();
			break;
		case 3:
			cout<<"Sözlüðünüzde "<<KelimeSay()<<" adet sözcük vardýr!"<<endl;
			menu();
			break;
		case 4:
			listele();
		default:
			cout<<"Menüden çýkýldý!";
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
   	throw "Sadece sayý giremezsiniz!";
} 

