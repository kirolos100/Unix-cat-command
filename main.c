#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void openfiles(char* x);
void updatefile(char* x);
void remove_chars(char* str, char c1, char c2);
void remove_char(char* str, char c1);
void append(char* filename);
void overwrite(char* filename);

int main()
{    char str[100];
    printf("$./mycat\t");
    gets(str);
    int i;
    if(str!=NULL){

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '<') {
             remove_chars(str, '<', '>');
             updatefile(str);
            break;
        }

        else if (str[i] == '>'&&str[i+1] == '>') {
            remove_chars(str, '>', '>');
             append(str);
            break;


        }


        else if (str[i] == '>') {
             remove_char(str, '>');
             overwrite(str);
            break;
        }



        else{
        openfiles(str);
          break;
    }
    }


   // printf("%s", str);

    //printf("%d",size);

   //< file1 > file2

    }


    return 0;
}

void openfiles(char* x){

    char *y= x;
    char str[10][10];
    strcpy(*str,y);
    char* filenames[30];  // assuming max 30 substrings

    int i = 0;
    char* token = strtok(str, " ");
    while (token != NULL) {
        filenames[i++] = token;
        token = strtok(NULL, " ");
    }

    int num_files = sizeof(filenames) / sizeof(char*);
    //printf("%d",num_files);

    for (int i = 0; i < num_files; i++) {
            int len = strlen(filenames[i]);
            if ( strstr(filenames[i] + len - 4, ".txt")== NULL){ // if it wasn't a txt file
                continue;
            }
        FILE* fp = fopen(filenames[i], "r");
        if (fp == NULL) {
            perror("Error: Could not open file\n"); // if the file wasn't availale
            continue;
        }

        printf("Contents of file %s:\n", filenames[i]);
        char buffer[256];
        while (fgets(buffer, 256, fp)) {
            printf("%s", buffer);
        }

        fclose(fp);
        printf("\n");
    }



}


void updatefile(char* x){
    char *y= x;
    char str[10][10];
    strcpy(*str,y);
    char* filenames[30];  // assuming max 30 substrings

    int i = 0;
    char* token = strtok(str, " ");
    while (token != NULL) {
        filenames[i++] = token;
        token = strtok(NULL, " ");
    }
    FILE *file1, *file2;
    char c;

    // Open file1 for reading
    file1 = fopen(filenames[0], "r");
    if (file1 == NULL) {
        perror("Error opening file\n");
        //return 1;
    }

    // Open file2 for writing
    file2 = fopen(filenames[1], "a");
    if (file2 == NULL) {
        perror("Error opening file\n");
       // return 1;
    }

    // Read file1 character by character and print to console and write to file2
    while ((c = fgetc(file1)) != EOF) {
        printf("%c", c);
        fputc(c, file2);
    }
    printf("\nDone Writing ...");

    // Close both files
    fclose(file1);
    fclose(file2);


}

//remove characters<>
void remove_chars(char *str, char c1, char c2) {
    int i, j;

    // Loop through the string
    for (i = 0, j = 0; str[i] != '\0'; i++) {
        // If the current character is not the one to be removed, keep it
        if (str[i] != c1 && str[i] != c2) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}
void remove_char(char *str, char c1) {
    int i, j;

    // Loop through the string
    for (i = 0, j = 0; str[i] != '\0'; i++) {
        // If the current character is not the one to be removed, keep it
        if (str[i] != c1) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}
void append(char* filename){    //append

 char text[100];
 printf("Enter text to append: ");
   scanf("%s", text);
FILE *fp = fopen(filename, "a");
   if (fp == NULL) {
      perror("Error opening file.\n");
     // return 1;
   }

   // Append the text to the file
   fprintf(fp, "%s", text);

   // Close the file
   fclose(fp);

   printf("Text appended successfully.\n");


}

void overwrite(char* filename){
char text[100];
printf("Enter text to write: ");
   scanf("%s", text);

   // Open the file in write mode
   FILE *fp = fopen(filename, "w");

   if (fp == NULL) {
      perror("Error opening file.\n");
      //return 1;
   }

   // Write the text to the file
   fprintf(fp, "%s", text);

   // Close the file
   fclose(fp);

   printf("Text written successfully.\n");





}





