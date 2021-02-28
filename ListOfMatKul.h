#ifndef LISTOFMATKUL_H
#define LISTOFMATKUL_H
#include "MatKul.h"
using namespace std;

class ListOfMatKul {
    private:
        int banyakMatKul;
        MatKul* daftarMatkul[];
    public:
        ListOfMatKul();
        ~ListOfMatKul();
        
        void addMatKul(MatKul* MatKul);
        bool adaMatKul(string namaMatKul);
        void topSort();
        MatKul *CariMatKulPendahulu();
};

#endif