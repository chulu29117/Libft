/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:13:29 by clu               #+#    #+#             */
/*   Updated: 2024/09/26 16:43:08 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int ft_sep(char c, char *charset)
{
    int i;

    i = 0;
    while (charset[i])
    {
        if (c == charset[i])
            return (1);
        i++;
    }
    return (0);
}

int ft_word_count(char *str, char *charset)
{
    int count = 0;
    int i = 0;
    int in_word = 0;

    while (str[i])
    {
        if (!ft_sep(str[i], charset) && !in_word)
        {
            in_word = 1;
            count++;
        }
        else if (ft_sep(str[i], charset))
            in_word = 0;
        i++;
    }
    return count;
}

int ft_word_len(char *str, char *charset)
{
    int len = 0;

    while (str[len] && !ft_sep(str[len], charset))
        len++;
    return len;
}

char *ft_strndup(char *src, int n)
{
    char *dup;
    int i;

    dup = (char *)malloc((n + 1) * sizeof(char));
    if (!dup)
        return NULL;
    i = 0;
    while (i < n)
    {
        dup[i] = src[i];
        i++;
    }
    dup[i] = '\0';
    return dup;
}

char **ft_split(char *str, char *charset)
{
    int word_count = ft_word_count(str, charset);
    char **result = (char **)malloc((word_count + 1) * sizeof(char *));
    int word_index = 0;

    if (!result)
        return NULL;

    while (*str)
    {
        if (!ft_sep(*str, charset))
        {
            int len = ft_word_len(str, charset);
            result[word_index] = ft_strndup(str, len);
            if (!result[word_index])
                return NULL;
            word_index++;
            str += len;
        }
        else
            str++;
    }
    result[word_index] = NULL;
    return result;
}

void free_split(char **split)
{
    int i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

int main(void)
{
    char str[] = "Hello,42 Piscine! Are you ready?";
    char charset[] = " ,!?";

    printf("Original string: %s\n", str);

    char **result = ft_split(str, charset);
    if (result == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Split result:\n");
    for (int i = 0; result[i] != NULL; i++)
    {
        printf("Word %d: %s\n", i + 1, result[i]);
    }

    free_split(result);
    return 0;
}

