# CH9 Search 查找

-   Search Table 
    -   Sequential Search
    -   Binary Search
    -   Indexing Search
-   Binary Search Trees
    -   Binary search tree
    -   AVL tree
    -   B- Tree
-   Hash Table
    -   What is hashing
    -   Hash Function
    -   Collision Resolution
        -   Open Addressing
        -   Rehashing
        -   Separate Chaining
    -   Analysis of Hashing

## Search Table 查找表

-   Search Table: A set of the same type of data elements.   
    搜索表: 一组相同类型的数据元素。

    -   Key: The value of data item in the data element. It is used to identify the data elements.  
        Key: data 元素中数据项的值。用于标识数据元素。
    -   Primary Key and Second Key.  
        主键和第二键。
-   Attributes:  
    属性:

    -   There is no fixed relationship between the elements.  
        元素之间没有固定的关系。
    -   Any relationship can be defined on the set for operation convenience.  
        为了操作方便，可以在集合上定义任何关系。

-   Operations on search table  
    搜索表上的操作

    -   Search a given element in the search table;  
        在搜索表中搜索给定的元素;
    -   Get attributes of a given element;  
        获取给定元素的属性;
    -   Insert an element into the search table;  
        在搜索表中插入一个元素;
    -   Delete an element from the search table.  
        从搜索表中删除一个元素。

    >   Static search table: Only do search on the search table  
    >   静态搜索表: 只在搜索表上进行搜索
    >
    >   Dynamic search table: Need do search, insertion and deletion on the search table  
    >   动态搜索表: 需要在搜索表上进行搜索、插入和删除

### Sequential Search  顺序搜索

- General Idea: Begin at one end of the list and scan down it until the desired key is found or the end is reached.   
    总体思路: 从列表的一端开始，向下扫描，直到找到所需的键或到达末尾。
- A successful search return the position of the record; A unsuccessful search return 0.  
    成功的搜索返回记录的位置; 不成功的搜索返回0。

顺序查找又称线性查找，适用于顺序表和链表。对于顺序表，可通过数组下标递增顺序扫描每个元素；对于链表，可通过指针next来依次扫描每个元素。从线性表的一端开始，依次将记录的关键字与给定值进行比较，也就是逐个检查关键字是否满足给定的条件。若查找到某个记录的关键字和给定值相等，则查找成功；反之，查找失败。

```c
#include <stdio.h>
#include <stdlib.h>
 
typedef char InfoType;
typedef int KeyType;
 
// 定义结构体ElemType，包含关键字域和其他域
typedef struct {
    KeyType key;        // 关键字域
    InfoType otherinfo;  // 其他域
} ElemType;
 
// 定义结构体SSTable，表示顺序表
typedef struct {
    ElemType* R;        // 存储空间基地址
    int length;         // 当前长度
} SSTable;
 
// 函数Search_Seq在顺序表ST中顺序查找关键字等于key的数据元素
int Search_Seq(SSTable ST, KeyType key) {
    int i = 0;
    ST.R[0].key = key;
    for (i = ST.length; ST.R[i].key != key; --i); // 从后往前查找
    return i;
}
 
int main() {
    // 假设KeyType是int，InfoType是char
    typedef int KeyType;
    typedef char InfoType;
 
    // 创建一个顺序表
    SSTable ST;
    ST.R = (ElemType*)malloc(10 * sizeof(ElemType)); // 假设分配10个元素的空间
    ST.length = 0;
 
    // 向顺序表中添加元素
    ST.R[1].key = 1;
    ST.R[1].otherinfo = 'A';
    ST.R[2].key = 2;
    ST.R[2].otherinfo = 'B';
    ST.length = 3;
 
    // 调用Search_Seq函数查找关键字为2的元素
    int position = Search_Seq(ST,2);
    if (position != 0) {
        printf("Element found at position %d\n", position);
        printf("%d", ST.R[position].otherinfo);
        putchar(ST.R[position].otherinfo);//将ASCII码转换为字符
    }
    else {
        printf("Element not found\n");
    }
 
    // 释放顺序表空间
    free(ST.R);
 
    return 0;
}
```

