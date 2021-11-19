#include <stdio.h>
#include <stdlib.h>
#include <string.h> // declarações de bibliotecas
#include <locale.h>
//#include <windows.h> //biblioteca responsavel por atualizar o codigo de acordo com o sistema operacional

#define TAM 5
/*criação de um STRUCT*/
/*
	Uma Struct é um novo tipo de dado
	por exemplo. assim como temos um tipo classes em POO.
	o struct cria um novo tipo de dado, que neste caso poderá receber valores pre definidos.
*/
struct agenda{
	char nome[30];
	char telefone[20];
	char email[40];
};
/*cria��o de  prototipos de fun��es*/
void limpa ();
void pause ();
void aluno ();
/*inicio do programa */
int main() {
	/*declara��o de variaveis*/

	struct agenda ficha[TAM]; // Vetor de struct
	int i,menu,cont,op;
	int escolha;
	/*corpo do programa*/
	setlocale(LC_ALL, "portuguese");
	SetConsoleOutputCP(1252);
	SetConsoleCP(1252); 
	// informa��oes do Aluno, antes do inicio do programa.
	aluno();
	/*programa principal proposto - agenda de clientes*/
	menu = 1;
	i = 0;
	cont = 0;
	while (menu != 0 ){ //condin��o para retorno ao MENU.
		printf (" _________________________________________\n");
		printf ("|*****************MENU********************|\n");
		printf ("| [1] INSERIR NOVO USU�RIO.               |\n");
		printf ("| [2] MOSTRAR TODOS OS CADASTROS.         |\n");
		printf ("| [0] SAIR                                |\n");
		printf ("|_________________________________________|\n");
		printf ("\nINFORME A OP��O DESEJADA:");
		scanf ("%d", &op);
		limpa();
		escolha = 1;
		switch (op){
			case 1:
				if (cont == TAM){
					printf ("\nAGENDA LOTADA!\n"); //INFORMA��O DE AGENDA LOTADA, QUANDO OS 5 CLIENTES FOREM CADASTRADOS
					printf ("\nRETORNE AO MENU PRINCIPAL\n");
					pause();
				}else{
					while ((escolha == 1) && (i < TAM)){
						printf ("CÓDIGO : %d\n",i+1); //c�digo gerado pelo sistema
						printf ("INFORME O NOME DO %d° CLIENTE:\n",i+1);
						scanf ("%30[^\n]s", &ficha[i].nome);
						//Atenção! o %30 é a definição do tamanho da palavra que poderá ser armazenada
						//ou seja, clientes como nome de no maximo 30 caracteres.
						fflush(stdin);
						printf ("INFORME O TELEFONE DO %d� CLIENTE:(XX)XXXXX-XXXX\n",i+1);
						scanf ("%s", &ficha[i].telefone);
						fflush(stdin);
						printf ("INFORME O EMAIL DO %d� CLIENTE\n",i+1);
						scanf ("%40[^\n]s", &ficha[i].email);
						fflush(stdin);             /*PREENCHIMENTO DOS DADOS CADASTRAIS.*/
						system("cls");
						printf ("\n%d� CLIENTE CADASTRADO\n",i+1);
						cont++;
						i++;
						pause();
						if (cont == TAM){
							printf ("\nAGENDA LOTADA!\n"); //INFORMA��O DE AGENDA LOTADA, QUANDO OS 5 CLIENTES FOREM CADASTRADOS
							printf ("\nRETORNE AO MENU PRINCIPAL\n");
							pause();
						}else{
							printf ("\nDESEJA CONTINUAR CADASTRANDO?[1 para SIM / 0 para N�O]\n");
							escolha = ' ';
							scanf ("%d", &escolha);
							limpa(); //chamada de fun��o.
							while ((escolha != 1) && (escolha != 0)){
								printf ("\nERR0! TENTE NOVAMENTE!\n");
								printf (" \nDIGITE 1- PARA CONTINUAR OU 0- PARA SAIR.\n");
								escolha = ' ';
								scanf ("%d", &escolha);
								limpa ();
							}
						}
					}
				}
			op = ' ';
			break;
			case 2:
				if (cont == 0){
					printf ("\nAGENDA VAZIA!\n POR FAVOR RETORNE AO MENU E PREENCHA.\n");
					pause();
				}else{
					for(i=0; i < cont; i++){
						printf ("________________________________________________\n");
						printf ("|              %d� USUARIO                      \n",i+1);
						printf ("|_______________________________________________\n");
						printf ("|C�DIGO: %d\n",i+1);
						printf ("|NOME: %s\n",ficha[i].nome);
						printf ("|TELEFONE: %s\n",ficha[i].telefone);
						printf ("|EMAIL: %s\n",ficha[i].email);
						printf ("|_______________________________________________\n");
						printf ("\n");
					}
					pause();
				}
			op = ' ';
			break;
			case 0:
				menu = 0;
				printf ("\nSAINDO DA AGENDA...\n");
			op = ' ';
			break;
			default:
				printf ("\nERRO!...\nOP��O INVALIDA!\nTENTE NOVAMENTE!\n");
			op = ' ';
			break;
		}
	}
	return (0);
}


/* todas as linhas abaixo s�o fun��es invocadas pelos seus propotipos de fun��es*/
void limpa (){
	fflush(stdin);
	system("cls");       //fun��o 1 - chamas linhas 63,96,102.
}
void pause (){
	system("pause");
	system("cls");      //fun��o 2 - chamadas linhas 70,87,91,112,125.
}
void aluno (){          //fun��o 3 - chamada linha 31.
	printf ("__________________________________________________\n");
	printf ("|********FACULDADE DE ENSINO - UNICESUMAR********|\n");
	printf ("|ALUNO: Airon silva gomes                        |\n");
	printf ("|R.A: 20014200-5                                 |\n");
	printf ("|PROFESSOR: Pietro Martins                       |\n"); /*informa��es complementares.*/
	printf ("|DISCIPLINA: ALGORITMO E L�GICA DE PROGRAMA��O 2 |\n");
	printf ("|MODULO: 52                                      |\n");
	printf ("|CURSO: AN�LISE E DESENVOLVIMENTO DE SISTEMAS    |\n");
	printf ("|------------------------------------------------|\n");
	printf ("|----------------ATIVIDADE MAPA------------------|\n");
	printf ("|------------------------------------------------|\n");
	printf ("|________________________________________________|\n");
	printf ("\nINICIANDO ATIVIDADE...\n\n");
	system("pause");
	limpa();
}
