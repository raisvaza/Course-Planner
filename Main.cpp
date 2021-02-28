#include "MatKul.hpp"
#include "ListOfMatKul.hpp"
#include <iostream>
#include <fstream>
#include <string>

int main(){
    ListOfMatKul daftarMatKul();
    string baris = ""; // satu baris dalam text.txt
    string wholeText = ""; // seluruh string yang diperoleh dari dalam text.txt
    string kodeMatKul;
    string prereq;
    int n;
    n = wholeText.size();
    fstream myText("Test.txt");
    while (getline(myText, baris))
    {// Mengambil setiap baris dari text.txt
        baris += '\n';
        wholeText = wholeText + baris; // Meng-ekstrak seluruh text dari text.txt ke string wholeText        
    }
    int i = 0;
    while (i < n)
    {// Iterasi seluruh char di wholeText
        while (wholeText[i] != '\n')
        {// Iterasi char per baris
            kodeMatKul = "";
            while (wholeText[i] != ',')
            {// Ambil kode matkul
                kodeMatKul += wholeText[i];
                i++;
            }
            cout << "Matkul: " << kodeMatKul << endl;
            prereq = "";
            while (wholeText[i] != '\n')
            {// Ambil prereq
                if (wholeText[i] == ',')
                {
                    i++;
                }
                
                prereq += wholeText[i];
                i++;
            }
            cout << "Prereq: " << prereq << endl;
            
            i++;
        }
        
        i++;
    }
        
    return 0;
}