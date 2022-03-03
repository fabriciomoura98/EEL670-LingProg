# EEL670-LingProg

# Project
- [Github Files](https://github.com/fabriciomoura98/EEL670-LingProg)
## Objetivo
O objetivo do trabalho é fazer um banco de dados de pessoas, e que nele podemos utilizar o C++ para fazer lógicas mais complexas que um banco de dados comum. 
![](https://i.imgur.com/PwYvXZY.png)
## Decisões de Projeto
É importante notar a utilização da escolha do sqlite para o nosso programa, isso porque é um database leve e que não se compara aos databases mais pesados como myql, mssql, oracle... Sendo assim ele utiliza um arquivo como SQL se comparando a uma chamada de  `fopen()`. Sendo assim portavel e mais leve, porem menos robusto.
## Modo de compilação
- É necessario instalar o sqlite
```bash=
sudo apt install sqlite3 libsqlite3-dev
make
```
## Modo de uso
O programa é todo controlado por meno então basta executar a main
```bash=
./main
```
## Classe Pessoa
A principal classe do nosso programa é a classe pessoa que é responsavel por possuir os atributos de idade,nome e região da mesma maneira que a modelagem do nosso banco de dados. Além disso, trabalhando com a classe `pessoa` utilizamos a sobrecarga do operador `<<` para facilitar a demonstração dos resultados obtidos na consulta SQL 
```cpp=
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
```
## Interface cpp + sql

Utilizaremos prepareStatement em funções SQL que sejam manipuladas de alguma forma pelo o usuário para evitar problemas de injeção de SQL ([OWASP SQL INJECTION](https://cheatsheetseries.owasp.org/cheatsheets/SQL_Injection_Prevention_Cheat_Sheet.html))
```cpp=
sqlite3_prepare_v2
```

## Menu c++
```cpp
"Digite [1] para inserir pessoas"
"Digite [2] para consultar pessoas"
"Digite [3] para deletar pessoa por id"
"Digite [4] para calcular a media de idade" 
"Digite [5] para saber a quantidade de pessoas em uma regiao" 
"Digite [0] para sair"
```
## Principais Funções do CPP
```cpp=
connection(); /* Responsavel por conectar ao arquivo de db */

void inserePessoa(Pessoa p) /* Responsavel por adicionar pessoa no db */

vector <Pessoa> consultaPessoa() /* Responsavel por consultar pessoas presentes no bd */
    
void deletaPessoa(Pessoa p) /* Responsavel por deletar pessoa presente no bd */
    
double avgIdade() /* Responsavel por pegar a media de idade do db */
    
int pessoasRegiao() /* Responsavel por a quantidade de pessoas em uma regiao do db */  
```

## Funções Externas

### Insere pessoa
Insere no banco de dados sql o objeto de classe pessoas com suas respectivas informações.
- Exemplo SQL
```sql=
INSERT INTO pessoas (nome, idade, regiao) VALUES (?, ?, ?);
```
### Deleta pessoa
Deleta pessoa do banco de dados
- Exemplo SQL
```sql=
DELETE FROM pessoas WHERE name = ?;
```
### Consulta Pessoa

Seleciona a pessoa através de uma entrada de string e retorna essa pessoa selecionada
- Exemplo SQL
```sql=
SELECT * FROM pessoas WHERE name = ?;
```

### Consulta Media Idade

Retorna a idade media das pessoas presentes no banco de dados. Porém evitamos utilizar essa função do SQL, para mostrar a facilidade de integração com o c++ e como é importante a correlação dessas aplicações, extendendo, facilitando, e, muitas vezes, "terceirizando" o processamento do banco de dados dados para a aplicação em c++. O mesmo foi feito para a quantidade de pessoas
- Exemplo SQL
```sql=
SELECT AVG(idade) AS idade FROM pessoas;
```
- Exemplo de media no cpp
```cpp
double avgIdade() 
```
### Quantidade de pessoas por regiao
Retorna a quantidade de pessoas por região
- Exemplo SQL
```sql=
SELECT COUNT(nome) FROM pessoas WHERE regiao="RJ";
```
- Exemplo de contagem no cpp
```cpp=
int pessoasRegiao()
```

### Video demo
![programarodando](https://user-images.githubusercontent.com/79655527/156664416-b96ebbf6-3e12-4a57-8c72-7c2b8924741f.gif)
