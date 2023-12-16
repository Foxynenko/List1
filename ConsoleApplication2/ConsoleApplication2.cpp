#include <iostream>
#include <vector>

using namespace std;

// Визначення структури вузла
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Функція для об'єднання двох відсортованих списків
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    // Створюємо пустий вузол, який буде головою нового списку
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;

    // Поки один зі списків не закінчиться
    while (list1 != nullptr && list2 != nullptr) {
        // Вибираємо менший елемент і додаємо його до нового списку
        if (list1->val < list2->val) {
            current->next = list1;
            list1 = list1->next;
        }
        else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    // Якщо один зі списків закінчився, додаємо решту елементів іншого списку
    if (list1 != nullptr) {
        current->next = list1;
    }
    else {
        current->next = list2;
    }

    // Повертаємо голову нового списку (починаючи з наступного від dummy, оскільки dummy - це фіктивний вузол)
    return dummy->next;
}

// Функція для виводу списку
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Приклад 1
    vector<int> list1_values = { 1, 2, 4 };
    vector<int> list2_values = { 1, 3, 4 };

    // Створюємо списки
    ListNode* list1 = nullptr;
    for (int i = list1_values.size() - 1; i >= 0; --i) {
        ListNode* temp = new ListNode(list1_values[i]);
        temp->next = list1;
        list1 = temp;
    }

    ListNode* list2 = nullptr;
    for (int i = list2_values.size() - 1; i >= 0; --i) {
        ListNode* temp = new ListNode(list2_values[i]);
        temp->next = list2;
        list2 = temp;
    }

    // Об'єднуємо списки
    ListNode* mergedList = mergeTwoLists(list1, list2);

    // Виводимо результат
    cout << "Merged List: ";
    printList(mergedList);

    return 0;
}
