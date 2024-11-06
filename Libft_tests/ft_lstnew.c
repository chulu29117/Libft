/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:56:04 by clu               #+#    #+#             */
/*   Updated: 2024/11/06 12:27:02 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new -> content = content;	// Set the content of the new node
	new -> next = NULL;			// Set the next node to NULL
	return (new);
}

// Test for ft_lstnew
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
