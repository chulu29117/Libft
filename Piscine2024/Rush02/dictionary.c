#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "rush-02.h"

// Function to parse a dictionary line, split it, and store in dict_entries
int parse_line(char *line, t_dict *dict_entries, int index)
{
	char	*colon_pos;
	char	*number_part;
	char	*word_part;

	if (line[0] == '\0' || line[0] == '#')
	        return (-1);
// Find the colon position
	colon_pos = ft_strchr(line, ':');
	if (!colon_pos) 
	{
		return (-1);
	}
// Split the string into number and word parts
	*colon_pos = '\0'; 					// Null-terminate the number part
	number_part = trim_space(line); 			// Trim spaces around the number part
	word_part = trim_space(colon_pos + 1); 		// Trim spaces around the word part
	
// Handle errors for missing number or word
	if (!is_num(number_part) || word_part[0] == '\0')
	{
		return (-1);
	}	
// Convert number part to an integer and store the word in dict_entries
	dict_entries[index].number = atoi(number_part); 	// Convert number part to int
	dict_entries[index].word = ft_strdup(word_part); 	// Store a copy of the word
	return (0); 					// Success
}

t_dict	*parse(int file)
{
	char	buffer[4096];
	int	entries;
	char	*line_start;
	char	*line_end;
	int	entry_i;
	
	entry_i = 0;
	t_dict	*dict_entries;
	
	dict_entries = (t_dict *)malloc(sizeof(t_dict) * 2048);
	if (dict_entries == NULL)
		return (NULL);
	while ((entries = read(file, buffer, 4096)) > 0)
	{
		buffer[entries] = '\0';			// Null-terminate the buffer
		line_start = buffer;			// Set line_start to the beginning of the buffer
	        // Loop through the buffer and manually find each line (split by '\n')
		while (*line_start != '\0')
		{
	            // Find the next newline character ('\n') to determine the end of the line
			line_end = line_start;
			while (*line_end != '\n' && *line_end != '\0')
				line_end++;
			if (*line_end == '\n')		// Newline, replace it with '\0'
				*line_end = '\0';
			if (parse_line(line_start, dict_entries, entry_i) == 0)
				entry_i++;		// Only increment if the line was valid
			line_start = line_end + 1;
		}
	}
	if (entries == -1)
	{
		write(1, "Dict_Error\n", 11);
		free(dict_entries);
		return (NULL);				// Return the array of dictionary entries
	}
	dict_entries[entry_i].word = NULL;
	return (dict_entries);
}


