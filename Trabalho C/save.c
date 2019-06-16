#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define pos_lv 10
#define pos_vd 10

typedef struct
{
    int codigo;
    char titulo[100];
    float preco;

} LIVRO;

typedef struct
{
    int codVenda;
    int codLivro;
    float data[11];
    int qtd;
    float valorTotal;

} VENDA;

void mostraMenu()
{
    int opcoes=0;

    do
    {
        printf("\nEscolha uma das op��o abaixo:");
        printf("\n\Cadastro");
        printf("\n2\n");
        printf("\n>");
        scanf("%i",&opcoes);

        switch(opcoes)
        {

        case 1:
            printf("Chamada de fun��o1");
            break;

        case 2:
            printf("Chamada de fun��o2");
            break;

        case 3:
            printf("Chamada de fun��o3");
            break;

        case 4:
            printf("Chamada de fun��o4");
            break;

        case 5:
            printf("Chamada de fun��o5");
            break;

        case 6:
            printf("Chamada de fun��o6");
            break;

        case 7:
            printf("Chamada de fun��o7");
            break;

        case 8:
            printf("Chamada de fun��o8");
            break;

        case 9:
            printf("Chamada de fun��o9");

        case 10:
            printf("Saindo...");
        }

        if(opcoes>10)
        {
            printf("\nInv�lido! \nTente novamente\n\n\n\n");
            system("cls");
        }
    }
    while(opcoes !=10);
}

void iniciaLivros(LIVRO **ptr)
{
    int i=0;

    for(i=0; i<10; i++)
    {

        ptr[i]=NULL;
    }
}


void cadastraLivros(LIVRO **ptr)
{
    int i=0;

    for(i=0; i<3; i++)
    {

        if(ptr[i]==NULL)
            ptr[i] =(LIVRO*)malloc(sizeof(LIVRO));

        printf("%i\n",i);

        printf("Digite o c�digo do livro: ");
        scanf("%i", &ptr[i]->codigo);

        printf("Digite o t�tulo do livro: ");
        scanf("%s", ptr[i]->titulo);

        printf("Digite o pre�o do livro: ");
        scanf("%f", &ptr[i]->preco);

        printf("\n\n");

        printf("\n\ncod: %i\n", ptr[i]->codigo);
        printf("\n\ntit: %s\n", ptr[i]->titulo);
        printf("\n\npre: %.2f\n", ptr[i]->preco);
    }
}

int main()
{
    setlocale(LC_ALL,"Portuguese");

    //mostraMenu();

    LIVRO *acervo[pos_lv];

    iniciaLivros(acervo);

    cadastraLivros(acervo);




    return 0;
}
