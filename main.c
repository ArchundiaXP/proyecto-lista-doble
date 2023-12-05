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

/*-*-*-*-*-*-*-*-*-*-*-*-*Funciones De La Estrcuctura De Datos-*-*-*-*-*-*-*-*-*-* */

/*
Nombre:imprimeMenu
fecha: 01/12/2023
objetivo: imprimir el menu de opciones del programa
*/
void imprimeMenu(){
    printf("\t--Central De Autobuses Del Norte--\n\n");

    printf("1.- Crear lista\n");
    printf("2.-Crear Final\n");
    printf("3.-Recorrer Iterativo\n");
    printf("4.-Recorrer Iterativo Inverso\n");
    printf("5.-Recorrer Recursivo\n");
    printf("6.-Recorrer Recursivo Inverso\n");
    printf("7.-Insertar nuevo registro\n");
    printf("8.-Insertar nuevo registro antes de otro registro\n");
    printf("9.-Eliminar primer registro\n");
    printf("10.-Eliminar ultimo registro\n");
    printf("11.-Eliminar registro especifico\n");
    printf("12.-Buscar registro\n");
    printf("13.-Exportar registro a una tabla\n");
    printf("0.-Salir\n\n");

}


/*
Nombre: VeriEstado
fecha: 01/12/2023
Objetivo: verificar el estado de  la lista si esta vacia o ya cuenta con elementos en ella 
(nodos)
*/
int veriEstado(pNodo P) {
    if (P == NULL) {
        return TRUE; // La lista está vacía
    } else {
        return FALSE; // La lista contiene elementos
    }
}


/*
nombre: registraDatos
fecha: 28-11-2023
objetivo: solicita los datos que se guardaran en un nodo de la lista
*/
void registraDatos(pNodo *P){

    printf("Central De Autobuses Del Norte\n");
    printf("Registro de control de horarios  \n\n");

    printf("Ingrese los datos solicitados...\n");
    printf("ID del viaje: ");
    scanf("%d", &(*P)->idViaje);
    printf("id del chofer: ");
    scanf("%d", &(*P)->idChofer);
    printf("Nombre de conductor:");
    scanf(" %[^\n]", (*P)->nombreChofer);
    printf("Apellido Paterno: ");
    scanf("%s", (*P)->apellidoP);
    printf("Apellido Materno: ");
    scanf("%s", (*P)->apellidoM);
    printf("Numero de la unidad asignada: ");
    scanf("%d", &(*P)->numUnidad); 
    printf("Sucursal de partida: ");
    scanf(" %[^\n]", (*P)->lugarSalida); 
    printf("Hora de salida(00:00): ");
    scanf("%s", (*P)->horaSalida);
    printf("Sucursal a arribar : ");
    scanf(" %[^\n]", (*P)->lugarLlegada);
    printf("Hora de llegada estimada(00:00): ");
    scanf("%s", (*P)->horaLlegada);
    printf("\n----------------------------------------\n");
   
}

/*Nombre: imprimeNodo
Fecha: 01/12/2023
objetivo: imprime el nodo completo que se le solicita*/
void imprimeNodo(pNodo *P){
    printf("ID del viaje: %d\n", (*P)->idViaje);
    printf("Nombre de conductor: %s\n", (*P)->nombreChofer);
    printf("Apellido Paterno: %s\n", (*P)->apellidoP);
    printf("Apellido Materno: %s\n", (*P)->apellidoM);
    printf("Numero de la unidad asignada: %d\n", (*P)->numUnidad); 
    printf("Sucursal de partida: %s\n", (*P)->lugarSalida);
    printf("Hora de salida: %s\n", (*P)->horaSalida);
    printf("Sucursal a arribar : %s\n", (*P)->lugarLlegada);
    printf("Hora de llegada estimada: %s\n", (*P)->horaLlegada);
    printf("\n----------------------------------------\n\n");
}

/*--------------------------funciones de creacion----------------------------*/

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
    *P = (pNodo)malloc(sizeof(tNodo));
    registraDatos(P);

    (*P)->siguiente = NULL;
    (*P)->anterior = NULL;
    

    do{
        Q = (pNodo) malloc (sizeof(tNodo));
            
        registraDatos(&Q);

        Q->siguiente=*P;
        Q->anterior=NULL;
        (*P)->anterior=Q;
        
        *P=Q;
        

        printf("Desea agregar otro registro? (Y/N): ");
        scanf("%s", &opc);

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

        Q->siguiente=NULL;
        Q->anterior=*P;
        T->siguiente=Q;
        
        T=Q;

        printf("Desea agregar otro registro? (Y/N): ");
        scanf("%c", &opc);

    }while (opc == 'Y' || opc == 'y');

    printf("tarea (CF) completada correctamente\n");

}


