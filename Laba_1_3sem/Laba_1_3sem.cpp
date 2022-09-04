#include <iostream>

using namespace std;


int ost(int a, int x, int m) {
    int res = 1;
    for (int i = 0; i < x; i++) {
        res *= a;
        res %= m;
    }
    return res;
}


class DH {
public:
    int p, g, Ya, Yb;

    DH(int a, int b) {
        p = a; g = b; Xa = 0; Xb = 0; Ya = 0; Yb = 0;
    }

    const int GetXa() {
        return Xa;
    }

    const int GetXb() {
        return Xb;
    }

    void SetXa(const int& a) {
        Xa = a;
    }

    void SetXb(const int& b) {
        Xb = b;
    }

private:
    int Xa, Xb;
};

void cryptoDH() {
    DH dh{ 23,5 };
    int a, b;

    cout << "Diffie-Hellman\n\n";
    cout << "Xa = " << dh.GetXa() << endl;
    cout << "Xb = " << dh.GetXb() << endl;

    cout << "Set Xa ";
    cin >> a;

    cout << "Set Xb ";
    cin >> b;

    dh.SetXa(a);
    dh.SetXb(b);

    cout << "Your data: p = " << dh.p << " g = " << dh.g << " Xa = " << dh.GetXa() << " Xb = " << dh.GetXb() << endl;

    dh.Ya = ost(dh.g, dh.GetXa(), dh.p);
    dh.Yb = ost(dh.g, dh.GetXb(), dh.p);

    cout << "Your key: Ya = " << dh.Ya << " Yb = " << dh.Yb << endl << endl;
}


class SR {
public:
    int p, x1;

    SR(int a) {
        p = a; Ca = 0; Cb = 0; da = 0; db = 0, x1 = 0;
    }

    const int GetCa() {
        return Ca;
    }

    const int GetCb() {
        return Cb;
    }

    void SetCa(const int& a) {
        Ca = a;
    }

    void SetCb(const int& b) {
        Cb = b;
    }

    const int Getda() {
        return da;
    }

    const int Getdb() {
        return db;
    }

    void Setda(const int& a) {
        da = a;
    }

    void Setdb(const int& b) {
        db = b;
    }

private:
    int Ca, Cb, da, db;
};

void cryptoSR() {
    SR sr{ 23 };
    int x2, x3, x4, text = 10;

    sr.SetCa(7);
    sr.SetCb(5);
    sr.Setda(19);
    sr.Setdb(9);

    for (int i = 0; i < 15; i++) {
        cout << (char)176 << (char)176 << (char)176 << (char)176;
    }
    cout << "\nShamir\n\n";
    cout << "text = " << text << ", p = " << sr.p << ", Ca = " << sr.GetCa() << ", Cb = " << sr.GetCb() << ", da = " << sr.Getda() << ", db = " << sr.Getdb() << endl << endl;

    sr.x1 = ost(text, sr.GetCa(), sr.p);
    cout << "Encrypto Alice = " << sr.x1 << endl;

    sr.x1 = ost(sr.x1, sr.GetCb(), sr.p);
    cout << "Encrypto Bob = " << sr.x1 << endl;

    sr.x1 = ost(sr.x1, sr.Getda(), sr.p);
    cout << "Encrypto Alice = " << sr.x1 << endl;

    sr.x1 = ost(sr.x1, sr.Getdb(), sr.p);
    cout << "Decrypto BOB = " << sr.x1 << endl << endl;

}


class EG {
public:
    int p, g, k, Da, Db, e, r, m;

    EG(int a, int b, int c) {
        p = a; g = b; k = c, Ca = 0; Cb = 0; Da = 0; Db = 0; e = 0; r = 0; m = 0;
    }

    const int GetCa() {
        return Ca;
    }

    const int GetCb() {
        return Cb;
    }

    void SetCa(const int& a) {
        Ca = a;
    }

    void SetCb(const int& b) {
        Cb = b;
    }

private:
    int Ca, Cb;
};

void cryptoEG() {
    EG eg{ 23, 7, 10 };//p,g,k
    int text = 10;

    eg.SetCa(4);
    eg.SetCb(9);

    eg.Da = ost(eg.g, eg.GetCa(), eg.p);
    eg.Db = ost(eg.g, eg.GetCb(), eg.p);

    eg.r = ost(eg.g, eg.k, eg.p);
    eg.e = ost(eg.Db, eg.k, eg.p);
    eg.e = (text * eg.e) % eg.p;

    eg.m = ost(eg.r, eg.p - 1 - eg.GetCb(), eg.p);
    eg.m = eg.m * eg.e % eg.p;

    for (int i = 0; i < 15; i++) {
        cout << (char)176 << (char)176 << (char)176 << (char)176;
    }
    cout << "\nElGamal\n\n";
    cout << "text = " << text << ", p = " << eg.p << ", g = " << eg.g << ", k = " << eg.k << ", Ca = " << eg.GetCa() << ", Cb = " << eg.GetCb() << ", da = " << eg.Da << ", db = " << eg.Db << endl << endl;
    cout << "Encrypto " << eg.e << ", " << eg.r << endl;
    cout << "Decrypto " << eg.m << endl << endl;
}


class RSA {
public:
    int p, q, N, phi, d, m, e;

    RSA(int a, int b, int c) {
        p = a; q = b; N = p * q; phi = (p - 1) * (q - 1); d = c; c = 0; m = 0; e = 0;
    }

    const int GetC() {
        return c;
    }
    void SetC(int a) {
        c = a;
    }
private:
    int c;
};

void cryptoRSA() {
    RSA rsa(7, 17, 5);
    int text = 10;

    rsa.SetC(77);

    rsa.e = ost(text, rsa.d, rsa.N);
    rsa.m = ost(rsa.e, rsa.GetC(), rsa.N);

    for (int i = 0; i < 15; i++) {
        cout << (char)176 << (char)176 << (char)176 << (char)176;
    }

    cout << "\nRSA\n\n";
    cout << "text = " << text << ", p = " << rsa.p << ", q = " << rsa.q << ", N = " << rsa.N << ", phi = " << rsa.phi << ", d = " << rsa.d << ", c = " << rsa.GetC() << endl << endl;
    cout << "Encrypto " << rsa.e << endl;
    cout << "Decrypto " << rsa.m << endl;

}

int main()
{
    cryptoDH();
    cryptoSR();
    cryptoEG();
    cryptoRSA();
}