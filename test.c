#include<stdio.h>
#include<string.h>

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
                if(A[j].burstTime > A[j+1].burstTime){
                    temp = A[j];
                    A[j]=A[j+1];
                    A[j+1]=temp;
                }
            }else if(time > nextTime){
                temp = A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
}

void sortBubbleIdWise(struct process A[], int n){
    struct process temp;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n-1-i; j++){
            if(A[j].id > A[j+1].id){
                temp = A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
}

int main(){
    struct process Q1[100], Q2[100];
    int f, n, tat=0, wt=0, q1=-1, q2=-1, totalTime=0;
    printf("Enter number of process : ");
    scanf("%d", &n);
    struct process Qc[n];
    for(int i = 0; i < n; i++)
    {
        printf("Process %d is in Queue 1 ? (1 for yes 0 for no) ", i);
        scanf("%d", &f);
        printf("Process %d Arrival and Burst Time : ", i);
        if(f){
            q1++;
            scanf("%d %d", &Q1[q1].arrivalTime, &Q1[q1].burstTime);
            Q1[q1].avgWaitingTime = Q1[q1].burstTime;
            totalTime += Q1[q1].burstTime;
            Q1[q1].id=i;
        }else
        {
            q2++;
            scanf("%d %d", &Q2[q2].arrivalTime, &Q2[q2].burstTime);
            Q2[q2].avgWaitingTime = Q2[q2].burstTime;
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

    int k=0, c=0, d=0, tq=1;
    for(int i = 0; i < totalTime; i++)
    {
        sortBubble(Q1, q1, i);

        if(q1>=0 && Q1[c].arrivalTime <= i ){
            Q1[0].burstTime--;
            if(Q1[0].burstTime == 0){
                Qc[k] = Q1[0];
                Qc[k].completedAt = i+1;
                Qc[k].turnAroundTime = Qc[k].completedAt - Qc[k].arrivalTime;
                for (c = 0; c < q1; c++)
                    Q1[c] = Q1[c+1];
                q1--;
                k++;
                c++;
            }
        }else if(q2>=0 && Q2[d].arrivalTime <= i){
            
            Q2[d].burstTime--;
            if(Q2[d].burstTime <= 0){
                Qc[k] = Q2[d];
                Qc[k].completedAt = i+1;
                Qc[k].turnAroundTime = Qc[k].completedAt - Qc[k].arrivalTime;
                for (c = d; c <=q2; c++)
                    Q2[c] = Q2[c+1];
                q2--;
                tq=0;
                if(q2<d) d=0;
                k++;
            }
            if(tq==2){
                d++;
                if(q2>0) d%=q2+1;
                tq=1;
            }
            else{
                tq++;
            }
            
        }
        else continue;
        
    }


    printf("\nProcesses will get completed in the following Order \n");
    for(int i = 0; i <n; i++){
        printf("--> P%d ", Qc[i].id);
    }
    sortBubbleIdWise(Qc, n);
    printf("\n\nAT : Arrival time \tBT : Burst Time \tCT : Completion Time \tTAT : TurnAround Time \tWT : Waiting Time\n");
    printf("\nProcess \tAT \tBT \tCT \tTAT \tWT \n");
    for(int i = 0; i <n; i++)
    {
        tat += Qc[i].turnAroundTime;
        wt += (Qc[i].turnAroundTime - Qc[i].avgWaitingTime);
        printf("P%d \t\t%d \t%d \t%d \t%d \t%d \n", Qc[i].id, Qc[i].arrivalTime, Qc[i].avgWaitingTime, Qc[i].completedAt, Qc[i].turnAroundTime, (Qc[i].turnAroundTime - Qc[i].avgWaitingTime) );
    }

    printf("\nAverage Turn Around Time : %0.2f", (float)tat/n);
    printf("\nAverage Waiting Time : %0.2f\n", (float)wt/n);
    
    return 0;
}