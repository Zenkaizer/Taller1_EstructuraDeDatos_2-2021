#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "MPP.h"
using namespace std;
/// <summary>
/// Clase encargada de los requerimientos del sistema.
/// </summary>
class Requerimientos
{
private:
	/// <summary>
	/// Corresponde a la matriz con los datos originales.
	/// </summary>
	MPP* matrizInicial;
	/// <summary>
	/// Corresponde a la matriz con las notas nuevas.
	/// </summary>
	MPP* matrizNotas;
	/// <summary>
	/// Corresponde a la matriz con los datos filtrados.
	/// </summary>
	MPP* matrizFiltrada;

public:
	/// <summary>
	/// Constructor de la clase requerimientos.
	/// </summary>
	Requerimientos();
	/// <summary>
	/// Destructor de la clase requerimientos.
	/// </summary>
	~Requerimientos() = default;
	/// <summary>
	/// Metodo que se encarga de iniciar las matrices del sistema.
	/// </summary>
	void iniciarMatrices();
	/// <summary>
	/// Metodo que busca si existe un rut en el sistema.
	/// </summary>
	/// <param name="rut">RUT del estudiante.</param>
	/// <returns>"true" si el estudiante existe y "false" si no.</returns>
	bool existeRut(string rut);
	/// <summary>
	/// Metodo que transforma el numero de las notas del estudiante a 1 decimal.
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="a_value">Dato a transformar.</param>
	/// <returns>Dato con un decimal.</returns>
	template <typename T>
	string to_string_con_precision(const T a_value);
	/// <summary>
	/// Metodo que calcula el total de estudiantes del sistema.
	/// </summary>
	/// <returns>Total de estudiantes del sistema.</returns>
	int totalEstudiantes();
	/// <summary>
	/// Metodo que añade un estudiante a las matrices del sistema.
	/// </summary>
	/// <param name="nombre">Nombre del estudiante.</param>
	/// <param name="rut">RUT del estudiante.</param>
	/// <param name="nota1">Nota de catedra 1 del estudiante.</param>
	/// <param name="nota2">Nota de catedra 2 del estudiante.</param>
	/// <param name="nota3">Nota de catedra 3 del estudiante.</param>
	/// <param name="aprueba">Estado de aprobacion del estudiante.</param>
	/// <param name="paralelo">Numero de paralelo del estudiante.</param>
	/// <param name="nLista">Numero de lista del estudiante.</param>
	void añadirEstudianteSistema(string nombre, string rut, float nota1, float nota2, float nota3, bool aprueba, int paralelo, int nLista);
	/// <summary>
	/// Metodo que cambia la nota del estudiante.
	/// </summary>
	/// <param name="rut">RUT del estudiante.</param>
	/// <param name="notaNueva">Nueva nota del estudiante.</param>
	/// <param name="nota">Numero de catedra a cambiar.</param>
	/// <returns></returns>
	bool registrarNota(string rut, float notaNueva, string nota);
	/// <summary>
	/// Metodo que calcula la cantidad de estudiantes por cada paralelo que estan reprobando el taller.
	/// </summary>
	void estudiantesReprobando();
	/// <summary>
	/// Metodo que calcula el porcentaje de estudiantes que se encuentran sin aprobar el curso.
	/// </summary>
	void porcentajeRepruebanCursoTxt();
	/// <summary>
	/// Metodo que calcula el porcentaje de estudiantes que se encuentran sin aprobar el curso con los datos ingresados por el sistema.
	/// </summary>
	void porcentajeRepruebanCursoSistema();
	/// <summary>
	/// Metodo que calcula el promedio de catedra para cada estudiante y si aprueba, reprueba o va a examen.
	/// </summary>
	void promedioFinalCatedraEstudiantesTxt();
	/// <summary>
	/// Metodo que calcula el promedio de catedra para cada estudiante y si aprueba, reprueba o va a examen con los datos del sistema.
	/// </summary>
	void promedioFinalCatedraEstudiantesSistema();
	/// <summary>
	/// Metodo que busca si existen las matrices en el sistema.
	/// </summary>
	/// <returns>"true" si existen las matrices en el sistema y "false" si no.</returns>
	bool existeMatriz() { return matrizInicial != nullptr; }
	/// <summary>
	/// Metodo que elimina a los estudiantes con taller reprobado.
	/// </summary>
	void filtrarMatrizSistema();
	/// <summary>
	/// Metodo que guarda los datos en un nuevo archivo txt.
	/// </summary>
	void guardarDatos();
};