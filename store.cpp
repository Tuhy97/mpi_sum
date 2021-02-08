/*这是一个消耗内存的测试c程序*/

/* 用法：

*  ./test-mem arg1 arg2 arg3

* arg1表示每秒分配的内存数量（单位M）

* arg2表示总共分配多少内存

* arg3表示程序存活多久（默认300秒）

*/


# include <stdio.h>

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define KB (1024)
# define MB (1024 * KB)
# define GB (1024 * MB)

int main(int argc, char *argv[])
{
        char *p;
        int size = 0, i = 0, j = 0;
        size = atoi(argv[1]);
        int end_time=300;
        int total_size = -1;
        if (argc > 2) {
                total_size = atoi(argv[2]);
                if (size > total_size)
                        total_size = size;
        }

        if (argc > 3) {
                end_time = atoi(argv[3]);
        }
        //again:
#if 0
        while ((p = (char *)malloc(GB)))
                memset(p, 0, GB);
#endif
        while (1) {
                i = size;
                if(total_size != j) {
                        while (i--) {
                                p = (char *)malloc(MB);
                                memset(p, 0, MB);
                                j++;
                                printf("malloc: %dMB\r", j);
                                fflush(stdout); 
                        }
                }
                sleep(1);               

end_time--;
                if(end_time == 0) {
                        break;
                }

          }

#if 0
        while ((p = (char *)malloc(KB)))
                memset(p, 0, KB);
#endif
        //sleep(1);
        ///     goto again;
        return 0;
}
