#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
int main(int argc,char* argv[])
{
	int i;
	for(i=1;i<argc;i++)
	{
		if(write(1,argv[i] ,strlen(argv[i]) ) < 0)
		{
			printf("Write Failed");
			exit(-3);
		}
	if(i<argc-1)	
		if(write(1," ",1) < 0)
		{
			printf("Write Faild");
			exit(-3);
		}
	}
	printf("\n");
return 0;
}
