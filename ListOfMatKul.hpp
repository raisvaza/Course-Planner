#ifndef __LISTOFMATKUL__HPP__
#define __LISTOFMATKUL__HPP__
#include "MatKul.hpp"
using namespace std;

class ListOfMatKul {
    private:
        int banyakMatKul;
        MatKul* daftarMatkul[];
    public:
        ListOfMatKul();
        ~ListOfMatKul();
        
        void addMatKul(MatKul* MatKul);
};

#endif