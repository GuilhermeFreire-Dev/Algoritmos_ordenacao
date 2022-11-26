/*
    Algoritmo de ordenação por inserção (Insertion Sort)
*/

#include <iostream>
#include <time.h>
#include <iomanip>

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

void tempoDecorrido(time_t tempo)
{
    double tempoTotal = (double)(tempo/(CLOCKS_PER_SEC/1000));

    std::cout << "Tempo decorrido: " << std::fixed << tempoTotal << std::setprecision(5) << "ms.\n";
}

int main()
{
    time_t tempo;
    const int tam = 100;
    int *vetor = new int[tam];

    preencheVetor(vetor, tam);
    std::cout << "Vetor nao ordenado:" << std::endl;
    mostrarVetor(vetor, tam);

    std::cout << "Vetor ordenado utilizando o algoritmo Insertion Sort:" << std::endl;

    tempo = clock();
    insertionSort(vetor, tam);
    tempo = clock() - tempo;

    mostrarVetor(vetor, tam);
    tempoDecorrido(tempo);

    return EXIT_SUCCESS;
}