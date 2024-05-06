#include<stdio.h>
int pid[100],at[100],bt[100],rt[100],pr[100],ct[100],flag[100];
int sort(int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(at[j]>at[j+1])
			{
				int temp=at[j];
				at[j]=at[j+1];
				at[j+1]=temp;
				
				temp=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=temp;
				
				temp=pid[j];
				pid[j]=pid[j+1];
				pid[j+1]=temp;
				
				temp=pr[j];
				pr[j]=pr[j+1];
				pr[j+1]=temp;
			}
		}
	}
}
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
		flag[i]=0;
	}
	sort(n);
	int sum=at[0];
	for(i=0;i<n;i++)
	{
		int min=999,p;
		int a=sum;
		for(j=0;j<n && at[j]<=a;j++)
		{
			if(pr[j]<min && flag[j]!=1)
			{
				min=pr[j];
				p=j;
			}
		}
		if(min<999)
		{
			flag[p]=1;
			sum+=bt[p];
			ct[p]=sum;
		}
		else
		{
			a=at[i];
			for(j=0;j<n && at[j]<=a;j++)
			{
				if(pr[j]<min && flag[j]!=1)
				{
					min=pr[j];
					p=j;
				}	
			}
			flag[p]=1;
			sum+=bt[p]+ct[p-1]-at[p];
			ct[p]=sum;
		}
	}
	for(i=0;i<n;i++)
		printf("%d\n",ct[i]);
}
