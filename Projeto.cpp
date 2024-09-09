#include <stdio.h> // Biblioteca de comunicação com o usuario
#include <stdlib.h> // Biblioteca de alocação de espaço em memória
#include <locale.h> // Biblioteca de alocação de texto por região
#include <string.h> //Biblioteca responsavel por cuidar das string


int registro()//Função para registro de nomes
{
   //inicío da criação de varíaveis/strings
   char arquivo[40];
   char cpf[40];
   char nome[40];
   char sobrenome[40];
   char cargo[40];
   
   printf("Você escolheu registro de nomes\n\n\n\n");
   
   printf("Digite o cpf a ser cadastrado: ");
   scanf("%s" , cpf);
   
   strcpy(arquivo, cpf);//Responsavel por copiar o valor das string
   
   FILE *file;//Cria o arquivo
   file = fopen(arquivo, "w");//Cria o arquivo
   fprintf(file, cpf);//Salva o valor da variavel
   fclose(file);// fecha o arquivo
   
   file = fopen(arquivo, "a");
   fprintf(file,",");
   fclose(file);
   
   printf("Digite o nome a ser cadastrado: ");
   scanf("%s" , nome);
   file = fopen(arquivo, "a");
   fprintf(file,nome);
   fclose(file);
   
   file = fopen(arquivo, "a");
   fprintf(file,",");
   fclose(file);
   
   printf("Digite o sobrenome a ser cadastrado: ");
   scanf("%s" , sobrenome);
   file = fopen(arquivo, "a");
   fprintf(file,sobrenome);
   fclose(file);
   
   file = fopen(arquivo, "a");
   fprintf(file,",");
   fclose(file);
   
   printf("Digite o cargo a ser cadastrado: ");
   scanf("%s" , cargo);
   file = fopen(arquivo, "a");
   fprintf(file,cargo);
   fclose(file);
   
   system("pause");
   
}

int consulta()//Função para consulta de nomes
{ 
    setlocale(LC_ALL, "Portuguese");//Defindo a linguagem
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o cpf que deseja consultar\n");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if(file == NULL)
    {
    	printf("Não foi possivel abrir o arquivo, não foi localizado!.\n");
    	
	}
    
     while(fgets(conteudo, 200, file) != NULL)
     {
     	printf("Essas são as informações do usuário: ");
     	printf("%s", conteudo);
     	printf("\n\n");
	 }
	 
        system("pause");
     
	}
	
int deletar()//Função para deletar nomes
{
	char cpf[40];
	printf("Digite o cpf do usuário que deseja deletar: ");
	scanf("%S", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!\n");
		system("pause");
	}
	
}



int main()//Função principal
{
	int opcao=0; // Definindo variaveis
	int laco=1;
	for(laco=1;laco=1;)
	{
		system("cls");
		
	setlocale(LC_ALL, "Portuguese");//Defindo a linguagem
	
	
	printf("\t Cartório da EBAC \n\n");//inicio do menu
	printf("Escolha a opção desejada do menu abaixo:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n\n"); 
	printf("Opção: ");//Final do menu
	
	scanf("%d" , &opcao);// Armezenando a escolha do usuario
	
	system("cls");
	
	switch(opcao)
	{//inicio da seleção
		case 1:
			registro();
		    break;
		    
	    case 2:
	    	consulta();
		    break;
		    
		case 3:  
		    deletar();
			break; 
			
		default:
		    printf("Esta opção não esta disponivel\n");
		    system("pause");
		    break;
		    //final da seleção
	}
	
   }
}
