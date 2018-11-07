#include "fillit.h"

t_lst	*ft_lst_new(void)
{
	t_lst	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(t_lst));
	if (new == NULL)
		return (NULL);
	new->tet = malloc(sizeof(char *) * 4);
	new->next = NULL;
	return (new);
}
