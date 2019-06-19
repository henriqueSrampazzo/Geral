#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define pos_lv 1
#define pos_vd 1

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

void mostraMenu()//menu principal
{
    int opcoes=0;

    LIVRO *acervo[pos_lv];
    VENDA *vendas[pos_vd];

    iniciaLivros(acervo);
    iniciaVendas(vendas);

    do
    {
        printf("Escolha uma das op��o abaixo:\n");
        printf("\n1-Cadastrar livros com os dados c�digo, t�tulo e pre�o");
        printf("\n2-Mostrar todos os dados de todos os livros cadastrados");
        printf("\n3-Consultar todos os dados de livros pelo t�tulo");
        printf("\n4-Registar cada venda com os seguintes dados: c�digo da venda, c�digo do livro, quantidade de livros, data da venda e o valor total da venda");
        printf("\n5-Consultar todos os dados de uma determinada venda por t�tulo do livro");
        printf("\n6-Consultar todos os dados de uma determinada venda por per�odo, informando o valor total recebido");
        printf("\n7-Mostrar todos os dados de todas as vendas realizadas");
        printf("\n8-Exportar todos os dados de Livros e de Vendas para um arquivo txt");
        printf("\n9-Importar os dados de Livros (c�digo, t�tulo e pre�o) de um arquivo txt");
        printf("\n10-Encerrar o programa");
        printf("\n\n>");
        scanf("%i",&opcoes);

        switch(opcoes)
        {

        case 1:

            printf("\n----------Fun��o iniciada----------\n");

            cadastraLivros(acervo);

            printf("\n----------Fun��o encerrada----------\n\n");

            break;

        case 2:

            printf("\n----------Fun��o iniciada----------\n");

            exibeLivros(acervo);

            printf("\n----------Fun��o encerrada----------\n\n");

            break;

        case 3:

            printf("\n----------Fun��o iniciada----------\n");

            consultaPorTitulo(acervo);

            printf("\n----------Fun��o encerrada----------\n\n");

            break;

        case 4:
            printf("\n----------Fun��o iniciada----------\n");

            cadastraVendas(vendas, acervo);

            printf("\n----------Fun��o encerrada----------\n\n");

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

            printf("\n----------Fun��o iniciada----------\n");

            exportaLivros(acervo);

            printf("\n----------Fun��o encerrada----------\n\n");


            break;

        case 9:
            printf("Chamada de fun��o9");
            break;

        case 10:
            printf("Programa encerrado");
        }

        if(opcoes==10)
        {
            exit(0);
        }

        if(opcoes>10)
        {
            printf("\nInv�lido! \nTente novamente\n\n");
        }
    }
    while(opcoes !=10);
}

void iniciaLivros(LIVRO **ptr)//seta os endere�os que ser�o usados como null
{
    int i=0;

    for(i=0; i<pos_lv; i++)
    {
        ptr[i]=NULL;
    }
}

void iniciaVendas(VENDA **ptr2)
{
    int i=0;

    for(i=0; i<pos_vd; i++)
    {
        ptr2[i]=NULL;
    }
}

void cadastraLivros(LIVRO **ptr) //Etapa 1
{
    int i=0;

    for(i=0; i<pos_lv; i++)
    {
        if(ptr[i]==NULL)

            ptr[i] =(LIVRO*)malloc(sizeof(LIVRO));

        printf("\nDigite o c�digo do livro: ");
        scanf("%i", &ptr[i]->codigo);

        printf("Digite o t�tulo do livro: ");
        scanf("%s", ptr[i]->titulo);

        printf("Digite o pre�o do livro: ");
        scanf("%f", &ptr[i]->preco);

        // printf("\n");
    }
}

