/**
Исходные данные
В единственной строке записано целое число n (1 ≤ n ≤ 2000) — количество монстров.
Результат
Выведите слово, соответствующее данному количеству монстров на языке аниндилъяква.

Количество 	Обозначение на русском языке 	Обозначение на языке аниндилъяква
от 1 до 4 	несколько 	few
от 5 до 9 	немного 	several
от 10 до 19 	отряд 	pack
от 20 до 49 	толпа 	lots
от 50 до 99 	орда 	horde
от 100 до 249 	множество 	throng
от 250 до 499 	сонмище 	swarm
от 500 до 999 	полчище 	zounds
от 1000 	легион 	legion

Примеры
исходные данные	
7
40
результат
several
lots

Algo:
- read number
- check using if-else
- output word
*/

#include <iostream>

using namespace std;

const int ZERO = [](){ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0;}();

int main() {
    int n;
    cin >> n;
    if (n >= 1000) {
        cout << "legion\n";
    } else if (n >= 500) {
        cout << "zounds\n";
    } else if (n >= 250) {
        cout << "swarm\n";
    } else if (n >= 100) {
        cout << "throng\n";
    } else if (n >= 50) {
        cout << "horde\n";
    } else if (n >= 20) {
        cout << "lots\n";
    } else if (n >= 10) {
        cout << "pack\n";
    } else if (n >= 5) {
        cout << "several\n";
    } else {
        cout << "few\n";
    }
    return 0;
}
