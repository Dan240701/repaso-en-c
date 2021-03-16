#include <stdio.h>
#include <cs50.h>

#include "lista.h"

bool insertar(string palabra);
void recorrer();
nodo *cabecera = NULL;

int main(void)
{
    int opcion;

    do{

        opcion = get_int("Presione 1 para insertar y 2 para mostrar y 5 para salir.");
        switch(opcion)
        {
            case 1:
                insertar(get_string("Ingrese una palabra: "));
                break;
            case 2:
                recorrer();
                break;
            case 5:
                printf("Gracias por usar el programa.");
                break;
            default:
                printf(" xd\n");
        }
    }while(opcion != 5);


    return 0;
}

bool insertar(string palabra)
{
    nodo *nuevo= malloc(sizeof(nodo));
    if(!nuevo)
    {
        return false;
    }
    nuevo->palabra = palabra;
    nuevo->siguiente = NULL;


    // cabecera es distinto de  NULL
    if(cabecera)
    {
        nuevo->siguiente = cabecera;
        cabecera = nuevo;
        return true;
    }
    // cabecera es  NULL
    else
    {
        cabecera = nuevo;
        return true;
    }
    return false;
}

void recorrer()
{
    nodo *temp = cabecera;
    while(temp)
    {
        printf("%s,",temp->palabra);
        temp = temp->siguiente;
    }
    printf("\n");
}