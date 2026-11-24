#include <stdio.h>
#include <string.h>
#define COUNT 6
#define SIZE 30
void sort_names(char names[COUNT][SIZE]) {
    char temp[SIZE];
    for(int i=0;i<COUNT-1;i++) for(int j=0;j<COUNT-1-i;j++)
        if(strcmp(names[j],names[j+1])>0) {
            strcpy(temp,names[j]); strcpy(names[j],names[j+1]); strcpy(names[j+1],temp);
        }
}
int binary_find(char names[COUNT][SIZE], const char *key) {
    int low=0,high=COUNT-1;
    while(low<=high) {
        int mid=low+(high-low)/2, c=strcmp(names[mid],key);
        if(c==0) return mid;
        if(c<0) low=mid+1; else high=mid-1;
    }
    return -1;
}
int main(void) {
    char names[COUNT][SIZE]={"Meera","Arun","Zoya","Kavin","Arun","Divya"};
    sort_names(names);
    printf("Sorted resident names:\n");
    for(int i=0;i<COUNT;i++) printf("%s\n",names[i]);
    printf("Search Arun: index %d\n",binary_find(names,"Arun"));
    printf("Search Rahul: index %d\n",binary_find(names,"Rahul"));
    printf("Duplicate names:\n");
    for(int i=1;i<COUNT;i++) if(strcmp(names[i],names[i-1])==0) printf("%s\n",names[i]);
    return 0;
}