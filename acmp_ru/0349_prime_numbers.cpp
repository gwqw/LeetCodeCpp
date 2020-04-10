/**
    349 Простые числа
Необходимо вывести все простые числа от M до N включительно.
Входные данные
Входной файл INPUT.TXT содержит два натуральных числа M и N, разделенных пробелом (2 ≤ M ≤ N ≤ 106)

Выходные данные
В выходной файл OUTPUT.TXT выведите все простые числа от M до N в порядке возрастания, по одному в строке. Если таковых чисел нет, то следует вывести «Absent». 

Example:
2 5 => 2\n3\n5\n
4 4 => Absent\n

Algo: Erathosphen
array a(N+1, true)
a[1] = false
for i from 2 to N:
    if (a[i]) {
        for j = i*i; j <= N; j *= i:
            a[j] = false
    }
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int _ = [](){ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0;}();

int main() {
    ifstream in("INPUT.TXT");
    ofstream out("OUTPUT.TXT");
    int M, N;
    in >> M >> N;
    
    vector<int> sito(N+1, true);
    for (int i = 2; i*i <= N; ++i) {
        if (sito[i]) {
            for (int j = i*i; j <= N; j += i) {
                sito[j] = false;
            }
        }
    }
    
    bool is_outputed = false;
    for (int j = M; j <= N; ++j) {
        if (sito[j]) {
            is_outputed = true;
            out << j << '\n';
        }
    }
    if (!is_outputed) {
        out << "Absent\n";
    }
    
    return 0;
}
