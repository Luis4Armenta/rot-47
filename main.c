//  Librerias del compilaodr
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//  Librerias de personalizadas
#include "./libraries/file-system/fsystem.h"
#include "./libraries/encoder/encoder-rot47.h"

//  declaración de tipos y defines
#define MAXCHARS 200
typedef char String[MAXCHARS];

//  Prototipo de funciones
void print_menu();
void encode_process(char *text_to_encode);
void decode_process(char *text_to_decode);

int main(int argc, char const *argv[]) {
  while (true) {
    int option;
    String text;

    print_menu(); // Imprime el menú
    
    // Leyendo opción ingresada por el usuario
    print_menu("Digita el número de opción: ");
    scanf("%d", &option);

    system("clear");  //  Limpiando pantala

    switch (option) {
      case 1:
        // Código a ejecutar en caso de seleccionar "cifrar".
        encode_process(text); // proceso de cifrado
        printf("\n\nPresiona una tecla para continuar...");
        getchar();  // Espera a que se presione una tecla para continuar

      break;
      case 2:
        // Código a ejecutar en caso de seleccionar "descifrar"
        decode_process(text); //  Proceso de descifrado
        printf("\n\nPresiona una tecla para continuar...");
        getchar();  // Espera a que se presione una tecla para continuar
      break;
      case 3:
        //  Cierre del programa en caso de seleccionar "Salir"
        exit(0);
      break;
      default:
        // En caso de introducir número diferente mostrar esto
        printf("\n\nPor favor digita una opción valida...");
        getchar(); // Espera a que se presione una tecla para continuar
      break;
    }
  }
  return 0;
}

void print_menu() {
  system("clear");  // Limpiando la terminal
  //  Imprimiendo partes de menú
  printf("1) Cifrar.\n");
  printf("2) Decifrar.\n");
  printf("3) Salir.\n");
}

void encode_process(char *text_to_encode) {
  String output = "";

  // obteniendo texto a cifrar
  ungetc('\0', stdin);
  printf("Escibe el texto a cifrar: ");
  fgets(text_to_encode, MAXCHARS, stdin);
  scanf("%[^\n]%*c", text_to_encode);
  
  // cifrando texto
  strcat(output, encode(text_to_encode));
  printf("Texto cifrado: %s\n ", output);

  // Guardando texto cirando en salida.txt
  save_in_file("salida.txt", output);
}

void decode_process(char *text_to_decode) {
  String output = "";

  // Obeniendo texto a descifrar
  ungetc('\0', stdin);
  printf("Escibe texto a decifrar: ");
  fgets(text_to_decode, MAXCHARS, stdin);
  scanf("%[^\n]%*c", text_to_decode);
      
  // Descifrando texto 
  strcat(output, encode(text_to_decode));
  printf("Texto cifrado: %s\n ", output);

  // Guardando texto descifrado en salida.txt
  save_in_file("salida.txt", output);
}
