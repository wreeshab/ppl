#include <iostream>
using namespace std;

class Largest {
public:
    int largest(int a, int b) {
        return (a > b) ? a : b;
    }

    double largestDouble(int a, int b) {
        return (a > b) ? static_cast<double>(a) : static_cast<double>(b);
    }

    void largestPrint(int a, int b) {
        int result = (a > b) ? a : b;
        cout << result << endl;
    }

    float largest(float a, float b) {
        return (a > b) ? a : b;
    }

    void largestPrint(float a, float b) {
        float result = (a > b) ? a : b;
        cout << result << endl;
    }
};

int main() {
    Largest obj;
    int x = 10, y = 20;
    float p = 10.5f, q = 20.7f;

    cout << obj.largest(x, y) << endl;
    cout << obj.largestDouble(x, y) << endl;
    obj.largestPrint(x, y);
    cout << obj.largest(p, q) << endl;
    obj.largestPrint(p, q);

    return 0;
}
