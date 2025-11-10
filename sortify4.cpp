#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[100];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int positive = 0, negative = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0)
            positive++;
        else if (arr[i] < 0)
            negative++;
    }

    cout << "Count of Positive Numbers: " << positive << endl;
    cout << "Count of Negative Numbers: " << negative << endl;
    return 0;
}
