#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 10


typedef struct arr_integer
{
  int size;
  int *arr;
}arr_integer;



arr_integer alloc_arr_integer(int len)
{
  arr_integer a = {len, len > 0 ? malloc(sizeof(int) * len) : NULL};
  return a;
}

int makeArrayConsecutive2(arr_integer sequence)
{
  int inicio,final,aux,extraer,i,verificador;

  printf("Arreglo Original:");
  for (int i = 0; i < sequence.size; i++)
  {
    printf("%d,",sequence.arr[i]);
  }
  printf("\n");

  inicio = sequence.arr[0];
  final = sequence.arr[sequence.size-1];
  i = 1;
  verificador = 0;
  printf("%d",final);
  printf("\n");
  printf("%d",inicio);
  printf("\n");
  //Primero recorremos el arreglo hasta dar con el valor que no cumpla la condicion a < b
  do
  {
    //Caso 0: Cuando el arreglo solo tiene 1 elemento
    if (sequence.size <= 1)
    {
      break;
    }
    //Caso 1: El primero evita que sea estrictamente creciente
    else if (sequence.arr[0] > sequence.arr[1] || sequence.arr[0] == sequence.arr[1] )
    {
      aux = sequence.arr[0];
      for (int j = 0; j < sequence.size - 1 ; j++)
      {
        sequence.arr[j] = sequence.arr[j+1];
      }
      sequence.arr[sequence.size-1] = aux;
      sequence.size--;
      verificador++;
      i = 0;

    }
    //Caso 2: El ultimo evita que sea estrictamente creciente
    else if (sequence.arr[sequence.size - 2] > sequence.arr[sequence.size - 1] || sequence.arr[sequence.size - 2] == sequence.arr[sequence.size - 1] )
    {
      verificador++;
      sequence.size--;
      i = 0;
    }
    //Caso 3: Alguno de enmedio evita que sea estrictamente creciente
    else if (sequence.arr[i] > sequence.arr[i+1] || sequence.arr[i] == sequence.arr[i+1])
    {
      if (sequence.arr[i] < sequence.arr[i+2])
      {
        verificador++;
        aux = sequence.arr[i+1];
        for (int j = i+1; j < sequence.size - 1 ; j++)
        {
          sequence.arr[j] = sequence.arr[j+1];
        }
        sequence.arr[sequence.size-1] = aux;
        sequence.size--;
        i = 0;
      }
      else
      {
        aux = sequence.arr[i];
        for (int j = i; j < sequence.size - 1 ; j++)
        {
          sequence.arr[j] = sequence.arr[j+1];
        }
        sequence.arr[sequence.size-1] = aux;
        sequence.size--;
        i = 0;
        verificador++;
      }
    }
    else
    {
      i++;
    }
  }while(i < sequence.size - 1);


  printf("Arreglo nuevo:");
  for (int i = 0; i < sequence.size; i++)
  {
    printf("%d,",sequence.arr[i]);
  }

  printf("\n");

  if (verificador <= 1)
  {
    printf("True\n");
  }
  else
  {
    printf("False\n");
  }


}

int main(int argc, char const *argv[])
{

  int len, maxProducto;

  printf("Ingrese la cantidad de numeros del arreglo:");
  scanf("%d",&len);

  arr_integer Array = alloc_arr_integer(len);

  for (int i = 0; i < len; i++)
  {
    scanf("%d",&Array.arr[i]);
  }

  maxProducto = makeArrayConsecutive2(Array);

  return 0;
}
