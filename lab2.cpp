#include<stdio.h>
# define n 5
int main(){ 
	int b[n],p[n];
	printf("enter the  5 blocks size you want to enter");
	for(int i=0;i<n;i++){
		scanf("%d",&b[i]);
	} 
	printf("enter the  5 processes  you want to enter");
	for(int i=0;i<n;i++){
		scanf("%d",&p[i]);
	} 
	int allocate[n];
	for(int i=0;i<n;i++){
		allocate[i]=-1;
	} 
	for(int i=0;i<n;i++){
		int index=-1;
		for(int j=0;j<n;j++){
			if(b[j]>=p[i]){
				if(index==-1){
					index=j;
				}
				else if(b[j]<b[index]){
					index=j;
				}
			}
		}
		if(index!=-1){
			allocate[i]=index;
			b[index]-=p[i];
		}
		
	}
	printf("the allocatd block is \n");
	for(int i=0;i<n;i++){
		if(allocate[i]!=-1){
			printf("%d \n",allocate[i]+1);
		}
		else{
			printf("the process is not allocated\n");
		}
	} 
	
	
}
