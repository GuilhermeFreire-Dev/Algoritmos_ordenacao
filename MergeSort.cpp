/*
    Algoritmo de ordenação MergeSort
*/

#include <iostream>
#include <ctime>

void merge(int* vetor, int const esquerda, int const meio, int const direita)
{
    int const arEsquerda = meio - esquerda + 1;
    int const arDireita = direita - meio;
    int* arrayEsquerda = new int[arEsquerda],
    * arrayDireita = new int[arDireita];

    if (arrayEsquerda != nullptr)
    {
        for (int i = 0; i < arEsquerda; i++)
        {
            arrayEsquerda[i] = vetor[esquerda + i];
        }
    }
    else
    {
        return;
    }

    if (arrayDireita != nullptr)
    {
        for (int j = 0; j < arDireita; j++)
        {
            arrayDireita[j] = vetor[meio + 1 + j];
        }
    }
    else
    {
        return;
    }

    int indice1 = 0,
    indice2 = 0;
    int indiceMeio = esquerda;

    while (indice1 < arEsquerda && indice2 < arDireita)
    {
        if (arrayEsquerda[indice1] <= arrayDireita[indice2])
        {
            vetor[indiceMeio] = arrayEsquerda[indice1];
            indice1++;
        }
        else
        {
            vetor[indiceMeio] = arrayDireita[indice2];
            indice2++;
        }
        indiceMeio++;
    }
    while (indice1 < arEsquerda)
    {
        vetor[indiceMeio] = arrayEsquerda[indice1];
        indice1++;
        indiceMeio++;
    }

    while (indice2 < arDireita)
    {
        vetor[indiceMeio] = arrayDireita[indice2];
        indice2++;
        indiceMeio++;
    }
}
void mergeSort(int* vetor, int const incio, int const fim)
{
    if (incio >= fim)
    {
        return;
    }

    int mid = incio + (fim - incio) / 2;
    mergeSort(vetor, incio, mid);
    mergeSort(vetor, mid + 1, fim);
    merge(vetor, incio, mid, fim);
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

double tempoDecorrido(time_t tempo)
{
    return (double)(tempo/(CLOCKS_PER_SEC/1000));
}

void runMergeSort(const int tam)
{
    time_t instante;
    int count = 0;
    double tempoTotal = 0;
    int *vetor = new int[tam];

    do
    {
        preencheVetor(vetor, tam);

        instante = clock();
        mergeSort(vetor, 0, tam - 1);
        instante = clock() - instante;
        count++;
        tempoTotal += tempoDecorrido(instante) / count;

    } while (tempoTotal <= 0);

    printf("Merge Sort com %d elementos\n", tam);
    printf("Tempo decorrido: %fms.", tempoTotal);
}

int main()
{
    runMergeSort(100);
    return EXIT_SUCCESS;
}