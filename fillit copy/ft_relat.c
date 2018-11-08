#include "fillit.h"

int		ft_srsh(char **str, int i, int j)
{
	int k;

	k = 0;
	if (j + 1 < 4)
		str[i][j + 1] == '#' ? k++ : 1 == 1;
	if (j - 1 >= 0)
		str[i][j - 1] == '#' ? k++ : 1 == 1;
	if (i - 1 >= 0)
		str[i - 1][j] == '#' ? k++ : 1 == 1;
	if (i + 1 < 4)
		str[i + 1][j] == '#' ? k++ : 1 == 1;
	return (k);
}

int		ft_valid_tetri(char **str, int cpt)
{
	int i;
	int j;

	i = 0;
	j = 0;
	cpt = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if ((str)[i][j] == '#')
			{
				if (!ft_srsh((str), i, j))
					return (0);
				else
					cpt = cpt + ft_srsh((str), i, j);
			}
			j++;
		}
		i++;
	}
	if (cpt < 6)
		return (0);
	return (1);
}
