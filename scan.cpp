#include<stdio.h>
#include<Math.h>
#define n 8
/*void sort(int a[]){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j+1]<a[j]){
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}*/
int main(){
	int t;
	printf("enter the tack length ");
	scanf("%d",&t);
	int m1=0,m2=2*t-1;
	int a[n]={98,183,37,122,14,124,65,67}; 
	int s,i,total=0;  
	printf("enter the starting point ");
	scanf("%d",&s);
	printf("\n");
	int index,min=a[0],max=a[0];
	for(int i=0;i<n;i++){
		 if(a[i]<min){
		 	min=a[i];
		 }
		 if(a[i]>max){
		 	max=a[i];
		 }
	}
	if(s<m2-s){
		total+=s+max;
 }
    else{
    	total+=m2-s+m2-min; 
	}
    printf("The output using scan is %d ",total);
	
}
