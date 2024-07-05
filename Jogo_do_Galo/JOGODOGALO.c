	#include <stdio.h> //biblioteca para input/output
	#include <stdlib.h> //biblioteca para declaração de variáveis, funções, algortimos, etc. 
	#include<locale.h> //biblioteca para inserir idioma
	#include<stdlib.h> //biblioteca para cores 
	
	int main () //inicio da execução do código
	{ 
	
		setlocale(LC_ALL,"Portuguese"); //definição do indioma
		system ("color 0C"); //definição da cor de fundo (preto) e da letra do programa (vermelho)
		
		//estrutura de dados 
		int l, c, linha, coluna, jogador, ganhou, jogadas, opcao; /*l= linha, c= coluna (variáveis para inicialização da matriz); 
																	linha, coluna variáveis para inputs por parte do utilizador
																	jogador variável que indica que jogador está a jogar
																	ganhou é a variável que irá guardar o valor de quem ganhou o jogo
																	jogadas guarda o número de jogadas feitas
																	opcao é a variável que guarda a opção se o utilizador quer jogar novamente*/ 
		char jogo [3] [3]; //definição da matriz com índice linha, coluna com 9 posições sendo uma matriz de 3x3 com carctere espaço
		
		do //permite imprimir o jogo e que os jogadores insiram várias jogadas
		{  
			jogador = 1; //atribuição do valor 1 à variável jogador - indica-nos que será primeiro o jogador 1 a jogar
			ganhou =0; //ganhou inicializa em 0 porque ainda ninguém ganhou e cada vez que um jogador ganhar a variável ganhou passar a ter o valor de 1 
			jogadas = 0; //jogadas inicia em 0 por ainda não ter sido feita nenhuma jogada
		
		
			//como inicializar a nossa estrutura de dados com espaços em branco para posteriormente serem preenchidos pelos jogadores
			 for (l = 0; l<3; l++)//definição de 3 linhas com posições 0, 1 e 2
			 { 
			 	for (c=0; c<3; c++)//definição de 3 colunas com posições 0, 1 e 2
				 { 
			 		jogo[l][c]= ' '; //atribuir o valor de espaço em branco à matriz 
				 }
			 }
			 
			 do //imprimir o jogo 
			 {
		
				 
				 printf ("\n\n\t 0   1    2 \n\n"); //impressão dos indices das colunas e das linhas com os devidos espaçamentos para tornar o tabuleiro mais perceptível 
				 for (l=0; l<3;l++)
				 { //impressão das linhas sem separação
				 	for (c=0; c<3; c++)
					 { //impressão das colunas sem separação
				 		if (c==0)
						 {
				 			printf("\t"); //impressão de uma tabulação para criar espaçamento da lateral esquerda do limite do ecrã
						 }
				 		printf("%c ", jogo [l][c]); //impressão de um caractere com indice linha, coluna 
				 		if (c<2)
						 { //nas duas primeiras colunas (0 e 1)
				 			printf(" |"); //é impresso um | para fazer a divisão das colunas (0 e 1)
						 }
						if (c==2)
						{ //quando a coluna 2 estiver com o seu indice impresso
							printf("  %d", l); //são impressos os indices das linhas
						}
					}
					if (l<2)
					{ //nas duas primeiras linhas (0 e 1)
					 printf("\n\t-----------"); //é impresso um ----------- para fazer a divisão das linhas com uma quebra de linha (0 e 1)
					}
					printf("\n"); //impressão de uma quebra de linha na última linha que fica sem ----------- 
			    }
			  
			  //ler e salvar coordenadas
			  do
			  { 
			  	printf("JOGADOR %d: Escreva a linha e a coluna que deseja jogar: ", jogador); //output com informação para o utilizador de como jogar - 1º linha 2º coluna
			  	scanf ("%d%d", &linha, &coluna); //input dos utilizadores com os inidices/coordenadas que pretendem jogar 
			  } 
			  while (linha <0 || linha >2 || c<0 || coluna>2 || jogo[linha][coluna] != ' '); /*ter a certeza que o utilizador insere coordenadas válidas 
			 																						 e se o espaço em que o jogador pretende jogar está vazio */
			  
			
			  if (jogador == 1)
			   { //Sendo o jogador 1 a iniciar o jogo 
			  	jogo [linha][coluna] = '0'; //é lhe atribuido o símbolo 0
			  	jogador++; //de seguida é o jogador 2 a jogar
			   }
				else 
				{
					jogo [linha][coluna]= 'X'; //cujo símbolo é x
					jogador =1; //quando o jogador 2 faz a sua jogada a variável jogador volta para 1 para que o jogador 1 possa jogar
				}	
				jogadas ++; //incrementado o valor de jogadas ou seja é adicionada +1 jogada cada vez que se verifica que as coordenadassão válidas e que é possível jogá-las
				
				//alguém ganhou linha - Jogador 1
				if (jogo[0][0] =='0' && jogo [0][1]=='0' && jogo [0][2]=='0' || 
			jogo[1][0] =='0' && jogo [1][1]=='0' && jogo [1][2]=='0' ||
			jogo[2][0] =='0' && jogo [2][1]=='0' && jogo [2][2]=='0')
				{
					printf("\n Parabéns! O Jogador 1 ganhou\n");
					ganhou =1; 
				}
				//alguém ganhou linha - Jogador 2
					if (jogo[0][0] =='X' && jogo [0][1]=='X' && jogo [0][2]=='X' ||
			jogo[1][0] =='X' && jogo [1][1]=='X' && jogo [1][2]=='X' ||
			jogo[2][0] =='X' && jogo [2][1]=='X' && jogo [2][2]=='X')
				{
					printf("\n Parabéns! O Jogador 2 ganhou\n");
					ganhou =1;
				}
				//alguém ganhou coluna - Jogador 1
				if (jogo[0][0] =='0' && jogo [1][0]=='0' && jogo [2][0]=='0' ||
			jogo[0][1] =='0' && jogo [1][1]=='0' && jogo [2][1]=='0' ||
			jogo[0][2] =='0' && jogo [1][2]=='0' && jogo [2][2]=='0')
				{
					printf("\n Parabéns! O Jogador 1 ganhou\n");
					ganhou =1;
				}
				//alguém ganhou coluna - Jogador 2
					if (jogo[0][0] =='X' && jogo [1][0]=='X' && jogo [2][0]=='X' ||
			jogo[0][1] =='X' && jogo [1][1]=='X' && jogo [2][1]=='X' ||
			jogo[0][2] =='X' && jogo [1][2]=='X' && jogo [2][2]=='X')
				{
					printf("\n Parabéns! O Jogador 2 ganhou\n");
					ganhou =1;
				}	
				//alguém ganhou diagonal principal - Jogador 1
				if (jogo [0][0]=='0' && jogo[1][1]=='0' && jogo [2][2]=='0')
				{
				   printf("\n Parabéns! O Jogador 1 ganhou\n");
				   ganhou =1;
				}
				//alguém ganhou diagonal principal - Jogador 2
				if (jogo [0][0]=='X' && jogo[1][1]=='X' && jogo [2][2]=='X')
				{
				   printf("\n Parabéns! O Jogador 2 ganhou\n");
				   ganhou =1;
				}
				//alguém ganhou diagonal secudária - Jogador 1 
				if (jogo[0][2]=='0'&& jogo[1][1]=='0' && jogo[2][0]=='0')
				{
				   printf("\n Parabéns! O Jogador 1 ganhou\n");
				   ganhou =1;
				}
				//alguém ganhou diagonal secudária - Jogador 2
				if (jogo[0][2]=='X'&& jogo[1][1]=='X' && jogo[2][0]=='X')
				{
					printf("\n Parabéns! O Jogador 2 ganhou\n");
					ganhou =1;
				}
			 }
			 
			 while (ganhou == 0 && jogadas <9); 
			 { //enquanto ainda ninguém tiver ganho e exitirem 9 jogadas disponíveis o programa continuará a ser executado
			 	
			 	if (ganhou ==0 )
				{
			 		printf("\nO jogo finalizou sem vencedores!\n "); /*se a variável ganhou se mantiver com o valor 0 o jogo finaliza sem vencedores*/
				}
				 
				printf("\nSe pretende jogar novamente clique na tecla 1\n ");
				scanf("%d", &opcao); //input do valor da variável opcao
			 }	
		}
		while(opcao==1);  //quando o jogador selecionar a tecla 1 o programa será executado novamente	
		
		return 0; //fim da execução do programa e o mesmo encontra-se sem erros
	}
	

