# include <stdio.h>

char main(int argc, char *argv[]){
    int i;

    for(i = 1; i < argc; i++){
        if (*argv[i] == '-'){
            printf("%s\n", argv[i]);
        }
    }
}