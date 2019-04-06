#include<stdio.h>
#include<string.h>

#include<stdlib.h>
#include <unistd.h>

struct process
{
    int id, arrivalTime, burstTime, completedAt, turnAroundTime, avgWaitingTime;
};

void sortBubble(struct process A[], int n){
    struct process temp;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1-i; j++){
            if(A[j].arrivalTime >A[j+1].arrivalTime){
                temp = A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
}

int main(){
    struct process Q1[100], Q2[100];
    int f, at, bt, n, q1=0, q2=0, totalTime=0;
    printf("Enter number of process : ");
    scanf("%d", &n);
    int Qc[n];
    for(int i = 0; i < n; i++)
    {
        printf("Process %d is in Queue 1 ? (1 for yes 0 for no) ", i);
        scanf("%d", &f);
        printf("Process %d Arrival and Burst Time : ", i);
        if(f){
            scanf("%d %d", &Q1[q1].arrivalTime, &Q1[q1].burstTime);
            totalTime += Q1[q1].burstTime;
            Q1[q1].id=i;
            q1++;
        }else
        {
            scanf("%d %d", &Q2[q2].arrivalTime, &Q2[q2].burstTime);
            totalTime += Q2[q2].burstTime;
            Q2[q2].id=i;
            q2++;
        }
        
    }

    // Logic for the scheduling
    //Queue1 which uses Shortest Job remaining Time First has higer Priority
    //than
    //Queue2 which uses Round Robin with time quanta = 2

    sortBubble(Q1, q1);
    sortBubble(Q2, q2);
    



    printf("\nQueue 1\n");
    for(int i = 0; i < q1; i++)
    {
        printf("P%d %d %d \n", Q1[i].id, Q1[i].arrivalTime, Q1[i].burstTime);
    }
    printf("\nQueue 2\n");
    for(int i = 0; i < q2; i++)
    {
        printf("P%d %d %d \n", Q2[i].id, Q2[i].arrivalTime, Q2[i].burstTime);
    }
    
    
    return 0;
}