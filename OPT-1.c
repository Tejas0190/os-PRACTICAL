//OPtimal page replacement algorithm

#include<stdio.h>
 
int main()
{
	int no_of_frames, no_of_pages, frames[10], pages[30], temp[10], flag1, flag2, flag3, i, j, k, pos, max, faults = 0;
	printf("Enter number of frames: ");
	scanf("%d", &no_of_frames);
	    
	printf("Enter number of pages: ");
	scanf("%d", &no_of_pages);
	    
	printf("Enter page reference string: ");
	    
	for(i = 0; i < no_of_pages; ++i)
	{
		scanf("%d", &pages[i]);
	}
	    
	for(i = 0; i < no_of_frames; ++i)
	{
		frames[i] = -1;
	}
	    
	for(i = 0; i < no_of_pages; ++i)
	{
		flag1 = flag2 = 0;
		for(j = 0; j < no_of_frames; ++j)
		{
			if(frames[j] == pages[i])
			{
				flag1 = flag2 = 1;
				break;
			}
		}
		
		if(flag1 == 0)
		{
			for(j = 0; j < no_of_frames; ++j)
			{
				if(frames[j] == -1)
				{
					faults++;
					frames[j] = pages[i];
					flag2 = 1;
					break;
				}
			}    
		}
		
		if(flag2 == 0)
		{
			flag3 =0;	    
			for(j = 0; j < no_of_frames; ++j)
			{
				temp[j] = -1;
				
				for(k = i + 1; k < no_of_pages; ++k)
				{
					if(frames[j] == pages[k])
					{
					temp[j] = k;
					break;
					}
				}
			}
			    
			for(j = 0; j < no_of_frames; ++j)
			{
				if(temp[j] == -1)
				{
					pos = j;
					flag3 = 1;
					break;
				}
			}
				    
			if(flag3 ==0)
			{
				max = temp[0];
				pos = 0;
				
				for(j = 1; j < no_of_frames; ++j)
				{
					if(temp[j] > max)
					{
						max = temp[j];
						pos = j;
					}
				}                
			}
			    
			frames[pos] = pages[i];
			faults++;
		}
		
		printf("\n");
		       
		for(j = 0; j < no_of_frames; ++j)
		{
			printf("\n pg=%d |",pages[i]);
			printf("%d\t", frames[j]);
		}
	}   
	printf("\n\nTotal Page Faults = %d", faults);
	return 0;
}

/****************OUTPUT*************
[ty92@ugilinux ~]$ cc OPT.c
[ty92@ugilinux ~]$ ./a.out
Enter number of frames: 3
Enter number of pages: 12
Enter page reference string: 1 2 3 4 1 2 5 1 2 3 4 5


 pg=1 |1	
 pg=1 |-1	
 pg=1 |-1	

 pg=2 |1	
 pg=2 |2	
 pg=2 |-1	

 pg=3 |1	
 pg=3 |2	
 pg=3 |3	

 pg=4 |1	
 pg=4 |2	
 pg=4 |4	

 pg=1 |1	
 pg=1 |2	
 pg=1 |4	

 pg=2 |1	
 pg=2 |2	
 pg=2 |4	

 pg=5 |1	
 pg=5 |2	
 pg=5 |5	

 pg=1 |1	
 pg=1 |2	
 pg=1 |5	

 pg=2 |1	
 pg=2 |2	
 pg=2 |5	

 pg=3 |3	
 pg=3 |2	
 pg=3 |5	

 pg=4 |4	
 pg=4 |2	
 pg=4 |5	

 pg=5 |4	
 pg=5 |2	
 pg=5 |5	

Total Page Faults = 7[ty92@ugilinux ~]$ 

*/
