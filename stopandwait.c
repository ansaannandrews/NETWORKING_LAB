#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct frame {
   int seq;
};

struct frame p;

int expected = 0;
int ack;
int disconnect = 0;
int attempts = 0;

void sender();
void receiver();

int main() {
     srand(time(NULL));
     p.seq = 0;
      while(!disconnect && attempts < 100) {
         sender();
         receiver();
         attempts++;
      }
      
      printf("Transaction finished\n");
      return 0;
}

void sender() {
     printf("SENDER: Sending frame %d\n",p.seq);
}
void receiver() {
     int frame_error = rand() % 5;
     int ack_error = rand() % 5;
     
     if(frame_error == 0) {
        printf("RECEIVER: Frame lost\n");
        printf("SENDER: Timeout -> Resending Frame %d\n",p.seq);
        return;
     }
     
     if(p.seq == expected) {
        printf("RECEIVER: Frame %d received\n",p.seq);
     if(ack_error == 0) {
        printf("RECEIVER: Ack lost\n");
        printf("SENDER: Timeout -> Resending Frame %d\n",p.seq);
        return;
     }
     
     ack = p.seq;
     printf("SENDER: Ack %d received\n",ack);
     
     expected++;
     p.seq++;
     
     
     if(p.seq == 5) {
        disconnect = 1;
     }
}   }











