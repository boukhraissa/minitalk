

#include "minitalk_bonus.h"

long	ft_atoi(const char *str)
{
	long	i;
	long	nb;

	i = 0;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (10 * nb) + (str[i] - 48);
		i++;
	}
	return (nb);
}