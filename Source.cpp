#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{

	fstream myFile;
	myFile.open("imput_exemple.csv");
	string name;
	string email;
	string location;
	int a = 0;
	

	string name1[100];
	string email1[100];
	string location1[100];
	if (!myFile.is_open()) {
		//cout << "eroare";
	}
	
	
	while (myFile.good()) {

		getline(myFile, name, ',');
		getline(myFile, email, ',');
		getline(myFile, location, '\n');
		if (name == "") {

		}
		else{
			name1[a] = name;
			email1[a] = email;
			location1[a] = location;
			//cout << name1[a] << ", " << email1[a] << ", " << location1[a] << endl;
			a++;
		}
	}
	int ver1[100];
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			if (name1[i] == name1[j] || email1[i] == email1[j]) {
				if (i != j) {
					//cout << i << j << endl;
					if (i > j) {
						ver1[i] = 1;
					}
					else
					{
						ver1[j] = 1;
					}
				}
			}
			
		}
	}
	int ascii[100][100];
	for (int i = 0; i < a; i++) {
		
		if (ver1[i] == 1) {
			
		}
		else {
			char cArray[1024];
			strncpy_s(cArray, name1[i].c_str(), sizeof(cArray));
			cArray[sizeof(cArray) - 1] = 0;
			int m=0;
			for (int j = 0; cArray[j] != 0; j++)
			{
				//cout << "\n cArray[ " << j << " ] :   " << cArray[j];
				m++;
			}
			for (int j = 0; cArray[j] != 0; j++) {
				ascii[i][j] = (int)cArray[j];
				//cout << ascii[i][j]<<",";
			}
			
			
		}
		//cout << endl;
	}
	//open file and write:
	ofstream myfile;
	myfile.open("out.csv");


	for (int j = 65; j < 91; j++){

		myfile << (char)j << "\n";
		for (int i = 0; i < a; i++) {

			if (ascii[i][0] == j) {
				//cout << i<< ":"<<j;
				myfile << name1[i] << "," << email1[i]<<","<<location1[i]<<"\n";
			}
			else {

			}
		}
	}


	char c = 'c';
	myFile.close();
	int num = (int)c;
	
	return 0;
}




