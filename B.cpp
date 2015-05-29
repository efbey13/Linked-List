#include<iostream>

using namespace std;

int main()
{
	int a = 50;									// initialize integer variable a
	cout<<"Value of 'a' = "<<a<<endl;			// show the output of a
	cout<<"Memory address of 'a': "<<&a<<endl;	// show the address of a
	cout<<endl;

	int * b;									// declare an integer pointer b
	b = &a;										// transfer the address of 'a' to pointer 'b'
	cout<<"Value of Pointer 'b': "<<*b<<endl;	// show the output of *b
	cout<<"Content of Pointer 'b': "<<b<<endl;	// show the content of *b
	cout<<"Memory address of Pointer 'b': "<<&b<<endl; // show the address of *b
	cout<<endl;

	int **c;									// declare an integer pointer to a pointer
	c = &b;										// transfer the address of 'b' to 'c'
	cout<<"Value of Pointer 'c': "<<**c<<endl;	// show the output of **c
	cout<<"Content of Pointer 'c': "<<c<<endl;  // show the content of **c
	cout<<"Memory address of Pointer 'c': "<<&c<<endl; // show the address of **c
	cout<<endl;
	return 0;
}