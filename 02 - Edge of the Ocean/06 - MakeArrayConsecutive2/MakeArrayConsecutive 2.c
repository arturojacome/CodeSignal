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

int makeArrayConsecutive2(arr_integer statues)
{

  //Primero buscamos el mayor y el menor numero del array.
  int mayorArr,menorArr,sizenewArr,result;

  mayorArr = statues.arr[0];
  menorArr = statues.arr[0];

  //Buscamos el mayor
  for (int i = 0; i < statues.size; i++)
  {
    if (mayorArr < statues.arr[i])
    {
      mayorArr = statues.arr[i];
    }
  }

  //Buscamos el menor
  for (int i = 0; i < statues.size; i++)
  {
    if (menorArr > statues.arr[i])
    {
      menorArr = statues.arr[i];
    }
  }

  //Cantidad de numeros desde el menor hasta el mayor
  sizenewArr = (mayorArr - menorArr) + 1;

  result = sizenewArr - statues.size;

  printf("\n%d",result );
  printf("El mayor numero del arrreglo es: %d\n",mayorArr);
  printf("El menor numero del arrreglo es: %d\n",menorArr);

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

  printf("%d",maxProducto);

  return 0;
}
