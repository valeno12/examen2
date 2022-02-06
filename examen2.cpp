
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string aux[10000][4];
void archivos(), igualar(), informe2();
int convertir(string k);
struct tot{
	string cod;
	string desc;
	int monto;
};
struct inv{
	int cod_suc;
	string cod_inv;
	int capital;
	int mes;
};

inv inversiones[10000];
tot inv_total[10];
int cod_suc[10], cont1=0, cont2=0, cont3=0, cont4=0, i=0, x=0, informe[10][12];
string nomb_suc[10], portafolio[50][2];
int main(int argc, char *argv[]) {
	archivos();
	for (i=0; i<cont2; i++)
	{
		//cout << portafolio[i][1] << endl;
	}
	//igualar();
	/*for (i=0; i<cont3-1; i++)
	{
		informe[inversiones[i].cod_suc-1][inversiones[i].mes-1] = informe[inversiones[i].cod_suc-1][inversiones[i].mes-1] + 1;
	}
	cout << "Suc" << "  " << "Ene" << "  " << "Feb" << "  " << "Mar" << "  " << "Abr" << "  " << "May" << "  " << " jun" << "  " << "jul" << "  " << "ago" << "  " << "sep" << "  " << "oct" << "  " << "nov" << "  " << "dic" << endl;
	for (i=0; i<10; i++)
	{
		cout << i+1 << "   ";
		for (int j=0; j<12; j++)
		{
			cout << " " << informe[i][j] << "  ";
		}
		cout << endl;
	}*/
	//informe2();
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
	for (i=0; i<cont3-1; i++)
	{
		inversiones[i].cod_suc = stoi (aux[i][0]);
		inversiones[i].cod_inv = aux[i][1];
		inversiones[i].capital = stoi (aux[i][2]);
		inversiones[i].mes = convertir(aux[i][3]);
		//cout << inversiones[i].cod_suc  << " " << inversiones[i].cod_inv << " " << inversiones[i].capital << " " << inversiones[i].mes << endl;
		//cout << inversiones[i].mes << endl;
	}
} 
int convertir(string k)
{
	string y = k.substr(3, 2);
	int x = stoi ( y );
	//cout << x << endl;
	return x;
}
void igualar()
{
	for (int k=0; k<12; k++)
	{
		for (int j=0; j<10; j++)
		{
			informe[j][k] = 0;
		}
	}
	
}
void informe2()
{
	int aux;
	string aux1, aux2;
	int k=0;
	cout << portafolio[1][1] << endl;
	for (i=0; i<cont2; i++)
	{
		for (int j=0; j<cont3; j++)
		{
			if (inversiones[j].cod_inv == portafolio[i][0])
			{
				
				inv_total[k].cod = portafolio[i][0];
				inv_total[k].desc = portafolio[i][1];
				inv_total[k].monto += inversiones[j].capital;
				cout << inv_total[0].desc << endl;
			}
		}
		k++;
		cont4;
	}
		cout << inv_total[0].desc;
	//
	/*for (i=0; i<cont4; i++)
	{
		for (int j=i+1; j<cont4; j++)
		{
			if (inv_total[i].monto < inv_total[j].monto)
			{
				aux = inv_total[i].monto;
				inv_total[i].monto = inv_total[j].monto;
				inv_total[j].monto = aux;
				
				aux1 = inv_total[i].desc;
				inv_total[i].desc = inv_total[j].desc;
				inv_total[j].desc = aux;
				
				aux2 = inv_total[i].cod;
				inv_total[i].cod = inv_total[j].cod;
				inv_total[j].cod = aux;
			}
		}
	}*/
	//cout << "Cod. Inv" << "          " << "Descripcion" << "        " << "monto" << endl;
	for (i=0; i<cont4; i++)
	{
		//cout << inv_total[i].cod << "          " << inv_total[i].desc << "         " << inv_total[i].monto << endl;
		
	}
}
