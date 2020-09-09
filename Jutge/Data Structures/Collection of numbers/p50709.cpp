#include <iostream>
#include <map>
using namespace std;

typedef map<int,int> M; 
typedef pair<int,int> P;

int main(){
/*
	Col·leccio de nombres enters, possiblement repetits. 
	Utilitzem un mapa<K,V> on K = nombre enter, V = vegades que apareix
*/
	M m; 
	char a;
	while(cin >> a){ // Cost: Θ (M * log(n)). sent M la mida de les dades del input.  
		if(a == 'S'){
			// 'S' x : Guarda una copia del numero x donat. Cost : Θ (log(n)).
			int x;
			cin >> x;
			if(m.find(x) == m.end()){
				//S'ha d'insertar el nombre ja que no apareix en la col·lecio.
				m.insert( P(x,1) );
			}
			else{
				//S'hi afegeix una copia. 
				++m[x];
			}
		}
		else if(a == 'A'){
			// 'A' : Consulta el numero mes gran i l'escriu per pantalla. Cost : Θ (1).
			if( !m.empty() ){
				auto it = m.end();
				--it;
				cout << it->first << endl;
			}
			else{
				cout << "error!" << endl; // Missatge d'error quan la col·leccio esta buida.
			}
		}
		else if(a == 'R'){
			// 'R' : Elimina una copia del nombre mes gran. Cost : Θ (log(n)).
			if( !m.empty() ){
				auto it = m.end();
				--it;
				int x = it->first;
				if(m[x] > 1){
					--m[x];
				}
				else {
					m.erase(it);
				}
			}
			else{
				cout << "error!" << endl;
			}
			
		}
		else if(a == 'I'){
			/* 
				'I' x : S'esborra una copia del nombre mes gran i s'insereix el nou nombre 
				incrementat en x. Cost : Θ (log(n)).
			*/
			int x;
			cin >> x;
			if( !m.empty() ){
				auto it = m.end();
				--it;
				if(m[it->first] > 1){
					--m[it->first];
					int r = it->first + x;
					if(m.find(r) == m.end())m.insert( P(r , 1) );
					else ++m[r];
				}
				else{
					int z = it->first;
					m.erase(z);
					int r = z + x;
					if(m.find(r) == m.end())m.insert( P(r , 1) );
					else ++m[r];
				}
			}
			else{
				cout << "error!" << endl;
			}
		}
		else if(a == 'D'){
			/* 
				'D' x : S'esborra una copia del nombre mes gran i s'insereix el nou nombre 
				decrementat en x. Cost : Θ (log(n)).
			*/ 
			int x;
			cin >> x;
			if( !m.empty()){
				auto it = m.end();
				--it;
				if(m[it->first] > 1){
					--m[it->first];
					int r = it->first - x;
					if(m.find(r) == m.end())m.insert( P(r , 1) );
					else ++m[r];
				}
				else{
					int z = it->first;
					m.erase(z);
					int r = z - x;
					if(m.find(r) == m.end())m.insert( P(r , 1) );
					else ++m[r];
				}
			}
			else{
				cout << "error!" << endl;
			}
		}
	}             

}


