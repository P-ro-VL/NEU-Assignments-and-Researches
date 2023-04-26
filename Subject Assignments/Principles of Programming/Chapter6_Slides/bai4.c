#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float max(float a, float b){
    return a >= b ? a : b;
}

float min(float a, float b){
    return a >= b ? b : a;
}

int isCollided(float xa, float xb, float ya, float yb, float xm, float ym, float radius){
    float m = (yb - ya) / (xb - xa);
    float b = (ya - m * xa);

    float maxX = max(xa, xb);
    float currentX = min(xa, xb), currentY;
    while(currentX <= maxX) {
        currentX += 0.1;
        currentY = m * currentX + b;

        float dist = sqrt((xm - currentX) * (xm - currentX) + (ym - currentY) * (ym - currentY));

        if(radius > dist)
        {
            return 1;
        }
    }
    return 0;
}

int main(){
    float xa, xb, xc, xm, ya, yb, yc, ym;
    scanf("%f %f", &xa, &ya);
    scanf("%f %f", &xb, &yb);
    scanf("%f %f", &xc, &yc);
    scanf("%f %f", &xm, &ym);

    int collideCheck = 0;
    float radius = 0.0;
    while(collideCheck == 0){
        radius += 0.0001;
        collideCheck = isCollided(xa, xb, ya, yb, xm, ym, radius) 
                    || isCollided(xa, xc, ya, yc, xm, ym, radius)
                    || isCollided(xb, xc, yb, yc, xm, ym, radius);
    }

    printf("%f", radius);
}