#include <stdio.h>
#include <math.h>

int main()  {

    int p1x, p1y, p2x, p2y;
    printf("Enter the coordinates of the two points as (x1 y1) (x2 y2): ");
    
    scanf("(%d %d) (%d %d)", &p1x, &p1y, &p2x, &p2y);
    
    float dist = sqrt(pow((float)(p1x - p2x), 2) + pow((float)(p1y - p2y),  2));
    printf("Distance between points: %.2f\n", dist);
    
    return 0;
}
