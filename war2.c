#include <stdio.h>
#include <string.h>

#define MAX_NOME 50
#define MAX_COR 20
#define QTD_TERRITORIOS 5

typedef struct {
    char nome[MAX_NOME];
    char cor[MAX_COR];
    int tropas;
} Territorio;

int main() {
    Territorio mapa[QTD_TERRITORIOS];

    for(int i = 0; i < QTD_TERRITORIOS; i++) {
        printf("\n--- Cadastro do Território %d ---\n", i+1);
        printf("Nome do território: ");
        fgets(mapa[i].nome, MAX_NOME, stdin);
        mapa[i].nome[strcspn(mapa[i].nome, "\n")] = '\0'; // Remove o '\n'

        printf("Cor do exército: ");
        fgets(mapa[i].cor, MAX_COR, stdin);
        mapa[i].cor[strcspn(mapa[i].cor, "\n")] = '\0';

        printf("Número de tropas: ");
        scanf("%d", &mapa[i].tropas);
        while(getchar() != '\n'); // Limpa o buffer do scanf
    }

    printf("\n=== ESTADO ATUAL DO MAPA ===\n");
    printf("| %-20s | %-15s | %-6s |\n", "Nome", "Cor Exército", "Tropas");
    printf("-----------------------------------------------\n");
    for(int i = 0; i < QTD_TERRITORIOS; i++) {
        printf("| %-20s | %-15s | %-6d |\n", mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }

    return 0;
}