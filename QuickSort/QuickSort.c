#include <stdio.h>

//교환
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// 분할
int partition(int arr[], int low, int high) {
  int pivot = arr[high]; // 제일 끝에 숫자 피봇설정
  printf("pivot : %d \n", pivot);
  swap(&arr[low], &arr[high]); // 맨앞으로 땡기기
  printf("%2d 교환 %2d: ", arr[low], arr[high]);
  for (int i = 0; i < 12; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  int i = (low + 1);
  int j = high;

  while (i <= j) {
    while (i <= high && arr[i] < pivot) { // pivot보다 큰 값까지
      i++;
    }
    while (j > low && arr[j] >= pivot) { // pivot보다 작은 값까지
      j--;
    }
    if (i > j) { // 피봇을 작은놈 옆으로
      swap(&arr[low], &arr[j]);
      printf("%2d 교환 %2d: ", arr[low], arr[j]);
      for (int i = 0; i < 12; i++) {
        printf("%d ", arr[i]);
      }
      printf("\n");
    } else { // i와 j를 교환
      swap(&arr[i], &arr[j]);
      printf("%2d 교환 %2d: ", arr[i], arr[j]);
      for (int i = 0; i < 12; i++) {
        printf("%d ", arr[i]);
      }
      printf("\n");
    }
  }

  return j; // pivot이 들어갈 위치를 반환
}

//퀵 정렬
void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high); // 피봇 중심 좌우 분할
    quickSort(arr, low, pi - 1);        // 왼쪽
    quickSort(arr, pi + 1, high);       // 오른쪽
  }
}

int main() {
  int arr[] = {6, 3, 11, 9, 12, 2, 8, 15, 18, 10, 7, 14};

  printf("\n");
  quickSort(arr, 0, 11);
  for (int i = 0; i < 12; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}
