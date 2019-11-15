//Calling three libraries for using different funtions of them used for sorting.
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
//Making a template (used for creating any type of array)
	template <class T>
	int partition(T* array, int start, int end, bool asc){
		T pivot = array[end]; // Selecting a pivot point
		int Pindex = start; // for comparing selecting an element as starting element named Pindex.
		//for loop including functions of swap for sorting in ascending or descending order
		for (int i = start; i < end; i++)
		{
			if (asc){
				if (array[i] <= pivot)
				{
					swap(array[i], array[Pindex]);
					Pindex++;
				}
			} else {
				if (array[i] >= pivot) 
				{
					swap(array[i], array[Pindex]);
					Pindex++;
				}
			}
		}
		swap(array[Pindex], array[end]);
		return Pindex;
	}

	template <class X>
	void quickSort(X *array, int start, int end, bool asc) {
		if (start < end) {
			int Pindex = partition<X>(array, start, end, asc);
			quickSort(array, start, Pindex - 1, asc);
			quickSort(array, Pindex + 1, end, asc);
		}
	}

	template<class Z>
	void getArrTypeInp() {
		system("cls");

		int size;
		Z *array;
		cout << "Enter the number of elements: ";
		cin >> size;
		array = new Z[size];
		cout << "Enter the elements: " << endl;

		for (int i = 0; i < size; i++){
			cin >> array[i];
		}

		system("cls");

		cout << "Order," << endl;
		cout << "1) Ascending" << endl;
		cout << "2) Descending" << endl << endl;

		int orderInp;
		bool asc;
		cout << "Input: " << endl;
		cin >> orderInp;

		switch (orderInp) {
		case 1:
			asc = true;
			break;
		case 2:
			asc = false;
			break;
		}

		system("CLS");
		cout << "Unsorted Array: ";
		
		for (int i = 0; i < size; i++)
			cout << array[i] << " ";

		quickSort<Z>(array, 0, size - 1, asc);
		
		cout << "\nSorted Array: ";
		for (int i = 0; i < size; i++)
			cout << array[i] << " ";

		cout << "\n";
	};

	void main(){
		cout << "Enter array element type," << endl;
		cout << "1) long" << endl;
		cout << "2) float" << endl;
		cout << "3) string" << endl;
		cout << endl << endl << "Input: ";

		int typeInp;

		cin >> typeInp;

		switch (typeInp) {
			case 1:
				getArrTypeInp<long>();
				break;
			case 2:
				getArrTypeInp<float>();
				break;
			case 3:
				getArrTypeInp<string>();
				break;
		}
	}
