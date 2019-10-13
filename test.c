#include <stdio.h>

int main()
{
	int i = 0;
	int j;
	char block[4][4];

	char *str = "1111000000000000";
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			block[i][j] = *str;
			str++;
			j++;
		}
		i++;
	}

	// печать блока
	i = 0;
	while (i < 4)
	{
		j = 0;
		while(j < 4)
		{
			printf("%c",block[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	return(0);
}
