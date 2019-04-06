#include<stdio.h>

struct process
{
    char name[2];
    int arrivalTime, burstTime, completedAt, turnAroundTime, avgWaitingTime;
};


int main(){
    struct process Q1[100], Q2[100];
    int f, at, bt, n, q1=0, q2=0;
    printf("Enter number of process : ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        printf("Process %d is in Queue 1 ? (1 for yes 0 for no) ", i);
        scanf("%d", &f);
        printf("Process %d burst Time : ", i);
        if(f){
            scanf("%d", &Q1[q1++].burstTime);
        }else
        {
            scanf("%d", &Q2[q2++].burstTime);
        }
        
    }
    printf("\nQueue 1\n");
    for(int i = 0; i < q1; i++)
    {
        printf("%d ", Q1[i].burstTime);
    }
    printf("\nQueue 2\n");
    for(int i = 0; i < q2; i++)
    {
        printf("%d ", Q2[i].burstTime);
    }
    
    
    return 0;
}