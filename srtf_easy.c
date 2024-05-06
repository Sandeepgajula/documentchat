#include<stdio.h>
int main()
{
	int n,i,j;
	printf("enter no.of process: ");
	scanf("%d",&n);
	int at[n],bt[n],rt[n],ct[n];
	printf("enter at&bt values: ");
	for(i=0;i<n;i++)
	{
		scanf("%d  %d",&at[i],&bt[i]);
		rt[i]=bt[i];
	}
	int c=0,min,t;
	for(t=0;c!=n;t++)
	{
		min=999;
		for(i=0;i<n;i++)
		{
			if(at[i]<=t && rt[i]<min && rt[i]>0)
			{
				min=rt[i];
				j=i;
			}
		}
		if(min!=999)
			rt[j]--;
		if(rt[j]==0)
		{
			c++;
			ct[j]=t+1;
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d\n",ct[i]);
	}
}
//6 0 8 1 4 2 2 3 1 4 3 5 2 ==> 20 10 4 5 13 7
