#include <iostream>
using namespace std;

struct DaThuc {
    unsigned int bac;
    double *he_so;

    // Default constructor
    DaThuc() : bac(0), he_so(nullptr) {}

    // Constructor with parameters
    DaThuc(unsigned int b) : bac(b) {
        he_so = new double[bac + 1];
    }

    void input() {
        cout << "Nhap bac da thuc: ";
        cin >> this->bac;

        he_so = new double[bac + 1]; // Allocate memory based on user input

        cout << "Nhap he so cua da thuc: " << endl;
        for (int i = this->bac; i >= 0; i--) {
            cin >> he_so[i];
        }
    }

    void print() {
        for (int i = this->bac; i >= 0; i--) {
            if (this->he_so[i] != 0) {
                cout << this->he_so[i] << "x^" << i;
                if (i != 0) {
                    cout << " + ";
                }
            }
        }
        cout << endl;
    }

    ~DaThuc() {
        delete[] he_so;
    }
};

DaThuc cong(DaThuc dathuc1, DaThuc dathuc2){
    DaThuc ketqua;

    if (dathuc1.bac > dathuc2.bac){
        ketqua.bac = dathuc1.bac;
    }else ketqua.bac = dathuc2.bac;

    for (int i=ketqua.bac; i>=0; i--){
        ketqua.he_so[i] = dathuc1.he_so[i] + dathuc2.he_so[i];
    }

    return ketqua;
}

DaThuc nhan(DaThuc dathuc1, DaThuc dathuc2){
    DaThuc ketqua;
    ketqua.bac = dathuc1.bac + dathuc2.bac;
    
    for (int i = 0; i <= dathuc1.bac; ++i) {
        for (int j = 0; j <= dathuc2.bac; ++j) {
            ketqua.he_so[i + j] += dathuc1.he_so[i] * dathuc2.he_so[j];
        }
    }

    return ketqua;
}

int main() {
    DaThuc *dathuc = new DaThuc[3];
    for (int i = 0; i < 3; i++) {
        dathuc[i].input();
    }
    for (int i = 0; i < 3; i++) {
        cout << "P" << i+1 << ": ";
        dathuc[i].print();
    }

    DaThuc so2(0);
    so2.he_so[0] = 2;
    so2.print();

    DaThuc p;
    p = cong(dathuc[0],dathuc[1]);
    cout << "P = 2(P1+P2) + P3: ";
    p.print();

    delete[] dathuc; 
    return 0;
}