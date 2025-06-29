#include <stdio.h>
#include <string.h>
#include <locale.h>

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.

// Nível Novato - Movimentação das Peças
// Sugestão: Declare variáveis constantes para representar o número de casas que cada peça pode se mover.

// Implementação de Movimentação do Bispo
// Sugestão: Utilize uma estrutura de repetição para simular a movimentação do Bispo em diagonal.
void movimento_bispo(int casas, char direcao[])
{
    printf("\nMovimentos do Bispo (diagonais):\n");
    int i = 0;
    do
    {
        printf("%s\n", strlen(direcao) > 0 ? direcao : "Direção Inválida");
        i++;
    } while (i < casas);
    printf("\n");
}

// Implementação de Movimentação da Torre
// Sugestão: Utilize uma estrutura de repetição para simular a movimentação da Torre para a direita.
void movimento_torre(int casas, char direcao[])
{
    printf("\nMovimento da TORRE:\n");
    int i = 0;
    while (i < casas)
    {
        printf("%s\n", strlen(direcao) > 0 ? direcao : "Direção Inválida");
        i++;
    }
    printf("\n");
}

// Implementação de Movimentação da Rainha
// Sugestão: Utilize uma estrutura de repetição para simular a movimentação da Rainha para a esquerda.
void movimento_rainha(int casas, char direcao[])
{
    printf("\nMovimento da RAINHA:\n");
    for (int i = 0; i < casas; i++)
    {
        printf("%s\n", strlen(direcao) > 0 ? direcao : "Direção Inválida");
    }
    printf("\n");
}

// Nível Aventureiro - Movimentação do Cavalo
// Sugestão: Utilize loops aninhados para simular a movimentação do Cavalo em L.
void movimento_cavalo(int casas, char direcao[])
{
    printf("\nMovimento do Cavalo (em L):\n");

    int movimentos = 0;

    for (int i = 0; i <= 2 && movimentos < casas; i++)
    {
        for (int j = 0; j <= 2 && movimentos < casas; j++)
        {
            // Verifica se é um movimento em L
            if ((i == 2 && j == 1) || (i == 1 && j == 2))
            {
                // Direção vazia? Pula.
                if (strlen(direcao) == 0)
                {
                    printf("Direção inválida. Pulando com continue.\n");
                    continue;
                }

                printf("Movimento %d: %s (2x%d, 1x%d)\n", movimentos + 1, direcao, i, j);
                movimentos++;
            }

            // Encerra se já atingiu o número de casas
            if (movimentos >= casas)
            {
                printf("Limite de movimentos alcançado com break.\n");
                break;
            }
        }
    }

    printf("\n");
}

// Nível Mestre - (Expansível para recursão futura)

int main()
{
    setlocale(LC_ALL, "");

    char direcao[30];
    int casas, peca;

    printf("Desafio de Xadrez - MateCheck\n\n");

    printf("Escolha uma peça:\n");
    printf("1. Torre\n");
    printf("2. Bispo\n");
    printf("3. Rainha\n");
    printf("4. Cavalo\n");
    printf("5. Sair\n");
    printf("Digite o número correspondente: ");
    scanf("%d", &peca);

    // Saída com operador ternário
    (peca == 5) ? printf("Saindo do Jogo\n") : 0;

    // Se for opção inválida
    if (peca < 1 || peca > 5)
    {
        printf("Opção Inválida\n");
        return 1;
    }

    // Se for a opção de sair, finaliza
    if (peca == 5)
        return 0;

    // Pergunta número de casas
    printf("Quantas casas mover? ");
    scanf("%d", &casas);
    getchar(); // limpar buffer

    // Pergunta direção, com instruções dependendo da peça
    switch (peca)
    {
    case 1:
        printf("Direção (ex: Direita, Esquerda, Superior, Inferior): ");
        break;
    case 2:
        printf("Direção (ex: Diagonais - Superior-Direita, Superior-Esquerda, Inferior-Direita, Inferior-Esquerda): ");
        break;
    case 3:
        printf("Direção (ex: Direita, Esquerda, Superior, Inferior ou Diagonais(Superior-Direita, Superior-Esquerda, Inferior-Direita, Inferior-Esquerda)): ");
        break;
    case 4:
        printf("Direção (ex: qualquer direção que represente um L: 2x1 ou seja 3 casas): ");
        break;
    }
    fgets(direcao, sizeof(direcao), stdin);
    direcao[strcspn(direcao, "\n")] = 0; // remove \n

    // Agora executa a função da peça escolhida
    switch (peca)
    {
    case 1:
        movimento_torre(casas, direcao);
        break;
    case 2:
        movimento_bispo(casas, direcao);
        break;
    case 3:
        movimento_rainha(casas, direcao);
        break;
    case 4:
        movimento_cavalo(casas, direcao);
        break;
    }

    return 0;
}