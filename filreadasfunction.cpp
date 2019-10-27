#include<iostream>
#include<fstream>
using namespace std;
void encrypt();
int main(){
encrypt();
}
void encrypt(){

char ch;
fstream fin("Encryptme.txt", fstream::in);
ofstream ready("ASCII.txt", ofstream::out);
int ascii;
int temp;
int shift;
int n;
while (fin >> noskipws >> ch){
    ascii=0;
    shift=8;
    //cout << ch;
    //cast to int
    ascii=int(ch);

    if(fin.eof())
        {ch='?';
        temp=int(ch);
        temp=temp<<shift;
        ascii+=ch;

        //cout << ch;
    }
    else{
        fin.get(ch);
        temp=int(ch);
        temp=temp<<shift;
        ascii+=temp;
        //cout << ch;
        }
    shift+=8;
    if(fin.eof())
        {ch='.';
        temp=int(ch);
        temp=temp<<shift;
        ascii+=temp;
        //cout << ch;
    }
    else{
        fin.get(ch);
        temp=int(ch);
        temp=temp<<shift;
        ascii+=temp;
        //cout << ch;
    }


    //encrypt
    //write to file
    ready<<ascii;
    ready<<"\n";
    //decrypt
    //read from file
    n=ascii%256;
    ch=char(n);
    cout<<ch;
    ascii=ascii/256;
    n=ascii%256;
    ch=char(n);
    cout<<ch;
    ascii=ascii/256;
    ch=char(ascii);
    cout<<ch;}

    cout<<" OK, done";
    fin.close();
    ready.close();
}
