// HomeWork12.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

//Добавить метод removeAll() полного удаления списка.
//Использовать этот метод в перегрузке оператора[].


//Код с занятия :

template <typename T>
class LinkedList {
public:
    class Node {
    public:
        T data;
        Node* next;

        Node() { this->data = 0; this->next = nullptr; }

        Node(T value) { this->data = value; this->next = nullptr; }
    };

    Node* Head;

    LinkedList() { this->Head = nullptr; }
    LinkedList(Node* head) { this->Head = head; }

    void push(T value) {
        if (Head == nullptr) {
            Head = new Node(value);
        }
        else {
            Node* current = Head;

            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new Node(value);
        }
    }

    void print() {
        if (Head == nullptr) {
            cout << "Список пустой";
        }
        else {
            Node* current = Head;

            while (current->next != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << current->data << " ";
            cout << endl;
        }
    }

    T get(int index) {
        if (Head == nullptr) {
            return 0;
        }
        else {
            Node* current = Head;

            while (current->next != nullptr && index > 0) {
                current = current->next;
                index--;
            }
            return current->data;
        }
    }

    void remove(T data) {
        Node* current = Head;

        while (current->next != nullptr && current->data != data) {
            current = current->next;
        }
    }

    void removeAt(int index) {

        Node* current = Head;

        while (current->next != nullptr && index > 1) {
            current = current->next;
            index--;
        }
        Node* buffer = current->next->next;
        delete current->next;
        current->next = buffer;
    }

    T& operator[] (int i) {
        Node* current = Head;
        while (i > 0) {
            current = current->next;
            i--;
        }
        return current->data;
    }

    friend std::ostream& operator<<(std::ostream& os, const LinkedList& list) {
        if (list.Head == nullptr) {
            os << "Список пустой";
        }
        else {
            Node* current = list.Head;

            while (current != nullptr) {
                os << current->data << " ";
                current = current->next;
            }
        }
        return os;
    }

    LinkedList& operator= (const LinkedList& list) {
        int busyCount = 0;
        Node* tempCurrent = this->Head;
        for (int i = 0; ; ++i)
        {
            if (tempCurrent->next != nullptr)
                tempCurrent = tempCurrent->next;
            else
            {
                busyCount = i;
                break;
            }
        }

        Node* currentSecond = list.Head;
        Node* current = this->Head;
            int countt = 0;
            T tempval;
        while (currentSecond != nullptr) {
            this->push(currentSecond->data);
            currentSecond = currentSecond->next;
            if (!countt)
            {
                tempval = Head->data;
                for (int i = 0; i <= busyCount; ++i)
                    current = current->next;
                Head->data = current->data;
                current->data = tempval;
            }
            countt++;
        }

        if (busyCount >=0)
        {
            while (busyCount>= 0)
            {
                --busyCount;
                removeAt(0);
            }
        }
        else return *this;

        return *this;
    }

    //Добавить очистку текущего списка перед присваиванием.


};



int main() {
    setlocale(LC_ALL, "rus");
    LinkedList<string> list;
    list.push("10");
    list.push("15");
    list.push("20");
    list.push("25");
    list.push("30");

    LinkedList<string> list2;
    list2.push("HELLO");
    list2.push("HELLO");
    list2.push("HELLO");
    list2.push("HELLO");
    list2.print();
    std::cout << "_____________________Первоначальный вариант списка перед присваиванием" << std::endl;

    list2 = list;

    list[3] = "Error";
    list2.print();
    list.print();
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