/*---------------------------funciones recorrer------------------------------------*/

/*
nombre:recorrerIterativo
fecha: 01/12/2023
objetivo: recorrer Iterativamente la lista y mostrarla en pantalla
*/
void recorrerIterativo (pNodo P){
    pNodo Q;
    Q = P;
    
    system("cls");
    printf("\nmostrando lista de forma iterativa..\n\n");
    
	    while (Q != NULL) {
        imprimeNodo(&Q);
        Q = Q->siguiente;
    }

    printf("imprimi todo\n");
    system("pause");

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
    system("cls");
    do{
        imprimeNodo(&Q);
        Q=Q->anterior;

    	} while (Q != NULL);
        system("pause");
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
    
    system("pause");
}

/*--------------------------Funciones Insertar-----------------------------*/

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

        printf("\nRegistro insertado correctamente...\n");
        system("pause");
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
        X = (pNodo) malloc (sizeof(tNodo));
        registraDatos(&X);
        printf("\nRegistro insertado correctamente...\n");
    if (*P==Q){
        X->anterior=NULL;
        X->siguiente=*P;
        (*P)->anterior=X;
        *P=X;
    }else{
        T->siguiente=X;
        X->anterior=T;
        X->siguiente=Q;
        Q->anterior=X;
    }

    }else{
        printf("Registro no encontrado...\n");
    }
    system("pause");
}

/*-------------------------------Funciones eliminacion-------------------------*/

/*
Nombre: eliminarPrimero
fecha: 02/12/2023
objetivo: eliminar el primer registro de la lista
*/
void eliminarPrimero(pNodo *P){
    pNodo Q;
    Q=*P;

    system("cls");
    printf("Eliminando el primer registro de la lista...\n");

    if (Q->siguiente != NULL){
        *P=Q->siguiente;
    	(*P)->anterior=NULL;

    	}else{
    		*P=NULL;
    	}

    free(Q);
    printf("\nRegistro eliminado correctamente...\n");
    system("pause");
}

/*
NOmbre: eliminarUltimo
fecha: 02/12/2023
objetivo: eliminar el ultimo registro de la lista
*/
void eliminarUltimo(pNodo *P){
    pNodo Q,T;
    system("cls");

    printf("Eliminando el ultimo registro de la lista...\n");
    if ((*P)->siguiente==NULL){
    		free(P);
    		*P=NULL;
    	}else {
    		Q=*P;
    		while (Q->siguiente != NULL){
    			T=Q;
    			Q=Q->siguiente;
    		}
    		T->siguiente=NULL;
    		free(Q);
    	}
    printf("\nRegistro eliminado correctamente...\n");
    system("pause");
}

/*
NOMBRE: eliminarX
FECHA: 02/12/2023
OBJETIVO: eliminar un registro de la lista que se le indique
*/
void eliminarX(pNodo *P){
    pNodo Q, T;
    int NumRef;
    int BAND = TRUE;
    Q=*P;
    printf("\tEliminando un registro de la lista...\n\n");

    printf("Ingrese el  del empleado, unidad o viaje que desea dar de baja: ");
    scanf("%d", &NumRef);

     while ((Q->idChofer||Q->numUnidad||Q->idViaje)!= NumRef && BAND==TRUE){
		if (Q->siguiente != NULL){
			T=Q;
			Q=Q->siguiente;
		} else {
			BAND=FALSE;
		}
	}

    if (BAND==FALSE){
    		printf("El elemento no fue encontrado");
    	}else if(*P==Q){
           *P=Q->siguiente;
    		(*P)->anterior= NULL;

    	} else {
    		T->siguiente=Q->siguiente;
    		(Q->siguiente)->anterior=T;
    	}

    free(Q);
    printf("Registro eliminado correctamente...\n");
    system("pause");

}


