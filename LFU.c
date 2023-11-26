
//LFU

#include<stdio.h>

int main()
{
      int total_frames, total_pages, hit = 0;
      int pages[25], frame[10], arr[25], time[25];
      int m, n, page, flag, k, minimum_time, temp;
      printf("Enter Total Number of Pages:\t");
      scanf("%d", &total_pages); 
      printf("Enter Total Number of Frames:\t");
      scanf("%d", &total_frames);
      for(m = 0; m < total_frames; m++)
      {
            frame[m] = -1;
      }
      for(m = 0; m < 25; m++)
      {
            arr[m] = 0;
      }
      printf("Enter Values of Reference String\n");
      for(m = 0; m < total_pages; m++)
      {
           // printf("Enter Value No.[%d]:\t", m + 1);
            scanf("%d", &pages[m]);
      }
      printf("\n");
      for(m = 0; m < total_pages; m++)
      {
            arr[pages[m]]++;
            time[pages[m]] = m;
            flag = 1;
            k = frame[0];
            for(n = 0; n < total_frames; n++)
            {
                  if(frame[n] == -1 || frame[n] == pages[m])
                  {
                        if(frame[n] != -1)
                        {
                              hit++;
                        }
                        flag = 0;
                        frame[n] = pages[m];
                        break;
                  }
                  if(arr[k] > arr[frame[n]])
                  {
                        k = frame[n];
                  }
            }
            if(flag)
            {
                  minimum_time = 25;
                  for(n = 0; n < total_frames; n++)
                  {
                        if(arr[frame[n]] == arr[k] && time[frame[n]] < minimum_time)
                        {
                              temp = n;
                              minimum_time = time[frame[n]];
                        }
                  }
                  arr[frame[temp]] = 0;
                  frame[temp] = pages[m];
            }
	    
            
            for(n = 0; n < total_frames; n++)
            {
                  printf("%d\t", frame[n]);
            }
            printf("\n");
      }
      printf("Page Fault : %d", hit);
      return 0;
}

/*****************OUTPUT***********
[ty92@ugilinux ~]$ cc LFU.c
[ty92@ugilinux ~]$ ./a.out
Enter Total Number of Pages:	12
Enter Total Number of Frames:	3
Enter Values of Reference String
1 2 3 4 1 2 5 1 2 3 4 5

1	-1	-1	
1	2	-1	
1	2	3	
4	2	3	
4	1	3	
4	1	2	
5	1	2	
5	1	2	
5	1	2	
3	1	2	
4	1	2	
5	1	2	
Page Fault : 2[ty92@ugilinux ~]$ 
*/
