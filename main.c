#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define PREMIS 1807


//NOS FALTA COMENTAR CADA FUNCION PK SI NO NOS BAJA NOTA


struct premio_loteria{
	char nombre[20];
	float importe;
    int numero;
    
};

int submenu_ver_premios();
void inicializar(struct premio_loteria premios[PREMIS],int nums[PREMIS+1]);
int menu();
void generar_sorteo(struct premio_loteria premios[PREMIS],int nums[PREMIS+1]);
int generar_boleto(struct premio_loteria premios[PREMIS]);
int generar_premio(struct premio_loteria premios[PREMIS],int nums[PREMIS+1]);
void mostrar_premios(struct premio_loteria premios[PREMIS], int pedreas, int mostrar_grans_premis);
void guardar_premio(int N,int P,struct premio_loteria premios[PREMIS]);
int llegirDecim(struct premio_loteria premios[PREMIS]);
void imprimir_premi(char nombre[20], float import);



int main(){
	
	struct premio_loteria premios[PREMIS];
    int opc, opc2, nums[PREMIS+1];
    
    //inicializar
	inicializar(premios,nums);

   //MENU
 
	do{
		opc=menu();
		switch (opc){
				case 1: generar_sorteo(premios,nums);
						break;
				case 2: do{
							opc2 = submenu_ver_premios();
							switch (opc2){
								case 1: mostrar_premios(premios, 10, 1);
										break;
								case 2: mostrar_premios(premios, 0, 1);
										break;
								case 0: break;
								
								default: printf("La opcion introducida no es correcta");
										break;
							
							}
						}while (opc2!=0);
						
						break;
				case 3: llegirDecim(premios);
						break;
				case 0: printf("\n  El programa ha terminado");
						break;
				default:printf("\n Opcion incorrecta! Prueba otra vez\n");
						break;
		}
    }while(opc!=0);
	
	/*if(premiat==1){
		printf("Te ha tocado");	
	}*/
	
    return 0;
}

int submenu_ver_premios(){
	int opc;
	printf("\n   SUBMENU VER PREMIOS\n");
	printf("--------------------------\n");
	printf("1. Ver los premios grandes y las 10 primeras pedreas\n");
	printf("2. Ver solo los premios grandes \n");
	printf("0. Salir\n");
	printf("Opcio: ");
	scanf("%d", &opc);
	printf("\n");
	
	
	return opc;
}

void inicializar(struct premio_loteria premios[PREMIS],int nums[1808]){

	srand(time(NULL));

	strcpy(premios[0].nombre,"Gordo");
	premios[0].importe = 4000000;
	premios[0].numero = -1;
	imprimir_premi(premios[0].nombre, premios[0].importe);

	strcpy(premios[1].nombre,"Segundo Premio");
	premios[1].importe = 1250000;
	premios[1].numero = -1;
	
	imprimir_premi(premios[1].nombre, premios[1].importe);

	strcpy(premios[2].nombre,"Tercer Premio");
	premios[2].importe = 500000;
	premios[2].numero = -1;
	imprimir_premi(premios[2].nombre, premios[2].importe);

	for(int i=3; i<5;i++){
		strcpy(premios[i].nombre,"Cuarto Premio");
		premios[i].importe = 200000;
		premios[i].numero = -1;
	}
	
	imprimir_premi(premios[3].nombre, premios[3].importe);
 
	for(int i=5; i<13;i++){
		strcpy(premios[i].nombre,"Quinto Premio");
		premios[i].importe = 60000;
		premios[i].numero = -1;
	}
	
	imprimir_premi(premios[5].nombre, premios[5].importe);
 
	for(int i=13; i<PREMIS;i++){
		strcpy(premios[i].nombre,"Pedrea ");
		premios[i].importe = 1000;
		premios[i].numero = -1;
	}
	
	imprimir_premi(premios[14].nombre, premios[14].importe);
 
	for(int i=0; i<PREMIS+1; i++){
		nums[i]=i;
	}
}

void imprimir_premi(char nombre[20], float import){
	printf("NOMBRE: %s\n   IMPORTE: %.2f€\n", nombre, import);
}

int menu(){
    int opcion;

  printf("\n ------MENU------");
  printf("\n 1. Iniciar Sorteo");
  printf("\n 2. Mostrar Premios");
  printf("\n 3. Encontrar premi");
  printf("\n 0. Salir");
  printf("\n Opcion: ");
  scanf("%d", &opcion);

    return opcion;
}

void generar_sorteo(struct premio_loteria premios[PREMIS],int nums[PREMIS+1] ){
	
	int N,P;
	
	for(int i=0;i<PREMIS;i++){
		N=generar_boleto(premios);
		P=generar_premio(premios,nums);
		guardar_premio(N,P,premios);
	}	
}

int generar_boleto(struct premio_loteria premios[PREMIS]){

	int i,num,existe=0;
	
	do{
		num=rand() % 100000;
		existe=0;
		for(i=0;i<PREMIS;i++){
				if(premios[i].numero == num) existe=1;
		}
	}while(existe==1);
	
	return num;
}
  
int generar_premio(struct premio_loteria premios[PREMIS],int nums[PREMIS+1] ){
	
	int pos,aux;	

	pos=rand() % nums[PREMIS];
	aux=nums[pos];
	nums[pos]=nums[nums[PREMIS]-1];
	nums[PREMIS]-=1;
		
    return aux;
}

void mostrar_premios(struct premio_loteria premios[PREMIS], int pedreas, int mostrar_grans_premis){
	int i=0;
	if (mostrar_grans_premis == 0) i=13;
	
    while(i<13+pedreas){
        printf("NOMBRE: %s\n   NUMERO: %d\n    IMPORTE: %.2f€ \n\n", premios[i].nombre, premios[i].numero, premios[i].importe);
        i++;
    }
}

void guardar_premio(int N,int P,struct premio_loteria premios[PREMIS]){
	
	premios[P].numero=N;
	
}

int llegirDecim(struct premio_loteria premios[PREMIS]){

	int decim,premiat=0;

		printf("Introdueix el numero de decim: ");
		scanf("%d", &decim);

	for(int i=0;i<PREMIS;i++){
			if(decim == premios[i].numero){
				premiat=1;
				printf("Te ha tocado!!");
				printf("\n\nNOMBRE: %s\n   NUMERO: %d\n    IMPORTE: %.2f€\n\n", premios[i].nombre, premios[i].numero, premios[i].importe);
			} 
	}
	if (premiat==0) printf("Este numero no tiene premio\n");
	
	//else printf("No te ha tocado ningun premio");
	return premiat;
}




