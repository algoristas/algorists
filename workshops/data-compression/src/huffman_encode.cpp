#include <queue>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <map>

#define forit(i, a) for (__typeof((a).begin()) \
				i=(a).begin(); i!=(a).end(); i++)
#define forn(i,ct) for(int i=0; i<(ct).size();i++)
#define neg(N) ((N)*(-1))
#define F first
#define S second
#define dbg 1

using namespace std;

typedef pair<int, string > node;
typedef map <char, int   > mci;
typedef map <char, string> mcs;
typedef map <string, char> msc;

void build_hf_codes(string msg, mcs &hf_code, msc &hf_key) {
	mci freq;
	forn(i,msg) freq[msg[i]]++;
	hf_code.clear();
	hf_key.clear();
	priority_queue < node > PQ;
	forit(it,freq) {
		hf_code[it->first] = "";
		string str = "";
		str += (it->F);
		node aux = make_pair(neg(it->second),str);
		PQ.push(aux);
	}
	while(PQ.size() > 1) {
		node one = PQ.top(); PQ.pop();
		node two = PQ.top(); PQ.pop();
		forn(i,one.S) hf_code[one.S[i]] = "0" + hf_code[one.S[i]];
		forn(i,two.S) hf_code[two.S[i]]	= "1" + hf_code[two.S[i]];
		node mrg = make_pair(neg(neg(one.F)+neg(two.F)),one.S+two.S);
		PQ.push(mrg);
	}
	forit(it,hf_code) {
		if(dbg) printf("%c | %s\n",it->F,it->S.c_str());
		hf_key[it->S] = it->F;
	}
}

string encode_string(string msg, mcs &hf_code, msc &hf_key) {
	string ans = "";
	forn(i,msg) {
		ans += hf_code[msg[i]];
	}
	if(dbg) printf("%s Encoded is %s\n",msg.c_str(),ans.c_str());
	return ans;
}

string decode_string(string msg, mcs &hf_code, msc &hf_key) {
	string ans = "", word = "";
	forn(i,msg) {
		word += msg[i];
		if(hf_key.count(word))
		{
			ans += hf_key[word];
			word = "";
		}
	}
	if(dbg) printf("%s Decoded is %s\n",msg.c_str(),ans.c_str());
	return ans;
}

int main()
{
	mcs hf_code;
	msc hf_key;
	string msg;
	int op, cnt = 1;
	
	while( cnt ) {
		puts(" --- MENU --- ");
		puts(" 1) Generate Huffman  code  ");
		puts(" 2) Give a string to Encode ");
		puts(" 3) Give a string to Decode ");
		puts(" 4) EXIT & LIVE HAPPY 4EVER ");
		getline(cin,msg);
		sscanf(msg.c_str(),"%d",&op);
		switch(op) {
			case 1: {
				puts("Please enter the frequency string");
				getline(cin,msg);
				build_hf_codes(msg, hf_code, hf_key);
				break;
			}
			case 2: {
				puts("Please enter the string to be encode");
				getline(cin,msg);
				msg = encode_string(msg,hf_code, hf_key);
				break;
			}
			case 3: {
				puts("Please enter the string to be decode");
				getline(cin,msg);
				msg = decode_string(msg,hf_code, hf_key);
				break;
			}
			case 4: {
				cnt = 0;
				break;
			}
			default: puts("Please read carefully !!!!");
		}
		
	}
    return 0;
}
