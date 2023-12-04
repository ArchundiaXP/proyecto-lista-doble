#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Estudiante {
    char nombre[MAX_SIZE];
    char apellidoPaterno[MAX_SIZE];
    char apellidoMaterno[MAX_SIZE];
    char numCuenta[MAX_SIZE];
};

/*
Nombre: guardarCSV
fecha: 03/12/2023
Objetivo: Guardar los datos de la lista en un archivo CSV llamado "registro.csv"
*/
void guardarCSV(pNodo P) {
    FILE *archivo;
    char *nombreArchivo = "registro.csv";

    archivo = fopen(nombreArchivo, "a+"); // Abre el archivo en modo lectura y escritura, crea el archivo si no existe ("a+")

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    // Verifica si el archivo está vacío
    fseek(archivo, 0, SEEK_END); // Se coloca al final del archivo
    if (ftell(archivo) == 0) { // Comprueba la posición actual para determinar si el archivo está vacío
        // Si el archivo está vacío, escribe los encabezados
        fprintf(archivo, "ID Viaje, Hora Registro, ID Chofer, Nombre Chofer, Apellido Paterno, Apellido Materno, Num Unidad, Lugar Salida, Lugar Llegada, Hora Salida, Hora Llegada\n");
    }

    // Regresa al inicio del archivo
    fseek(archivo, 0, SEEK_SET);

    // Escribe los datos de la lista en el archivo CSV
    while (P != NULL) {
        fprintf(archivo, "%d, %s, %d, %s, %s, %s, %d, %s, %s, %s, %s\n", P->idViaje, P->hrRegistro, P->idChofer, P->nombreChofer, P->apellidoP, P->apellidoM, P->numUnidad, P->lugarSalida, P->lugarLlegada, P->horaSalida, P->horaLlegada);
        P = P->siguiente;
    }

    fclose(archivo); // Cierra el archivo después de escribir los datos
    printf("Datos guardados correctamente en %s.\n", nombreArchivo);
}



int main() {
    struct Estudiante estudiante;
    FILE *archivo;
    char nombreArchivo[] = "alumnos.csv"; // Nombre fijo del archivo

    // Verificar si el archivo existe
    if ((archivo = fopen(nombreArchivo, "r")) != NULL) {
        fclose(archivo);
        printf("El archivo %s ya existe. Se abrirá para agregar datos.\n", nombreArchivo);
        archivo = fopen(nombreArchivo, "a"); // Abrir en modo 'append' para añadir datos al final del archivo
    } else {
        printf("El archivo %s no existía. Se ha creado y está listo para guardar datos.\n", nombreArchivo);
        archivo = fopen(nombreArchivo, "w"); // Crear un nuevo archivo si no existe
        fprintf(archivo, "Nombre,Apellido Paterno,Apellido Materno,Numero de Cuenta\n"); // Escribir la cabecera
    }

    if (archivo == NULL) {
        printf("Error al abrir/crear el archivo.");
        return 1;
    }

    // Solicitar al usuario ingresar los datos del estudiante
    printf("Ingrese el nombre: ");
    scanf("%s", estudiante.nombre);

    printf("Ingrese el apellido paterno: ");
    scanf("%s", estudiante.apellidoPaterno);

    printf("Ingrese el apellido materno: ");
    scanf("%s", estudiante.apellidoMaterno);

    printf("Ingrese el número de cuenta: ");
    scanf("%s", estudiante.numCuenta);

    // Escribir los datos del estudiante en el archivo CSV
    fprintf(archivo, "%s,%s,%s,%s\n", estudiante.nombre, estudiante.apellidoPaterno, estudiante.apellidoMaterno, estudiante.numCuenta);

    printf("Datos guardados exitosamente en el archivo %s\n", nombreArchivo);

    fclose(archivo);

    return 0;
}
