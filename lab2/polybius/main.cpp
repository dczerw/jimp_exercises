//
// Created by dawid on 07.03.17.
//

#include "Polybius.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{


    ifstream file_read("file1.txt");
    ofstream file_save ("file2.txt", ios_base::in | ios_base::app);
    string word;
    string saved_file;

    if(!file_read or !file_save) cout << "Nie można otworzyć pliku!" << endl;

    while(file_read >> word) file_save<<PolybiusCrypt(word);

    file_read.close();
    file_save.close();


    cout<<PolybiusDecrypt("4313244331154411243315");


    return 0;
}


