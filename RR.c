#include<stdio.h>
int queue[100],front=-1,rear=-1;
int gc[100],in =0;

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

int check_gc(int i){
	if(in!=0)
		if(gc[in-1]==i)
		return 1;
	return 0;
}

int check_rq(int k){
	int i;
	for(i=front+1;i<=rear;i++){
		if(queue[i] == k)
		return 1;
	}
	return 0;
}

void enqueue(int i){
	queue[++rear] = i;
}

int dequeue(){
	return queue[++front];
}

void main(){
	int n,i;
	scanf("%d",&n);
	int at[n],p[n],bt[n],tat[n],wt[n],ct[n],max,idle,visit[n],b[n];
	for(i=0;i<n;i++){
		scanf("%d",&p[i]);
	}
	for(i=0;i<n;i++){
		scanf("%d",&at[i]);
	}
	for(i=0;i<n;i++){
		scanf("%d",&bt[i]);
		b[i] = bt[i];
	}
	int tq;
	scanf("%d",&tq);
	sort(p,at,bt,n);
	int count=0,flag;
	while(count<n){
		idle = 10000;
		flag = 0;
		for(i=0;i<n;i++){
			if(visit[i]!=1 && at[i]<=max){
				flag = 1;
				if(check_gc(i)!=1 && check_rq(i)!=1){
					enqueue(i);
				}
			}
			else if(visit[i]!=1){
				if(idle>at[i])
				idle = at[i];
			}
		}
		if(in!=0 && gc[in-1]!=100){
			if(visit[gc[in-1]]!=1)
			enqueue(gc[in-1]);
		}
		if(flag==0){
			max = idle;
			//if(gc[in-1]!=100)
			gc[in++] = 100;
		}
		else{
			int now = dequeue();
			gc[in++] = now;
			if(bt[now]<=tq){
				visit[now] = 1;
				ct[now] = max + bt[now];
				max = ct[now];
				bt[now] = 0;
				count++;
			}
			else{
				bt[now]-=tq;
				max+=tq;
			}
		}
	}
	for(i=0;i<in;i++){
		if(gc[i]==100){
			printf("IDle\t");
		}
		else
		printf("P%d\t",p[gc[i]]);
	}
	printf("");
	for(i=0;i<n;i++){
		tat[i] = ct[i] - at[i];
		wt[i] = tat[i] - bt[i];
		printf("\n%d\t%d\t%d\t%d\t%d\t%d",p[i],at[i],b[i],ct[i],tat[i],wt[i]);
	}
}