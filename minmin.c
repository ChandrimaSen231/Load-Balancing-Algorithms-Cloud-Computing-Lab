#include<stdio.h>
int main()
{
    int m,n,A[10][10],min1,min2,vm_selected,vm_num,task_selected,sch[10][2],k = 0,total_time = 0;
    
    //m -> number of vms
    //n -> number of tasks
    //min1 -> stores the minimum duration for a particular task
    //min2 -> stores the minimum duration out of selected minimum 
    //durations of all the tasks
    //vm_selected -> stores the vm selected for the task
    //task_selected -> stores the task selected that will be executed
    //total_time -> stores the total time required for running all the tasks
    
    printf("Enter the number of vms : ");
    scanf("%d",&m);
    printf("Enter the number of tasks : ");
    scanf("%d",&n);
    printf("Enter the completion times of the tasks : \n");
    for(int i=0; i<n; i++)
    {
        printf("Task%d : \n",i+1);
        for(int j=0; j<m; j++)
        {
            printf("\tVM%d : ",j+1);
            scanf("%d",&A[i][j]);
        }
    }
    
    while(k < n)
    {
        min2 = 9999;
        for(int i=0;i<n;i++)
        {
            min1 = 9999;
            for(int j=0;j<m;j++)
            {
                if(min1 > A[i][j])
                {
                    min1 = A[i][j];
                    vm_num = j;
                }
            }
            if(min2 > min1)
            {
                min2 = min1;
                vm_selected = vm_num;
                task_selected = i;
            }
        }
        sch[k][0] = vm_selected+1;
        sch[k][1] = task_selected+1;
        k++;
        total_time += min2;
        for(int i=0; i<m; i++)
        {
            A[task_selected][i] = 10001;
        }
        for(int i=0;i<n; i++)
        {
            if(A[i][vm_selected] != 10001)
            {
                A[i][vm_selected] += min2;
            }
        }
    }
    printf("\nTask\t\tMachine\n");
    for(int i=0;i<n; i++)
    {
        printf("%d\t\t%d\n",sch[i][1],sch[i][0]);
    }

}
