#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define pos_lv 2
#define pos_vd 2

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
    char data[11];
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
        printf("Escolha uma das op��es abaixo:\n");
        printf("\n1-Cadastrar livros");
        printf("\n2-Mostrar livros");
        printf("\n3-Consultar livros por t�tulo");
        printf("\n4-Registar vendas");
        printf("\n5-Consultar venda por t�tulo do livro");
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

            printf("\n----------Fun��o iniciada----------\n");

            cadastraLivros(acervo);

            printf("\n----------Fun��o encerrada----------\n\n");

            break;

        case 2:

            printf("\n----------Fun��o iniciada----------\n");

            exibeLivros(acervo);

            printf("\n\n----------Fun��o encerrada----------\n\n");

            break;

        case 3:

            printf("\n----------Fun��o iniciada----------\n");

            consultaPorTituloLivros(acervo);

            printf("\n----------Fun��o encerrada----------\n\n");

            break;

        case 4:

            printf("\n----------Fun��o iniciada----------\n");

            cadastraVendas(vendas, acervo);

            printf("\n----------Fun��o encerrada----------\n\n");

            break;

        case 5:

            printf("\n----------Fun��o iniciada----------\n");

            consultaPorTituloVendas(vendas, acervo);

            printf("\n----------Fun��o encerrada----------\n\n");

            break;

        case 6:

            printf("\n----------Fun��o iniciada----------\n");

            consultaPorDataVendas(vendas);

            printf("\n----------Fun��o encerrada----------\n\n");

            break;

        case 7:

            printf("\n----------Fun��o iniciada----------\n\n");

            exibeVendas(vendas, acervo);

            printf("\n----------Fun��o encerrada----------\n\n");

            break;

        case 8:

            printf("\n----------Fun��o iniciada----------\n");

            exportaLivros(acervo);

            exportaVendas(vendas);

            printf("\n----------Fun��o encerrada----------\n\n");


            break;

        case 9:

            printf("\n----------Fun��o iniciada----------\n");

			importaLivros(acervo);

            printf("\n----------Fun��o encerrada----------\n\n");

            break;

        case 10:
            printf("\nPrograma encerrado\n");
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

void iniciaLivros(LIVRO **ptr)//seta os endere�os que ser�o usados como null para os livros
{
    int i=0;

    for(i=0; i<pos_lv; i++)
    {
        ptr[i]=NULL;
    }
}

void iniciaVendas(VENDA **ptr2)//seta os endere�os que ser�o usados como null para as vendas
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
    }
}

void exibeLivros(LIVRO **ptr) //Etapa 2
{
    int i;

    for(i=0; i<pos_lv; i++)
    {
        printf("\nC�digo: %i - T�tulo: %s - Pre�o: %.2f", ptr[i]->codigo, ptr[i]->titulo, ptr[i]->preco);
    }
}

void consultaPorTituloLivros(LIVRO **ptr) //Etapa 3
{
    char tituloConsulta[100];
    int i=0;

    printf("\nDigite o t�tulo:");
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

void cadastraVendas(VENDA **ptr2, LIVRO **ptr)//etapa 4
{
    int i=0, j=0, codAux=0;     

    for(i=0; i<pos_vd; i++)
    {
        if(ptr2[i]==NULL)

        ptr2[i] =(VENDA*)malloc(sizeof(VENDA));

        printf("\nDigite o c�digo da venda: ");
        scanf("%i", &ptr2[i]->codVenda);

        printf("Digite o c�digo do livro: ");
		scanf("%i", &ptr2[i]->codLivro); 

        printf("Digite a data da venda: ");
        scanf("%s", &ptr2[i]->data);

        printf("Digite a quantidade: ");
        scanf("%i", &ptr2[i]->qtd);

        ptr2[i]->valorTotal = ptr[j]->preco * ptr2[i]->qtd;
        printf("%f", ptr2[i]->valorTotal);
    }
}

void exibeVendas(VENDA **ptr2) //Etapa 5
{
    int i;

    for(i=0; i<pos_lv; i++)
    {
        printf("C�digo: %i - C�digo livro: %i - Data: %s - Quantidade: %i - Valor total: %.2f\n", ptr2[i]->codVenda, ptr2[i]->codLivro, ptr2[i]->data, ptr2[i]->qtd, ptr2[i]->valorTotal);
    }
}

void consultaPorTituloVendas(VENDA **ptr2, LIVRO **ptr) //Etapa 6
{
    char tituloConsulta[100];
    int i=0;

    printf("\nDigite o t�tulo:");
    scanf("%s", &tituloConsulta);

    for(i=0; i<pos_vd; i++)
    {
        if(strcmp(tituloConsulta,ptr[i]->titulo)==0)
        {
            printf("\nResultado da pesquisa por \"%s\": ", tituloConsulta);

            printf("\n\nC�digo: %i - C�digo livro: %i - Data: %s - Quantidade: %i - Valor total: %.2f\n", ptr2[i]->codVenda, ptr2[i]->codLivro, ptr2[i]->data, ptr2[i]->qtd, ptr2[i]->valorTotal);
        }
    }
}

void consultaPorDataVendas(VENDA **ptr2) //Etapa 7
{
    char dataConsulta[100];
    int i=0;

    printf("\nDigite a data da venda:");
    scanf("%s", &dataConsulta);

    for(i=0; i<pos_vd; i++)
    {
        if(strcmp(dataConsulta,ptr2[i]->data)==0)
        {
            printf("\nResultado da pesquisa por \"%s\": ", dataConsulta);

            printf("\n\nC�digo: %i - C�digo livro: %i - Data: %s - Quantidade: %i - Valor total: %.2f\n", ptr2[i]->codVenda, ptr2[i]->codLivro, ptr2[i]->data, ptr2[i]->qtd, ptr2[i]->valorTotal);
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
        fprintf(pont_arq,"C�digo: %i - T�tulo: %s - Pre�o: %.2f\n", ptr[i]->codigo, ptr[i]->titulo, ptr[i]->preco);
    }
    fclose(pont_arq);

    printf("\nDados dos livros gravados com sucesso!\n");
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
        fprintf(pont_arq,"C�digo: %i - C�digo livro: %i - Data: %s - Quantidade: %i - Valor total: %.2f\n", ptr2[i]->codVenda, ptr2[i]->codLivro, ptr2[i]->data, ptr2[i]->qtd, ptr2[i]->valorTotal);
    }
    fclose(pont_arq);

    printf("\nDados das vendas gravados com sucesso!\n");
}

void importaLivros(LIVRO **ptr){
	FILE *pont_arq;
	char c, linha[100];
	int i=0, j=0;
	   pont_arq = fopen("saidalivros.txt","r");       
  // while (!feof(pont_arq))
  //  {
      // fscanf(pont_arq,"%c",&c);
      // printf("%c",c);
       
       for (i=0; i<9; i++){
   
   fgets(linha, sizeof(linha), pont_arq);
   printf("%s",linha);

}
   // } 
   fclose(pont_arq);
	
}

int main()
{
    setlocale(LC_ALL,"Portuguese");

    mostraMenu();

    return 0;
}
