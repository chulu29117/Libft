/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:56:55 by clu               #+#    #+#             */
/*   Updated: 2024/11/06 16:24:37 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	del(void *content);
t_list	*ft_lstnew(void *content);
void	print_list(t_list *lst);
size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *s1);

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		del(lst -> content);	// Delete the content of the node
		free(lst);				// Free the node memory
	}
}

// Test for ft_lstdelone
#include <stdio.h>

int main(void)
{
	t_list *lst;
	t_list *temp;
	
	// Create initial list
	lst = ft_lstnew(ft_strdup("Node 1"));
	lst->next = ft_lstnew(ft_strdup("Node 2"));
	lst->next->next = ft_lstnew(ft_strdup("Node 3"));

	// Print initial list
	printf("List:\n");
	print_list(lst);
	
	temp = lst->next;		// Save the second node
	ft_lstdelone(lst, del);	// Delete the first node
	lst = temp;				// Set the list to the second node
	
	// Print list after deleting the first node
	printf("List after deleting the first node:\n");
	print_list(lst);
	
	// Free the list
	while (lst)
	{
		temp = lst;
		lst = lst->next;
		ft_lstdelone(temp, del);
	}
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
        printf("%s -> ", (char *)lst->content);
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
