#include<bits/stdc++.h>
using namespace std;

int recursive(int n){
    if(n <= 1){
        return n;
    }
    return recursive(n-1) + recursive(n-2);
}

int iterative(int n){
    if(n<=1){
        return n;
    }

    int first = 0;
    int second = 1;

    for(int i = 2;i<= n; i++){
        int next = first + second;
        first = second;

        second = next;
    }
    return second;
}

int main(){
    int n;
    cin>>n;
    int ans1 = recursive(n);
    cout<<ans1<<endl;

    int ans2 = iterative(n);
    cout<<ans2<<endl;
}