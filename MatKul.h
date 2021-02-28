#ifndef MATKUL_H
#define MATKUL_H
#include <string>
using namespace std;

class MatKul {
    private:
        string kodeMatKul;
        int banyakPrereq;
        int derajatMasuk;
        MatKul* prereq[];
    public:
        MatKul(string kodeMatKul);
        ~MatKul();

        string getKodeMatKul();
        void showPrereq();
        void setKodeMatkul(string kodeMatkul);
        void addPrereq(MatKul* MatKul);
        int getDerajatMasuk();
        void setDerajatMasuk(int derajat);
};

#endif