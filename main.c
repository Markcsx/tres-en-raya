#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void bucle(int graella[3][3]);
void inicialitzaMatriu(int graella[3][3]);
void imprimeix(int graella[3][3]);
int estaPlena(int graella[3][3], int fila, int columna);
void introdueix(int graella[3][3], int fila, int columna, int jugador);
int comprovaGuanyat(int graella[3][3], int jugador);
int taules(int graella[3][3]);
int comprovaHorizon(int graella[3][3], int jugador);
int comprovaVertic(int graella[3][3], int jugador);
int comprovaDiagonalUn(int graella[3][3], int jugador);
int comprovaDiagonalDos(int graella[3][3], int jugador);
	
int main(){
	setlocale(LC_ALL,"");
	int graella[3][3];
	bucle(graella); //Esta función llama a las principales y refresca la pantalla
	system("pause");
	return 0;
}
void bucle(int graella[3][3]){
	inicialitzaMatriu(graella);
	int Fi, fila, columna, jugador;
	char continuar;
	Fi = 0;
	jugador = 1;
	do {	
			system("cls");
			imprimeix(graella);
			printf("\nEs turno del jugador %d \n", jugador);
			do {
				printf("En qué fila (1 a 3): ");
				fflush(stdin);
	            scanf("%d",&fila);
	        }while (fila > 3);

	        do {
	            printf ("En qué columna (1 a 3): ");
				fflush(stdin);
	            scanf("%d",&columna);
	        }while (columna > 3);

		if(fila != 0 && columna != 0){
			if(estaPlena(graella,fila,columna) != 1){
				introdueix(graella, fila, columna, jugador);
				system("cls");
				imprimeix(graella);
				if(comprovaGuanyat(graella, jugador) != 0){
					printf("Jugador %d has guanyat!\n", jugador);
					printf("Nova partida?(S o s): ");
					fflush(stdin);
					scanf("%c", &continuar);
					if(continuar == 's' || continuar == 'S'){
						inicialitzaMatriu(graella);
						imprimeix(graella);
					} else {
						Fi = 1;
					}
				}else if(taules(graella) != 0){
					printf("Heu empatat!\n");
					printf("Nova partida?(S o s): ");
					fflush(stdin);
					scanf("%c", &continuar);
					if(continuar == 's' || continuar == 'S'){
						inicialitzaMatriu(graella);
						imprimeix(graella);
					} else {
						Fi = 1;
					}
				}else {
					if (jugador == 1){
						jugador = 2;
					} else {
						jugador = 1;
					}
				}
			} else {
				printf("\nPosició plena!\n");
			}
		}else{
			Fi = 1;
		}
	}while(Fi == 0);
	printf("\nGracias por jugar!\n");
}


void inicialitzaMatriu(int graella[3][3]){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			graella[i][j]=0;
		}
	}
}


void imprimeix(int graella[3][3]){
	int i, j;
	printf("\n");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			if(graella[i][j]==0){
				if(j<2){
					printf("  #  |");
				} else {
					printf("  #  ");
				}
			} else if (graella[i][j]==1){
				_textcolor(4);
				printf("  #  ");
				_textcolor(7);
				printf("|");
			} else if (graella[i][j]==2){
				_textcolor(2);
				printf("  #  ");
				_textcolor(7);
				printf("|");
			}
		}
		_textcolor(7);
		if(i<2){
			printf("\n-----------------\n");
		}
	}
	
	printf("\n");
}


void introdueix(int graella[3][3], int fila, int columna, int jugador){
	graella[fila - 1][columna - 1] = jugador;
}


int estaPlena(int graella[3][3], int fila, int columna){
	int flag = 0;
	if (graella[fila - 1][columna - 1] != 0) {
		flag = 1; 
	}
	return flag;
}


int comprovaGuanyat(int graella[3][3], int jugador){

	if (comprovaVertic(graella, jugador) == 1){
		return 1;
	}
	if (comprovaHorizon(graella, jugador) == 1){
		return 1;
	}
	if (comprovaDiagonalUn(graella,jugador) == 1){
		return 1;
	}if (comprovaDiagonalDos(graella,jugador) == 1){
		return 1;
	}
	return 0;
}
	
int comprovaHorizon(int graella[3][3], int jugador){
	int j = 0; int i = 0; int comptador = 0;
	while(i<3 && comptador!=3){
		if(j==3 && i<3){
			j=0;
			i++;
			comptador=0;
		}
		if(graella[i][j]==jugador){
			comptador++;
		}
		j++;
	}
	if(comptador==3){
		comptador=1;
	}else{
		comptador=0;
	}
	return comptador;
}

int comprovaVertic(int graella[3][3], int jugador){
	int j = 0; int i = 0; int comptador = 0;
	while(j<3 && comptador!=3){
		if(i==3 && j<3){
			i=0;
			j++;
			comptador=0;
		}
		if(graella[i][j]==jugador){
			comptador++;
		}
		i++;
	}
	if(comptador==3){
		comptador=1;
	}else{
		comptador=0;
	}
	return comptador;
}

int comprovaDiagonalUn(int graella[3][3], int jugador){
	int j = 0; int i = 0; int comptador = 0;
	while(i<3 && j<3 && comptador!=3){
		if(graella[i][j] == jugador){
			comptador++;
		}
		i++;
		j++;
	}
	if(comptador==3){
		comptador=1;
	}else{
		comptador=0;
	}
	return comptador;
}

int comprovaDiagonalDos(int graella[3][3], int jugador){
	int j = 2; int i = 0; int comptador = 0;
	while(i<3 && j<3 && comptador!=3){
		if(graella[i][j] == jugador){
			comptador++;
		}
		i++;
		j--;
	}
	if(comptador==3){
		comptador=1;
	}else{
		comptador=0;
	}
	return comptador;
}

int taules(int graella[3][3]){
	int flag;
	flag = 1;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if(graella[i][j] == 0){
				flag = 0;
			}
		}
	}
	return flag;
}


