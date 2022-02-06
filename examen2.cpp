
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string aux[10000][4];
void archivos();
int convertir(string k);
struct inv{
	int cod_suc;
	string cod_inv;
	int capital;
	string fecha;
};

inv inversiones[10000];
int cod_suc[10], cont1=0, cont2=0, cont3=0, i=0, x=0;
string nomb_suc[10], portafolio[50][2];
int main(int argc, char *argv[]) {
	archivos();
	//cout << inversiones[0].cod_suc;
	/*for (i=0; i<cont3; i++)
	{
		
		//cout << portafolio[i][0] << " " << portafolio[i][1] << endl;
		//cout << inversiones[i].cod_suc << " " << inversiones[i].cod_inv << " " << inversiones[i].capital << " " << inversiones[i].fecha << endl;
	}*/
	//cout << cont2;
	return 0;
	
}

void archivos()
{
	ifstream archivo1;
	archivo1.open("SUCURSALES.TXT");
	if (archivo1.fail())
	{
		cout << "ERROR";
	}
	else 
	{
		while (!archivo1.eof())
		{
			archivo1 >> cod_suc[i];
			getline(archivo1, nomb_suc[i]);
			cont1++;
			i++;
		}
		
	}
	archivo1.close();
	i=0;
	char delimitador = ' ';
	char a = '2020';
	ifstream archivo2;
	archivo2.open("PORTFOLIO.TXT");
	if (archivo2.fail())
	{
		cout << "ERROR";
	}
	else
	{
		while (!archivo2.eof())
		{
			getline (archivo2, portafolio[i][0]);
			getline (archivo2, portafolio[i][1]);
			i++;
			cont2++;
		}
		
	}
	archivo2.close();
	i=0;
	ifstream archivo3;
	archivo3.open("INVERSIONES.TXT");
	if (archivo3.fail())
	{
		cout << "ERROR";
	}
	else
	{
		while (!archivo3.eof())
		{
			getline (archivo3, aux[i][0], delimitador);
			getline (archivo3, aux[i][1], delimitador);
			getline (archivo3, aux[i][2], delimitador);
			getline (archivo3, aux[i][3]);
			i++;
			cont3++;
		}
	}
	archivo3.close();
	cout << aux[0][0] << " " << aux[0][1] << " " << aux[0][2] << " " << aux[0][3];
	/*for (i=0; i<cont3-1; i++)
	{
		inversiones[i].cod_suc = stoi (aux[i][0]);
		inversiones[i].cod_inv = aux[i][1];
		inversiones[i].capital = stoi (aux[i][2]);
		//inversiones[i].fecha = convertir(aux[i][3]);
		cout << aux[i][3] << endl;
	}*/
} 
int convertir(string k)
{
	int x = stoi (k.substr(3,2));
	return x;
}
