#include <stdio.h>
#include <stdlib.h>

FILE *fin;
FILE *fout;

//greatest common divison
int gcd(int a, int b) {
    // 유클리드 호제법 사용, 재귀 사용
    if(a%b == 0)
        return b;
    else
        return gcd(b, a%b);
}

//least common multiple
int lcm(int a, int b) {
    return (a*b/gcd(a,b)); // 두 수의 곱을 최대공약수로 나눠줌
}

int main(int argc, char **argv) {
    fin=fopen(argv[1], "r");
    fout=fopen(argv[2], "w");
    
    int a,b;
    int gcd_value;
    int lcm_value;

    while(fscanf(fin,"%d%d", &a, &b)!=EOF) {
        gcd_value = gcd(a,b);
        fprintf(fout, "gcd value:%d ", gcd_value);
        lcm_value = lcm(a,b);
        fprintf(fout, "lcm value:%d\n", lcm_value);
    }

    fclose(fin);
    fclose(fout);

    return 0;
}