#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int compare(const void *a,const void *b){
    return strcmp((const char *)a,(const char *)b);
    }
int binary_search(char arr[][20],int left,int right,const char *target){
    while(left<=right){
        int mid=left+(right-left)/2;
        int cmp=strcmp(arr[mid],target);
        if(cmp==0){return 1;}
        else if(cmp<0){left=mid+1;}
        else{right=mid-1;}
}
return 0;
}
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int i;
    char yesterday[n][20],found[m][20],newi[k][20];
    for(i=0;i<n;i++){
        scanf("%s",yesterday[i]);
        }
    for(i=0;i<m;i++){
        scanf("%s",found[i]);
        }
    for(i=0;i<k;i++){
        scanf("%s",newi[i]);
        }
    qsort(found,m,sizeof(found[0]),compare);
    int cnt=0;
    char tomorrow[n+k][20];
    for(i=0;i<n;i++){
        if(!binary_search(found,0,m-1,yesterday[i]))
        {
            strcpy(tomorrow[cnt++],yesterday[i]);
            }
            }
    for(i=0;i<k;i++){
        strcpy(tomorrow[cnt++],newi[i]);
        }
    qsort(tomorrow,cnt,sizeof(tomorrow[0]),compare);
    for(i=0;i<cnt;i++){
        printf("%s\n",tomorrow[i]);
        }
    return 0;
}