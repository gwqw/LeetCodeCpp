#include <iostream>
#include <fstream>
 
using namespace std;
 
int main() {
    ifstream in("INPUT.TXT");
    ofstream out("OUTPUT.TXT");
    int a, b;
    in >> a >> b;
    out << a + b;
}

#include <iostream>
 
using namespace std;
 
int main() {
    int a, b;
    cin >> a >> b;
    cout << a + b;
}
