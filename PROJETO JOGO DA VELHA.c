/* JOGO DA VELHA - EM LINGUAGEM C 
   PROJETO DE FINAL DE SEMANA. DATA DE INICIO DA APLICAÇÃO: 02/04/15 ÁS 9:54
                              DATA DE TÉRMINO DA APLICAÇÃO: 02/04/15 ÁS 15:54
   autor do projeto: @lucasfirmino
   formação: cursando bacharelado em sistemas de informação
*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define size 3
//função para informar as instruções do jogo
void instrucoes(){
	printf("o jogador 1 ficara com o simbolo x\n");
	printf("o jogador 2 ficara com o simbolo o\n");
	printf("o primeiro que conseguir fazer uma sequencia de 3 simbolos ganha.\n");
	printf("COMO JOGAR?\n\n");
	printf("voce deve colocar as cordenadas da linha e da coluna, respctivamente para que sua jogada seja efetuada.");
	printf("Coloque a numero da linha, espaco e depois o numero da coluna.");
	printf("exemplo: 2 3\n\n");
}
// limpando a matriz do tabuleiro
void limparTab(char tab[][size]){
	int linha, coluna;
	for(linha=0;linha<size;linha++){
		for(coluna=0;coluna<size;coluna++){
			tab[linha][coluna] = ' ';
		}
	}
}
//função para apresentar a matriz que representa o tabuleiro do jogo
void tabuleiro(char tab[][size]){
	int x=0, linha, coluna;
	printf(" 1 2 3\n");//simplesmente serve para mostrar aos jogadores o número dass colunas e das linhas envolta da matriz
	for(linha=0;linha<size;linha++){
		for(coluna=0;coluna<size;coluna++){
			printf("%2c",tab[linha][coluna]);
		}printf(" %d\n",++x);
	}
}
//função que insere o carctere no tabuleiro de acordo com a escolha do jogador
void jogada(int linha, int coluna, char tab[][size], int player){	
	if(player==1){
		if((tab[linha-1][coluna-1]!='x')&&(tab[linha-1][coluna-1]!='o')){
			tab[linha-1][coluna-1] = 'x';	
		}
		else
			printf("ESSA POSICAO JA FOI PREENCHIDA...\n");
	}else{
		if((tab[linha-1][coluna-1]!='x')&&(tab[linha-1][coluna-1]!='o')){
			tab[linha-1][coluna-1] = 'o';	
		}
		else
			printf("ESSA POSICAO JA FOI PREENCHIDA...\n");
	}
	
}
//função para o jogador inserir as coordenadas onde será colocado o simbolo correspondente
void escolherCord(int player, char tab[][size]){
	int linha, coluna;
	if(player==1)
		printf("JOGADOR 1: ");
	else
		printf("JOGADOR 2: ");
		
	scanf("%d %d",&linha, &coluna);
	jogada(linha, coluna, tab, player);
	tabuleiro(tab);
}
//função que faz as verificações se algum jogador ja ganhou ou não
void verificaResultado(char tab[][size], int *vencedor, int *play1, int *play2){
	int aux1=0, aux2=0, coluna, linha;
	// 1° bloco de for verifica os resultados possiveis na horizontal
	for(linha=0;linha<size;linha++){
		for(coluna=0;coluna<size;coluna++){
			if(tab[linha][coluna]=='x'){
				aux1++;
			}else if(tab[linha][coluna]=='o'){
				aux2++;
			}
		}//fim do for
		if(aux1==3){
			*vencedor = 1;
			printf(" JOGADOR 1 VENCEU...\n");
			*play1+= 1;
			break;
		}if(aux2==3){
			*vencedor = 1;
			printf(" JOGADOR 2 VENCEU...\n");
			*play2+= 1;
			break;
		}aux1 = 0; aux2 = 0;
	}
	// 2° bloco de for verifica os resultados possiveis na vertical
	
	for(coluna=0;coluna<size;coluna++){
		for(linha=0;linha<size;linha++){
			if(tab[linha][coluna]=='x'){
				aux1++;
			}else if(tab[linha][coluna]=='o'){
				aux2++;
			}
		}if(aux1==3){
			*vencedor = 1;
			printf(" JOGADOR 1 VENCEU...\n");
			*play1+=1;
			break;
		}if(aux2==3){
			*vencedor = 1;
			printf(" JOGADOR 2 VENCEU...\n");
			*play2+=1;
			break;
		}aux1 = 0; aux2 = 0;
	}
		// 3° bloco de for verifica os resultados possiveis na diagonal principal
	for(linha=0;linha<size;linha++){
		for(coluna=0;coluna<size;coluna++){
			if(linha==coluna){
				if(tab[linha][coluna]=='x'){
					aux1++;
				}else if(tab[linha][coluna]=='o'){
					aux2++;
				}
			}
		}//fim do for
	
	}//fim do for
	if(aux1==3){
		*vencedor = 1;
		printf(" JOGADOR 1 VENCEU...\n");
		*play1+=1;
	}if(aux2==3){
		*vencedor = 1;
		printf(" JOGADOR 2 VENCEU...\n");
		*play2+=1;
	}aux1 = 0; aux2 = 0;
		// 4° bloco de for verifica os resultados possiveis na diagonal secundaria
	for(linha=0;linha<size;linha++){
		for(coluna=0;coluna<size;coluna++){
			if(linha+coluna==size-1){
				if(tab[linha][coluna]=='x'){
					aux1++;
				}else if(tab[linha][coluna]=='o'){
					aux2++;
				}
			}
		}//fim do for
	
	}//fim do for
	if(aux1==3){
		*vencedor = 1;
		printf(" JOGADOR 1 VENCEU...\n");
		*play1+=1;
	}if(aux2==3){
		*vencedor = 1;
		printf(" JOGADOR 2 VENCEU...\n");
		*play2+=1;
	}aux1 = 0; aux2 = 0;
}
//função para testar se não houve vencedores
int teste(char tab[][size]){
	int boolean, linha, coluna;
	for(linha=0;linha<size;linha++){
		for(coluna=0;coluna<size;coluna++){
			if(tab[linha][coluna]!=' '){
				boolean = 1;
			}else{
				boolean = 0;
				break;
			}
		}	
		if(boolean==0)
			break;
	}
	if(boolean==1)
		return(boolean);
	
}
//função onde o jogo roda
void game(char tab[][size], int *play1, int *play2){
	int player, vencedor=0,cont=0;
	while(vencedor==0){
		
		if(cont%2==0)
			player = 1;
		else
			player = 2;
		escolherCord(player, tab);

		verificaResultado(tab, &vencedor, play1, play2);
		cont++;
		if((teste(tab)==1)&&(vencedor==0)){
			printf("NAO HOUVE VENCEDORES...\n\n\n");
			break;
		}	
	}
	printf("PLACAR\njogador 1: %d\njogador 2: %d",*play1, *play2);
}
main(){
	int  linha, coluna, player,play1=0, play2=0, op=1, vencedor=0, cont=0;
	char tab_main[size][size], tabu[size][size];

	instrucoes();
	limparTab(tab_main);
	tabuleiro(tab_main);
	printf("pressione ENTER  para iniciar o jogo\n\n");
	getch();
	while(op==1){
		game(tab_main, &play1, &play2);
		
		printf("\n\ndeseja jogar novamente?\n 1-SIM    2-NAO");
		scanf("%d",&op);
		if(op==1)
			limparTab(tab_main);
		system("cls");
	}
	system("pause");
}













































