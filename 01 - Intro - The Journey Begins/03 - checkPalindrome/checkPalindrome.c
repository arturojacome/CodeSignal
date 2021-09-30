#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TAM_MAX 100000

//Prototype Function
bool pruebapalindromo(char *);

//Functions
bool pruebapalindromo(char *Palabra)
{
	int Tam = (strlen(Palabra)) - 1;
	int Inicio = 0, Final = Tam;


	while (Inicio < Final && Palabra[Inicio] == Palabra[Final])
	{
		Inicio++;
		Final--;
	};

	if(Inicio >= Final)
	{
		printf("SiOY");
		//return true;
		
	}
	else
	{
		printf("No soy");
		//return false;
	}



}

//Principal Function
int main()
{

	//Decalramos el caracter de tipo apuntador
	char *Palabra1 = NULL;
	//Reservamos memoria para la cadena de caracteres [10^5]
	Palabra1 = (char*)malloc(sizeof(char)*TAM_MAX);
	//Instrucciones
	printf("Introdusca la cadena [Palabra 1]:");
	//
	//fgets(Palabra1, TAM_MAX, stdin);

	char Palabra2[] = "OSO";

	
	pruebapalindromo(Palabra2);
	pruebapalindromo("OSO");
	pruebapalindromo("OSO");
	pruebapalindromo("OSO\n");



	return 0;
}
