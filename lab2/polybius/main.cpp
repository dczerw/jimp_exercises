//
// Created by dawid on 07.03.17.
//

#include <iostream>
#include "Polybius.h"
using namespace std;
int main(int argc, char **argv) {
    string input_file=argc[0],output_file=argc[1];
    int choice=argc[2];
    if(choice==1)
    {
        ifstream myfile(input_file);
        char word[64];

        if(!myfile)
            cout << "Nie można otworzyć pliku!" << endl;

        while(myfile >> word){
            PolybiusCrypt(word);
            ofstream myfileout (output_file, ios_base::in | ios_base::app);

            if(!myfile)
                cout << "Nie można otworzyć pliku!" << endl;

            myfileout << word<< endl;



        }
        }


        myfile.close();
        return 0;
    }
    else
    {

    }



}
