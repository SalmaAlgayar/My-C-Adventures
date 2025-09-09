#include <stdio.h>


void bubble_sort(int * arr, int arr_lengh, int flag /*0 ASC - 1 DESC*/ ) {
    flag = 1 - 2 * flag;
    for (int i = 0; i < arr_lengh; i++) {
        for (int j = 0, tmp = arr[0]; j < arr_lengh - 1; j++, tmp = arr[j]) {
            if (flag * arr[j] > flag * arr[j + 1]) {
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;

            }
        }
    }
}


void print_arr(int * arr, int arr_lengh) {
    for (int i = 0; i < arr_lengh; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main()
{

    int bucket[] = {
        7,
        1,
        3,
        9,
        0,
        2,
        4,
        5,
        8,
        6
    };
    int arr_lengh = sizeof(bucket) / sizeof(int);



    // Original
    print_arr(bucket, arr_lengh);

    // Ascending
    bubble_sort(bucket, arr_lengh, 0);
    print_arr(bucket, arr_lengh);

    // Descending
    bubble_sort(bucket, arr_lengh, 1);
    print_arr(bucket, arr_lengh);

}
