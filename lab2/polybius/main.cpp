//
// Created by dawid on 07.03.17.
//

#include <iostream>
#include "Polybius.h"
using namespace std;
int main(int argc, char **argv) {
/*
if (argv[1]==1)
{
    ifstream myfile(argv[2]);
    ofstream myfilesave (argv[3], ios_base::in | ios_base::app);
    string word;

    if(!myfile)
        cout << "Nie można otworzyć pliku!" << endl;

    while(myfile >> word)
    {
        myfilesave << PolybiusDecrypt(word);
    }




    myfilesave.close();
    myfile.close();
    return 0;
}
    else if(argv[1]==0)
{
    //odszyfr
}
    else
{
    cout<<"0 albo 1"<<endl;
}
*/
string message="3245334455";
    cout<<PolybiusDecrypt(message);

return 0;
}
