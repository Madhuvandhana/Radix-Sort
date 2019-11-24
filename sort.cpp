#include <cstdio>
#include <cstdlib>

#include "sort.h"

/*
 * HW 2 part
 */
int string_compare(char* s1, char *s2)
{
/*
 * We assume that s1 and s2 are non-null pointers
 */
  int i;

  i = 0;
  while ((s1[i] != 0) && (s2[i] != 0) && (s1[i] == s2[i]))
    i++;

  if (s1[i] == s2[i])
    return 0;
  else
    {
      if (s1[i] < s2[i])
	return -1;
      else
	return 1;
    }
} /*>>>*/

void insertion_sort(char** A, int l, int r)
{
  int i;
  char* key;

  for (int j = l+1; j <= r; j++)
    {
      key = A[j];
      i = j - 1;

      while ((i >= l) && (string_compare(A[i], key) > 0))
        {
	  A[i+1] = A[i];
	  i = i - 1;
	}

      A[i+1] = key;
    }
}
int string_compare_digit(char* s1, char *s2, int d)
{

  if(s1[d] == 0){
    	return -1;
  }
  else if(s2[d] == 0){
    	return 1;
  }
  else if (s1[d] == s2[d]){
    return 0;
  }
  else if(s1[d] < s2[d]){
      	return -1;
    }
  else
    {
	return 1;
    }
} /*>>>*/

void insertion_sort_digit(char** A, int* A_len, int l, int r, int d){
  int i;
  char* key;
  int key_len;

  for (int j = l+1; j <= r; j++)
    {
      key = A[j];
      key_len = A_len[j];
      i = j - 1;

      while ((i >= l) &&  (string_compare_digit(A[i], key, d) > 0 ))
        {
    A[i+1] = A[i];
    A_len[i+1] = A_len[i];
    i = i - 1;
  }

      A[i+1] = key;
      A_len[i+1] = key_len ;
    }

}

void radix_sort_is(char** A, int* A_len, int n, int m){
  for(int i = m-1; i >=0; i--){
    insertion_sort_digit(A, A_len, 0, n-1, i);
  }

}

void counting_sort_digit(char** A, int* A_len, char** B, int* B_len, int n, int d){
  int* c = new int[256];
  for(int i=0; i<256; i++){
    c[i] = 0;
  }

  for(int j=0;j<n;j++){
    c[A[j][d]] = c[A[j][d]]+1;
  }
  // fills the c array in position starting with smallest character's ascii value till the next largest character's ascii value
  for(int i=1; i<256;i++){
    c[i]= c[i]+c[i-1];
  }
  for(int j=n-1; j>=0; j--){
    B[c[A[j][d]]-1] = A[j];
    B_len[c[A[j][d]]-1] = A_len[j];
    c[A[j][d]] = c[A[j][d]]-1;
  }

  for (int i = 0; i<n; ++i)  {
    A[i]=B[i];
    A_len[i]=B_len[i];
}

}

void radix_sort_cs(char** A, int* A_len, int n, int m) {
  char ** input_array_b_counting_sort= new char*[n];
  int* B_len_counting = new int[n];
  for(int i = m-1; i >=0; i--){
     counting_sort_digit(A, A_len, input_array_b_counting_sort, B_len_counting, n, i);
  }
}

/*
 * Simple function to check that our sorting algorithm did work
 * -> problem, if we find position, where the (i-1)-th element is
 *    greater than the i-th element.
 */
bool check_sorted(char** A, int l, int r)
{
  for (int i = l+1; i < r; i++)
    if (string_compare(A[i-1],A[i]) > 0)
      return false;
  return true;
}

/*
 * Simple function to check that our sorting algorithm did work
 * -> problem, if we find position, where the (i-1)-th element is
 *    greater than the i-th element.
 */
bool check_sorted_digit(char** A, int l, int r, int d, int* A_len)
{
  for (int i = l+1; i < r; i++)
    if ((d<=A_len[i]) && A[i-1][d] > A[i][d])
      return false;
  return true;
}

void remove_ivector(char** iv_array, int m)
{
  for (int i = 0; i < m; i++)
    delete[] iv_array[i];
  delete[] iv_array;
}
void remove_array(int* array)
{
  delete[] array;
}
