#include<stdio.h>
#define INFINITY 999

int main() {
     int n, i, j, k, l;
     printf("Enter the number of routers: ");
     scanf("%d",&n);
     
     int cost[n][n];
     int dist[n][n];
     int nexthop[n][n];
     printf("Enter the cost matrix(Enter 999 for no direct connection):\n");
     for(i = 0;i < n;i++) {
        for(j = 0;j < n;j++) {
           scanf("%d",&cost[i][j]);
           dist[i][j] = cost[i][j];
           if(cost[i][j] != INFINITY && i != j)
              nexthop[i][j] = j;
           else
              nexthop[i][j] = -1;
             
    }   }
    
    //Bellmanford Algorithm
    for(k = 0;k < n;k++) {
        for(i = 0;i < n;i++) {
           for(j = 0;j < n;j++) {
              for(l = 0;l < n;l++) {
                 if(dist[i][l] + dist[l][j] < dist[i][j]) {
                    dist[i][j] = dist[i][l] + dist[l][j];
                    nexthop[i][j] = nexthop[i][l];
     }   }   }   }   }
     
     printf("\nDistance =\n");
     for(i = 0;i < n;i++) {
        printf("\nROUTER %d  ",i);
           for(j = 0;j < n;j++) {
              printf("%d ",dist[i][j]);
     }     }
     
     printf("\n\nNext Hop =\n");
     for(i = 0;i < n;i++) {
        printf("\nROUTER %d  ",i);
           for(j = 0;j < n;j++) {
           if(nexthop[i][j] != -1)
              printf("%d ",nexthop[i][j]);
           else
              printf("- ");
     }     }
}
              
              
              
              
              
              
        
