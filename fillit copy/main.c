#include "fillit.h"
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
#include "get_next_line.h"

int		main(void)
{
	int fd;
	t_lst	*toto;
	t_coor	*lolo;

	fd = 0;
	fd = open("test.txt",O_RDONLY);
	toto = ft_read_file(fd);
	if (toto)
	{
		ft_putstr("good file keep work\n");
		ft_print_lst(toto);
	}
	else
		ft_putstr("error");
	lolo = ft_hash_pos(toto);
	ft_print_coor(lolo);
	ft_place(lolo);
	return (0);
}
