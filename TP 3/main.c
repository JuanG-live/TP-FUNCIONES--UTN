#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void ingresarElementos (Pila* pilaOrigen);
void pasarElementos (Pila* pilaOrigen, Pila* pilaDada);
void pasarElementosOrdenados (Pila* pilaOrigen, Pila* PilaDada);
int menorElemento (Pila* pilaOriginal);
void pilaOrdenada (Pila* pilaOrigen, Pila* pilaOrdenada);
void insertarElemento (Pila* pilaOrigen, int elemento);
void ordenarPilaInsercion(Pila* pilaOriginal, Pila* pilaOrdenada);
int sumarDosElementos(Pila* pilaMain);
float promedio(Pila* pilaMain);
int sumar(Pila* pilaMain);
int cantidad(Pila* pilaMain);
void cargarPila(Pila* pilaMain);
int verPila(Pila* pilaMain);
float numeroDecimal(Pila* pilaMain);

int main()
{
    printf("-----------EJERCICIO 1-----------\n\n");
    Pila pila;
    inicpila(&pila);

    ingresarElementos(&pila);
    mostrar(&pila);

    printf("-----------EJERCICIO 2-----------\n\n");

    Pila pilaOrigenEjercicio2;
    Pila pilaDestinoEjercicio2;
    inicpila(&pilaOrigenEjercicio2);
    inicpila(&pilaDestinoEjercicio2);

    ingresarElementos(&pilaOrigenEjercicio2);
    printf("PILA ORIGINAL ES:\n");
    mostrar(&pilaOrigenEjercicio2);
    pasarElementos(&pilaOrigenEjercicio2, &pilaDestinoEjercicio2);
    printf("PILA DESTINO ES: \n");
    mostrar(&pilaDestinoEjercicio2);

    printf("-----------EJERCICIO 3-----------\n\n");

    Pila pilaOrigenEjercicio3;
    Pila pilaDestinoEjercicio3;

    inicpila(&pilaOrigenEjercicio3);
    inicpila(&pilaDestinoEjercicio3);

    ingresarElementos(&pilaOrigenEjercicio3);
    printf("PILA ORIGEN CARGADA POR EL USUARIO\n");
    mostrar(&pilaOrigenEjercicio3);

    pasarElementosOrdenados(&pilaOrigenEjercicio3, &pilaDestinoEjercicio3);
    printf("PILA ORDENADA EN DESTINO\n");
    mostrar(&pilaDestinoEjercicio3);

    printf("-----------EJERCICIO 4-----------\n\n");
    int nuevaVariable;

    Pila pilaOrigenEjercicio4;
    inicpila(&pilaOrigenEjercicio4);

    ingresarElementos(&pilaOrigenEjercicio4);
    printf("PILA ORIGEN CON SUS ELEMENTOS:\n");
    mostrar(&pilaOrigenEjercicio4);

    nuevaVariable = menorElemento(&pilaOrigenEjercicio4);
    printf("EL MENOR ELEMENTO DE LA PILA ES: %i \n\n ", nuevaVariable);

    printf("-----------EJERCICIO 5-----------\n\n");

    Pila pilaOrigenEjercicio5;
    Pila pilaOrdenadaEjercicio5;
    inicpila(&pilaOrdenadaEjercicio5);
    inicpila(&pilaOrigenEjercicio5);

    ingresarElementos(&pilaOrigenEjercicio5);
    printf("PILA ORIGEN CON SUS ELEMENTOS: \n");
    mostrar(&pilaOrigenEjercicio5);

    pilaOrdenada(&pilaOrigenEjercicio5, &pilaOrdenadaEjercicio5);
    printf("PILA ORDENADA");
    mostrar(&pilaOrdenadaEjercicio5);

    printf("-----------EJERCICIO 6-----------\n\n");

    Pila pilaOrigenEjercicio6;
    inicpila(&pilaOrigenEjercicio6);

    int valorInsertar;

    ingresarElementos(&pilaOrigenEjercicio6);
    printf("\nPILA INGRESADA POR EL USUARIO: \n");
    mostrar(&pilaOrigenEjercicio6);

    printf("Ingrese el valor para agregar a la pila: ");
    scanf("%i", &valorInsertar);

    insertarElemento(&pilaOrigenEjercicio6, valorInsertar);
    printf("PILA CON EL ELEMENTO INSERTADO");
    mostrar(&pilaOrigenEjercicio6);

    printf("-----------EJERCICIO 7-----------\n\n");

    Pila pilaOrigenEjercicio7, pilaOrdenadaEjercicio7;
    inicpila(&pilaOrigenEjercicio7);
    inicpila(&pilaOrdenadaEjercicio7);

    ingresarElementos(&pilaOrigenEjercicio7);
    printf("La pila Origen es: \n");
    mostrar(&pilaOrigenEjercicio7);

    printf("-----------EJERCICIO 8-----------\n\n");
    Pila ordenada;
    inicpila(&ordenada);
    sumarDosElementos(&ordenada);
    mostrar(&ordenada);
    printf(" LA SUMA DE LOS ELEMENTOS ES DE: %i\n\n", sumarDosElementos(&ordenada));

    printf("-----------EJERCICIO 9-----------\n\n");

    mostrar(&ordenada);
    promedio(&ordenada);
    printf("LA SUMA DE LOS ELEMENTOS DE LA PILA ES DE: %i\n", sumar(&ordenada));
    printf("\nLA CANTIDAD DE ELEMENTOS DE LA PILA ES DE: %i\n", cantidad(&ordenada));
    printf("\nEL PROMEDIO DE LOS ELEMENTOS DE LA PILA ES DE: %.2f\n\n", promedio(&ordenada));

    printf("-----------EJERCICIO 10-----------\n\n");
    Pila main;
    inicpila(&main);
    ingresarElementos(&main);
    mostrar(&main);
    numeroDecimal(&main);
    return 0;
}
//1. Hacer una función que permita ingresar varios elementos a una pila, tanto como quiera el
//usuario
void ingresarElementos (Pila* pilaOrigen)
{
    char opt;
    int valor;
    do
    {
        printf("Ingrese un numero para cargar elementos a la pila:\n");
        fflush(stdin);
        scanf("%i", &valor);
        apilar(pilaOrigen, valor);
        printf("Desea ingresar otro elemento? s/n \n");
        fflush(stdin);
        scanf("%c", &opt);
    }
    while (opt == 's' || opt == 'S');
}

