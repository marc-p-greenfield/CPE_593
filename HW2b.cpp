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

//Creating the heap
void heapify(int a[], int n, int i){
    int max = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    //Assume the max value is the root i

    if (left < n && a[left] > a[max])
        max = left;
    if (right < n && a[right] > a[max])
        max = right;
    //Above statements determining which node is maximum

    if (max != i){
        swap(a[i], a[max]);
        heapify(a,n,max);
        //If the max value is not the root, swap and recursively call the function and start over with the new largest as the root
    }
}

//The main-recursive heapsort function
void heapsort(int a[], int n){
    for (int i = (n/2)-1; i >= 0; i--)
        heapify(a,n,i);
    for (int i = n-1; i >= 0; i--){
        swap(a[0], a[i]);
        heapify(a,i,0);
    }
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
    myFile.open("hw2b.dat");

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
        heapsort(array,y);
        print (array,y);
    }

}
