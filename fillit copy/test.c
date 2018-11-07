#include "fillit.h"

int		main()
{
	t_lst	*tetri1;
	t_lst   *tetri2;
	t_lst   *tetri3;
	t_lst   *tet;

	tetri1 = ft_lst_new();
	tetri1->tet[0] = "0000";
	 tetri1->tet[1] = "0000";
	  tetri1->tet[2] = "0000";
	   tetri1->tet[3] = "0000";
	tetri2 = ft_lst_new();
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
	ft_print_lst(ad_lst_addend(&tet, tetri3));
	return (0);
}
