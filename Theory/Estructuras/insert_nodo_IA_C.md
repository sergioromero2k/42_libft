```c
void insertar_inicio(PunteroNodo *cabeza, Tarea nuevo_dato) {
    // 1. Crear el nuevo nodo y reservar memoria (malloc)
    PunteroNodo nuevo = (PunteroNodo) malloc(sizeof(Nodo));
    
    // Verificar si malloc fue exitoso
    if (nuevo == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return;
    }

    // Asignar el dato
    nuevo->dato = nuevo_dato; 

    // 2. El puntero 'siguiente' del nuevo nodo apunta al nodo actual de la cabeza
    nuevo->siguiente = *cabeza; 
    
    // 3. Mover la cabeza para que apunte al nuevo nodo
    *cabeza = nuevo; 
}
```