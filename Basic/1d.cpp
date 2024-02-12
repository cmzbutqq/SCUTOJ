#include <iostream>
#include <cmath>
using namespace std;
const float eps = 10e-3;

int input[4] = {0, 0, 0, 0};

char showMethod[4] = {'+', '-', '*', '/'};

struct choice
{
    int lc; // left choice index
    int rc; // right choice index
};
choice A_4_2[12] =
    {
        {0, 1}, {1, 0}, // A22:index0-1
        {0, 2},
        {2, 0},
        {1, 2},
        {2, 1}, // A32:index0-5
        {0, 3},
        {3, 0},
        {1, 3},
        {3, 1},
        {2, 3},
        {3, 0} // A42:index0-11
};

struct processCode
{
    int c1code; // index of A_4_2
    int c2code;
    int c3code;
    int m1code; // methodCode:0+ 1- 2* 3/
    int m2code;
    int m3code;
} processCodes[9216];

void initProcessCode()
{
    //
    // int ct=0;
    //
    int indexProcessCodes = 0;
    for (int c1c = 0; c1c < 12; c1c++)
    {
        for (int c2c = 0; c2c < 6; c2c++)
        {
            for (int c3c = 0; c3c < 2; c3c++)
            {
                for (int m1c = 0; m1c < 4; m1c++)
                {
                    for (int m2c = 0; m2c < 4; m2c++)
                    {
                        for (int m3c = 0; m3c < 4; m3c++)
                        {
                            processCodes[indexProcessCodes].c1code = c1c;
                            processCodes[indexProcessCodes].c2code = c2c;
                            processCodes[indexProcessCodes].c3code = c3c;
                            processCodes[indexProcessCodes].m1code = m1c;
                            processCodes[indexProcessCodes].m2code = m2c;
                            processCodes[indexProcessCodes].m3code = m3c;
                            ++indexProcessCodes;
                            //
                            // out<<c1c<<' '<<c2c<<' '<<c3c<<' '<<m1c<<' '<<m2c<<' '<<m3c<<endl;
                            // ct++;
                            //
                        }
                    }
                }
            }
        }
    }
    //
    // cout<<ct<<endl;
    //
    return;
}

float calc1(float lNum, float rNum, int methodCode)
{
    switch (methodCode)
    {
    case 0:
        return lNum + rNum;
    case 1:
        return lNum - rNum;
    case 2:
        return lNum * rNum;
    case 3:
        return lNum / rNum;
    default:
        return 0;
    }
}

float calc4(int PCs_index, bool onPrint = false)
{
    processCode PC = processCodes[PCs_index];
    choice c1 = A_4_2[PC.c1code], c2 = A_4_2[PC.c2code], c3 = A_4_2[PC.c3code];
    int c1l = c1.lc, c1r = c1.rc, c2l = c2.lc, c2r = c2.rc, c3l = c3.lc, c3r = c3.rc;
    int m1c = PC.m1code, m2c = PC.m2code, m3c = PC.m3code;

    float temp_3[3], temp_2[2], temp_1;

    //
    // onPrint=true;
    //

    temp_3[0] = calc1(*(input + c1l), *(input + c1r), m1c);
    for (int i = 0, j = 1; i < 4 && j < 3; i++) // input[i]->temp3[j]
    {
        if (i != c1l && i != c1r)
        {
            temp_3[j] = input[i];
            j++;
        }
    }

    if (onPrint)
    {
        cout << *(input + c1l) << ' ' << showMethod[m1c] << ' ' << *(input + c1r) << "= " << temp_3[0] << endl;
        cout << temp_3[0] << ' ' << temp_3[1] << ' ' << temp_3[2] << endl;
    }

    temp_2[0] = calc1(*(temp_3 + c2l), *(temp_3 + c2r), m2c);
    for (int i = 0, j = 1; i < 3 && j < 2; i++) // temp3->temp2
    {
        if (i != c2l && i != c2r)
        {
            temp_2[j] = temp_3[i];
            j++;
        }
    }

    if (onPrint)
    {
        cout << *(temp_3 + c2l) << ' ' << showMethod[m2c] << ' ' << *(temp_3 + c2r) << "= " << temp_2[0] << endl;
        cout << temp_2[0] << ' ' << temp_2[1] << endl;
    }

    temp_1 = calc1(*(temp_2 + c3l), *(temp_2 + c3r), m3c);

    if (onPrint)
    {
        cout << *(temp_2 + c3l) << ' ' << showMethod[m3c] << ' ' << *(temp_2 + c3r) << "= " << temp_1 << endl;
        cout << temp_1 << endl
             << endl;
    }

    return temp_1;
}

bool if24(int PCs_index)
{
    float result = calc4(PCs_index);
    float offset = abs(result - 24);
    if (offset <= eps)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void runResult()
{
    for (int PCs_index = 0; PCs_index < 9216; PCs_index++)
    {
        if (if24(PCs_index))
        {
            cout << "YES" << endl;
            // 显示计算出24的过程
            // calc4(PCs_index,true);
            //
            return;
        }
    }
    cout << "NOT" << endl;
    return;
}

int main()
{
    initProcessCode();
    while (cin >> input[0])
    {
        for (int i = 1; i < 4; i++)
        {
            cin >> input[i];
        }
        runResult();
    }
    return 0;
}