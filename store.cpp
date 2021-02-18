#include <stdio.h>
                        
#include <stdlib.h>
#include <string.h>
                        
#define PAGE_SZ (1<<12)
                        
int main() {
     int i;
     int gb = 1; //以GB为单位分配内存大小
                        
     for (i = 0; i < ((unsigned long)gb<<30)/PAGE_SZ ; ++i) {
         void *m = malloc(PAGE_SZ);
         if (!m)
             break;
         memset(m, 0, 1);
     }
     printf("allocated %lu MB\n", ((unsigned long)i*PAGE_SZ)>>20);
     getchar();
     return 0;
 }
