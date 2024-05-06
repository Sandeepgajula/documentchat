#include<stdio.h>
#include<Math.h>
#define n 8
int main(){ 
	int a[n]={98,183,37,122,14,124,65,67};
	int s,i,total=0;
    printf("Enter the value to start ");
    scanf("%d",&s);
    for(i=0;i<n;i++){
    	total+=abs(s-a[i]);
    	s=a[i]; 
	}
    printf("the output using fcfs is %d",total);
	
}
