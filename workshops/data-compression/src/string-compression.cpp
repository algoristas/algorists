#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string lre(const string& input){
	stringstream compressed;
	for(string::const_iterator c = input.begin(); c != input.end();){
		char x = *c;
		compressed << x;
		unsigned int k = 1;
		while(*(++c) == x){
			k++;
		}
		compressed << k;
	}

	string result = compressed.str();
	return result.size() >= input.size() ? input : result;
}

string lre_bin(const string& input){
	const int B = 8;
	const int b = B * sizeof(char);
	int k,x,y = 0;
	char p,M = (~0) >> 1;
	stringstream compressed;

	for(auto c: input){
		for(k = b - 1; k >= 0; k--){
			x = ((c & (1 << k)) >> k);
			if((p < M) && (x == y)){
				p++;
			}else{
				compressed << ((x << (B - 1)) | p);
				if(x != y){
					p = 1;
				}
			}
			cout << x;
		}
		//cout << ' ';
	}
	cout << endl;
	string result = compressed.str();
	return result;
	return result.size() >= input.size() ? input : result;
}

string lre_v2(const string& input){
	const unsigned char MAX = ~0;
	stringstream compressed;
	for(string::const_iterator c = input.begin(); c != input.end();){
		unsigned char x = *c;
		compressed << x;
		unsigned char k = 1;
		while(*(++c) == x && k < MAX){
			k++;
		}
		compressed << k;
	}

	string result = compressed.str();
	return result.size() >= input.size() ? input : result;
}

string decompress(const string& input){
	stringstream uncompressed;
	for(string::const_iterator c = input.begin(); c != input.end(); c += 2){
		unsigned char k = *(c + 1);
		for(unsigned char i = 1; i <= k; i++){
			uncompressed << *c;
		}
	}
	return uncompressed.str();
}

int main(int argc, char const *argv[]){
	string in;
	getline(cin,in);
	cout << "LRE v1.0: " << lre(in) << endl;
	//cout << "LRE v2.0: " << lre_bin(in) << endl;
	string compressed = lre_v2(in);
	cout << "LRE v2.0: " << compressed << endl;
	cout << "Original: " << decompress(compressed) << endl;
	return 0;
}
