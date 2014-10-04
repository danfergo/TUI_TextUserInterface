/*
 * TextUserInterface.h
 *
 *  Created on: 04/11/2013
 *      author: Daniel Gomes
 *      e-mail: up201306839@fe.up.pt
 *
 */

#include "TextUserInterface.h"

using namespace std;

vector<string> TextUserInterface::strsplit(string str, string sep){
	vector<string> ret;
	if(sep.size() ==0){
		for(unsigned int i = 0; i < str.size(); i++){
			ret.push_back(str.substr(i,1));
		}
		return ret;
	}

	bool isSep = false;
	unsigned int lastIndex = 0;

	for(unsigned int i = 0; i < str.size(); i++){
		if(str[i] == sep[0]){
			isSep = true;
			for(unsigned j = 1; j < sep.size(); j++){
				if(str[i + j] != sep[j]){
					isSep = false;
					break;
				}
			}
			if(isSep){
				ret.push_back(str.substr(lastIndex, i - lastIndex));
				lastIndex = i + sep.size();
				i = i + sep.size() - 1;
			}
		}
	}
	ret.push_back(str.substr(lastIndex, str.size() - lastIndex));
	return ret;
}
static int verifOp(string str){
	if(str.size() > 2 || str.size() == 0){
		return -1;
	}
	int b = 1, n = 0;
	for(int i = str.size() - 1; i >= 0; i--){
		if(str[i] >= 48 || str[i] <= 57){
			n += (str[i] - 48)*b;
			b = b * 10;
		}else {
			return -1;
		}
	}
	return n;
}


TextUserInterface::TextUserInterface(string title, unsigned int w, unsigned int h): width(w),height(h), title(title){

}

string TextUserInterface::printLine(int size, char c){
	string ret = "";
	for(int i = 0; i < size ; i++){
		ret += c;
	}
	return ret;
}

string TextUserInterface::printTextLine(string text, Alignment align, unsigned int size){
	if(text.size() > size){
		text = text.substr(0,size);
	}
	if(align == CENTER){
		string sepace = printLine(size/2 - text.size()/2, ' ');
		string line = sepace + text + sepace;
		if(size % 2 != 0){
			line = " " + line;
		}
		if(text.size() % 2 != 0 ){
			line = line.substr(1);
		}
		return line;
	}else if(align == RIGHT){
		return printLine(size - text.size(), ' ')+ text;
	}else{
		return text + printLine(size - text.size(), ' ');
	}
}

string TextUserInterface::print(string o, Alignment align, string msg, bool menu){
	clearScreen();
	vector<string> toPrint = strsplit(o, "\n");
	string inp;
	cout << "+"<< printLine(width, '-') << "+"<< endl;
	cout << "|" + printTextLine(title, CENTER, width) + "|" << endl;
	cout << "+"<< printLine(width, '-') << "+"<< endl;

	for(unsigned int i = 0; i < toPrint.size(); i++){
		if(menu){
			cout << "|" << ((i + 1) == toPrint.size()? 0 : i+1) << " - " + printTextLine(toPrint[i], LEFT, i > 9 ? width - 5 : width - 4) + "|" << endl;
		}else{
			cout << "|" + printTextLine(toPrint[i], align, width) + "|" << endl;
		}
	}
	for(unsigned int i = toPrint.size(); i < height; i++){
		cout << "|" + printLine(width, ' ') + "|" << endl;
	}
	cout << "+"<< printLine(width, '-') << "+"<< endl;
	if(msg != "%%END%%"){
		cout  << (msg.size() == 0 ? "Prima enter para continuar..." : msg) << endl;
		cout << ">";
		getline(cin, inp);
		return inp;
	}else{
		cout << endl;
		return "";
	}
}

int TextUserInterface::printInt(string output, string msg, int min, int max, Alignment align){
	string s = print(output, align, msg, false);
	int n;
	stringstream str(s);
	str >> n;
	while(!(stringstream(s) >> n) || n < min || n > max){
		s = print(output, align,  "ERRO! Valor inválido. "+msg, false);
		stringstream str(s);
		str >> n;
	}
	return n;
}


float TextUserInterface::printFloat(string output, string msg, float min, float max, Alignment align){
	string s = print(output, align, msg, false);
	float n;
	stringstream str(s);
	str >> n;
	while(!(stringstream(s) >> n) || n < min || n > max){
		s = print(output, align,  "ERRO! Valor inválido. "+msg, false);
		stringstream str(s);
		str >> n;
	}
	return n;
}


int TextUserInterface::printMenu(string menu, bool err){
	string msg = err ? "ERRO! Opção inválida. Insira a opção:" : "Insira a opção:";

	string str = print(menu, LEFT, msg, true);

	unsigned int n = verifOp(str);
	if(n < 0 || n >   strsplit(menu, "\n").size() -1 ){
		return printMenu(menu,true);
	}
	return n;
};


void TextUserInterface::clearScreen(){
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

void TextUserInterface::printEnd(string o, Alignment align){
	string str = print(o, align, "%%END%%");
}



