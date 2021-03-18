#include <stdio.h>
#include <cs50.h>
#include <stdbool.h>

#include "lista.h"

bool insertar(string palabra);
void recorrer();
int hash_function(string palabra);
bool buscar(string palabra);

nodo *hashtable[27];

int main(void)
{
    int opcion = 0;

    do{
        opcion = get_int("Presione 1 para insertar, 2 para mostrar,3 para buscar y 5 para salir.");
        switch(opcion)
        {
            case 1:
                insertar(get_string("Ingrese una palabra: "));
                break;
            case 2:
                recorrer();
                break;
            case 3:
                if(buscar(get_string("Ingrese la palabra a buscar: ")))
                {
                    printf("Elemento encontrado.\n");
                }
                else{
                    printf("Elemento no encontrado.\n");
                }

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
        printf("\nEstá vacío\n");
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

bool buscar(string palabra)
{
    int hash_buscado = hash_function(palabra);
    if(hashtable[hash_buscado])
    {
        nodo *temp = hashtable[hash_buscado];


        while(temp)
        {
            if(strcmp(palabra, temp->palabra) == 0)
            {
                return true;
            }
            temp = temp->siguiente;
        }
        return false;

    }// si hashtable[hash_buscado] == NULL
    else
    {
       return false;
    }
}

int hash_function(string palabra)
{
    int hash =(toupper(palabra[0]) - 'A') % 27;
    return hash;
}