#include "libft.h"

int	main(int argc, char **argv)
{
	t_hmap *m = ft_hmap_init(TRUE);
	ft_hmap_additem(m, NULL, NULL, 0);
	ft_hmap_additem(m, NULL, "lets go", 8);
	ft_hmap_additem(m, NULL, "lets go", 8);
	ft_hmap_additem(m, NULL, "lets go", 8);
	ft_hmap_additem(m, NULL, "lets go", 8);
	return (0);
}