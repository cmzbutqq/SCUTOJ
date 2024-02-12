#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class T_Counter {
public:
    T_Counter(T initValue = 0) : value(initValue) {}

    T operator+(const T_Counter<T>& rhs) const {
        return value + rhs.getValue();
    }

    T operator-(const T_Counter<T>& rhs) const {
        return value - rhs.getValue();
    }

    T operator*(const T_Counter<T>& rhs) const {
        return value * rhs.getValue();
    }

    T operator/(const T_Counter<T>& rhs) const {
        if (rhs.getValue() == 0) {
            throw "Division by zero";
        }
        return value / rhs.getValue();
    }

    T getValue() const {
        return value;
    }

    void setValue(T newValue) {
        value = newValue;
    }

private:
    T value;
};

template<typename T>
class T_Vector {
public:
    T_Vector(const vector<T>& initVector) : values(initVector) {}

    T_Vector<T> operator+(const T_Vector<T>& rhs) const {
        if (size() != rhs.size()) {
            throw "Vector尺寸不匹配";
        }
        vector<T> result(size());
        for (int i = 0; i < size(); i++) {
            result[i] = values[i] + rhs.values[i];
        }
        return T_Vector(result);
    }

    T_Vector<T> operator-(const T_Vector<T>& rhs) const {
        if (size() != rhs.size()) {
            throw "Vector尺寸不匹配";
        }
        vector<T> result(size());
        for (int i = 0; i < size(); i++) {
            result[i] = values[i] - rhs.values[i];
        }
        return T_Vector(result);
    }

    T operator*(const T_Vector<T>& rhs) const {
        if (size() != rhs.size()) {
            throw "Vector尺寸不匹配";
        }
        T result = 0;
        for (int i = 0; i < size(); i++) {
            result += values[i] * rhs.values[i];
        }
        return result;
    }

    T_Vector<T> operator*(const T& rhs) const {
        vector<T> result(size());
        for (int i = 0; i < size(); i++) {
            result[i] = values[i] * rhs;
        }
        return T_Vector(result);
    }

    int size() const {
        return values.size();
    }

    vector<T> getValues() const {
        return values;
    }

private:
    vector<T> values;
};

template<typename T>
class T_Matrix {
public:
    T_Matrix(const vector<vector<T>>& initMatrix) : matrix(initMatrix) {}

    T_Matrix<T> operator+(const T_Matrix<T>& rhs) const {
        if (rows() != rhs.rows() || cols() != rhs.cols()) {
            throw "Matrix尺寸不匹配";
        }

        vector<vector<T>> result(rows(), vector<T>(cols()));
        for (int i = 0; i < rows(); i++) {
            for (int j = 0; j < cols(); j++) {
                result[i][j] = matrix[i][j] + rhs.matrix[i][j];
            }
        }

        return T_Matrix<T>(result);
    }

    T_Matrix<T> operator-(const T_Matrix<T>& rhs) const {
        if (rows() != rhs.rows() || cols() != rhs.cols()) {
            throw "Matrix尺寸不匹配";
        }

        vector<vector<T>> result(rows(), vector<T>(cols()));
        for (int i = 0; i < rows(); i++) {
            for (int j = 0; j < cols(); j++) {
                result[i][j] = matrix[i][j] - rhs.matrix[i][j];
            }
        }

        return T_Matrix<T>(result);
    }

    T_Matrix<T> operator*(const T_Matrix<T>& rhs) const {
        if (rows() != rhs.rows() || cols() != rhs.cols()) {
            throw "Matrix尺寸不匹配";
        }

        vector<vector<T>> result(rows(), vector<T>(cols()));
        for (int i = 0; i < rows(); i++) {
            for (int j = 0; j < cols(); j++) {
                result[i][j] = 0;
                for (int k = 0; k < cols(); k++){
                    result[i][j] += matrix[i][k] * rhs.matrix[k][j];
                }
            }
        }

        return T_Matrix<T>(result);
    }

    int rows() const {
        return matrix.size();
    }

    int cols() const {
        return matrix[0].size();
    }

    vector<vector<T>> getMatrix() const {
        return matrix;
    }

private:
    vector<vector<T>> matrix;
};

int main() {
    
    T_Counter<int> i1(3);
    T_Counter<int> i2(5);
    cout << "i1 + i2 = " << i1 + i2 << endl;
    cout << "i1 - i2 = " << i1 - i2 << endl;
    cout << "i1 * i2 = " << i1 * i2 << endl;
    cout << "i1 / i2 = " << i1 / i2 << endl;

    
    T_Vector<float> vec1(vector<float> {1, 2});
    T_Vector<float> vec2(vector<float> {4, 5});
    cout << "vec1 + vec2 = ";
    for (auto f : (vec1 + vec2).getValues()) { cout << f << " "; }
    cout << endl;
    cout << "vec1 - vec2 = ";
    for (auto f : (vec1 - vec2).getValues()) {
        cout << f << " ";
    }
    cout << endl;
    cout << "vec1 * vec2 = " << (vec1 * vec2) << endl;

    
    vector<vector<float>> m1 = { {1, 2}, {3, 4} };
    vector<vector<float>> m2 = { {7, 8}, {9, 10} };
    T_Matrix<float> mat1(m1);
    T_Matrix<float> mat2(m2);
    cout << "mat1 + mat2 = ";
    for (auto row : (mat1 + mat2).getMatrix()) {
        for (auto d : row) {
            cout << d << " ";
        }
    }
    cout << endl;
    cout << "mat1 - mat2 = ";
    for (auto row : (mat1 - mat2).getMatrix()) {
        for (auto d : row) {
            cout << d << " ";
        }
    }
    cout << endl;
    cout << "mat1 * mat2 = ";
    for (auto row : (mat1* mat2).getMatrix()) {
        for (auto d : row) {
            cout << d << " ";
        }
    }
    cout << endl;
    return 0;
}
