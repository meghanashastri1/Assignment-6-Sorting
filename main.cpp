#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>


using namespace std;


void bubbleSort(double* myArray, int n){
  for (int i = 0; i < n; ++i) {
    double temp = 0;
    for (int j = i; j < n-1; ++j){
      if (myArray[j] > myArray[j + 1]) {
        temp = myArray[j + 1];
        myArray[j + 1] = myArray[j];
        myArray[j] = temp;
      }
    }
  }
  cout << "Bubble Sort: " << endl;
  for (int k = 0; k < n; ++k){
    cout << myArray[k] << endl;
  }
}

void selectionSort(double *myArray, int n){
  int i, j, minIndex;
  double temp;
  for (i = 0; i < n-1; i++){
    minIndex = i;
    for (j = i+1; j < n; j++){
      if (myArray[j] < myArray[minIndex]){
        minIndex = j;
      }
      if (minIndex != i){
        temp = myArray[i];
        myArray[i] = myArray[minIndex];
        myArray[minIndex] = temp;
      }
    }
  }
  cout << "selection sort: " << endl;
  for (int k = 0; k < n; ++k){
    cout << myArray[k] << endl;
  }
}

void insertionSort(double* myArray, int n){
  for (int j = 0; j < n; ++j){//marker
    double temp = myArray[j]; //store marked item
    int i = j;//where to start shifting
    while (i > 0 && myArray[i-1] >= temp){
      myArray[i] = myArray[i-1];
      --i;
    }
    myArray[i] = temp;
  }
  cout << "insertion sort: " << endl;
  for (int k = 0; k < n; ++k){
    cout << myArray[k] << endl;
  }
}

int partition(double* myArray, int start, int end){
  double temp;
  double piv = myArray[end];
  int j = start-1;
  for (int i = start; i < end; ++i){
    if (myArray[i] <= piv){
      ++j;
      temp = myArray[j];
      myArray[j] = myArray[i];
      myArray[i] = temp;
    }
  }
  temp = myArray[j + 1];
  myArray[j + 1] = myArray[end];
  myArray[end] = temp;
  return (j + 1);
}

void quickSort(double* myArray, int start, int end){
  if (start < end){
    int idx = partition(myArray, start, end);
    quickSort(myArray, start, idx-1);
    quickSort(myArray, idx+1, end);
  }
}

int shellSort(double* myArray, int n){
  for (int gap = n/2; gap > 0; gap /= 2){
    for (int j = gap; j < n; j +=1){
      double temp = myArray[j];
      int i;
      for (int i = j; i >= gap && myArray[i - gap] > temp; i -= gap){
        myArray[i] = myArray[i - gap];
      }
      myArray[i] = temp;
    }
  }
  return 0;
}


int main (int argc, char ** argv){
  //string userInput;
  string fileName;
  int count;
  string nElements;
  string line;
  int numLine = 1;
  int numbers;
  double fileArray;
  clock_t startTime;
  clock_t endTime;
  float calculatedTime;

  cout << "please enter a file to sort" << endl;
  cin >> fileName;
  ifstream file(fileName);
  if (file.is_open()){
    while(getline(file, line)){
      ++numLine;
        cout << line << endl;
    }
  }
  file.close();


  int size = 10;
  double bubbleArray[size] = {1.0, 3.2, 2.5, 5.3, 6.7, 4.8, 7.1, 9.4, 8.6, 10.3};
  double insertionArray[size] = {1.0, 3.2, 2.5, 5.3, 6.7, 4.8, 7.1, 9.4, 8.6, 10.3};
  double selectionArray[size] = {1.0, 3.2, 2.5, 5.3, 6.7, 4.8, 7.1, 9.4, 8.6, 10.3};
  double quickArray[size] = {1.0, 3.2, 2.5, 5.3, 6.7, 4.8, 7.1, 9.4, 8.6, 10.3};
  double shellArray[size] = {1.0, 3.2, 2.5, 5.3, 6.7, 4.8, 7.1, 9.4, 8.6, 10.3};

  startTime = clock();
  bubbleSort(bubbleArray, size);
  endTime = clock();
  calculatedTime = (float(endTime - startTime)/CLOCKS_PER_SEC)*1000;
  cout << "bubble sort time: " << calculatedTime << "seconds" << size << endl;

  startTime = clock();
  insertionSort(insertionArray, size);
  endTime = clock();
  calculatedTime = (float(endTime - startTime)/CLOCKS_PER_SEC)*1000;
  cout << "insertion sort time: " << calculatedTime << "seconds" << size << endl;


  startTime = clock();
  selectionSort(selectionArray, size);
  endTime = clock();
  calculatedTime = (float(endTime - startTime)/CLOCKS_PER_SEC)*1000;
  cout << "selection sort time: " << calculatedTime << "seconds" << size << endl;

  startTime = clock();
  quickSort(quickArray, 0, size - 1);
  endTime = clock();
  calculatedTime = (float(endTime - startTime)/CLOCKS_PER_SEC)*1000;
  cout << "Quick sort time: " << calculatedTime << "seconds" << size << endl;

  /*for (int k = 0; k < size; ++k){
    cout << quickArray[k] << endl;
  }*/

  //cout << "shellsort: " << endl;
  startTime = clock();
  shellSort(shellArray, size);
  endTime = clock();
  calculatedTime = (float(endTime - startTime)/CLOCKS_PER_SEC)*1000;
  cout << "shell sort time: " << calculatedTime << "ms" << size << endl;

  /*for (int k = 0; k < size; ++k){
    cout << shellArray[k] << endl;
  }*/
  return 0;
}
