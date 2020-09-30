#include <iostream>
#include <stdio.h>10

using namespace std;

template <typename TYPE>
class CVector {
    private:
    int size;

    protected:
    TYPE * v;

    public:
    CVector() {
        size = 100;
        this->v = new TYPE[size];
    }
    CVector(int len) {
        size = len;
        this->v = new TYPE[size];
    }
    ~CVector() {
        delete[] v;
    }
};

template <typename TYPE>
class BVector : public CVector<TYPE> {

    private:
    int l; int r;

    public:
    BVector(int left, int right) : CVector<TYPE>(right - left + 1) {
        l = left;
        r = right;
    }
    TYPE& operator[](int i) {
        return CVector<TYPE>::v[i - l];
    }
    friend ostream& operator<<(ostream& os, const BVector<TYPE>& other) {
        for (int i = 0; i < other.r - other.l; i++)
            os << other.v[i + 1] << ' ';
        return os;
    }
};

int main(int argc, char* argv[])
{
    BVector<int> aVector(-10, 10);
    for (int i = -10; i < 11; i++)
        aVector[i] = 0;
    aVector[-7] = 9;
    cout << aVector << endl;
    system("PAUSE");
    return 0;
}
