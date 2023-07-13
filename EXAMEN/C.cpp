#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main(){
	int nro , numero_total  ,v;
	cin>>nro;
	
	while(nro--){
		cin>>numero_total;
		
		vector<int> Monedas;
		for(int i = 0 ; i<numero_total;i++){
			cin>>v;
			Monedas.push_back(v);
		}
		
		int suma = 0 , resultado = 0 ;
		for(int i = 0 ; i<numero_total ; i++){
			if(numero_total-1	== i || suma+Monedas[i]<Monedas[i+1]){
				suma += Monedas[i];
				resultado++;
			}
		}
		cout<<resultado<<endl;
	}
}