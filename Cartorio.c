#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocação de texto por região
#include <string.h> //Bibliteca responsável por cuidar das string

int registro()//Função responsavel por cadastrar os usuários no sistema
{
	//Inicío criação de varíaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final criação de varíaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s",cpf); //%s se refere-se a string
	
	strcpy(arquivo,cpf); //Responsavel por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo,"w"); //Cria o arquivo e W é de escrever
	fprintf(file,cpf); //Salvo o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo,"a"); //Cria o arquivo e A é de atualizar
	fprintf(file,","); //Salvo o valor da variavel
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file); 
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause"); //Pausa o sistema para exibir mensagens
}


int consulta() //Função para consultar usuários cadastrados
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem

	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // Abre o arquivo para leitura e R é de read
	
	if(file == NULL) // Verifica se o arquivo foi aberto com sucesso
	{
		printf("Não foi possível abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // Lê o conteúdo do arquivo
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
		
	system("pause");

	
}

int deletar() // Função para deletar usuários cadastrados
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf); // Remove o arquivo com o CPF
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file ==  NULL); // Verifica se o arquivo foi removido com sucesso
	{
		printf("Usúario deletado com sucesso!.\n");
		printf("Usúario não se encontra no sistema!.\n");
		system("pause");
		
	}
	
}


int main()  // Função principal do programa
 {
    int opcao=0; //Definindo variáveis
    int laco=1;
    
    for(laco=1;laco=1;)
    {
	
		system("cls"); //Responsavel por limpar a tela
	
	setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	
		printf("### Cartório da Ebac ###\n\n"); //Início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); //Fim do menu
	
		scanf("%d", &opcao); //Armezenando a escolha do usuário
	
		system("cls");
		
		
	switch(opcao) //Inicio da seleção do menu
	{
	    	case 1:
			registro(); //Chamada de funções
			break;
			
			case 2: 
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponivel!\n");
			system("pause"); // Pausa o sistema para exibir mensagens
			break;
		
		}

	
	}
}

