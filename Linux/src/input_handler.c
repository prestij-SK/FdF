#include "../header/fdf.h"

void	input_init(t_Input *input_data)
{
	if (!input_data)
		return ;
	input_data->is_esc = 0;
	input_data->is_b1 = 0;
}

int	key_press(int key_code, t_Input *input_data)
{
	printf("here\n");
	if (key_code == 65307)
	{
		input_data->is_esc = 1;
		exit(0);
	}
	return (1);
}