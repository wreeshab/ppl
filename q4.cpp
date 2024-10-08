#include <iostream>
using namespace std;

class matrix {
public:
    int rows;
    int columns;
    int arr[10][10];

    matrix(int a, int b) {
        rows = a;
        columns = b;
    }

    void get_input() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cout << "Enter element at (" << i << ", " << j << "): ";
                cin >> arr[i][j];
            }
        }
    }

    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    int get_element(int i, int j) {
        return arr[i][j];
    }

    int get_rows() {
        return rows;
    }

    int get_columns() {
        return columns;
    }
};

class add_matrix : public matrix {
public:
    add_matrix(int r, int c) : matrix(r, c) {}

    void add(matrix &m1, matrix &m2) {
        if (m1.get_rows() == m2.get_rows() && m1.get_columns() == m2.get_columns()) {
            for (int i = 0; i < m1.get_rows(); i++) {
                for (int j = 0; j < m1.get_columns(); j++) {
                    arr[i][j] = m1.get_element(i, j) + m2.get_element(i, j);
                }
            }
        } else {
            cout << "Matrices cannot be added" << endl;
        }
    }

    void subtract(matrix &m1, matrix &m2) {
        if (m1.get_rows() == m2.get_rows() && m1.get_columns() == m2.get_columns()) {
            for (int i = 0; i < m1.get_rows(); i++) {
                for (int j = 0; j < m1.get_columns(); j++) {
                    arr[i][j] = m1.get_element(i, j) - m2.get_element(i, j);
                }
            }
        } else {
            cout << "Matrices cannot be subtracted" << endl;
        }
    }

    void multiply(matrix &m1, matrix &m2) {
        if (m1.get_columns() == m2.get_rows()) {
            for (int i = 0; i < m1.get_rows(); i++) {
                for (int j = 0; j < m2.get_columns(); j++) {
                    arr[i][j] = 0;
                    for (int k = 0; k < m1.get_columns(); k++) {
                        arr[i][j] += m1.get_element(i, k) * m2.get_element(k, j);
                    }
                }
            }
        } else {
            cout << "Matrices cannot be multiplied" << endl;
        }
    }

    void display_result(const string &operation) {
        cout << "Resultant Matrix after " << operation << ":" << endl;
        display();
    }
};

int main() {
    matrix m1(3, 3);
    matrix m2(3, 3);
    add_matrix mn(3, 3);
    
    cout << "Input for first 3x3 matrix:" << endl;
    m1.get_input();
    cout << "Input for second 3x3 matrix:" << endl;
    m2.get_input();
    
    mn.add(m1, m2);
    mn.display_result("addition");
    
    mn.subtract(m1, m2);
    mn.display_result("subtraction");
    
    mn.multiply(m1, m2);
    mn.display_result("multiplication");
    
    return 0;
}
