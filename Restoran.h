//
//  Restoran.h
//  ResoranSystem
//
//  Created by Adin Jahic on 25/12/2020.
//  Copyright © 2020 Adin Jahic. All rights reserved.
//

#ifndef Restoran_h
#define Restoran_h

#include <iostream>
#include <string>
#include <vector>
#include "ManjeStrukture.h"
using namespace std;

class Restoran : public jelo, dostavljac {
private:
    string imeRestorana;
    string MjestoRestorana;
    string imeVlasnika;
    string prezimeVlasnika;
    int MaxKapacitet;
public:
    vector<jelo> Meni;
    vector<dostavljac> Osoblje;
    int brojStola;
    bool active = true;
    
public:
    // getteri
    string getIme() { return this->imeRestorana; }
    string getMjesto() { return this->MjestoRestorana; }
    int getMaxSize() { return this->MaxKapacitet; }
    string getImeV(){return this->imeVlasnika;};
    string getPrezimeV(){return this->prezimeVlasnika;};
    //setteri
    void setIme(string ime) { this->imeRestorana = ime; }
    void setMjesto(string mjesto) { this->MjestoRestorana = mjesto; }
    void setSize(int vel) { this->MaxKapacitet = vel; }
    void setImeV(string ime){this->imeVlasnika = ime;}
    void setPrezimeV(string prezime){this->prezimeVlasnika = prezime;}
    //kontruktori
    Restoran() {};
    Restoran(string ime, string mjesto, int velicina,string imev,string prezimeV) {
        setIme(ime);
        setMjesto(mjesto);
        setSize(velicina);
        setImeV(imev);
        setPrezimeV(prezimeV);
    }
    //funkcije
     virtual void IspisiInfoRestorana(){
        cout <<"Naziv Restorana: "<< this->getIme()<<endl;
        cout <<"Mjesto Restorana: "<<this->getMjesto()<<endl;
        cout <<"Ime vlasnika: "<<this->getImeV()<<endl;
        cout <<"Prezime vlasnika: "<<this->getPrezimeV()<<endl;
    }
    virtual void ispisiJela(){
        for(int i = 0; i<Meni.size(); i++){
            cout <<Meni[i];
        }
    }
 
    void dodajJelo() {
        string ime;
        cout << "Napisi naziv jela: ";
        cin >> ime;
        float cijena;
        cout << "Napisi cijenu jela: ";
        cin >> cijena;
        cout << "Navedi sastojke:"<<endl;
        string sastojak1,sastojak2,sastojak3,sastojak4,sastojak5;
        cin >> sastojak1>> sastojak2>>sastojak3>>sastojak4>>sastojak5;
        jelo novo;
        novo.NazivJela = ime;
        novo.cijena = cijena;
        novo.Sastojci[0] = sastojak1;
        novo.Sastojci[1] = sastojak2;
        novo.Sastojci[2] = sastojak3;
        novo.Sastojci[3] = sastojak4;
        novo.Sastojci[4] = sastojak5;
        Meni.push_back(novo);
    }
    
    void ukloniJelo(string ime){
        for(int i = 0 ; i < Meni.size();i++){
            if(Meni[i].NazivJela == ime){
                Meni.erase(Meni.begin()+i);
            }
        }
        
    }
    
  
    void UcitajMeni(Restoran *x){
        for(int i = 0 ; i < this->Meni.size();i++){
            x->Meni.push_back(this->Meni[i]);
        }
    }
    void dodajDostavljaca(){
        string ime;
        cout <<"Unesi ime: ";
        cin >>ime;
        string prezime;
        cout <<"Unesi preime: ";
        cin >>prezime;
        int godineRada;
        cout <<"Unesi godine: ";
        cin >>godineRada;
        int staz;
        cout <<"Unesi staz: ";
        cin >>staz;
        int d,m,g;
        cout <<"Unesi datum zaposlenja: ";
        cin >>d>>m>>g;
        datum Dt(d,m,g);
        dostavljac novi(ime,prezime,godineRada,staz,Dt);
        Osoblje.push_back(novi);
        
    }
    void OtpustiDostavljaca(string ime){
        for(int i = 0; i < Osoblje.size();i++){
            if(Osoblje[i].ime == ime){
                Osoblje.erase(Osoblje.begin()+i);
            }
        }
    }
    
    void IspisiDostavljce(){
        for(int i = 0 ; i < Osoblje.size();i++){
            cout <<Osoblje[i];
        }
    }
    
    void ucitajMeni(Restoran *x){
        for(int i = 0 ; i < this->Meni.size();i++){
            x->Meni.push_back(this->Meni[i]);
        }
    }
    
    
    
};
#endif /* Restoran_h */
