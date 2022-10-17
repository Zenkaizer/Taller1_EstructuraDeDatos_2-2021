#include "Requerimientos.h"

Requerimientos::Requerimientos()
{
	this->matrizInicial = nullptr;
	this->matrizNotas = nullptr;
	this->matrizFiltrada = nullptr;
}

void Requerimientos::iniciarMatrices()
{
	this->matrizInicial = new MPP(25, 9);
	this->matrizNotas = new MPP(25, 9);
	this->matrizFiltrada = new MPP(25, 9);
}

bool Requerimientos::existeRut(string rut)
{
	if (this->matrizNotas->buscarNodoEstudiante(this->matrizNotas->buscarEstudiante(rut)) != nullptr)
	{
		return true;
	}

	return false;
}

template <typename T>
string Requerimientos::to_string_con_precision(const T a_value)
{
	ostringstream out;
	out.precision(1);
	out << fixed << a_value;
	return out.str();
}

int Requerimientos::totalEstudiantes()
{
	int totalEstudiantes = 0;

	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 26; j++)
		{
			Nodo* aux = this->matrizNotas->obtenerNodoEstudiantePosicion(j, i);

			if (aux != nullptr)
			{
				totalEstudiantes++;
			}
		}
	}
	return totalEstudiantes;
}

void Requerimientos::añadirEstudianteSistema(string nombre, string rut, float nota1, float nota2, float nota3, bool aprueba, int paralelo, int nLista)
{
	this->matrizInicial->añadirEstudiante(new Estudiante(nombre, rut, nota1, nota2, nota3, aprueba, paralelo, nLista), nLista, paralelo);
	this->matrizFiltrada->añadirEstudiante(new Estudiante(nombre, rut, nota1, nota2, nota3, aprueba, paralelo, nLista), nLista, paralelo);
	this->matrizNotas->añadirEstudiante(new Estudiante(nombre, rut, nota1, nota2, nota3, aprueba, paralelo, nLista), nLista, paralelo);
}

bool Requerimientos::registrarNota(string rut, float notaNueva, string nota)
{
	Estudiante* estudiante = this->matrizNotas->buscarNodoEstudiante(this->matrizNotas->buscarEstudiante(rut))->getEstudiante();

	if (estudiante == nullptr)
	{
		return false;
	}

	if (nota == "1")
	{
		if (estudiante->getNota1() == 1.0)
		{
			estudiante->setNota1(notaNueva);
			estudiante = nullptr;
			return true;
		}
	}
	else if (nota == "2")
	{
		if (estudiante->getNota2() == 1.0)
		{
			estudiante->setNota2(notaNueva);
			estudiante = nullptr;
			return true;
		}
	}
	else if (nota == "3")
	{
		if (estudiante->getNota3() == 1.0)
		{
			estudiante->setNota3(notaNueva);
			estudiante = nullptr;
			return true;
		}
	}
	return false;
}

void Requerimientos::estudiantesReprobando()
{
	int* datos = new int[9];

	for (int i = 1; i < 10; i++)
	{
		int cantidadReprobados = 0;

		for (int j = 1; j < 26; j++)
		{
			Nodo* aux = this->matrizInicial->obtenerNodoEstudiantePosicion(j, i);

			if (aux != nullptr)
			{
				if (!aux->getEstudiante()->getEstado())
				{
					cantidadReprobados++;
				}
			}
		}

		datos[i - 1] = cantidadReprobados;
	}

	cout << "La cantidad de estudiantes reprobados por taller son: " << endl;
	for (int i = 0; i < 9; i++)
	{
		cout << "Paralelo " << i + 1<< ": " << datos[i] << " Estudiantes reprobados." << endl;
	}
}

void Requerimientos::porcentajeRepruebanCursoTxt()
{
	double totalReprobados = 0.0;
	double totalEstudiantes = 0.0;

	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 26; j++)
		{
			Nodo* aux = this->matrizInicial->obtenerNodoEstudiantePosicion(j, i);
			if (aux != nullptr)
			{
				totalEstudiantes++;

				if (!aux->getEstudiante()->getEstado())
				{
					totalReprobados++;
				}
				else if (aux->getEstudiante()->promedioCatedra() < 3.4)
				{
					totalReprobados++;
				}
				else if (3.4 <= aux->getEstudiante()->promedioCatedra() && aux->getEstudiante()->promedioCatedra() < 3.95)
				{
					totalReprobados++;
				}
			}
		}
	}

	double resultado = totalReprobados / totalEstudiantes * 100;

	cout << "\nEl porcentaje de reprobados es de: " << resultado << "%\n" << endl;
}

