// Incluye la biblioteca Serial para imprimir en el monitor serial
#define EEPROM_SIZE 64
#include <EEPROM.h>

 // Definir el tamaño de la matriz (3x3 en este caso)
//int filas = 31;
//int columnas = 2;

//////////-Prog/Esc/Col-///////////////////////////////////////////////////////////////////////
int matrizProgramacion [4] [32] [2] = {//Programa guardado en EPROM o MicroSD  
                            { // Programa 1
                              {0b00000000000000000000000000000000, 0},      // ***Inicio de Programa****
                              {0b10010010010000100100000000000000, 10000},  // ***Escenario 1***
                              {0b00100100110000110000000000000000, 10000},  // ***Escenario 2***
                              {0b00100110000110000100000000000000, 12000},  // ***Escenario 3***  
                              {0b11111111111111111111111111111111, 0},      // ***Fin de Programa****
                            }, 
                            { // Programa 2
                              {0b00000000000000000000000000000000, 0},      // ***Inicio de Programa****
                              {0b10010010010000100100000000000000, 10000},  // ***Escenario 1***
                              {0b00100100110000110000000000000000, 10000},  // ***Escenario 2***
                              {0b00100110000110000100000000000000, 10000},  // ***Escenario 3***
                              {0b11111111111111111111111111111111, 0},      // ***Fin de Programa****
                            },
                            { // Programa 3
                              {0b00000000000000000000000000000000, 0},      // ***Inicio de Programa****
                              {0b10010010010000100100000000000000, 10000},  // ***Escenario 1***
                              {0b00100100110000110000000000000000, 10000},  // ***Escenario 2***
                              {0b00100110000110000100000000000000, 20000},  // ***Escenario 3***
                              {0b11111111111111111111111111111111, 0},      // ***Fin de Programa****
                            }, 
                            { // Programa 4
                              {0b00000000000000000000000000000000, 0},      // ***Inicio de Programa****
                              {0b10010010010000100100000000000000, 10000},  // ***Escenario 1***
                              {0b00100100110000110000000000000000, 10000},  // ***Escenario 2***
                              {0b00100110000110000100000000000000, 20000},  // ***Escenario 3***
                              {0b11111111111111111111111111111111, 0},      // ***Fin de Programa****
                            } 
                          };

unsigned long prog00[10][2] = {// Programa solo Escenarios
                            {0b00000000000000000000000000000000, 0},      // ***Inicio de Programa - Configuración***

                            {0b10010010010000100100000000000000, 10000},  // ***Escenario 1***

                            {0b00100100110000110000000000000000, 10000},  // ***Escenario 2*** 

                            {0b00100110000110000100000000000000, 12000},  // ***Escenario 3***
                              
                            {0b11111111111111111111111111111111, 0} 	  // ***Fin de Programa**
};

int filas = sizeof(prog00) / sizeof(prog00[0]);
int columnas = sizeof(prog00[0]) / sizeof(prog00[0][0]);

unsigned long matrizEjecucion[31][2] = {// Programa Completo
                            {0b00000000000000000000000000000000, 0},      // ***Inicio de Programa***

                            {0b10010010010000100100000000000000, 10000},  // ***Escenario 1***
                            {0b00000000010000100100000000000000, 375},    // Transición de Verde a Ambar
                            {0b10010010010000100100000000000000, 375},    // Transición de Verde a Ambar
                            {0b00000000010000100100000000000000, 375},    // Transición de Verde a Ambar
                            {0b10010010010000100100000000000000, 375},    // Transición de Verde a Ambar
                            {0b00000000010000100100000000000000, 375},    // Transición de Verde a Ambar
                            {0b10010010010000100100000000000000, 375},    // Transición de Verde a Ambar
                            {0b00000000010000100100000000000000, 375},    // Transición de Verde a Ambar
                            {0b10010010010000100100000000000000, 375},    // Transición de Verde a Ambar
                            {0b01001001010000100100000000000000, 3000},   // Tiempo de ambar  

                            {0b00100100110000110000000000000000, 10000}, // ***Escenario 2***
                            {0b00100100100000100000000000000000, 375}, // Transición de Verde a Ambar
                            {0b00100100110000110000000000000000, 375}, // Transición de Verde a Ambar
                            {0b00100100100000100000000000000000, 375}, // Transición de Verde a Ambar
                            {0b00100100110000110000000000000000, 375}, // Transición de Verde a Ambar
                            {0b00100100100000100000000000000000, 375}, // Transición de Verde a Ambar
                            {0b00100100110000110000000000000000, 375}, // Transición de Verde a Ambar
                            {0b00100100100000100000000000000000, 375}, // Transición de Verde a Ambar
                            {0b00100100110000110000000000000000, 375}, // Transición de Verde a Ambar
                            {0b00100100101000101000000000000000, 3000}, // Tiempo de ambar  

                            {0b00100110000110000100000000000000, 12000}, // ***Escenario 3***
                            {0b00100110000100000100000000000000, 375}, // Transición de Verde a Ambar
                            {0b00100110000110000100000000000000, 375}, // Transición de Verde a Ambar
                            {0b00100110000100000100000000000000, 375}, // Transición de Verde a Ambar
                            {0b00100110000110000100000000000000, 375}, // Transición de Verde a Ambar
                            {0b00100110000100000100000000000000, 375}, // Transición de Verde a Ambar
                            {0b00100110000110000100000000000000, 375}, // Transición de Verde a Ambar
                            {0b00100110000100000100000000000000, 375}, // Transición de Verde a Ambar
                            {0b00100110000110000100000000000000, 375}, // Transición de Verde a Ambar
                            {0b00100110000101000100000000000000, 3000}  // Tiempo de ambar  
};

