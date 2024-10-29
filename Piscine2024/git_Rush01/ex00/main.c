#include <unistd.h>

int	map(char *c);

int	main(int argc, char *argv[])
{	
	char	*input = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";
	int	i;
	
	if (argc == 2)
	{
        	i = 0;
        	while (argv[1][i] != '\0' && input[i] != '\0') 
        	{
        		if (argv[1][i] != input[i]) 
        		{
        			break;
        		}
        		i++;
        	}
		if (argv[1][i] == '\0' && input[i] == '\0')
			map(argv[1]);
		else
			write(1, &"Invalid input, correct input is: \"4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2\"\n", 70);  
	else
		write(1, &"Invalid input, correct input is: \"4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2\"\n", 70);
	}
	return (0);
}
