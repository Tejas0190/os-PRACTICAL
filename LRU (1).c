//LRU 

#include<stdio.h>

int pf=0,pg;
int f,frame[5],ref[50],victim=0,time[50];

int searchpage(int p)
{
	int i;
	for(i=0;i<f;i++)
	if(frame[i]==p)
	return i;
	return -1;
}

int selectvictim()
{
	int min=0,i;
	for(i=1;i<f;i++)
	{
		if(time[i]<time[min])
		min=i;
	}
	return min;
}

main()
{
	int i;
	printf("\nEnter the no.of frames : ");
	scanf("%d",&f);
	for(i=0;i<f;i++)
	frame[i]=-1;
	for(i=0;i<f;i++)
	time[i]=-1;

	printf("\nEnter the no. of pages : ");
	scanf("%d",&pg);

	printf("\nEnter the page(reference string) : ");
	for(i=0;i<pg;i++)
	scanf("%d",&ref[i]);

	for(i=0;i<pg;i++)
	{
		int k,j;
		k=searchpage(ref[i]);
		if(k==-1)
		{
			pf++;
			k=selectvictim();
			frame[k]=ref[i];
		}
		time[k]=i;
		printf("\n pg=%d |",ref[i]);
		for(j=0;j<f;j++)
		printf("\t%d",frame[j]);
	}
	printf("\nPage Fault is = %d",pf);
}

/*************OUTPUT**************
[ty92@ugilinux ~]$ cc LRU.c
[ty92@ugilinux ~]$ ./a.out

Enter the no.of frames : 3

Enter the no. of pages : 12

Enter the page(reference string) : 1 2 3 4 1 2 5 1 2 3 4 5

 pg=1 |	1	-1	-1
 pg=2 |	1	2	-1
 pg=3 |	1	2	3
 pg=4 |	4	2	3
 pg=1 |	4	1	3
 pg=2 |	4	1	2
 pg=5 |	5	1	2
 pg=1 |	5	1	2
 pg=2 |	5	1	2
 pg=3 |	3	1	2
 pg=4 |	3	4	2
 pg=5 |	3	4	5
Page Fault is = 10[ty92@ugilinux ~]$ 

*/
