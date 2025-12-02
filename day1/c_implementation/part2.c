//run using xargs and redirect the input file in
#include <stdio.h>
#include <stdlib.h>

long password=0;
long turn(long currentPosition, long value){
    if(value<0){
        value*=-1;
        while(value>0){
            value--;
            if(!currentPosition) currentPosition=99;
            else currentPosition--;
            if(!currentPosition) password++;
        }
    }
    else{
        while(value>0){
            value--;
            if(currentPosition==99){
                currentPosition=0;
                password++;
            }
            else currentPosition++;
        }
    }
    return currentPosition;
}

int main(int argc, char *argv[]) {
    long currentPosition=50;
    for(int i=1;i<argc;i++){
        long value = ((argv[i][0]=='R') ? 1:-1)*strtol(argv[i]+1,0,10);
        fprintf(stderr,"%s\n",argv[i]);
        currentPosition=turn(currentPosition, value);
    }
    printf("Password: %ld\n",password);
	return 0;
}