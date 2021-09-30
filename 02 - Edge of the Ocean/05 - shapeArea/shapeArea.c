#include "stdlib.h"
#include "stdio.h"

int main(int argc, char const *argv[])
{

  int n,size,incrementador,resultado;

  printf("Ingrese el numero:");
  scanf("%d",&n);

  size = n + (n-1); //Cantidad de numeros que se sumaran
  printf("Tamaño:d%\n",size );
  incrementador = 1;
  resultado = 0;

  while (incrementador < size)
  {
    printf("Incrementador: %d\n",incrementador );
    resultado = resultado + incrementador;
    incrementador = incrementador + 2;
  }

  printf("Incrementador: %d\n",incrementador );
  resultado = resultado + incrementador;

  while (incrementador > 1)
  {
    incrementador = incrementador - 2;
    printf("Incrementador: %d\n",incrementador);
    resultado = resultado + incrementador;
  }

  printf("%d",resultado);

  return 0;
}
