#include<stdio.h>
#define n 8
int main(){
	int t;
	printf("enter the tack length ");
	scanf("%d",&t);
	int m1=0,m2=2*t-1;
	int a[n]={98,183,37,122,14,124,65,67}; 
	int s,index,total=0; 
	printf("enter the starting point ");
	scanf("%d",&s); 
	int diff=999;
	for(int i=0;i<n;i++){
		if(a[i]<s && (s-a[i])<diff){
			diff=s-a[i];
			index=i;
		}
	}
	total+=m2-s+m2+a[index];
	printf("the output for c-scan %d",total);
}
