#include<stdio.h>
# define n 5
void swap(int x[],int i,int j){
	int temp=x[i];
	x[i]=x[j];
	x[j]=temp;
}
void sort(int a[],int p[],int b[]){
	for(int i=0;i<n-1;i++){
		for(int j=i;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				swap(a,j,j+1);
				swap(p,j,j+1);
				swap(b,j,j+1);
			}
			
		}
	}
}
int main(){
	int p[10]={1,2,3,4,5};
	int a[10]={0,1,2,3,4};
	int b[10]={2,4,6,1,3};
	//sort(a,b,p);
	int c[10],s=a[0]; 

	int vis[10];
	for(int i=0;i<n;i++){
		vis[i]=0;
	}
	for(int i=0;i<n;i++){
		int min=999;
		int index=0;
		for(int j=0;j<n;j++){
			 if(a[j]<=s &&b[j]<min  && vis[j]==0){
			 	min=b[j];
			 	index=j;
			 }
	 	  
		}
		c[index]=s+b[index];
		s=c[index];
		vis[index]=1;
	}
	int wt[10],t[10];
	for(int i=0;i<n;i++){
		wt[i]=c[i]-a[i];
	}
	for(int i=0;i<n;i++){
		t[i]=wt[i]-b[i];
	}
	float c1=0,c2=0;
	for(int i=0;i<n;i++){
		c1+=wt[i];
		c2+=t[i];
	}
	printf("the avg waaiting time is %.2f \n",c1/n);
	printf("the avg turn around time is %.2f ",c2/n);
}
