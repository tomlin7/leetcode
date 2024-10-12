#include<stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp = fopen("test.txt", "w"),
        *fp1 = fopen("test1.txt", "w"); 

    if(!fp1) exit(5);

    int ch;
    do{
        ch = getc(fp);
        putc(ch, fp1);
    } while(!feof(fp));

    fclose(fp);
    fclose(fp1);
    system("pause");
}