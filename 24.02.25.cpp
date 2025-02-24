#include <iostream>
using namespace std;

void checkPass() {
    string pass;
    bool IsExecut = false;

    do try {
        cout << "Для регистрации введите пароль состоящий минимиум из 8 символов без знаков '.', ',', '/'" << endl;
        cin >> pass;
        if (pass.size() != 8) {
            throw "ошибка с размером";
        }
        else {
            for (int i = 0; i < 8; i++) {
                if (pass[i] == '.' || pass[i] == ',' || pass[i] == '/') {
                    throw "ошибка, есть символ";
                }
            }
            cout << "Пароль принят";
            IsExecut = true;
            cout << "Новый пароль: " << pass;
            
        }
    }
    catch (const char* error) {
        cout << error << endl;
    }
    while (IsExecut == false);
}

int main()
{
    setlocale(LC_ALL, "rus");
    checkPass();
}
