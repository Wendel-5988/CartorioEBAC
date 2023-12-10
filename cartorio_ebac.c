#include <stdio.h>  //biblioteca de comunicação com o usuário.
#include <stdlib.h>  //biblioteca de alocação de espaço em memória.
#include <locale.h>  //biblioteca de alocaçôes de texto por região.
#include <string.h>  //biblioteca de organização de strings.

int registro(){
	setlocale (LC_ALL, "Portuguese");
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);  //Copia os valores das strings. Como se fosse (aqruivo = cpf).
	
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
	printf("Usuario registrado!\n\n");
	system("pause");
}

int consulta(){
	setlocale (LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[300];
	
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
}
	
int deletar(){
	printf("Você escolheu deletar arquivos.\n");
	system("pause");
}

int main(){
	int opcao=0;  //Definindo um valor para a variável.
	int i=1;
	
	for(i=1;i=1;){  //estrutura de repetição. 
		
		system("cls");  //comando para limpar a tela do usuário a cada atualização.
	
		setlocale (LC_ALL, "Portuguese"); // em tese serviria para definir a região que a biblioteca vai usar as alocações de texto.
	
		printf("\n  | Cartorio da EBAC |\n\n\n");  //printf é ultilizado para passar um texto para o usuário.
		printf(" Selecione a opcao desejada no menu:\n\n");
		printf("\t1 - Registrar Nome\n");  //\t é ultilizado para dar um espaçamento antes do texto.
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nome\n\n\n"); 
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
			default:
				printf("Opcao invalida.\n\n");
				system("pause"); 
				break;		
		}	
	}
} 
