#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

ifstream instream;
ifstream readstream;
string linie;
string erlin;
string zwlin;

int len_erlin;
int len_zwlin;
int length;
int length2;
int eof_b;

float natom, x_c, y_c, z_c, ladung, abstand, atom_vol;

vector <float> ladungen;

int get_nlines(){
 int nline = 0;
	readstream.open("ACF.dat");
		while(getline(readstream, linie)){
			nline += 1;
		}
	readstream.close();

	return nline;
}

int main() {
 int nlines;
	nlines = get_nlines();

	instream.open("ACF.dat");

	getline(instream, erlin);
	len_erlin = erlin.length();
	len_zwlin = len_erlin + 4;

	// zieh die Grosse des Dateies
	instream.seekg(-(len_erlin+len_zwlin), instream.end);
	length = instream.tellg();
	// Lieg am Anfang des Dateies
	instream.seekg(0, instream.beg);

	instream.seekg((len_erlin+len_zwlin), instream.beg);

	for (int i = 1; i<=(nlines-6) ; i++){
		getline(instream, linie);
  // Stream das String
	 istringstream iss(linie); 
		// Variablen speichern
		iss >> natom >> x_c >> y_c >> z_c >> ladung >> abstand >> atom_vol;
		// Ladungen in Vektor pushen.
		ladungen.push_back(ladung);
	}

	for (float j: ladungen){
		cout << j << endl;
	}

	instream.close();

	return 0;
}
