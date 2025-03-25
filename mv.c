#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define COUNT 100
int main(int argc,char* argv[])
{
        if(argc != 3)
        {
                printf("Usage Error\n");
                exit(-3);
        }
        char buf [COUNT];
        int fd_1 = open(argv[1],O_RDONLY);
        int num_read;
        if(fd_1 < 0)
        {
                printf("could not open the source\n ");
                exit(-3);
        }	
	int fd_2 = open(argv[2],O_RDWR|O_CREAT|O_TRUNC,0666);
	while((num_read=read(fd_1, buf,COUNT))>0)
	{
		if((write(fd_2,buf,num_read))<0)
		{
			printf("Write Failed\n");
			exit(-3);
		}

	}
	unlink(argv[1]);
	close(fd_1);
	close(fd_2);
return 0;
}
