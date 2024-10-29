void map_num(int map[4][4])
{
	int 	num[4][4] = {
		{1, 2, 3, 4},
		{2, 3, 4, 1},
		{3, 4, 1, 2},
		{4, 1, 2, 3}
	};
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			map[row][col] = num[row][col];
			col++;
		}
		row++;
	}
}
