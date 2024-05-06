#include<stdio.h>
int main(){
	int n=5; 
//	for(int i=0;i<n;i++){
//		for(int j=0;j<3;j++){  
//	    printf("enter the values %d %d",i,j);
//	    scanf("%d",&a[i][j]);
//		}
//	}	
//	printf("MAX matrix"); 
//	for(int i=0;i<n;i++){
//		for(int j=0;j<3;j++){  
//	    printf("enter the values %d %d",i,j);
//	    scanf("%d",&b[i][j]);
//		}
//	}	
    int a[5][3] = { { 0, 1, 0 }, // P0 // Allocation Matrix
						{ 2, 0, 0 }, // P1
						{ 3, 0, 2 }, // P2
						{ 2, 1, 1 }, // P3
						{ 0, 0, 2 } }; // P4

	int b[5][3] = { { 7, 5, 3 }, // P0 // MAX Matrix
					{ 3, 2, 2 }, // P1
					{ 9, 0, 2 }, // P2
					{ 2, 2, 2 }, // P3
					{ 4, 3, 3 } };
	int available[3]={3,3,2};
	int need[n][3];
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){  
		   need[i][j]=b[i][j]-a[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){  
		   printf("%d ",need[i][j]);
		}
		printf("\n");
	}
	int r[n],index=0;
	int f[n];
	for(int i=0;i<n;i++){
		f[i]=0;
	} 
	for(int k=0;k<5;k++){
	for(int i=0;i<n;i++){
		if(f[i]==0){ 
		int flag=0;
		for(int j=0;j<3;j++){  
		  if(need[i][j] > available[j]){
		    flag=1;
		    break;
		  	 
		  }
		}
	
	   if(flag==0){
	   	r[index++]=i;
	   	for(int y=0;y<3;y++){
	   		 available[y]+=a[i][y];
	   		 
		   }
		f[i]=1;   
	   }}
	}}

   for(int i=0;i<n;i++){ 
   	 	 printf("%d ",r[i]); 
   }
}
