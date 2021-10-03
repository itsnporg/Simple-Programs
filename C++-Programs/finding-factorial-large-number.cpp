
#include <iostream>

int multiply(int x, int a[], int size)
{
	int carry = 0;
	for (int i = 0; i < size; i++)
	{
		int prod = a[i] * x + carry;
		a[i] = prod % 10;
		carry = prod / 10;
	}

	while (carry)
	{
		a[size]=(carry % 10);
		carry = carry / 10;
		size++;
	}

	return size;
}

int main()
{
	int a[500];

	a[0] = 1;
	int size = 1;
        
        int n;
	std::cout<<"Enter a number: ";std::cin>>n;

	for (int x = 2; x <= n; x++)
	{
		size = multiply(x, a,size);
	}

	int sum = 0;
	std::cout << "Factorial of given number is"<<std::endl;
	for(int i = size-1;i>=0;i--)
	{
		std::cout << a[i] << " ";
	}

}
