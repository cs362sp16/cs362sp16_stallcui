#include "stdio.h"
#include "math.h"
#include <stdlib.h>

#define DEBUG 0

int main(int argc, char* argv[])
{
	int i;

	if (argc < 5)
	{
		printf("tarantula:invald arguments\n");
		exit(1);
	}

	if (DEBUG != 0)
	{
		printf("# args %d\n", argc-1);
		for (i = 0; i < argc; i++)
		{
			printf("arg %d = %s\n", i, argv[i]);
		}
	}
	
	int fe = atoi(argv[1]);
	if (DEBUG != 0)
		printf("failed(e) = %d\n", fe);
	int tf = atoi(argv[2]);
	if (DEBUG != 0)
		printf("totalfailed = %d\n", tf);
	int pe = atoi(argv[3]);
	if (DEBUG != 0)
		printf("passed(e) = %d\n", pe);
	int tp = atoi(argv[4]);
	if (DEBUG != 0)
		printf("totalpassed = %d\n", tp);

	float fq = (float)fe/(float)tf;
	if (DEBUG != 0)
		printf("fq = %f\n",fq);
	float pq = (float)pe/(float)tp;
	if (DEBUG != 0)
		printf("pq = %f\n",pq);	

	float suspiciousness = fq/(fq+pq);
	printf("suspiciousness = %f\n", suspiciousness);

	return 0;
}
