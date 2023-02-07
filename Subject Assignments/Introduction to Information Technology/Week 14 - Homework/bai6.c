#include <stdio.h>

int main(){

    for(int muoi = 0; muoi <= 20; muoi++)
        for(int haimuoi = 0; haimuoi <= 10; haimuoi++)
            for(int nammuoi = 0; nammuoi <= 4; nammuoi++)
                if(10000*muoi + 20000*haimuoi + 50000*nammuoi == 200000){
                    printf("%d dong 10k, %d dong 20k, %d dong 50k\n", muoi, haimuoi, nammuoi);
                }

    return 0;
}