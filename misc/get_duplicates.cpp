#include <iostream>
 
using namespace std;

void dump(int arr[], int n) {
    for (int i = 0; i < n; ++ i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// for each element xi, 
// swap arr[i] and arr[xi-1], set count of arr[xi-1].
void printNumCount(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        int x = arr[i];
        if (x <= 0)
            continue;
        else {
            int y = arr[x-1];
            if (y <= 0) {
                arr[x-1]--;
                arr[i] = 0;
            } else {
                arr[i] = y;
                arr[x-1] = -1;
                i--;
            }
        }
        
        dump(arr, n);
    }  
    for (int i = 0; i < n; i++)
        cout << "Count of " <<  i+1 << ": " << -arr[i] << endl;
}

/*
// By: dreamstring
// http://www.mitbbs.com/article_t1/JobHunting/32340835_0_4.html
void printNumCount2(int arr[], int n)
{
    for(int i = 0; i < n; ++i)
    {
        int num = arr[i];
        while(arr[num-1] != num)
        {
            swap(arr, num-1, i);
            num = arr[i];
        }
    }
    for(int i = 0; i < n; ++i)
    {
        if(arr[i] == i+1)
            arr[i] = 1;
        else
        {
            arr[arr[i]-1]++;
            arr[i] = 0;
        }
    }
}
*/

int main()
{
    //int arr[] = {1, 1, 1, 1, 1};
    int arr[] = {3, 2, 4, 2, 1};
    printNumCount(arr, sizeof(arr) / sizeof(int));
    return 0;
}
