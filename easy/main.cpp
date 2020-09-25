#include <iostream>
#include <vector>
#include <set>
#include <map>
#include "solution.h"
using namespace std;
 
int main() {
    int num;
    cin >> num;
    vector<int> vec(num);
    for (int i = 0; i < num; ++i){
        int a, b;
        cin >> a >> b;
        vec[i] = a + b;
    }
    for(auto e: vec){
        cout << e << std::endl;
    }
   return 0;
}