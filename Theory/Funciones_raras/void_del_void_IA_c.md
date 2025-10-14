## void (*del)(void *)
Esto declara un puntero a una función.
Es decir, `del` no es una función, sino una variable que guarda la dirección de una función.

Esa función debe tener:
* **Un argumento:** un puntero genérico `void *`.
* Ningún valor de retorno: `void`.

### ¿Qué significa `void *`?
`void *` es un **puntero genérico**, significa "puntero a algo", pero sin especificar el tipo.
Puedes convertir (`cast`) un `void *` a cualquier otro tipo de puntero.

Por ejemplo:
```c
int x = 10;
void *ptr=&x;   // ptr apunta a un int, pero el compilador no sabe de qué tipo es.
```

### ¿Para qué sirve algo como `void (*del)(void *)`?
Se usa muchísimo en estructuras de datos genéricas (listas, pilas, árboles, etc.).
Para definir una función "de limpieza" sin importar el tipo de dato guardado.

Por ejemplo, en una lista enlazada genérica, no sabes si el contenido es un `int`, un `char *`, o una `struct`.

Entonces usas una función `del` que se encarga de liberar o limpiar el contenido, y la pasas como parámetro a funciones como `list_clear()` o `list_detele()`.

#### Ejemplo simple
Supongamos quetienes una función que libera memoria:
```c
void free_data(void *data){
    free(data);
}
// Luego tienes una función que recibe un puntero a función del:
void delete_node(void *content, void(*del)(void *)){
    if(del)
        del content;
}
// Se usa así:
int *num=malloc(sizeof(int));
*num=42;
delete_node(num,free_data); // Llama a free_data(num);
```

#### Ejemplos más ilustrativo (con distintos tipos)
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void del_int(void *ptr){
    printf("Liberando entero: %d\n, *(int *)ptr");
    free(ptr);
}

void del_str(void *ptr){
    printf("Liberando string: %s\n", (char *)ptr);
    free(ptr);
}

void delete_anything(void *data, void (*del)(void *)){
    if(del)
        del(data);
}

int main(){
    int *num = malloc(sizeof(int));
    *num=123;

    char *name=strdup("Hola mundo");

    delete_anything(num, del_int);
    delete_anything(name,del_str);

    return 0;
}
```