//2. Hacer una función que pase todos los elementos de una pila a otra.
void pasarElementos(Pila* pilaOrigen, Pila* pilaDada)
{
    while(!pilavacia(pilaOrigen))
    {
        apilar(pilaDada, desapilar(pilaOrigen));
    }
}

//3. Hacer una función que pase todos los elementos de una pila a otra, pero conservando el orden.
void pasarElementosOrdenados (Pila* pilaOrigen, Pila* pilaDada)
{
    Pila aux;
    inicpila(&aux);

    while (!pilavacia(pilaOrigen))
    {
        apilar(&aux, desapilar(pilaOrigen));
    }
    while(!pilavacia(&aux))
    {
        apilar(pilaDada, desapilar(&aux));
    }
}
//4. Hacer una función que encuentre el menor elemento de una pila y lo retorna. La
//misma debe eliminar ese dato de la pila
int menorElemento (Pila* pilaOriginal)
{

    Pila aux, aux2;
    inicpila(&aux);
    inicpila(&aux2);

    apilar(&aux, desapilar(pilaOriginal));

    while(!pilavacia(pilaOriginal))
    {
        if(tope(pilaOriginal)>tope(&aux))
        {
            apilar(&aux2, desapilar(pilaOriginal));
        }
        else
        {
            apilar(&aux2, desapilar(&aux));
            apilar(&aux, desapilar(pilaOriginal));
        }

    }
    while(!pilavacia(&aux2))
    {
        apilar(pilaOriginal, desapilar(&aux2));
    }

    int menor = desapilar(&aux);

    return menor;
}
//5. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una
//nueva pila ordenada. Usar la función del ejercicio 4. (Ordenamiento por selección)
void pilaOrdenada (Pila* pilaOrigen, Pila* pilaOrdenada)
{
    while(!pilavacia(pilaOrigen))
    {
        apilar(pilaOrdenada, menorElemento(pilaOrigen));

    }
}

