#include "Solution.h"

int Solution::Fibonacci(int n) {//JZ10 斐波那契数列-递归
	//Fibonacci(x) = Fibonacci(x-1) + Fibonacci(x-2) {x= 1 || 2 ,Fibonacci = 1}
	if (n == 1 || n == 2) {
		return 1;
	}
	else {
		int num1, num2, sum;
		num1 = Fibonacci(n - 1);
		num2 = Fibonacci(n - 2);
		sum = num1 + num2;
		return sum;
	}
}

int Solution::Fibonacci1(int n) {//动态规划
	if (n <=2 && n>0) return 1;
	int result, first, second;
	first = 1; // 2 - 2
	second = 1; // 2- 1
	for (int i = 2; i < n; i++) {
		//f(2) = f(1) + f(0) = 2
		//f(3) = f(2) + f(1) = 2 + 1 = 3
		//f(4) = f(3) + f(2 ) =  3 + 2 = 5 
		//f(5) = f(4) + f(3 ) =  5 + 3 = 8 
		result = first + second;
		second = first;
		first = result;
		
	}
	return result;
}