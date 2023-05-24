#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PALAVRA 50

int palavraExistente(char palavra[], char palavrasUnicas[][MAX_PALAVRA], int numPalavras) {
    int i;
    for (i = 0; i < numPalavras; i++) {
        if (strcmp(palavra, palavrasUnicas[i]) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    char palavra[MAX_PALAVRA];
    char palavrasUnicas[MAX_PALAVRA][MAX_PALAVRA];
    int frequencia[MAX_PALAVRA] = {0};
    int numPalavrasUnicas = 0;
    int totalPalavras = 0;

    FILE* arquivo = fopen("texto.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    while (fscanf(arquivo, "%s", palavra) == 1) {
        int indice = palavraExistente(palavra, palavrasUnicas, numPalavrasUnicas);

        if (indice == -1) {
            strcpy(palavrasUnicas[numPalavrasUnicas], palavra);
            frequencia[numPalavrasUnicas]++;
            numPalavrasUnicas++;
        } else {
            frequencia[indice]++;
        }

        totalPalavras++;
    }

    // Exibe o resultado
    printf("Numero total de palavras: %d\n", totalPalavras);
    printf("Numero de palavras unicas: %d\n", numPalavrasUnicas);
    printf("Frequencia de cada palavra unica:\n");

    int i;
    for (i = 0; i < numPalavrasUnicas; i++) {
        printf("%s: %d\n", palavrasUnicas[i], frequencia[i]);
    }

    // Fecha o arquivo
    fclose(arquivo);

    return 0;
}
