#include "MatKul.hpp"
#include "ListOfMatKul.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <algorithm>
#include <sstream>
using namespace std;

int main(){
    ListOfMatKul daftarMatKul();
    ifstream myFile("Test.txt");
    string baris;
    string daftarNilai;
    vector <string> temp;
    while (getline(myFile, baris))
    {// Memproses seluruh baris pada file
        
        for (int i = 0; i < baris.size(); i++)
        {// Mengubah ',' menjadi spasi
            if (baris[i] == ',')
            {
                baris[i] = ' ';
            } 
            
        }
        // Menghapus titik '.'
        baris.erase(remove(baris.begin(), baris.end(), '.'), baris.end());

        // Memproses tiap baris per kata
        string word;
        istringstream iss(baris);
        vector <string> temp;
        while (iss >> word)
        {
            temp.push_back(word);
        }
        
        for (int i = 0; i < temp.size(); i++)
        {
            if (i == 0)
            {
                cout << "Bikin matkul " << temp[i] << endl;
            } else {
                cout << "Bikin prereq " << temp[i] << endl;
            }
            
        }
        
        
    }


    myFile.close();
    return 0;
}