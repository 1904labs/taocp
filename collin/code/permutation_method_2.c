#include <limits.h>
// for malloc
#include <stdlib.h>

// for printf
#include <stdio.h>

int** permutate(int *nums, int len) {
    int **rv; //2d "array" of floats

    // malloc memory for float*
    // if len=4, equivalent to [[], [], [], [], []]
    rv = (int **) malloc(sizeof(int*) * (len + 1));

    int permute_count, i, j, smallest_ind;
    int numerator = 1;
    for(permute_count=0; permute_count<len+1; permute_count++){
        //malloc memory for all numbers in permutation (len of original + 1)
        rv[permute_count] = malloc(sizeof(int) * len+1);
        float intermed[len+1];

        for(i=0; i<len; i++){
            // assing value of nums[i] to memory pointed to by rv[..][..]
            intermed[i] = nums[i];
        }
        // assign last number the fraction
       intermed[len] = (permute_count * 2.0 + 1) / 2.0;

       // do the substitution
       for(i=0; i<len+1; i++){
           smallest_ind = -1;
           for(j=0; j<len+1; j++){
               if(smallest_ind == -1 || intermed[j] < intermed[smallest_ind]){
                   smallest_ind = j;
               }
           }
           // code breaks if n+1 > 9999999 btw
           intermed[smallest_ind] = 9999999; // effectively remove the num from list
           rv[permute_count][smallest_ind] = i+1;
       }
    }
    return rv;
}

int main(){
    int nums[]= {3,1,2,4};
    int** rv = permutate(nums, 4);
    for(int i=0; i<5; i++){
        printf("{");
        for(int j=0; j<5; j++){
            printf("%d,", rv[i][j]);
        }
        printf("}\n");
    }
    return 0;
}
