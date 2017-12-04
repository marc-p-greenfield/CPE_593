/*
 Author : Marc Greenfield
 Date : 10/23/17
 Note : Was not present for class - homework is based on lecture video from spring 2017
 Sources : Received help from Joe Puciloski
 */

#include <iostream>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

class GrowArray {
private:
	int* p;
	int used;
	int size;

	void grow() {
		size = size * 2 + 2;
		int* temp = p;
		p = new int[size];
		for (int i = 0; i < used; i++)
			p[i] = temp[i];
		delete [] temp;
	}

public:
	GrowArray() : p(NULL), used(0), size(0) {}

	~GrowArray() {
		delete [] p;
	}

	GrowArray(const GrowArray& original): p(new int[original.used]), used(original.used), size(original.size) {
		for (int i = 0; i < original.used; i++)
			p[i] = original.p[i];
	}

	GrowArray& operator =(GrowArray copy) {
		int* temp = p; p = copy.p; copy.p = temp;}

    //Function to add to front of grow array
	void add_front(int original) {
		if (used >= size)
			grow();
		used++;
		for (int i = used; i > 0; i--)
			p[i] = p[i-1];
		p[0] = original;
	}

    //Function to add to back of grow array
	void add_back(int original) {
		if (used >= size)
			grow();
		p[used++] = original;
	}

    //Function to remove from front of grow array
    void remove_front(){
        used--;
        for (int i = 0; i < used; i++)
            p[i] = p[i+1];
    }

    //Function to remove from back of grow array
	void remove_back(){
		used--;
	}

    //Defines how to print out the grow array
    friend ostream& operator <<(ostream& s, const GrowArray& a){
        for (int i = 0; i < a.used - 1; i++)
            s << a.p[i] << ",";
        s << a.p[a.used - 1];
        return s;
    }

};

int main(){
    //Opens homework file
	ifstream f ("HW4a.txt");
	GrowArray grow;
	string line;

    //This while loop will continue to run until there are no lines left in the file
	while(f >> line){
		if(line == "OUTPUT")
			cout << grow << '\n';

		else if (line == "ADD_FRONT"){
			string values;
			f >> values;
			int pos, a, b, c;

            //This sub function takes in the three inputs for add front, separated by colons
			pos = values.find(":");
			stringstream strTointa(values.substr(0, pos));
			strTointa >> a;
			values.erase(0, pos + 1);

			pos = values.find(":");
			stringstream strTointb(values.substr(0, pos));
			strTointb >> b;
			values.erase(0, pos + 1);

			stringstream strTointc(values);
			strTointc >> c;

            //Executes the actual function
			for (int i = a; i <= c; i += b)
				grow.add_front(i);
		}

		else if (line == "ADD_BACK"){
			string values;
			f >> values;
			int pos, a, b, c;

            //Similar to ADD_FRONT, this take in values, separated by colons
			pos = values.find(":");
			stringstream strTointa(values.substr(0, pos));
			strTointa >> a;
			values.erase(0, pos + 1);

			pos = values.find(":");
			stringstream strTointb(values.substr(0, pos));
			strTointb >> b;
			values.erase(0, pos + 1);

			stringstream strTointc(values);
			strTointc >> c;

            //Executes the actual function
			for (int i = a; i <= c; i += b)
				grow.add_back(i);
		}

        else if (line == "REMOVE_FRONT"){
			string values;
			f >> values;
			int a;
			stringstream strToint(values);
			strToint >> a;
			for (int i = a; i > 0; i--)
				grow.remove_front();
		}

		else if (line == "REMOVE_BACK"){
			string values;
			f >> values;
			int a;
			stringstream strToint(values);
			strToint >> a;
			for (int i = a; i > 0; i--)
				grow.remove_back();
		}

	}


    //Closes the file once we are done reading from it
	f.close();
}
