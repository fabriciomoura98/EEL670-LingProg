#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

class Pessoa
{
    public:
    Pessoa()=default;
    Pessoa (string, int, string);
    string nome, regiao;
    int idade;

};

ostream &operator<< (ostream&, Pessoa &);

#endif // PESSOA_H_INCLUDED
