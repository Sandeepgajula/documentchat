#include<stdio.h>
void swap(int x[],int a,int b){
	int temp=x[a];
	x[a]=x[b];
	x[b]=temp;
	
}
void sort(int p[],int a[],int b[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				swap(a,j+1,j);
				swap(b,j+1,j);
				swap(p,j+1,j);
			}
			 
		}
	}
}
int main(){
	int m=5;
	int p[15]={1,2,3,4,5};
	int a[51]={0,1,2,3,4};
	int b[15]={2,4,6,1,3};
   // sort(p,a,b,5);
    int t[15];
    int c[15];
    int w[15];
 	c[0]=b[0]+a[0];
    for(int i=1;i<m;i++){
    	 int min=999;
    	c[i]=c[i-1]+b[i];
    	if(c[i]<a[i+1]){
    		c[i]=c[i]+(a[i+1]-c[i]);
		}
		if(c[i]>a[i])
			for(int j=0;j<m-i;j++){
				if(min>b[i]){
				    min=b[i];
			    }
			c[i]=c[i-1]+min;
			}
	
	
		
			
		}
	
	
    for(int i=0;i<m;i++){
    	 printf("%d  ",c[i]);
	}
	
	for(int i=0;i<m;i++){
    	 t[i]=c[i]-a[i];
    
	}
	for(int i=0;i<m;i++){
    	 w[i]=t[i]-b[i];
    
	}
	float avt=0,avw=0;
	for(int i=0;i<m;i++){
        avt+=t[i];
        avw+=w[i];
    
	}
	printf("\n");
	printf("the average turn around time is %.2f",(avt)/5);
	printf("\n");
	printf("the average waiting time is %.2f",avw/5);
	
}
