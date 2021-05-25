#include <iostream>
#include <vector>

	using namespace std;


int main( ) 
{ 

	const int max = 10;
	vector<int> v(max,77);

	for(int i = 0; i < v.size(); ++i) 
		cout << v[i] << endl;

	for(vector<int>::size_type i = 0; i < v.size() ; i++)
		cout << v[i] << endl;	

}