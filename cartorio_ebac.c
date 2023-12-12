#include <stdio.h>  //biblioteca de comunicação com o usuário.
#include <stdlib.h>  //biblioteca de alocação de espaço em memória.
#include <locale.h>  //biblioteca de alocaçôes de texto por região.
#include <string.h>  //biblioteca de organização de strings.

int registro(){
	setlocale (LC_ALL, "Portuguese");
	  // Inicio da criação de variáveis/strings.
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	int opcao = 0;
		//variável para criação de um novo arquivo.
	int registrar(){ 
			FILE *file;  //Cria um arquivo
			file = fopen(arquivo, "w");  //fopen abre o arquivo. "w" serve para criar um novo arquivo.
			fprintf(file, "CPF: ");  //salva o arquivo.
			fclose(file);  //fecha o arquivo.
			
			file = fopen(arquivo, "a"); //"a" serve para editar um arquivo ja existente.
			fprintf(file, cpf); 
			fclose(file);
			
			file = fopen(arquivo, "a");
			fprintf(file, "\n");
			fclose(file);
			  //aqui acaba o criação de um arquivo novo e o registro do cpf.
			
			  //NOME
			file = fopen(arquivo, "a");
			fprintf(file, "NOME:");
			fclose(file);
			
			printf("digite o Nome a ser cadastrado: ");
			scanf("%s", nome);
		
			file = fopen(arquivo, "a"); 
			fprintf(file, nome);
			fclose(file);
			
			file = fopen(arquivo, "a");
			fprintf(file, "\n");
			fclose(file);
			  //registro do nome encerrado.
			
			  //SOBRENOME
			file = fopen(arquivo, "a");
			fprintf(file, "SOBRENOME: ");
			fclose(file);
			
			printf("digite o Sobrenome a ser cadastrado: ");
			scanf("%s", sobrenome);
		
			file = fopen(arquivo, "a");
			fprintf(file, sobrenome);
			fclose(file);
			
			file = fopen(arquivo, "a");
			fprintf(file, "\n");
			fclose(file);
			  //registro do sobrenome encerrado.
			
			  //CARGO
			file = fopen(arquivo, "a");
			fprintf(file, "CARGO: ");
			fclose(file);
			
			printf("digite o Cargo a ser cadastrado: ");
			scanf("%s", cargo);
		
			file = fopen(arquivo, "a");
			fprintf(file, cargo);
			fclose(file);
			
			file = fopen(arquivo, "a");
			fprintf(file, "\n");
			fclose(file);
			  //registro do cargo encerrado.
			system("cls");
			}	
	  // Fim da criação de variáveis.
	  
	  //Criação de arquivo e novo registro do cpf.
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);  //Copia os valores das strings. Como se fosse (aqruivo = cpf).
	
	system("cls");
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL){  
		registrar();
		
		system("cls");
		printf("Usuario registrado!\n\n");
		system("pause");
	}else{		//opção de ediçao de um usuário já encontrado.
		printf("Esse arquivo ja existe!\n\n");
		printf("Deseja edita-lo?\n\t1 - Sim!\n\t2 - Não!");
		printf("opção: ");
		scanf("%d",&opcao);
		
		system("cls");
		
		switch(opcao){
			case 1:
				printf("Editando arquivo do usuário: ");
				printf(cpf);
				printf("\n\n");
				registrar();
				
				system("cls");
				printf("Usuario editado!\n\n");
				system("pause");
			break;
			
			case 2:
				printf("Cancelando registro...\n\n");
				system("pause");
			break;
			
			default:
				printf("Opcao Invalida\n\n");
				system("pause");	
			break;	
		}	
	}
	fclose(file);	
}

int consulta(){
	setlocale (LC_ALL, "Portuguese");
	  
	  //Criação de variáveis/strings.
	char cpf[40];
	char conteudo[300];
	  //fim da criação de variáveis.
	  
	  //consulta dos arquivos.
	printf("Digite o cpf que deseja consultar: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");  //"r" de read, ou seja, ele vai ler o arquivo.	
	system("cls");
	
	if(file == NULL){
		printf("Arquivo não localizado.\n\n");
		system("pause");
	}else{
	system("cls");
	
	printf("  Essas são as informações do usuário:\n\n");	
	while(fgets(conteudo, 200, file) != NULL){  //fgets serve para buscar o arquivo. ele vai buscar o aqruivo conteudo, ate 200 caracteres enquanto o mesmo for diferente de NULL.
		printf("%s", conteudo);
	}
	printf("\n");
	system("pause");
	}
	fclose(file);  //Não explicaram, mas acabei descobrindo depois de muita tentativa e erro, que para excluir um arquivo aberto, é obrigatório fecha-lo anteriormente.
	  //fim da consulta.
}
	
