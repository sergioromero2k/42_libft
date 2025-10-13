```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node_IA_C.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:08:41 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/13 11:46:46 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct					node
{
	int					data;
	struct node			*next;
};

struct					node1
{
	int					data1;
	struct node1		*next;
};

struct					node2
{
	int					data2;
	struct node2		*next;
};

struct					sergio_node
{
	char				data;
	struct sergio_node	*next;
};

struct					ultimo_node
{
	void				*data;
	struct ultimo_node	*next;
};

typedef struct last_node
{
	void				*content;
	struct last_node	*next;
}						l_node;

struct node	*createNode(int value)
{
	struct node	*node1;

	node1 = malloc(sizeof(struct node));
	if (!node1)
	{
		return (1);
	}
	node1->data = value;
	node1->next = NULL;
	return (node1);
}
l_node	*createnode2(void *content)
{
	l_node	*node;

	node = malloc(sizeof(l_node));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

// Inicializar el nodo
typedef struct ft_bacano
{
	void				*data;
	struct ft_bacano	*next;
}						ft;

struct					ft_vacano
{
	int					data;
	struct ft_vacano	*next;
};

void insertarPrincipio(struct ft_vacano **head, int value){
    struct ft_vacano *newMode=createNode(value);
    newMode->next=*head;
    *head = newMode;
}

void insetarPrimero(struct ft_vacano **head,int value){
    struct ft_vacano *newMode=createNode(value);
    newMode->next=*head;
    *head=newMode;
}

void insertFinal(struct ft_vacano ** head, int value){
    struct ft_vacano *newMode=createNode(value);
    struct ft_vacano *temp=*head;
    if(*head == NULL)
        *head=newMode;
        return NULL;

    while(temp->next != NULL)
        temp = temp -> next;
    temp->next=newMode;
}
```