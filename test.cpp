#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
	int left ;
	int right;
	for(int i = 3;i < 35;i++){
        if(pow(2,i)>=n){
            left = pow(2,i-1);
            right = pow(2,i);
        };

        if (abs(left - n) < abs(right - n))
            printf("%d",left);
        else
            printf("%d",right);
        return 0;
    };
 	return 0;
}