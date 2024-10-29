#include <unistd.h>
#include "rush-02.h"

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

int	is_num(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	len;
	
	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;
	
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int	len;
	
	len = ft_strlen(src);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	ft_strcpy(dup, src);
	return (dup);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	
	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	res;
	
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{ 
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

int	ft_atoi_substr(const char *str, int start, int len)
{
	char	*buffer;
	int	i;
	int	result;

	buffer = (char *)malloc(len + 1);
	if (buffer == NULL)
		return (0);
	i = 0;
	while (i < len && str[start + i] != '\0')
	{
		buffer[i] = str[start + i];
		i++;
	}
	buffer[i] = '\0';
	result = ft_atoi(buffer);
	free(buffer);
	return result;
}

char	*ft_strchr(char *str, int c)
{
	int	i;
	
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

char	*trim_space(char *str)
{
	int	start;
	int	end;
	
	start = 0;
	// Find the first non-space character
	while (str[start] == ' ' || str[start] == '\t')
		start++;
	end = start;
	// Find the last non-space character
	while (str[end] != '\0')
		end++;
	// Move the null terminator to trim trailing spaces
	while (end > start && (str[end - 1] == ' ' || str[end - 1] == '\t'))
		end--;
	str[end] = '\0'; 	// Null-terminate the trimmed string
	return (&str[start]);   // Return the trimmed string
}





