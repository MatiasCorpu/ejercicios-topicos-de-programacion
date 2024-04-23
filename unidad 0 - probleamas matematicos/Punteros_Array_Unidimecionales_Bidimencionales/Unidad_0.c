/*
Ejercicios 1/13 ejercicios sin punteros, relacionado con math:


1. El factorial de un número natural incluido el 0  ->  N. (N - 1)!
2. m! / [n! * (m - n)!]
3. Dado un número entero X y una tolerancia (TOL)
4. Desarrollar una función para determinar si un entero pertenece a la serie de Fibonacci
5. Desarrollar una función para determinar si un entero pertenece a la serie de Fibonacci
6. seno (x) con suma de terminos en serie
7. Clasificación de número naturales:  perfecto, deficiente o abundante
8. Dados dos números naturales (incluido el cero), obtener su producto por sumas sucesivas.
9. Dados dos números naturales A y B, desarrollar una función para obtener el cociente entero A/B y el resto. (A puede ser 0; B, no).
10 y 11. Construir un programa que lea un número natural N y calcule la suma de los primeros N números naturales.
12. Construir un programa que lea un número natural N y calcule la suma de los números pares menores
que N.
13.Desarrollar una función que determine si un número natural es primo.
*/

#include <stdio.h>
#include "Unidad_0.h"

int factorial(int num)
{
    if (num < 0)
        return ERROR_MATH;

    if (num == 0)
        return 1;

    int resultado = 1;

    for (int i = num; i > 0; i--)
        resultado *= i;

    return resultado;
}

int conbinatorio(int m, int n)
{
    if (m < n || n < 0)
        return ERROR_MATH;

    return (factorial(m) / (factorial(n) * factorial(m - n)));
}

double calcularEx(int x, double TOL)
{
    double termino = 1.0;
    double resultado = 1.0;

    int n = 1;

    while (TOL <= termino)
    {
        termino *= (double)x / n;
        resultado += termino;
        n++;
    }

    return resultado;
}

double raizCuadrada(double A, double TOL)
{
    double xn = A * 0.5;
    double xn1;

    do
    {
        xn1 = xn;
        xn = 0.5 * (xn + A / xn);
    } while ((xn1 - xn) >= TOL);

    return xn;
}

bool perteneceSerieFibonacci(int num)
{
    int n = 0;
    int resultFibo;

    do
    {
        n++;
        resultFibo = fibonacci(n);
    } while (resultFibo < num);

    if (resultFibo == num)
        return true;

    return false;
}

int fibonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

double seno(double x, double TOL) {
    double termino = x;
    double resultado = termino;

    int signoNegativo = -1;
    int signo = signoNegativo;

    int n = 3;

    while (termino >= TOL) {
        termino *= (x * x) / ((n - 1) * n);
        resultado += (signo * termino);
        signo *= signoNegativo;
        n += 2;
    }

    return resultado;
}

char* esPerfectoDeficienteOAbundante(int num)
{
    if(num <= 0)
        return "Error: Entrada no válida";

    int suma = 1;

    for(int i = 2; i < num / 2; i++)
        if(num % i == 0)
            suma += i;

    if (suma == num)
        return "Perfecto";

    else if(suma < num)
            return "Deficiente";
        else
        return "Abundante";
}

float productoPorSumasSucesivas(float n1, float n2)
{
    if(n1 == 0 || n2 == 0)
        return 0;

    float result = 0;

    for(int i = 0; i < n1 ; i++)
        result += n2;

    return result;
}

void cocienteYrestoDivision(int n1, int n2, int* cociente, int* resto)
{
    *cociente = 0;

    if(n2 != 0)
        while ( n1 >= n2)
        {
            n1 -= n2;
            (*cociente)++;
        }

    *resto = n1;
}

int sumaNnumerosNaturales(int n)
{
    int suma = 0;
    int acumulador = 0;

    while (acumulador < n)
    {
        acumulador++;
        suma += acumulador;
    }

    return suma;
}

int sumaParesMenoresAnumero(int n)
{
    int suma = 0;

    for (int i = 2; i < n; i += 2)
        suma+=i;

    return suma;
}

bool esPrimo(int n)
{
    if( n <= 1)
        return false;

    for(int i = 2; i < n; i ++)
        if(n % i == 0)
            return false;

    return true;
}
