#include <stdio.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int main(void)
{
        int	string;

        string = ft_strlen("Hello");
        printf("Number of characters: %d\n", string);
        return (0);
}
