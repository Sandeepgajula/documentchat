#include<stdio.h>
int main(){
	int a[4]={0,3,7,8};
	int b[4]={10,6,1,3};
	int n=4,r[n],c[n];
	int k;
	for( k=0;k<n;k++){
		r[k]=b[k];
	}
	int t,com=0,i;
	for(t=0;com!=n;t++){
		int min=999;
		int index=0;
		for(i=0;i<n;i++){
			if(a[i]<=t && r[i]<min && r[i]>0){
				min=r[i];
				index=i; 
			}
		}
		if(min!=999){
			r[index]--;
		}
		if(r[index]==0){
			com++;
			c[index]=t+1; 
		}
		
	}
	int m;
	for(m=0;m<n;m++){
		printf("%d \t",c[m]);
	}
	
}
