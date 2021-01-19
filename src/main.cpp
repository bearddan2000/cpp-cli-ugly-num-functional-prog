// CPP program to find nth ugly number
# include<iostream>

using namespace std;

/*
    Forward declaration of functions
    lets main be the first function.
*/

/*This function divides a by greatest divisible power of b*/
int const maxDivide(const int a, const int b);

/* Function to check if a number is ugly or not */
int const isUgly(const int no);

/* Function to get the nth ugly number*/
int const getNthUglyNo(const int n, const int i, const int count /* ugly number count */);

/* Driver program to test above functions */
int main()
{
    const int input = 10;
	cout<<"[INPUT] "<<input<<endl;
	const int output = getNthUglyNo(input, 1, 1);
	cout<<"[OUTPUT] "<<output<<endl;
	return 0;
}

/*This function divides a by greatest divisible power of b*/
int const maxDivide(const int a, const int b)
{
    if(a%b != 0) return a;
    return maxDivide(a/b, b);
}

/* Function to check if a number is ugly or not */
int const isUgly(const int no)
{
    const int a = maxDivide(no, 2);
    const int b = maxDivide(a, 3);
    const int c = maxDivide(b, 5);

    return (c == 1)? 1 : 0;
}

/* Function to get the nth ugly number*/
int const getNthUglyNo(const int n, const int i, const int count /* ugly number count */)
{
    /*Check for all integers untill ugly count becomes n*/
    if (n < count) return i-1;
    if (isUgly(i)) return getNthUglyNo(n, i+1, count+1);
    else return getNthUglyNo(n, i+1, count);
} 
