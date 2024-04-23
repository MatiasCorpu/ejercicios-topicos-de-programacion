#ifndef UNIDAD1_H
#define UNIDAD1_H

#include <stdio.h>
#include <stdbool.h>

#define ERROR_MATH -1


int factorial(int num);
int conbinatorio(int m , int n);
double calcularEx(int x, double TOL);
double raizCuadrada(double A, double TOL);
int fibonacci(int n);
bool perteneceSerieFibonacci(int num);
double seno(double x, double TOL);
char* esPerfectoDeficienteOAbundante(int num);
float productoPorSumasSucesivas(float n1, float n2);
void cocienteYrestoDivision(int n1, int n2, int* cociente, int* resto);
int sumaNnumerosNaturales(int n);
int sumaParesMenoresAnumero(int n);
bool esPrimo(int n);

#endif // UNIDAD1_H
