/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:56:32 by clu               #+#    #+#             */
/*   Updated: 2024/11/07 10:19:50 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list *last;

	if (!lst)
		return (NULL);
	last = lst;
	while (last -> next)
		last = last -> next;
	return (last);
}

// Test for ft_lstlast
#include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new -> content = content;
	new -> next = NULL;
	return (new);
}

// Function to print the list
void print_list(t_list *lst)
{
	while (lst)
	{
		printf("%s -> ", (char *)lst->content);
		lst = lst->next;
	}
	printf("NULL\n");
}

int main(void)
{
	t_list *lst;

	// Create initial list
	lst = ft_lstnew("Node 1");
	lst->next = ft_lstnew("Node 2");
	lst->next->next = ft_lstnew("Node 3");

	// Print initial list
	printf("List:\n");
	print_list(lst);

	// Print the size of the list
	printf("Last node in list: \n");
	print_list(ft_lstlast(lst));

	// Free the list
	t_list *temp;
	while (lst)
	{
		temp = lst;
		lst = lst->next;
		free(temp);
	}

	return (0);
}