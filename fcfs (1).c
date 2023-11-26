//First Come First Serve

#include<stdio.h>
#include<stdlib.h>

struct job
{
	int atime;
	int btime;
	int ft;
	int tat;
	int wt;
}p[10];

int arr[10],burst[10],rq[10],no_rq=0,time=0,n;

void main()
{
	int i,j;
	printf("Enter number of jobs : ");
	scanf("%d",&n);
	printf("\n");

	for(i=0;i<n;i++)
	{	
		printf("Enter arrival time of p%d : ",i);
		scanf("%d",&p[i].atime);
		arr[i]=p[i].atime;
	}
	printf("\n");

	for(i=0;i<n;i++)
	{	
		printf("Enter burst time of p%d : ",i);
		scanf("%d",&p[i].btime);
		burst[i]=p[i].btime;
	}
	printf("\n");

	
	addrq();
	while(1)
	{
		j=selectjob();
		if(j==-1)
		{
			printf("CPU is Idle");
			time++;
			addrq();
		}
		else
		{
			while(burst[j]!=0)
			{
				printf("\tj%d",j);
				burst[j]--;
				time++;
				addrq();
			}
			p[j].ft=time;
		}

		if(finishall()==1)
		break;
	}

	int Ttat=0,Twt=0;
	printf("\n\n Job\t Finish time\t TAT\t WT");
	for(i=0;i<n;i++)
	{
		p[i].tat=p[i].ft-p[i].atime;
		p[i].wt=p[i].tat-p[i].btime;

		printf("\n job%d \t %d\t \t%d\t %d\t",i,p[i].ft,p[i].tat,p[i].wt);
		Ttat=Ttat+p[i].tat;
		Twt=Twt+p[i].wt;
	}
	float avgtat=Ttat/n;
	float avgwt=Twt/n;
	printf("\n\nAverage Turn Around Time = %f",avgtat);
	printf("\nAverage Waiting Time = %f",avgwt);
}

	
	void addrq()
	{	
		int i;
		for(i=0;i<n;i++)
		if(arr[i]==time)
		{
			rq[no_rq]=i;
			no_rq++;
		}
	}

	int selectjob()
	{
		int i,j;
		if(no_rq==0)
		return -1;
		j=rq[0];
		delq(j);
		return j;
	}

	void delq(int j)
	{
		int i;
		for(i=0;i<no_rq;i++)
		if(rq[i]==j)
		break;
		for(i=i+1;i<no_rq;i++)
		rq[i-1]=rq[i];
		no_rq--;
	}

	int finishall()
	{
		int i;
		for(i=0;i<n;i++)
		if(burst[i]!=0)
		return -1;
		return 1;
	}
	

/************OUTPUT********
[ty92@ugilinux ~]$ cc fcfs.c
[ty92@ugilinux ~]$ ./a.out
Enter number of jobs : 3

Enter arrival time of p0 : 1
Enter arrival time of p1 : 2
Enter arrival time of p2 : 0

Enter burst time of p0 : 2
Enter burst time of p1 : 3
Enter burst time of p2 : 5

	j2	j2	j2	j2	j2	j0	j0	j1	j1	j1

 Job	 Finish time	 TAT	 WT
 job0 	 7	 	6	 4	
 job1 	 10	 	8	 5	
 job2 	 5	 	5	 0	

Average Turn Around Time = 6.000000
Average Waiting Time = 3.000000
[ty92@ugilinux ~]$
*/
