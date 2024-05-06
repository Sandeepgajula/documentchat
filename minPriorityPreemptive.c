#include<stdio.h>
int pid[100],at[100],bt[100],rt[100],pr[100],ct[100],flag[100];
int main()
{
	int n,i,j=0;
	printf("Enter no.of process: ");
	scanf("%d",&n);
	at[n],bt[n],ct[n],pid[n],rt[n],pr[n];
	printf("Enter at&bt&pr: ");
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d",&at[i],&bt[i],&pr[i]);
		rt[i]=bt[i];
		pid[i]=i+1;
	}
	int t,c=0,min,p;
	for(t=0;c!=n;t++)
	{
		int max=0;
		for(i=0;i<n;i++)
		{
			if(at[i]<=t && pr[i]>max && rt[i]>0)
			{
				max=pr[i];
				p=i;
			}
		}
		if(max!=0)
		{
			rt[p]--;
		}
		if(rt[p]==0)
		{
			ct[p]=t+1;
			c++;
		}
	}
	for(i=0;i<n;i++)
		printf("%d\n",ct[i]);
}
