#include <stdio.h>

// 교환
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// 분할
int partition(int arr[], int low, int high) {
  int pivot = arr[high];       // 제일 끝에 숫자 피봇설정
  swap(&arr[low], &arr[high]); // 맨앞으로 땡기기
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
    } else { // i와 j를 교환
      swap(&arr[i], &arr[j]);
    }
  }
  return j; // pivot이 들어갈 위치를 반환
}

// 셀렉션
int selection(int arr[], int low, int high, int k) {
  if (low == high) {
    return arr[low];
  }

  int pivot_index = partition(arr, low, high); // 피봇
  int pivot_rank = pivot_index - low + 1; // 피봇의 랭크
  if (k == pivot_rank) {
    return arr[pivot_index];
  } else if (k < pivot_rank) {
    return selection(arr, low, pivot_index - 1, k); // 왼쪽 부분 배열 k번째 작은 원소
  } else { // k > pivot_rank
    return selection(arr, pivot_index + 1, high, k - pivot_rank); // 오른쪽 부분 배열 k-pivot_rank
  }
}

int main() {
  int arr[] = {6, 3, 11, 9, 12, 2, 8, 15, 18, 10, 7, 14};
  int result = selection(arr, 0, 11, 7);
  printf("%d", result);

  return 0;
}