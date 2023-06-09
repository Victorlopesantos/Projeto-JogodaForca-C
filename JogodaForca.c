#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define maximo_de_tentativas 3
#define maximo_de_palavras 11
#define tamanho_da_palavra 20

char *palavras[maximo_de_palavras] = {"abacaxi", "banana", "laranja", "limao", "manga", "uva", "melancia", "morango", "pera", "kiwi", "carambola"};

void desenhaForca(int tentativas) 
{
    printf(" +-----+\n");
    printf(" |     |\n");
    
    if (tentativas >= 1) 
    {
        printf(" O     |\n");
    } 
    else 
    {
        printf("       |\n");
    }
    
    if (tentativas >= 2) 
    {
        printf("/|\\    |\n");
    }
    else 
    {
        printf("       |\n");
    }
    
    if (tentativas >= 3) 
    {
        printf("/ \\    |\n");
    } 
    else 
    {
        printf("       |\n");
    }
    
        printf("       |\n");
        printf("       |\n");
        printf("=========\n");
}

int main(void) 
{
    srand(time(NULL)); 

    char palavra[tamanho_da_palavra + 1];
    char palavraComUnderscores[tamanho_da_palavra * 2];
    int tamanhoPalavra;
    int i;
    int tentativas;
    int acertos;
    char letra;
    int jogoContinua = 1;
    
    printf("\n\nBem-vindo ao jogo da forca!\n");
    printf("\nO objetivo do jogo e adivinhar a palavra escolhida.\n");
    printf("\nAs palavras sao nomes de frutas conhecidas.\n");
    printf("\nVoce pode errar no maximo %d vezes.\n", maximo_de_tentativas);
    printf("\nBoa sorte!\n\n");
    
    while (jogoContinua) 
    {
        
        strcpy(palavra, palavras[rand() % maximo_de_palavras]);

        tamanhoPalavra = strlen(palavra);
        
        for (i = 0; i < tamanhoPalavra * 2; i++) 
        {
            if (i % 2 == 0) 
            {
                palavraComUnderscores[i] = '_';
            } 
            else 
            {
                palavraComUnderscores[i] = ' ';
            }
        }
        palavraComUnderscores[tamanhoPalavra * 2 - 1] = '\0';
        
        tentativas = 0;
        acertos = 0;
        
        while (tentativas < maximo_de_tentativas && acertos < tamanhoPalavra) 
        {
            desenhaForca(tentativas);

            printf("\nPalavra: %s\n", palavraComUnderscores);
            printf("\nTentativas restantes: %d\n", maximo_de_tentativas - tentativas);
            printf("\nDigite uma letra: ");
            scanf(" %c", &letra);
            
            for (i = 0; i < tamanhoPalavra; i++) 
            {
                if (palavra[i] == letra && palavraComUnderscores[i * 2] == '_') 
                {
                    palavraComUnderscores[i * 2] = letra;
                    acertos++;
                }
            }
            
            if (acertos == tamanhoPalavra) 
            {
                printf("\nParabens, voce venceu!\n");
                printf("\nA palavra era: %s\n", palavra);
                break;
            } 
            else if (strchr(palavraComUnderscores, '_') == NULL) 
            {
                printf("\nParabens, voce venceu!\n");
                printf("\nA palavra era: %s\n", palavra);
                break;
            } 
            else if (strchr(palavra, letra) == NULL) 
            {
                printf("\nA letra %c nao esta na palavra.\n", letra);
                tentativas++;
            }
        }
        
        if (tentativas == maximo_de_tentativas) 
        {
            desenhaForca(tentativas);

            printf("\nVoce perdeu.\n");
            printf("\nA palavra era: %s\n", palavra);
        }
        
        printf("\nDigite 1 para jogar novamente ou qualquer outro numero para sair: ");
        scanf("%d", &jogoContinua);
    }
    
    printf("\nObrigado por jogar o jogo da forca!\n");
    
    return 0;
}