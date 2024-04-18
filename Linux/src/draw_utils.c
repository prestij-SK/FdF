#include "../header/draw.h"

int	is_steep(t_Point2D start, t_Point2D end)
{
	return (abs(end.y - start.y) > abs(end.x - start.x));
}