#include <iostream>
#include <stdio.h>
#include <vector>
#include <conio.h>

int main()
{
	char input;
	printf("APPLES\n");
	input = getch();
	printf("INPUT = %c\n", input);
	// return 1;
	// enum = {up,left,down,right};
	int stay_in_loop = 1;
	while (stay_in_loop)
	{
		input = getch();
		switch (input)
		{
		case 'w':
			printf("input = %c\n", input);
			break;
		case 'a':
			printf("input = %c\n", input);
			break;
		case 's':
			printf("input = %c\n", input);
			break;

		case 'd':
			printf("input = %c\n", input);
			break;
		case '`':
			printf("will_escape_from_loop\n");
			stay_in_loop = 0;
			break;
		default:
			printf("not valid movement cmd\n");
			printf("input = %c\n\n", input);
			break;
		}
	}
	return 0;
}