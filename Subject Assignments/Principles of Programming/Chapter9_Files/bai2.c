#include <stdio.h>

int main() {
    char sourcePath[10000];
    char distPath[10000];

    printf(">> Input the source path: ");
    fflush(stdin);
    gets(sourcePath);
    printf(">> Input the dist path: ");
    fflush(stdin);
    gets(distPath);

    FILE *source = fopen(sourcePath, "r");
    char sourceContent[10000];
    fgets(sourceContent, 100, source);
    fclose(source);

    FILE *dist = fopen(distPath, "a+");
    fprintf(dist, "%s", sourceContent);
    fclose(dist);

    printf(">> Source content concatnated.");
}