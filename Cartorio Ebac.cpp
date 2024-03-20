#include <stdio.h>  //biblioteca de comunicação com o usuário
#include <stdlib.h> //bibliotrca de alocação de espaço de memória 
#include <locale.h> //biblioteca de alocação de texto por região e acentuação de acordo com a localidade
#include <string.h> //biblioteca responsavel por coidar das strings

int registro()//função responável por cadastrar os usuários no sistema
{
	//inicio da criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string

	strcpy(arquivo, cpf); //responsavel por copiar valores das string
	
	FILE *file; //cria um arquivo no banco de dados
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa write, escrever
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a"); //acrescenta o arquivo
	fprintf(file,","); //salvo o valor da variavel
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",nome); //%s refere-se a string
	
	file = fopen(arquivo, "a");//acrescenta o arquivo
	fprintf(file,nome); //salvo o valor da variavel
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,","); //salvo o valor da variavel
	fclose(file); //fecho o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a");//acrescenta o arquivo
	fprintf(file,sobrenome); //salvo o valor da variavel
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a");//acrescenta o arquivo
	fprintf(file,","); //salvo o valor da variavel
	fclose(file); //fecho o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informação do usuário
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
	
	printf("Digite o CPF a ser consultado: "); //coletando informação do usuário
	scanf("%s",cpf);
	
	FILE *file; //cria um arquivo no banco de dados
	file = fopen(cpf,"r"); //le o arquivo
	
	if(file == NULL)
	{
		printf("\nNão foi possivel abrir o arquivo, não localizado!\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: "); //coletando informação do usuário
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file; //cria um arquivo no banco de dados
	file = fopen(cpf,"r"); //le o arquivo
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema! \n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //Definindo as variáveis
	int laco=1; //laco é igual a x
	char senhadigitada[]="a";
	int comparacao;
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		system ("cls");
		for(laco=1;laco=1;)
		{
	
			system("cls");
			
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
			printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
			printf("Escolha a opção desejado do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n");
			printf("\t4 - Sair do programa\n\n");
			printf("Opção: "); //fim do menu
	
			scanf("%d", &opcao); //armazenando a escolha do usuário
	
			system("cls"); //responsavel por limpar a tela
		
			switch(opcao) //inicio da seleção do menu
			{
				case 1:
				registro(); //chamada de funções
				break;
		
				case 2:
				consulta(); //chamada de funções
				break;
			
				case 3:
				deletar(); //chamada de funções
				break;
				
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
			
				default:
				printf("Essa opção não esta disponível\n");
				system("pause");
				break;
			} //fim da seleção do menu
		}
	}
	
	else
		printf("Senha incorreta!");
		
}
