#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
double const TWOPI = 6.2831853071795864;

int main()
{

    double GRE2JULE(int date_YY, int date_MM, int date_DD);
    void JULE2GRE(int input, int num);

    int date_YY, date_MM, date_DD, birth_YY, birth_MM, birth_DD, SPAN_1;
    double SPAN;

    cout << "Please input today's date in the format of YY MM DD" << endl;
    cin >> date_YY >> date_MM >> date_DD;

 //   cout << "Please input your BIRTHDAY in the format of YY MM DD" << endl;
 //   cin >> birth_YY >> birth_MM >> birth_DD;
    birth_YY = 1988; birth_MM = 5; birth_DD = 23;

    double JD_NOW, JD_BIRTH;
    JD_NOW = GRE2JULE(date_YY, date_MM, date_DD);
    JD_BIRTH = GRE2JULE(birth_YY, birth_MM, birth_DD);
    SPAN = JD_NOW - JD_BIRTH;

    vector<double> star_index(3), next_climax(3);

    star_index[1] = 5.00 * sin(TWOPI * SPAN / 23.00) + 5.00;
    star_index[2] = 5.00 * sin(TWOPI * SPAN / 28.00) + 5.00;
    star_index[3] = 5.00 * sin(TWOPI * SPAN / 33.00) + 5.00;

    SPAN_1 = int(SPAN);

    next_climax[1] = 23 - (SPAN_1 + 23 * 3 / 4) % 23 + int(JD_NOW) + 1;
    next_climax[2] = 28 - (SPAN_1 + 28 * 3 / 4) % 28 + int(JD_NOW) + 1;
    next_climax[3] = 33 - (SPAN_1 + 33 * 3 / 4) % 33 + int(JD_NOW) + 1;

    cout << "****************************************************************************" << endl;
    cout << "Have fun! Thanks for your test" << endl;
    cout << "Your Psycological Index:" << endl;
    cout << star_index[1] << endl;
    cout << "Your Emotional Index:" << endl;
    cout << star_index[2] << endl;
    cout << "Your Intellectual Index" << endl;
    cout << star_index[3] << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    JULE2GRE(next_climax[1], 1);
    JULE2GRE(next_climax[2], 2);
    JULE2GRE(next_climax[3], 3);
    cout << "----------------------------------------------------------------------------" << endl;
    cout << "****************************************************************************" << endl;
}

double GRE2JULE(int date_YY, int date_MM, int date_DD)
{
    double JD, temp_value_1, temp_value_2, temp_value_3;
    int Y, M, D;
    Y = date_YY;
    M = date_MM;
    D = date_DD;
    temp_value_1 = 1461 * (Y + 4800 + (M - 14) / 12) /4;
    temp_value_2 = 367 * (M - 2 - ((M - 14) / 12) * 12) / 12;
    temp_value_3 = 3 * (Y + 4900 + (M - 14) / 12) / 100 / 4;
    JD = D - 32075 + temp_value_1 + temp_value_2 - temp_value_3 - 0.500;
    return JD;
}

void JULE2GRE(int input, int num)
{
    int J, N, L1, Y1, L2, M1, D, L3, M, Y;
    J = int(input + 0.500);
    N = 4 * (J + 68569) / 146097;
    L1 = J + 68569 - (N * 146097 + 3) / 4;
    Y1 = 4000 * (L1 + 1) / 1461001;
    L2 = L1 - 1461 * Y1 / 4 + 31;
    M1 = 80 * L2 / 2447;
    D = L2 - 2447 * M1 / 80;
    L3 = M1 / 11;
    M = M1 + 2 - 12 * L3;
    Y = 100 * (N - 49) + Y1 + L3;

    if (num == 1){
            cout << "Your next Psycological Climax in prediction" << endl;
            cout << Y; cout << "."; cout << M; cout << "."; cout << D << endl;}
        else
            if (num == 2){
                cout << "Your next Emotional Climax" << endl;
                cout << Y; cout << "."; cout << M; cout << "."; cout << D << endl;}
            else
                if(num == 3){
                    cout << "Your next Intellectual Climax" << endl;
                    cout << Y; cout << "."; cout << M; cout << "."; cout << D << endl;}
}
