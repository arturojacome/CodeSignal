#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 10

typedef struct arr_integer
{
  int size;
  int *arr;
} arr_integer;

arr_integer alloc_arr_integer(int len)
{
  arr_integer a = {len, len > 0 ? malloc(sizeof(int) * len) : NULL};
  return a;
}

int adjacentElementsProduct(arr_integer inputArray)
{
  int maxProducto,Producto;
  maxProducto = inputArray.arr[0]*inputArray.arr[1];

  for (int i = 0; i < inputArray.size-1; i++)
  {
    Producto = inputArray.arr[i]*inputArray.arr[i+1];

    if (Producto > maxProducto)
    {
      maxProducto = Producto;
    }
  }

  return maxProducto;
}

int main(int argc, char const *argv[])
{

  int len, maxProducto;

  printf("Ingrese la cantidad de numeros del arreglo:");
  scanf("%d",&len);

  arr_integer Array = alloc_arr_integer(len);

  for (int i = 0; i < len; i++)
  {
    scanf("%d",&Array.arr[i].arr[j]);
  }

  maxProducto = adjacentElementsProduct(Array);

  printf("%d",maxProducto);

  return 0;
}
