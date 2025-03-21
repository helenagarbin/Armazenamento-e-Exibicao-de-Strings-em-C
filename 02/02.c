#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

/*
Aluna: Helena Tubino Garbin
2. Escreva um programa que receba do usuário uma string menor que 200 caracteres e o nome do arquivo no qual ela deve ser armazenada.
Em seguida, ler do arquivo esta string armazenada e imprimir na tela a string em letra maiúscula.
*/

int main() {
    setlocale(LC_ALL,"Portuguese");

    char string[200];
    char nome_arquivo[100];
    char valor_string[200];
    int i;
    FILE *arquivo;


    printf("\nDigite uma string que seja menor que 200 caracteres: ");
    fgets(string, sizeof(string), stdin);


    size_t tamanho = strlen(string);
    if (tamanho > 0 && string[tamanho - 1] == '\n')
    {
        string[tamanho - 1] = '\0';
    }


    printf("\nDigite o nome do arquivo no qual a string será armazenada: ");
    fgets(nome_arquivo, sizeof(nome_arquivo), stdin);

    tamanho = strlen(nome_arquivo);
    if (tamanho > 0 && nome_arquivo[tamanho - 1] == '\n')
    {
        nome_arquivo[tamanho - 1] = '\0';
    }

    arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL)
    {
        fprintf(stderr,"Erro\n");
        return 1;
    }


    fprintf(arquivo, "%s", string);
    fclose(arquivo);


    arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL)
    {
        fprintf(stderr,"Erro\n");
        return 1;
    }


    if (fgets(valor_string, sizeof(valor_string), arquivo) == NULL)
    {
        fprintf(stderr, "Erro\n");
        fclose(arquivo);
        return 1;
    }
    fclose(arquivo);


    for (i = 0; valor_string[i] != '\0'; i++)
    {
        valor_string[i] = toupper(valor_string[i]);
    }


    printf("\nstring em letra maiúscula: %s\n", valor_string);

    return 0;
}
