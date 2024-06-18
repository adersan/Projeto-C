#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#define MAX_CONTACTS 5
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20
#define MAX_EMAIL_LENGTH 50
#define MAX_CPF_LENGTH 15
#define STRTAM 40

//Funcões para menus
void criarMenuLinhaSuperior(){
	int i;
	printf("%c", 201);
	for (i=0;i<STRTAM;i++){
		printf("%c",205);
	}
	printf("%c\n", 187);
}

void criarMenuLinhaInferior(int tamX){
	int i;
	printf("%c", 200);
	for (i=0;i<STRTAM;i++)
		printf("%c",205);
	printf("%c\n", 188);
}

void criaMenuItem(int tamX, char str[]){
	int contaLetras=0;
	int i;
	for(i=0;i<tamX;i++){
		if(str[i] == '\0')
			break;
		else
			contaLetras++;
	}		
	printf("%c", 186);
	//for (i=0;i<STRTAM;i++)
	printf("%s",str);
	while(contaLetras<tamX){
		printf("%c",32);
		contaLetras++;
	}
	printf("%c\n", 186);	
}

void chamaMenuPrincipal(){
	criarMenuLinhaSuperior();
	criaMenuItem(STRTAM,">>>>>>> SELECIONE UMA OPCAO <<<<<<<");
	criarMenuLinhaInferior(STRTAM);
	criarMenuLinhaSuperior();
	criaMenuItem(STRTAM,"| 1 | Adicionar Contato");
	criaMenuItem(STRTAM,"| 2 | Excluir Contato");
	criaMenuItem(STRTAM,"| 3 | Modificar Contato");
	criaMenuItem(STRTAM,"| 4 | Imprimir Lista de Contatos");
	criaMenuItem(STRTAM,"| 5 | Buscar Contato");
	criaMenuItem(STRTAM,"| 6 | Sair");
	criarMenuLinhaInferior(STRTAM);
	printf("\n");
}
void chamaMenuEditar(){
	criarMenuLinhaSuperior();
	criaMenuItem(STRTAM,">>> SELECIONE UMA OPCAO PARA EDITAR <<<");
	criarMenuLinhaInferior(STRTAM);
	criarMenuLinhaSuperior();
	criaMenuItem(STRTAM,"| 1 | NOME");
	criaMenuItem(STRTAM,"| 2 | TELEFONE");
	criaMenuItem(STRTAM,"| 3 | EMAIL");
	criaMenuItem(STRTAM,"| 4 | CPF");
	criaMenuItem(STRTAM,"| 5 | SAIR");
	criarMenuLinhaInferior(STRTAM);
	printf("\n");
}

// Declaração dos arrays para armazenar os atributos dos contatos
char names[MAX_CONTACTS][MAX_NAME_LENGTH];
char phones[MAX_CONTACTS][MAX_PHONE_LENGTH];
char emails[MAX_CONTACTS][MAX_EMAIL_LENGTH];
char cpfs[MAX_CONTACTS][MAX_CPF_LENGTH];
int numContacts = 0;

// Função para adicionar um novo contato
void addContact() {
	int i = 0;
  if (numContacts >= MAX_CONTACTS) {
    printf("A agenda esta cheia.\n");
    return;
  }

	// Solicita informações do novo contato ao usuário
	printf("Nome: ");
	fflush(stdin);
	fgets(names[numContacts],MAX_NAME_LENGTH, stdin);
 	//Funçao da biblioteca string para remover \n
	size_t newline_index = strcspn(names[numContacts], "\n");
  	names[numContacts][newline_index] = '\0';
	//Laço para converter em maiúscula a string nomes
	for (i = 0; names[numContacts][i] != '\0'; i++) {
    	names[numContacts][i] = toupper(names[numContacts][i]);	
	}
	printf("Telefone: ");
	scanf("%s", phones[numContacts]);
	printf("E-mail: ");
	scanf("%s", emails[numContacts]);
	printf("CPF: ");
	scanf("%s", cpfs[numContacts]);

  // Incrementa o contador de contatos
  numContacts++;
  printf("|-CONTATO ADICIONADO COM SUCESSO-|\n");
  system("PAUSE");
  printf("PRESCIONE ENTER PARA CONTINUAR");
  system("cls");
}

// Função para excluir um contato
void deleteContact() {
	int i = 0;
	int j = 0;
    char name [MAX_NAME_LENGTH];
    printf("Nome do contato que deseja excluir: \n");
    fflush(stdin);
    fgets(name, MAX_NAME_LENGTH, stdin);
    //Funçao da biblioteca string para remover \n
    size_t newline_index = strcspn(name, "\n");
  	name[newline_index] = '\0';
    for (i = 0; name[i] != '\0'; i++) {
    	name[i] = toupper(name[i]);	
	}
    /*Aqui a variável found é inicializada com 0.
	Ela serve como 	um flag para indicar se o 
	contato a ser excluído foi encontrado ou não*/
    int found = 0;
    /*Um laço para comparar o nome 
	digitado o nome do vetor*/
    for (i = 0; i < numContacts; i++) {
        if (strcmp(names[i], name) == 0) {
            /* Move os contatos para frente para preencher 
			o espaço do contato excluído
			Um loop interno for percorre os contatos a partir
			da posição encontrada (i) até o penúltimo (numContacts - 2).
			A função strcpy(names[j], names[j + 1]) copia o nome do 
			próximo contato para a posição atual (j), movendo os 
			contatos subsequentes para a frente.*/
            
            for (j = i; j < numContacts - 1; j++) {
                strcpy(names[j], names[j + 1]);
                strcpy(phones[j], phones[j + 1]);
                strcpy(emails[j], emails[j + 1]);
                strcpy(cpfs[j], cpfs[j + 1]);
            }
            // Decrementa o contador de contatos
            numContacts--;
            found = 1;
            printf("Contato excluido com sucesso.\n");
            break;

        }
    }
    //Verifica se o contado foi encontrador
    if (!found) {
        printf("Contato nao encontrado.\n");
    }
}

