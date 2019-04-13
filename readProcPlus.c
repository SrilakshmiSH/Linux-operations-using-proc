
// Part C3

/*
 * Srilakshmi Shivakumar
 * Sushmitha Shridhar
 */

#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

void print_time (char* label, long time)
{
	const long minute = 60;
	const long hour = minute * 60;
	const long day = hour * 24;
	printf ("%s: %ld days, %ld:%02ld:%02ld\n", label, time / day, (time % day) / hour, (time % hour) / minute, time % minute);
}

int main (int argc, char *argv[])
{
	double idle_time;
	FILE *fp = fopen ("/proc/uptime", "r");
	fscanf (fp, "%lf\n",&idle_time);
	fclose (fp);
	print_time ("idle time", (long) idle_time);	

	double ver;
	char vers[1000],v2[1000],v3[1000];

	FILE *fpvr = fopen("/proc/version","r");
	fscanf(fpvr, "%s %s %lf %s", vers,v2,&ver,v3);
	fclose(fpvr);
	printf("Linux version = %s-%s-%lf-%s\n",vers,v2,ver,v3);

	char hs[1000];
	FILE *fph = fopen("/proc/sys/kernel/hostname","r");
	fscanf(fph, "%s\n", hs);
	fclose(fph);
	printf("hostname = %s\n",hs);

	unsigned long total=0;
	FILE *memf = fopen("/proc/meminfo","r");
	fscanf(memf, "MemTotal: %lu kB", &total);
	fclose(memf);
	printf("Amount of Memory = %lu\n",total);

	int ctxt;
	FILE *fpc = fopen("/proc/stat","r");
	char tag[32];
	while ( strcmp(tag, "ctxt") != 0) fscanf( fpc, "%s", tag );
	fscanf( fpc, "%8d", &ctxt);
	fclose(fpc);
	printf("Number of Context Switches = %8d\n",ctxt);

	struct timeval t1;
	gettimeofday(&t1,NULL);
	printf("Current Time of Day %s \n", ctime(&(t1.tv_sec)) );

	return 0;
}