#include <iostream>
#include <string>
using namespace std;

struct Flat { // определяем структуру квартиры
    int rooms;
    int floor;
    float area;
    string address;
    Flat* next;
};
Flat* createFlat(int rooms, int floor, float area, string address) { // функция создания новой квартиры
    Flat* flat = new Flat;
    flat->rooms = rooms;
    flat->floor = floor;
    flat->area = area;
    flat->address = address;
    flat->next = NULL;
    return flat;
}
void addFlat(Flat* &list, Flat* flat) { // функция добавления квартиры в список
    if (list == NULL) { // если список пуст, добавляем квартиру первой
        list = flat;
    }
    else { // иначе ищем последний элемент списка и добавляем квартиру после него
        Flat* current = list;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = flat;
    }
}
void printList(Flat* list) { // функция вывода списка квартир на экран
    Flat* current = list;
    while (current != NULL) {
        cout << "Количество комнат: " << current->rooms << endl;
        cout << "Этаж: " << current->floor << endl;
        cout << "Площадь: " << current->area << endl;
        cout << "Адрес: " << current->address << endl << endl;
        current = current->next;
    }
}
void searchFlat(Flat* &list, int rooms, int floor) { // функция поиска квартиры в списке
    Flat* current = list;
    Flat* previous = NULL;
    while (current != NULL) {
        if (current->rooms == rooms && current->floor == floor) { // если нашли подходящую квартиру, выводим ее и удаляем из списка
            cout << "Найдена подходящая квартира:" << endl;
            cout << "Количество комнат: " << current->rooms << endl;
            cout << "Этаж: " << current->floor << endl;
            cout << "Площадь: " << current->area << endl;
            cout << "Адрес: " << current->address << endl << endl;
            if (previous == NULL) { // если это первый элемент списка, удаляем его и делаем следующий элемент первым
                list = current->next;
            }
            else { // иначе связываем предыдущий элемент со следующим и удаляем текущий
                previous->next = current->next;
            }
            delete current;
            return;
        }
        previous = current;
        current = current->next;
    }
    cout << "Подходящей квартиры не найдено." << endl << endl;
}
int main() {
    Flat* list = NULL;
    int choice;
    do {
        cout << "Меню:" << endl;
        cout << "1. Добавить квартиру" << endl;
        cout << "2. Поиск квартиры" << endl;
        cout << "3. Вывод списка квартир" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int rooms, floor;
                float area;
                string address;
                cout << "Введите количество комнат: ";
                cin >> rooms;
                cout << "Введите этаж: ";
                cin >> floor;
                cout << "Введите площадь: ";
                cin >> area;
                cout << "Введите адрес: ";
                cin >> address;
                Flat* flat = createFlat(rooms, floor, area, address);
                addFlat(list, flat);
                break;
            }
            case 2: {
                int rooms, floor;
                cout << "Введите количество комнат: ";
                cin >> rooms;
                cout << "Введите этаж: ";
                cin >> floor;
                searchFlat(list, rooms, floor);
                break;
            }
            case 3: {
                cout << "Список квартир:" << endl;
                printList(list);
                break;
            }
            case 0: {
                cout << "Выход из программы." << endl;
                break;
            }
            default: {
                cout << "Неверный выбор. Попробуйте еще раз." << endl;
                break;
            }
        }
    } while (choice != 0);
    return 0;
}
