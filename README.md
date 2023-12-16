# Sistema de Gerenciamento de Banco de Dados (SGBD) na linguagem C
Projeto criado na disciplina de Introdução às Técnicas de Programação, durante o semestre de 2023.2.

## Menu
Quando o programa é iniciado, o sistema exibirá o seguinte menu:
```
-------------------------------------------
Digite o número correspondente à operação:
1. Criar uma tabela
2. Listar todas as tabelas
3. Criar uma nova linha na tabela
4. Listar todos os dados de uma tabela
5. Pesquisar valor em uma tabela
6. Apagar uma linha
7. Apagar uma tabela
8. Sair
-------------------------------------------
```

### 1. Criar uma tabela
O usuário informa o nome da tabela.
O usuário informa o nome dos atributos logo em seguida.
A inserção dos atributos deve seguir o formato "type name", em que "type" será um dos tipos primitivos em C ( char, int, float e double) e strings;
O usuário deverá digitar "FIM" quando terminar de inserir os atributos.
Será solicitado o nome da coluna que será a chave primária.

Exemplo:

```
>>>Insira o nome da tabela: tabela_funcionarios

>>>A primeira coluna da tabela será a chave primaria, do tipo inteiro sem sinal
>>>Insira o nome da coluna de chave primária
cpf

>>>Agora, vamos cadastrar as demais colunas, conforme o exemplo: string nome
>>>Os tipos disponíveis são: INT, CHAR, FLOAT, DOUBLE e STRING
>>>Digite 'FIM' para encerrar.
string nome
float salario
FIM

```


### 2. Listar todas as tabelas
O sistema listará todas as tabelas existentes, informando seus nomes e quantidade de linhas e colunas.

Exemplo de saída:

```
tabela_alunos
tabela_professores
tabela_funcionarios

```

### 3. Criar uma nova linha na tabela
O sistema exibe as tabelas existentes.
O usuário informa o nome da tabela.
O sistema imprimirá o nome e tipo de cada uma das colunas.
O usuário deverá digitar um valor para cada uma das colunas.
Caso o usuário use uma chave primária repetida ou inválida, será emitida uma mensagem de erro.

Exemplo de um caso com erro:

```
>>>Aqui está a lista de tabelas:
tabela_alunos
tabela_professores
tabela_funcionarios

>>>Insira o nome da tabela: tabela_funcionarios
>>>Insira um valor de tipo inteiro sem sinal para a chave primária 'cpf'
12345678910
>>>Insira um valor de tipo string para a coluna 'nome'
Pedro Paulo
>>>Insira um valor de tipo float para a coluna 'salario'
1250.80

```

### 4. Listar todos os dados de uma tabela
O sistema exibe as tabelas existentes.
O usuário informa o nome da tabela.

Exemplo:

```
>>>Aqui está a lista de tabelas:
tabela_alunos
tabela_professores
tabela_pessoa
tabela_loja
tab_funcionarios

>>>Insira o nome da tabela:tabela_funcionarios
                  cpf |                nome |             salario |
         unsigned_int |              string |               float |
 ------------------------------------------------------------------
          12345678910 |               Ramon |             5400.20 |                   
          23456789101 |               Doris |             9823.44 |   

```

### 5. Pesquisar valor em uma tabela
O sistema exibe as tabelas existentes.
O usuário informa o nome da tabela.
O sistema deverá fornecer as colunas disponíveis na tabela e o usuário deverá selecionar uma delas.
O sistema deverá solicitar o valor para pesquisar, disponibilizando algumas opções.
O sistema retornará todos os valores da coluna escolhida que se encaixam na pesquisa, juntamente com a chave primária da linha desses valores.

Exemplo:

```
>>>Aqui está a lista de tabelas:
tabela_alunos
tabela_professores
tabela_funcionarios

>>>Insira o nome da tabela: tab_funcionarios
>>>As colunas disponí­veis são:

>>>  1. : 'cpf' de tipo 'unsigned_int'
>>>  2. : 'nome' de tipo 'string'
>>>  3. : 'salario' de tipo 'float'

>>>Insira o número da coluna em que você quer pesquisar
3      

>>>A coluna escolhida foi: 'salario' de tipo 'float'

>>>Insira o valor a ser pesquisado
9000

OpÃ§Ãµes de pesquisa:
 1. Valores maiores que 9000
 2. Valores maiores ou iguais a 9000
 3. Valores iguais a 9000
 4. Valores menores que 9000
 5. Valores menores ou iguais a 9000
 6. Valores prÃ³ximos a 9000

>>>Insira o número da opção de pesquisa
1

>>>Resultado da pesquisa:
PK:23456789101 Valor:9823,00

```

### 6. Apagar uma linha
O sistema exibe as tabelas existentes.
O usuário escolhe uma tabela.
O sistema lista os dados da tabela escolhida.
O usuário informa a chave primária da tupla a ser apagada.

Exemplo:

``` 
>>>Aqui está a lista de tabelas:
tabela_alunos
tabela_professores
tab_funcionarios

>>>Insira o nome da tabela que contÃ©m a linha a ser apagada:tab_funcionarios
>>>Aqui está a tabela escolhida:
                  cpf |                nome |             salario |
         unsigned_int |              string |               float |
 ------------------------------------------------------------------
          12345678910 |               Ramon |             5400.20 |
          23456789101 |               Doris |             9823.44 |
 
>>>Insira o valor da chave primária da linha a ser apagada: 12345678910

```

### 7. Apagar uma tabela
O sistema exibe as tabelas existentes.
O usuário escolhe a tabela a ser apagada.

Exemplo:

``` 
>>>Aqui está a lista de tabelas:
tabela_alunos
tabela_professores
tabela_funcionarios

>>>Insira o nome da tabela a ser apagada:tabela_funcionarios

```


### 8. Sair
O programa é encerrado.