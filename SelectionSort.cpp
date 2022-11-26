/*
    Algoritmo de ordenação por seleção (Selection Sort)
*/

#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

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

double tempoDecorrido(time_t tempo)
{
    return (double)(tempo/(CLOCKS_PER_SEC/1000));
}

void runSelectionSort(const int tam)
{
    time_t instante;
    int count = 0;
    double tempoTotal = 0;
    int *vetor = new int[tam];

    do
    {
        preencheVetor(vetor, tam);

        instante = clock();
        selectionSort(vetor, tam);
        instante = clock() - instante;
        count++;
        tempoTotal += tempoDecorrido(instante) / count;

    } while (tempoTotal <= 0);

    printf("Selection Sort com %d elementos\n", tam);
    printf("Tempo decorrido: %fms.", tempoTotal);
}

int main()
{
    runSelectionSort(100);
    return EXIT_SUCCESS;
}