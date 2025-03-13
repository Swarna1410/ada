#include<stdio.h>
#include<stdlib.h>
#define INF 999
int p[100],c[100][100];
int fp(int i)
{
while(p[i]!=0)
{
i=p[i];
}
return i;
}
int unionv(int i,int j)
{
if(i!=j)
{
p[j]=i;
return 1;
}
return 0;
}
int main()
{
int i,j,n,min,ne=1;
int u=0,v=0,a=0,b=0,mincost=0;
printf("enter the number of nodes int the graph\n");
scanf("%d",&n);
printf("enter the cost matrix\n");
for(i=1;i<=n;i++)
{
p[i]==0;
for(j=1;j<=n;j++)
{
scanf("%d",&c[i][j]);
if(c[i][j]==0)
{
c[i][j]=INF;
}
}
}
printf("the edges of min spanning tree are\n");
while(ne<n)
{
min=INF;
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
if(c[i][j]<min)
{
min=c[i][j];
a=u=i;
b=v=j;
}
}
}
u=fp(u);
v=fp(v);
if(unionv(u,v))
{
printf("%d edge selected (%d--%d)cost =%d\n",ne++,a,b,min);
mincost+=min;
}
c[a][b]=c[b][a]=INF;
}
printf("min cost is %d\n",mincost);
return 0;
}






