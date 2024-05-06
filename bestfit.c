 #include<stdio.h>
int main()
{
	int n,i,j,l,m;
	printf("enter no.of blocks: ");
	scanf("%d",&n); 
	int b[n],p[4];
    for(l=0;l<n;l++) { 
	    printf("enter %d block size : ",l); 
    	scanf("%d",&b[l]);
	}
	for(m=0;m<4;m++) { 
	    printf("enter %d process size : ",m); 
    	scanf("%d",&p[m]);
	}
	int allocated[4],x; 
	for(x=0;x<n;x++) {  
	    allocated[x]=-1;
	}
    for(i=0;i<n;i++){
		int index=-1;
		for(j=0;j<n;j++){
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
			allocated[i]=index;
			b[index]-=p[i];
		}
		
	}
	int y;
	for(y=0;y<n;y++) {  
	    if(allocated[y]==-1){
	    	printf("thr process is not allocated \t");
		} 
		else{
			printf("%d \t",allocated[y]+1);
		} 
	}
	 
    
}
