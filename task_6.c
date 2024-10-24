#define _GNU_SOURCE
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main(int argc, char *argv[]){

    // make sure a file is provided
    if (argc != 2) {
        perror("Enter one file");
        return 1;
    }

    // Open file 
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char *line = NULL;
    unsigned int len = 0;
    int read;

    char *last_line1 = NULL;
    char *last_line2 = NULL;

    // get next line
    while ((read = getline(&line, (size_t *)&len, file)) != -1){
        
        // if somethings in last line 2, free it
        if (last_line2){
            free(last_line2);
        }

        // move last line 1 to last line 2, then add the newline to last line 1
        last_line2 = last_line1;
        last_line1 = strdup(line);
    }

    // print the last lines
    if (last_line2) {
        printf("%s", last_line2);
    }
    if (last_line1) {
        printf("%s\n", last_line1);
    }

    // free memory
    free(line);
    free(last_line1);
    free(last_line2);
    fclose(file);

    return 0;
}