#include <iostream>
#include <vector>

using namespace std;

vector<bool> generateprime_bools(int n){
    vector<bool> isprime(n,true);
    isprime[0]=isprime[1]=true;

    for(int i=2; i*i<n ; i++){
        if(isprime[i]){
            for(int j=i*i; j<=n; j+=i){
                isprime[j]=false;
            }
        }
    }
    return isprime;
}

int main(){
    int n;
    cout<<"Enter a value for n: ";
    cin>>n;

    vector<bool> isprime = generateprime_bools(n);

    for(int i=2; i<=n; i++){
        if(isprime[i]){
            cout<<i<<" ";
        }
    } 
}
