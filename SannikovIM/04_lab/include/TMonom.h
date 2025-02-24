#pragma once
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
class TMonom{
private:
	string pMem;
	int len;
public:
	TMonom(){}
	TMonom(string pMem){
		this->pMem = pMem;
		this->len = strlen(this->pMem.c_str());
	}
	TMonom(const TMonom& mon){
		this->pMem = mon.pMem;
		this->len = strlen(this->pMem.c_str());

	}
	double GetValue(){
		int i = 0;
		string newNum = "";
	//	cout << pMem[i] << endl;;
		while (pMem[i] != 'x' && pMem[i] != 'X' && pMem[i] != 'y' && pMem[i] != 'Y' && pMem[i] != 'z' && pMem[i] != 'Z') {
			newNum += pMem[i];
			i++;
		
		}
		return stod(newNum);
	}
	double GetConvolution() {
		int i = 0;
		string newNum = "";
		char lastChar;
		double xconf = 0, yconf = 0 , zconf = 0;
		while (pMem[i] != 'x' && pMem[i] != 'X' && pMem[i] != 'y' && pMem[i] != 'Y' && pMem[i] != 'z' && pMem[i] != 'Z') {
			i++;

		}
		while(i < this->len) {
			if (pMem[i] == 'x' || pMem[i] == 'X' || pMem[i] == 'y' || pMem[i] == 'Y' || pMem[i] == 'z' || pMem[i] == 'Z') {
				lastChar = pMem[i];
				if (pMem[i+1] == 'x' || pMem[i+1] == 'X' || pMem[i+1] == 'y' || pMem[i+1] == 'Y' || pMem[i+1] == 'z' || pMem[i+1] == 'Z' || i+1 == this->len) {
					switch (lastChar) {
					case 'x':
						xconf = 100;
						if (xconf == 0) xconf = 100;
						break;
					case 'X':
						xconf = 100;
						if (xconf == 0) xconf = 100;
						break;
					case 'y':
						yconf = 10;
						if (yconf == 0) yconf = 10;
						break;
					case 'Y':
						yconf = 10;
						if (yconf == 0) yconf = 10;
						break;
					case 'z':
						zconf = 1;
						if (zconf == 0) zconf = 1;
						break;
					case 'Z':
						zconf = 1;
						if (zconf == 0) zconf = 1;
						break;
					}
				}
				lastChar = pMem[i];
			}
			else if (pMem[i] == '^') {
				if (pMem[i] != 'x' && pMem[i] != 'X' && pMem[i] != 'y' && pMem[i] != 'Y' && pMem[i] != 'z' && pMem[i] != 'Z') {
					switch (lastChar) {
						case 'x': 
							xconf =100* (pMem[i + 1] - '0');
							i++;
							if(xconf == 0) xconf =100;
							//cout<<xconf<<endl;
							break;
						case 'X':
							xconf = 100 * (pMem[i + 1] - '0');
							i++;
							if(xconf == 0) xconf = 100;
							break;
						case 'y':
							yconf = 10 * (pMem[i + 1] - '0');
							i++;
							if(yconf == 0) yconf =10;
							break;
						case 'Y':
							yconf = 10 * (pMem[i + 1] - '0');
							i++;
							if(yconf == 0) yconf = 10;
							break;
						case 'z':
							zconf =  pMem[i + 1] - '0';
							i++;
							if(zconf == 0) zconf =1;
							break;
						case 'Z':
							zconf =  pMem[i + 1] - '0';
							i++;
							if(zconf == 0) zconf = 1;
							break; 
					}
				}

			}
			
			i++;
		}
		return xconf+yconf+zconf;
	}
};
