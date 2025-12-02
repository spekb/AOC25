//run using xargs and redirect the input file in
#include <stdio.h>
#include <stdlib.h>
int password=0;
long turn(long currentPosition, long value){
    currentPosition=(currentPosition+value)%100;
    if (currentPosition==0) password++;
    return currentPosition;
}

int main(int argc, char *argv[]) {
    int currentPosition=50;
    for(int i=1;i<argc;i++){
        long value = ((argv[i][0]=='R') ? 1:-1)*strtol(argv[i]+1,0,10);
        fprintf(stderr,"%s\n",argv[i]);
        currentPosition=turn(currentPosition, value);
    }
    printf("Password: %d\n",password);
	return 0;
}