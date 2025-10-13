```c
void liberarLista(struct Nodo* cabeza){
    struct Nodo *actual = cabeza;
    struct Nodo *siguiente;
    while(actual != NULL){
        siguiente = actual -> siguiente;
        free(actual);
        actual=siguiente;
    }
}
```
