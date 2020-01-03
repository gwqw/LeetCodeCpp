/**
    1352. Простые числа Мерсенна
    Ограничение времени: 1.0 секунды
    Ограничение памяти: 64 МБ
Определение. Если число 2^N−1 простое, то оно называется простым числом Мерсенна.
Например, 2^2−1 — первое простое число Мерсенна, 2^3−1 — второе, 2^11213−1 — 23-e, 2^216091−1 — 31-e.
Искать эти числа без компьютера довольно тяжело. Так, Эйлер в 1772 году нашёл 8-е число, 231−1, но после этого в течение 100 лет не было найдено ни одного! Лишь в 1876 Люк показал, что 2127−1 — простое число. Но он нашел не 9-е, а сразу 12-е, так как 261−1, 289−1, 2107−1 — тоже простые, но были найдены позднее. Новый прорыв случился лишь в 1950-х, когда с помощью вычислительной техники были найдены простые числа Мерсенна с показателями 521, 607, 1279, 2203, 2281. Все последующие числа Мерсенна были найдены с помощью ЭВМ. И для этого не нужно было быть великим математиком, в 1978 и 1979 годах студенты Нолл и Никел нашли 25-е и 26-е числа (21701 и 23209) на мэйнфрейме своего университета, чем и прославились на всю Америку. Но и у современных суперкомпьютеров есть пределы возможностей. Сегодня простые числа Мерсенна ищут десятки тысяч людей по всему миру, объединённые одним метапроектом GIMPS (Great Internet Mersenne Prime Search, www.mersenne.org). На счету GIMPS уже 8 самых больших простых чисел Мерсенна. Их показатели — 1398269, 2976221, 3021377, 6972593, 13466917, 20996011, 24036583, 25964951. 26972593−1 является 38-м простым числом Мерсенна, а про последние 4 ещё нельзя сказать, какие они по счету, т.к. ещё не все меньшие числа проверены. Эти же 4 числа являются самыми большими известными простыми числами.
Последнее число — 225964951−1 — было найдено 18 февраля 2005 года, оно состоит из 7816230 десятичных цифр, тот же, кто найдёт простое число более чем из 10 миллионов цифр, получит приз в $100000. Эти деньги можете выиграть и Вы, если присоединитесь к проекту.

В этой задаче N не превосходит 38. Итак, Вам даётся N, от Вас требуется найти N-е по порядку простое число Мерсенна.
Исходные данные
В первой строке дано число T — количество тестов. В каждой из последующих T строк дано число N.
Результат
Для каждого числа N выведите показатель N-го по порядку простого числа Мерсенна.

Пример
исходные данные
13
18
32
24
21
19
34
27
33
20
30
28
29
22

результат
3217
756839
19937
9689
4253
1257787
44497
859433
4423
132049
86243
110503
9941

Algo: cheat:
take table from task description and get primes from here
*/

#include <iostream>
#include <vector>

using namespace std;

const int ZERO = [](){ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0;}();

int get_mersenne_prime_exp(int n) {
    static constexpr int A000043[] =            {0,2,3,5,7,13,17,19,31,61,89,107,127,521,607,1279,2203,2281,3217,4253,4423,9689,9941,11213,19937,21701,23209,44497,86243,110503,132049,216091,756839,859433,1257787,1398269,2976221,3021377,6972593};
    return A000043[n];    
}

int main() {
    int cnt, n;
    cin >> cnt;
    for (int i = 0; i < cnt; ++i) {
        cin >> n;
        int p = get_mersenne_prime_exp(n);
        cout << p << endl;
    }
    return 0;
}



