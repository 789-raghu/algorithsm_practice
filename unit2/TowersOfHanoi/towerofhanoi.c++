#include<bits/stdc++.h>

using namespace std;

void tower_of_hanoi(int diskNumber,char source,char desitination,char helper){
    if(diskNumber==1){
        printf("Move disk %d from %c to %c\n",diskNumber,source,desitination);
        return;
    }

    tower_of_hanoi(diskNumber-1,source,helper,desitination);
    printf("Move disk %d from %c to %c\n", diskNumber,source,desitination);
    tower_of_hanoi(diskNumber-1,helper,desitination,source);
}

int main(){
    char source = 'a',destionation = 'c',helper = 'b';
    tower_of_hanoi(3,source,destionation,helper);
    return 0;
}