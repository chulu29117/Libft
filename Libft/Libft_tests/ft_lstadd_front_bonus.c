/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:56:14 by clu               #+#    #+#             */
/*   Updated: 2024/11/07 10:19:37 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Add a new element to the front of the list
// PARAMETERS
// 	lst: pointer address to the first element of the list
// 	new: pointer address of the new element to add to the list
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new -> next = *lst; // Set the next node of the new node to the first node of the list
	*lst = new;			// Set the first node of the list to the new node
}

// Test for ft_lstadd_front
#include <stdio.h>
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

int main(void)
{
    t_list *lst;
    t_list *new_node;

    // Create initial list
    lst = ft_lstnew("Node 1");
    lst->next = ft_lstnew("Node 2");
    lst->next->next = ft_lstnew("Node 3");

    // Print initial list
    printf("Initial list:\n");
    print_list(lst);

    // Add new node to the front
    new_node = ft_lstnew("New Node");
    ft_lstadd_front(&lst, new_node);

    // Print updated list
    printf("Updated list:\n");
    print_list(lst);

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