#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define TAMANHO_HABILIDADE 5

#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// Inicializa o tabuleiro preenchendo com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
  for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
      tabuleiro[i][j] = AGUA;
    }
  }
}

// Posiciona um navio horizontal de tamanho 3
int posicionarNavioHorizontal(
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha,
    int coluna) {
  if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO)
    return 0;
  for (int j = coluna; j < coluna + TAMANHO_NAVIO; j++) {
    if (tabuleiro[linha][j] == NAVIO)
      return 0;
  }
  for (int j = coluna; j < coluna + TAMANHO_NAVIO; j++) {
    tabuleiro[linha][j] = NAVIO;
  }
  return 1;
}

// Posiciona um navio vertical de tamanho 3
int posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                            int linha, int coluna) {
  if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO)
    return 0;
  for (int i = linha; i < linha + TAMANHO_NAVIO; i++) {
    if (tabuleiro[i][coluna] == NAVIO)
      return 0;
  }
  for (int i = linha; i < linha + TAMANHO_NAVIO; i++) {
    tabuleiro[i][coluna] = NAVIO;
  }
  return 1;
}

// Gera a matriz da habilidade em forma de CONE
void gerarMatrizCone(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
  for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
    for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
      // Condição para formar um cone apontando para baixo
      if (j >= TAMANHO_HABILIDADE / 2 - i && j <= TAMANHO_HABILIDADE / 2 + i) {
        matriz[i][j] = 1;
      } else {
        matriz[i][j] = 0;
      }
    }
  }
}

// Gera a matriz da habilidade em forma de CRUZ
void gerarMatrizCruz(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
  int centro = TAMANHO_HABILIDADE / 2;
  for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
    for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
      // Linhas e colunas centrais formam a cruz
      if (i == centro || j == centro) {
        matriz[i][j] = 1;
      } else {
        matriz[i][j] = 0;
      }
    }
  }
}

// Gera a matriz da habilidade em forma de OCTAEDRO (losango)
void gerarMatrizOctaedro(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
  int centro = TAMANHO_HABILIDADE / 2;
  for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
    for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
      // Fórmula para formar um losango (baseada na distância de Manhattan)
      if (abs(i - centro) + abs(j - centro) <= centro) {
        matriz[i][j] = 1;
      } else {
        matriz[i][j] = 0;
      }
    }
  }
}

// Aplica a matriz da habilidade ao tabuleiro, centralizando no ponto de origem
void aplicarHabilidadeAoTabuleiro(
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
    int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int origemLinha,
    int origemColuna) {
  int centro = TAMANHO_HABILIDADE / 2;
  for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
    for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
      // Posição correspondente no tabuleiro
      int linhaTabuleiro = origemLinha - centro + i;
      int colunaTabuleiro = origemColuna - centro + j;

      // Verifica se está dentro dos limites do tabuleiro
      if (linhaTabuleiro >= 0 && linhaTabuleiro < TAMANHO_TABULEIRO &&
          colunaTabuleiro >= 0 && colunaTabuleiro < TAMANHO_TABULEIRO) {
        // Aplica a habilidade apenas onde a matriz tiver valor 1 e onde não há
        // navio
        if (habilidade[i][j] == 1 &&
            tabuleiro[linhaTabuleiro][colunaTabuleiro] != NAVIO) {
          tabuleiro[linhaTabuleiro][colunaTabuleiro] = HABILIDADE;
        }
      }
    }
  }
}

// Exibe o tabuleiro com cabeçalhos e diferentes representações
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

int main() {
  int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
  int matrizCone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
  int matrizCruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
  int matrizOctaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

  inicializarTabuleiro(tabuleiro);

  // Posicionar dois navios
  posicionarNavioHorizontal(tabuleiro, 2, 3);
  posicionarNavioVertical(tabuleiro, 4, 7);

  // Gerar as habilidades
  gerarMatrizCone(matrizCone);
  gerarMatrizCruz(matrizCruz);
  gerarMatrizOctaedro(matrizOctaedro);

  // Aplicar habilidades no tabuleiro (você pode alterar as coordenadas de
  // origem)
  aplicarHabilidadeAoTabuleiro(tabuleiro, matrizCone, 1,
                               2); // Cone no topo esquerdo
  aplicarHabilidadeAoTabuleiro(tabuleiro, matrizCruz, 5, 5); // Cruz no centro
  aplicarHabilidadeAoTabuleiro(tabuleiro, matrizOctaedro, 7,
                               8); // Octaedro no canto inferior direito

  // Mostrar o tabuleiro final
  printf("\nTabuleiro com habilidades aplicadas:\n");
  exibirTabuleiro(tabuleiro);

  return 0;
}


    
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


