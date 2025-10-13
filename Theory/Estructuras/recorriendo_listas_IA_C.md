```c
// Recorriendo la lista
void imprimirLista(struct Nodo* cabeza)
{
    struct Nodo* actual=cabeza;
    while(actual != NULL){
        printf("%d ->", actual->dato);
        actual=actual->siguiente;
    }
    printf("NULL\n");
}
```