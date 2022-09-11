
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define RESERVAR_MAS 1

int main()
{
    int *int_dyn_arr;
    
    int tam_inicial;
    int incremento;
    bool globalopc = true;
    
    do{
        
        int opcion;
    printf("-------------------------\n");
    printf("Leonardo, ingresa la opcion a usar:\n");
    printf("-------------------------\n");
    printf("1) Hacer uso solo realloc\n");
    printf("2) Hacer uso adiciona con memstet\n");
    printf("3) Salir\n");
    scanf("%d",&opcion);
   

   switch(opcion) {
      case 1 :
         printf("Haciendo uso unicamente de realloc!\n" );
        
        //Se solicita y guarda tamaño inicial 
        printf("Ingrese el tamaño inicial\n");
        scanf("%d", &tam_inicial);
        
       //Se valida si el arreglo no es null
        if (int_dyn_arr != NULL){
            
             //Se reserva espacio en memoria en bytes
            int_dyn_arr = (int *)malloc(tam_inicial * sizeof(int));
            printf("-----------------------------------------------------\n");
            printf("Se ha reservado correctamente el tamaño del bloque\ntamaño: %d\n", tam_inicial);
            printf("-----------------------------------------------------\n");
            
            int sel = RESERVAR_MAS;
            int aumento_reserva = tam_inicial;
            
            do{
                printf("¿Desea agregar más espacio?\n");
		        printf("1) Si.\n");
		        printf("2) No.\n");
		        scanf("%d", &sel);
		        
		        if (sel == RESERVAR_MAS){
		        printf("¿Cuantos elementos desea agregar?\n");
			    scanf("%d", &incremento);
			    
			    aumento_reserva += incremento;
			    
			    printf("\n------------------------------------------------\n");
			    printf("Incremento vale: %d.\n", incremento);
			    printf("El tamaño del arreglo actual es de: %d.\n", aumento_reserva);
			    printf("------------------------------------------------\n\n");
		        
		        //Reasigno el peso en bytes
                int_dyn_arr = (int *)realloc(int_dyn_arr, aumento_reserva * sizeof(int));    
		        }
		        
            }while(sel == RESERVAR_MAS);
    
            tam_inicial = 0;
            incremento = 0;
            sel = RESERVAR_MAS;
            free(int_dyn_arr);
            
        }else{
            printf("No se ha podido reservar la memoria\n");
        }
        
         
         break;
      case 2 :
         printf("Haciendo uso de malloc y memset.\n" );
         
         //Se solicita y guarda tamaño inicial 
        printf("Ingrese el tamaño inicial\n");
        scanf("%d", &tam_inicial);	
         
          if (int_dyn_arr != NULL){
              
              //Se reserva espacio en memoria en bytes
            int_dyn_arr = (int *)malloc(tam_inicial * sizeof(int));
            printf("-----------------------------------------------------\n");
            printf("Se ha reservado correctamente el tamaño del bloque\ntamaño: %d\n", tam_inicial);
            printf("-----------------------------------------------------\n");
            
            int sel = RESERVAR_MAS;
            int aumento_reserva = tam_inicial;
            
            do{
                printf("¿Desea agregar más espacio?\n");
		        printf("1) Si.\n");
		        printf("2) No.\n");
		        scanf("%d", &sel);
                
                if (sel == RESERVAR_MAS){
				    printf("¿Cuantos elementos desea agregar?\n");
					scanf("%d", &incremento);
					
					aumento_reserva += incremento;
					
					printf("\n------------------------------------------------\n");
					printf("Incremento vale: %d.\n", incremento);
					printf("El tamaño del arreglo actual es de: %d.\n", aumento_reserva);
					printf("------------------------------------------------\n\n");
				    
				    //Reasigno el peso en bytes
                	int_dyn_arr = (int *)realloc(int_dyn_arr, aumento_reserva * sizeof(int));  
				    
				    //Uso de memset
				    int_dyn_arr = (int *)memset(int_dyn_arr, 1, sizeof(int_dyn_arr));
		        
		        }
		        
                
            }while(sel == RESERVAR_MAS);
            free(int_dyn_arr);
            tam_inicial = 0;
            incremento = 0;
            sel = 0;        
          }
         break;
      case 4 :
         globalopc = false;
         printf("Hasta luego\n" );
         return 0;
         break;
      default :
         printf("Seleccione una opcion valida.\n" );
   }
      
}while (globalopc);
    
    
    
}

