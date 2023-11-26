//Non-pre-emptive SJF

#include<stdio.h>
#include<stdbool.h>
typedef struct process
{
	bool isc;
	int bt,at,st,wt,ft,tat;
}PP;

PP P[100];
int tm=0,n,arr[100],arrv=0,count=0;
float atat,awt;

void minb(int a[],int k)
{
	int min=P[a[1]].bt,i,m=a[1];
	for(i=1;i<=k;i++)
	{
		if(P[a[i]].bt<min)
			{
				min=P[a[i]].bt;
				m=a[i];
			}
	}
	proc(m);
}

finda()
{
	int l;
	for(l=1;l<=n;l++)
	{
		if(P[l].at<=tm && P[l].isc==false)
		arr[++arrv]=l;	
	}
}

proc(int s)
{
	P[s].isc=true;
	P[s].st=tm;
	tm+=P[s].bt;
	P[s].ft=tm;
	P[s].wt=P[s].st-P[s].at;
	P[s].tat=P[s].ft-P[s].at;
	atat+=P[s].tat;
	awt+=P[s].wt;
	printf("| P%d ",s);
}

main()
{
	int i,a[100],k=0;
	printf("How many process : ");
	scanf("%d",&n);
	printf("Enter:-\nprocess BTime ATime \n");
	for(i=1;i<=n;i++)
	{
		printf("P%d\t",i);
		scanf("%d%d",&P[i].bt,&P[i].at);
		P[i].isc=false;	
	}

	printf("\nDetails about processes as follows\n\n");
	printf("Process\tBTime\tATime \n");
	for(i=1;i<=n;i++)
		printf("P%d\t%d\t%d\n",i,P[i].bt,P[i].at);

	printf("\nGantt chart\n");
	for(i=1;i<=n;i++)
	{
		if(P[i].at==0)
			{
			a[++k]=i;
			}
	}
	minb(a,k);
	for(count=2;count<=n;)
	{
		finda();
		if(arrv==0)
		{
			printf("|idl");
			tm+=1;
		}
		else
		{
			minb(arr,arrv);
			arrv=0;
			count++;
		}
	}
	printf("|\nDetails about processes as follows\n");
	printf("Process\tBT\tAT \tST\tWT\tFT\tTAT\n");
	for(i=1;i<=n;i++)
		printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",i,P[i].bt,P[i].at,P[i].st,P[i].wt,P[i].ft,P[i].tat);
	printf("\nAvg wait time=%f\nAvg TAT=%f\n",awt/n,atat/n);
}
/************OUTPUT********
[ty92@ugilinux ~]$ cc NPsjf.c
[ty92@ugilinux ~]$ ./a.out
How many process : 4
Enter:-
process BTime ATime 
P1	5     1
P2	6     0
P3	2     2
P4	4     0

Details about processes as follows

Process	BTime	ATime 
P1	5	1
P2	6	0
P3	2	2
P4	4	0

Gantt chart
| P4 | P3 | P1 | P2 |
Details about processes as follows
Process	BT	AT 	ST	WT	FT	TAT
P1	5	1	6	5	11	10
P2	6	0	11	11	17	17
P3	2	2	4	2	6	4
P4	4	0	0	0	4	4

Avg wait time=4.500000
Avg TAT=8.750000


[ty92@ugilinux ~]$ ./a.out
How many process : 4
Enter:-
process BTime ATime 
P1	5     2 
P2	1     0
P3	2     2
P4	4     3

Details about processes as follows

Process	BTime	ATime 
P1	5	2
P2	1	0
P3	2	2
P4	4	3

Gantt chart
| P2 |idl| P3 | P4 | P1 |
Details about processes as follows
Process	BT	AT 	ST	WT	FT	TAT
P1	5	2	8	6	13	11
P2	1	0	0	0	1	1
P3	2	2	2	0	4	2
P4	4	3	4	1	8	5

Avg wait time=1.750000
Avg TAT=4.750000
[ty92@ugilinux ~]$ 

*/
