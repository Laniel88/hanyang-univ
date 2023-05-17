#include <stdio.h>
#include <stdlib.h>

FILE *fin;
FILE *fout;

long long sum_betwwen_two(int a, int b) {
    return a+b;
}

int main(int argc, char **argv) {
    fin=fopen(argv[1], "r");
    fout=fopen(argv[2], "w");

    int a,b;
    long long sum;

    while(fscanf(fin, "%d%d", &a, &b)!=EOF){
        sum=sum_betwwen_two(a,b);
        fprintf(fout, "sum of (%d) and (%d) is %lld\n", a, b, sum);
    }

    fclose(fin);
    fclose(fout);

    return 0;
}