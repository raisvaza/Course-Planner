#include "ListOfMatKul.hpp"

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