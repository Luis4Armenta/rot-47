#include "fsystem.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// Función para salvar archivos
void save_in_file(char *fileName, char *content) {
  FILE *fp; // Puntero para archivo
  fp = fopen(fileName, "w");  // abriendo archivo

  // Revisando por errores a la hora de abrir el archivo
  if (fp == NULL) {
    printf("¡Ha ocurrido un error al intentar crear o escribir en el archivo!...\n");
    getchar();
    exit(1);
  }
  
  // Insertando contenido
  fputs(content, fp);
  fclose(fp);
  printf("\nLa salida ha sido guardada en: ./%s\n", fileName);
}