/**
Исходные данные
Входной поток содержит набор целых чисел Ai (0 ≤ Ai ≤ 1018), 
отделённых друг от друга произвольным количеством пробелов и переводов строк. 
Размер входного потока не превышает 256 КБ.
Результат
Для каждого числа Ai, начиная с последнего и заканчивая первым, 
в отдельной строке вывести его квадратный корень не менее чем с четырьмя знаками после десятичной точки.
*/

#include <iostream>
#include <vector>
#include <cstdint>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int64_t n;
    vector<int64_t> v;
    while (cin >> n) {
        v.push_back(n);
    }
    cout << fixed;
    for (auto it = v.rbegin(); it != v.rend(); ++it) {
        cout << setw(4) << sqrt(*it) << '\n';
    }
    return 0;
}
