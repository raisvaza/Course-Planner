#ifndef __LISTOFMATKUL__HPP__
#define __LISTOFMATKUL__HPP__
#include "MatKul.hpp"
using namespace std;

class ListOfMatKul {
    private:
        MatKul* daftarMatkul[];
        int banyakMatKul;
    public:
        ListOfMatKul();
        ~ListOfMatKul();
        
        void addMatKul(MatKul* MatKul);
};

#endif