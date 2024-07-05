	#include <stdio.h> //biblioteca para input/output
	#include <stdlib.h> //biblioteca para declara��o de vari�veis, fun��es, algortimos, etc. 
	#include<locale.h> //biblioteca para inserir idioma
	#include<stdlib.h> //biblioteca para cores 
	
	int main () //inicio da execu��o do c�digo
	{ 
	
		setlocale(LC_ALL,"Portuguese"); //defini��o do indioma
		system ("color 0C"); //defini��o da cor de fundo (preto) e da letra do programa (vermelho)
		
		//estrutura de dados 
		int l, c, linha, coluna, jogador, ganhou, jogadas, opcao; /*l= linha, c= coluna (vari�veis para inicializa��o da matriz); 
																	linha, coluna vari�veis para inputs por parte do utilizador
																	jogador vari�vel que indica que jogador est� a jogar
																	ganhou � a vari�vel que ir� guardar o valor de quem ganhou o jogo
																	jogadas guarda o n�mero de jogadas feitas
																	opcao � a vari�vel que guarda a op��o se o utilizador quer jogar novamente*/ 
		char jogo [3] [3]; //defini��o da matriz com �ndice linha, coluna com 9 posi��es sendo uma matriz de 3x3 com carctere espa�o
		
		do //permite imprimir o jogo e que os jogadores insiram v�rias jogadas
		{  
			jogador = 1; //atribui��o do valor 1 � vari�vel jogador - indica-nos que ser� primeiro o jogador 1 a jogar
			ganhou =0; //ganhou inicializa em 0 porque ainda ningu�m ganhou e cada vez que um jogador ganhar a vari�vel ganhou passar a ter o valor de 1 
			jogadas = 0; //jogadas inicia em 0 por ainda n�o ter sido feita nenhuma jogada
		
		
			//como inicializar a nossa estrutura de dados com espa�os em branco para posteriormente serem preenchidos pelos jogadores
			 for (l = 0; l<3; l++)//defini��o de 3 linhas com posi��es 0, 1 e 2
			 { 
			 	for (c=0; c<3; c++)//defini��o de 3 colunas com posi��es 0, 1 e 2
				 { 
			 		jogo[l][c]= ' '; //atribuir o valor de espa�o em branco � matriz 
				 }
			 }
			 
			 do //imprimir o jogo 
			 {
		
				 
				 printf ("\n\n\t 0   1    2 \n\n"); //impress�o dos indices das colunas e das linhas com os devidos espa�amentos para tornar o tabuleiro mais percept�vel 
				 for (l=0; l<3;l++)
				 { //impress�o das linhas sem separa��o
				 	for (c=0; c<3; c++)
					 { //impress�o das colunas sem separa��o
				 		if (c==0)
						 {
				 			printf("\t"); //impress�o de uma tabula��o para criar espa�amento da lateral esquerda do limite do ecr�
						 }
				 		printf("%c ", jogo [l][c]); //impress�o de um caractere com indice linha, coluna 
				 		if (c<2)
						 { //nas duas primeiras colunas (0 e 1)
				 			printf(" |"); //� impresso um | para fazer a divis�o das colunas (0 e 1)
						 }
						if (c==2)
						{ //quando a coluna 2 estiver com o seu indice impresso
							printf("  %d", l); //s�o impressos os indices das linhas
						}
					}
					if (l<2)
					{ //nas duas primeiras linhas (0 e 1)
					 printf("\n\t-----------"); //� impresso um ----------- para fazer a divis�o das linhas com uma quebra de linha (0 e 1)
					}
					printf("\n"); //impress�o de uma quebra de linha na �ltima linha que fica sem ----------- 
			    }
			  
			  //ler e salvar coordenadas
			  do
			  { 
			  	printf("JOGADOR %d: Escreva a linha e a coluna que deseja jogar: ", jogador); //output com informa��o para o utilizador de como jogar - 1� linha 2� coluna
			  	scanf ("%d%d", &linha, &coluna); //input dos utilizadores com os inidices/coordenadas que pretendem jogar 
			  } 
			  while (linha <0 || linha >2 || c<0 || coluna>2 || jogo[linha][coluna] != ' '); /*ter a certeza que o utilizador insere coordenadas v�lidas 
			 																						 e se o espa�o em que o jogador pretende jogar est� vazio */
			  
			
			  if (jogador == 1)
			   { //Sendo o jogador 1 a iniciar o jogo 
			  	jogo [linha][coluna] = '0'; //� lhe atribuido o s�mbolo 0
			  	jogador++; //de seguida � o jogador 2 a jogar
			   }
				else 
				{
					jogo [linha][coluna]= 'X'; //cujo s�mbolo � x
					jogador =1; //quando o jogador 2 faz a sua jogada a vari�vel jogador volta para 1 para que o jogador 1 possa jogar
				}	
				jogadas ++; //incrementado o valor de jogadas ou seja � adicionada +1 jogada cada vez que se verifica que as coordenadass�o v�lidas e que � poss�vel jog�-las
				
				//algu�m ganhou linha - Jogador 1
				if (jogo[0][0] =='0' && jogo [0][1]=='0' && jogo [0][2]=='0' || 
			jogo[1][0] =='0' && jogo [1][1]=='0' && jogo [1][2]=='0' ||
			jogo[2][0] =='0' && jogo [2][1]=='0' && jogo [2][2]=='0')
				{
					printf("\n Parab�ns! O Jogador 1 ganhou\n");
					ganhou =1; 
				}
				//algu�m ganhou linha - Jogador 2
					if (jogo[0][0] =='X' && jogo [0][1]=='X' && jogo [0][2]=='X' ||
			jogo[1][0] =='X' && jogo [1][1]=='X' && jogo [1][2]=='X' ||
			jogo[2][0] =='X' && jogo [2][1]=='X' && jogo [2][2]=='X')
				{
					printf("\n Parab�ns! O Jogador 2 ganhou\n");
					ganhou =1;
				}
				//algu�m ganhou coluna - Jogador 1
				if (jogo[0][0] =='0' && jogo [1][0]=='0' && jogo [2][0]=='0' ||
			jogo[0][1] =='0' && jogo [1][1]=='0' && jogo [2][1]=='0' ||
			jogo[0][2] =='0' && jogo [1][2]=='0' && jogo [2][2]=='0')
				{
					printf("\n Parab�ns! O Jogador 1 ganhou\n");
					ganhou =1;
				}
				//algu�m ganhou coluna - Jogador 2
					if (jogo[0][0] =='X' && jogo [1][0]=='X' && jogo [2][0]=='X' ||
			jogo[0][1] =='X' && jogo [1][1]=='X' && jogo [2][1]=='X' ||
			jogo[0][2] =='X' && jogo [1][2]=='X' && jogo [2][2]=='X')
				{
					printf("\n Parab�ns! O Jogador 2 ganhou\n");
					ganhou =1;
				}	
				//algu�m ganhou diagonal principal - Jogador 1
				if (jogo [0][0]=='0' && jogo[1][1]=='0' && jogo [2][2]=='0')
				{
				   printf("\n Parab�ns! O Jogador 1 ganhou\n");
				   ganhou =1;
				}
				//algu�m ganhou diagonal principal - Jogador 2
				if (jogo [0][0]=='X' && jogo[1][1]=='X' && jogo [2][2]=='X')
				{
				   printf("\n Parab�ns! O Jogador 2 ganhou\n");
				   ganhou =1;
				}
				//algu�m ganhou diagonal secud�ria - Jogador 1 
				if (jogo[0][2]=='0'&& jogo[1][1]=='0' && jogo[2][0]=='0')
				{
				   printf("\n Parab�ns! O Jogador 1 ganhou\n");
				   ganhou =1;
				}
				//algu�m ganhou diagonal secud�ria - Jogador 2
				if (jogo[0][2]=='X'&& jogo[1][1]=='X' && jogo[2][0]=='X')
				{
					printf("\n Parab�ns! O Jogador 2 ganhou\n");
					ganhou =1;
				}
			 }
			 
			 while (ganhou == 0 && jogadas <9); 
			 { //enquanto ainda ningu�m tiver ganho e exitirem 9 jogadas dispon�veis o programa continuar� a ser executado
			 	
			 	if (ganhou ==0 )
				{
			 		printf("\nO jogo finalizou sem vencedores!\n "); /*se a vari�vel ganhou se mantiver com o valor 0 o jogo finaliza sem vencedores*/
				}
				 
				printf("\nSe pretende jogar novamente clique na tecla 1\n ");
				scanf("%d", &opcao); //input do valor da vari�vel opcao
			 }	
		}
		while(opcao==1);  //quando o jogador selecionar a tecla 1 o programa ser� executado novamente	
		
		return 0; //fim da execu��o do programa e o mesmo encontra-se sem erros
	}
	

