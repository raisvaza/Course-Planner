#include "MatKul.h"
#include "ListOfMatKul.h"
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <algorithm>
#include <sstream>
using namespace std;

int main(){
    ListOfMatKul daftarMataKuliah;
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
            MatKul *A;
            if (i == 0)
            {// Proses Mata Kuliah
                cout << "Bikin matkul " << temp[i] << endl;
                A = new MatKul(temp[i]);
                daftarMataKuliah.addMatKul(A);
            } else {// Proses Prereq
                cout << "Bikin prereq " << temp[i] << endl;
                MatKul *B;
                if (!daftarMataKuliah.adaMatKul(temp[i]))
                {// Kalau prereq belum terdaftar di daftar mata kuliah
                    
                    B = new MatKul(temp[i]);
                    daftarMataKuliah.addMatKul(B);
                }
                
                // Tambah B sebagai prereq A
                A->addPrereq(B);
            }
            
        } // Satu baris MatKul dengan prereq-nya selesai diproses
        
        
    }

    // TOPOLOGICAL SORT



    myFile.close();
    return 0;
}