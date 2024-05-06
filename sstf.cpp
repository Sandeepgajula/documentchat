#include<stdio.h>
#include<Math.h>
#define n 8
int main(){ 
	int a[n]={98,183,37,122,14,124,65,67};
	int s,i,total=0,f[n];
    printf("Enter the value to start ");
    scanf("%d",&s); 
    for(int i=0;i<n;i++){
    	f[i]=0;
	}
    for(int i=0;i<n;i++){
      int min=999,index=0,j; 
    	 for(j=0;j<n;j++){
    	 	if(abs(a[j]-s)<min){
    	 		min=abs(a[j]-s);
    	 		index=j;
			 }
		 }
      total+=min;
      s=a[index];
      a[index]=1000;
	}
    printf("the output using sst is %d",total);
	
}
