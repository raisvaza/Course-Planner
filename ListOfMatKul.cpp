#include "ListOfMatKul.h"
#include <iostream>

ListOfMatKul::ListOfMatKul(){
    this->banyakMatKul = 0;
};

ListOfMatKul::~ListOfMatKul(){
    delete[] daftarMatkul;
};

void ListOfMatKul::addMatKul(MatKul* MatKul){
    daftarMatkul[banyakMatKul] = MatKul;
    banyakMatKul++;
}

bool ListOfMatKul::adaMatKul(string namaMatKul){
    bool found = false;
    int i = 0;
    while (!found && i < banyakMatKul)
    {
        if (daftarMatkul[i]->getKodeMatKul() == namaMatKul)
        {
            found = true;
        }
        
        i++;
    }
    
    return found;
}

MatKul * ListOfMatKul::CariMatKulPendahulu(){
    for (int i = 0; i < banyakMatKul; i++)
    {
        if (daftarMatkul[i]->getDerajatMasuk() == 0)
        {
            cout << daftarMatkul[i]->getKodeMatKul() << endl;
        }
        
    }
    
}

void ListOfMatKul::topSort(){
    
}