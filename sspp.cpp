#include <iostream>
#include <cstring>
#include <cstdio>
#include <fstream>
#include <ctime>

using namespace std;

template<typename T>
class matrix {
        int n, m;  
        T *elements;

    public:
        matrix(int h = 1, int w = 1);
        matrix (const matrix & source);
        ~matrix(){ delete [] elements; }
        void operator = (const matrix & source);
        matrix operator + (matrix & b);
        void set_element(int str, int col, T &elem);
        T get_element(int str, int col);
        void read_matrix(ifstream &in);         
        void print();
        void fprint(ofstream &out);
        
        template<typename Tip>
        friend void ijk(const matrix<Tip> &a, const matrix<Tip> &b, matrix<Tip> &c);
        template<typename Tip>      
        friend void ikj(const matrix<Tip> &a, const matrix<Tip> &b, matrix<Tip> &c);
        template<typename Tip>
        friend void kij(const matrix<Tip> &a, const matrix<Tip> &b, matrix<Tip> &c);
        template<typename Tip>
        friend void jik(const matrix<Tip> &a, const matrix<Tip> &b, matrix<Tip> &c);
        template<typename Tip>
        friend void jki(const matrix<Tip> &a, const matrix<Tip> &b, matrix<Tip> &c);
        template<typename Tip>
        friend void kji(const matrix<Tip> &a, const matrix<Tip> &b, matrix<Tip> &c);

};

template<typename T>
matrix<T>::matrix(int h , int w ) {
    m = h; n = w;
    int size_of_matrix = m * n;
    elements = new T[size_of_matrix];
    memset(elements, 0, size_of_matrix * sizeof(T));
}

template<typename T>
matrix<T>::matrix (const matrix & source){
    m = source.m; n = source.n;
    int size_of_matrix = m * n;
    elements = new T[size_of_matrix];
    for(int i = 0; i < size_of_matrix; ++i){
        elements[i] = source.elements[i];
    }
}

template<typename T>
void matrix<T>::operator = (const matrix & source){
    delete [] elements;
    m = source.m; n = source.n;
    int size_of_matrix = m * n;
    elements = new T[size_of_matrix];
    for(int i = 0; i < size_of_matrix; ++i){
        elements[i] = source.elements[i];
    }
}
template<typename T>    
matrix<T> matrix<T>::operator + (matrix & b){
    try{ 
        if((n != b.n) | (m != b.m)){
            throw 100;
        }
    }
    catch(int i){
        
                cout << "+matrix!"<<endl;
        throw;
    }
    matrix ret(m, n);
    for(int i = 0; i < m * n; ++i){
        ret.elements[i] = elements[i] + b.elements[i];
    }
    return ret;
}
template<typename T>
void matrix<T>::set_element(int str, int col, T &elem){
    try{
        if((str > m) | (col > n)){
            throw 200;
        }
    }
    catch(int i){
                cout << "set!"<<endl;
        throw;
    }
    elements[ (str - 1) * n + col - 1 ] = elem;
}
template<typename T>
T matrix<T>::get_element(int str, int col){
    try{
        if((str > m) | (col > n)){
            throw 300;
        }
    }
    catch(int i){
                cout << "get!"<<endl;
        throw;
    }
    return elements[ (str - 1) * n + col - 1 ];
}
template<typename T>
void matrix<T>::print(){
    int i, k;
    for(i = 1; i <= m; ++i){
        for(k = 1; k <= n; k++){
            cout << get_element(i,k)<<' ';
        }
        cout << endl;
    }
}

template<typename T>
void matrix<T>::read_matrix(ifstream &in) {
    T tmp;
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            in.read((char*)&tmp, sizeof tmp);
            elements[i * n + j] = tmp;
        }
    }
}       
template<typename T>
void matrix<T>::fprint(ofstream &out){
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            out.write((char*)&elements[i * n + j], sizeof(T));
        }
    }
}

