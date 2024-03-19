#include <stdio.h>  //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //bibliotrca de aloca��o de espa�o de mem�ria 
#include <locale.h> //biblioteca de aloca��o de texto por regi�o e acentua��o de acordo com a localidade
#include <string.h> //biblioteca responsavel por coidar das strings

int registro()//fun��o respon�vel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string

	strcpy(arquivo, cpf); //responsavel por copiar valores das string
	
	FILE *file; //cria um arquivo no banco de dados
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa write, escrever
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a"); //acrescenta o arquivo
	fprintf(file,","); //salvo o valor da variavel
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",nome); //%s refere-se a string
	
	file = fopen(arquivo, "a");//acrescenta o arquivo
	fprintf(file,nome); //salvo o valor da variavel
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,","); //salvo o valor da variavel
	fclose(file); //fecho o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a");//acrescenta o arquivo
	fprintf(file,sobrenome); //salvo o valor da variavel
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a");//acrescenta o arquivo
	fprintf(file,","); //salvo o valor da variavel
	fclose(file); //fecho o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a");//acrescenta o arquivo
	fprintf(file,cargo); //salvo o valor da variavel
	fclose(file); //fecho o arquivo
	
	system("pause");

}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //coletando informa��o do usu�rio
	scanf("%s",cpf);
	
	FILE *file; //cria um arquivo no banco de dados
	file = fopen(cpf,"r"); //le o arquivo
	
	if(file == NULL)
	{
		printf("\nN�o foi possivel abrir o arquivo, n�o localizado!\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: "); //coletando informa��o do usu�rio
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file; //cria um arquivo no banco de dados
	file = fopen(cpf,"r"); //le o arquivo
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema! \n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //Definindo as vari�veis
	int laco=1; //laco � igual a x
	
	for(laco=1;laco=1;)
	{

		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a op��o desejado do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Op��o: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
		system("cls"); //responsavel por limpar a tela
		
		switch(opcao) //inicio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��es
			break;
		
			case 2:
			consulta(); //chamada de fun��es
			break;
			
			case 3:
			deletar(); //chamada de fun��es
			break;
			
			default:
			printf("Essa op��o n�o esta dispon�vel\n");
			system("pause");
			break;
		} //fim da sele��o do menu
 
	}
}
