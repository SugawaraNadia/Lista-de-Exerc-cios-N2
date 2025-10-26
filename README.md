Parte 1 – Teoria 
1. O que significa alocação estática de memória para um conjunto de elementos? 
A alocação estática de memória para um conjunto de elementos refere-se à reserva de memória para uma sequência de dados, como um array ou matriz, que possui um tamanho fixo e é organizada sequencialmente na memória do computador. Isso significa que, ao declarar uma variável estática, o programador reserva um espaço fixo para armazenar todos os elementos do conjunto de dados, e esse espaço permanece disponível durante toda a execução do programa. A alocação estática é útil em situações onde a quantidade de dados é conhecida em tempo de compilação e não pode ser alterada durante a execução

2. Qual a diferença entre alocação estática e alocação dinâmica?
A alocação estática é utilizada quando a quantidade de memória necessária é conhecida em tempo de compilação, enquanto a alocação dinâmica é utilizada quando a quantidade de memória é determinada em tempo de execução. A alocação estática é mais rápida, mas menos flexível, pois não permite alterar o tamanho da memória durante a execução. A alocação dinâmica, por outro lado, permite que o programa responda às necessidades de memória em tempo real, ajustando-se conforme necessário.

3. O que é um ponteiro? 
É uma variável que guarda o endereço de memória de outra variável.
Em vez de guardar um valor direto, ele “aponta” para onde o valor está.
Ex:
int x = 5;
int *p = &x; // p guarda o endereço de x
printf("%d", *p); // imprime 5

4. O que é uma estrutura de dados homogêneos? 
É uma estrutura que guarda elementos do mesmo tipo.
Exemplo clássico: vetores e matrizes.
 Ex: int notas[5]; // todos são inteiros

5. O que é uma estrutura de dados heterogêneos? 
É uma estrutura que pode conter elementos de tipos diferentes.
O exemplo clássico é a struct em C.

struct Pessoa {
    char nome[40];
    int idade;
    float altura;
};
Aqui cada campo tem um tipo diferente → heterogênea.

6. Qual a vantagem das listas sobre os vetores em termos de consumo de memória? 
Exemplifique. 
As listas encadeadas só usam memória proporcional à quantidade de elementos armazenados.
Já os vetores precisam reservar um bloco contínuo de memória, mesmo que parte dele fique vazia.
 Ex: Vetor: int v[100]; → reserva 100 posições, mesmo se só usar 10.
Lista: armazena nós conforme você insere elementos — usa menos memória se houver poucos dados.

7. O que é uma lista simplesmente encadeada? Apresente um diagrama para ilustrar 
essa estrutura de dados. 
Uma lista encadeada é uma estrutura de dados dinâmica composta por uma sequência de elementos chamados nós. Cada nó contém dois componentes principais: o valor armazenado e um ponteiro que referencia o próximo nó na sequência. Diferente de arrays, os elementos de uma lista encadeada não precisam estar em posições contíguas na memória, o que permite maior flexibilidade para inserções e remoções.
Características Principais 
Alocação Dinâmica: A lista cresce ou diminui conforme necessário, sem a necessidade de definir um tamanho fixo previamente.
Acesso Sequencial: Para acessar um elemento, é necessário percorrer a lista a partir do início até o nó desejado.
Flexibilidade: Inserções e remoções podem ser feitas de forma eficiente, especialmente no início ou no meio da lista.
Vantagens Inserção e Remoção Simples: Atualizar os ponteiros é suficiente para adicionar ou remover elementos, sem a necessidade de deslocar outros. Uso Eficiente de Memória: Apenas a memória necessária para os nós é alocada, evitando desperdícios. Facilidade para Implementar Outras Estruturas: Estruturas como filas e pilhas podem ser facilmente construídas a partir de listas encadeadas.


Desvantagens Acesso Lento: O acesso a um elemento específico requer a travessia sequencial da lista, resultando em complexidade O(n). Maior Consumo de Memória: Cada nó precisa armazenar, além do valor, o ponteiro para o próximo nó. Baixa Localidade de Memória: Como os nós estão dispersos na memória, o desempenho pode ser impactado em sistemas que dependem de cache.
Diagrama: 
[ dado | *prox ] → [ dado | *prox ] → [ dado | NULL ]
 
       Figura 1: Exemplo de lista encadeada.

8. O que é uma lista duplamente encadeada? Apresente um diagrama para ilustrar 
essa estrutura de dados. 
A lista duplamente encadeada é formada por nós similares ao da lista encadeada simples, porém com um atributo adicional: um apontador para o nó anterior. Dessa forma, é possível percorrer esse tipo de lista em ambas as direções. A Figura 1 redefine a estrutura “nó” vista anteriormente para adicionar o novo apontador e simplificar o armazenamento de dados, uma vez que a chave não é realmente necessário.Deve-se ter cuidado ao atualizar os apontadores dos nós durante as operações com esse tipo de lista. Se o apontador “anterior” de um dado nó tem valor NULO, então este é o nó cabeça. Se o apontador “próximo” de um dado nó tem valor NULO, este é o nó cauda (que contém o último elemento). Se o nó cabeça da lista é NULO, a lista está vazia 
 
       Figura 1: Exemplo de lista duplamente encadeada.

9. O que é uma lista duplamente encadeada? Apresente um diagrama para ilustrar 
essa estrutura de dados. ( PERGUNTA REPETIDA)

10. Explique o funcionamento do algoritmo de busca binária e sequencial. 
A busca binária é um algoritmo eficiente para encontrar elementos em um vetor ordenado, enquanto a busca sequencial é a abordagem mais simples e básica, que não requer a ordenação do vetor. A busca binária funciona ao dividir a lista em metades, descartando metade dos elementos, o que reduz a complexidade para uma ordem logarítimica. A busca sequencial, por outro lado, checa todos os elementos do vetor, o que é mais eficiente em listas não ordenadas ou em listas que não são indexadas. Ambos os algoritmos têm suas aplicações e limitações, sendo escolhidos em função do tipo de dados e do contexto em que são utilizados.
11. Explique o funcionamento dos seguintes algoritmos de ordenação: Insertion sort, 
Selection sort, Merge sort, Count sort, Quicksort.
InsertionSort:
Pega um elemento por vez e o insere na posição correta da parte já ordenada.
 Exemplo: arruma cartas na mão.
SelectionSort:
Procura o menor elemento e coloca no início, depois o segundo menor, e assim por diante.
 Exemplo: escolher o menor e trocar.
MergeSort:
Divide o vetor em duas metades, ordena recursivamente e depois intercala (merge).
 Complexidade: O(n log n)
CountingSort:
Conta quantas vezes cada valor aparece (funciona só com inteiros pequenos).
Muito rápido: O(n + k), onde k é o maior valor.
QuickSort:
Escolhe um pivô, divide o vetor em elementos menores e maiores que ele, e ordena recursivamente.
 Muito usado — geralmente o mais rápido na prática.
Complexidade média: O(n log n)

