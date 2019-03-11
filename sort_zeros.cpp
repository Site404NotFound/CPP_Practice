#include <iostream>
#include <array>

using namespace std;

int sort_list(int, int*);
void add_zeros(int, int, int*);
void print_list(int, int*);

int main() {
	// SOLUTION: 1, 2, 4, 5, 1, 1, 9, 0, 0, 0, 0
	int num_list[11] = {0, 1, 2, 0, 0, 4, 5, 1, 1, 0, 9};
	cout << "Original List:" << endl;
	print_list(11, num_list);
	int zero_count = sort_list(11, num_list);
	add_zeros(zero_count, 11, num_list);
	cout << "Sorted List:" << endl;
	print_list(11, num_list);
	return 0;
}

/*******************************************************************
 * Function receives the array size and a list of numbers. The
 * function then searches each array index for zero values.  When
 * a zero is located the counter is incresed.  When a non-zero
 * value is located, the number is shifted forward in the array the
 * as many indeces as zeros that have been located.
 * 
 * Function returns the number of zeros that were encountered
 ******************************************************************/

int sort_list(int size, int* num_list) {
	int zero_count = 0;
	for(int i = 0; i < size; ++i) {
		if(num_list[i] == 0) {
			++zero_count;
		}
		if(zero_count > 0 && num_list[i] > 0) {
			num_list[i - zero_count] = num_list[i];
		}
	}
	return zero_count;
}

/*******************************************************************
 * Function receives the array of integers (as a pointer), the size
 * of the array, and the number of zeros that were located.  For
 * each zero that was found, the function places a zero at the end
 * of the number array.
 ******************************************************************/

void add_zeros(int count, int size, int* num_list) {
	for(int i = 0; i < count; ++i){
		num_list[size - i - 1] = 0;
	}
}

/*******************************************************************
 * Function prints the elements of the number array.  Uses a comma
 * to seperate values and a newline after the last value
 ******************************************************************/

void print_list(int size, int* num_list) {
	for(int i = 0; i < size; ++i) {
		cout << num_list[i];
		if(i < (size - 1)){
			cout << ", ";
		} else {
			cout << endl;
		}
	} 
}
