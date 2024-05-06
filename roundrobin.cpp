#include<stdio.h>
# define n 6 
int front=rear=-1;
int queue[n];
 
void swap(int x[],int i,int j){
	int temp=x[i];
	x[i]=x[j];
	x[j]=temp;
}
void sort(int p[],int at[],int bt[]){
	for(int i=0;i<n-1;i++)
	{
		for(int j=i;j<n-i-1;j++){
			if(at[j]>at[j+1]){
				swap(at,j,j+1);
				swap(bt,j,j+1);
				swap(p,j,j+1);
			}
		}
	}
}
int main(){
	int i,sum=0;
	int count=0, y=n;
	int quant=2, wt=0, tat=0;
	int p[n]={1,2,3,4,5,6};
	int at[n]={0,1,2,3,4,5};
	int bt[n]={4,5,2,1,6,3}; 
	 
	sort(p,at,bt);
	int rb[n];
	for(int i=0;i<n;i++){
		rb[i]=b[i];
	}
	for(sum=0, i = 0; y!=0; )  
{  
if(temp[i] <= quant && temp[i] > 0) // define the conditions   
{  
    sum = sum + temp[i];  
    temp[i] = 0;  
    count=1;  
    }     
    else if(temp[i] > 0)  
    {  
        temp[i] = temp[i] - quant;  
        sum = sum + quant;    
    }  
    if(temp[i]==0 && count==1)  
    {  
        y--; //decrement the process no.  
        printf("\nProcess No[%d] \t\t %d\t\t\t\t %d\t\t\t %d", i+1, bt[i], sum-at[i], sum-at[i]-bt[i]);  
        wt = wt+sum-at[i]-bt[i];  
        tat = tat+sum-at[i];  
        count =0;     
    }  
    if(i==NOP-1)  
    {  
        i=0;  
    }  
    else if(at[i+1]<=sum)  
    {  
        i++;  
    }  
    else  
    {  
        i=0;  
    }  
}
	
}
