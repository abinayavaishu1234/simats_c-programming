#include <stdio.h>
#define ROWS 3
#define MONTHS 4
void analyse(const double rain[ROWS][MONTHS]) {
    double stateTotal=0, max=-1; int wetRow=0,wetMonth=0;
    double rowTotal[ROWS]={0};
    for(int i=0;i<ROWS;i++) for(int j=0;j<MONTHS;j++) {
        rowTotal[i]+=rain[i][j]; stateTotal+=rain[i][j];
        if(rain[i][j]>max) { max=rain[i][j]; wetRow=i; wetMonth=j; }
    }
    double stateAverage=stateTotal/(ROWS*MONTHS);
    printf("State average rainfall: %.2f mm\n",stateAverage);
    for(int i=0;i<ROWS;i++) printf("District %d annual total: %.2f mm\n",i+1,rowTotal[i]);
    printf("Wettest record: District %d, Month %d = %.2f mm\n",wetRow+1,wetMonth+1,max);
    printf("Below 60%% of state average: ");
    for(int i=0;i<ROWS;i++) if(rowTotal[i]/MONTHS < 0.60*stateAverage) printf("District %d ",i+1);
    printf("\n");
}
int main(void) {
    const double rain[ROWS][MONTHS]={{80,60,40,20},{30,25,35,20},{100,120,90,110}};
    analyse(rain); return 0;
}