#ifndef __MATKUL__HPP__
#define __MATKUL__HPP__
#include <string>
using namespace std;

class MatKul {
    private:
        string kodeMatKul;
        MatKul* prereq[];
        int banyakPrereq;
    public:
        MatKul();
        MatKul(string kodeMatKul, MatKul* prereq);
        ~MatKul();

        string getKodeMatkul();
        void showPrereq();
        void setKodeMatkul(string kodeMatkul);
        void addPrereq(MatKul& Matkul, string kodeMatKul);
};

#endif