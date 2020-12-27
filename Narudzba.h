//
//  Narudzba.h
//  ResoranSystem
//
//  Created by Adin Jahic on 25/12/2020.
//  Copyright © 2020 Adin Jahic. All rights reserved.
//

#ifndef Narudzba_h
#define Narudzba_h
#include <iostream>
#include <string>
#include <vector>
#include "ManjeStrukture.h"
#include "Restoran.h"
using namespace std;

class narudzba :public Restoran{
public:
    datum narudzbe;
    string imeRestorana;
    string imeVlasnika;
    string imeZaduzenogKonobara;
    float cijena = 0;
    float PDV = 0.17;
    float Popust;
    float ukupno=0;

    vector<jelo> narucenaJela;
    
    //Getteri i setteri
    string getIme() { return this->imeRestorana; };
    string getImeV() { return this->imeVlasnika; };
    string getKonobara() { return this->imeZaduzenogKonobara; };
    void setIme(string ime) { this->imeRestorana = ime; };
    void setImeV(string imeV){ this->imeVlasnika = imeV; };
    void setImeK(string imeK){ this->imeZaduzenogKonobara = imeK; };
    
    narudzba(string ImeRestorana, string Vlasnika) {
        setIme(ImeRestorana);
        setImeV(Vlasnika);
    };
    void ispisiJela() override {
        cout <<"Jelovnik!  "<<endl;
        cout <<endl;
        for(int i = 0; i < this->Meni.size();i++){
            cout <<Meni[i]<<endl;
        }
    };
    
    void IspisiInfoRestorana()override{
        cout <<"Naziv Restorana: "<< this->getIme()<<endl;
        cout <<"Ime vlasnika: "<<this->getImeV()<<endl;
    }
    void naruci(string ime){
        for (int i = 0; i < this->Meni.size(); i++) {
            if (this->Meni[i].NazivJela == ime) {
                this->narucenaJela.push_back(this->Meni[i]);
                this->cijena =this->cijena+ this->narucenaJela[i].cijena;
            }
        }
        cout <<"Unesi Datum narudzbe ";
        cin >>this->narudzbe.dan>>this->narudzbe.mjesec>>this->narudzbe.godina;
        cout <<"Unesi BrojStola ";
        cin >>this->brojStola;
        
    };
    
    void Naplati (float popust){
        this->Popust = popust/100;
        for (int i = 0; i < this->narucenaJela.size(); i++) {
            cout <<"  "<<this->narucenaJela[i].NazivJela <<" "<<this->narucenaJela[i].cijena << " KM"<<endl;
        }
        cout << "--------------------------------" << endl;
        this->ukupno = this->cijena - (this->cijena * this->Popust) + (this->cijena * this->PDV);
        cout << "Neoporezovano: " <<this->cijena << " KM" << endl;
        cout << "PDV: " <<this->PDV << " %" << endl;
        cout << "Popust: "<<this->Popust<<" %"<<endl;
        cout << "Ukupno za naplatu: " <<this->ukupno << " KM" << endl;
        cout << "Datum Izdavanja Racuna: " <<this->narudzbe<<endl;
        cout << "Ime konobara: "<<this->getKonobara()<<endl;
        cout <<"-------------------------------->"<<endl;
    }
    
};


#endif /* Narudzba_h */
