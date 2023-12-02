/*
Autor: Archundia
programa: sistema de control de horarios de transporte usando lista doble
fecha: 28-11-2023
descripcion: el programa es capas de:
*/

/*bibliotecas*/
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct nodo{
    int idViaje;
    char hrRegistro[20];
    int idChofer;
    char nombreChofer[20];
    char apellidoP[20];
    char apellidoM[20];

    int numUnidad;
    char lugarSalida[50];
    char lugarLlegada[50];
    char horaSalida[20];
    char horaLlegada[20]; 

    struct nodo *siguiente;
    struct nodo *anterior;
}tNodo;

typedef tNodo *pNodo;

/*-----------------Funciones De La Estrcuctura De Datos----------------------*/


/*
Nombre: VeriEstado
fecha: 01/12/2023
Objetivo: verificar el estado de  la lista si esta vacia o ya cuenta con elementos en ella 
(nodos)*/

int VeriEstado(pNodo *P){
    if(*P == NULL){
        return 1;
    }else{
        return 0;
    }
}


/*
nombre: registraDatos
fecha: 28-11-2023
objetivo: solicita los datos que se guardaran en un nodo de la lista
*/
void registraDatos(pNodo *P){

    printf("Central De Autobuses Del Norte\n");
    printf("Registro de control de horarios  \n");

    printf("Ingrese los datos solicitados...\n");
    printf("ID del viaje: ");
    scanf("%d", &(*P)->idViaje);
    printf("id del chofer: ");
    scanf("%d", &(*P)->idChofer);
    printf("Nombre de conductor:");
    scanf("%s", (*P)->nombreChofer);
    printf("Apellido Paterno: ");
    scanf("%s", (*P)->apellidoP);
    printf("Apellido Materno: ");
    scanf("%s", (*P)->apellidoM);

    printf("\n");

    printf("Numero de la unidad asignada: ");
    scanf("%d", &(*P)->numUnidad); 
    printf("Sucursal de partida: ");
    scanf("%s", (*P)->lugarSalida);
    printf("Hora de salida(00:00): ");
    scanf("%s", (*P)->horaSalida);
    printf("Sucursal a arribar : ");
    scanf("%s", (*P)->lugarLlegada);
    printf("Hora de llegada estimada(00:00): ");
    scanf("%s", (*P)->horaLlegada);
   
}

/*Nombre: imprimeNodo
Fecha: 01/12/2023
objetivo: imprime el nodo completo que se le solicita*/
void imprimeNodo(pNodo *P){
    printf("ID del viaje: %d\n", (*P)->idViaje);
    printf("Nombre de conductor: %s\n", (*P)->nombreChofer);
    printf("Apellido Paterno: %s\n", (*P)->apellidoP);
    printf("Apellido Materno: %s\n", (*P)->apellidoM);

    printf("\n");

    printf("Numero de la unidad asignada: %d\n", (*P)->numUnidad); 
    printf("Sucursal de partida: %s\n", (*P)->lugarSalida);
    printf("Hora de salida: %s\n", (*P)->horaSalida);
    printf("Sucursal a arribar : %s\n", (*P)->lugarLlegada);
    printf("Hora de llegada estimada: %s\n", (*P)->horaLlegada);
}

/*
nombre: crearInicio
fecha: 17-11-2023
objetivo: inicializar la lista
*/
void crearInicio (pNodo *P){
    pNodo Q;
    char opc;
    system("cls"); /*limpia la pantalla*/

    /*generamos nuevo nodo*/
    *P =(pNodo)malloc(sizeof(tNodo));
    registraDatos(P);

    (*P)->siguiente = NULL;
    (*P)->anterior = NULL;

    do{
            Q = (pNodo) malloc (sizeof(tNodo));
            registraDatos(&Q);

            Q->siguiente = *P;
            Q->anterior = NULL;

            (*P)-> siguiente = Q;
            *P = Q;

        printf("Desea agregar otro registro? (Y/N): ");
        scanf("%c", &opc);

    }while (opc == 'Y' || opc == 'y');
    
    printf("tarea (CI) completada correctamente\n");
}

