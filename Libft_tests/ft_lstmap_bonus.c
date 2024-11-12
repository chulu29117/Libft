/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:57:21 by clu               #+#    #+#             */
/*   Updated: 2024/11/12 16:59:04 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Functions used in lstmap //
void	*lst_dup(void *content);
void	del(void *content);

// Helper functions prototypes //
t_list	*ft_lstnew(void *content);
void	print_list(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *s1);

// Iterate over the list 'lst' and apply the function 'f' to the content of 
// each elements. Create a new list resulting of the successive applications 
// of 'f'. The function 'del' is used to destroy the content of an element 
// if necessary.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*temp;
	t_list	*nelem;		// To store the new element created by f
	
	if (!lst || !f || !del)
		return (NULL);
	// Initialize the new list
	new_lst = NULL;
	while (lst)
	{
		temp = f(lst -> content);	// Apply f to the content of the node
		nelem = ft_lstnew(temp);	// Create a new node with the temp content
		if (!nelem)		// If the new node is NULL, free the content and the new list
		{
			del(temp);	// Free the content
			ft_lstclear(&new_lst, del);		// Free the new list
			return (NULL);
		}
		ft_lstadd_back(&new_lst, nelem);	// Add the new node to the new list
		lst = lst -> next;
	}
	return (new_lst);
}

// Test for ft_lstmap
#include <stdio.h>

int	main(void)
{
	t_list *lst;
	t_list *new_lst;

	// Test case 1: Normal list
	printf("Test case 1: Normal list\n");
	lst = ft_lstnew(ft_strdup("Node 1"));
	lst->next = ft_lstnew(ft_strdup("Node 2"));
	lst->next->next = ft_lstnew(ft_strdup("Node 3"));
	new_lst = ft_lstmap(lst, lst_dup, del);
	if (!new_lst)
		printf("Failed to duplicate the list\n");
	else
		print_list(new_lst);
	ft_lstclear(&lst, del);
	ft_lstclear(&new_lst, del);

	// Test case 2: Empty list
	printf("Test case 2: Empty list\n");
	lst = NULL;
	new_lst = ft_lstmap(lst, lst_dup, del);
	if (!new_lst)
		printf("New list is NULL as expected\n");
	else
		print_list(new_lst);
	ft_lstclear(&new_lst, del);

	// Test case 3: Single element list
	printf("Test case 3: Single element list\n");
	lst = ft_lstnew(ft_strdup("Single Node"));
	new_lst = ft_lstmap(lst, lst_dup, del);
	if (!new_lst)
		printf("Failed to duplicate the list\n");
	else
		print_list(new_lst);
	ft_lstclear(&lst, del);
	ft_lstclear(&new_lst, del);
	
	return (0);
}

// Helper functions //

void	*lst_dup(void *content)
{
	return (ft_strdup((char *)content));
}

void	del(void *content)
{
	free(content);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new -> content = content;
	new -> next = NULL;
	return (new);
}

// Function to print the list
void print_list(t_list *lst)
{
	t_list *temp;

	temp = lst;
	while (temp)
	{
		if (temp->content)
			printf("%s -> ", (char *)temp->content);
		else
			printf("NULL -> ");
		temp = temp->next;
	}
	printf("NULL\n");
}

// Clear the entire list
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !*lst)
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

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *temp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
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