// Função para modificar um contato
void modifyContact() {
    char name[MAX_NAME_LENGTH];
    int i = 0;
    int choice;
    printf("DIGITE O NOME DO CONTATO:\n ");
    fflush(stdin);
    fgets(name, MAX_NAME_LENGTH, stdin);
    //Funçao da biblioteca string para remover \n
    size_t newline_index = strcspn(name, "\n");
  	name[newline_index] = '\0';
    for (i = 0; name[i] != '\0'; i++) {
    	name[i] = toupper(name[i]);	
	}
	//Found em 0 e a funç]ão de comparação/
    int found = 0;
    for (i = 0; i < numContacts; i++) {
        if (strcmp(names[i], name) == 0) {
            found = 1;
            /*Para melhorar a experiência do usuário
			foi criado um menu para escolher o que ele deseja alterar*/
            do {
            	chamaMenuEditar();
                scanf("%d", &choice);

                // Executa a opção escolhida pelo usuário
                switch (choice) {
                    case 1:
                        printf("Digite o novo nome: \n");
                        fflush(stdin);
						fgets(names[i],MAX_NAME_LENGTH, stdin);
                        system("cls");
                        printf("Nome alterado para %s\n", names[i]);
                        break;
                    case 2:
                        printf("Digite o novo telefone: ");
                        scanf("%s", phones[i]);
                        system("cls");
                        printf("Telefone alterado para %s\n", phones[i]);
                        break;
                    case 3:
                        printf("Digite o novo e-mail: \n");
                        scanf("%s", emails[i]);
                        system("cls");
                        printf("Email alterado para %s\n", emails[i]);
                        break;
                    case 4:
                        printf("Digite o novo CPF: \n");
                        scanf("%s", cpfs[i]);
                        system("cls");
                        printf("CPF alterado para %s\n", cpfs[i]);
                        break;
                    case 5:
                        printf("Saindo do modo editar.\n");
                        system("cls");
                        break;
                    default:
                        printf("Opção inválida. Tente novamente.\n");
                        break;
                }
            } while (choice != 5);
            break;
        }
    }
    if (!found) {
        printf("Contato não encontrado.\n");
    }
}

void searchContact() {
    char cpf[MAX_CPF_LENGTH];
    int i = 0;
    printf("DIGITE O CPF DO CONTATO:\n ");
    fflush(stdin);
    fgets(cpf, MAX_CPF_LENGTH, stdin);
    //Funçao da biblioteca string para remover \n
    size_t newline_index = strcspn(cpf, "\n");
    cpf[newline_index] = '\0';
    for (i = 0; cpf[i] != '\0'; i++) {
        cpf[i] = toupper(cpf[i]);	
    }
    //Found em 0 e a funç]ão de comparação/
    int found = 0;
    for (i = 0; i < numContacts; i++) {
        if (strcmp(cpfs[i], cpf) == 0) {
            found = 1;
            printf("------------------------------------\n");
            printf("-=-=-=-=- CONTATO ENCONTRADO -=-=-=-=\n");
            printf("Nome: %s\n", names[i]);
            printf("Telefone: %s\n", phones[i]);
            printf("E-mail: %s\n", emails[i]);
            printf("CPF: %s\n", cpfs[i]);
            printf("\n");
            printf("------------------------------------\n");
            break; // interrompe o loop assim que encontrar o contato
        }
    }
    if (!found) {
        printf("Contato não encontrado.\n");
    }
}
// Função para imprimir todos os contatos
void printContacts() {
	int i=0;
	int saldoContacts = 0;
	printf("------------------------------------\n");
    printf("-=-=-=-=- LISTA DE CONTATOS -=-=-=-=\n");
    for (i = 0; i < numContacts; i++) {
    	printf("------------------------------------\n");
        printf("Nome: %s\n", names[i]);
        printf("Telefone: %s\n", phones[i]);
        printf("E-mail: %s\n", emails[i]);
        printf("CPF: %s\n", cpfs[i]);
        printf("\n");
        printf("------------------------------------\n");
    }
    
    printf("Total de %d contatos na agenda\n",numContacts);
    saldoContacts=MAX_CONTACTS-numContacts;
    printf("------------------------------------\n");
    printf("Voce possui %d vagas restantes\n",saldoContacts);
    printf("------------------------------------\n");
    printf("TECLE ENTER PARA CONTINUAR>>>>>>>>>>\n");
    system("PAUSE");
    system("cls");
}

// Função principal
int main() {
	//Atribuição de cor do sistema
	system("color b0");
/*	0 - Preto
	1 - Azul
	2 - Verde
	3 - Verde-água
	4 - Vermelho
	5 - Roxo
	6 - Amarelo
	7 - Branco
	8 - Cinza
	9 - Azul claro
	A - Verde Claro
	B - Verde-água claro
	C - Vermelho Claro
	D - Lilás
	E - Amarelo Claro
	F - Branco Brilhante*/
    int choice = 0;

    // Loop do menu principal
    do {
    	chamaMenuPrincipal();
        scanf("%d", &choice);

        // Executa a opção escolhida pelo usuário
        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                deleteContact();
                break;
            case 3:
                modifyContact();
                break;
            case 4:
            	system("cls");
                printContacts();
                break;
            case 5:
                searchContact();
                break;
			case 6:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                system("PAUSE");
                system("cls");
        }
    } while (choice != 6);

    return 0;
}
