#include<stdio.h>
struct Process
{
int id, Bt, tBt, Wt, TAt;
}
P[20];
int main()
{
int i,n,tq,total_wt=0,total_tat=0;
int x,y;
printf("Enter the Number of Processes:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter process id and burst time of P-%d:",i+1);
scanf("%d%d", &P[i].id, &P[i].Bt);
P[i].tBt=P[i].Bt;
}
printf("Enter the time quantum:");
scanf("%d",&tq);
x=0;
//0th time
y=0;
//0 processes completed
i=0; //ith process
while(1)
{
if(P[i].Bt>0)
{
if(P[i].Bt>tq)
{
P[i].Bt=P[i].Bt-tq;
x=x+tq;
}
else
{
x=x+P[i].Bt;
P[i].Bt=0;
P[i].TAt=x;
P[i].Wt=P[i].TAt-P[i].tBt;
y++;
if(y==n)
break;
}
}
if(i==n-1)
i=0;
else
i=i+1;
}
printf("PROCESS ID\tBURST TIME\tWAITING TIME\tTURNARROUND TIME\n");
printf("\t \t \t \n");
for(i=0;i<n;i++)
{
printf("%d\t\t%d\t\t%d\t\t%d\n",P[i].id, P[i].tBt, P[i].Wt, P[i].TAt);
}
for (int i=0;i<n;i++) 
 { 
 total_wt=total_wt +P[i].Wt; 
 total_tat=total_tat+P[i].TAt; 
 }
float s=(float)total_wt/(float)n;
float t=(float)total_tat/(float)n;
 printf("Average waiting time = %f",s);
 printf("\n");
 printf("Average turn around time = %f ",t);
return 0;
}
