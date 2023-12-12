#include <iostream>
using namespace std;
class Complex
{
	private:
		int real;
		int imag;
	public:
	Complex()
	{
		real = 0;
		imag = 0;
	}
	Complex operator+ (Complex &ob)
	{
		Complex result;
		result.real = real + ob.real;
		result.imag = imag + ob.imag;
		return result;
	}
	Complex operator* (Complex &ob)
	{
		Complex result;
		result.real = ((real * ob.real) + (-1)*(imag)*(ob.imag));
		result.imag = (imag * ob.real) + (real * ob.imag);
		return result;
	}
	void inputData()
	{
		cout << "enter real part: " << endl;
		cin >> real;
		cout << "enter imag part: " << endl;
		cin >> imag;
	}
	void displayComp()
	{
		if (imag < 0)
			cout << real << " - " << imag << "i" << endl;
		else
			cout << real << " + " << imag << "i" << endl;
	}
	friend ostream& operator<<(ostream&, Complex&);
	friend istream& operator>>(istream&, Complex&);
};

istream &operator>>(istream& is, Complex& ob)
{
	is >> ob.real;
	is >> ob.imag;
	return is;
}

ostream &operator<<(ostream& os, Complex& ob)
{
	os << ob.real;
	if (ob.imag < 0)
		os << " ";
	else
		os << " + ";
	os << ob.imag << "i" << endl;
	return os;
}

int main()
{
	Complex* num1 = new Complex;
	Complex* num2 = new Complex;
	cout << "Enter data for num1: " << endl;
	num1->inputData();
	cout << "Enter data for num2: " << endl;
	num2->inputData();
	cout << *num1;
	cout << *num2;
	Complex sumres = (*num1 + *num2);
	Complex multres = (*num1 * *num2);
	cout << sumres;
	cout << multres;
}