//6. Hacer una función que inserta en una pila ordenada un nuevo elemento, conservando el orden
//de ésta.
void insertarElemento (Pila* pilaOrigen, int elemento)
{
    Pila aux;
    inicpila(&aux);

    int flag = 0;
    while(!pilavacia (pilaOrigen)&& flag ==0)
    {
        if(elemento > tope(pilaOrigen))
        {
            apilar(pilaOrigen, elemento);
            flag = 1;
        }
        else
        {
            apilar(&aux, desapilar(pilaOrigen));
        }
    }
    if (flag == 0)
    {
        apilar(&aux, elemento);
    }
    while(!pilavacia(&aux))
    {
        apilar(pilaOrigen, desapilar(&aux));
    }

}
//7. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una
//nueva pila ordenada. Usar la función del ejercicio 6. (Ordenamiento por inserción)

void ordenarPilaInsercion(Pila* pilaOriginal, Pila* pilaOrdenada)
{
    Pila aux;
    inicpila(&aux);

    while (!pilavacia(pilaOriginal))
    {
        apilar(pilaOrdenada, insertarElemento);
    }
}
//8. Hacer una función que sume y retorne los dos primeros elementos de una pila (tope y anterior),
//sin alterar su contenido.**/
int sumarDosElementos(Pila* pilaMain)
{
    int suma=0;
    int count=0;
    Pila funcion8;
    inicpila(&funcion8);

    while(!pilavacia(pilaMain)&&count!=2)
    {
        suma = suma+tope(pilaMain);
        apilar(&funcion8, desapilar(pilaMain));
        count++;
    }
    while(!pilavacia(&funcion8))
    {
        apilar(pilaMain, desapilar(&funcion8));
    }
    return suma;
}
//9. Hacer una función que calcule el promedio de los elementos de una pila, para ello hacer también
//una función que calcule la suma, otra para la cuenta y otra que divida. En total son cuatro
//funciones, y la función que calcula el promedio invoca a las otras 3.
float promedio(Pila* pilaMain)
{
    float promedio;
    promedio = (float)sumar(pilaMain)/cantidad(pilaMain);
    return promedio;
}
int sumar(Pila* pilaMain)
{
    int suma=0;
    Pila auxSuma;
    inicpila(&auxSuma);
    while(!pilavacia(pilaMain))
    {
        suma=suma+tope(pilaMain);
        apilar(&auxSuma, desapilar(pilaMain));
    }
    while(!pilavacia(&auxSuma))
    {
        apilar(pilaMain, desapilar(&auxSuma));
    }
    return suma;
}
int cantidad(Pila* pilaMain)
{
    int elementos=0;
    Pila auxCant;
    inicpila(&auxCant);
    while(!pilavacia(pilaMain))
    {
        apilar(&auxCant, desapilar(pilaMain));
        elementos++;
    }
    while(!pilavacia(&auxCant))
    {
        apilar(pilaMain, desapilar(&auxCant));
    }
    return elementos;
}
//10. Hacer una función que reciba una pila con números de un solo dígito (es responsabilidad de
//quien usa el programa) y que transforme esos dígitos en un número decimal.
void cargarPila(Pila* pilaMain)
{
    char opt;
    int valor;
    do
    {
        printf(" INGRESE UN ELEMENTO: ");
        scanf("%i",&valor);
        apilar(pilaMain,valor);
        printf("\n DESEA CARGAR UN NUEVO ELEMENTO? Y/N: ");
        fflush(stdin);
        scanf("%c", &opt);
        printf("\n");
    }
    while(opt=='Y'||opt=='y');
}
int verPila(Pila* pilaMain)
{
    Pila funcion11;
    inicpila(&funcion11);
    {
        apilar(&funcion11, desapilar(&pilaMain));
        printf("| %d |", &funcion11);
    }
}
float numeroDecimal(Pila* pilaMain)
{
    float acc=0;
    float base;
    float digito=1;
    float number;
    Pila funcion10;
    inicpila(&funcion10);

    while(!pilavacia(pilaMain))
    {
        base=tope(pilaMain);
        number=base*digito;
        acc+=number;
        digito*=10;
        desapilar(pilaMain);
    }
    printf("\n EL NUMERO FORMADO POR LOS ELEMENTOS DE LA PILA ES: %.2f\n\n", acc);
    return acc;
}


