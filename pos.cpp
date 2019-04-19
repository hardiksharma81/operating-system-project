#include<stdio.h>
#include<conio.h>
int main()
{
    int bt[10],p[10],n,temp,i,j,wt[10],sum=0,t,at[10],tat[10],sum1=0,avg1;
    float avg;
    printf("Enter total no of proces:");
    scanf("%d",&n);
     printf("\n Enter arrival time for each process:-");
    for(t=0;t<n;t++)
    {
        printf("\n arrival time of process P %d:",t);
        scanf("%d",&at[t]);
        p[t]=t;
    }
    printf("\n Enter burst time for each process:-");
    for(i=0;i<n;i++)
    {
        printf("\nBurst time of process P%d:",i);
        scanf("%d",&bt[i]);
        p[i]=i;
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(bt[i]>bt[j])
            {
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    
    wt[0]=0;
    for(i=1;i<n;i++)
    {
        wt[i]=wt[i-1]+bt[i-1];
    }
    for(i=0;i<n;i++)
    {
        sum+=wt[i];
    }
    avg=(float)sum/n;
    printf("\n Waiting time for each process:-");
    for(i=0;i<n;i++)
    {
        printf("\n Waiting time for process P%d is %d sec.",p[i],wt[i]);
       
    }
    tat[0]=0;
    for(i=1;i<n;i++)
    {
        tat[i]=wt[i]+bt[i];
    }
    for(i=0;i<n;i++)
    {
        sum1+=tat[i];
    }
    avg1=(float)sum/n;
    printf("\n turnaroundtime for each process:-");
    for(i=0;i<n;i++)
    {
    printf("\n Turnaround around time for process P%d is %d sec.",p[i],tat[i]);	
	}
    printf("\n Average waiting time is %f sec.",avg);
    printf("\n Average turnaround time is %f sec.",avg1);
    getch();
    return 0;
}
