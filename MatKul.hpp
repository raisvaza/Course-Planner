#ifndef __MATKUL__HPP__
#define __MATKUL__HPP__
#include <string>
using namespace std;

class MatKul {
    private:
        string kodeMatKul;
        int banyakPrereq;
        MatKul* prereq[];
    public:
        MatKul(string kodeMatKul);
        ~MatKul();

        string getKodeMatKul();
        void showPrereq();
        void setKodeMatkul(string kodeMatkul);
        void addPrereq(MatKul* MatKul);
};

#endif