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
tabela_funcionarios
string nome
int cpf
float salario
FIM
----------------------------
Qual será a chave primária?
----------------------------
cpf

```


### 2. Listar todas as tabelas
O sistema listará todas as tabelas existentes, informando seus nomes e quantidade de linhas e colunas.

Exemplo de saída:

```
tabela_funcionarios
3 colunas || 7 linhas

tabela_cargos
2 colunas || 3 linhas

tabela_produtos
8 colunas || 12 linhas

```

### 3. Criar uma nova linha na tabela
O usuário informa o nome da tabela.
O sistema imprimirá o nome e tipo de cada uma das colunas.
O usuário deverá digitar um valor para cada uma das colunas.
Caso o usuário use uma chave primária repetida ou inválida, será emitida uma mensagem de erro.

Exemplo de um caso com erro:

```
tabela_funcionarios
string nome || int cpf || float salario
Pedro Paulo
12345678910
2500.50

---------------------------------------------------------------------------------
Erro! Já existe uma linha com essa chave primária. O registro não será inserido.
---------------------------------------------------------------------------------

```

### 4. Listar todos os dados de uma tabela
O usuário informa o nome da tabela.

Exemplo:

```
tabela_funcionarios
string nome || int cpf || float salario
Camilo Sinf || 12345678910 || 2500.50
Kleber Filho || 55344411211 || 9800.00
Maria Maria || 12398765400 || 4460.88

```

### 5. Pesquisar valor em uma tabela
O usuário informa o nome da tabela.
O sistema deverá fornecer as colunas disponíveis na tabela e o usuário deverá selecionar uma delas.
O sistema deverá solicitar o valor para pesquisar, disponibilizando algumas opções.

Exemplo:

```
tabela_funcionarios
-----------------------------------------------
As colunas disponíveis são:
string nome || int cpf || float salario
-----------------------------------------------

salario
-----------------------------------------------
Informe um valor e escolha uma das opções:
>: valores maiores que o valor informado
>=: valores maiores ou iguais que o valor informado
=: valores iguais o valor informado
<: valores menores que o valor informado
<=: valores menores ou iguais que o valor informado
p: valores próximos ao valor informado (se aplica apenas se a coluna for do tipo string)
-----------------------------------------------

4000
>
-----------------------------------------------
string nome || int cpf || float salario
Kleber Filho || 55344411211 || 9800.00
Maria Maria || 12398765400 || 4460.88
-----------------------------------------------

```

### 6. Apagar uma linha
O usuário deve informar o nome da tabela e a chave primária da tupla a ser apagada.

Exemplo:

```
tabela_funcionarios
12398765400

```

### 7. Apagar uma tabela
O usuário deve informar o nome da tabela a ser apagada.

Exemplo:

```
tabela_funcionarios

```


### 8. Sair
O programa é encerrado.