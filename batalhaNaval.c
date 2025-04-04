#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Inicializa todas as posições do tabuleiro com água (0)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
      for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        tabuleiro[i][j] = AGUA;
      }
    }
  }
  
  int posicionarNavioHorizontal(
      int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha,
      int coluna) {
    // Verifica se o navio cabe horizontalmente no tabuleiro
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
      printf("Erro: Navio horizontal ficaria fora do tabuleiro!\n");
      return 0;
    }
  
    // Verifica se não há sobreposição com outro navio
    for (int j = coluna; j < coluna + TAMANHO_NAVIO; j++) {
      if (tabuleiro[linha][j] == NAVIO) {
        printf("Erro: Posição já ocupada por outro navio!\n");
        return 0;
      }
    }
  
    // Posiciona o navio horizontalmente
    for (int j = coluna; j < coluna + TAMANHO_NAVIO; j++) {
      tabuleiro[linha][j] = NAVIO;
    }
  
    return 1;
  }
  
  int posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                              int linha, int coluna) {
    // Verifica se o navio cabe verticalmente no tabuleiro
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
      printf("Erro: Navio vertical ficaria fora do tabuleiro!\n");
      return 0;
    }
  
    // Verifica se não há sobreposição com outro navio
    for (int i = linha; i < linha + TAMANHO_NAVIO; i++) {
      if (tabuleiro[i][coluna] == NAVIO) {
        printf("Erro: Posição já ocupada por outro navio!\n");
        return 0;
      }
    }
  
    // Posiciona o navio verticalmente
    for (int i = linha; i < linha + TAMANHO_NAVIO; i++) {
      tabuleiro[i][coluna] = NAVIO;
    }
  
    return 1;
  }
  
  void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("  ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
      printf("%d ", j);
    }
    printf("\n");
  
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
      printf("%d ", i);
      for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%d ", tabuleiro[i][j]);
      }
      printf("\n");
    }
  }

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {


    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int navioHorizontal[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navioVertical[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};
  
    // Inicializar o tabuleiro com água
    inicializarTabuleiro(tabuleiro);
  
    // Posicionar navio horizontal na linha 2, começando na coluna 3
    if (posicionarNavioHorizontal(tabuleiro, 2, 3)) {
      printf("Navio horizontal posicionado com sucesso!\n");
    }
  
    // Posicionar navio vertical na coluna 7, começando na linha 4
    if (posicionarNavioVertical(tabuleiro, 4, 7)) {
      printf("Navio vertical posicionado com sucesso!\n");
    }
  
    // Exibir o tabuleiro
    printf("\nTabuleiro de Batalha Naval:\n");
    exibirTabuleiro(tabuleiro);
  
    return 0;
        

    
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

}
