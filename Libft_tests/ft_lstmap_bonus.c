/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:57:21 by clu               #+#    #+#             */
/*   Updated: 2024/11/11 12:04:15 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *));
void	del(void *content);
t_list	*ft_lstnew(void *content);
void	print_list(t_list *lst);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *s1);

// Iterate over the list 'lst' and apply the function 'f' to the content of 
// each elements. Create a new list resulting of the successive applications 
// of 'f'. The function 'del' is used to destroy the content of an element 
// if necessary.
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*temp;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = ft_lstnew(NULL);		// Create a new list
	while (lst)
	{
		// Create a temp list by apply the function 'f' to the content
		temp = ft_lstnew(f(lst -> content));
		// If the function/list fails, clear the new list and return NULL
		if (!temp)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		// Add the temp content to the end of the new list
		ft_lstadd_back(&new_lst, temp);
		// Go to the next node
		lst = lst -> next;		
	}
}

// Test for ft_lstmap
#include <stdio.h>

int	main(void)
{
	t_list *lst;
	t_list *new_lst;
	t_list *temp;

	// Create initial list
	lst = ft_lstnew(ft_strdup("Node 1"));
	lst->next = ft_lstnew(ft_strdup("Node 2"));
	lst->next->next = ft_lstnew(ft_strdup("Node 3"));

	// Apply ft_lstmap to duplicate the content of each node
	new_lst = ft_lstmap(lst, ft_strdup, del);
	if (!new_lst)
	{
		printf("Failed to duplicate the list\n");
		return (1);
	}

	// Print the content of the new list
	printf("New list content:\n");
	print_list(new_lst);

	// Clear the new list
	ft_lstclear(&new_lst, del);
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

// Function to clear the list
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *temp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
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

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
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