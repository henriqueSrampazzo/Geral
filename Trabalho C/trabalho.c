#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

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
        printf("\nEscolha uma das opção abaixo:");
        printf("\n\Cadastro");
        printf("\n2\n");
        printf("\n>");
        scanf("%i",&opcoes);

        switch(opcoes)
        {

        case 1:
            printf("Chamada de função1");
            break;

        case 2:
            printf("Chamada de função2");
            break;

        case 3:
            printf("Chamada de função3");
            break;

        case 4:
            printf("Chamada de função4");
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
            printf("Chamada de função8");
            break;

        case 9:
            printf("Chamada de função9");

        case 10:
            printf("Saindo...");
        }

        if(opcoes>10)
        {
            printf("\nInválido! \nTente novamente\n\n\n\n");
            system("cls");
        }
    }
    while(opcoes !=10);
}

void iniciaLivros(LIVRO **ptr)
{
    int i=0;

    for(i=0; i<pos_lv; i++)
    {
        ptr[i]=NULL;
    }
}

void cadastraLivros(LIVRO **ptr, int qtd)
{
    int i=0;

    for(i=0; i<qtd; i++)
    {
        if(ptr[i]==NULL)

            ptr[i] =(LIVRO*)malloc(sizeof(LIVRO));

        printf("%i\n",i);

        printf("Digite o código do livro: ");
        scanf("%i", &ptr[i]->codigo);

        printf("Digite o título do livro: ");
        scanf("%s", ptr[i]->titulo);

        printf("Digite o preço do livro: ");
        scanf("%f", &ptr[i]->preco);

        printf("\n\n");
    }

            for(i=0; i<qtd; i++)
    {
        printf("\n\ncod: %i\n", ptr[i]->codigo);
        printf("\n\ntit: %s\n", ptr[i]->titulo);
        printf("\n\npre: %.2f\n", ptr[i]->preco);
        
    }

}

void consultaPorTitulo(LIVRO **ptr, int qtd){
	char tituloConsulta[100];
	int i=0;
	printf("Digite o título:");
	scanf("%s", &tituloConsulta);
	
	for(i=0;i<qtd;i++){
	if(strcmp(tituloConsulta,ptr[0]->titulo)==0){
	printf("Resultado da pesquisa por \"%s\": ", tituloConsulta);
	printf("\n\ncod: %i\n", ptr[0]->codigo);
    printf("\n\ntit: %s\n", ptr[0]->titulo);
    printf("\n\npre: %.2f\n", ptr[0]->preco);
    }
}
}

void exportaLivros(LIVRO **ptr, int qtd){
  int i=0;
  FILE *pont_arq;
  
  pont_arq = fopen("saidalivros.txt", "w");
  
  if(pont_arq == NULL)
  {
  printf("Erro na abertura do arquivo!");
  }

for(i=0;i<qtd;i++){
  fprintf(pont_arq,"%i\n", ptr[i]->codigo);
  fprintf(pont_arq,"%s\n", ptr[i]->titulo);
  fprintf(pont_arq,"%.2f\n", ptr[i]->preco);
}
  fclose(pont_arq);
  
  printf("Dados gravados com sucesso!");
}

int main()
{
    setlocale(LC_ALL,"Portuguese");

	int qtd=2;
    //mostraMenu();

    LIVRO *acervo[pos_lv];

    iniciaLivros(acervo);

    cadastraLivros(acervo, qtd);
    
    //consultaPorTitulo(acervo);
    
    exportaLivros(acervo,qtd);

    return 0;
}
