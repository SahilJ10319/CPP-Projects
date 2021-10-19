#include "cmpt_error.h"
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct item{
    string name;
    int count;
};

bool countCheck (const item& x, const item& y) {
    return x.count > y.count;
}

void add_product (const string& name, vector<item>& product) {
    for(int k = 0; k < product.size(); k++) {
        if (name == product[k].name) {
            product[k].count++;
            return;
        }
    }
    product.push_back(item{name, 1});
    return;
}

int main() {
    string name = " ";
    vector<item> product;
    while (cin >> name) {
        add_product(name, product);
    }
    sort(begin(product), end(product), countCheck);
    for (int i = 0; i < 10; i++) {
        cout << "Name: " << product[i].name <<"Count : " << product[i].count << endl;
    }
}