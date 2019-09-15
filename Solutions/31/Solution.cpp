#include <iostream>
#include <vector>

using namespace std;

int changeCount(int goal, vector<int>& change) {
    vector<int> subchange(goal + 1, 0);
    subchange[0] = 1; // 1 way to make 0.
    for (const auto& coin : change) { 
        for (int i = coin; i <= goal; i++){ 
            subchange[i] += subchange[i - coin];
        }
    }  
    return subchange[goal];
}

int main(int argc, char* argv[]) {
    vector<int> change = { 1, 2, 5, 10, 20, 50, 100, 200 };
    cout << changeCount(200, change) << endl;
    return 0;
}