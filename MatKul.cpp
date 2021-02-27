#include "MatKul.hpp"
#include <iostream>

MatKul::MatKul(string kodeMatKul){
    this->kodeMatKul = kodeMatKul;
    this->banyakPrereq = 0;
}

MatKul::~MatKul(){
    delete[] prereq;
}

string MatKul::getKodeMatKul(){
    return this->kodeMatKul;
}

void MatKul::showPrereq(){
    if (this->banyakPrereq > 0)
    {
        int i;
        for (i = 0; i < banyakPrereq; i++)
        {
            cout << prereq[i] << endl;
        }
    }
}

void MatKul::setKodeMatkul(string kodeMatKul){
    this->kodeMatKul = kodeMatKul;
}

void MatKul::addPrereq(MatKul* MatKul){
    prereq[banyakPrereq] = MatKul;
    this->banyakPrereq++;
}