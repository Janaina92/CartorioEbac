#include  <stdio.h>  //biblioteca de comunica��o com o usu�rio
#include  <stdlib.h>  //biblioteca de aloca��o de espa�o em mem�ria
#include  <locale.h>  //biblioteca de aloca��es de texto por regi�o
#include  <string.h>  //biblioteca respons�vel por cuidar das strings

int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores das strings
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo, "w"); // cria o arquivo e o w significa escrever
	fprintf(file,cpf); // salvo o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o a significa atualizar
	fprintf(file,","); // salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo e o a significa atualizar
	fprintf(file,nome); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o a significa atualizar
	fprintf(file,","); //salvo o valor da vari�vel e da ,
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s",sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo e o a sigifica atualizar
	fprintf(file, sobrenome); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o a significa atualizar
	fprintf(file,","); //salvo o valor da vari�vel e da ,
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s",cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo e o a significa atualizar
	fprintf(file, cargo); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");//Definindo a Linguagem
	
	//inicio cria��o de vari�vei/string
	char cpf[40];
	char conteudo[200];
	//fim da cria��o das vari�veis/string
	
	printf("Digite o CPF a ser consultado: "); //coletando informa��o do usu�rio
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //cria o arquivo e o r significa ler
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}

	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}

	system("pause");
	
}

int deletar()
{
	
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: "); //coletando informa��es do usu�rio
	scanf("%s",cpf); //%s refere-se a string
	
	remove(cpf);
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //cria o arquivo e o r significa ler
	
	if (file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
		
	}

}



int main()
{
	int opcao=0;//Definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
	
		setlocale(LC_ALL, "Portuguese");//Definindo a Linguagem
	
		printf("### Cart�rio da EBAC ###\n\n");//inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Op��o: ");//fim do menu
	
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
			printf("Essa opcao n�o est� dispon�vel!\n");
			system("pause");
			break;	
				
		} //fim da sele��o
		
    }
}