void Requerimientos::porcentajeRepruebanCursoSistema()
{
	double totalReprobados = 0.0;
	double totalEstudiantes = 0.0;

	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 26; j++)
		{
			Nodo* aux = this->matrizNotas->obtenerNodoEstudiantePosicion(j, i);
			if (aux != nullptr)
			{
				totalEstudiantes++;

				if (!aux->getEstudiante()->getEstado())
				{
					totalReprobados++;
				}
				else if (aux->getEstudiante()->promedioCatedra() < 3.4)
				{
					totalReprobados++;
				}
				else if (3.4 <= aux->getEstudiante()->promedioCatedra() && aux->getEstudiante()->promedioCatedra() < 3.95)
				{
					totalReprobados++;
				}
			}
		}
	}

	double resultado = totalReprobados / totalEstudiantes * 100;

	cout << "\nEl porcentaje de reprobados del sistema es de: " << resultado << "%\n" << endl;
}

void Requerimientos::promedioFinalCatedraEstudiantesTxt()
{
	string* nombre = new string[totalEstudiantes()];
	string* nota = new string[totalEstudiantes()];
	string* estado = new string[totalEstudiantes()];

	int pos = 0;

	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 26; j++)
		{
			Nodo* aux = this->matrizInicial->obtenerNodoEstudiantePosicion(j, i);

			if (aux != nullptr)
			{
				nombre[pos] = aux->getEstudiante()->getNombre();
				nota[pos] = to_string_con_precision(aux->getEstudiante()->promedioCatedra());

				if (aux->getEstudiante()->getEstado())
				{
					if (aux->getEstudiante()->promedioCatedra() < 3.4) 
					{
						estado[pos] = "Reprueba";
					}

					else if (3.4 <= aux->getEstudiante()->promedioCatedra() && aux->getEstudiante()->promedioCatedra() < 3.95)
					{
						estado[pos] = "Examen";
					}
					else 
					{
						estado[pos] = "Aprueba";
					}
				}
				else 
				{
					estado[pos] = "Reprueba";
				}
				pos++;
			}
		}
	}

	cout << "Los promedios finales de catedra son: " << endl;
	for (int i = 0; i < totalEstudiantes(); i++)
	{
		cout << nombre[i] << ", Nota final de catedra: " << nota[i] << ", El estudiante: " << estado[i] << endl;
	}
}

void Requerimientos::promedioFinalCatedraEstudiantesSistema()
{
	string* nombre = new string[totalEstudiantes()];
	string* nota = new string[totalEstudiantes()];
	string* estado = new string[totalEstudiantes()];

	int pos = 0;

	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 26; j++)
		{
			Nodo* aux = this->matrizNotas->obtenerNodoEstudiantePosicion(j, i);

			if (aux != nullptr)
			{
				nombre[pos] = aux->getEstudiante()->getNombre();
				nota[pos] = to_string_con_precision(aux->getEstudiante()->promedioCatedra());

				if (aux->getEstudiante()->getEstado())
				{
					if (aux->getEstudiante()->promedioCatedra() < 3.4)
					{
						estado[pos] = "Reprueba";
					}

					else if (3.4 <= aux->getEstudiante()->promedioCatedra() && aux->getEstudiante()->promedioCatedra() < 3.95)
					{
						estado[pos] = "Examen";
					}
					else
					{
						estado[pos] = "Aprueba";
					}
				}
				else
				{
					estado[pos] = "Reprueba";
				}
				pos++;
			}
		}
	}

	cout << "Los promedios finales de catedra son: " << endl;
	for (int i = 0; i < totalEstudiantes(); i++)
	{
		cout << nombre[i] << ", Nota final de catedra: " << nota[i] << ", El estudiante: " << estado[i] << endl;
	}
}

void Requerimientos::filtrarMatrizSistema()
{
	this->matrizFiltrada->filtrarMatrizFiltrada();
}

void Requerimientos::guardarDatos()
{
	ofstream archivoSalida;

	archivoSalida.open("estudiantesSalida.txt", ios::out);

	if (archivoSalida.fail())
	{
		cout << "No se pudo abrir el archivo";
	}
 
	for (int i = 1; i < 26; i++)
	{
		for (int j = 1; j < 10; j++)
		{

			Estudiante* aux = this->matrizNotas->obtenerEstudiantePosicion(i, j);

			if (aux != nullptr)
			{
				archivoSalida << aux->toString() << endl;
			}
		}
	}
	archivoSalida.close();
}