// шашки.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

struct shashki{
    bool sost = true;
    int sh[8][8] = { {3,1,3,1,3,1,3,1},
                     {1,3,1,3,1,3,1,3},
                     {3,1,3,1,3,1,3,1},
                     {3,3,3,3,3,3,3,3},
                     {3,3,3,3,3,3,3,3},
                     {0,3,0,3,0,3,0,3},
                     {3,0,3,0,3,0,3,0},
                     {0,3,0,3,0,3,0,3} };
};

shashki pole;

shashki static is_move(shashki nm, int x, int y, int n, int napr) {
    cout << n << napr << " " << x << " " << y << endl;
    
    switch (napr) {
    case 1:
        if ((nm.sh[y + 1][x + 1] == 3 && nm.sh[x][y] == n%2) && n%2==1) {
            nm.sh[y][x] = 3;
            nm.sh[y + 1][x + 1] = n % 2;    
        }
        else nm.sost = false; 

        break;
    case 2:
        if ((nm.sh[y - 1][x + 1] == 3 && nm.sh[x][y] == n % 2) && n%2 == 0) {
            nm.sh[y][x] = 3;
            nm.sh[y - 1][x + 1] = n % 2;
        }
        else nm.sost = false;
        break;
    case 3:
        if ((nm.sh[y - 1][x - 1] == 3 && nm.sh[x][y] == n % 2) && n%2 == 0) {
            nm.sh[y][x] = 3;
            nm.sh[y - 1][x - 1] = n % 2;
        }
        else nm.sost = false;

        break;
    case 4:
        if ((nm.sh[y + 1][x - 1] == 3 && nm.sh[x][y] == n % 2) && n%2 == 1) {
            nm.sh[y][x] = 3;
            nm.sh[y + 1][x - 1] = n % 2;
        }
        else nm.sost = false;
        
        break;
    }
    if (nm.sost) {
        cout << endl;
        for (int y = 0; y < 8; y++) {
            for (int x = 0; x < 8; x++) {
                cout << nm.sh[y][x] << " ";
            }
            cout << endl;
        }
    }
    return nm;
}
/*
shashki is_take(shashki m, int x, int y, int n, int napr1, int napr2) {
    m.sost = false;
    return m;
    switch (napr1) {
    case 1:
        switch (napr2) {
        case 1:
            if (y == 6) {
                m.sost = false;
                break;
            }
            if (m.sh[x + 1][y + 1] != n % 2 && m.sh[x + 1][y + 1] != 3 && m.sh[x][y] == n % 2 && m.sh[x][y+2] == 3) {
                m.sh[x][y] = 3;
                m.sh[x + 1][y + 1] = 3;
                m.sh[x][y + 2] = n % 2;
                
            }
            else m.sost = false;
            break;
        case 2:
            if (y == 6 && x == 6) {
                m.sost = false;
                break;
            }
            if (m.sh[x + 1][y + 1] != n % 2 && m.sh[x + 1][y + 1] != 3 && m.sh[x][y] == n % 2 && m.sh[x+2][y + 2] == 3) {
                m.sh[x][y] = 3;
                m.sh[x + 1][y + 1] = 3;
                m.sh[x+2][y + 2] = n % 2;
                
            }
            else m.sost = false;
            break;
        case 3:
            if (x == 6) {
                m.sost = false;
                break;
            }
            if (m.sh[x + 1][y + 1] != n % 2 && m.sh[x + 1][y + 1] != 3 && m.sh[x][y] == n % 2 && m.sh[x + 2][y] == 3) {
                m.sh[x][y] = 3;
                m.sh[x + 1][y + 1] = 3;
                m.sh[x + 2][y] = n % 2;
                
            }
            else m.sost = false;
            break;
        }
        break;
    case 2:
        switch (napr2) {
        case 1:
            if (x == 6) {
                m.sost = false;
                break;
            }
            if (m.sh[x + 1][y - 1] != n % 2 && m.sh[x + 1][y - 1] != 3 && m.sh[x][y] == n % 2 && m.sh[x+2][y] == 3) {
                m.sh[x][y] = 3;
                m.sh[x + 1][y - 1] = 3;
                m.sh[x+2][y] = n % 2;
            }
            else m.sost = false;
            break;
        case 2:
            if (y == 1 && x == 6) {
                m.sost = false;
                break;
            }
            if (m.sh[x + 1][y - 1] != n % 2 && m.sh[x + 1][y - 1] != 3 && m.sh[x][y] == n % 2 && m.sh[x + 2][y - 2] == 3) {
                m.sh[x][y] = 3;
                m.sh[x + 1][y - 1] = 3;
                m.sh[x + 2][y - 2] = n % 2;
            }
            else m.sost = false;
            break;
        case 3:
            if (y == 1) {
                m.sost = false;
                break;
            }
            if (m.sh[x + 1][y - 1] != n % 2 && m.sh[x + 1][y - 1] != 3 && m.sh[x][y] == n % 2 && m.sh[x][y-2] == 3) {
                m.sh[x][y] = 3;
                m.sh[x + 1][y - 1] = 3;
                m.sh[x][y-2] = n % 2;
            }
            else m.sost = false;
            break;
        }
    case 3:
        switch (napr2) {
        case 1:
            if (y == 1) {
                m.sost = false;
                break;
            }
            if (m.sh[x - 1][y - 1] != n % 2 && m.sh[x - 1][y - 1] != 3 && m.sh[x][y] == n % 2 && m.sh[x][y-2] == 3) {
                m.sh[x][y] = 3;
                m.sh[x - 1][y - 1] = 3;
                m.sh[x][y-2] = n % 2;
                
            }
            else m.sost = false;
            break;
        case 2:
            if (y == 1 && x == 1) {
                m.sost = false;
                break;
            }
            if (m.sh[x - 1][y - 1] != n % 2 && m.sh[x - 1][y - 1] != 3 && m.sh[x][y] == n % 2 && m.sh[x - 2][y - 2] == 3) {
                m.sh[x][y] = 3;
                m.sh[x - 1][y - 1] = 3;
                m.sh[x - 2][y - 2] = n % 2;

            }
            else m.sost = false;
            break;
        case 3:
            if (x == 1) {
                m.sost = false;
                break;
            }
            if (m.sh[x - 1][y - 1] != n % 2 && m.sh[x - 1][y - 1] != 3 && m.sh[x][y] == n % 2 && m.sh[x - 2][y] == 3) {
                m.sh[x][y] = 3;
                m.sh[x - 1][y - 1] = 3;
                m.sh[x - 2][y] = n % 2;
                
            }
            else m.sost = false;
            break;
        }
        break;
    case 4:
        switch (napr2) {
        case 1:
            if (x == 1) {
                m.sost = false;
                break;
            }
            if (m.sh[x - 1][y + 1] != n % 2 && m.sh[x - 1][y + 1] != 3 && m.sh[x][y] == n % 2 && m.sh[x - 2][y] == 3) {
                m.sh[x][y] = 3;
                m.sh[x + 1][y + 1] = 3;
                m.sh[x - 2][y] = n % 2;
                
            }
            else m.sost = false;
            break;
        case 2:
            if (y == 6 && x == 1) {
                m.sost = false;
                break;
            }
            if (m.sh[x - 1][y + 1] != n % 2 && m.sh[x - 1][y + 1] != 3 && m.sh[x][y] == n % 2 && m.sh[x - 2][y + 2] == 3) {
                m.sh[x][y] = 3;
                m.sh[x - 1][y + 1] = 3;
                m.sh[x - 2][y + 2] = n % 2;
                
            }
            else m.sost = false;
            break;
        case 3:
            if (y == 6) {
                m.sost = false;
                break;
            }
            if (m.sh[x - 1][y + 1] != n % 2 && m.sh[x - 1][y + 1] != 3 && m.sh[x][y] == n % 2 && m.sh[x][y + 2] == 3) {
                m.sh[x][y] = 3;
                m.sh[x - 1][y + 1] = 3;
                m.sh[x][y + 2] = n % 2;
                
            }
            else m.sost = false;
            break;
        }
        break;
    }
    return m;
}
*/
int f(int move, int m_move, shashki fm) {
    if (!fm.sost) return 0;
    if (move > m_move ) return 1;
    int s = 0;
    int st = 0;
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if (x == 0 && y == 0) {
                s += f(move + 1, m_move, is_move(fm, x, y, move, 1));
            }
            else if (x == 7 && y == 0) {
                s += f(move + 1, m_move, is_move(fm, x, y, move, 4));
                
            }
            else if (x == 7 && y == 7) {
                s += f(move + 1, m_move, is_move(fm, x, y, move, 3));
                
            }
            else if (x == 0 && y == 7) {
                s += f(move + 1, m_move, is_move(fm, x, y, move, 2));
                
            }
            else if (y == 0) {
                s += f(move + 1, m_move, is_move(fm, x, y, move, 1));
                s += f(move + 1, m_move, is_move(fm, x, y, move, 4));
                
            }
            else if (x == 7) {
                s += f(move + 1, m_move, is_move(fm, x, y, move, 3));
                s += f(move + 1, m_move, is_move(fm, x, y, move, 4));
                
            }
            else if (y == 7) {
                s += f(move + 1, m_move, is_move(fm, x, y, move, 3));
                s += f(move + 1, m_move, is_move(fm, x, y, move, 2));
                
            }
            else if (x == 0) {
                s += f(move + 1, m_move, is_move(fm, x, y, move, 1));
                s += f(move + 1, m_move, is_move(fm, x, y, move, 2));
                
            }
            else {
                s += f(move + 1, m_move, is_move(fm, x, y, move, 1));
                s += f(move + 1, m_move, is_move(fm, x, y, move, 2));
                s += f(move + 1, m_move, is_move(fm, x, y, move, 3));
                s += f(move + 1, m_move, is_move(fm, x, y, move, 4));
                
            }
        }
        
    }
    
    return s;
}

int main()
{
    cout << "1. " << f(1, 1, pole) << endl;
    //cout << "2. " << f(1, 2, pole) << endl;
    //cout << "3. " << f(1, 3, pole) << endl;
    
    cout << "Hello World!\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
