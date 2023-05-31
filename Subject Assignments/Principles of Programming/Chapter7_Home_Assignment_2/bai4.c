#include <stdio.h>
#include <string.h>
 
char toupper(char charx){
    if(charx >= 'a' && charx <='z') charx = charx-32;
    return charx;
}
 
void chuanHoa(char a[])
{
    int n = strlen(a); //Lấy độ dài xâu

    for(int i=0;i<n;i++){
        if(a[i]==' '){
            for(int j=i;j<n-1;j++){
                a[j] = a[j+1];
            }
            a[n-1]=NULL;
            i--;
            n--;
        }
        else break;
    }

    for(int i=n-1;i>=0;i--){
        if(a[i]==' '){
            a[i]=NULL;
            n--;
        }
        else break;
    }
     
    for(int i=1;i<n-1;i++)
    {
        if(a[i]==a[i+1]){
            for(int j=i;j<n-1;j++){
                a[j] = a[j+1];
            }
            a[n-1]=NULL;
            i--;
            n--;
        }
    }
     
    a[0] =  toupper(a[0]);  
}

int main()
{
    char s[100];
    gets(s);
    chuanHoa(s);

    int count = 1;
    for (int i = 0; i < 100; i++){
        if(s[i] == ' ')
            count++;
    }
    printf("Word Count: %d", count);
}