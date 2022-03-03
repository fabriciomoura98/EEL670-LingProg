#include "pessoa.h"
#include <string>

using namespace std;

ostream &operator<< (ostream &out, Pessoa &p)
{
    out << p.nome << "\t" << to_string(p.idade) << "\t" << p.regiao << endl;
    return out;
}

Pessoa::Pessoa(string n, int i, string r)
{
    nome = n;
    idade = i;
    regiao = r;
}