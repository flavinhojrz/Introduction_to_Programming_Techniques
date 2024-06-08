#include <iostream>

int binary_search(int arr[], int begin, int end_arr, int item){

  if (end_arr >= begin) {
    int mid = begin + (end_arr - begin) / 2;

    if (arr[mid] == item){
      return mid;
    }
    else if (arr[mid] > item){
      return binary_search(arr, begin, mid - 1, item);
    }
    else {
      return binary_search(arr, mid + 1, end_arr, item);
    }
  }
  return -1; 
}

int main() {
  int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int item = 5; 
  int pos = binary_search(array, 0, 10, item);
  if (pos != -1) {
    std::cout << "O número " << item << " está na posição: " << pos << std::endl;
  } else {
    std::cout << "Número não encontrado" << std::endl;
  }
}
