//
//  ManjeStrukture.h
//  ResoranSystem
//
//  Created by Adin Jahic on 25/12/2020.
//  Copyright © 2020 Adin Jahic. All rights reserved.
//

#ifndef ManjeStrukture_h
#define ManjeStrukture_h
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct datum {
public:
    int dan, mjesec, godina;
    datum(){};
    datum(int dan,int mjesec,int godina){
        this->dan = dan;
        this->mjesec = mjesec;
        this->godina = godina;
    }
    friend ostream& operator<<(ostream& output, datum dt) {
        output << dt.dan << "/"<<dt.mjesec << "/"<<dt.godina;
        return output;
    }
    
};
struct jelo {
public:
    string NazivJela;
    string Sastojci[5];
    float cijena;
    friend ostream& operator<<(ostream& output,jelo neko){
        output <<"Naziv jela: "<<neko.NazivJela<<"     ";
        output<<"Cijena Jela: "<<neko.cijena<<" KM"<<endl;
        output <<"Sastojci: ";
        for(int i = 0; i < 5; i++){
            output<<" "<<neko.Sastojci[i];
        }
        output<<endl;
        output<<"----------------------------------------->"<<endl;
        return output;
    }
};
struct dostavljac {
public:
    string ime;
    string prezime;
    int godine;
    int staz;
    datum zaposlenja;
    dostavljac(){};
    dostavljac(string ime,string prezime,int godine,int staz,datum datumZaposlenja){
        this->ime =ime;
        this->prezime =prezime;
        this->godine =godine;
        this->staz = staz;
        this->zaposlenja = datumZaposlenja;
    }
    friend ostream& operator<<(ostream& output,const dostavljac neki){
        output <<"Ime dostavljaca: "<<neki.ime<<endl;
        output <<"Prezime dostavljaca: "<<neki.prezime<<endl;
        output <<"Godine dostavljaca: "<<neki.godine<<endl;
        output <<"Staz dostavljaca: "<<neki.staz<<endl;
        output <<"Datum zaposlenja dostavljaca: "<<neki.zaposlenja<<endl;
        output <<"-------------------------------------->"<<endl;
        return output;
    };
    
};
#endif
