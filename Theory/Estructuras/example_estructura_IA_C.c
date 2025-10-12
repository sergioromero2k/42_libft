#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int	main(void)
{
	// Crear nodos
	t_list *nodo1;
	t_list *nodo2;
	t_list *nodo3;

	nodo1 = malloc(sizeof(t_list));
	nodo2 = malloc(sizeof(t_list));
	nodo3 = malloc(sizeof(t_list));

	// Crear datos
	int a;
	int b;
	int c;

	a = 1;
	b = 2;
	c = 3;

	// Asignar conenido a los nodos
	nodo1->content = &a;
	nodo2->content = &b;
	nodo3->content = &c;

	// Enlazar nodos
	nodo1->next = nodo2; // nodo1 apunta a nodo2
	nodo2->next = nodo3; // nodo2 apunta a nodo3
	nodo3->next = NULL;  // último nodo apunta a NULL

	// Puntero a la lista (inicio)
	t_list *lista = nodo1;

	// Recorrer la lista e imprimir valores
	t_list *temp = lista;
	while (temp != NULL)
	{
		printf("%d\n", *(int *)temp->content);
		temp = temp->next;
	}

	// Liberar memoria
	free(nodo1);
	free(nodo2);
	free(nodo3);

	return (0);
}