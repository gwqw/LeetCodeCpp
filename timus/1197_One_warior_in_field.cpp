/**
Исходные данные
В первой строке находится единственное число N, 1 ≤ N ≤ 100 — количество тестов. В каждой из последующих N строк содержится очередной тест: два символа (маленькая латинская буква от 'a' до 'h' и цифра от 1 до 8) — стандартное шахматное обозначение клетки, на которой стоит конь. При этом буква обозначает вертикаль, а цифра — горизонталь.
Результат
Выведите N строк: в каждой из них должно находиться единственное число — количество клеток шахматной доски, находящихся под боем коня.
Пример
исходные данные	результат
3
a1      2
d4      8
g6      6

Algo: 
- get x, y
- calc dist_x dist_y to the edge
- steps = 8 (max_steps)
- map dist to out: 0,0 -> 6, 0,1 -> 5, 1,1 -> -4, x,0 -> -4, x,1 -> -2, x,y -> 0
- output result
*/

#include <iostream>
#include <string>

using namespace std;

const int ZERO = [](){ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0;}();

int get_dist(int x) {
    return min(x, 7-x);
}

int get_out(int x, int y) {
    if (x == 0) {
        if (y == 0) return -6;
        if (y == 1) return -5;
        return -4;
    } else if (x == 1) {
        if (y == 0) return -5;
        if (y == 1) return -4;
        return -2;
    } else {
        if (y == 0) return -4;
        if (y == 1) return -2;
        return 0;
    }
}

int main() {
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        int x = s[0] - 'a';
        int y = s[1] - '1';
        cout << 8 + get_out(get_dist(x), get_dist(y)) << '\n';
    }
    return 0;
}