/*
NOmbre:buscarRecursivo
fecha: 02/12/2023
objetivo: buscar un registro solicitado de la lista de forma recursiva
*/
void buscarRecursivo(pNodo P){
    int NumRef;
    printf("Ingrese el ID del empleado, unidad o viaje que desea buscar: ");
    scanf("%d", &NumRef);

    if(P != NULL){
        if(P->idChofer == NumRef || P->numUnidad == NumRef || P->idViaje == NumRef){
            printf("Registro encontrado...\n");
            imprimeNodo(&P);
        }else{
            buscarRecursivo(P->siguiente);
        }
    }else{
        printf("Registro no encontrado...\n");
    }
    system("pause");
}

/*///////////////////////////////FUNCIONES DE GESTION DE ARCHIVOS////////////////////////////*/

/*
Nombre: guardarCSV
fecha: 03/12/2023
Objetivo: Guardar los datos de la lista en un archivo CSV llamado "registro.csv"
*/
void guardarCSV(pNodo P) {
    FILE *archivo;
    archivo = fopen("registro.csv", "a+"); // Abre el archivo en modo de adición ("a+")

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.");
        return;
    }

    // Recorre hasta el final del archivo para escribir los datos
    fseek(archivo, 0, SEEK_END);

    while (P != NULL) {
        fprintf(archivo, "%d, %s, %d, %s, %s, %s, %d, %s, %s, %s, %s\n", P->idViaje, P->hrRegistro, P->idChofer, P->nombreChofer, P->apellidoP, P->apellidoM, P->numUnidad, P->lugarSalida, P->lugarLlegada, P->horaSalida, P->horaLlegada);
        P = P->siguiente;
    }

    fclose(archivo); // Cierra el archivo después de escribir los datos
    printf("Datos guardados correctamente en registro.csv.\n");
}





int main(){
    pNodo P = NULL;
    int X;
    int OPC = 0;

    do{
        system("cls");
        imprimeMenu();

        printf("Ingrese una opcion: ");
        scanf("%d", &OPC);

        switch(OPC){
            case 1:
                crearInicio(&P);
                break;
            case 2:
                crearFinal(&P);
                break;
            case 3:
                if(veriEstado(P)){
                    printf("La lista esta VACIA cree un registro antes...\n");
                    system("pause");
                }else{
                    recorrerIterativo(P);
                }
                break;
            case 4:
                if(veriEstado(P)){
                    printf("La lista esta VACIA cree un registro antes...\n");
                    system("pause");
                }else{
                    recorrerIterativoInverso(P);
                }
                break;
            case 5:
                if(veriEstado(P)){
                    printf("\nLa lista esta VACIA cree un registro antes...\n");
                    system("pause");
                }else{
                    system("cls");
                    recursivo(P);
                    system("pause");
                }
                break;
            case 6:
                if(veriEstado(P)){
                    printf("\nLa lista esta VACIA cree un registro antes...\n");
                    system("pause");
                }else{
                    system("cls");
                    recursivoInv(P);
                }
                break;
            case 7:
                if(veriEstado(P)){
                    printf("\nLa lista esta VACIA cree un registro antes...\n");
                    system("pause");
                }else{
                    insertarFinal(P);
                }
                break;
            case 8:
                if(veriEstado(P)){
                    printf("\nLa lista esta VACIA cree un registro antes...\n");
                    system("pause");
                }else{
                    insertarAntes(&P);
                }
                break;
            case 9:
                if(veriEstado(P)){
                    printf("\nLa lista esta VACIA cree un registro antes...\n");
                    system("pause");
                }else{
                    eliminarPrimero(&P);
                }
                break;
            case 10:
                if(veriEstado(P)){
                    printf("\nLa lista esta VACIA cree un registro antes...\n");
                    system("pause");
                }else{
                    eliminarUltimo(&P);
                }
                break;
            case 11:
                if(veriEstado(P)){
                    printf("\nLa lista esta VACIA cree un registro antes...\n");
                    system("pause");
                }else{
                    eliminarX(&P);
                }
                break;
            case 12:
                if(veriEstado(P)){
                    printf("\nLa lista esta VACIA cree un registro antes...\n");
                    system("pause");
                }else{
                    buscarRecursivo(P);
                }
                break;
            case 13:
                if(veriEstado(P)){
                    printf("\nLa lista esta VACIA cree un registro antes...\n");
                    system("pause");
                }else{
                    guardarCSV(P);
                }
                break;
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida...\n");
                break;
        }
        
    }while(OPC != 0);

    printf("\nNos vemos pronto super usuario...");
    system("pause");
    return 0;
}