//
//  main.cpp
//  ResoranSystem
//
//  Created by Adin Jahic on 25/12/2020.
//  Copyright © 2020 Adin Jahic. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include "ManjeStrukture.h"
#include "Restoran.h"
#include "Narudzba.h"
#include "Engine&Interface.h"
using namespace std;

void CustomerInterface();
void AdminInterface();
void AdminEngine(Restoran *moj);
void CustomerEngine(Restoran *moj);

int main()
{
    Restoran* moj = new Restoran("adinGrilL","Zenica",30,"Adin","Jahic");
    char x;
    cout <<"Jesi li Admin ili gost: (a/g) ";
    cin >>x;
    cout <<endl;
    if(x == 'a'){
        AdminInterface();
        AdminEngine(moj);
    }
    else if(x == 'g'){
        CustomerInterface();
        CustomerEngine(moj);
    }
}



