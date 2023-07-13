#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    vector<int> Vec;
 	int elemento ;
    while(cin>>elemento){
        Vec.push_back(elemento);
        sort(Vec.begin(), Vec.end());
	    int numero_mitad = 0 ;
	    if(Vec.size() % 2 != 0){
	        numero_mitad =Vec[ Vec.size() /2 ];
	        cout<< numero_mitad<<endl;
	    }
	    else{
	        numero_mitad = (Vec[ Vec.size() /2 ] + Vec[(Vec.size() /2) - 1 ])/2;
	        cout<< numero_mitad<<endl;
	    }
    } 
    return 0;
}