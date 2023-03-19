#include <iostream>
#include <cstdlib>
#include <ctime>

const int size = 10;
int arr[size];

template <typename T>
void three_max(T &a, T &b, T &c) {
	T max = a;
	if (b > max) max = b;
	if (c > max) max = c;
	a = b = c = max;
}

template <typename T>
void fill_arr(T *p_arr, const int length, T A, T B) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		*(p_arr + i) = rand() % (B - A + 1) + A; // [A..B]
}

template <typename T>
void print_arr(T *p_arr, const int length) {
	std::cout << '[';
	for (int i = 0; i < length; i++)
		std::cout << *(p_arr + i) << ", ";
	std::cout << "\b\b]\n";
}

template <typename T>
T &first_el(T *p_arr, const int length) {
	for (int i = 0; i < length; i++)
		if (*(p_arr + i) < 0)
			return *(p_arr + i);
	return *p_arr;
}

template <typename T>
void coincident_to_zero(T *p_arr1, const int length1, T *p_arr2, const int length2) {
	for (int i = 0; i < length1; i++)
		for(int j = 0; j < length2; j++)
			if (*(p_arr2 + j) == *(p_arr1 + i)) 
				*(p_arr2 + j) = 0;
}

int main() {
	
	//23.1 Max of 3 numbers
	std::cout << "\t23.1 Max of 3 numbers\n";
	int a, b, c;
	std::cout << "Enter 3 numbers -> ";
	std::cin >> a >> b >> c;
	std::cout << "a = " << a << "\nb = " << b << "\nc = " << c << '\n';
	three_max(a, b, c);
	std::cout << "Now all 3 numbers are equal to max:\n";
	std::cout << "a = " << a << "\nb = " << b << "\nc = " << c << '\n';


	//23.2 First negative array element
	std::cout << "\n\t23.2 First negative array element\n";
	int *p_arr = arr;
	fill_arr(p_arr, size, -2, 10);	// [-2..10]
	std::cout << "Array:\n";
	print_arr(p_arr, size);
	std::cout << "First (negative) array element: " << first_el(p_arr, size) << "\n\n";


	//23.3 Coincident array elements => to zero
	std::cout << "\t23.3 Coincident array elements => to zero\n";
	const int size1 = 8;
	int arr1[size1];
	int *p_arr1 = arr1;
	fill_arr(p_arr1, size1, 2, 9);	// [2..9]
	std::cout << "Array 1:\n"; 
	print_arr(p_arr1, size1);
	
	const int size2 = 10;
	int arr2[size2];
	int *p_arr2 = arr2;
	fill_arr(p_arr2, size2, 1, 10);	// [1..10]
	std::cout << "\nInitial array 2:\n";
	print_arr(p_arr2, size2);
	coincident_to_zero(p_arr1, size1, p_arr2, size2);
	std::cout << "\nResult array 2:\n";
	print_arr(p_arr2, size2);
	
	return 0;
}