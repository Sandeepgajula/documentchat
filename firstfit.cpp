#include<stdio.h>
int main(){
	/*int a[5]={100,200,50,15,30};
	int visit[5]={1,0,0,0,1}; 
	int n=5;
	while(true){
	
	printf("enter the process to read");
	int t;
	scanf("%d",&t);
	for(int i=0;i<n;i++){
		
		if(t<a[i] && visit[i]!=1){
			a[i]=t;
			break;
		}
		
	}
}
	for(int j=0;j<n;j++){
		printf("%d  ", a[j]);
	}*/
	int n;
	printf("enter the size ");
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++){
		printf("enter the %d  block  size :",i);
		scanf("%d",&a[i]); 
	}
	int b[n];
	for(int i=0;i<4;i++){
		printf("enter the %d  process size:",i);
		scanf("%d",&b[i]); 
	}
	for(int i=0;i<n;i++){
		 for(int j=0;j<4;j++){
		 	if(a[i]>=b[j]){
		 		 printf("The Process %d allocated to %d\n",j,a[i]);
		 		 b[j]=10000;
		 		 break;
			 }
			
		 }
	}
	for(int j=0;j<4;j++){
		if(b[j]!=10000){
			printf("process %d is not allocated\n",j);
		}
	}
}
