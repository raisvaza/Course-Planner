#include "MatKul.hpp"
#include "ListOfMatKul.hpp"
#include <iostream>
#include <fstream>


int main(){
    ListOfMatKul daftarMatKul();
    string text;
    string wholeText;
    fstream myText("Test.txt");
    while (getline(myText, text))
    {
        wholeText = wholeText + " " + text + " \n";
    }

    cout << wholeText;
    cout << "Hello";
    
    return 0;
}