template<typename T>
void ijk(const matrix<T> &a, const matrix<T> &b, matrix<T> &c) {
    int i, j, k, m, n, h;
    m = a.m;
    h = a.n;
    n = b.n;
    for ( i = 0; i < m; ++i) {
        for ( j = 0; j < n; ++j) {
            for ( k = 0; k < h; ++k) {
                c.elements[i * n + j] += a.elements[i * h + k] * b.elements[k * n + j];
            }
        }
    }
}
template<typename T>
void ikj(const matrix<T> &a, const matrix<T> &b, matrix<T> &c) {
    int i, j, k, m, n, h;
    m = a.m;
    h = a.n;
    n = b.n;
    for ( i = 0; i < m; ++i) {
        for ( k = 0; k < h; ++k) {
            for ( j = 0; j < n; ++j) {
                c.elements[i * n + j] += a.elements[i * h + k] * b.elements[k * n + j];
            }
        }
    }
}
template<typename T>
void kij(const matrix<T> &a, const matrix<T> &b, matrix<T> &c) {
    int i, j, k, m, n, h;
    m = a.m;
    h = a.n;
    n = b.n;
    for ( k = 0; k < h; ++k) {
        for ( i = 0; i < m; ++i) {
            for ( j = 0; j < n; ++j) {
                c.elements[i * n + j] += a.elements[i * h + k] * b.elements[k * n + j];
            }
        }
    }
}
template<typename T>
void jik(const matrix<T> &a, const matrix<T> &b, matrix<T> &c) {
    int i, j, k, m, n, h;
    m = a.m;
    h = a.n;
    n = b.n;
    for ( j = 0; j < n; ++j) {
        for ( i = 0; i < m; ++i) {
            for ( k = 0; k < h; ++k) {
                c.elements[i * n + j] += a.elements[i * h + k] * b.elements[k * n + j];
            }
        }
    }
}
template<typename T>
void jki(const matrix<T> &a, const matrix<T> &b, matrix<T> &c) {
    int i, j, k, m, n, h;
    m = a.m;
    h = a.n;
    n = b.n;
    for ( j = 0; j < n; ++j) {
        for ( k = 0; k < h; ++k) {
            for ( i = 0; i < m; ++i) {
                c.elements[i * n + j] += a.elements[i * h + k] * b.elements[k * n + j];
            }
        }
    }
}
template<typename T>
void kji(const matrix<T> &a, const matrix<T> &b, matrix<T> &c) {
    int i, j, k, m, n, h;
    m = a.m;
    h = a.n;
    n = b.n;
    for ( k = 0; k < h; ++k) {
        for ( j = 0; j < n; ++j) {
            for ( i = 0; i < m; ++i) {
                c.elements[i * n + j] += a.elements[i * h + k] * b.elements[k * n + j];
            }
        }
    }
}

template<typename T>
void comp_and_print(const matrix<T> &A, const matrix<T> &B, matrix<T> &C, ofstream &out, char mode) {
    clock_t start, stop;
    start = clock ();
    switch (mode) {
        case '0': ijk(A, B, C); break;
        case '1': ikj(A, B, C); break;
        case '2': kij(A, B, C); break;
        case '3': jik(A, B, C); break;
        case '4': jki(A, B, C); break;
        case '5': kji(A, B, C); break;
    }
    stop = clock();
    C.fprint(out);
    double seconds = (double)(stop - start) / CLOCKS_PER_SEC;
    out.write((char*)&seconds, sizeof(double));
    cout <<seconds <<' ';
}

int main(int argc, char *argv[])
{
    try {
        if (argc < 5) {
            throw "Недостаточно аргументов";
        }
        ifstream ain, bin;
        ofstream out;
        ain.open(argv[1], ios::binary | ios::in);
        bin.open(argv[2], ios::binary | ios::in);
        out.open(argv[3], ios::binary | ios::trunc | ios::out);
        
        if( !ain.is_open() || !bin.is_open() || !out.is_open() ) {
            throw "Не удалось открыть один из файлов";
        }
        char mode = *argv[4];
        if( mode < '0' || mode > '5' ) {
            throw "Ошибка при вводе параметров(число от 0 до 5)";
        }

        char c, d;      
        bin.read(&c, sizeof c);
        ain.read(&d, sizeof d);

        if(c != d) {
            throw "Матрицы разных типов данных!";
        }
        
        int m, k;
        ain.read((char*)&m, sizeof m);
        //ain.read((char*)&n, sizeof n);
        bin.read((char*)&k, sizeof k);
        //bin.read((char*)&l, sizeof l);
        
        if(k != m) {
            throw "Матрицы разного размера";
        }
        out.write(&c, sizeof c);
        out.write((char*)&m, sizeof m);
        //out.write((char*)&l, sizeof l);
        if( c == 'T' ) {
            matrix<int> A(m, m), B(k, k), C(m, k);
            A.read_matrix(ain); B.read_matrix(bin);
            comp_and_print(A, B, C, out, mode);
        }
        else{
            matrix<long> A(m, m), B(k, k), C(m, k);
            A.read_matrix(ain); B.read_matrix(bin);
            comp_and_print(A, B, C, out, mode);
        }        
        ain.close();
        bin.close();
        out.close();
    }
    catch (const char *error)
    {
        cout << error << endl;
        return 1;
    }
    catch (...)
    {
        cout << "unknown error" << endl;
        return 1;
    }

    return 0;
}
