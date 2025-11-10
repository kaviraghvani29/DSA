#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[100], even[100], odd[100];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int e = 0, o = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0)
            even[e++] = arr[i];
        else
            odd[o++] = arr[i];
    }

    for (int i = 0; i < e - 1; i++)
        for (int j = 0; j < e - i - 1; j++)
            if (even[j] > even[j + 1])
                swap(even[j], even[j + 1]);

    for (int i = 0; i < o - 1; i++)
        for (int j = 0; j < o - i - 1; j++)
            if (odd[j] < odd[j + 1])
                swap(odd[j], odd[j + 1]);

    cout << "Merged array (Even Asc + Odd Desc): ";
    for (int i = 0; i < e; i++)
        cout << even[i] << " ";
    for (int i = 0; i < o; i++)
        cout << odd[i] << " ";

    return 0;
}
