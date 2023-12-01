#include "day1.h"

int main(void)
{
	char 	buff[256];
	char	num[3];
	int		inum;
	int		sum;

	FILE *the_file = fopen("input.txt", "r");
	if (the_file == NULL)
	{
		printf("Rip!");
	}
	while (fgets(buff, sizeof(buff), the_file))
	{
		num[0] = *ft_strnum(buff);
		num[1] = *ft_strrnum(buff);
		num[2] = '\0';
		sum += ft_atoi(num);
	}
	printf("The sum is: %i", sum);
	return EXIT_SUCCESS;
}
