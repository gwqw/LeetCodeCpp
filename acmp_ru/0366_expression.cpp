/**
    366 Выражение
    (Время: 0,5 сек. Память: 16 Мб Сложность: 56%)
 Даны N целых чисел X1, X2, …, XN. Требуется расставить между ними знаки «+» и «-» так, чтобы значение получившегося выражения было равно заданному целому S.
Входные данные
Входной файл INPUT.TXT в первой строке содержит числа N и S. В следующей строке располагается N чисел, разделенных пробелом. Ограничения: 2 ≤ N ≤ 24, 0 ≤ Xi ≤ 5*10^7, -10^9 ≤ S ≤ 10^9.

Выходные данные
В выходной файл OUTPUT.TXT выведите «No solution», если такой результат получить невозможно, 
иначе выведите получившееся равенство. Если решение не единственное, выведите любое.
Примеры
INPUT
3 10
15 25 30
OUTPUT
15+25-30=10
INPUT
2 100
10 10
OUTPUT
No solution
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>

using namespace std;

const int _ = [](){ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0;}();

enum class Action {Plus, Minus};

ostream& operator<<(ostream& out, Action act) {
    if (act == Action::Plus) {
        out << '+';
    } else {
        out << '-';
    }
    return out;
}

struct ExprRes {
    int res = 0;
    vector<Action> actions;
};

vector<ExprRes> findExpression(vector<int> a, size_t from, size_t to) {
    assert(to - from >= 2);
    if (to - from == 2) {
        return {ExprRes{a[from] + a[from+1], {Action::Plus}}, ExprRes{a[from] - a[from+1], {Action::Minus}}};
    }
    auto expr = findExpression(a, from+1, to);
    
    vector<ExprRes> res;
    res.reserve(2*expr.size());
    for (const auto& e : expr) {
        res.push_back(ExprRes{
            a[from] + e.res,
            e.actions
        });
        res.back().actions.push_back(Action::Plus);
        res.push_back(ExprRes{
            a[from] - e.res,
            e.actions
        });
        res.back().actions.push_back(Action::Minus);
    }
    return res;
}

ExprRes findExpression(vector<int> a, int target) {
    auto expr = findExpression(a, 0, a.size());
    for (auto& e : expr) {
        if (e.res == target) return move(e);
    }
    return ExprRes{0, {}};
}

int main() {
    ifstream in("INPUT.TXT");
    ofstream out("OUTPUT.TXT");
    int N, target;
    in >> N >> target;
    //cout << N << " " << target << endl;
    vector<int> a(N);
    for (auto& v : a) {
        in >> v;
    }
    
    auto expr = findExpression(a, target);
    
    if (expr.actions.empty()) {
        out << "No solution\n";
    } else {
        assert(expr.actions.size()+1 == N);
        out << a[0];
        for (size_t i = 0; i+1 < N; ++i) {
            out << expr.actions[N-2-i] << a[i+1];
        }
        out << '=' << expr.res << '\n';
    }
    
    
    return 0;
}
