#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>


int main() {
    setlocale(LC_CTYPE, "Russian");
    using namespace std;
    ifstream in;
    ifstream vesa;
    ifstream target;
    ofstream vesaof;
    const int N = 3;
    const int k = 3;
    const int m = 3;

    long double Input[N];
    in.open("C:\\Users\\serge\\CLionProjects\\neural\\Input.txt");///Считываем входные значения
    for (int i = 0; i < N; ++i)
    {
        in >> (Input[i]);
    }
    in.close();

    long double Target[N];
    target.open("C:\\Users\\serge\\CLionProjects\\neural\\target.txt");///Считываем желаемые значения
    for (int i = 0; i < N; ++i)
    {
        target >> (Target[i]);
    }
    target.close();


    for (int i = 0; i < N; ++i) ///Выводим входные значения
    {
        cout << Input[i] << endl;
    }
    cout << endl;

    for (int i = 0; i < N; ++i) ///Выводим желаемые значения
    {
        cout << Target[i] << endl;
    }
    cout << endl;

    long double Wesa[k][m];///Считываем веса нейронов
    vesa.open("C:\\Users\\serge\\CLionProjects\\neural\\vesa.txt");
    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            vesa >> Wesa[i][j];
        }
    }
    vesa.close();

    long double Otvet1 = 0;
    long double Otvet2 = 0;
    long double Otvet3 = 0;

    bool status = true;
    int i = 0;
    int epochs = 0;
    while (status) {

        long double S0 = Input[0] * Wesa[0][0] + Input[1] * Wesa[0][1] + Input[2] * Wesa[0][2];
        long double S1 = Input[0] * Wesa[1][0] + Input[1] * Wesa[1][1] + Input[2] * Wesa[1][2];
        long double S2 = Input[0] * Wesa[2][0] + Input[1] * Wesa[2][1] + Input[2] * Wesa[2][2];


        Otvet1 = S0 * 0.9;
        Otvet2 = S1 * 0.9;
        Otvet3 = S2 * 0.9;



        long double E0 = Target[0] - Otvet1;
        long double E1 = Target[1] - Otvet2;
        long double E2 = Target[2] - Otvet3;



        Wesa[0][0] = Wesa[0][0] + 0.8 * E0 * Input[0];
        Wesa[0][1] = Wesa[0][1] + 0.8 * E0 * Input[1];
        Wesa[0][2] = Wesa[0][2] + 0.8 * E0 * Input[2];

        Wesa[1][0] = Wesa[1][0] + 0.8 * E1 * Input[0];
        Wesa[1][1] = Wesa[1][1]  + 0.8 * E1 * Input[1];
        Wesa[1][2] = Wesa[1][2]  + 0.8 * E1 * Input[2];

        Wesa[2][0] = Wesa[2][0]  + 0.8 * E2 * Input[0];
        Wesa[2][1] = Wesa[2][1]  + 0.8 * E2 * Input[1];
        Wesa[2][2] = Wesa[2][2]  + 0.8 * E2 * Input[2];

        double eror = pow(E0, 2.0) + pow(E1, 2.0) + pow(E2, 2.0);
        ++i;
        srand(time(NULL));
        if ((eror <= 0.01) || (i == 100000)){
            status = false;
        }
    epochs++;
    }

    vesaof.open("C:\\Users\\serge\\CLionProjects\\neural\\vesa.txt");
    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            vesaof << Wesa[i][j] << endl;
        }
    }
    vesaof.close();
    cout << "Neural learned for " << epochs << " epoch" << endl;
    cout << "X3->X1&X2   " << Otvet1 << endl;
    cout << "X2&X3     " << Otvet2 << endl;
    cout << "X2->X3      " << Otvet3 << endl;
}