/*
nombre: crearFinal
fecha: 17-11-2023
objetivo: generar registros al final de la lista

*/
void crearFinal (pNodo *P){
    pNodo Q, T;
    char opc;

    system("cls");
    *P = (pNodo) malloc (sizeof(tNodo));
    registraDatos(P);

    (*P)->siguiente = NULL;
    (*P)->anterior = NULL;
    T = *P;

    do{
        Q= (pNodo) malloc(sizeof(tNodo));
        registraDatos(&Q);

        Q->siguiente = NULL;
        Q->anterior = *P;
        T=Q;

        printf("Desea agregar otro registro? (Y/N): ");
        scanf("%c", &opc);

    }while (opc == 'Y' || opc == 'y');

    printf("tarea (CF) completada correctamente\n");

}

/*
nombre:
fecha: 01/12/2023
objetivo: 
*/
void recorrerIterativo (pNodo P){
    pNodo Q;
    Q = P;
    
    system("cls");
    printf("\nmostrando lista de forma iterativa..\n\n");
    
	    do {
            imprimeNodo(&Q);
		    Q=Q->siguiente;
	    } while (Q != NULL);

}


/*
Nombre: recorrerIterativoInverso
fecha: 01/12/2023
objetivo: recorrer la lista de manera iterativa pero inversamente*/
void recorrerIterativoInverso (pNodo P){
    pNodo Q;
    Q = P;

    printf("\nmostrando lista de forma iterativa inversa..\n\n"); 

    while (Q->siguiente != NULL){ /*bamos al final*/
    		Q=Q->siguiente;
    }

    do{
        imprimeNodo(&Q);
        Q=Q->anterior;

    	} while (Q != NULL);
}


/*
nombre: recursivo
fecha: 01/12/2023
objetivo: recorrer lalista y imprimirla de forma recursiva*/
void recursivo(pNodo P){
    if(P != NULL){
        printf("\nImprimiendo de manera recursiva...\n");
        imprimeNodo(&P);
        recursivo(P->siguiente);
    }
}


/*
nombre: recursivoInve
fecha: 01/12/2023
obejtivo: recorrer la lista de forma recursiva pero inversamente*/
void recursivoInv(pNodo P){
    pNodo Q;
	
	Q=P;
	while (Q->siguiente != NULL){
		Q=Q->siguiente;
	}
	
	do {
		imprimeNodo(&Q);

		Q=Q->anterior;
	} while (Q != NULL);
}


/*
nombre: insertarInicio
fecha: 01/12/2023
objetivo: insertar un nuevo noregistro al inicio de la lista
*/
void insertarFinal (pNodo P){
    system("cls");
    printf("Insertar registro al final de la lista\n");

    pNodo Q, T;
    T=P;

    while(T->siguiente != NULL){

        T=T->siguiente;
	    }

        Q = (pNodo) malloc (sizeof(tNodo));
        registraDatos(&Q);

        Q->siguiente=NULL;
        Q->anterior=T;
        T->siguiente=Q;
}

/*
NOMBRE : insertarAntes
FECHA : 02/12/2023
OBJETIVO : insertar un nuevo registro antes de un nodo que se le indique
*/
void insertarAntes (pNodo *P){

    pNodo Q, T, X;
    int NumRef;
    int BAND = TRUE;
    
    system("cls");

    printf("Insertar registro nuevo antes de un de ....\n");
    printf("Ingrese el ID ya sea del empleado, unidad o viaje: ");
    scanf("%d", &NumRef);


    Q=*P;

    while ((Q->idChofer||Q->numUnidad||Q->idViaje)!= NumRef && BAND==TRUE){
		if (Q->siguiente != NULL){
			T=Q;
			Q=Q->siguiente;
		} else {
			BAND=FALSE;
		}
	}

    if(BAND == FALSE){
        printf("Registro encontrado...\n");
        printf("Ingrese los datos solicitados...\n");

        Q = (pNodo) malloc (sizeof(tNodo));
        registraDatos(&Q);

        Q->siguiente = *P;
        Q->anterior = NULL;

        (*P)-> siguiente = Q;
        *P = Q;

    }
}




int main(){

    printf("codigo funcionando correctamente...");
    return 0;
}