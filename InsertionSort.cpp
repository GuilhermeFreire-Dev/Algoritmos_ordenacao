/*
    Algoritmo de ordenação por inserção (Insertion Sort)
*/

#include <iostream>
#include <ctime>

void insertionSort(int *vetor, int tam) 
{
    //Algoritmo de ordenação Insertion Sort
    int chave;
    int i;

    for (int j = 1; j < tam; j++) 
    {
        chave = vetor[j];
        i = j - 1;

        while (i >= 0 && vetor[i] > chave) 
        {
            vetor[i + 1] = vetor[i];
            i--;
        }
        vetor[i + 1] = chave;
    }
}

void preencheVetor(int *vetor, int tam)
{
    //Essa função preenche o vetor passado como parâmetro com números aleatórios
    int i;
    int maxTam = tam * 2;
    //Gerando uma semente para produzir números pseudoaleatórios
    unsigned seed = time(0);
    srand(seed);

    for (i = 0; i < tam; i++)
        vetor[i] = 1 + rand() % maxTam;
}

void mostrarVetor(int *vetor, int tam)
{
    //Essa função imprime na tela o vetor passado como parâmetro
    for (int i = 0; i < tam; i++)
    {
        std::cout << vetor[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    const int tam = 10;
    int *vetor = new int[tam];

    preencheVetor(vetor, tam);
    std::cout << "Vetor nao ordenado:" << std::endl;
    mostrarVetor(vetor, tam);

    std::cout << "Vetor ordenado utilizando o algoritmo Insertion Sort:" << std::endl;
    insertionSort(vetor, tam);
    mostrarVetor(vetor, tam);
}