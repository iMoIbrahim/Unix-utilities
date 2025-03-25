#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{	
	char buf [1000];
	if (NULL == getcwd(buf , 1000))
	{
		printf("An Error\n");
		exit(-3);
	}
	if(write(1, buf, strlen(buf)) == -1)
	{
		printf("Write Failed\n ");
                exit(-3);

	}
	printf("\n");
	return 0;
}
