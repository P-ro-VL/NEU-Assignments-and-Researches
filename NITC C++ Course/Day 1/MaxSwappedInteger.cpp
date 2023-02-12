#include <bits/stdc++.h>

using namespace std;

int getMaxIndex(int numbers[]){
    int currentMax = 0;

}

int main() {

    int n;
    cin >> n;

    int numbers[60];
    memset(numbers, 0, sizeof(numbers));

    int index = 0;
    int count = 0;
    while(n != 0){
        int character = n % 10;
        numbers[index] = character;
        n /= 10;
        index++;
        count++;
    }

    int maxNumber = 0;

    while(count--){
        int currentMax = 0;
        int maxIndex = 0;
        for(int i = 0; i < index; i++)
            if(numbers[i] > currentMax){
                currentMax = numbers[i];
                maxIndex = i;
            }

        maxNumber = maxNumber*10 + currentMax;
        numbers[maxIndex] = -1; 
    }

    cout<<maxNumber;

    return 0;
}