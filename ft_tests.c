#include "stdio.h"
#include "unistd.h"

void hello();

int min(int a, int b);

int main()
{
	hello();
	int a = min(42, 1);
	printf("min = %i\n", a);
	return (0);
}