#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

/*
Author : Marc Greenfield
Due Date : 09/26/17
*/

//Recursive quicksort function
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

//Simple print function
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

    //If-statement below determines number of lists in the .dat file
    if(myFile.is_open()){
        myFile >> x;
    }

    int y;
    int *array;

    //For loop to run through each list
    for (int i = 0; i < x; i++){
        if(myFile.is_open()){
            myFile >> y;
            array = new int[y];
            //For loop to iterate through one list
            for (int j = 0; j < y; j++)
                myFile >> array[j];
        }
        quickSort(array,0,y-1);
        print (array,y);
    }

}
