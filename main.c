/*
Autor: Archundia
programa: sistema de control de horarios de transporte usando lista doble
fecha: 28-11-2023
descripcion: el programa es capas de:
*/

/*bibliotecas*/
#include <stdio.h>
#include <stdlib.h>


typedef struct nodo{
    int idViaje[10];
    char hrRegistro[20];
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
nombre: registraDatos
fecha: 28-11-2023
objetivo: solicita los datos que se guardaran en un nodo de la lista
*/
void registraDatos(pNodo *P){

    printf("Central De Autobuses Del Norte\n");
    printf("Registro de control de horarios - %s \n");

    printf("Ingrese los datos solicitados...\n");
    printf("ID del viaje: ");
    scanf("%d", &(*P)->idViaje);
    printf("Nombre de conductor:");
    scanf("%s", &(*P)->nombreChofer);
    printf("Apellido Paterno: ");
    scanf("%s", &(*P)->apellidoP);
    printf("Apellido Materno: ");
    scanf("%s", &(*P)->apellidoM);

    printf("\n");

    printf("Numero de la unidad asignada: ");
    scanf("%d", &(*P)->numUnidad); 
    printf("Sucursal de partida: ");
    scanf("%s", &(*P)->lugarSalida);
    printf("Hora de salida: ");
    scanf("%s", &(*P)->horaSalida);
    printf("Sucursal a arribar : ");
    scanf("%s", &(*P)->lugarLlegada);
    printf("Hora de llegada estimada: ");
    scanf("%s", &(*P)->horaLlegada);
   
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
void recorrerIterativo ()

int main(){


    return 0;
}