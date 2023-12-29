#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct DateOfBirth{
    unsigned int day;
    unsigned int month;
    unsigned int year;
};

struct SinhVien {
    string hoten;
    string mssv;
    DateOfBirth DoB;
    float cpa;
    void print_sv(){
        cout <<"Ma so sinh vien: "<<this->mssv<<endl;
        cout <<"Ho va ten: "<<this->hoten<<endl;
        cout <<"Ngay thang nam sinh: "<<this->DoB.day<<"/"<<this->DoB.month<<"/"<<this->DoB.year<<endl;
        cout <<"Diem CPA: "<<this->cpa<<endl;
	}
};

void input_sv(SinhVien *sv, unsigned int n){
    for (int i=0; i<n; i++){
        cout <<"Sinh vien "<<i+1<<":" <<endl;
        cout <<"Ma so sinh vien: "; cin >> sv[i].mssv;
        cout <<"Ho va ten: ";
        cin.ignore(); // Ignore the newline character left in the buffer
        getline(cin, sv[i].hoten);
        cout <<"Ngay thang nam sinh: ";
        cin >> sv[i].DoB.day >> sv[i].DoB.month >> sv[i].DoB.year;
        cout <<"Diem CPA: "; cin >> sv[i].cpa;
    }
}
void sort_cpa(SinhVien *sv, unsigned int n){
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            if (sv[i].cpa < sv[j].cpa){
                SinhVien temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }
}
void print_all(SinhVien *sv, unsigned int n){
    sort_cpa(sv,n);
    for (int i=0; i<n; i++){
    	cout <<"================================="<<endl;
        cout <<"Sinh vien "<<i+1<<":"<<endl;
		sv[i].print_sv();
    }
}
SinhVien find_mssv(SinhVien *sv, unsigned int n){
    string find;
    cout << "Nhap MSSV cua sinh vien can tim: "; cin>>find;
    for (int i=0;i<n;i++){
        if (find == sv[i].mssv){
            return sv[i];
        }
    }
}
SinhVien search(SinhVien *sv, unsigned int n, const string &searchTerm) {
    for (int i = 0; i<n; ++i) {
        if (sv[i].hoten.find(searchTerm) != string::npos) {
            return sv[i];
        }
    }
    cout << "Not found." << endl;
    return SinhVien{};
}

int main (){
    unsigned int n;
    cout << "Nhap so sinh vien: ";
    cin >> n;
    SinhVien *sv = new SinhVien[n];
    input_sv(sv,n);
    print_all(sv,n);
    
    string searchTerm;
    cout << "Enter search keyword: ";
    cin >> searchTerm;
    search(sv,n,searchTerm).print_sv();
    
	delete[] sv;
    return 0;
}
