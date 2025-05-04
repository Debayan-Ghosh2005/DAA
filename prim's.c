#include<stdio.h>
#include<stdlib.h>
#define max 20
#define INF 999
int min,mincost=0,visited[max],g[max][max];
int prims(int n){
	int i,j,k,v1,v2;
	for(i=1;i<=n;i++)
	   visited[i]=0;
    visited[1]=1;
    for(k=1;k<=n-1;k++){
    	min=999;
    	for(i=0;i<=n;i++){
		 for(j=1;j<=n;j++){
		 	if(g[i][j]!=INF && (visited[i]==1 &&visited[j]==0)){
		 		if(g[i][j]<min){
		 			min=g[i][j];
		 			v1=i;
		 			v2=j;
		 		}
		 	}
		 }
		 }
		 printf("Edge %d =(%d-%d)= %d\n",k,v1,v2,min);
		 visited[v1]=visited[v2]=1;
		 mincost+=min;	
    }
    return mincost;
}
int main(){
	int n,i,j,cost;
	printf("Enter the number of vertices:");
	scanf("%d",&n);
	printf("Enter the adjacency matrix:");
	for(i=1;i<=n;i++){
	   for(j=1;j<=n;j++){
         scanf("%d",&g[i][j]);		
         if(g[i][j]==0)
		 g[i][j]=INF; 
	}
}
   printf("Matrix :\n"); 
   for(i=1;i<=n;i++){ 
   	for(j=1;j<=n;j++){ 
	   if(g[i][j]==INF){
	   	printf("0\t",g[i][j]);
	   }
	   else
   		printf("%d\t",g[i][j]);
   	}
   	printf("\n");
   }
   printf("Minimum spanning tree edges\n");
   cost=prims(n);
   printf("Total cost of mst is %d",cost);
   return 0;
} 
