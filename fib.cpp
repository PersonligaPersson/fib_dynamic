#include <iostream>
#include <vector>
using namespace std;

const unsigned long long fib(int n, vector<unsigned long long> & fib_cache) {
    int val = 0;
    if(fib_cache[n-1] != 0)
        return fib_cache[n-1];
    if(n == 1 || n == 2)
        val = 1;
    else
        val = fib(n-1, fib_cache) + fib(n-2, fib_cache);
    fib_cache[n-1] = val;
    return val;
}

int main(int argc, char * argv[]){
    if(argc != 2){
        cerr << "Usage: fib <int>" << endl;
        exit(EXIT_FAILURE);
    }

    int n = atoi(argv[1]);
    if(n <= 0){
        cerr << "Error: Argument must be a positive integer." << endl;
        exit(EXIT_FAILURE);
    }

    vector<unsigned long long> fib_cache(n);

    cout << fib(n,fib_cache);
    return 0;
}