#include <stdio.h>
#include <cs50.h>

#include "lista.h"

bool insertar(string palabra);
void recorrer();
int hash_function(string palabra);

nodo *hashtable[27];

int main(void)
{
    int opcion = 0;

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

                printf(" %d opcion valor\n", opcion);
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

    int hash =  hash_function(palabra);

    if(hashtable[hash])
    {
        nuevo->siguiente = hashtable[hash];
        hashtable[hash]= nuevo;
        return true;
    }
    else
    {
        hashtable[hash] = nuevo;
        return true;
    }

    return false;
}

void recorrer_lista(nodo *cabecera)
{
    nodo *temp = cabecera;
    if(!cabecera)
    {
        printf("Está vacío\n");
        return;
    }

    while(temp)
    {
        printf("%s,",temp->palabra);
        temp = temp->siguiente;
    }
    printf("\n");
}
void recorrer()
{
    for(int i = 0; i < 27; i++)
    {
        printf("--- Hash #%d---", i);
        recorrer_lista(hashtable[i]);
    }
}

int hash_function(string palabra)
{
    return (toupper(palabra[0]) - 'A') % 27;
}