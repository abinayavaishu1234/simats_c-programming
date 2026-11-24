#include <stdio.h>
#define CANDIDATES 4
#define VOTES 12
int main(void) {
    int votes[VOTES]={1,2,1,4,0,3,2,1,5,-1,4,2};
    int count[CANDIDATES+1]={0},valid=0,invalid=0;
    for(int i=0;i<VOTES;i++) {
        if(votes[i]>=1 && votes[i]<=CANDIDATES) { count[votes[i]]++; valid++; }
        else invalid++;
    }
    printf("Valid votes: %d\nInvalid votes: %d\n",valid,invalid);
    for(int i=1;i<=CANDIDATES;i++) printf("Candidate %d: %d votes\n",i,count[i]);
    int order[CANDIDATES],max=-1;
    for(int i=1;i<=CANDIDATES;i++) { order[i-1]=i; if(count[i]>max) max=count[i]; }
    for(int i=0;i<CANDIDATES-1;i++) for(int j=0;j<CANDIDATES-1-i;j++)
        if(count[order[j]]<count[order[j+1]]) { int t=order[j];order[j]=order[j+1];order[j+1]=t; }
    printf("Ranking:\n");
    for(int i=0;i<CANDIDATES;i++) printf("%d. Candidate %d - %d votes\n",i+1,order[i],count[order[i]]);
    int winners=0;
    for(int i=1;i<=CANDIDATES;i++) if(count[i]==max) winners++;
    if(winners>1) {
        printf("Result: Tie between");
        for(int i=1;i<=CANDIDATES;i++) if(count[i]==max) printf(" Candidate %d",i);
        printf("\n");
    } else {
        for(int i=1;i<=CANDIDATES;i++) if(count[i]==max) printf("Winner: Candidate %d\n",i);
    }
    return 0;
}