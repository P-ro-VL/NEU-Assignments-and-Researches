
#include <stdio.h>

int main() {
    char sourcePath[10000];
    char toPath[10000];
    printf(">> Input the source path: ");
    fflush(stdin);
    gets(sourcePath);
    printf(">> Input the path you want to copy to: ");
    fflush(stdin);
    gets(toPath);

    FILE *source = fopen(sourcePath, "r");
    char sourceContent[10000];
    fgets(sourceContent, 100, source);
    fclose(source);

    FILE *to = fopen(toPath, "w");
    fprintf(to, "%s", sourceContent);
    fclose(to);

    printf(">> File has been copied !");
}