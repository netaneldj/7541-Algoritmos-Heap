#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"
#include "testing.h"
#define CANTIDAD 20

int comparar (const void* a, const void* b){
	char* dir_a = (char*)a;
	char* dir_b = (char*)b;
	if(*dir_a < *dir_b)return (int)-1;
	if(*dir_a == *dir_b)return (int)0;
	return (int)1;
}

void destruir_dato(void* valor){
	free(valor);
}

void crear_heap_num(){
	printf("COMIENZAN LAS PRUEBAS CON UN HEAP CON NUMEROS\n");
	heap_t* mi_heap = heap_crear(comparar);
	int valores[CANTIDAD];
	printf("\nMIENTRAS VOY ENCOLANDO...\n");
	for(int i=0;i<CANTIDAD;i++){
		valores[i]=i;
		heap_encolar(mi_heap,(void*)&valores[i]);
		printf("El valor maximo del heap es %d\n",*(int*)heap_ver_max(mi_heap));
	}
	print_test("El heap no esta vacio ",!heap_esta_vacio(mi_heap));
	printf("MIENTRAS VOY DESENCOLANDO...\n");
	while(!heap_esta_vacio(mi_heap)){
		printf("El valor maximo del heap es %d\n",*(int*)heap_ver_max(mi_heap));
		heap_desencolar(mi_heap);
	}
	print_test("EL heap esta vacio ",heap_esta_vacio(mi_heap));
	heap_destruir(mi_heap,NULL);
}

void crear_heap_letras(){
	printf("\nCOMIENZAN LAS PRUEBAS CON UN HEAP CON LETRAS\n");
	heap_t* mi_heap = heap_crear(comparar);
	char cadena[CANTIDAD] = "Me gusta programar c";
	char** arr_cadena = malloc(CANTIDAD*sizeof(char*));
	printf("\nMIENTRAS VOY ENCOLANDO...\n");
	for(int i=0;i<CANTIDAD;i++){
		char* carac = malloc(sizeof(char*));
		*carac = cadena[i];
		arr_cadena[i] = carac;
		heap_encolar(mi_heap,(void*)arr_cadena[i]);
		printf("El valor maximo del heap es %d\n",*(int*)heap_ver_max(mi_heap));
	}
	print_test("El heap no esta vacio ",!heap_esta_vacio(mi_heap));
	printf("MIENTRAS VOY DESENCOLANDO...\n");
	while(!heap_esta_vacio(mi_heap)){
		printf("El valor maximo del heap es %d\n",*(int*)heap_ver_max(mi_heap));
		heap_desencolar(mi_heap);
	}
	print_test("EL heap esta vacio ",heap_esta_vacio(mi_heap));
	heap_destruir(mi_heap,NULL);
	for(int i=0;i<CANTIDAD;i++)free(arr_cadena[i]);
	free(arr_cadena);
}

void prueba_heap_arreglo(){
	printf("\nCOMIENZAN LAS PRUEBAS DE UN HEAP CON UN ARREGLO DADO\n");
	int** mi_arreglo = malloc(CANTIDAD*(sizeof(int*))); 
	for(int i=0;i<CANTIDAD;i++){
		int* mi_val = malloc(sizeof(int));
		*mi_val = i;
		mi_arreglo[i] = mi_val;
	}
	heap_t* mi_heap = heap_crear_arr((void**)mi_arreglo,CANTIDAD,comparar);
	while(!heap_esta_vacio(mi_heap)){
		printf("El valor maximo del heap es %d\n",*(int*)heap_ver_max(mi_heap));
		heap_desencolar(mi_heap);
	}
	print_test("EL heap esta vacio ",heap_esta_vacio(mi_heap));
	heap_destruir(mi_heap,NULL);
	for(int i=0;i<CANTIDAD;i++){
		free(mi_arreglo[i]);
	}
	free(mi_arreglo);			
}

void prueba_heap_sort(){
	printf("\nCOMENZARON LAS PRUEBAS DEL HEAP SORT\n");
	int** mi_arreglo = malloc(CANTIDAD*(sizeof(int*))); 
	for(int i=0;i<CANTIDAD;i++){
		int* mi_val = malloc(sizeof(int));
		*mi_val = 53-i;
		mi_arreglo[i] = mi_val;
	}
	for(int i=0;i<CANTIDAD;i++){
		if(i!=CANTIDAD-1)printf("%d -",*mi_arreglo[i]);
		else printf("%d\n",*mi_arreglo[i]);
	}
	printf("Ahora el arreglo ordenado \n");	
	heap_sort((void**)mi_arreglo,(size_t)CANTIDAD,comparar);
	for(int i=0;i<CANTIDAD;i++){
		if(i!=CANTIDAD-1)printf("%d -",*mi_arreglo[i]);
		else printf("%d\n",*mi_arreglo[i]);
		free(mi_arreglo[i]);
	}
	free(mi_arreglo);
}

void pruebas_heap_alumno(){
	crear_heap_num();
	crear_heap_letras();
	prueba_heap_arreglo();
	prueba_heap_sort();
}
