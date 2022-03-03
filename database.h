#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED

#include <iostream>
#include "sqlite3.h"
#include <vector>
#include "pessoa.h"
#include <string>

using namespace std;


void connection();

void closedb();

void inserePessoa(Pessoa p);

vector <Pessoa> consultaPessoa();

void deletaPessoa(Pessoa p);

double avgIdade();

int pessoasRegiao();

#endif // DATABASE_H_INCLUDED
