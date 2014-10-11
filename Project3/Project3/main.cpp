//
// Project 3
// Name: Daniil Kim
// Group: 201.1
// Date: 4.10.2014
// Task: Insertion sorts
// IDE: Xcode, tested in Visual Studio
//

#include <iostream>
#include <fstream>
#include <string>
#include "sortings.h"

using namespace std;

void read_arrays();
void read_input(int &param, string message);
void copy_array(int array1[], int array2[], int n);
void sort_array(int array[], int n);

int main(int argc, const char *argv[]) {
  // User's choice
  int choice;
  cout << "1. Generate an array\n2. Read from file" << endl;
  cin >> choice;

  switch (choice) {
  case 1:
    // Generate an array
    int array_size;
    read_input(array_size, "Enter array size: ");

    int min;
    read_input(min, "Enter minimum value: ");

    int max;
    read_input(max, "Enter maximum value: ");

    cout << endl;

    int *array;
    array = new int[array_size];

    array_generation(array, array_size, min, max);
    sort_array(array, array_size);

    delete[] array;
    break;
  case 2:
    // Read arrays from file
    read_arrays();
    break;

  default:
    cout << "Error" << endl;
    break;
  }
}

// Read and sort arrays from file
void read_arrays() {
  string line;
  ifstream input_file;
  input_file.open("test_proekt_3.txt");

  if (input_file.is_open()) {
    // Get arrays count
    int n;
    input_file >> n;
    cout << "Arrays: " << n << "\n" << endl;

    // Read arrays
    for (int i = 0; i < n; i++) {
      // Get array size
      int array_size;
      input_file >> array_size;
      cout << "Array size: " << array_size << endl;

      int *array;
      array = new int[array_size];

      // Read array elements
      for (int j = 0; j < array_size; j++) {
        int element;
        input_file >> element;
        array[j] = element;
      }

      // Sort array
      sort_array(array, array_size);

      if (i != n - 1) {
        cout << endl;
      }
      delete[] array;
    }
  } else {
    cout << "Unable to open" << endl;
  }
}

// Read integer input from the console
void read_input(int &param, string message) {
  while (true) {
    cout << message;
    if (cin >> param) {
      break;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
}

// Copy array1 to array2
void copy_array(int array1[], int array2[], int n) {
  for (int i = 0; i < n; i++) {
    array2[i] = array1[i];
  }
}

// Sort the array and pretty print the result
void sort_array(int array[], int n) {
  // Sort copied array, not the original one
  int *array_copy;
  array_copy = new int[n];

  // Print array
  cout << "Array before: " << endl;
  results(array, n);

  // Insertion sort
  cout << "Insertion sort: " << endl;
  copy_array(array, array_copy, n);
  insertion_sort(array_copy, n);
  results(array_copy, n);

  // Binary sort
  cout << "Binary sort: " << endl;
  copy_array(array, array_copy, n);
  binary_sort(array_copy, n);
  results(array_copy, n);

  // Clean up
  delete[] array_copy;
}