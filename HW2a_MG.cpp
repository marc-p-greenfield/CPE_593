#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


void quickSort(int x[], int L, int R) {
    int pivot = x[(L + R) / 2];
    int i = L, j = R;

    while (i <= j) {
        while (x[i] < pivot)
            i++;
        while(x[j] > pivot)
            j--;
        // at this point, i == j == pivot
        if (i <= j) {
            swap(x[i], x[j]);
            i++;
            j--;
        }
    }
    if (L < j)
        quickSort(x, L, j);
    if (i < R)
        quickSort(x, i, R);
}

void print(int a[], int n) {
    for (int i = 0; i < n; i++){
        cout << a[i] << " " ;
    }
    cout << endl;
}

int main() {
    string temp;
    int x;
    ifstream myFile;
    myFile.open("hw2a.dat");
    if(myFile.is_open()){
        myFile >> x;
    }

    int y;
    int *array;

    for (int i = 0; i < x; i++){
        if(myFile.is_open()){
            myFile >> y;
            array = new int[y];
            for (int j = 0; j < y; j++)
                myFile >> array[j];
        }
        quickSort(array,0,y-1);
        print (array,y);
    }

}
