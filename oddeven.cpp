#include<iostream>
using namespace std;

int main()
{
    int arr[6] = {1,2,3,4,5,6};
    int even=0;
    int odd=0;

    for(int i=0; i<6; i++)
    {
        if(arr[i] % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }
    cout << "Even: " << even << endl;
    cout << "Odd: " << odd << endl;
}