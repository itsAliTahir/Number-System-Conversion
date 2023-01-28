#include <iostream>
#include <string>
#include <conio.h>
#include <math.h>
using namespace std;
bool numberCheck(string n, int m)
{
	bool check = false;
	int len = n.length();
	char cs[len + 1];	
 	strcpy(cs, n.c_str());
 	for(int i=0; i<len; i++)
	{
		if(m==2)
		{
			if(cs[i] == 48 || cs[i] == 49)	check = true;
			else	{	check = false; break;	}	
		}
		else if(m==8)
		{
			if(cs[i] >= 48 && cs[i] <= 55)	check = true;
			else	{	check = false; break;	}
		}
		else if(m==10)
		{
			if(cs[i] >= 48 && cs[i] <= 57)	check = true;
			else	{	check = false; break;	}
		}
		else if(m==16)
		{
			if((cs[i] >= 48 && cs[i] <= 57) || (cs[i] >= 65 && cs[i] <= 70))	check = true;
			else	{	check = false; break;	}	
		}	
	}
	return check;
};
int toDecimal(int n, int m)
{
	int rem=0, ans=0, power=0;
	while(n>0)
	{
		rem = n%10;
		n = n/10;
		ans = ans+(rem*pow(m, power));
		power++;
  	}
	return ans;
};
long int fromDecimal(int n, int m)
{
	long int rem=0, ans=0, p=1;
	while(n>0)
	{
		rem = n%m;
		ans = ans+(rem*p);		
		n = n/m;
		p = p*10;
	}
	return ans;
}
string decimalToHexadecimal(int n)
{
	int rem=0;
	string r=" ";
	string ans=" ";
	while(n>0)
	{
		rem = n%16;
		if (rem == 0) r = "0";
		else if (rem == 1) r = "1";
		else if (rem == 2) r = "2";			
		else if (rem == 3) r = "3";
		else if (rem == 4) r = "4";
		else if (rem == 5) r = "5";			
		else if (rem == 6) r = "6";
		else if (rem == 7) r = "7";
		else if (rem == 8) r = "8";			
		else if (rem == 9) r = "9";
		else if (rem == 10) r = "A";
		else if (rem == 11)	r = "B";
		else if (rem == 12) r = "C";
		else if (rem == 13) r = "D";
		else if (rem == 14) r = "E";
		else if (rem == 15) r = "F";
		ans = r + ans;
		r = " ";
		n = n/16;	
	}
	return ans;		
}

int hexadecimalToDecimal(string s)
{
	int num = 0, power = 0;
	int ans=0;
	int len = s.length();
	char cs[len + 1];	
 	strcpy(cs, s.c_str());
 	power = len-1;
	for(int i=0; i<len; i++)
	{
		if (cs[i] == '0') num = 0;
		else if (cs[i] == '1') num = 1;
		else if (cs[i] == '2') num = 2;
		else if (cs[i] == '3') num = 3;
		else if (cs[i] == '4') num = 4;
		else if (cs[i] == '5') num = 5;
		else if (cs[i] == '6') num = 6;
		else if (cs[i] == '7') num = 7;
		else if (cs[i] == '8') num = 8;
		else if (cs[i] == '9') num = 9;
		else if (cs[i] == 'A') num = 10;
		else if (cs[i] == 'B') num = 11;
		else if (cs[i] == 'C') num = 12;
		else if (cs[i] == 'D') num = 13;
		else if (cs[i] == 'E') num = 14;
		else if (cs[i] == 'F') num = 15;
		ans = ans+(num*(pow(16,power)));
		power--;				 		 		 				 		 		
	}
	return ans;
}
int main ()
{
	int number;
	string st;
	char option;
	cout << "\t     Menu" << endl;
	for(int i=0;i<35;i++)
	cout << "\xcd";
	cout << endl;
	cout << "Press 1 to Enter Binary Number" <<endl;
	cout << "Press 2 to Enter Octal Number" <<endl;
	cout << "Press 3 to Enter Decimal Number" <<endl;
	cout << "Press 4 to Enter Hexadecimal Number" <<endl;	
	option = getch();
	system("CLS");
	if (option == '1') cout << "Enter Binary Number: ";
	if (option == '2') cout << "Enter Octal Number: ";	
	if (option == '3') cout << "Enter Decimal: ";
	if (option == '4') cout << "Enter Hexadecimal: ";
	if(option>48 && option<53)
	cin >> st;
	switch(option)
	{
		case '1':
			if (numberCheck(st, 2) == true)
			{
				number = stoi(st);
				cout << "Decimal: " << toDecimal(number,2) << endl;
				cout << "Octal: " << fromDecimal(toDecimal(number,2),8) << endl;
				cout << "Hexadecimal: " << decimalToHexadecimal(toDecimal(number,2)) << endl;
			}
			else cout << "Not Binary Number";
		break;	
			
		case '2':
			if (numberCheck(st, 8) == true)
			{
				number = stoi(st);	
				cout << "Binary: " << fromDecimal(toDecimal(number,8),2) << endl;
				cout << "Decimal: " << toDecimal(number,8) << endl;
				cout << "Hexadecimal: " << decimalToHexadecimal(toDecimal(number,8)) << endl;
			}
			else cout << "Not Octal Number";
		break;			
		
		case '3':
			if (numberCheck(st, 10) == true)
			{	
				number = stoi(st);					
				cout << "Binary: " << fromDecimal(number,2) << endl;
				cout << "Octal: " << fromDecimal(number,8) << endl;
				cout << "Hexadecimal: " << decimalToHexadecimal(number) << endl;
			}
			else cout << "Not Decimal Number";	
		break;
		
		case '4':
			if (numberCheck(st, 16) == true)
			{			
				cout << "Binary: " << fromDecimal(hexadecimalToDecimal(st),2) << endl;
				cout << "Octal: " << fromDecimal(hexadecimalToDecimal(st),8) << endl;
				cout << "Decimal: " << hexadecimalToDecimal(st) << endl;
			}
			else cout << "Not Hexadecimal Number";	
		break;	
			
		default:
			cout << "Invalid Input.";
		break;
	}
	return 0;
}