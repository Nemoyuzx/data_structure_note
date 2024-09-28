# 数据结构第一节

## 引入

- 课程信息
  
  - 郭三川
  - guosanchuan@Foxmail.com
  - 4学分 64 学时
  - 作业用c语言完成 pta平台
  - 周四 4-138 实验课

- 学习内容
  
  - 算法分析 时间空间复杂度
  
  - 抽象数据结构 链表 队列 ....
  
  - 字符串
  
  - 树 二叉树 优先队列
  
  - 图论 相关算法

- 相关书籍
  
  - data structures and algorithm analysis in C, second edition, pearson education
  
  - 严蔚敏 《数据结构》(清华大学）

- 什么是数据结构
  
  - 问题-->数学模型-->算法-->程序-->结果
  
  - 科学计算+非科学计算

## terminologies 术语

- 数据 data

- 数据元素 data element

- 数据项 data item 

- 数据对象 data object 

## 结构 structure

### 结构分类 structural classification

- logic structure 逻辑结构
  
  - set 集合
  
  - Linear 线性
  
  - tree 树型结构
  
  - graphic 图

- physical structure 物理结构
  
  - 依据逻辑结构的算法设计

### 顺序存储结构 sequential storage structure

- 例子：数组

### 链式存储结构 linked storage structure

- 使用指针去寻找相关数据元素

## data type 数据类型

### c语言的数据类型

- atomic：integral、float、...

- structural（结构体）：can be divided further 

### abstract data types (ADTs) 抽象数据类型

- A specification of a set of data and the set of operations that can be performed on the data. Such a data type is abstract in the sense that it is independent of various concrete implementations.
  一组数据和可以对数据执行的一组操作的规范。这种数据类型是抽象的，因为它独立于各种具体实现。

```ADTs
ADT ADT name
Data 
    structure on data elements
operation
    operation 1
        initial conditions
        actions
    operation 2
        initial conditions
        action
endADT
```

## algorithm & algorithm analysis 算法与算法分析

- 数据结构+算法 = 程序
- Data Structures:  Methods of organizing large amounts of data for nonnumeric calculation.   
  数据结构：组织大量数据进行非数值计算的方法；
- Algorithm : A finite, clearly specified sequence of instructions to be followed to solve a problem.   
  算法：为解决问题而遵循的有限、明确指定的指令序列。
- Algorithm Analysis: The estimation of the running time/space of algorithms.  
  算法分析：算法运行时间/空间的估计

## algorithm features 算法的特点

- input 输入

- output 输

- definiteness 确定性

- finiteness 有穷性

- effectiveness 有效性

## algorithm requirement 算法需求

- correctness 正确性
  
  - 无语法错误
  
  - 对合法/非法输入的预期输出
  
  - 选择性输入的预期输出（边界条件）

- readability 可读性
  
  - 易读、易理解、可交流

- robustness 鲁棒性；稳健性
  
  - 可以处理非法输入

- High efficiency 高效性
  
  - 运行时间
  
  - 储存管控

# 数据结构第二节

- What to Analyze ? 要分析什么？

- Running Time Analysis  运行时间分析

- General Rules  通用规则

- Recursive Calls  递归调用

- Maximum Subsequence Sum Problem  最大子序列求和问题

- Experimentally checking analysis  实验检查分析

## 要分析什么 What to Analyze

1、机器、编译器 与运行时间相关

2、时间、空间复杂度 与 机器、编译器 独立

（预先假设：1、顺序执行；2、简单指令，执行单位时间；3、整形的大小固定，内存无限大）



用T(N)表示算法执行时间

$T_{avg}(N)$  &  $T_{worst}(N)$  平均和最差时间复杂度 average and worst case time complexities



- EXP
  
  - algorithm 1    $T_{sum}(N) =2n+3$
    
    ```c
    int i, sum = 0, n = 100; // 1 step
    for (i = 1; i <= n; i++)    //  n+1 steps
    {        
        sum =  sum + i;     //  n steps
    } 
    printf (“%d”, sum);      //  1 step 
    ```
  
  - algorithm 2      $T_{sum}(N) =3$
    
    ```c
    int sum = 0, n = 100;    // 1 step
    sum =  (1 + n ) * n/2;    // 1 step
    printf (“%d”, sum) ;     // 1 step 
    ```
    
    

## 运行时间分析 Running Time Analysi

Empirical --> after implementation 实证-->实施后

Theoretical -->before implementation  理论-->实施前

- 使用渐近表示法（ asymptotic notations）—— O, Ω, θ, o
  
  - compare relative growth 比较相对增长
  
  - independent of platform  独立于平台

- Definition (略)
  
  - $T (N) = O( f (N) )$
  
  - $T (N) = \Omega( g(N) ) $
  
  - $T (N) = \theta( h(N) ) $
  
  - $T (N) = o( p(N) ) $

- $T (N) = O( f (N) )$
  
  - EXP：$O(3n^3+4n^2 +5) = O(n^3)$  
  
  - STEP:
    
    - Count the steps  to get T(n)  
    
    - Simplyfy $T(N)$       
      Lower-order terms are ignored        
      Drop the constants 
    
    - Get f(n)       
      $T(n) = O ( f(n) )$  
    
    - Compare between algorithms

- Compare 比较
  $O(1) < O(logn) < O(n) < O(nlogn) < O(n^2) < O(n^3) < O(2^n) < O(n!) < O(n^n) $ 
  
  

## 通用规则 General Rules （时间复杂度）

### Constant order 常数阶

```c
int sum = 0, n = 100;    // 1 step
sum =  (1 + n ) * n/2;    // 1 step (or 4 step ✓) 
printf (“%d”, sum) ;     // 1 step  
```

        $T_N   = O(3) = O(1) $ 

### Linear order 线性阶

```c
int i; for (i = 0; i < n; i++) 
{ 
    /*execution steps of O(1) */ 
} 
```

        $T_N   = O(N)  $

### Log order 对数阶

```c
int count = 1;
 while (count < n) {
    count = count * 2;      
    /*execution steps of O(1) */ 
} 
```

        $2^X=n \ge x=log_2n$

        $T_N = O(logn)$ 

### Square order 平方阶

- 1
  
  ```c
  int i j;
  for (i = 0; i < n; i++){      
      for (j = 0; j < n; j++){           
          /*execution steps of O(1) */       
      } 
  } 
  ```
  
  $T_N   = O(N^2)  $

- 2
  
  ```c
  int i j;
  for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++){
            /*execution steps of O(1) */       
      } 
  }
  ```
  
          $T_N   = O(m \times n)  $

- 3
  
  ```c
  int i j;
  for (i = 0; i < n; i++){
      for (j = i; j < n; j++){
          /*execution steps of O(1) */   
      }
  } 
  ```

                $T  (N) = n + (n-1) + (n-2) +…+1= (n^2+n)/2 = O(n^2)  $

### 并列语句 $T_1 (N) + T_2 (N)$

- 并列语句直接加

- 加完$O(f(n))$ 取最高次项

### 条件判断 If / Else

- 运行时间不得超过测试运行时间加上S1和S2运行时间中的较大值

- $T(n) ≤ T_3(n) + max (T_1(n), T_2(n))$

- ![19d00353-44d4-43b3-99d3-91380809b22a](file:///C:/Users/20999/Pictures/Typedown/19d00353-44d4-43b3-99d3-91380809b22a.png)

## 递归调用 Recursive Calls

- 设这一次和下一次的用时为 $T(n)$ 和 $T(n-1)$

- ```c
  int factorial (int n) {
  if (n<=1)         //1 for if
      return 1;
  else              //1 for else
      return n*factorial(n-1); //1 for multiplication + 1 for substraction + cost of evaluation of factorial(n-1)  
  } 
  ```

- $T(n)= 4 + T(n-1)$ 且 $T(1)= 2$ 

- 逐步归纳得出结果

- 双调用递归形式
  
  - ```c
    Fib (int N) {
      if (N<=1)         
        return 1;     
    else         
        return Fib(N-1)+Fib(N-2); 
    } 
    ```
  - $T(N) = T(N-1) + T(N-2) + 2 \ge  Fib(N) $ 
  - $(\frac{3}{2})^N \le Fib(N) \le (\frac{5}{3})^N$ 

## 最大子序列求和问题 Maximum Subsequence Sum Problem

- Given (possibly negative) integers $A1, A2, …, A_N$ find the maximum value of $ {\textstyle \sum_{k=i}^{j}} A_K$ 

### 算法1

```c
int  MaxSubsequenceSum ( const int A[],  int  N ) { 
    int  ThisSum,  MaxSum,  i,  j,  k; 
    MaxSum = 0;   /* initialize the maximum sum */
       for( i = 0; i < N; i++ ){ /* start from A[ i ] */
           for( j = i; j < N; j++ ) {   /* end at A[ j ] */
               ThisSum = 0; 
               for( k = i; k <= j; k++){
                   ThisSum += A[k];  /* sum from A[ i ] to A[ j ] */
                   if ( ThisSum > MaxSum)  MaxSum = ThisSum;  /* update max sum */
               }
           }  /* end for-j and for-i */
       }
     return  MaxSum; 
} 
```

- $T( N) = O( N^3 )$ 

### 算法2

```c
int  MaxSubsequenceSum ( const int A[],  int  N ) { 
    int  ThisSum,  MaxSum,  i,  j; 
    MaxSum = 0;   /* initialize the maximum sum */
    for( i = 0; i < N; i++ )  {   /* start from A[ i ] */
           ThisSum = 0; 
           for( j = i; j < N; j++ ) {   /* end at A[ j ] */
                ThisSum += A[ j ];  /* sum from A[ i ] to A[ j ] */
                 if ( ThisSum > MaxSum ) MaxSum = ThisSum;  /* update max sum */
          }  /* end for-j */
      }  /* end for-i */
      return  MaxSum; 
} 
```

- $T( N ) = O( N^2 )$ 

### 算法3 ——「分治算法」（Divide and Conquer）

在C语言中，可以使用「分治算法」（Divide and Conquer）来解决最大子序列和问题。这个问题的目标是找到一个数组中具有最大和的连续子序列。分治法的思路是将问题分成左右两部分，递归解决子问题，并结合左右部分的结果来找到最终解。

#### 算法的关键思想：

1. 将数组分成左右两部分，分别求解左边的最大子序列和右边的最大子序列。
2. 同时要考虑跨越左右部分的子序列，它可能是最大子序列。
3. 返回以上三者中最大的值。

#### 算法的步骤：

- 将数组从中间分成两半。
- 分别递归地找到左半部分和右半部分的最大子序列和。
- 计算跨越中间的子序列的最大值。
- 返回三者中的最大值。

#### C语言实现：

```c
#include <stdio.h>
#include <limits.h>

// 辅助函数，计算跨越中间的子数组的最大和
int maxCrossingSum(int arr[], int left, int mid, int right) {
    int sum = 0;
    int left_sum = INT_MIN;

    // 从中间向左扫描，找出最大左边子序列和
    for (int i = mid; i >= left; i--) {
        sum += arr[i];
        if (sum > left_sum) {
            left_sum = sum;
        }
    }

    // 从中间向右扫描，找出最大右边子序列和
    sum = 0;
    int right_sum = INT_MIN;
    for (int i = mid + 1; i <= right; i++) {
        sum += arr[i];
        if (sum > right_sum) {
            right_sum = sum;
        }
    }

    // 返回跨越左右的最大子序列和
    return left_sum + right_sum;
}

// 分治法求最大子序列和
int maxSubArraySum(int arr[], int left, int right) {
    // 基本情况：如果数组只有一个元素
    if (left == right) {
        return arr[left];
    }

    // 找到中间点
    int mid = (left + right) / 2;

    // 递归求解左边、右边和跨越中间的最大子序列和
    int left_sum = maxSubArraySum(arr, left, mid);
    int right_sum = maxSubArraySum(arr, mid + 1, right);
    int cross_sum = maxCrossingSum(arr, left, mid, right);

    // 返回三者中的最大值
    if (left_sum >= right_sum && left_sum >= cross_sum) {
        return left_sum;
    } else if (right_sum >= left_sum && right_sum >= cross_sum) {
        return right_sum;
    } else {
        return cross_sum;
    }
}

int main() {
    int arr[] = {2, 3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int max_sum = maxSubArraySum(arr, 0, n - 1);

    printf("最大子序列和是: %d\n", max_sum);

    return 0;
}
```

#### 解释：

1. **`maxCrossingSum` 函数**：用于计算跨越数组中间的子数组的最大和。它从中间向左右两边扩展，分别计算左右两部分的最大子序列和，然后将两者相加得到跨越的最大子序列和。
2. **`maxSubArraySum` 函数**：递归地求解左半部分、右半部分和跨越中间的最大子序列和，返回这三者的最大值。
3. **`main` 函数**：定义数组并调用 `maxSubArraySum` 来求解整个数组的最大子序列和。

    该代码成功求解了最大子序列和问题，时间复杂度为 O(n log n)。



### 算法4 —— **On-line Algorithm** 在线算法

**On-line Algorithm**，即在线算法，指的是一种能够逐步处理输入数据并且在每一步做出决策的算法。相比于一次性获取所有数据后再做决策的离线算法，在线算法更适合处理流式数据或未知长度的数据流。在线算法在遇到数据的每一步时，需要立即做出最优的决策，通常不能回溯到之前的数据进行修改。

对于最大子序列和问题，使用**在线算法**可以通过**Kadane's Algorithm**（卡丹算法）来实现。这个算法的核心思想是在遍历数组的过程中逐步更新最大子序列和，时间复杂度为 O(n)，是一种经典的在线算法。

#### 思路：

1. 从数组的第一个元素开始，逐步遍历每一个元素。
2. 对于每个元素，更新当前的子序列和（`current_sum`），如果当前和小于 0，则丢弃当前和，重新开始计算（从下一个元素开始一个新的子序列）。
3. 在每一步都更新最大子序列和（`max_sum`）。

#### 关键点：

- **current_sum**：当前子序列的和。表示到目前为止的子序列和，如果 `current_sum` 小于 0，那么丢弃它并从当前元素重新开始。
- **max_sum**：记录迄今为止遇到的最大子序列和。

#### C 语言实现：

```c
#include <stdio.h>
#include <limits.h>

int maxSubArraySum(int arr[], int n) {
    int max_sum = INT_MIN;  // 存储最大子序列和
    int current_sum = 0;    // 当前子序列和

    for (int i = 0; i < n; i++) {
        current_sum += arr[i];   // 加上当前元素

        if (current_sum > max_sum) {
            max_sum = current_sum;  // 更新最大子序列和
        }

        if (current_sum < 0) {
            current_sum = 0;  // 如果当前和为负数，抛弃当前和，重新开始
        }
    }

    return max_sum;
}

int main() {
    int arr[] = {2, 3, -6, 1, 2, 3, -4, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int max_sum = maxSubArraySum(arr, n);

    printf("最大子序列和是: %d\n", max_sum);

    return 0;
}
```

#### 解释：

1. **`maxSubArraySum` 函数**：
   
   - 遍历数组中的每一个元素。
   - 使用 `current_sum` 累加当前的子序列和，并在每一步检查是否需要更新 `max_sum`。
   - 如果 `current_sum` 变成负数，说明当前子序列不再有贡献，因此将 `current_sum` 重置为 0，从下一个元素重新开始计算。

2. **`main` 函数**：定义了一个数组并调用 `maxSubArraySum` 来求解数组的最大子序列和。

#### why？丢弃

在 Kadane's Algorithm 中，当当前子序列和（`current_sum`）小于 0 时，我们选择丢弃当前和，重新从下一个元素开始计算，这是因为：

##### 1. **负数只会拖累后续的计算**

   如果当前的子序列和为负数，并且我们继续把它加到后续的元素上，这会导致后续的子序列和变得更小，无法获得更大的子序列和。换句话说，一个负的子序列和对后续的子序列没有任何帮助，反而会降低它们的值。

##### 2. **负数的累积没有正贡献**

   假设当前子序列的和小于 0，那么不论接下来遇到什么样的元素（无论是正数还是负数），加上一个负的 `current_sum` 都只会使得新子序列的和变小。此时不如丢弃负数的和，从下一个元素重新开始累加，从而增加子序列和的可能性。

##### 3. **重新开始的子序列更有可能获得最大和**

   当 `current_sum` 小于 0 时，直接从下一个元素开始重新累加相当于开始了一个新的子序列。这意味着我们认为前面的子序列（因为是负数）对后续没有帮助，而希望从新的元素开始，看看能否找到更大的子序列和。

##### 4. **保证全局最优解**

   Kadane’s Algorithm 的设计思路是通过每一步局部的最优选择来保证全局的最优解。当子序列和小于 0 时，丢弃它相当于做出了局部最优的选择：不让负数影响到后面的子序列，从而提升整体的最大和。

#### 总结

当当前子序列和小于 0 时，丢弃它是因为负数只会降低后续子序列的值，无法产生任何正面的贡献。通过从下一个元素重新开始计算，我们可以避免负数的累积带来的负面影响，从而增加找到最大子序列和的机会。这种做法保证了 Kadane's Algorithm 能够在每一步做出局部最优选择，最终得到全局最优解。

##### 在线算法的优点：

- **空间复杂度为 O(1)**：Kadane’s Algorithm 只需要常数空间，因为它只维护了 `current_sum` 和 `max_sum` 两个变量。
- **时间复杂度为 O(n)**：Kadane’s Algorithm 只需要一次遍历数组，因此时间复杂度是线性的，非常高效。
- **适合动态输入**：如果数据是动态到达的（即流式数据），Kadane’s Algorithm 能够在每一步实时更新结果，因此它是一个在线算法的经典例子。

##### 在线算法的使用场景：

- **流式数据处理**：Kadane's Algorithm 适合处理动态输入数据，能够在数据不断变化或增加时持续计算最大子序列和。
- **实时计算问题**：当你不能提前知道所有输入数据时，在线算法能随着数据的到来不断更新最优解。

## 实验检查分析 Experimentally checking analysis

### method 1

Implement your algorithm, measure therunning time of your implementation

实现你的算法，测量实现的运行时间
     When N doubles (2x), check T(2N)/T(N) 
     linear       => T(2N)/T(N)  2 
     quadratic    => T(2N)/T(N)  4 
     cubic        => T(2N)/T(N)  8

### method 2

$T_t (N)$  = theoretical running time

$T_e (N)$= experimental running time 

- $T_t(N) = O(f(N))$  $\frac{T_e(N)}{T_f(N)}\Rightarrow \frac{T_E(N)}{f(N)}$ 

- compute
  
  - if converges to a constant  $\Rightarrow $ f(N) is a tight bound 
  
  - if converges to zero  $\Rightarrow $   not tight bound (overestimate) 
  
  - if diverges   $\Rightarrow $   underestimate 

# 数据结构第四节——CH3 Linear Lists

- List ADT

- Linear List 线性表
  
  - Array list 数组
  
  - Linked list 链表
  
  - Cursor List 基于数组管理内存的链表
  
  - Doubly Linked List 双向链表

## Linear List 线性表

A linear List is a list in which each element has a unique successor. 

线性列表是一个列表，其中每个元素都有一个唯一的后继元素。

- $A_i$+1 follows (succeeds) $A_i$, $A_i$ precedes Ai.

- Position of element $A_i$ = I 

- List of size 0 is empty list 

### List ADT Operations 抽象数据类型操作表

- List MakeEmpty( List L )    清空列表

- int  IsEmpty( List L)  判断线性表是否为空

- int  IsLast( Position P, List L)  判断P位置是否为线性表最后一位

- void Insert ( ElementType X, List L, Position P )    在位置P后插入
  
  - Insert(X, L, 3)  ->    (34,12,52,X,16,12) 

- void Delete ( ElementType X, List L )         
  
  - Delete(52, L)    ->    (34,12,X,16,12)      //e.g. list 

- Position Find ( ElementType X, List L )     
  
  - Find(16)     ->　4 

- ElementType Retrieve( Position P )  
  
  - Retrieve(3)    ->    X 

- Position FindPrevious( ElementType X, List L )    
  
  - FindPrevious (12, L )  -> 4  

### Types of Lists 线性表的类型

#### General:  data can be inserted and deleted anywhere in the list  常规：可以在列表中的任何位置插入和删除数据

- Array List 数组

- Linked List  链表

- Cursor List  游标线性表

- Doubly Linked List  双向链表

- Circularly Linked List  环链表

#### Restricted:  data can be inserted or deleted at the ends of the list  限制：可以在列表末尾插入或删除数据

- Last-In-First-Out (Stack)  后进先出（栈）

- First-In-First-Out (Queue)  先进先出（队列）

### Array List 顺序表（数组）

- Elements are stored contiguously in memory as an array (easy to find kth element) 元素作为数组连续存储在内存中（容易找到第k个元素）

- Simple array implementation 简单的阵列实现
  
  - Must know estimate of size before hand (waste of space) 必须事先知道尺寸估计（浪费空间）
  
  - Insert and Delete: expensive  插入和删除：昂贵

| 0            |               |
| ------------:|:-------------:|
| 1            | element[1]    |
| 2            | element[2]    |
| 3            | Element[3]    |
|              | ……            |
| 1 ≤ i ≤ last | element[i]    |
|              | ……            |
|              | ……            |
| last         | element[last] |
|              | ……            |
| maxlength-1  |               |

```c
//Type Definition： 类型定义
# define maxlength 100 
struct LIST {      
    elementtype * elements;
    int last; 
}; 
//Position Type：重定义
    typedef int position; 
//Linear List L: 声明结构
    struct LIST L; 
//Initialization: 初始化
    L.elements= (elemttype *)  malloc  (maxlength* sizeof (elemttype))  
//Representation：调用
    L.elements[p] // pth element       
    L.last // length of L, position of last element 
```

#### 插入（前插） Array list-INSERT Operation

```c++
 void Insert (int newItem, List &L, int location) {       
     int i;       
     if (L.last + 1 == maxlength) {//array is full 数组已满          
         int *b = new int[2 * maxlength]; // Allocate a new array, twice as long. 分配一个新数组，长度是原来的两倍。
         for (i = 0; i <= L.last; i++) {// Copy items to the bigger array.将项目复制到更大的数组。
             b[i] = L.elements[i];           
         }       
         L.elements = b; // Replace the too-small array with the new one.用新的阵列替换太小的阵列。
     }       
     for (i = L.last; i >= location; i--) { // Shift items to the right.将项目向右移动。
         L.elements[i + 1] = L.elements[i];       
     }      
     L.elements[location] = newItem;      
     L.last++; 
 }//Time Complexity 时间复杂度：O(n) 
```

#### 删除 Array list-DELETE Operation

```c
 void Delete( Element X, LIST &L) {   
     position i, q ;     
     for (  i= 0 ; i <= L.last ; i ++ ){          
         if ( L.elements[ i ] == X ){    
             q = i;//find the position of X          
             break;          
         }     
     }     
     if ( i == L.last+1)// X found or not?
        error (not found X)；     
     else{             
         L.last = L.last – 1;          
         for ( i = q ; i < L.last ; i ++ ){        
             L.elements[ i ] = L.elements[ i + 1 ]; //move all elements       
         } 
     }//Time Complexity：O(n) 
```

#### 查找 Array list-Find and Retrieve Operations

- 查找数据元素
  
  ```c
  position Find ( elementtype x ,LIST L ) {   
    position q ;     
    for ( q = 1; q <= L.last ; q++ )     
        if ( L.elements[ q ] == x )         
            return ( q ) ;         
    return ( L.last + 1 ); 
  }  //Time Complexity O(n) 
  ```

- 查找某一位置上的数据
  
  ```c
  elementtype Retrieve ( position p ,LIST L ) {  
      if ( p > L.last )         
          error( illegal position) ;     
      else
          return ( L.elements[ p ] ) ; 
  }   //Time Complexity O(1) 
  ```

### Linked List 链表

- 定义
  
  ```c
  //Type definition： 
  struct celltype { 
      elementtype element ; 
      struct celltype *next ; 
  } ; /*Node Type*/ 
  /*List Type */ 
  typedef struct celltype *LIST; 
  /*Position Type*/ 
  typedef struct celltype *position; 
  ```

- special ATTENTION！！！
  
  ```c
  struct celltype *LIST;//指针
  struct celltype &LIST;//地址
  struct celltype LIST;//对象
  ```

#### 查找和检索 Linked list-Find and Retrieve Operations

```c
position Find ( elementtype x, LIST L ) {  
    position p ;     
    p = L->next ; //pass the pointer to first item 将指针传递到第一个项目
    while ( p != NULL && p ->element != X  ){
        p = p→next ;     
        return p ;
    } 
} //Time Complexity：O(n) 
```

```c
elementtype Retrieve ( position p , LIST L ) {     
    return ( p →element ); 
} //Time Complexity：O(1) 
```

#### 插入 Linked list-INSERT Operations

![33f02d7c-a5fd-4465-93ab-dfb7e63ada26](file:///C:/Users/20999/Pictures/Typedown/33f02d7c-a5fd-4465-93ab-dfb7e63ada26.png)

```c
void Insert ( elementtype x, position p, LIST &L ) {
    position q ;     
    q = new celltype ;     
    q →element = x ;     
    q →next = p →next ;     
    p →next = q ; 
} //Time Complexity O(1) 
```

#### 删除 Linked list-DELETE Operation

![d62e7107-a598-4fa1-bc1a-d34efe7700ff](file:///C:/Users/20999/Pictures/Typedown/d62e7107-a598-4fa1-bc1a-d34efe7700ff.png)

```c
void Delete (Element X, LIST &L ) {  
    position P, TmpCell ;    
    p = FindPrevious( X, L ) ;      
    if ( !IsLast( P, L ) ) {//not the last element            
        TmpCell = P->Next;         
        P->Next = TmpCell->Next;         
        free ( TmpCell );      
    }  
} //Time Complexity：O(1)  
```

### 顺序表和链表对比 Array List vs. Linked List

|                                 | Array List                                                           | Linked List                                        |
|:-------------------------------:| -------------------------------------------------------------------- | -------------------------------------------------- |
| Findkth operation 查找操作          | Random Time efficient O(1)                                           | Sequential Time inefficient  O(n)                  |
| Insert/Delete Operation 插入/删除操作 | Time inefficient O(n)                                                | Time efficient O(1)                                |
| Space 空间                        | Estimated size, Fixed, waste space, hard to expand 估计大小，固定，浪费空间，难以扩展 | Actual size, Flexible, easy to expand 实际尺寸，灵活，易于扩展 |

### Cursor List 静态链表（游标链表）——基于数组管理内存的链表

- 每一位置一数据一下标（输入下标静态表开始检索，检索到下标到-1静态表终止）

- 手动模拟malloc和free函数的操作，操作“available”表确定空地址

#### Representation & Definition

![cb348438-c058-4b34-8965-0ae2a363dd7a](file:///C:/Users/20999/Pictures/Typedown/cb348438-c058-4b34-8965-0ae2a363dd7a.png)

```c
//Type Definition： 
typedef struct {     //数组的每一项用结构体实现
    elementtype element ;     //要存储的数据类型
    int next ;         //表内下一个元素的下标
} spacestr; /*Node Type*/  
spacestr SPACE[ maxsize ] ;/*Memory pool*/  //结构体数组
typedef int position，cursor; 
cursor av; /*cursor variable, label a liner list*/  
SPACE[i].next /*position of next element */ 
```

#### GetNode and FreeNode 获取和释放节点

```c
//get an unallocated node 获取节点
cursor GetNode(){      //malloc
    cursor p;    
    if (SPACE[available].next ==-1)        
        p=-1;    
    else{   
        p= SPACE[available].next ;        
        SPACE[available].next = SPACE[ p ].next ;    
    }     
return p; 
} 
```

```c
//free node  释放节点
void FreeNode(cursor q){  //delete q;      //free
    SPACE [ q ].next = SPACE[available].next ;     
    SPACE[available].next = q ; 
} /* free node to the pool*/ 
```

### Doubly-linked list 双向链表

#### 初始化

```c
struct dcelltype { 
    elementtype element ; 
    struct dcelltype *next, *previous ; 
} ; /* list and  position type*/ 
typedef struct dcelltype *DLIST ; 
typedef struct dcelltype *position ; 
```

#### Doubly-linked listINSERT and DELETE 双向链表的插入和删除

```c
//insert at position p 
void INSERT( elementtype x, position p,DLIST &L ) {     
    position q ;     
    q = new dcelltype ;     
    q→element = x ;     
    p→previous→next = q ;     
    q→previous = p→previous ;     
    q→next = p ;     
    p→previous = q ; 
} 
```

```c
//delete node at position p 
void DELETE(  position p, DLIST  &L ) {       
    if (p->previous!=NULL)             
        p→previous→next = p→next;       
    if (p→next!=NULL)             
        p→next →previous = p→previous ;       
    delete p; 
} 
```

### Circularly Linked List 循环链表

![fb0f7c7b-263f-41e8-9aa0-ada599262061](file:///C:/Users/20999/Pictures/Typedown/fb0f7c7b-263f-41e8-9aa0-ada599262061.png)

### Circularly Doubly Linked List 双向循环链表

![85f2756b-a49d-4800-bd98-dd6e9856554b](file:///C:/Users/20999/Pictures/Typedown/85f2756b-a49d-4800-bd98-dd6e9856554b.png)

# 数据结构第五节——CH4 Stacks and Queues 栈和队列

- Stack 
  
  - Stack Model 
  
  - Implementation of Stacks 
  
  - Applications 

- Queue 
  
  - Queue Model 
  
  - Implementation of Queues
  
  - Applications    

## Stack 栈

- Definition：A stack is a Last-In-First-Out (LIFO) list, that is, an ordered list in which insertions and deletions are made at the top only. 堆栈是后进先出（LIFO）列表，即一个有序列表，其中仅在顶部进行插入和删除。

- 输入输出
  
  - Input   push() 
  
  - Output   pop() 

![4f77c72d-4b39-4db6-9fe5-5c3e26af5534](file:///C:/Users/20999/Pictures/Typedown/4f77c72d-4b39-4db6-9fe5-5c3e26af5534.png)

### Operations 操作

1. Int  IsEmpty( Stack S );  

2. Stack CreateStack( );   

3. MakeEmpty( Stack S );   

4. Push( ElementType X, Stack S );    //压栈Push

5. ElementType  Top( Stack S );   

6. Pop( Stack S );  //弹栈Pop
- 栈的常见错误 Note:  
  
  - Underflow:A Pop (or Top) on an empty stack is an error in the stack ADT.
    空堆栈上的Pop（或Top）是堆栈ADT中的错误。
  
  - Overflow: Push on a full stack is an implementation error. 
    推送完整堆栈是一个实现错误。

### Linked List Implementation 用链表实现

链表头

```c
struct node; 
typedef struct node * PtrToNode; 
typedef PtrToNode Stack;  
struct node {     
    ElementType element;     
    PtrToNode next; 
}; 
```

![73aefd98-8693-41be-b8aa-8468ed86cf09](file:///C:/Users/20999/Pictures/Typedown/73aefd98-8693-41be-b8aa-8468ed86cf09.png)

![a934d245-ab4d-4a78-bbf1-483c24fd5680](file:///C:/Users/20999/Pictures/Typedown/a934d245-ab4d-4a78-bbf1-483c24fd5680.png)

#### CreateStack 创建栈

```c
Stack createStack() {   
    Stack s;      
    s = malloc (sizeof (struct Node ));     
    if (s==NULL) {         
        printf(“Out of space!!”);     
    }     
    s->next = NULL;     
    return s; 
} 
```

#### isEmpty 判断为空

```c
int isEmpty(Stack s) {     
    return s->next == NULL; 
} 
```

#### MakeEmpty 置空

```c
void makeEmpty(Stack s) {     
    if (s == NULL) {         
        printf(“Must use CreateStack first”);     
    } else {         
        while (!isEmpty(s)) {             
            pop(s);         
        }     
    } 
} 
```

#### Pop 弹栈/出栈

```c
void pop (Stack s) {     
    PtrToNode first;      
    if (isEmpty(s)) {         
        printf(“empty stack”);     
    } else {         
        first = s->next;         
        s->next = s->next->next;         
        free(first);     
    } 
} 
```

#### Push 压栈

```c
void push (ElementType x, Stack s) {     
    PtrToNode = temp;      
    = malloc(sizeof(structNode));     
    if (temp == NULL) {         
    printf(“out of space!!”);     
    } else {         
        temp->element = x;         
        temp ->next = s->next;         
        s->next = temp     
    } 
} 
```

#### Top 头元素

```c
ElementType top(Stack s) {
    if (!isEmpty(s)) {
        return s->next->element;
    }
    printf(“Empty stack”);
    return 0;
}
```

### Array implementation 数组实现

```c
struct  StackRecord {     
    int Capacity ;              /* size of stack */     
    int TopOfStack;          /* the top pointer */     
    /* ++ for push, -- for pop, -1 for empty stack */                         
    ElementType *Array;    /* array for stack elements */  
} ;  
```

- Popular implementation (v.s. Linked list implem.), why? 优势
  
  - Takes  fast constant time (specific instruction) 
  
  - Actual stacks usually not large (no waste of space) 

- Note  注意
  
  - Error checking before push or pop  

### EXP 运用实例

#### Balancing Symbols 平衡符号检查

- Balancing symbols: Check if parenthesis ( ), brackets [ ], are balanced.
  平衡符号：检查括号（）、括号[]是否平衡。

##### 流程

- Keep a stack 

- Read the charecters one by one  逐一阅读字符

- If the charecter is ‘(‘  or ‘[‘ push into stack 如果字符是“（”或“[”，则推入堆栈

- If the charecter is ‘)’ or ‘]’ pop the stack  如果字符是“）”或“]”，则弹出堆栈
  
  - if the stack is empty ERROR     
  
  - if the symbol popped does not match with character ERROR 

- Continue until the end of file 继续，直到文件结束

- At the end of file     
  
  - if  the stack is not empty ERROR        
  
  - else SUCCESS 

##### code 代码

```c
Algorithm  {
    Make an empty stack S;
    while (read in a character c) {
        if (c is an opening symbol)
            Push(c, S);
        else if (c is a closing symbol) {
            if (S is empty)  { ERROR; exit; }
            else  {  /* stack is okay */
                if  (Top(S) doesn’t match c)  { ERROR, exit; }
                else  Pop(S);
            }  /* end else-stack is okay */
        }  /* end else-if-closing symbol */
    } /* end while-loop */ 
    if (S is not empty)  ERROR;
}
```

#### Postfix Evaluation 后缀表达式的评估（机器计算）

1. 数学上常用的表达式叫做中缀表达式，需要用括号来表示运算顺序，但是计算机做中缀表达式的求值比较难，一是需要知道运算符优先级，二是需要处理括号  

2. 为了方便计算机进行求值，我们引入了前缀表达式和后缀表达式。

3. 后缀表达式更加简单，他有一个特性，就是我们从左到右扫描表达式，如果遇到操作符，那么他的两个操作数一定已经ready了，可以进行这个操作符所对应的运算。由于这样的性质，我们可以使用堆栈来解决后缀表达式求值问题 
- 〖Example〗
  
  - An infix expression 中缀表达式:     a + b * c - d / e                       
  - A prefix expression 前缀表达式:     - + a * b c / d e                      
  - A postfix expression 后缀表达式（逆波兰表示）:   a b c * + d e / - 

![c296e9a6-398a-4a58-a038-5ecfa2da1dff](file:///C:/Users/20999/Pictures/Typedown/c296e9a6-398a-4a58-a038-5ecfa2da1dff.png)

#### Infix to Postfix Conversion 从前缀到后缀的转换

- 栈里只放运算符，在下一个运算符的优先级判断后，优先级比读取的低或等时，出栈（一直出栈）并输出（括号不输出），优先级比读取的高时，压栈

- 左括号栈外优先级最高，栈内优先级最低

##### 〖Example1〗  a + b * c - d  =  ?

1. Read one by one.

2. If it is not symbol,  output as part of the postfix expression.

3. else compare with the symbol at top of the stack.
   
   - If its precedence is lower than or equal to the top symbol or it is“)”,pop the symbol from top, output it, until a entry of lower priority,and push the current symbol.
     如果其优先级低于或等于顶部符号或为“）”，则从顶部弹出符号，输出它，直到优先级较低的条目，然后推送当前符号。
   
   - else push the current symbol into stack.
     否则，将当前符号推入堆栈。

##### Tips 括号的处理:

- Never pop a ( from the stack except when processing a ) .
  永远不要弹出a（从堆栈中弹出，除非处理a）。

- Observe that when (  is not in the stack, its precedence is the highest; but when it is in the stack, its precedence is the lowest.  Define in-stack precedence and incoming precedence for symbols, and each time use the corresponding precedence for comparison.
  请注意，当（不在堆栈中时，其优先级最高；但当它在堆栈中，其优先级最低。定义符号的堆栈内优先级和传入优先级，每次使用相应的优先级进行比较。
  (in other words, “(” must be pushed, and when meet “)”, symbols in stack above “(” are poped) 
  （换言之，“（必须被推，当遇到时）”，上面堆栈中的符号“（”被弹出）

##### Note 嵌套次方的处理：

- a – b – c will be converted to a b – c –.  However, 2^2^3 must be converted to 2 2 3 ^ ^, not 2 2 ^ 3 ^ since exponentiation associates right to left （and thus suppose the right ^ has higher priority than the left ^）.
  a–b–c将转换为a b–c。但是，2^2^3必须转换为2 2 3^^，而不是2 2^3^，因为求幂运算是从右向左关联的（因此假设右^的优先级高于左^）。

#### Functions calls 系统调用

![4e2d183e-a291-4c2f-8c17-b4bb5eb20101](file:///C:/Users/20999/Pictures/Typedown/4e2d183e-a291-4c2f-8c17-b4bb5eb20101.png)

- When a function is called 
  
  - Local variables and status should be saved  

- When the function returns 
  
  - Saved values needs to be restored 
