#include<stdio.h>

void main(){
    int nob,nop,i,j;
    printf("Enter no of blocks: ");
    scanf("%d",&nob);
    printf("Enter no of processes: ");
    scanf("%d",&nop);
    int p[nop],b[nob],ba[nob],pa[nop];
    printf("Enter block sizes: ");
    for(i=0;i<nob;i++){
        scanf("%d",&b[i]);
        ba[i] = -1;
    }
    printf("Enter process sizes: ");
    for(i=0;i<nop;i++){
        scanf("%d",&p[i]);
    }
    for(i=0;i<nop;i++){
        for(j=0;j<nob;j++){
            if(p[i]<=b[j] && ba[j]==-1){
                ba[j] = 1;
                pa[i] = j+1;
                break;
            }
        }
    }
    printf("P_No\tP_size\tB_allocated\n");
    for(i=0;i<nop;i++){
        printf("%d\t%d\t",i+1,p[i]);
        if(pa[i]!=-1)
        printf("%d\n",pa[i]);
        else
        printf("Not allocated\n");
    }
}