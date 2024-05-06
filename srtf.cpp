#include<stdio.h>
void swap(int a[],int i,int j){
    int t=a[i];
    a[i]=a[j];
    a[j]=t;
}
void sort(int a[],int b[],int p[],int n){
    for(int i=0;i<n;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(a[min]>a[j]){
                min=j;
            }
        }
        swap(a,i,min);
        swap(b,i,min);
        swap(p,i,min);
    }
}
// int CT(int index,int ct,int b[],int c[],int vis[]){
//     c[index]=ct+b[index];
//     ct=c[index];
//     vis[index]=1;
//     return ct;
// }
int main(){
    int n;
    printf("enter number of process :");
    scanf("%d",&n);
    
    int p[n+1],a[n+1],b[n+1],c[n+1],tat[n+1],w[n+1];
    float tsum=0,wsum=0,tavg,wavg;
    printf("enter processess :");
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    printf("enter arrival time :");
    for(int i=0;i<n;i++){
        //printf("\tarrival time :");
        scanf("%d",&a[i]);
    }
    printf("enter burst time :");
    for(int i=0;i<n;i++){
        //printf("\tarrival time :");
        scanf("%d",&b[i]);
        c[i]=0;
    }
    int tb[n+1];   //temp_burst_time
    for(int i=0;i<n;i++){
        tb[i]=b[i];
    }
    sort(a,b,p,n);
    // for(int i=0;i<n;i++){
    //     if(i==0 || c[i-1]<a[i]){
    //         c[i]=a[i]+b[i];
    //     }
    //     else{
    //         c[i]=c[i-1]+b[i];
    //     }
    // }
    int ct=a[0];
    int vis[n+1];
    for(int i=0;i<n;i++){
        vis[i]=0;
    }
    for(int i=0;i<n;i++){
        int min=99999;
        int index=-1;
        int p;
        if(i<n-1){
            p=a[i+1]-a[i];
        }
        for(int j=0;j<n;j++){
            if(a[j]<=ct && b[j]<min && vis[j]==0){
                min=b[j];
                index=j;
            }
        }
        b[index]=b[index]-p;
        c[index]=ct+p;
        ct=c[index];
        if(b[index]==0){
            vis[index]=1;
        }
       // ct=CT(index,ct,b,c,vis);
    }
    for(int i=0;i<n;i++){
        int min=99999;
        int index=-1;
        for(int j=0;j<n;j++){
            if(b[j]<min && vis[j]==0){
                min=b[j];
                index=j;
            }    
        }
        c[index]=ct+b[index];
        ct=c[index];
        vis[index]=1;

    }
    for(int i=0;i<n;i++){
        tat[i]=c[i]-a[i];
        tsum=tsum+tat[i];
    }
    for(int i=0;i<n;i++){
        w[i]=tat[i]-tb[i];
        wsum=wsum+w[i];
    }
    tavg=tsum/n;
    wavg=wsum/n;
    printf("AT\tBT\tPID\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\tP%d\t%d\t%d\t%d\n",a[i],tb[i],p[i],c[i],tat[i],w[i]);
    }
    printf("tat avg :%f\nwt avg :%f",tavg,wavg);
}
