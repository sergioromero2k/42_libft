```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nodo {
    int dato;
    struct Nodo* next;
};

int main(void){
    struct Nodo *nodo1;

    nodo1=malloc(sizeof(struct Nodo));
    nodo1->dato=10;
    nodo1->next=NULL;

    printf("Dato del nodo %d\n",nodo1->dato);

    // Liberar memoria al final
    free(nodo1);
    return 0;
}
```