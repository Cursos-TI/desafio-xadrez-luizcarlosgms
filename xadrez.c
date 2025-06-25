#include <stdio.h>

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.

int main() {
    // Nível Novato - Movimentação das Peças
    // Sugestão: Declare variáveis constantes para representar o número de casas que cada peça pode se mover.

    //Psição atual da peça no tabuleiro (lina e coluna de 0 a 7)
    int linha = 4; // Exemplo: posição inicial da peça na linha 4
    int coluna = 4; // Exemplo: posição inicial da peça na coluna 4

    printf("Peça posicionada em (%d, %d)\n", linha, coluna);

    // Implementação de Movimentação do Bispo
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação do Bispo em diagonal.
    printf("\nMovimentos do Bispo (diagonais):\n");

    //Diagonal Superior Esquerda
    for(int i = 1; linha - i >= 0; i++){
        printf("(%d, %d)\n", linha - i, coluna - i);
    }
    //Diagonal Superior Direita
    for(int i = 1; linha - i >= 0; i++){
        printf("(%d, %d)\n", linha - i, coluna + i);
    }
    //Diagonal Inferior Esquerda
    for(int i = 1; linha + i <= 7; i++){
        printf("(%d, %d)\n", linha + i, coluna - i);
    }
    //Diagonal Inferior Direita
    for(int i = 1; linha + i <= 7; i++){
        printf("(%d, %d)\n", linha + i, coluna + i);
    }

    // Implementação de Movimentação da Torre
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação da Torre para a direita.
    printf("\nMovimentos da Torre (para direita):\n");

    for(int j = coluna + 1; j < 8; j++) {
        printf("(%d, %d)\n", linha, j);
    }

    // Implementação de Movimentação da Rainha
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação da Rainha para a esquerda.
    printf("\nMovimentos da RAINHA(para esquerda):\n");
    for(int j = coluna - 1; j >= 0; j--) {
        printf("(%d, %d)\n", linha, j);
    }
    
    // Nível Aventureiro - Movimentação do Cavalo
    // Sugestão: Utilize loops aninhados para simular a movimentação do Cavalo em L.
    // Um loop pode representar a movimentação horizontal e outro vertical.
    printf("\nMovimentos do Cavalo (em L):\n");
    int movimentodCavalo[8][2] = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };
    for(int i = 0; i < 8; i++) {
        int novaLinha = linha + movimentodCavalo[i][0];
        int novaColuna = coluna + movimentodCavalo[i][1];
        if(novaLinha >= 0 && novaLinha < 8 && novaColuna >= 0 && novaColuna < 8) {
            printf("(%d, %d)\n", novaLinha, novaColuna);
        }
    }

    // Nível Mestre - Funções Recursivas e Loops Aninhados
    // Sugestão: Substitua as movimentações das peças por funções recursivas.
    // Exemplo: Crie uma função recursiva para o movimento do Bispo.

    // Sugestão: Implemente a movimentação do Cavalo utilizando loops com variáveis múltiplas e condições avançadas.
    // Inclua o uso de continue e break dentro dos loops.

    return 0;
}
