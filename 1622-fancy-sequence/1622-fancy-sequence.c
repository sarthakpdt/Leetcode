#include <stdlib.h>

#define MOD 1000000007

typedef struct {
    long *nums;
    int size;
    int capacity;
    long cur_mul;
    long cur_add;
} Fancy;

long power(long base, long exp) {
    long res=1;
    base%=MOD;
    while (exp>0) {
        if (exp%2==1) res=(res*base)%MOD;
        base=(base*base)%MOD;
        exp/=2;
    }
    return res;
}

long modInverse(long n) {
    return power(n, MOD-2);
}

Fancy* fancyCreate() {
    Fancy* obj=(Fancy*)malloc(sizeof(Fancy));
    obj->capacity=100001;
    obj->nums=(long*)malloc(sizeof(long)*obj->capacity);
    obj->size=0;
    obj->cur_mul=1;
    obj->cur_add=0;
    return obj;
}

void fancyAppend(Fancy* obj, int val) {
    long invMul=modInverse(obj->cur_mul);
    long normalized=(val-obj->cur_add+MOD)%MOD;
    normalized=(normalized*invMul)%MOD;
    obj->nums[obj->size++]=normalized;
}

void fancyAddAll(Fancy* obj, int inc) {
    obj->cur_add=(obj->cur_add+inc)%MOD;
}

void fancyMultAll(Fancy* obj, int m) {
    obj->cur_mul=(obj->cur_mul*m)%MOD;
    obj->cur_add=(obj->cur_add*m)%MOD;
}

int fancyGetIndex(Fancy* obj, int idx) {
    if (idx>=obj->size) return -1;
    long res=(obj->nums[idx]*obj->cur_mul)%MOD;
    res=(res+obj->cur_add)%MOD;
    return (int)res;
}

void fancyFree(Fancy* obj) {
    free(obj->nums);
    free(obj);
}