#include <stdio.h> //biblioteca de comunica��o do usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	
	//In�cio da cria��o das vari�veis/strings
	char arquivo[40]; //Vari�vel arquivo, char pq s�o caracteres
	char cpf[40]; //Vari�vel cpf
	char nome[40]; //Vari�vel nome
	char sobrenome[40]; //Vari�vel sobrenome
	char cargo[40]; //Vari�vel cargo
	//final da cria��o de vari�veis
	
	printf("Digite o CPF a ser cadastrado: "); //Mensagem de in�cio
	scanf("%s", cpf); //Armanzenamento em string (%s)
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file,cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file,", "); //Coloca v�rgula no arquivo
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); 
	scanf("%s",nome); //Armazena na vari�vel nome
	
	file = fopen(arquivo, "a"); //Atualiza o arquivo
	fprintf(file,nome); //Escreve no arquivo
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Atualiza o arquivo
	fprintf(file,", "); //Coloca a v�rgula no arquivo
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome); //Armazena na vari�vel sobrenome
	
	file = fopen(arquivo, "a"); //Atualiza o arquivo
	fprintf(file,sobrenome); //Escreve no arquivo
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Atualiza o arquivo
	fprintf(file,", "); //Coloca v�rgula no arquivo
	fclose(file); //Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo); //Armazena na vari�vel cargo
	
	file = fopen(arquivo, "a"); //Atualiza o arquivo
	fprintf(file,cargo); //Escreve no arquivo
	fclose(file); //Fecha o arquivo
	
    system("pause"); //Pausa no sistema

}

int consulta ()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40]; //Vari�vel cpf
	char conteudo[100]; //Vari�vel conte�do
	
	printf("Digite o n�mero do CPF: ");
	scanf("%s",cpf); //Armazena na vari�vel cpf (%s pq � uma string)
  	
	FILE *file; //Linka o arquivo
	file = fopen(cpf,"r"); //L� o arquivo
  	
	if(file == NULL) //Se o arquivo for nulo
	{
		printf("Usu�rio n�o encontrado!\n");
	}
	
	while(fgets(conteudo, 100, file) != NULL) //Enquanto busca no arquivo, na vari�vel at� 200 valores que est�o dentro do arquivo. Diferente de nulo
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
  	
	system ("pause"); //Pausa no sistema
}

int deletar ()
{
	char cpf [40]; //Vari�vel cpf
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf); //Armazena na string
	
	remove(cpf); //Remove o arquivo do banco de dados
	
	FILE *file; //Seleciona o arquivo
	file = fopen(cpf,"r"); //L� o arquivo
	
	if(file == NULL) //Se o arquivo for nulo (n�o existir)
	{
		printf("Usu�rio n�o encontrado!\n"); 
		system("pause"); //Pausa no sistema
	}
		
}


int main () 
{
	int opcao=0; //definindo vari�veis
	int laco=1; //definindo vari�vel para la�o de repeti��o
	char senhadigitada[10]="a"; //Definindo vari�vel para comprova��o da senha
	int comparacao; //Vari�vel de comprova��o da senha
	
	printf("### Cart�rio do EBAC ###\n\n");
	printf("Login de Administrador\n\nDigite sua senha: ");
	scanf("%s",senhadigitada); //Local de armazenamento da string
	
	comparacao = strcmp(senhadigitada, "admin"); //Fun��o para defini��o da senha
	
	if(comparacao == 0) //A senha admin � armazenada como 0 na string, por isso a compara��o deve ser com 0
	{
		
		system("cls"); //Limpar o programa ap�s escolha do usu�rio
		for(laco=1;laco=1;) //La�o de repeti��o
		{
			setlocale(LC_ALL, "Portuguese"); //definindo o idioma
	
			printf("### Cart�rio EBAC ###\n\n"); //Texto principal
			printf("Escolha a op��o desejada do menu\n\n"); //Texto com as op��es do usu�rio
			printf("\t1 - Registrar nomes\n"); //Primeira op��o
			printf("\t2 - Consultar nomes\n"); //Segunda op��o
			printf("\t3 - Deletar nomes\n"); //Terceira op��o
			printf("\t4 - Sair do sistema\n\n"); //Quarta op��o
			printf("Op��o desejada: "); //Fim do menu
	
			scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
			system("cls"); //Limpar o programa ap�s escolha do usu�rio
		
			switch(opcao) //Substitui��o de IF
			{
				case 1:
				registro(); //Chamada de fun��es
				break; //fim do case
			
				case 2:
				consulta(); //Chamada de fun��es
				break; //fim do case
			
				case 3:
				deletar(); //Chamada de fun��es
				break; //fim do case
			
				case 4:
				printf("Obrigado por utilizar o sistema!\n"); //Mensagem amostra para o usu�rio
				return 0; //Fechar o programa
				break; //Fim do case
			
			
				default:
				printf("Essa op��o n�o est� dispon�vel!\n\n"); //Texto que aparece para o usu�rio
				system("pause"); //Pausa 
				break; //fim do default
			
			}
	
		}
	}
	
	else
		printf("\n\tSenha incorreta!");
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
