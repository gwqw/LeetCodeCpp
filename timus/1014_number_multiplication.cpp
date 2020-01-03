/**
    1014. Произведение цифр
    Ограничение времени: 1.0 секунды
    Ограничение памяти: 64 МБ
Ваша задача — найти минимальное положительное целое число Q такое, что произведение цифр числа Q в точности равняется N.
Исходные данные
Целое число N (0 ≤ N ≤ 109).
Результат
Выведите целое число Q. Если такого числа не существует, выведите −1.

Пример
исходные данные	результат
10              25

Algo: O(sqrt(N))
- find all simple mults (they will be already sorted) O(sqrt(N))
    - go from 2 to sqrt(n)
    - while is mult
        - add it to array
        - divide on it
- if max > 9: break
- go through end and try to combine numbers
- output number O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

const int ZERO = [](){ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0;}();

int main() {
    int n;
    cin >> n;
    if (n < 10) {
        if (n) {
            cout << n << endl;
        } else {
            cout << 10 << endl;
        }
        return 0;
    }
    
    vector<int> res;    
    for (int i = 9; i >= 2; --i) {
        while (n % i == 0) {
            res.push_back(i);
            n /= i;
        }
    }
    if (n != 1) {
        cout << -1 << endl;
        return 0;
    }
    
    for (auto it = res.rbegin(); it != res.rend(); ++it) {
        cout << *it;
    }
    cout << endl;

    return 0;
}
