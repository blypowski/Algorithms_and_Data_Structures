#include<iostream>
#include<string>
#include<stack>

#define MAX 1000000

int main() {

	std::stack<char> s;
char znak;
std::string out;
	while (std::cin>>znak) {
		if(isdigit(znak)) out += znak;
		else {
			if (znak=='*' || znak=='/' || znak=='+' || znak=='-') {
				out+=" ";
				if(s.size()<MAX) {
					s.push(znak);
				}
			}
			
			else if (znak==')') {
				if(!s.empty()) {
					out = out +" " + s.top();
					s.pop();
				}
			}
		}
		
	}
	out.pop_back();
	std::cout << out;
	
	return 0;
}
