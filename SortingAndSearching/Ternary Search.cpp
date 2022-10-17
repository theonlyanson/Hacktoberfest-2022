
#include <bits/stdc++.h>
using namespace std;


int ternarySearch(int l, int r1, int key1, int ar[])
{
	if (r1 >= l) {


		int mid1 = l + (r1 - l) / 3;
		int mid2 = r1 - (r1 - l) / 3;


		if (ar[mid1] == key1) {
			return mid1;
		}
		if (ar[mid2] == key1) {
			return mid2;
		}

		
		if (key1 < ar[mid1]) {

			return ternarySearch(l, mid1 - 1, key1, ar);
		}
		else if (key1 > ar[mid2]) {

			
			return ternarySearch(mid2 + 1, r1, key1, ar);
		}
		else {

			
			return ternarySearch(mid1 + 1, mid2 - 1, key1, ar);
		}
	}

	
	return -1;
}


int main()
{
	int l, r1, p, key1;

	
	int ar[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	
	l = 0;

	r1 = 9;


	key1 = 5;

	
	p = ternarySearch(l, r1, key1, ar);

	
	cout << "Index of " << key1
		<< " is " << p << endl;

	
	key1 = 50;


	p = ternarySearch(l, r1, key1, ar);

	
	cout << "Index of " << key1
		<< " is " << p << endl;
}


