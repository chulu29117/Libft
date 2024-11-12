/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:56:45 by clu               #+#    #+#             */
/*   Updated: 2024/11/12 15:44:23 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Function prototypes //
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
void print_list(t_list *lst);

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;	// Create a pointer to the last node

	// If the list is empty, set the new node as the first node
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);	// Get the last node
	last -> next = new;			// Set the next of the last node to the new node
}

// Test for ft_lstadd_back /////////////////////////////////////////////////
#include <stdio.h>
int main(void)
{
	t_list *lst;

	// Create initial list
	lst = ft_lstnew("Node 1");
	lst->next = ft_lstnew("Node 2");
	lst->next->next = ft_lstnew("Node 3");

	// Print the list
	print_list(lst);

	// Add a new node to the end of the list
	ft_lstadd_back(&lst, ft_lstnew("Node 4"));

	// Print the list
	print_list(lst);

	return (0);
}

/// Helper functions ///
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
