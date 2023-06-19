#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#define MAX_PALAVRAS 10
#define MAX_CHANCES 7
#define MAX_TAMANHO_PALAVRA 20

// Estrutura para armazenar uma palavra e sua dica
typedef struct {
    char palavra[MAX_TAMANHO_PALAVRA];
    char dica[MAX_TAMANHO_PALAVRA];
} Palavra;

int main() {
    srand(time(NULL));

    setlocale(LC_ALL, "");

    // Cadastrar as palavras e dicas
    Palavra palavras[MAX_PALAVRAS] = {
        {"casa", "Local onde se mora"},
        {"computador", "Máquina eletrônica"},
        {"abacaxi", "Fruta tropical"},
        {"guitarra", "Instrumento musical"},
        {"praia", "Local de areia e mar"},
        {"carro", "Veículo automotor"},
        {"sorvete", "Gelado e saboroso"},
        {"escola", "Local de aprendizado"},
        {"livro", "Contém histórias e conhecimento"},
        {"chocolate", "Doce derivado do cacau"}
    };

    char letra;
    char letras_usadas[26] = {0};  // Array para armazenar as letras já testadas
    int num_palavra;
    int chances = MAX_CHANCES;

    printf("Bem-vindo ao Jogo da Forca!\n");

    while (1) {
        // Sortear uma palavra
        num_palavra = rand() % MAX_PALAVRAS;
        int tamanho_palavra = strlen(palavras[num_palavra].palavra);

        // Inicializar a palavra oculta com "_" para cada letra
        char palavra_oculta[MAX_TAMANHO_PALAVRA];
        for (int i = 0; i < tamanho_palavra; i++) {
            palavra_oculta[i] = '_';
        }
        palavra_oculta[tamanho_palavra] = '\0';

        // Loop principal do jogo
        while (1) {
            printf("\nDica: %s\n", palavras[num_palavra].dica);
            printf("Palavra: %s\n", palavra_oculta);
            printf("Chances restantes: %d\n", chances);
            printf("Letras já usadas: ");
            for (int i = 0; i < 26; i++) {
                if (letras_usadas[i]) {
                    printf("%c ", 'a' + i);
                }
            }
            printf("\n");

            printf("Digite uma letra: ");
            scanf(" %c", &letra);
            letra = tolower(letra);

            // Verificar se a letra já foi usada
            if (letras_usadas[letra - 'a']) {
                printf("Essa letra já foi usada. Tente novamente.\n");
                continue;
            }

            letras_usadas[letra - 'a'] = 1;

            // Verificar se a letra está presente na palavra
            int acertou = 0;
            for (int i = 0; i < tamanho_palavra; i++) {
                if (palavras[num_palavra].palavra[i] == letra) {
                    palavra_oculta[i] = letra;
                    acertou = 1;
                }
            }

            // Verificar se o jogador acertou ou errou
            if (acertou) {
                printf("Parabéns! Você acertou uma letra.\n");
            } else {
                printf("Letra errada. Tente novamente.\n");
                chances--;
            }

            // Verificar se o jogador ganhou ou perdeu
            if (strcmp(palavras[num_palavra].palavra, palavra_oculta) == 0) {
                printf("\nParabéns! Você acertou a palavra: %s\n", palavra_oculta);
                break;
            } else if (chances == 1) {
                printf("\nDica final: %s\n", palavras[num_palavra].dica);
            } else if (chances == 0) {
                printf("\nVocê perdeu! A palavra era: %s\n", palavras[num_palavra].palavra);
                break;
            }
        }

        // Perguntar se o jogador quer jogar novamente
        char opcao;
        printf("\nDeseja jogar novamente? (s/n): ");
        scanf(" %c", &opcao);
        if (tolower(opcao) != 's') {
            break;
        }

        // Resetar o jogo para uma nova partida
        memset(letras_usadas, 0, sizeof(letras_usadas));
        chances = MAX_CHANCES;
    }

    printf("\nObrigado por jogar! Até a próxima.\n");

    return 0;
}
