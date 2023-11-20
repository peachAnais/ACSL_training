//  Vampire - WRITTEN BY TROY HS
//
//

// Includes
#include <iostream.h>
#include <fstream.h>
#include <iomanip.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#include "apvector.h"
//#include "apqueue.h"
#include "apstack.h"
#include "apstring.h"
//#include "apmatrix.h"
const bool debug = false;

/*bool isDigitIn(int digit,int num)
{
	char d= digit + '0';
	int occur(0);
	apstring s = atoi(num);
	for (int x=0;x<s.length();x++)
	{
		if (s[x] == d) occur++;
	}
	return occur == 1;
}*/

bool isDigitIn(char digit,apstring num)
{
	int occur(0);
	for (int x=0;x<num.length();x++)
	{
		if (num[x] == digit) occur++;
	}
	return occur == 1;
}
apstring atoi(int x)
{
	apstring n;
	
	while ( x > 0 )
	{
	  n = ('0'+x%10) + n;
	  x /=10;
	}
	return n;
}

bool allDigitsAndFactor(int num, int f1, int f2)
{
	bool go = (f1==60 || f2 == 60);
	if (debug && go)
		cout << "MADE IT TO FUNCTION"<<endl;
		
	bool ok(true);
	apstring big(atoi(num));
	apstring fact1(atoi(f1));
	apstring fact2(atoi(f2));
	if (f1%100 == 0 || f2%100 == 0) return false;
	if (debug && go) cout << "NOT DIVIS BY 100"<<endl;
	if (debug && go) cout << "Target "<< big.length()<<endl;
	if (debug && go) cout << fact1.length() <<endl;
	if (fact1.length() != big.length()/2) return false;
	if (debug && go) cout << "F1 CORRECT LENGTH"<<endl;
	if (fact2.length() != big.length()/2) return false;
	if (debug && go) cout << fact2.length() <<endl;
	if (debug && go) cout << "F2 CORRECT LENGTH"<<endl;	
	
	apvector<int> dig(10,0);
	for (int x=0;x<big.length();x++)
	{
		dig[big[x]-'0'] += 1;
	}
	for (int y=0;y<fact1.length();y++)
	{
		dig[fact1[y]-'0'] -= 1;
	}
	for (int y=0;y<fact2.length();y++)
	{
		dig[fact2[y]-'0'] -= 1;
	}
	for (int x=0;x<dig.length();x++)
	{
		if (dig[x] != 0)
			ok = false;
	}
	if (debug && go) cout << "RIGHT NUM OF DIGITS"<<endl;
	ok = ok && (f1 * f2 == num);
	return ok;
}

struct factorPair
{
	int f1,f2;
};

apvector<factorPair> allFactors(int num)
{
	apstack<factorPair> outp;
	for (int x=num;x>=sqrt(num);x--)
	{
		int y = num/x;
		if (y * x == num)
		{
			factorPair t;
			t.f1 = y;
			t.f2 = x;
			outp.push(t);
		}
	}
	int x=0;
	apvector<factorPair> j(outp.length());
	while (!outp.isEmpty())
	{
		outp.pop(j[x]);
		x++;
	}
	return j;
}
		

int main()
{
	for (int lkj=0;lkj < 10;lkj ++)
	{
		int num;
		cout << "Enter Data: ";
		cin >> num;
		
		apvector<factorPair> fact = allFactors(num);
		if (debug) for (int x=0;x<fact.length();x++) cout << fact[x].f1 << ',' << fact[x].f2<< ' ';
		if (debug) cout << endl;
		
		apstack<factorPair> sol;
		for (int x=0;x<fact.length();x++)
		{
			if (debug) cout << "I  AM IN A FOR LOOP"<<endl;
			if (allDigitsAndFactor(num,fact[x].f1,fact[x].f2))
				sol.push(fact[x]);
		}
		
		if (sol.isEmpty()) cout << "NONE"<<endl;
		else
		{
			cout <<sol.top().f1 << ','<<sol.top().f2;
			sol.pop();
			while (!sol.isEmpty())
			{
				cout << " and "<<sol.top().f1 << ','<<sol.top().f2;
				sol.pop();
			}
			cout << endl;
		}
		
	}

}