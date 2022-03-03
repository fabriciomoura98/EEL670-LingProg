#include <iostream>
#include <vector>
#include "database.h"
#include "pessoa.h"

using namespace std;

int main()
{
    connection();

    string nome, regiao;
    int idade;

    vector <Pessoa> vP;
    int menu;
    cout << "Digite [1] para inserir pessoas" << endl;
    cout << "Digite [2] para consultar pessoas" << endl;
    cout << "Digite [3] para deletar pessoa por id" << endl;
    cout << "Digite [4] para calcular a media de idade" << endl;
    cout << "Digite [5] para saber a quantidade de pessoas em uma regiao" << endl;
    cout << "Digite [0] para sair" << endl;
    cin >> menu;

    if (menu==1)
    {
        
        cout << "Digite seu nome, idade e regiao: " << endl;
        cin >> nome;
        cin >> idade;
        cin >> regiao;
        Pessoa p(nome,idade,regiao);
        inserePessoa(p);
        cout << endl;
        main();
    }
    else if (menu==2)
    {
        vP = consultaPessoa();
        for (unsigned int i =0 ; i < vP.size(); i++)
        {
            cout << vP[i] << endl;
        }
        cout << endl;
        main();
    }
    else if(menu==3)
    {
        cout << "Digite o nome, idade e regiao da pessoa que deseja deletar: " << endl;
        cin >> nome;
        cin >> idade;
        cin >> regiao;
        Pessoa p(nome,idade,regiao);
        deletaPessoa(p);
        cout << endl;
        main();
    }
    else if (menu==4)
    {
        cout << "Media de idade: " << avgIdade() << endl;
        cout << endl;
        main();
    }
    else if (menu==5)
    {
        cout << pessoasRegiao() << " pessoas" << endl;
        cout << endl;
        main();
    }
    else if (menu==0)
    {
        closedb();
        return 0;
    }
}


