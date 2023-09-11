#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double computeMedian(double*,int*);

int main()
{

    int size;
    printf("Size: ");
    scanf("%d", &size);

    double *data = (double*) malloc(sizeof(double) * size);

    for (int x = 0; x < size; x++)
        scanf("%lf", &data[x]);

    double median = computeMedian(data,&size);

    printf("%.1lf",median);

    free(data);

    return 0;
}

double computeMedian(double *data, int *size){

    for(int x = 1;x < *size;x++){
        if(data[x]<data[x-1]){
            double temp = data[x];
            data[x] = data[x-1];
            data[x-1] = temp;
        }
    }

    return ((*size%2==0)? ((data[*size/2]-1)+(data[*size/2]))/2:data[*size/2]);
}
