```c
#include <stdio.h>
struct Nodo {
    int dato;
    struct Nodo* next;
}

int main(void){
    struct Nodo *nodo1=malloc(sizeof(struct Nodo));
    struct Nodo *nodo2=malloc(sizeof(struct Nodo));
    struct Nodo *nodo3=malloc(sizeof(struct Nodo));
    struct Nodo *nodo_act=nodo1;

    nodo1->dato=10;
    nodo2->dato=20;
    nodo3->dato=30;

    nodo1->next=nodo2;
    nodo2->next=nodo3;
    nodo3->next=NULL;

    while(actual != NULL) {
        printf("%d -> ", actual->dato)
        actual = actual -> siguiente;
    }
    prinft("NULL\N");

    // Liberar memoria
    free(nodo1);
    free(nodo2);
    free(nodo3);

    return 0;
}
```