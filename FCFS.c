#include<stdio.h>

void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void sort(int p[],int at[],int bt[],int n){
	int i,j,temp;
	for(i=0;i<n-1;i++){
		for(j=i;j<n;j++){
			if(at[i]>at[j]){
				swap(&at[i],&at[j]);
				swap(&p[i],&p[j]);
				swap(&bt[i],&bt[j]);
			}
		}
	}
}

void main(){
	int n,i;
	printf("Enter no of processes: ");
	scanf("%d",&n);
	int p[n],at[n],bt[n],ct[n],tat[n],wt[n],gc[100],c=0;
	printf("Enter the process ids:\n");
	for(i=0;i<n;i++){
		scanf("%d",&p[i]);
	}
	printf("Enter the arrival times:\n");
	for(i=0;i<n;i++){
		scanf("%d",&at[i]);
	}
	printf("Enter the Burst times:\n");
	for(i=0;i<n;i++){
		scanf("%d",&bt[i]);
	}
	sort(p,at,bt,n);
	int max = 0;
	for(i=0;i<n;i++){
		if(max >= at[i]){
			gc[c++] = p[i];
			ct[i] = max + bt[i];
			max = ct[i];
		}
		else{
			gc[c++] = 100;
			max = at[i];
			gc[c++] = p[i];
			ct[i] = max + bt[i];
			max = ct[i];
		}
	}
	for(i=0;i<n;i++)
		tat[i] = ct[i] - at[i];
	for(i=0;i<n;i++)
		wt[i] = tat[i] - bt[i];
	printf("\n\nGantt Chart: \t");
	for(i=0;i<c;i++){
		if(gc[i]!=100){
			printf("P%d\t",gc[i]);
		}
		else
			printf("Idle\t");
	}
	printf("\n\nPId\tAT\tBT\tCT\tTAT\tWT");
	for(i=0;i<n;i++){
		printf("\n%d\t%d\t%d\t%d\t%d\t%d",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
	}
}
