#include "Estudiante.h"

Estudiante::Estudiante(string nombre, string rut, float nota1, float nota2, float nota3, bool estado, int paralelo, int lista)
{
	this->nombre = nombre;
	this->rut = rut;
	this->nota1 = nota1;
	this->nota2 = nota2;
	this->nota3 = nota3;
	this->estado = estado;
	this->paralelo = paralelo;
	this->lista = lista;
}

template <typename T>
string Estudiante::to_string_con_precision(const T a_value)
{
	ostringstream out;
	out.precision(1);
	out << fixed << a_value;
	return out.str();
}

string Estudiante::toString()
{
	string dato = this->nombre + ", " + this->rut + ", " + to_string_con_precision(this->nota1) + ", " + to_string_con_precision(this->nota2) + ", "  + to_string_con_precision(this->nota3) + ", ";

	if (estado)
	{
		dato += "Verdadero, " + to_string(this->paralelo) + ", " + to_string(this->lista);
	}
	else 
	{
		dato += "Falso, " + to_string(this->paralelo) + ", " + to_string(this->lista);
	}

	return dato;
}
