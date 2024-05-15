#include <stdio.h>	//biblioteca de comunicação com o usuário
#include <stdlib.h>	//biblioteca de alocação de espaço de memória
#include <locale.h>	//biblioteca de alocação de texto por região
#include <string.h>	//biblioteca de string

void virgula(char arquivo[]){				//função para adicionar uma virgula no registro
	FILE *file;
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
}

int registro(){								// funcao registro de nomes
//variaveis
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	char arquivo[40];
//final variaveis
	
	// coletar informações usuario
	system("cls");
	printf("Digite o cpf a ser cadastrado: ");	//registro cpf
	scanf("%s", cpf);
	
    strcpy(arquivo, cpf);						//copiar valores das strings
	
	FILE *file;									//cria o arquivo
	file = fopen(arquivo, "w");					//abre o arquivo
	fprintf(file, cpf);							//salva variavel
	fclose(file);								//fecha arquivo
	
	
	virgula(arquivo);							//adiciona virgula ao registro
	printf("\nDigite o nome a ser cadastrado: ");	//registro nome
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	
	virgula(arquivo);
	printf("\nDigite o sobrenome a ser cadastrado: ");	//registro sobrenome
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	
	virgula(arquivo);
	printf("\nDigite o cargo a ser cadastrado: ");	//registro cargo
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	// coletar informações usuario - Final
}

int consulta(){								// funcao consultar nomes
	setlocale(LC_ALL, "Portuguese");
	
	//variaveis
	char conteudo[40];
	char cpf[40];
	//Final variaveis
	
	printf("\nDigite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL){							//verifica existencia do arquivo
		printf("Arquivo não localizado.\n");
	}
	while(fgets(conteudo,200,file) != NULL){	//mostra as informações
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file);
}

int deletar(){								// funcao deletar nomes

	//variaveis
	char cpf[40];
	char resposta;
	//Final variaveis
	
	
	system("cls");
	setlocale(LC_ALL, "Portuguese");
	
	printf("Digite o CPF a ser deletado: ");
	scanf(" %s", cpf);
	
	
	FILE *file;
	file = fopen(cpf, "r");
	if(file == NULL){						//verificar existencia do arquivo
		printf("Usuário não encontrado no sistema.\n");
		system("pause");
		fclose(file);
	}
	else {
        printf("\nVocê realmente deseja deletar o CPF %s? (s/n): ", cpf);
        fclose(file);
        scanf(" %c", &resposta);
        if (resposta == 's' || resposta == 'S') {				//conrfimar delete
            if (remove(cpf) == 0) {								//deleta arquivo
                printf("\nUsuário deletado com sucesso.\n");
                getchar();
            } else {
                printf("\nErro ao deletar o usuário.\n");
            }
        }
    }
}

char obterResposta(int valor) {				//função para manter ou terminar loop
    char resposta;
    	switch(valor){													//define qual função perguntar
		case 1:
    	printf("\nDeseja continuar registrando? (s/n): ");				//pergunta do registro
		break;
		
		case 2:
    	printf("\nDeseja continuar consultando? (s/n): ");				//pergunta da consulta
		break;
		
		case 3:
    	printf("\nDeseja continuar deletando? (s/n): ");				//pergunta do delete
		break;
		
		case 4:
    	printf("\nDeseja retornar ao menu? (s/n): ");					//retorno de menu
		break;
	}
    scanf(" %c", &resposta);
    getchar();
    return resposta;
}

int main(){
	//variaveis
	int opcao = 0;
	char resposta;
	//Final variaveis
	
	do {
        system("cls");
		setlocale(LC_ALL, "Portuguese");               // Definir a linguagem
	
		printf("### Cartório da EBAC ###\n\n");        // Menu
		printf(" Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");            
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção: ");
	
		scanf("%d", &opcao);                           // Scanear variavel
		system("cls");                                 // Limpar tela
	
		switch(opcao){
			case 1:
            do{
				registro();
				resposta = obterResposta(1);
            } while (resposta != 'n' && resposta != 'N');
            break;

            case 2:
            do {
                consulta();
				resposta = obterResposta(2);
            } while (resposta != 'n' && resposta != 'N');
            break;

            case 3:
            do {
                deletar();
				resposta = obterResposta(3);
            } while (resposta != 'n' && resposta != 'N');
            break;

            default:														//opcao indisponivel
            printf("Opção indisponível\n");
            system("pause");
            break;
        }
        system("cls");
		resposta = obterResposta(4);
    } while (resposta != 'n' && resposta != 'N');							//retornar menu
}
