#pragma once
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
/// <summary>
/// Clase encargada de la entidad Estudiante.
/// </summary>
class Estudiante
{
private:
	/// <summary>
	/// Nombre del estudiante.
	/// </summary>
	string nombre;
	/// <summary>
	/// RUT del estudiante.
	/// </summary>
	string rut;
	/// <summary>
	/// Nota de la catedra 1 del estudiante.
	/// </summary>
	float nota1;
	/// <summary>
	/// Nota de la catedra 2 del estudiante.
	/// </summary>
	float nota2;
	/// <summary>
	/// Nota de la catedra 3 del estudiante.
	/// </summary>
	float nota3;
	/// <summary>
	/// Estado de aprobacion del estudiante.
	/// </summary>
	bool estado;
	/// <summary>
	/// Numero de paralelo del estudiante.
	/// </summary>
	int paralelo;
	/// <summary>
	/// Numero de lista del estudiante.
	/// </summary>
	int lista;

public:
	/// <summary>
	/// Constructor de la clase estudiante.
	/// </summary>
	/// <param name="nombre">Nombre del estudiante.</param>
	/// <param name="rut">RUT del estudiante.</param>
	/// <param name="nota1">Nota de la catedra 1 del estudiante.</param>
	/// <param name="nota2">Nota de la catedra 2 del estudiante.</param>
	/// <param name="nota3">Nota de la catedra 3 del estudiante.</param>
	/// <param name="estado">Estado de aprobacion del estudiante.</param>
	/// <param name="paralelo">Numero de paralelo del estudiante.</param>
	/// <param name="lista">Numero de lista del estudiante.</param>
	Estudiante(string nombre, string rut, float nota1, float nota2, float nota3, bool estado, int paralelo, int lista);
	/// <summary>
	/// Destructor de la clase estudiante.
	/// </summary>
	~Estudiante() = default;
	/// <summary>
	/// Metodo que obtiene el nombre del estudiante.
	/// </summary>
	/// <returns>Nombre del estudiante.</returns>
	string getNombre() { return this->nombre; }
	/// <summary>
	/// Metodo que obtiene el RUT del estudiante.
	/// </summary>
	/// <returns>RUT del estudiante.</returns>
	string getRut() { return this->rut; }
	/// <summary>
	/// Metodo que obtiene la nota de catedra 1 del estudiante.
	/// </summary>
	/// <returns>Nota de catedra 1 del estudiante.</returns>
	float getNota1() { return this->nota1; }
	/// <summary>
	/// Metodo que obtiene la nota de catedra 2 del estudiante.
	/// </summary>
	/// <returns>Nota de catedra 2 del estudiante.</returns>
	float getNota2() { return this->nota2; }
	/// <summary>
	/// Metodo que obtiene la nota de catedra 3 del estudiante.
	/// </summary>
	/// <returns>Nota de catedra 3 del estudiante.</returns>
	float getNota3() { return this->nota3; }
	/// <summary>
	/// Metodo que obtiene el estado de aprobacion del estudiante.
	/// </summary>
	/// <returns>"true" si el estudiante aprueba el taller y "false" si no.</returns>
	bool getEstado() { return this->estado; }
	/// <summary>
	/// Metodo que obtiene el numero de paralelo del estudiante.
	/// </summary>
	/// <returns>Numero de paralelo del estudiante.</returns>
	int getParalelo() { return this->paralelo; }
	/// <summary>
	/// Metodo que obtiene el numero de lista del estudiante.
	/// </summary>
	/// <returns>Numero de lista del estudiante.</returns>
	int getLista() { return this->lista; }
	/// <summary>
	/// Metodo que cambia la nota de catedra 1 del estudiante.
	/// </summary>
	/// <param name="nota1">Nota de catedra 1.</param>
	void setNota1(float nota1) { this->nota1 = nota1; }
	/// <summary>
	/// Metodo que cambia la nota de catedra 2 del estudiante.
	/// </summary>
	/// <param name="nota2">Nota de catedra 2.</param>
	void setNota2(float nota2) { this->nota2 = nota2; }
	/// <summary>
	/// Metodo que cambia la nota de catedra 3 del estudiante.
	/// </summary>
	/// <param name="nota3">Nota de catedra 3.</param>
	void setNota3(float nota3) { this->nota3 = nota3; }
	/// <summary>
	/// Metodo que cambia el estado de aprobacion del taller del estudiante.
	/// </summary>
	/// <param name="estado">Estado de aprobacion del taller del estudiante.</param>
	void setEstado(bool estado) { this->estado = estado; }
	/// <summary>
	/// Metodo que transforma el numero de las notas del estudiante a 1 decimal.
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="a_value">Dato a transformar.</param>
	/// <returns>Dato con un decimal.</returns>
	template <typename T>
	string to_string_con_precision(const T a_value);
	/// <summary>
	/// Metodo que transforma los datos del estudiante a un string.
	/// </summary>
	/// <returns>Datos del estudiante.</returns>
	string toString();

	double promedioCatedra() { return (this->nota1 * 0.3) + (this->nota2 * 0.4) + (this->nota3 * 0.3); }

};