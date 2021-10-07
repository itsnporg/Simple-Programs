#include <stdio.h>
#include <stdlib.h>
#define ALGARISMO 11
#include <math.h>

int maiorValor(int *v, int tam){
    int maior = 0, i;
    for(i = 0 ; i < tam ; i++){
        if(v[i] > maior){
            maior = v[i];
        }
    }
    return maior;
}

void radixSort(int *v, int *org, int tam, int i){
    int k, j;
    int vetAux[ALGARISMO];

    for(k = 0 ; k <= ALGARISMO ; k++)
        vetAux[k] = 0;
    for(j = 0 ; j < tam ; j++)
        vetAux[((v[j] % (int)pow(10,i)) / (int)pow(10,i-1))] = vetAux[((v[j] % (int)pow(10,i)) / (int)pow(10,i-1))] + 1;
    for(k = 1 ; k <= ALGARISMO ; k++)
        vetAux[k] = vetAux[k] + vetAux[k-1];
    for(k = tam-1 ; k >= 0 ; k--){
        int c = vetAux[((v[k] % (int)pow(10,i)) / (int)pow(10,i-1))];
        org[c] = v[k];
        vetAux[((v[k] % (int)pow(10,i)) / (int)pow(10,i-1))] = vetAux[((v[k] % (int)pow(10,i)) / (int)pow(10,i-1))] - 1;
    }
}

int main(){
    int *v, *org, i, j, tam, grande = 0, valor = 0;

    printf("Entre com o tamanho do vetor: ");
    scanf("%d", &tam);

    v = (int*)malloc(tam*sizeof(int));
    org = (int*)malloc(tam*sizeof(int));

    printf("Preencha o vetor\n");
    for(i = 0 ; i < tam ; i++){
        printf("Elemento %d: ", i+1);
        scanf("%d", &v[i]);
    }
    grande = maiorValor(v, tam);
    while(grande > 0){
        grande = grande / 10;
        valor++;
    }

    printf("\nVetor desodernado\n");
    for(i = 0 ; i < tam ; i++){
        printf("%d\t", v[i]);
    }
    for(i = 1 ; i <= valor ; i++){
        radixSort(v, org, tam, i);
    }

    printf("\nVetor Ordernado\n");
    for(i = 1 ; i <= tam ; i++){
        printf("%d\t", org[i]);
    }
    return 0;
}


