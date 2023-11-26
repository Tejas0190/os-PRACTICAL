//Non-pre-emptive Priority

#include<stdio.h>
#include<stdbool.h>
typedef struct process
{
	bool isc;
	int bt,at,st,wt,ft,tat,p;
}PP;

PP P[100];
int tm=0,n,arr[100],arrv=0,count=0;
float atat,awt;

void minp(int a[],int k)
{
	int min=P[a[1]].p,i,m=a[1];
	for(i=1;i<=k;i++)
	{
		if(P[a[i]].p<min)
		{
			min=P[a[i]].p;
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
	printf("|  P%d ",s);
}

main()
{
	int i,a[100],k=0;

	printf("How many process : ");
	scanf("%d",&n);

	printf("Enter:-\nprocess BTime ATime Priority\n");
	for(i=1;i<=n;i++)
	{
		printf("P%d\t",i);
		scanf("%d%d%d",&P[i].bt,&P[i].at,&P[i].p);
		P[i].isc=false;	
	}

	printf("\nDetails about processes as follows :\n");
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
	minp(a,k);
	for(count=2;count<=n;)
	{
		finda();
		if(arrv==0)
		{
			printf("|idl");tm+=1;
		}
		else
		{
			minp(arr,arrv);count++;
			arrv=0;
		}
	}
	printf("|\nDetails about processes as follows :\n");
	printf("Process\tBT\tAT \tST\tWT\tFT\tTAT\n");
	for(i=1;i<=n;i++)
		printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",i,P[i].bt,P[i].at,P[i].st,P[i].wt,P[i].ft,P[i].tat);
	printf("\nAvg wait time=%f\nAvg TAT=%f\n",awt/n,atat/n);
}


/************OUTPUT********
[ty92@ugilinux ~]$ cc NPpriority.c
[ty92@ugilinux ~]$ ./a.out
How many process : 5
Enter:-
process BTime ATime Priority
P1	5     1     2
P2	3     0     3
P3	2     2     2
P4	4     3     1
P5	2     13    1

Details about processes as follows :
Process	BTime	ATime 
P1	5	1
P2	3	0
P3	2	2
P4	4	3
P5	2	13

Gantt chart
|  P2 |  P4 |  P1 |  P3 |  P5 |
Details about processes as follows :
Process	BT	AT 	ST	WT	FT	TAT
P1	5	1	7	6	12	11
P2	3	0	0	0	3	3
P3	2	2	12	10	14	12
P4	4	3	3	0	7	4
P5	2	13	14	1	16	3

Avg wait time=3.400000
Avg TAT=6.600000
[ty92@ugilinux ~]$ 

*/
