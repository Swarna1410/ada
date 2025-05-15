#include<stdio.h>
#define MAX_ITEMS 100
double compute(double w,double weight[],double val[],double ratio[],int n);
int get(double weight[],double val[],double ratio[],int n);

int main(){
int n ,i;
double w,weight[MAX_ITEMS],val[MAX_ITEMS],ratio[MAX_ITEMS];
printf("enter the number of items");
scanf("%d",&n);
printf("enter the weights of items");
for(i=0;i<n;i++)
scanf("%lf",&weight[i]);
printf("enter the values of items");
for(i=0;i<n;i++)
scanf("%lf",&val[i]);
for(i=0;i<n;i++)
ratio[i]=val[i]/weight[i];
printf("enter the capacity of the knapsack");
scanf("%lf",&w);
printf("the maximum value in knapsack of capacity %.2f is:%.2f\n",w,compute(w,weight,val,ratio,n));
return 0;
}
double compute(double w,double weight[],double val[],double ratio[],int n)
{
double cw=0;
double cv=0;
printf("items considered are");
while(cw<w)
{
int item=get(weight,val,ratio,n);
if(item==-1)
{
break;
}
printf("%d",item+1);
if(cw+weight[item]<=w)
{
cw+=weight[item];
cv+=val[item];
ratio[item]=0;
}
else{
cv+=(ratio[item]*(w-cw));
cw+=(w-cw);
break;
}
}
return cv;
}
int get(double weight[],double val[],double ratio[],int n)
{
int i;
double highest=0;
int index=-1;
for(i=0;i<n;i++)
{
if(ratio[i]>highest)
{
highest=ratio[i];
index=i;
}
}
return index;
}

