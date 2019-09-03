# 求素数（暴力枚举）

## **Problem Description**

*Besides the ordinary Boy Friend and Girl Friend, here we define a more academic kind of friend: Prime Friend. We call a nonnegative integer A is the integer B’s Prime Friend when the sum of A and B is a prime.*

*So an integer has many prime friends, for example, 1 has infinite prime friends: 1, 2, 4, 6, 10 and so on. This problem is very simple, given two integers A and B, find the minimum common prime friend which will make them not only become primes but also prime neighbor. We say C and D is prime neighbor only when both of them are primes and integer(s) between them is/are not.*



## **Input**

*The first line contains a single integer T, indicating the number of test cases.*

*Each test case only contains two integers A and B.*



#### *Technical Specification*



1. 1 <= T <= 1000

2. 1 <= A, B <= 150



## **Output**

*For each test case, output the case number first, then the minimum common prime friend of A and B, if not such number exists, output -1.*



## **Sample Input**

*2*

*2 4*

*3 6*



## **Sample Output**

*Case 1: 1*

*Case 2: -1*



### **题意：**

 	即求一个数，能使a，b与之相加后，成为素数，并且a与b之间没有其他的素数。



### **做法：**

 	该题的关键是将20000000之前的素数打表，然后求其每个之间的差值，相等的存放到同一个数组中。



### **关于枚举：**

 	如果手工都很容易算出来的东西，有理由相信写成程序以后也能很快得到结果。

​	枚举算法在很多时候，无法立刻得出某个问题的可行解或者最优解，但是可以用一种比较“笨”的方法**通过列举所有情况然后逐一判断**来得到结果，这就是枚举算法的核心思想。

​	枚举界法的特点是比较单纯，往往容易写出程序，也**容易证明算法的正确性和分析算法的时间复杂度**，可以解决一些规模很小的问題。

​	它的缺点是**速度慢**，当枚举量很大的时候运行速度无法忍受，所以采用线性素数筛。

​	