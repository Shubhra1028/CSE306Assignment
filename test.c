#include<stdio.h>
#include<string.h>

#include<stdlib.h>
#include <unistd.h>

struct process
{
    int id, arrivalTime, burstTime, completedAt, turnAroundTime, avgWaitingTime;
};

void sortBubble(struct process A[], int n, int currentTime){
    struct process temp;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n-1-i; j++){
            int time = (A[j].arrivalTime-currentTime)>0 ? A[j].arrivalTime-currentTime : 0 ;
            int nextTime = (A[j+1].arrivalTime-currentTime)>0 ? A[j+1].arrivalTime-currentTime : 0 ;
            if( time == nextTime){
                // printf("%d\n", A[j].burstTime);
                if(A[j].burstTime > A[j+1].burstTime){
                    temp = A[j];
                    A[j]=A[j+1];
                    A[j+1]=temp;
                }
            }else if(time > nextTime){
                // printf("%d\n", A[j].burstTime);
                temp = A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
}

int main(){
    struct process Q1[100], Q2[100];
    int f, at, bt, n, q1=-1, q2=-1, totalTime=0;
    printf("Enter number of process : ");
    scanf("%d", &n);
    struct process Qc[n];
    for(int i = 0; i < n; i++)
    {
        // printf("Process %d is in Queue 1 ? (1 for yes 0 for no) ", i);
        // scanf("%d", &f);
        printf("Process %d Arrival and Burst Time : ", i);
        if(1){
            q1++;
            scanf("%d %d", &Q1[q1].arrivalTime, &Q1[q1].burstTime);
            totalTime += Q1[q1].burstTime;
            Q1[q1].id=i;
        }else
        {
            q2++;
            scanf("%d %d", &Q2[q2].arrivalTime, &Q2[q2].burstTime);
            totalTime += Q2[q2].burstTime;
            Q2[q2].id=i;
        }
        
    }

    // Logic for the scheduling
    //Queue1 which uses Shortest Job remaining Time First has higer Priority
    //than
    //Queue2 which uses Round Robin with time quanta = 2

    sortBubble(Q1, q1, 0);
    sortBubble(Q2, q2, 0);

    int k=0, c=0;
    for(int i = 0; i < totalTime; i++)
    {
        // printf("P%d %d \n", Q1[c].id, Q1[c].arrivalTime);
        sortBubble(Q1, q1, i);
        printf("\nQueue 1\n");
        for(int j = 0; j <=q1; j++)
        {
            printf("P%d %d %d \n", Q1[j].id, Q1[j].arrivalTime, Q1[j].burstTime);
        }
        if(q1>=0 && Q1[c].arrivalTime <= i ){
            Q1[0].burstTime--;
            printf("\n P%d %d %d\n", Q1[c].id, Q1[c].arrivalTime, Q1[c].burstTime);
            if(Q1[0].burstTime == 0){
                Qc[k] = Q1[0];
                Qc[k].completedAt = i+1;
                for (c = 0; c < q1; c++)
                    Q1[c] = Q1[c+1];
                q1--;
                k++;
                c++;
            }
        }
        
    }
    

    printf("\nQueue\n");
    printf("\nProcess \tAT \tCT \n");
    for(int i = 0; i <n; i++)
    {
        printf("P%d \t\t%d \t%d \n", Qc[i].id, Qc[i].arrivalTime, Qc[i].completedAt);
    }

    // printf("\nQueue 1\n");
    // for(int i = 0; i <=q1; i++)
    // {
    //     printf("P%d %d %d \n", Q1[i].id, Q1[i].arrivalTime, Q1[i].burstTime);
    // }
    // printf("\nQueue 2\n");
    // for(int i = 0; i <=q2; i++)
    // {
    //     printf("P%d %d %d \n", Q2[i].id, Q2[i].arrivalTime, Q2[i].burstTime);
    // }
    
    
    return 0;
}