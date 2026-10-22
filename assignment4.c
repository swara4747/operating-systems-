//menu driven program to stimulate the first come first serve (fcfs) cpu scheduling algorithm

#include<stdio.h>
int main(){

int i, n ;              //n is the number of processes (user input)
int at[10],bt[10],ct[10],wt[10],tat[10];     //all the types of time used and their limits
int avgtat=0, avgwt=0;     //declaring the avg times as 0 as initial values



printf("Enter the number of processes: ");
    scanf("%d",&n);
   
   
printf("enter the arrival time and then the burst time for each of the processes :   \n");
for(i=0;i<n;i++);{
printf("P%d:",i+1);
scanf("%d %d",&at[i],&bt[i]);
}

//using the fcfs scheduling
ct[0]=at[0]+bt[0];
for(i=1; i<n; i++){
if(ct[i-1]<at[i])
ct[i]=at[i]+bt[i];

else
ct[i]=ct[i-1]+bt[i];
}



//calculating the values of tat and waiting time
for (i=0;i<n;i++){
//turnaround time is the sub of ct (completion time) and at
tat[i]=ct[i]-at[i];  
//total process time spent          
wt[i]=tat[i]-bt[i];
avgtat= avgtat+tat[i];
avgwt=avgwt+wt[i];
}

printf("showing the processes: \n");
for (i=0;i<n;i++){
printf("p%d\n", i+1);          
}



//showing time for each process

printf("\nprocess number  \narrival time  \nburst time  \ncompletion time  \nturnaround time  \nwait time \n");

for (i=0;i<n;i++)
    {
 printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1,at[i], bt[i], ct[i], tat[i], wt[i]);
    }


   
    printf("Average Turnaround Time = %.2f\n",avgtat);
    printf("Average Waiting Time = %.2f\n",avgwt);

    return 0;
}
