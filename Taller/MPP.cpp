#include "MPP.h"
#include <iostream>
using namespace std;
MPP::MPP()
{
	this->listaFila = nullptr;
	this->listaColumna = nullptr;
 //bonillacp1@gmail.com
}

MPP::MPP(int fila, int columna)
{
	this->listaFila = new Nodo[fila + 1];
	this->listaColumna = new Nodo[columna + 1];

	for (int i = 1; i < fila + 1; i++)
	{
		(this->listaFila + i)->setNodoIzquierda(this->listaFila + i);
		(this->listaFila + i)->setColumna(0);
	}

	for (int i = 1; i < columna + 1; i++)
	{
		(this->listaColumna + i)->setNodoArriba(this->listaColumna + i);
		(this->listaColumna + i)->setFila(0);
	}
}

void MPP::añadirEstudiante(Estudiante* estudiante, int fila, int columna)
{
	Nodo* nuevoNodo = new Nodo(estudiante, fila, columna);

	Nodo* auxFila = &this->listaFila[fila];

	while (columna < auxFila->getNodoIzquierda()->getColumna() && 0 < auxFila->getNodoIzquierda()->getColumna())
	{
		auxFila = auxFila->getNodoIzquierda();
	}

	Nodo* auxColumna = &this->listaColumna[columna];

	while (fila < auxColumna->getNodoArriba()->getFila() && 0 < auxColumna->getNodoArriba()->getFila())
	{
		auxColumna = auxColumna->getNodoArriba();
	}

	nuevoNodo->setNodoIzquierda(auxFila->getNodoIzquierda());
	nuevoNodo->setNodoArriba(auxColumna->getNodoArriba());

	auxFila->setNodoIzquierda(nuevoNodo);
	auxColumna->setNodoArriba(nuevoNodo);
}

Estudiante* MPP::buscarEstudiante(string rut)
{
	if (this->listaColumna == nullptr || this->listaFila == nullptr)
	{
		return nullptr;
	}

	Nodo* aux;

	for (int i = 1; i < 26; ++i)
	{
		aux = this->listaFila + i;

		while (aux->getNodoIzquierda() != this->listaFila + i)
		{
			aux = aux->getNodoIzquierda();
	
			if ((aux->getEstudiante()->getRut()) == rut)
			{
				return aux->getEstudiante();
			}
		}
	}
	return nullptr;
}

Nodo* MPP::buscarNodoEstudiante(Estudiante* estudiante)
{
	if (this->listaColumna == nullptr || this->listaFila == nullptr)
	{
		return nullptr;
	}

	for (int i = 1; i < 26; i++)
	{
		Nodo* aux = listaFila[i].getNodoIzquierda();

		while (aux != &listaFila[i])
		{
			if (aux->getEstudiante()->getRut() == estudiante->getRut())
			{
				return aux;
			}

			aux = aux->getNodoIzquierda();
		}
	}

	return nullptr;
}

void MPP::eliminarEstudiante(Nodo* estudiante)
{
	Nodo* nodoFilaAnterior = &listaFila[estudiante->getFila()];
	Nodo* nodoColumnaAnterior = &listaColumna[estudiante->getColumna()];

	while (nodoFilaAnterior->getNodoIzquierda() != estudiante)
	{
		nodoFilaAnterior = nodoFilaAnterior->getNodoIzquierda();
	}

	while (nodoColumnaAnterior->getNodoArriba() != estudiante)
	{
		nodoColumnaAnterior = nodoColumnaAnterior->getNodoArriba();
	}

	nodoFilaAnterior->setNodoIzquierda(estudiante->getNodoIzquierda());
	nodoColumnaAnterior->setNodoArriba(estudiante->getNodoArriba());

	estudiante->~Nodo();
}

Estudiante* MPP::obtenerEstudiante(string rut)
{
	for (int i = 1; i < 26; i++)
	{
		Nodo* aux = &listaFila[i];

		while (aux->getNodoIzquierda() != &listaFila[i])
		{
			if (aux->getNodoIzquierda()->getEstudiante()->getRut() == rut)
			{
				return aux->getNodoIzquierda()->getEstudiante();
			}
			else 
			{
				aux = aux->getNodoIzquierda();
			}
		}
	}

	return nullptr;
}

Estudiante* MPP::obtenerEstudiantePosicion(int fila, int columna)
{
	if (fila < 1 || fila > 26 || columna > 10 || columna < 1)
	{
		return nullptr;
	}

	Nodo* aux = listaFila[fila].getNodoIzquierda();

	while (aux != &listaFila[fila])
	{
		if (aux->getColumna() == columna)
		{
			return aux->getEstudiante();
		}
		else if (aux->getColumna() < columna) 
		{
			return nullptr;
		}
		aux = aux->getNodoIzquierda();
	}
	return nullptr;
}

Nodo* MPP::obtenerNodoEstudiantePosicion(int fila, int columna)
{
	if (fila < 1 || fila > 26 || columna > 10 || columna < 1)
	{
		return nullptr;
	}

	Nodo* aux = listaFila[fila].getNodoIzquierda();

	while (aux != &listaFila[fila])
	{
		if (aux->getColumna() == columna)
		{
			return aux;
		}
		else if (aux->getColumna() < columna)
		{
			return nullptr;
		}
		aux = aux->getNodoIzquierda();
	}
	return nullptr;
}

void MPP::filtrarMatrizFiltrada()
{
	for (int i = 1; i < 26; i++)
	{
		Nodo* aux = listaFila[i].getNodoIzquierda();

		while (aux != &listaFila[i])
		{
			if (!aux->getEstudiante()->getEstado())
			{
				eliminarEstudiante(aux);
				filtrarMatrizFiltrada();
				return;
			}
			else
			{
				aux = aux->getNodoIzquierda();
			}
		}
	}
}
