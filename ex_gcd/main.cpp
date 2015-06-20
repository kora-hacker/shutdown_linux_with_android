/*
 * main.cpp
 *
 *  Created on: 2015年6月20日
 *      Author: kora
 */

#include <iostream>
#include <cmath>
using namespace std;

typedef long long int LONGINT;

LONGINT ex_gcd (LONGINT a, LONGINT b, LONGINT &x, LONGINT &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	LONGINT ans = ex_gcd (b, a%b, x, y);
	LONGINT temp = x;
	x = y;
	y = temp - a/b*y;
	return ans;
}

LONGINT cal (LONGINT a, LONGINT m)
{
	LONGINT x, y;
	LONGINT gcd_value  = ex_gcd (a,m,x,y);
	if (1%gcd_value!=0)return -1;
	x*=1/gcd_value;
	m=abs(m);
	cout << m << endl;
	int ans=x%m;
	if (ans <= 0) ans+=m;
	return ans;
}


int main ()
{
	LONGINT a,b,x,y;
	a = 26857;
	b = 215;
	cout << ex_gcd (a,b,x,y) << endl;
	cout << a << " " << b << " " << x << " " << y << endl;
	cout << cal (a, b) << endl;
	return 0;
}


