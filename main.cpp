//
//  main.cpp
//  trials_temp
//
//  Created by Nithya Murali on 2/1/18.
//  Copyright © 2018 Nithya Murali. All rights reserved.
//

#include <iostream>
#include <iostream>
#include <map>
#include <string>
#include <math.h>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

//converts back to base 27 from decimal
void decimaltoBearcatII(int decimal_number, int num_len,std::map<char,int> *mymap)
{
   /* std::map<char,int> mymap;
    std::map<char,int>::iterator it;
    mymap[' ']= 0;mymap['A']= 1;mymap['B']= 2;mymap['C']= 3;mymap['D']=4;mymap['E']=5;mymap['F']=6;mymap['G']= 7;mymap['H']= 8;mymap['I']= 9;mymap['J']= 10;mymap['K']= 11;mymap['L']= 12;mymap['M']= 13;mymap['N']= 14;mymap['O']= 15;mymap['P']= 16;mymap['Q']= 17;mymap['R']= 18;mymap['S']= 19;mymap['T']= 20;mymap['U']= 21;mymap['V'] = 22;mymap['W']= 23;mymap['X']= 24;mymap['Y']= 25;mymap['Z']= 26;*/
    char keys[50];
    //cout<<"\nin backtobase\n";
    //cout<<decimal_number<<"\n\n";
    int num_values[50] = {};
    int count = (num_len - 1);
    int d_dec = 0;
    int m = 0;
    //cout<<"\n";
    cout<<"\ndeciamlnumber toBearcatII:";
    for(int i = 0; i< num_len;i++)
    {
        d_dec = decimal_number / 27;
        //cout<<"\nd_dec:"<<decimal_number;
        num_values[count--] = decimal_number % 27;
        m = decimal_number % 27;
        decimal_number = d_dec;
    }
    for(int i = 0; i< num_len;i++)
    {
        cout<<num_values[i];
    }
    std::map<char,int>::iterator it;
    cout<<"\nPlaintext from the BEARCATII:";
    for(int i = 0; i< num_len;i++)
    {
        //cout<<num_values[i];
        for (it = mymap->begin(); it != mymap->end(); ++it)
        {
            if (it->second == num_values[i])
            {
                keys[i] = it->first;
                cout<<keys[i];
            }
        }
    }
    cout<<"\n";
}

//converts to decimal by multiplying with powers of 27
int BearcatIItodecimalnumber(int num_vals[], int num_length)
{
    //cout<<"in decimal number\n";
    int dec_number = 0;
    int power_num = 0;
    int number = 0;
    int count = (num_length - 1);
    for(int i = 0; i < num_length; i++)
    {
        //cout<<num_vals[count--]<<"\n";
        power_num = pow(27,i);
        //cout<<"\npow_num:"<<power_num;
        number = num_vals[count--];
        //cout<<"\nnumber_vals:"<<number;
        dec_number += number * power_num;
        //cout<<dec_number;
    }
    //cout<<dec_number;
    return dec_number;
    //decimaltoBearcatII(dec_number,num_length,&mymap);
}

//get the ascii values for the input message
void messagetoBearcat(string msg)
{
    int msglt = 0;
    int base = 0;
    int dec_count=0;
    //charaters assigned their values in a define map
    std::map<char,int> mymap;
    std::map<char,int>::iterator it;
    mymap[' ']= 0;mymap['A']= 1;mymap['B']= 2;mymap['C']= 3;mymap['D']=4;mymap['E']=5;mymap['F']=6;mymap['G']= 7;mymap['H']= 8;mymap['I']= 9;mymap['J']= 10;mymap['K']= 11;mymap['L']= 12;mymap['M']= 13;mymap['N']= 14;mymap['O']= 15;mymap['P']= 16;mymap['Q']= 17;mymap['R']= 18;mymap['S']= 19;mymap['T']= 20;mymap['U']= 21;mymap['V'] = 22;mymap['W']= 23;mymap['X']= 24;mymap['Y']= 25;mymap['Z']= 26;
    msglt = int(msg.length());
    int num_values[50] = {};
    cout<<"\n";
    //cout<<"in func length:"<<msglt<<"\n";
    cout<<"\nmessage to Bearcat:";
    for(int i=0;i < msglt;i++)
    {
        int n;
        n = mymap.find(msg[i])->second;
        num_values[i] = n;
        //cout<<num_values[i];
    }
    stringstream ss;
    for (int i = 0; i < msglt; ++i)
    {
        ss << num_values [i];
    }
    ss>>base;
    cout<<base;
    dec_count = BearcatIItodecimalnumber(num_values,msglt);
    cout<< "\nBEARCATII to decimal:"<<dec_count;
    decimaltoBearcatII(dec_count,msglt,&mymap);
}

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    
    string message;
    //obtain the message from user
    cout<<"Please Enter the message in BLOCK letters:";
    std::getline(std::cin,message);
    cout<<"\nMessage:"<<message;
    messagetoBearcat(message);
    return 0;
}
