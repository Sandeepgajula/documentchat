#include<stdio.h>
# define n 4
int main(){
	 int a[n]={0,1,2,3};
	 int b[n]={6,4,2,3};
	 int r[n];
	 for(int i=0;i<n;i++){
	 	r[i]=b[i];
	 }
	 int comp=0,c[n];
	 for(int t=0;comp!=n;t++){
	 	int min=999,index;
	 	for(int i=0;i<n;i++){
	 		if(a[i]<=t && r[i]<min && r[i]>0){
	 			min=r[i];
	 			index=i;
			 }
		}
		if(min!=999){
			r[index]--;
		}
		if(r[index]==0){
			c[index]=t+1;
			comp++;
		}
		
	 }
	 for(int i=0;i<n;i++){
	 	printf("%d ",c[i]);
	 }
	 int t[n],w[n];
	 float tavg,wavg;
	 for(int i=0;i<n;i++){
	 	t[i]=c[i]-a[i];
	 }
	 for(int i=0;i<n;i++){
	 	w[i]=t[i]-c[i];
	 }
	 for(int i=0;i<n;i++){
	 	tavg+=t[i];
	 	wavg+=w[i];
	 }
	 printf("The avg turn around time is %.2f ",tavg/n);
	 printf("The avg waiting time is %.2f",wavg/n);
}
