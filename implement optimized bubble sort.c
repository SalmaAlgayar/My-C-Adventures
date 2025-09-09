#include <stdio.h>

void print_arr(int * arr, int arr_lengh) {
    for (int i = 0; i < arr_lengh; i++) printf("%d ", arr[i]);
    printf("\n");
}

void bubble_sort_optimized(int * arr, int arr_lengh, int flag /*0 ASC - 1 DESC*/ ) {
    arr_lengh--;
    int start = (flag) * arr_lengh;

    for (int i = start, end = (!flag) * arr_lengh, swapped = 1;
        (i != end - (2 * flag - 1)) && (swapped); i -= (2 * flag - 1))
    {
        swapped = 0;
        for (int j = start, * curr = & arr[start], * next = & arr[start - (2 * flag - 1)]; j != (arr_lengh - i); j -= (2 * flag - 1), curr = & arr[j], next = & arr[j - (2 * flag - 1)])
        {
            if ( * curr > * next) {
                swapped = 1;
                int temp = * curr;
                * curr = * next;
                * next = temp;
            }
        }
    }

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


    bubble_sort_optimized(bucket, arr_lengh, 1);



    print_arr(bucket, arr_lengh);
}
