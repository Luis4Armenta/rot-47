/*
* ENCODER-ROT47
* Este encoder funciona gracias a la capacidad de C
* para adminitr números como caracetes y viceversa.
*
* En el cifrado utilizamos la capacidad anteriormente
* mencionada para cifrar nuestros textos por medio de
* simples sumás y codiciones.
*
* Los caracteres imprimibles van desde el 32 al 126,
* por lo que nuestro programa solo se movera entre
* ese rango.
**/

// Header de la libreria
#include "encoder-rot47.h"

// Constantes
#define MAXCHARS 200  // Número máximo de caracteres
#define SUSTITUCION_NUMBER 47 // Recorrido
#define MIN_ASCII_CODE 32 // threshold de visibilidad minimo
#define MAX_ASCII_CODE 126  // 

// Funcion para cifrar textos
char *encode(char *text) {
  // Declaración de variables
  char *text_encoded = malloc (sizeof (char) * MAXCHARS);
  memset(text_encoded, 0, sizeof (char) * MAXCHARS);

  // Cifrado de cada uno de los caracteres por separado
  for (int i = 0; i < strlen(text); i++) {
    // Almacenamiento del code de cada caracter
    int letter_code = text[i];
    int letter_code_encoded;

    if (letter_code == MIN_ASCII_CODE) {
      // No procesa los espacios   
      letter_code_encoded = MIN_ASCII_CODE; // 32 -> " "
    } else if ((letter_code + SUSTITUCION_NUMBER) > MAX_ASCII_CODE) {
      // Procesa el caracter cuando al sumarle 47 pasa 126
      int aux = MAX_ASCII_CODE - letter_code;
      letter_code_encoded = MIN_ASCII_CODE + (SUSTITUCION_NUMBER - aux);
    } else {
      // si la adición de 47 al code del caracter no pasa 126 solo da la suma
      letter_code_encoded = letter_code + SUSTITUCION_NUMBER;
    }

    // creando cadena de texto cifrado.
    char strAux[2] = {letter_code_encoded, '\0'};
    strcat(text_encoded, strAux);
  }
  
  return text_encoded;
}

/*
* Con base en que para descifrar el código en cifrado
* ROT-47 lo único que debemos hacer es recifrarlo,
* basta con llamar de nuevo la función de cifrar.
*/
char *decode(char *text_encoded) {
  return encode(text_encoded);
} 