void cadastraVendas(VENDA **ptr2, LIVRO **ptr)
{
    int i=0, j=0;
    float total=0;

    for(i=0; i<pos_vd; i++)
    {
        if(ptr2[i]==NULL)

            ptr2[i] =(VENDA*)malloc(sizeof(VENDA));

        printf("%i\n",i);

        printf("Digite o c�digo da venda: ");
        scanf("%i", &ptr2[i]->codVenda);

        printf("Digite o c�digo do livro: ");
        scanf("%i", &ptr2[i]->codLivro);

        printf("Digite a data da venda: ");
        scanf("%s", &ptr2[i]->data);

        printf("Digite a quantidade: ");
        scanf("%i", &ptr2[i]->qtd);

        printf("\n\n");

        for(j=0; j<pos_lv; j++)
        {
            if(ptr2[i]->codLivro == ptr[j]->codigo)
            {
                ptr2[i]->valorTotal = ptr[j]->preco * ptr2[i]->qtd;
                printf("%f", ptr2[i]->valorTotal);
            }
            if(ptr2[i]->codLivro != ptr[j]->codigo)
            {
                printf("C�digo de livro informado n�o existe.");
            }
        }

    }

}

void exibeLivros(LIVRO **ptr)//Etapa 2
{
    int i;

    for(i=0; i<pos_lv; i++)
    {
        printf("\nC�digo: %i - T�tulo: %s - Pre�o: %.2f", ptr[i]->codigo, ptr[i]->titulo, ptr[i]->preco);
    }

    printf("\n");
}

void exibeVendas(VENDA **ptr2)//Etapa 2
{
    int i;

    for(i=0; i<pos_vd; i++)
    {
        printf("\nC�digo: %i - C�digo livro: %i - Data: %s - Quantidade: %i - Valor total: %.2f\n", ptr2[i]->codVenda, ptr2[i]->codLivro, ptr2[i]->data, ptr2[i]->qtd, ptr2[i]->valorTotal);
    }

    printf("\n");
}

void consultaPorTitulo(LIVRO **ptr)//Etapa 3
{
    char tituloConsulta[100];
    int i=0;
    printf("Digite o t�tulo:");
    scanf("%s", &tituloConsulta);

    for(i=0; i<pos_lv; i++)
    {
        if(strcmp(tituloConsulta,ptr[i]->titulo)==0)
        {
            printf("\nResultado da pesquisa por \"%s\": ", tituloConsulta);

            printf("\n\nC�digo: %i - T�tulo: %s - Pre�o: %.2f\n", ptr[i]->codigo, ptr[i]->titulo, ptr[i]->preco);
        }
    }
}

void exportaLivros(LIVRO **ptr)//Etapa 8.1
{
    int i=0;
    FILE *pont_arq;

    pont_arq = fopen("saidalivros.txt", "w");

    if(pont_arq == NULL)
    {
        printf("Erro na abertura do arquivo!");
    }

    for(i=0; i<pos_lv; i++)
    {
        fprintf(pont_arq,"%i\n", ptr[i]->codigo);
        fprintf(pont_arq,"%s\n", ptr[i]->titulo);
        fprintf(pont_arq,"%.2f\n", ptr[i]->preco);
    }
    fclose(pont_arq);

    printf("\n\nDados dos livros gravados com sucesso!\n");
}

void exportaVendas(VENDA **ptr2)
{
    int i=0;
    FILE *pont_arq;

    pont_arq = fopen("saidavendas.txt", "w");

    if(pont_arq == NULL)
    {
        printf("Erro na abertura do arquivo!");
    }

    for(i=0; i<pos_vd; i++)
    {
        fprintf(pont_arq,"C�digo: %i - C�digo livro: %i - Data: %s - Quantidade: %i - Valor total: %.2f\n", ptr2[i]->codVenda, ptr2[i]->codLivro, ptr2[i]->data, ptr2[i]->qtd, ptr2[i]->valorTotal);
    }
    fclose(pont_arq);

    printf("Vendas gravadas com sucesso!");
}

int main()
{
    setlocale(LC_ALL,"Portuguese");

    mostraMenu();

    return 0;
}
