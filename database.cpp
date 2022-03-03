#include "database.h"
#include "pessoa.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

sqlite3 *db;
sqlite3_stmt *stmt;
char *zErrMsg = 0;

string nome, regiao;
int idade;
int result;
string sql;

void connection()
{
    if(sqlite3_open("myDB.db",&db) == SQLITE_OK)
    {
        result = sqlite3_prepare_v2(db,"CREATE TABLE IF NOT EXISTS PESSOA (NOME, IDADE INT, REGIAO);", -1, &stmt, NULL);
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);

        if (result != SQLITE_OK)
        {
            cout << "\nERROR: " << sqlite3_errmsg(db) << endl;
        }
    }
}

void closedb()
{
    sqlite3_close(db);
}

void inserePessoa(Pessoa p)
{
    nome = p.nome;
    regiao = p.regiao;
    idade = p.idade;

    sql = "INSERT INTO PESSOA (NOME, IDADE, REGIAO) VALUES (?,?,?);";

    result = sqlite3_prepare_v2(db,sql.c_str(),-1,&stmt,0);

    sqlite3_bind_text(stmt,1,nome.c_str(),nome.length(), SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt,2,idade);
    sqlite3_bind_text(stmt,3,regiao.c_str(),regiao.length(),SQLITE_TRANSIENT);

    sqlite3_step(stmt);
    sqlite3_finalize(stmt);



    if (result != SQLITE_OK)
    {
        cout << "\nERROR: " << sqlite3_errmsg(db) << endl;
    }
    else
    {
        cout << "Data Inserted Successfully" << endl;
    }
}

vector <Pessoa> consultaPessoa()
{
    string n;
    
    vector <Pessoa> vetorPessoa;
    cout << "Digite o nome da pessoa que deseja consultar no banco de dados" << endl;
    cin >> n;
    sql = "SELECT * FROM PESSOA WHERE NOME = ?";
    result = sqlite3_prepare_v2(db,sql.c_str(),-1,&stmt,0);


    sqlite3_bind_text(stmt,1,n.c_str(),n.length(), SQLITE_TRANSIENT);

    if(result != SQLITE_OK)
    {
        cout << "\nERROR:" << sqlite3_errmsg(db) << endl;
    }
    else
    {
        cout <<"Nome\t"  << "Idade\t" << "Regiao\t" << endl;
        int idadePessoa;
        while (sqlite3_step(stmt) != SQLITE_DONE)
        {
            idadePessoa = sqlite3_column_int(stmt,1);
            nome = (const char *) (sqlite3_column_text(stmt,0));
            regiao = (const char *) (sqlite3_column_text(stmt,2));

            Pessoa pessoa(nome,idadePessoa,regiao);
            
            vetorPessoa.push_back(pessoa);
        }

    }
    cout << endl;
    sqlite3_finalize(stmt);

    return vetorPessoa;

}

void deletaPessoa(Pessoa p)
{
    nome = p.nome;
    idade = p.idade;
    regiao = p.regiao;

    sql = "DELETE FROM PESSOA WHERE (nome = ? AND idade = ? AND regiao = ?)";
    result = sqlite3_prepare_v2(db,sql.c_str(),-1,&stmt,NULL);

    sqlite3_bind_text(stmt,1,nome.c_str(),nome.length(), SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt,2,idade);
    sqlite3_bind_text(stmt,3,regiao.c_str(),regiao.length(),SQLITE_TRANSIENT);
    
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    if (result != SQLITE_OK)
    {
        cout << "\nERROR:" << sqlite3_errmsg(db) << endl;
    }
    else
    {
        cout << p <<"retirada do banco de dados\n" << endl;
    }
}

double avgIdade()
{
    int soma=0, c=0;

    sqlite3_prepare_v2(db,"SELECT * FROM PESSOA",-1,&stmt,0);

    while (sqlite3_step(stmt) != SQLITE_DONE)
    {
        soma = soma + sqlite3_column_int(stmt,1);
        c++;
    }

    sqlite3_finalize(stmt);

    return soma/c;
}

int pessoasRegiao()
{
    string r;
    int c = 0;
    cout << "Digite a sigla da regiao (minusculo) que deseja procurar a quantidade de pessoas existente" << endl;
    cin >> r;
    sqlite3_prepare_v2(db,"SELECT * FROM PESSOA WHERE REGIAO = ?", -1, &stmt, 0);

    sqlite3_bind_text(stmt,1,r.c_str(),r.length(),SQLITE_TRANSIENT);

    while (sqlite3_step(stmt) != SQLITE_DONE)
    {
        c++;
    }

    sqlite3_finalize(stmt);

    cout << "Em " << r << " existem ";
    return c;
}
