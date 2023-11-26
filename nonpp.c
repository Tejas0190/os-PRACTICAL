
#include<stdio.h>
#include<stdlib.h>

struct job{
	int atime; // arraival time.
	int btime; //brust time.
	int ft; //finish time.
	int tat; //Trun around time.
	int wt; // waiting time.
	int pri; //Priority varilable is add.
}p[10];

int arr[10],brust[10],n,rq[10],no_rq=0,time=0,j=-1;

void main(){
	
	int i,j;
	printf("Enter the job number:");
	scanf("%d",&n);
	printf("\n");
	
	for(i = 0;i<n;i++){
		printf("Enter the arrival time p%d:",i);
		scanf("%d",&p[i].atime); //Assigning the arrival time.
		arr[i] = p[i].atime;
	}
	printf("\n");
	
	for(i = 0;i<n;i++){
	printf("Enter the arrival time p%d:",i);
	printf("%d",p[i].atime); //Assigning the arrival time.
	arr[i] = p[i].atime;
	}
	printf("\n");
	
	for(i = 0;i<n;i++){
	printf("Enter the brust time p%d:",i);
	scanf("%d",&p[i].btime); //Assigning the brust time.
	brust[i] = p[i].btime;
	}
	printf("\n");
	
	for(i = 0;i<n;i++){
	printf("Enter the brust time p%d:",i);
	printf("%d",p[i].btime); //Assigning the brust time.
	brust[i] = p[i].btime;
	}
	printf("\n");

	for(i = 0;i<n;i++){
	printf("Enter the Priority p%d:",i);
	scanf("%d",&p[i].pri); //Assigning the Priority.
	}
	printf("\n");
	
	for(i = 0;i<n;i++){
	printf("Enter the Priority p%d:",i);
	printf("%d",p[i].pri); //Assigning the Priority.
	}
	printf("\n");

	
	addrq();  //Adding the process.
	// Process start now.
	while(1){
	j = selectionjob(); //sercah the process now.
		
		if(j == -1){
			printf("CPU is ideal");
			time++;
			addrq();			
		}else{
			while(brust[j]!=0){
				printf("\t j %d",j);
				brust[j]--;
				time++;
				addrq();
			}
			p[j].ft = time;
		}
		if(fsahll() == 1)
		break;
	}
	int Tat = 0,Twt =0;
	
	printf("\nJob \t FT \t TAT \t WT");
	for(i=0;i<n;i++){
		p[i].tat = p[i].ft-p[i].atime;
		p[i].wt = p[i].tat-p[i].btime;
		
		printf("\n JOb %d \t %d \t %d \t %d",i,p[i].ft,p[i].tat,p[i].wt);
		Tat += p[i].tat;
		Twt += p[i].wt;
	}
	
	float avgtat = Tat /n;
	float avgwt = Twt /n;
	
	printf("\nAverage of trun around time is:%f",avgtat);
	printf("\nAverage of wait time is:%f",avgwt);
}

int addrq(){
	int i;
	for(i=0;i<n;i++){
		if(arr[i] == time){
			if(j!=-1 && p[i].pri>p[j].pri){
			rq[no_rq] = i;
			j = i;
			}else{
				rq[no_rq++] = i;
			}
		}
	}
}

int selectionjob(){
	int i,k;
	if(no_rq == 0)
		return -1;
		k = rq[0];
	
	for(i=1;i<no_rq;i++)
	if(p[k].pri<p[rq[i]].pri){
		k = rq[i];
	}
	deleteq(k);
	return k;
}

int deleteq(int k){
	int i;
	for(i=0;i<no_rq;i++)
		
		if(rq[i] == k)
			break;
		
		for(i= i+1;i<no_rq;i++)
		rq[i-1] = rq[i];
		no_rq--;
}

int fsahll(){
	int i;
	for(i=0;i<n;i++)
	if(brust[i]!=0)
	return -1;
	return 1; 
}

/*
Enter the job number:3

Enter the arrival time p0:1
Enter the arrival time p1:2
Enter the arrival time p2:0

Enter the arrival time p0:1
Enter the arrival time p1:2
Enter the arrival time p2:0

Enter the brust time p0:3
Enter the brust time p1:2
Enter the brust time p2:5

Enter the brust time p0:3
Enter the brust time p1:2
Enter the brust time p2:5

Enter the Priority p0:3
Enter the Priority p1:2
Enter the Priority p2:1

Enter the Priority p0:3
Enter the Priority p1:2
Enter the Priority p2:1

         j 2     j 2     j 2     j 2     j 2     j 0     j 0     j 0     j 1     j 1
Job      FT      TAT     WT
 JOb 0   8       7       4
 JOb 1   10      8       6
 JOb 2   5       5       0
Average of trun around time is:6.000000
Average of wait time is:3.000000
--------------------------------
Process exited after 28.64 seconds with return value 33
Press any key to continue . . .
*/
