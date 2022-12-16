#include <iostream>
#include <cstdio>
#include "omp.h"
#include<vector>

using namespace std;

void mod(const vector<bool> &base) {
    size_t n = base.size(), i, num;
#pragma omp parallel for default(none) shared(base, n) private(i) schedule(dynamic)
    for (i = 0; i < n; ++i) {
        if (base[i]) {
            printf("Group number %d find treasure\n", omp_get_thread_num());
        }
    }
}

// модель вычислений - openMp
// пример описание ввода данных см ниже
// ввод данных из консоли - ок
int main() {
    while (true) {
        int count, len, pos;
        cout << "Enter the size of the island (the number of elements in the array [1..100000000]): \n";
        cin >> len;
        cout << "Enter the number of pirate groups [1..16]: \n";
        cin >> count;
        cout
                << "Enter the place where the treasure will be hidden(the number of the cell from 0 to the size of the island is 1): \n";
        cin >> pos;
        omp_set_num_threads(count); // делаем количество потоков ровно столько сколько групп пиратов
        vector<bool> base(len, false); // вектор это по сути остров который пираты будут обыскивать
        base[pos] = true; // позиция сокровища
        mod(base);
        int ok;
        cout << "Do you want to run the program again? Enter 1 if yes, otherwise 0.\n";
        cin >> ok;
        if (ok == 0)
            break;

    }


    return 0;
}
