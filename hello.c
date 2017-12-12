#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/fs.h>
int main (void)
{
	printf ("hello world\n");
	const char* pathname="/dev/sdb1";
	int fd=open(pathname,O_RDONLY);

	if (fd==-1) {
	  printf("can not open /dev/sdb1\n");
	}

	uint64_t size = 0;
	if (ioctl(fd,BLKGETSIZE64,&size)==-1) {
	  printf("%llu\n", size);
	}

	close(fd);
	printf ("end\n");
}

