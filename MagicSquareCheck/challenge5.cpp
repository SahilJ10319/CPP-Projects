#include "cmpt_error.h"
#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool magic_square_check(const int x[]) {
    int u1_sum(0), u2_sum(0), u3_sum(0);
    int c1_sum(0), c2_sum(0), c3_sum(0);
    int d1_sum(0), d2_sum(0);

    u1_sum = x[0] + x[1] + x[2];
    u2_sum = x[3] + x[4]+ x[5];
    u3_sum = x[6] + x[7] + x[8];

    c1_sum = x[0] + x[3] + x[6];
    c2_sum = x[1] + x[4] + x[7];
    c3_sum = x[2] + x[5] + x[8];

    d1_sum = x[0] + x[4] + x[8];
    d2_sum = x[2] + x[4] + x[6];

    if (u1_sum == u2_sum && u2_sum == u3_sum) {
        if (c1_sum == c2_sum && c2_sum == c3_sum) {
            if (d1_sum == d2_sum) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int count = 0;
    int numbers[] = {16, 37, 1, 3, 18, 33, 35, -1, 20};
    sort(numbers, numbers + 9);

    do {
        if (magic_square_check(numbers)) count ++;
    } while (next_permutation(numbers, numbers + 9));
    cout << "Count: " << count << endl;
}