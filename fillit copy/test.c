#include "fillit.h"

int		main()
{
	//t_lst	*tetri = NULL;
	//t_lst   *tetri2;
//	t_lst   *tetri3;
//	t_lst   *tet;*/
	char **tet;

	//tetri1 = ft_lst_new();
	tet = malloc(sizeof(char *) * 4);
	tet[0] =   ft_strdup("..##");
	 tet[1] =  ft_strdup("...#");
	  tet[2] =  ft_strdup("...#");
	   tet[3] = ft_strdup("...#");
	/*tetri2 = ft_lst_new();
	tetri2->tet[0] = "1111";
	      tetri2->tet[1] = "1111";
	        tetri2->tet[2] = "1111";
	       tetri2->tet[3] = "1111";
	tetri3 = ft_lst_new();
	tetri3->tet[0] = "3333";
	       tetri3->tet[1] = "3333";
	        tetri3->tet[2] = "3333";
	         tetri3->tet[3] = "3333";
	tet = ad_lst_addend(&tetri1,tetri2);
	ft_print_lst(ad_lst_addend(&tet, tetri3));*/
	   if (!ft_valid_tetri(tet))
		  ft_putstr("bad keep work");
	   else
		   ft_putstr("nice keep work");
	return (0);
}
