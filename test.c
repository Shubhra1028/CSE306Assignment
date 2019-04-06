#include<stdio.h>

int main(){
    int Q1[100], Q2[100];
    int f, at, bt, n, q1=0, q2=0;
    printf("Enter number of process : ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        printf("Process 1 is in Queue 1 ? (1 for yes 0 for no) ");
        scanf("%d", &f);
        printf("Process 1 burst Time");
        if(f){
            scanf("%d", &Q1[q1]);
            q1++;
        }else
        {
            scanf("%d", &Q2[q2]);
            q2++;
        }
        
    }
    printf("\nQueue 1\n");
    for(int i = 0; i < q1; i++)
    {
        printf("%d ", Q1[i]);
    }
    printf("\nQueue 2\n");
    for(int i = 0; i < q2; i++)
    {
        printf("%d ", Q2[i]);
    }
    
    
    return 0;
}