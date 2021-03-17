#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define PREMIS 1807

struct premio_loteria{
    int numero;
    char nombre[20];
    float importe;
};
struct premio_loteria premios[1806];

void inicializar(premios){

   srand(time(NULL));

   strcpy(premios[0].nombre,"Gordo");
   premios[0].importe = 4000000;
   premios[0].numero = -1;

   strcpy(premios[1].nombre,"Segundo Premio");
   premios[1].importe = 1250000;
   premios[1].numero = -1;

   strcpy(premios[2].nombre,"Tercer Premio");
   premios[2].importe = 500000;
   premios[2].numero = -1;

   for(int i=3; i<5;i++){
       strcpy(premios[i].nombre,"Cuarto Premio");
       premios[i].importe = 200000;
       premios[i].numero = -1;
   }

   for(int i=5; i<14;i++){
       strcpy(premios[i].nombre,"Quinto Premio ");
       premios[i].importe = 60000;
       premios[i].numero = -1;
   }

   for(int i=14; i<1806;i++){
       strcpy(premios[i].nombre,"Pedrea ");
       premios[i].importe = 1000;
       premios[i].numeroBOMBO1 = -1;
   }
}

int generar_boleto(){
   int bombo1;

   bombo1=rand() % 100000;
    //printf("%d) %d \n", i+1, bombo1[i]);

   return bombo1;
}

int generar_premio(){
   int bombo2[PREMIS];

   for(int i=0; i<PREMIS; i++){
        bombo2[i]=rand() % 1807;
        printf("%d) %d \n", i+1, bombo2[i]);
    }
}
void guardar_premios(N,P,premios){




}

void menu(){
    int opcion;

  printf("\n ------MENU------");
  printf("\n 1. Mostrar Premios.");
  printf("\n 2. Iniciar Sorteo");
  printf("\n 3. Encontrar premi");
  printf("\n 0. Salir");
  printf("\n Opcio: ");
  scanf("%d", &opcion);

    return opcion;
}

void generar_sorteo(struct premios){
   int N,P;

   for(int i=0;i<1807;i++){
       N=generar_boleto(premios);
       P=generar_premio(premios);
       guardar_premios(N,P,premios);
   }

}

int main(){
    int opc;
    //inicializar
   inicializar(premios);

   //MENU
   opc=menu();

   switch (opc){
       case 1: mostrarPremi();
                break;
       case 2: generar_sorteo();
               break;
       case 3: llegirDecim();
               break;
       case 0: printf("\n  El programa s'ha acabat");
               break;
       default:printf("\n Opcion incorrecta !!!ERROR!!!");
               break;
    }

    // 1r bombo: 100.000 boles [00000 - 99999]
//    generarNums_1bombo();
//
//    // 2n bombo premis: 1807 boles [0000 - 1807]
//    generarNums_bomboPremis();
//
//
//  */ //leer numero de decimo
//   */ leerNum();
//
//   *///mostrar el premi
//   mostrarPremi(); //mostrar mensaje tanto si tiene premio como si no

    return 0;
}


