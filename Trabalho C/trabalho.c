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
        printf("Escolha uma das opção abaixo:\n");
        printf("\n1-Cadastrar livros");
        printf("\n2-Mostrar livros");
        printf("\n3-Consultar livros por título");
        printf("\n4-Registar vendas");
        printf("\n5-Consultar venda por título do livro");
        printf("\n6-Consultar venda por data");
        printf("\n7-Mostrar vendas");
        printf("\n8-Exportar todos os dados de Livros e de Vendas para um arquivo txt");
        printf("\n9-Importar os dados de Livros e Vendas de um arquivo txt");
        printf("\n10-Encerrar o programa");
        printf("\n\n>");
        scanf("%i",&opcoes);

        switch(opcoes)
        {

        case 1:

            printf("\n----------Função iniciada----------\n");

            cadastraLivros(acervo);

            printf("\n----------Função encerrada----------\n\n");

            break;

        case 2:

            printf("\n----------Função iniciada----------\n");

            exibeLivros(acervo);

            printf("\n----------Função encerrada----------\n\n");

            break;

        case 3:

            printf("\n----------Função iniciada----------\n");

            consultaPorTitulo(acervo);

            printf("\n----------Função encerrada----------\n\n");

            break;

        case 4:
            printf("\n----------Função iniciada----------\n");

            cadastraVendas(vendas, acervo);

            printf("\n----------Função encerrada----------\n\n");

            break;

        case 5:
            printf("Chamada de função5");
            break;

        case 6:
            printf("Chamada de função6");
            break;

        case 7:
            printf("Chamada de função7");
            break;

        case 8:

            printf("\n----------Função iniciada----------\n");

            exportaLivros(acervo);

            printf("\n----------Função encerrada----------\n\n");


            break;

        case 9:
            printf("Chamada de função9");
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
            printf("\nInválido! \nTente novamente\n\n");
        }
    }
    while(opcoes !=10);
}

void iniciaLivros(LIVRO **ptr)//seta os endereços que serão usados como null
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

        printf("\nDigite o código do livro: ");
        scanf("%i", &ptr[i]->codigo);

        printf("Digite o título do livro: ");
        scanf("%s", ptr[i]->titulo);

        printf("Digite o preço do livro: ");
        scanf("%f", &ptr[i]->preco);

        // printf("\n");
    }
}

void cadastraVendas(VENDA **ptr2, LIVRO **ptr) //Etapa 4
{
    int i=0, j=0;
    float total=0;

    for(i=0; i<pos_vd; i++)
    {
        if(ptr2[i]==NULL)

            ptr2[i] =(VENDA*)malloc(sizeof(VENDA));

        printf("%i\n",i);

        printf("Digite o código da venda: ");
        scanf("%i", &ptr2[i]->codVenda);

        printf("Digite o código do livro: ");
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
                printf("Código de livro informado não existe.");
            }
        }

    }

}

void exibeLivros(LIVRO **ptr) //Etapa 2
{
    int i;

    for(i=0; i<pos_lv; i++)
    {
        printf("\nCódigo: %i - Título: %s - Preço: %.2f", ptr[i]->codigo, ptr[i]->titulo, ptr[i]->preco);
    }

    printf("\n");
}

void exibeVendas(VENDA **ptr2) //Etapa 7
{
    int i;

    for(i=0; i<pos_vd; i++)
    {
        printf("\nCódigo: %i - Código livro: %i - Data: %s - Quantidade: %i - Valor total: %.2f\n", ptr2[i]->codVenda, ptr2[i]->codLivro, ptr2[i]->data, ptr2[i]->qtd, ptr2[i]->valorTotal);
    }

    printf("\n");
}

void consultaPorTitulo(LIVRO **ptr) //Etapa 3
{
    char tituloConsulta[100];
    int i=0;
    printf("Digite o título:");
    scanf("%s", &tituloConsulta);

    for(i=0; i<pos_lv; i++)
    {
        if(strcmp(tituloConsulta,ptr[i]->titulo)==0)
        {
            printf("\nResultado da pesquisa por \"%s\": ", tituloConsulta);

            printf("\n\nCódigo: %i - Título: %s - Preço: %.2f\n", ptr[i]->codigo, ptr[i]->titulo, ptr[i]->preco);
        }
    }
}

void exportaLivros(LIVRO **ptr) //Etapa 8.1
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

void exportaVendas(VENDA **ptr2) //Etapa 8.2
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
        fprintf(pont_arq,"Código: %i - Código livro: %i - Data: %s - Quantidade: %i - Valor total: %.2f\n", ptr2[i]->codVenda, ptr2[i]->codLivro, ptr2[i]->data, ptr2[i]->qtd, ptr2[i]->valorTotal);
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
