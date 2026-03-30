#include<stdio.h>
int main() {
     int outgoing, bucketsize, n, incoming, store = 0;
     printf("Enter the outgoing rate, bucket size and number of inputs: ");
     scanf("%d %d %d",&outgoing,&bucketsize,&n);
     
     while(n>0) {
          printf("\n\nEnter the incoming packet size: ");
          scanf("%d",&incoming);
          
          printf("Incoming packet size = %d",incoming);
          
          if(incoming <= bucketsize-store)
             store += incoming;
          else {
             printf("\nDropped %d packets",(incoming - (bucketsize-store)));
             store = bucketsize;
          }
          printf("\nBucket buffer size = %d",bucketsize);
          
          if(store >= outgoing)
             store -= outgoing;
          else
             store = 0;
             
        printf("\nAfter outgoing %d out of %d packets left in buffer",store,bucketsize);
        n--;
     }
     printf("\n");
     return 0;
}
           
           
