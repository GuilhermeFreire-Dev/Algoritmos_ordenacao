/*
    Algoritmo de ordenação por seleção (Selection Sort)
*/

#include <iostream>
#include <ctime>

void selectionSort(int *vetor, int tam)
{
    //Algoritmo de ordenação Selection Sort
    int menor;

    for (int i = 0; i < tam - 1; i++)
    {
        menor = i;

        for (int j = i + 1; j < tam; j++)
        {
            if (vetor[j] < vetor[menor])
                menor = j;
        }
        int aux = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = aux;
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

    std::cout << "Vetor ordenado utilizando o algoritmo Selection Sort:" << std::endl;
    selectionSort(vetor, tam);
    mostrarVetor(vetor, tam);
}