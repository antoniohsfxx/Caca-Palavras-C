#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

int mPrincipal; //Opção escolhida no menuPrincipal()
int mMatriz; //Opção escolhida na imprimirMatrizMenu()
int opcao; //Opção escolhida no menuJogarMT()

char mat[MAX][MAX]; // Declaração da matriz.
char cad[MAX+1]; // Cadeia a ser procurada.
int tam; // Numero de caracteres de cad.

int i,j; //Linha e Coluna.
int n; //Ordem das Matrizes.

	int main() {
		menuPrincipal();
		return 0;
	}

	//Procedimento que adicina elementos a Matriz Teste.
	void leiaMatrizTeste(){
		n = 10;
		mat[0][0]='a'; mat[0][1]='b'; mat[0][2]='a'; mat[0][3]='c'; mat[0][4]='a'; mat[0][5]='x'; mat[0][6]='i'; mat[0][7]='b'; mat[0][8]='a'; mat[0][9]='a';
		mat[1][0]='n'; mat[1][1]='b'; mat[1][2]='y'; mat[1][3]='f'; mat[1][4]='a'; mat[1][5]='z'; mat[1][6]='a'; mat[1][7]='a'; mat[1][8]='a'; mat[1][9]='l'; 
		mat[2][0]='t'; mat[2][1]='t'; mat[2][2]='a'; mat[2][3]='e'; mat[2][4]='h'; mat[2][5]='p'; mat[2][6]='e'; mat[2][7]='r'; mat[2][8]='o'; mat[2][9]='a';
		mat[3][0]='o'; mat[3][1]='i'; mat[3][2]='r'; mat[3][3]='a'; mat[3][4]='v'; mat[3][5]='e'; mat[3][6]='r'; mat[3][7]='o'; mat[3][8]='f'; mat[3][9]='f';
		mat[4][0]='n'; mat[4][1]='z'; mat[4][2]='t'; mat[4][3]='a'; mat[4][4]='z'; mat[4][5]='m'; mat[4][6]='a'; mat[4][7]='d'; mat[4][8]='i'; mat[4][9]='f';
		mat[5][0]='i'; mat[5][1]='x'; mat[5][2]='q'; mat[5][3]='m'; mat[5][4]='u'; mat[5][5]='a'; mat[5][6]='l'; mat[5][7]='a'; mat[5][8]='l'; mat[5][9]='i';
		mat[6][0]='o'; mat[6][1]='c'; mat[6][2]='w'; mat[6][3]='n'; mat[6][4]='u'; mat[6][5]='s'; mat[6][6]='u'; mat[6][7]='l'; mat[6][8]='g'; mat[6][9]='n';
		mat[7][0]='t'; mat[7][1]='e'; mat[7][2]='s'; mat[7][3]='t'; mat[7][4]='e'; mat[7][5]='d'; mat[7][6]='e'; mat[7][7]='l'; mat[7][8]='i'; mat[7][9]='n';
		mat[8][0]='h'; mat[8][1]='o'; mat[8][2]='m'; mat[8][3]='a'; mat[8][4]='n'; mat[8][5]='t'; mat[8][6]='o'; mat[8][7]='n'; mat[8][8]='i'; mat[8][9]='o';
		mat[9][0]='k'; mat[9][1]='o'; mat[9][2]='a'; mat[9][3]='z'; mat[9][4]='z'; mat[9][5]='z'; mat[9][6]='a'; mat[9][7]='m'; mat[9][8]='a'; mat[9][9]='l';
	}

	//Procedimento padrão para imprimir qualquer matriz armazenada em 'mat[][]'.
	/*O procedimento usa dois laços de repetição que percorrem todos os elementos i,j da matriz mat
	e depois usando o printf, imprime-os*/
	void imprimaMatriz() {
		for (i=0; i<n; i++) {
			printf("\n");
			for (j=0; j<n; j++) {
				//printf("mat[%d][%d]=%c ", i,j,mat[i][j]); //Detalhes
				printf("%c ", mat[i][j]); //Sem Detalhes
			}
		}
	}

	//Procedimento para voltar ao menu principal após uma busca.
	void voltarPosBusca() {
		int continuar;
		printf("\n\n[AVISO] Digite qualquer NUMERO e clique enter para continuar!");
		scanf("%d", &continuar);
		system("cls");
		jogarMenu();
	}

	//Procedimento para voltar ao menu principal após um teste.
	void voltarPosTeste() {
		int continuar;
		printf("\n\n[AVISO] Digite qualquer NUMERO e clique enter para continuar!");
		scanf("%d", &continuar);
		system("cls");
		menuTestes();
	}

	/*--------------------------------------------------------
    Inicio dos Procedimentos para busca das palavras na Matriz.
    --------------------------------------------------------*/

	//Procedimento que lê a subcadeia de caracteres que será pesquisada na matriz.
	void leSubCad() {
		printf("Forneca a subcadeia: ");
		scanf("%s", cad);
		tam = strlen(cad);
		printf("Cadeia lida: %s com %d caracteres\n", cad, tam);
		
		switch(opcao) {
			case 1: esqDir(); voltarPosBusca(); break;
			case 2: dirEsq(); voltarPosBusca(); break;
			case 3: horizontal(); voltarPosBusca(); break;
			case 4: cimabaixo(); voltarPosBusca(); break;
			case 5: baixocima(); voltarPosBusca(); break;
		}			
	}
	
	/*Os proceedimentos abaixo, usam laços de repetição
	(de acordo com o que o procedimento precisar, ex.: cima p/ baixo ou baixo p/ cima)
	para percorrer as linhas e as colunas da Matriz.*/

	//Procedimento de pesquisa da Esquerda para a Direita.
	int esqDir(){
		imprimaMatriz();
		for (i=0; i<256; i++){
			for(j=0; j<256-tam+1; j++){
				if(strncmp(&mat[i][j], cad, tam) == 0){
				printf("\n[Esquerda p/ Direita] Linha: %d Coluna: %d", i ,j);
				}
			}
		}
	}
	
	//Procedimento de pesquisa da Direita para a Esquerda.
	void dirEsq() {
		imprimaMatriz();
		int auxColMat; //auxiliar de coluna em mat
		int colCad; //auxiliar de coluna em cad
		
		for (i=0; i<256; i++)
			for(j = 256-tam; j>=0; j--){
				auxColMat = j;
				colCad = 0;
				while (cad[colCad] == mat[i][auxColMat] && colCad<tam){
					colCad++;
					auxColMat--;
				}
				if (colCad==tam)
				printf("\n[Direita p/ Esquerda] Linha: %d Coluna: %d \n", i ,j);
			}
	}
	
	//Procedimento de pesquisa na Horizontal.
	/*O procedimento 'horizontal()' reaproveita o código dos procedimentos de busca
	'esqDir()' e 'dirEsq()'*/
	int horizontal() {
		imprimaMatriz();
		
		//PESQUISA ESQUERDA PARA A DIREITA
		for (i = 0; i < 256; i++){
			for(j = 0; j < 256-tam+1; j++){
				if(strncmp(&mat[i][j], cad, tam) == 0){
				printf("\n[Esquerda p/ Direita] Linha: %d Coluna: %d", i ,j);
				}
			}
		}
		
		//PESQUISA DIREITA PARA A ESQUERDA
		int auxColMat; // auxiliar de coluna em mat
		int colCad; // auxiliar de coluna em cad		
		for (i=0; i<256; i++)
			for(j = 256-tam; j>=0; j--){
				auxColMat = j;
				colCad = 0;
				while (cad[colCad] == mat[i][auxColMat] && colCad<tam){
					colCad++;
					auxColMat--;
				}
				if (colCad==tam)
				printf("\n[Direita p/ Esquerda] Linha: %d Coluna: %d", i ,j);
			}
	}
	
	//Procedimento de pesquisa de Cima para Baixo.
	int cimabaixo(){
		imprimaMatriz();
		
		int auxlinMat; // auxiliar de coluna em mat
		int colCad; // auxiliar de coluna em cad
			
		for (j=0; j<256; j++) // Percorre todas as colunas da matriz
			for(i = 0; i<256-tam+1; i++){
				auxlinMat = i;
				colCad = 0;
				while (cad[colCad] == mat[auxlinMat][j] && colCad<tam){
					colCad++;
					auxlinMat++;
				}
					if (colCad==tam) {
					printf("\n[Cima p/ Baixo] Linha: %d Coluna: %d", i ,j);						
					}
			}
	}
	
	//Procedimento de pesquisa de Baixo para Cima.
	int baixocima(){
		imprimaMatriz();
		int auxlinMat; // auxiliar de coluna em mat
		int colCad; // auxiliar de coluna em cad
		
		for (j=0; j<256; j++) // Percorre todas as colunas da matriz
			for(i=256 ; i>=0; i--){
				auxlinMat = i;
				colCad = 0;
				while (cad[colCad] == mat[auxlinMat][j] && colCad<tam){
					colCad++;
					auxlinMat--;
				}
				if (colCad==tam) {
					printf("\n[Baixo p/ Cima] Linha: %d Coluna: %d", i ,j);
				}
			}
	}

	/*--------------------------------------------------------
    Fim dos Procedimentos para busca das palavras na Matriz.
    --------------------------------------------------------*/

	/*----------------------------------------------------
    Inicio dos Procedimentos para busca nos casos de Teste.
    -----------------------------------------------------*/

	//Procedimento de caso de teste da Esquerda para a Direita.
	void testeEsqDir(){
		const int nmrdecasos = 8; //Número de casos teste.
		char casosdeteste[8][20]={"aba\0", "aa\0", "ita\0", "off\0", "ix\0", "t\0", "n\0", "testedelin\0"};
		int cont;
		leiaMatrizTeste();
		cabecario();
		for (cont = 0; cont<nmrdecasos; cont++){
			printf("\n\nCaso %d:\n" ,cont);
			cad[0]= '\0';
			strcpy(cad, casosdeteste[cont]);
			tam = strlen(cad);
			printf("Palavra %s com %d letras\n" ,cad ,tam);
			esqDir();
		}
		voltarPosTeste();
	}
	
	//Procedimento de caso de teste da Direita para a Esquerda.
	void testeDirEsq(){
		const int nmrdecasos = 5; //Número de casos teste.
		char casosdeteste[5][20]={"ore\0" ,"sun\0" ,"amo\0" , "lama\0" ,"forevar\0"};
		int cont;
		leiaMatrizTeste();
		cabecario();
		for (cont = 0; cont<nmrdecasos; cont++){
			printf("\n\nCaso %d:\n" ,cont);
			cad[0]= '\0';
			strcpy(cad, casosdeteste[cont]);
			tam = strlen(cad);
			printf("Palavra %s com %d letras\n" ,cad ,tam);
			dirEsq();
		}
		voltarPosTeste();
	}
	
	//Procedimento de caso de teste de Cima para a Baixo.
	void testeCimaBaixo(){
		const int nmrdecasos = 5; //Número de casos teste.
		char casosdeteste[5][20]={"finnal\0" ,"art\0" ,"giba\0" , "ala\0" ,"era\0"};
		int cont;
		leiaMatrizTeste();
		cabecario();
		for (cont = 0; cont<nmrdecasos; cont++){
			printf("\n\nCaso %d:\n" ,cont);
			cad[0]= '\0';
			strcpy(cad, casosdeteste[cont]);
			tam = strlen(cad);
			printf("Palavra %s com %d letras\n" ,cad ,tam);
			cimabaixo();
		}
		voltarPosTeste();
	}
	
	//Procedimento de caso de teste de Baixo para Cima.
	void testeBaixoCima(){
		const int nmrdecasos = 5; //Número de casos teste.
		char casosdeteste[5][20]={"ma\0" ,"lar\0" ,"dor\0" , "same\0" ,"molla\0"};
		int cont;
		leiaMatrizTeste();
		cabecario();
		for (cont = 0; cont<nmrdecasos; cont++){
			printf("\n\nCaso %d:\n" ,cont);
			cad[0]= '\0';
			strcpy(cad, casosdeteste[cont]);
			tam = strlen(cad);
			printf("Palavra %s com %d letras\n" ,cad ,tam);
			baixocima();
		}
		voltarPosTeste();
	}
	/*----------------------------------------------------
    Fim dos Procedimentos para busca nos caasos de Teste.
    -----------------------------------------------------*/

	//Procedimento para imprimir o cabeçario.
	void cabecario() {
		printf("------------------------------------------\n");
		printf("|              CACA-PALAVRAS             |\n");
		printf("------------------------------------------\n");
	}

	//Procedimento que mostra o Menu Principal do Caça-Palavras
	void menuPrincipal() {
		cabecario();
		printf("1 - Crie uma Matriz utilizando o teclado\n");
		printf("2 - Imprima a Matriz\n");
		printf("3 - Jogar\n");
		printf("4 - Execute o teste padrao\n");
		printf("0 - Sair\n");
		printf("\nDigite a sua opcao: ");
		scanf("%d", &mPrincipal);
		printf(" \n");
		
		switch (mPrincipal) {
			case 1: system("cls"); criarMatrizTeclado(); break;
			case 2: system("cls"); imprimirMatrizMenu(); break;
			case 3: system("cls"); jogarMenu(); break;
			case 4: system("cls"); menuTestes(); break;
		}
	}

	/*Procedimento da opção Nº1 do Menu Principal.
    Procedimento que cria a matriz personalizada manualmente.*/
	void criarMatrizTeclado() {
		int continuar;
		system("cls");
		cabecario();
		
		printf("------------------AVISO-------------------\n");
		printf("  Para criar a matriz pelo teclado, voce\n");
		printf("tera que digitar todas as letras da matriz.\n\n");
		printf("Deseja continuar? 1 = Sim | 2 = Nao: ");
		scanf("%d", &continuar);
		printf(" \n");
		if (continuar == 2) {
			system("cls");
			menuPrincipal();
		}else if (continuar == 1){
			leiaMatriz();
		}
	}

	/*Procedimeno que lê os elementos que serão adicionados a Mariz Personalizada (Porém, no Menu Principal).
	Primeiro, o procedimeno pergunta a ordem da matriz, e se a ordem não ulrapassar 256x256, o procedimeno
	pedirá os elementos de cada linha e coluna da matriz.*/
	int leiaMatriz(){
		system("cls");
		cabecario();
		printf("Diga qual a ordem da Matriz:  ");
		scanf("%d" ,&n);
		printf(" \n");
		if (n<=MAX){
			printf("A matriz sera %dx%d, agora digite as letras da matriz:\n" ,n ,n);
			for(i=0; i<n; i++){
				for(j=0; j<n; j++){
					printf("mat[%d][%d]: ", i,j);
					scanf(" %c" ,&mat[i][j]);
					}
				}
				menuPrincipal();
			}else{
			printf("A Matriz nao pode ultrapassar 256x256, digite uma ordem menor\n");
		}
	}

	/*Procedimento da opção Nº2 do Menu Principal.
    Procedimento que imprime a Matriz.*/  
	void imprimirMatrizMenu() {
		cabecario();
		printf("1 - Imprimir Matriz Teste\n2 - Imprimir Matriz Escrita\n0 - Voltar ao Menu Principal\n \nDigite sua opcao: ");
		scanf("%d", &mMatriz);
		switch(mMatriz) {
			case 1: leiaMatrizTeste(); imprimaMatriz(); printf(" \n"); menuPrincipal(); break;
			case 2: imprimaMatriz(); printf(" \n"); menuPrincipal(); break;
			case 0: system("cls"); menuPrincipal(); break;
		}	
	}

	/*Procedimentos da opção Nº3 do Menu Principal.
    Procedimento que mostra o Menu Jogar.*/ 
	void jogarMenu() {
		int mJogar;
		cabecario();
		printf("1 - Jogar utilizando a Matriz Teste\n");
		printf("2 - Jogar com a Matriz Personalizada\n");
		printf("0 - Voltar ao Menu Principal\n");
		printf("\nDigite a sua opcao: ");
		scanf("%d", &mJogar);
		printf(" \n");
		
		switch (mJogar) {
			case 1: system("cls"); menuJogarMT(); break;
			case 2: system("cls"); leiaMatrizNoJogar(); break;
			case 0: system("cls"); menuPrincipal(); break;
		}	
	}

	//Menu de opções de pesquisa para busca uilizando a Matriz Teste.
	int menuJogarMT() {
		leiaMatrizTeste();
		cabecario();
		imprimaMatriz();
		printf("\n\n1 - Pesquisa da esquerda para a direita.\n");
		printf("2 - Pesquisa da direita para esquerda.\n");
		printf("3 - Pesquisa na horizontal (esq->dir e dir-->esq).\n");
		printf("4 - Pesquisa de cima para baixo.\n");
		printf("5 - Pesquisa de baixo para cima.\n");
		printf("0 - Sair.\n");
		printf("Digite a sua opcao: ");
		scanf("%d", &opcao);
		printf("\n");
		
		if (opcao == 0) {
			system("cls");
			menuPrincipal();
		}else{
			leSubCad();			
		}
		
		return opcao;
	}
	
	//Menu de opções de pesquisa para busca uilizando a Matriz Personalizada.
	int menuJogarMDgt() {
		cabecario();
		imprimaMatriz();
		printf(" \n\n");
		printf("1 - Pesquisa da esquerda para a direita.\n");
		printf("2 - Pesquisa da direita para esquerda.\n");
		printf("3 - Pesquisa na horizontal (esq->dir e dir-->esq).\n");
		printf("4 - Pesquisa de cima para baixo.\n");
		printf("5 - Pesquisa de baixo para cima.\n");
		printf("0 - Sair.\n");
		printf("Digite a sua opcao: ");
		scanf("%d", &opcao);
		printf("\n");
		
		if (opcao == 0) {
			system("cls");
			menuPrincipal();
		}else{
			leSubCad();			
		}
		
		return opcao;
	}

	/*Procedimeno que lê os elementos que serão adicionados a Mariz Personalizada.
	Primeiro, o procedimeno pergunta a ordem da matriz, e se a ordem não ulrapassar 256x256, o procedimeno
	pedirá os elementos de cada linha e coluna da matriz.*/
	int leiaMatrizNoJogar(){
		system("cls");
		cabecario();
		printf("Diga qual a ordem da Matriz:  ");
		scanf("%d" ,&n);
		printf(" \n");
		if (n<=MAX){
			printf("A matriz sera %dx%d, agora digite as letras da matriz:\n" ,n ,n);
			for( i = 0 ; i < n ; i++){
				for( j = 0 ; j < n ; j++){
					printf("mat[%d][%d]: ", i,j);
					scanf(" %c" ,&mat[i][j]);
					}
				}
				system("cls");
				menuJogarMDgt();
			}else{
			printf("A Matriz nao pode ultrapassar 256x256, digite uma ordem menor\n");
		}
	}

	/*Procedimentos da opção Nº4 do Menu Principal.
    Procedimento que mostra o Menu Testes.*/
	int menuTestes() {
		int escolha;
		cabecario();
		printf("1 - Teste da esquerda para a direita.\n");
		printf("2 - Teste da direita para esquerda.\n");
		printf("3 - Teste de cima para baixo.\n");
		printf("4 - Teste de baixo para cima.\n");
		printf("0 - Sair.\n");
		printf("Digite a sua opcao: ");
		scanf("%d", &escolha);
		printf("\n");
		
		switch (escolha) {
			case 1: system("cls"); testeEsqDir(); break;
			case 2: system("cls"); testeDirEsq(); break;
			case 3: system("cls"); testeCimaBaixo(); break;
			case 4: system("cls"); testeBaixoCima(); break;
			case 0: system("cls"); menuPrincipal(); break;
		}
		return escolha;
	}

	
    /*
	Desenvolvido por: Antônio Humberto Silva Fontes :)
	
	Sugestões de Jogo: 
	> 3-1-1; Subcadeia: antonio (O prgrama encntrará a palavra 'antonio' na Linha 8, Coluna 3).
	> 3-1-4; Subcadeia: roda (O prgrama encntrará a palavra 'roda' na Linha 2, Coluna 7).
	> 3-1-1; Subcadeia: abacaxi (O prgrama encntrará a palavra 'bacaxi' na Linha 0, Coluna 0).
	*/