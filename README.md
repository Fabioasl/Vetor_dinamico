# Vetor_dinamico
Atividade avaliativa para a matéria de algoritmos do curso de Tecnologia em Análise e Desenvolvimento de Sistemas

Arquivos base para implementação de classes de 
vetor dinâmico em C++. 
Cada classe esta definida no arquivo 'classe.hpp'. 
São 2 classes: 'Lista_ligada' e 'Vetor_dinamico', 
cada uma definida no respecivo arquivo, 
'Lista_ligada.hpp' e 'Lista_ligada.cpp'.
'Vetor_dinamico.hpp' e 'Vetor_dinamico.cpp'. 

São fornecidos arquivos de teste básicos. Um arquivo teste se chama push
e o outro se chama remove_at.O programa mostra 
na saída de erro o tempo total necessário para realizar o teste 
a que se propõe. 

Exemplo de como compilar o arquivo de teste de push_front em um
'Lista_ligada':
  g++ -Wall -o test-pushfront-linked-list-01 test-pushfront-linked-list-01.cpp 

Para executar:
  ./test-pushfront-linked-list-01 < push/e1.txt

Exemplo de como compilar o arquivo de teste de push_front em um
'Vetor_dinamico':
g++ -Wall -o test-pushfront-array-list-01 test-pushfront-array-list-01.cpp

Para executar:
./test-pushfront-array-list-01 < push/e1.txt

São fornecidos 8 arquivos de base para o programa de teste 
de inserção: e1.txt, e2.txt, e3.txt , e4.txt, e5.txt, e6.txt, e7.txt e e8.txt
no diretório 'push/' ou 'remove_at'. 

A primeira  linha de cada  arquivo contém um inteiro `n` 
com a quantidade  total de números do arquivo. 
Depois o arquivo contém `n` linhas, cada uma com um 
número inteiro.
Estes arquivos contém uma sequencia de números gerados de forma
aleatória através do programa `gen_array.cpp`. 

Para compilar o programa gen_array.c: 
  g++ -Wall -o gen_array gen_array.cpp

O programa `gen_array` recebe um valor inteiro `n`
como parâmetro e gera um arquivo com `n` números 
gerados de forma aleatória. Para gerar um arquivo 
com nome `meu_teste.txt`, com 1000 números inteiros:
  ./gen_array 1000 > meu_teste.txt 

O arquivo gerado `meu_teste.txt` terá n+1 linhas, 
a primeira com o valor 1000 e a 1000 com 
1 valor inteiro cada, gerados aleatoriamente. 

Existem cinco arquivo de teste de 'remove_at', no diretório 
'remove_at/': r1.txt , r2.txt, r3.txt, r4.txt , r5.txt e r6.txt. os 2 primeiros arquivos inserem 15 elementos 
e depois remove '10' elementos pelo índice.
no Terceiro arquivo são inseridos 100 elementos, no quarto 1000 elementos
no quinto 10000 elementos e no sexto 100000 elementos.
No arquivo 'r1.txt' 
é garantido que todos os '10' elementos a serem removidos são removidos, 
enquanto que o no arquivo 'r2.txt', apenas '8' dos '10' são removidos.
No arquivo 'r3.txt', apenas '19' dos '100' elementos serão removidos,
no arquivo 'r4.txt', apenas '90' dos '100' elementos serão removidos,
no arquivo 'r5.txt', apenas '1000' dos '10000' elementos serão removidos,
no arquivo 'r6.txt', apenas '10000' dos '100000' elementos serão removidos.


Exemplo de como compilar o arquivo de teste de remove)at em um
'Lista_ligada':
  g++ -Wall -o test-removeat-linked-list-01 test-removeat-linked-list-01.cpp 

Para executar:
  ./test-removeat-linked-list-01 < push/r1.txt

Exemplo de como compilar o arquivo de teste do remove_at em um
'Vetor_dinamico':
  g++ -Wall -o test-removeat-array-list-01 test-removeat-array-list-01.cpp 

Para executar:
  ./test-removeat-array-list-01 < remove_at/r1.txt


Faz parte do trabalhar a definição de testes para 
os métodos implementados. 

