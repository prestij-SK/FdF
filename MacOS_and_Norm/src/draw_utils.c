#include "../header/draw.h"

int	is_steep(t_Point2D start, t_Point2D end)
{
	return (abs(end.y - start.y) > abs(end.x - start.x));
}

int	in_range(int x, int y, int width, int height)
{
	if (x >= width || y >= height || x <= 0 || y <= 0)
		return (0);
	return (1);
}

void	setup_line_3D(t_Line2D *line, t_Point3D_d *start, t_Point3D_d *end)
{
	if (!line || !start || !end)
		return ;
	
	printf("%f %f\n", start->z, end->z);
}