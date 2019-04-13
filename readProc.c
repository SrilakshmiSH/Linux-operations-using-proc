
//Part C2

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/times.h>

int main(int argc, char* argv[]) {
	char filename[1000];
	int arg1 = atoi(argv[1]);
	
	sprintf(filename,"/proc/%d/stat",arg1);
	FILE *fp = fopen(filename,"r");
	int ppid;
	long utime;
	long stime;
	char comm[30];
	if(fp != NULL)  {
		fscanf(fp,"%d %s %lu %lu",&ppid, comm,&utime, &stime);
	}
	
	printf("ppid is %d\n",ppid);
	printf("process name is %s\n",comm);
	printf("user time is %lu\n", utime);
	printf("system time is %lu\n",stime);
	fclose(fp);

	return 0;
}

