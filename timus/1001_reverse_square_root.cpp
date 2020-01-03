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
#include <stack>
#include <cstdint>
#include <cmath>
#include <iomanip>

using namespace std;

const int ZERO = [](){ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0;}();

int main() {
    int64_t n;
    stack<int64_t> st;
    while (cin >> n) {
        st.push(n);
    }
    cout << fixed;
    while (!st.empty()) {
        cout << setw(4) << sqrt(st.top()) << '\n';
        st.pop();
    }
    return 0;
}
