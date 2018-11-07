#include "fillit.h"
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
#include "get_next_line.h"

int		main()
{
	int fd;
	char *str;
	t_lst	*toto;
	
	str = "####";
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
	return (0);
}
