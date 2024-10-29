#include "rush-02.h"
#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char *argv[])
{
	int	file;
	
	t_dict	*dict_entries;
	if (argc == 2)
	{
		// Proceed to convert the number using "numbers.dict"
		if (is_num(argv[1]) == 0)
		{
			write(1, "Error\n", 6);
			return (1);
		}
		file = open("numbers.dict", O_RDONLY);
		if (file == -1)
			return (1);
		dict_entries = parse(file);
		if (!dict_entries)
		{
			write(1, "Dict Error\n", 11);
			close(file);
			return (1);
		}
		num_to_word(argv[1], dict_entries);
		free(dict_entries);
		close(file);
	}
	else if (argc == 3)
	{
		// Proceed to convert the number using a custom dictionary file
		if (is_num(argv[2]) == 0)
		{
			write(1, "Error\n", 6);
			return (1);
		}
		file = open(argv[1], O_RDONLY);
		if (file == -1)
			return (1);
		dict_entries = parse(file);
		if (!dict_entries)
		{
			write(1, "Dict Error\n", 11);
			close(file);
			return (1);
		}
		num_to_word(argv[2], dict_entries);
		free(dict_entries);
		close(file);
	}
	else
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}