// Definición de Matrices de prueba
unsigned long miMatriz[31][2];// = {0};
unsigned long miMatriz2[31][2];// = {0};

// Declaración de la funciones
void generarMatrizAleatoria(unsigned long *matriz, int *filas, int *columnas);
void imprimirMatriz(unsigned long *matriz, int *filas, int *columnas);
void escribirMatrizEnEEPROM(unsigned long* matriz, int *filas, int *columnas);
void leerMatrizDesdeEEPROM(unsigned long* matriz, int *filas, int *columnas);
int* revisionMatrizProgramacion(unsigned long* matriz, int *filas, int *columnas);

void setup() {
  EEPROM.begin(EEPROM_SIZE);
  // Inicializa el monitor serial
  Serial.begin(115200);
   int* filasColumnas = revisionMatrizProgramacion(&prog00[0][0],&filas, &columnas);
   
  // Genera una matriz aleatoria de tamaño filasXcolumnas
  generarMatrizAleatoria(&miMatriz[0][0], &filas, &columnas);
  // Guardar la matriz en la EEPROM
  escribirMatrizEnEEPROM(&prog00[0][0], &filasColumnas[0], &filasColumnas[1]);
  // Recuperar la matriz desde la EEPROM
  leerMatrizDesdeEEPROM(&miMatriz2[0][0], &filasColumnas[0], &filasColumnas[1]);
  // Llama a la función imprimirMatriz pasando la matriz y sus dimensiones como punteros
  imprimirMatriz(&miMatriz2[0][0], &filasColumnas[0], &filasColumnas[1]);
}

void loop() {
  // Llama a la función imprimirMatriz pasando la matriz y sus dimensiones como punteros
  //imprimirMatriz(&miMatriz2[0][0], &filas, &columnas);
  //delay(2000);
}

// Definición de la función generarMatrizAleatoria
void generarMatrizAleatoria(unsigned long *matriz, int *filas, int *columnas) {
  // Inicializa el generador de números aleatorios con una semilla
  randomSeed(analogRead(0));
  // Llena la matriz con números aleatorios
  for (int i = 0; i < *filas; i++) {
    for (int j = 0; j < *columnas; j++) {
      (*(matriz + i * (*columnas) + j)) = random(0, 101);  // Genera números aleatorios entre 0 y 100
    }
  }
}
// Definición de la función imprimirMatriz
void imprimirMatriz(unsigned long *matriz, int *filas, int *columnas) {

  Serial.println("Programa: ");
  Serial.println("Inicio de Programa:");
  // Recorrer las filas de la matriz
  for (int i = 0; i < *filas; i++) {
    Serial.print(i);
    Serial.print(" - ");
    // Recorrer las columnas de la matriz
    for (int j = 0; j < *columnas; j++) {
      // Imprimir el elemento en la posición (i, j) usando el puntero
      Serial.print(*(matriz + i * (*columnas) + j));
      Serial.print("\t");  // Tabulador para separar las columnas
    }
    // Imprimir un salto de línea al final de cada fila
    Serial.println();
  }
  Serial.println("Fin de Programa:");
}
// Definición de la función escribirMatrizEnEEPROM
void escribirMatrizEnEEPROM(unsigned long* matriz, int *filas, int *columnas) {
  int direccion = 0;  // Dirección inicial en la EEPROM

  for (int fila = 0; fila < *filas; fila++) {
    for (int columna = 0; columna < *columnas; columna++) {
      EEPROM.put(direccion, (* (matriz + fila * (*columnas) + columna)));
      direccion += sizeof(unsigned long);
    }
  }
}
// Definición de la función escribirMatrizEnEEPROM
void escribirMatriz3EnEEPROM(unsigned long* matriz, int *prog, int *esc, int *col) {
  int direccion = 0;  // Dirección inicial en la EEPROM

  for (int fila = 0; fila < *prog; fila++) {
    for (int columna = 0; columna < *esc; columna++) {
      for (int columna2 = 0; columna2 < *esc; columna2++) {
        EEPROM.put(direccion, (* (matriz + fila * (*esc) + columna) * (*col) + columna2));
        direccion += sizeof(unsigned long);
      }
    }
  }
}
// Definición de la función leerMatrizDesdeEEPROM
void leerMatrizDesdeEEPROM(unsigned long* matriz, int *filas, int *columnas) {
  int direccion = 0;  // Dirección inicial en la EEPROM

  for (int fila = 0; fila < *filas; fila++) {
    for (int columna = 0; columna < *columnas; columna++) {
      EEPROM.get(direccion, (* (matriz + fila * (*columnas) + columna)));
      direccion += sizeof(unsigned long);
    }
  }
}
// Definición de la función de revisión de matriz de programación
int* revisionMatrizProgramacion(unsigned long* matriz, int *filas, int *columnas) {
  static int arreglo[2];
  // Recorrer las filas de la matriz
  for (int i = 0; i < *filas; i++) {
    // Recorrer las columnas de la matriz
    for (int j = 0; j < *columnas; j++) {
      if ((*(matriz + i * (*columnas) + j)) == 4294967295 && (*(matriz + i * (*columnas) + j + 1)) == 0) {
        Serial.print("No. de filas de Programa: ");
        Serial.println(i+1);
        // Asigna valores aleatorios a los elementos del arreglo
        arreglo[0] = ++i;
        arreglo[1] = *columnas;
        // Retorna el arreglo
        return arreglo;
      }
      
    }
  }
}