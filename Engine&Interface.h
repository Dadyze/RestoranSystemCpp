//
//  Engine&Interface.h
//  ResoranSystem
//
//  Created by Adin Jahic on 25/12/2020.
//  Copyright © 2020 Adin Jahic. All rights reserved.
//

#ifndef Engine_Interface_h
#define Engine_Interface_h
#include <iostream>
#include "Restoran.h"
#include "Narudzba.h"
#include "ManjeStrukture.h"
#include <vector>
using namespace std;
void CustomerEngine(Restoran *moj);
void recursivePart(Restoran *info,narudzba *nova,Restoran *moj);
void CustomerInterface();
void AdminInterface();
void AdminEngine(Restoran *moj);
// ENUM
enum izbori : char{
    a= 'a',b,c,d,e,f,g,h,i,x='x'
};
// INTERFACE

void CustomerInterface(){
    cout <<"DobroDosli u Online RestoranSystem "<<endl;
    cout <<"Created by Adin Jahic"<<endl;
    cout <<"----------------------------------->"<<endl;
    cout <<"Izaberite Opciju: "<<endl;
    cout <<"a)Pogledaj Meni "<<endl;
    cout <<"b)Informacije o Restoranu"<<endl;
    cout <<"c)Naruci Jelo"<<endl;
    cout <<"d)Plati Narudžbu"<<endl;
    cout <<"e)Prijedji u Admin Mode"<<endl;
    cout <<"x)Izadji iz programa"<<endl;
    cout <<"----------------------------------->"<<endl;
}

void AdminInterface(){
    cout <<"Online RestoranSystem AdminConsole"<<endl;
    cout <<"----------------------------------->"<<endl;
    cout <<"Izaberite Opciju: "<<endl;
    cout <<"a)Informacije o Restoranu"<<endl;
    cout <<"b)Pogledaj Meni"<<endl;
    cout <<"c)Dodaj Jelo"<<endl;
    cout <<"d)Izbaci Jelo"<<endl;
    cout <<"e)Zaposli Dostavljaca"<<endl;
    cout <<"f)Otpusti Dostavljaca"<<endl;
    cout <<"g)Ispisi dostavljace"<<endl;
    cout <<"h)Pogledaj Fakture Poslovaja"<<endl;
    cout <<"i)Prijedji u Guest mode"<<endl;
    cout <<"x)Izadji iz programa."<<endl;
    cout <<"----------------------------------->"<<endl;
}


 // ENGINE

void AdminEngine(Restoran *moj){
    char izbor;
    cout <<"-----------------------------------"<<endl;
    cout <<"Unesi izbor: ";
    cin >>izbor;
    cout <<"-----------------------------------"<<endl;
    switch (izbor) {
        case a:
            moj->IspisiInfoRestorana();
            AdminEngine(moj);
        case b:
            moj->ispisiJela();
            AdminEngine(moj);
        case c:
            moj->dodajJelo();
            AdminEngine(moj);
        case d:{
            string imeJela;
            cout <<"Napisi ime jela za uklonit: ";
            cin >>imeJela;
            moj->ukloniJelo(imeJela);
            AdminEngine(moj);
        }
        case e:
            moj->dodajDostavljaca();
            AdminEngine(moj);
        case f:{
            string ime;
            cout <<"Napisi ime za otpustit: ";
            cin >>ime;
            moj->OtpustiDostavljaca(ime);
            AdminEngine(moj);
        }
        case g:
            moj->IspisiDostavljce();
            AdminEngine(moj);
        case i:
            CustomerInterface();
            CustomerEngine(moj);
        case x:
            break;
    }
}
void CustomerEngine(Restoran *moj){
    string imeR = moj->getIme();
    string imeV = moj->getImeV();
    Restoran* info = new narudzba(imeR,imeV);
    moj->UcitajMeni(info);
    narudzba* nova = new narudzba(imeR,imeV);
    moj->ucitajMeni(nova);
    recursivePart(info,nova,moj);
    
}
void recursivePart(Restoran *info,narudzba *nova,Restoran *moj){
    char izbor;
    cout <<"-----------------------------------"<<endl;
    cout <<"Unesi izbor: ";
    cin >> izbor;
    cout <<"-----------------------------------"<<endl;
    switch (izbor) {
        case a:
            info->ispisiJela();
            recursivePart(info,nova,moj);
        case b:
            info->IspisiInfoRestorana();
            recursivePart(info,nova,moj);
        case c:
        {
            string imeJela;
            cout <<"Unesi sta zelis narucit: "<<endl;
            cin >>imeJela;
            nova->naruci(imeJela);
            recursivePart(info,nova,moj);
        }
        case d:
            nova->Naplati(10.0);
            recursivePart(info,nova,moj);
        case e:
            AdminInterface();
            AdminEngine(moj);
        case x:
            break;
    }
    
}



#endif /* Engine_Interface_h */
