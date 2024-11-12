/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:57:14 by clu               #+#    #+#             */
/*   Updated: 2024/11/12 09:53:23 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Function prototypes //
void	del(void *content);
t_list	*ft_lstnew(void *content);
void	print_list(t_list *lst);
size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *s1);
void	ft_lstclear(t_list **lst, void (*del)(void *));

// Iterates the list ’lst’ and applies the function
// ’f’ on the content of each node.
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)				// Iterates the list
	{
		f(lst -> content);	// Function on the content of each node
		lst = lst -> next;	// Go to next node
	}
}

// Test for ft_lstiter
#include <stdio.h>

int	main(void)
{
	t_list *lst;
	t_list *temp;

	// Create initial list
	lst = ft_lstnew(ft_strdup("Node 1"));
	lst->next = ft_lstnew(ft_strdup("Node 2"));
	lst->next->next = ft_lstnew(ft_strdup("Node 3"));

	// Apply ft_lstiter to print the content of each node
	printf("List content:\n");
	print_list(lst);
	
	// Apply ft_lstiter to delete the content of each node
	printf("After applying the function:\n");
	ft_lstiter(lst, del);
	
	// Show that the content of each node is NULL
	temp = lst;
	while (temp)
	{
		temp->content = NULL;
		temp = temp->next;
	}
	print_list(lst);
    // Clear the entire list
    ft_lstclear(&lst, del);
	print_list(lst);
	return (0);
}

// Helper functions //
void	del(void *content)
{
	free(content);
}

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

// Function to print the list
void print_list(t_list *lst)
{
	while (lst)
	{
		if (lst->content)
			printf("%s -> ", (char *)lst->content);
		else
			printf("NULL -> ");
		lst = lst->next;
	}
	printf("NULL\n");
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*ptr_dest;
	char		*ptr_src;

	i = 0;
	ptr_dest = (char *)dest;
	ptr_src = (char *)src;
	while (i < n)
	{
		ptr_dest[i] = ptr_src[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	char		*ptr;
	size_t		len;

	len = ft_strlen(s1) + 1;	// +1 for the null-terminator
	ptr = (char *)malloc(len); 	// Allocate memory for the string
	if (ptr == NULL)			// If malloc fails, return 0
		return (NULL);
	ft_memcpy(ptr, s1, len);	// Copy the string to the allocated memory
	return (ptr);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}