int deletar(){
	setlocale (LC_ALL, "Portuguese");
	  
	  //Criação de variáveis/strings/numbers.
	char cpf [40];
	char conteudo [300];
	int opcao = 0;
	  //fim da Criação de variáveis/strings/numbers.
	  
	  //etapa de consulta de cpf para exclusão.
	printf("Insira o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	system("cls");
	
	
	if(file == NULL){
		printf("Arquivo não localizado.\n\n");
		system("pause");
		//fim da consulta para exclusão.
		
		//etapa de confirmação da exclusão
	}else{
		system("cls");
		
		while(fgets(conteudo, 200, file) != NULL){  //fgets serve para buscar o arquivo. ele vai buscar o aqruivo conteudo, ate 200 caracteres enquanto o mesmo for diferente de NULL.
		printf("%s", conteudo);
		}
		
		fclose(file);  //tenho que fechar o arquivo para conseguir exvluir ele! 
		
		printf("\nDeseja excluir esse usuário? \n\n\t1 - SIM! \n\t2 - NAO!\n\n");
		printf("Opcao: "); 
		
		scanf("%d",&opcao);  //armazena a resposta do usuário na variável. (tipo o prompt).
		
		system("cls");
		
		switch(opcao){
			case 1:
				remove(cpf);
				printf("Usuario excluído com sucesso!\n\n");
				system("pause");
			break;
			
			case 2:
				printf("Cancelando exclusão...\n\n");
				system("pause");
			break;
			
			default:
				printf("Opção Inválida!");
				system("pause");
			break;	
		      //fim da etapa de confirmação da exclusão.		
		}	
	}	
}

int main(){
	setlocale (LC_ALL, "Portuguese");
	
	int opcao=0;  //Definindo um valor para a variável.
	int i=1;
	char usuario[40]="a";
	char senha[10]="b";
	int comparacao1;
	int comparacao2;
	
	printf("\n  | Cartorio da EBAC |\n\n\n");
	printf("Informe o Usuário e senha.\n\n");
	printf("\n\tUsuário: ");
	scanf("%s",usuario);
	printf("\n\tSenha: ");
	scanf("%s", senha);
	
	comparacao1 = strcmp(usuario, "administrador");
	comparacao2 = strcmp(senha, "adm123");
	
	if(comparacao1 == 0 && comparacao2 == 0){
	
		for(i=1;i=1;){  //estrutura de repetição. 
			
			system("cls");  //comando para limpar a tela do usuário a cada atualização.
		
			setlocale (LC_ALL, "Portuguese"); // em tese serviria para definir a região que a biblioteca vai usar as alocações de texto.
		
			printf("\n  | Cartorio da EBAC |\n\n\n\n");  //printf é ultilizado para passar um texto para o usuário.
			printf("Seja bem vindo, EBACER!\n\n\n");
			printf("Selecione a opcao desejada no menu:\n\n");
			printf("\t1 - Registrar Nome\n");  //\t é ultilizado para dar um espaçamento antes do texto.
			printf("\t2 - Consultar Nomes\n");
			printf("\t3 - Deletar Nome\n"); 
			printf("\t4 - Fechar Programa\n\n\n");
			printf("Opcao: ");  //fim do menu
			
			scanf("%d",&opcao);  //armazena a resposta do usuário na variável. (tipo o prompt).
			
			system("cls");
			
			switch(opcao){
				case 1:
					registro();
				break;
				case 2:
					consulta();
				break;	
				case 3:
					deletar();
				break;
				case 4:
					printf("Encerrando o programa...\n\n");
					return 0;   // retorno 0, então fecha o programa.
				break;
				default:
					printf("Opcao invalida.\n\n");
					system("pause"); 
					break;		
			}	
		}
	}else{
		system("cls");
		printf("Usuário ou senha incorreto. Tente novamente.\n\n\n");
		system("pause");
		system("cls");
		main();
	
	}
} 
