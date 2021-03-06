/*
malloc 是 memory(内存) allocate(分配)的缩写
*/

# include <stdio.h>
# include <malloc.h>//不能省（该函数只有一个整数类型的形参）
int main(void)
{
    int i = 5;//分配了四个字节 静态分配
    int * p = (int *)malloc(4);//该语句一共分配了4字节的内存加一个地址（p（p指向了分配的第一个字节的地址）
                                //因此总共分配的字节数为4+4==8
        /*
            1. 要使用malloc函数，必须添加malloc.h这个函数
            2. 该函数只有一个整数类型的形参
            3. 4表示请求系统为本程序分配四个字节
            4. malloc函数只能返回第一个字节的地址（但是由于不知道该地址所占的字节数，
            即不知道该地址是什么类型的地址，因此需要在函数返回值前面进行强制类型转换）
            5. 分配数组元素的个数==函数实参/强制类型转换的该类型字节数
            6. p本身所占的内存是静态分配的，p所指向的内存是动态分配的
        */
    *p = 5; //*p代表的就是一个int变量，只不过*p这个整形变量的内存分配方式和11行的i变量的分配方式不同
    free(p);//free(p)表示把p指向的内存释放掉 但是由于p本身的内存是静态的，不能由程序释放
            //故p的内存只能等程序运行结束后自动释放

    return 0;
}
