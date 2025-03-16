#include <iostream>
#include <vector>

using std::deque,std::cout,std::cin;

deque<int> find_binary(int n, int size) {
    deque<int> q;
    int k = n;
    for(int i = 1; i <= k; i++) {
        q.push_front(n % 2);
        n /= 2;
        if (!n) {
            if (q.size()!=size) {
                for (int j = q.size(); j < size; j++) {
                    q.push_front(0);
                }
            }
            return q;
        }
    }
   return q;
}

deque <deque<int>> find_grey_code(int n, int k) {
    deque<deque<int>> q;
    for (int i = 0; i < pow(2,n); i++) {
        q.push_front(find_binary(i, k));
    }
    return q;
}

int main() {
    int n,k;
    cin >> n >> k;
    for (auto i : find_grey_code(n, k)) {
        for (auto j : i) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}