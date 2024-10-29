#include <unistd.h>

void input_grid(int map[4][4]);
int	map(char c);

int	main(int argc, char *argv[])
{
	if (argc == 2)
		map(*argv[1]);
	else
		write(1, &"Invalid input, correct input is: \"4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2\"\n", 70);  
	return (0);
}

