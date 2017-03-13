//
// Created by dawid on 13.03.17.
//

#include "XorCypherBreaker.h"
using namespace std;
vector<string> dictionary {"the","of"};
void PrintVector(vector<char> &v) {

    for(auto n : v) {

        cout << n;

    }
    cout<<endl;
}
string XorCypherBreaker(const vector<char> &cryptogram,
                             int key_length,
                             const vector<string> &dictionary)
{
    vector<char> decrypt;
    char letters[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int size=cryptogram.size(),sizeletters=26;
    char key[3];
    for(int l=0;l<sizeletters;l++){
        for(int j=0;j<sizeletters;j++)
        {
            for(int k=0;k<sizeletters;k++)
            {
                for(int i=0; i<size;i+=3) {
                    int a, b, c;
                    int n1,n2,n3;
                        if (cryptogram[i] + letters[l] > 122) {
                            n1=((cryptogram[i] + letters[l]) - 122)/25;
                            a = 97 + (cryptogram[i] + letters[l]) - 122-n1*25;
                        } else {
                            a = cryptogram[i] + letters[l];
                        }
                        if (cryptogram[i + 1] + letters[j] > 122) {
                            n2=((cryptogram[i+1] + letters[j]) - 122)/25;
                            b = 97 + (cryptogram[i + 1] + letters[j]) - 122-n2*25;
                        } else {
                            b = cryptogram[i + 1] + letters[j];
                        }
                        if (cryptogram[i + 2] + letters[k] > 122) {
                            n3=((cryptogram[i+2] + letters[k]) - 122)/25;
                            c = 97 + (cryptogram[i + 2] + letters[k]) - 122-n3*25;
                        } else {
                            c = cryptogram[i + 2] + letters[k];
                        }


                    char _a,_b,_c;
                    _a=a;
                    _b=b;
                    _c=c;

                    decrypt.emplace_back(_a);
                    decrypt.emplace_back(_b);
                    decrypt.emplace_back(_c);


                  // cout<<decrypt[i]<<decrypt[i+1]<<decrypt[i+2]<<a<<b<<c<<endl;
                }
                for(int m=0;m<decrypt.size()-3;m++)
                {
                    char w,x,y,z;
                    x=decrypt[m];
                    y=decrypt[m+1];
                    z=decrypt[m+2];
                    w=decrypt[m+3];
                    if((x=='t' and y=='h' and z=='a' and w=='t')) {
                        PrintVector(decrypt);
                        break;

                    }
                }
                decrypt.clear();
            }
        }
    }

}