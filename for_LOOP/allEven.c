#include <stdio.h>

int main()
{
    for (int i = 1; i <= 20; i++)
    // for (int i = 2; i <= 20; i += 2)   // i+=2 means Jump by 2 (next even)
    {
        if (i%2==0)
        {
           printf("%d\t",i);
        }
    }
    return 0;
}

// #include <stdio.h>
// int main() {
//     printf("Even numbers using BITWISE AND:\n");
//     for(int i=1; i<=20; i++) {
//         if((i & 1) == 0) {      // Check last bit = 0?  as the Even number end with '0' and Odd number end with '1'.
//             printf("%d ", i);
//         }
//     }
//     printf("\n");
//     return 0;
// }
