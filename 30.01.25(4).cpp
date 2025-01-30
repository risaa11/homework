#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct figure {
    int id;
    char field[4][4];
};

void ran(figure I, figure L, figure Г, figure z, figure s, figure c, figure ш) {
    srand(time(nullptr));
    int a = rand() % 7 + 1;


    switch (a) {
    case 1:
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cout << I.field[i][j];
            }
            cout << endl;
        }
        break;
    case 2:
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cout << L.field[i][j];
            }
            cout << endl;
        }
        break;
    case 3:
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cout << Г.field[i][j];
            }
            cout << endl;
        }
        break;
    case 4:
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cout << z.field[i][j];
            }
            cout << endl;
        }
        break;
    case 5:
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cout << s.field[i][j];
            }
            cout << endl;
        }
        break;
    case 6:
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cout << c.field[i][j];
            }
            cout << endl;
        }
        break;
    case 7:
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cout << ш.field[i][j];
            }
            cout << endl;
        }
        break;
    }
    int per;
    cout << "1-переворот на 90\n2-переворот на 180\n3-переворот на 270\n";
    cin >> per;
    switch (a) {
    case 1:
        switch (per) {
        case 1:
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    cout << I.field[j][i];
                }
                cout << endl;
            }
            break;
        case 2:
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    cout << I.field[i][j];
                }
                cout << endl;
            }
            break;
        case 3:
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    cout << I.field[j][i];
                }
                cout << endl;
            }
            break;
        }
        break;
    case 2:
        switch (per) {
        case 1:
            cout << "  *\n***\n";
            break;
        case 2:
            cout << "**\n *\n *";
            break;
        case 3:
            cout << "***\n*";
            break;
        }
        break;
    case 3:
        switch (per) {
        case 1:
            cout << "*\n***";
            break;
        case 2:
            cout << " *\n *\n**";
            break;
        case 3:
            cout << "***\n  *";
            break;
        }
        break;
    case 4:
        switch (per) {
        case 1:
            cout << " *\n**\n*";
            break;
        case 2:
            cout << "**\n **";
            break;
        case 3:
            cout << " *\n**\n*";
            break;
        }
        break;
    case 5:
        switch (per) {
        case 1:
            cout << "*\n**\n *";
            break;
        case 2:
            cout << " **\n**";
            break;
        case 3:
            cout << "*\n**\n *";
            break;
        }
        break;
    case 6:
        switch (per) {
        case 1:
            cout << "**\n**";
            break;
        case 2:
            cout << "**\n**";
            break;
        case 3:
            cout << "**\n**";
            break;
        }
        break;
    case 7:
        switch (per) {
        case 1:
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    cout << ш.field[j][i];
                }
                cout << endl;
            }
            break;
        case 2:
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    cout << ш.field[i][j];
                }
                cout << endl;
            }
            break;
        case 3:
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    cout << ш.field[j][i];
                }
                cout << endl;
            }
            break;
        }
        break;
    }
}

int main() {
    setlocale(LC_ALL, "rus");

    figure I;
    I.id = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            I.field[i][j] = ' ';
        }
    }
    I.field[0][0] = '*';
    I.field[1][0] = '*';
    I.field[2][0] = '*';
    I.field[3][0] = '*';

    figure L;
    L.id = 2;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            L.field[i][j] = ' ';
        }
    }
    L.field[0][0] = '*';
    L.field[1][0] = '*';
    L.field[2][0] = '*';
    L.field[2][1] = '*';

    figure Г;
    Г.id = 3;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            Г.field[i][j] = ' ';
        }
    }
    Г.field[0][0] = '*';
    Г.field[0][1] = '*';
    Г.field[1][0] = '*';
    Г.field[2][0] = '*';

    figure z;
    z.id = 4;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            z.field[i][j] = ' ';
        }
    }
    z.field[0][0] = '*';
    z.field[0][1] = '*';
    z.field[1][1] = '*';
    z.field[1][2] = '*';

    figure s;
    s.id = 5;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            s.field[i][j] = ' ';
        }
    }
    s.field[0][1] = '*';
    s.field[0][2] = '*';
    s.field[1][0] = '*';
    s.field[1][1] = '*';

    figure c;
    c.id = 6;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            c.field[i][j] = ' ';
        }
    }
    c.field[0][0] = '*';
    c.field[0][1] = '*';
    c.field[1][0] = '*';
    c.field[1][1] = '*';

    figure ш;
    ш.id = 7;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            ш.field[i][j] = ' ';
        }
    }
    ш.field[0][1] = '*';
    ш.field[1][0] = '*';
    ш.field[1][1] = '*';
    ш.field[1][2] = '*';
    ran(I, L, Г, z, s, c, ш);

}
