//FIFO

#include<stdio.h>

int page[40];
int n,frame[5],ref[50],victim=-1,pf=0;

int searchp(int p)
{
	int i;
	for(i=0;i<n;i++)
	if(frame[i]==p)
	return i;
	return -1;
}

int selectvictim()
{
	victim++;
	return victim%n;
}

main()
{
	int i,m;
	printf("\nEnter the no. of pages:");
	scanf("%d",&m);

	printf("\nEnter the reference string:");
	for(i=0;i<m;i++)
		scanf("%d",&page[i]);

	printf("\nEnter the no. of frames:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	frame[i]=-1;
	for(i=0;i<m;i++)
	{
		int k,j;
		k=searchp(page[i]);
		if(k==-1)
		{
			pf++;
			k=selectvictim();
			frame[k]=page[i];
		}
	 
		printf("\n req=%d",page[i]);
		for(j=0;j<n;j++)
		printf("\t%d",frame[j]);
	}

	printf("\nPage Fault = %d",pf);
}

/**************OUTPUT************
[ty92@ugilinux ~]$ cc FIFO.c
[ty92@ugilinux ~]$ ./a.out

Enter the no. of pages:12

Enter the reference string:1 2 3 4 1 2 5 1 2 3 4 5

Enter the no. of frames:3

 req=1	1	-1	-1
 req=2	1	2	-1
 req=3	1	2	3
 req=4	4	2	3
 req=1	4	1	3
 req=2	4	1	2
 req=5	5	1	2
 req=1	5	1	2
 req=2	5	1	2
 req=3	5	3	2
 req=4	5	3	4
 req=5	5	3	4
Page Fault = 9[ty92@ugilinux ~]$ 

*/
