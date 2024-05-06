#include<stdio.h>

void main(){
	int n,i,j;
	printf("Enter no of processes: ");
	scanf("%d",&n);
	int p[n],at[n],bt[n],ct[n],tat[n],wt[n],gc[100],c=0,v[n];
    for(i=0;i<n;i++)
    v[i]=0;
	printf("Enter the process ids:\n");
	for(i=0;i<n;i++){
		scanf("%d",&p[i]);
	}
	printf("Enter the arrivalll times:\n");
	for(i=0;i<n;i++){
		scanf("%d",&at[i]);
	}
	printf("Enter the Burst times:\n");
	for(i=0;i<n;i++){
		scanf("%d",&bt[i]);
	}
	int comp = 0,lb,count = -1,nfp,temp=-1,gcin=0;
	while(count<n-1){
        lb = 1000;
        temp = -1;
        for(i=0;i<n;i++){
            if(at[i]<=comp && v[i]==0 && bt[i]<lb){
                lb = bt[i];
                temp = i;
            }
        }
        if(temp != -1){
            v[temp] = 1;
            ct[temp] = comp + bt[temp];
            comp = ct[temp];
            count++;
            gc[gcin++] = p[temp];
        }
        else{
            if(gc[gcin-1]!=100)
            gc[gcin++] = 100;
            comp++;
        }
    }
	for(i=0;i<n;i++)
		tat[i] = ct[i] - at[i];
	for(i=0;i<n;i++)
		wt[i] = tat[i] - bt[i];
	printf("\n\nGantt Chart: \t");
	for(i=0;i<gcin;i++){
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
