//
// Created by dawid on 07.03.17.
//

#include "Polybius.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{


    string filename_read=argv[1];
    string filename_save=argv[2];
    string operation = argv[3];
    ifstream file_read(filename_read);
    ofstream file_save (filename_save, ios_base::in | ios_base::app);
    string word;
    string saved_file;

    if(!file_read or !file_save) cout << "Nie można otworzyć pliku!" << endl;

    while(file_read >> word)
    {
        if(operation=="1") file_save<<PolybiusCrypt(word);
        else file_save<<PolybiusDecrypt(word);
    }

    file_read.close();
    file_save.close();


    cout<<PolybiusDecrypt("4313244331154411243315");


    return 0;
}


