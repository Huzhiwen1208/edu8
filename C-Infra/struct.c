#include <stdio.h>

struct iphone{
    char brand[30];
    int size;
    int color;
    double price;
    int inventory;
    int sale_amount;
};

int main() {
    int a;
    struct iphone ios;
    ios.size = 7;
    ios.price = 9999.99;
    ios.color = 1;
    ios.inventory = 100;

    return 0;
}