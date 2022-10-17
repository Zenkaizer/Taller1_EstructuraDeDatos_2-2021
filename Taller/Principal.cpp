#include "Principal.h"

Principal::Principal()
{
    this->requerimientos = new Requerimientos();
}

void Principal::leerArchivos()
{
    if (this->requerimientos->existeMatriz())
    {
        cout << "\nLOS DATOS YA HAN SIDO CARGADOS EN EL SISTEMA.\n" << endl;
        return;
    }
    else
    {
        cout << "\nDATOS CARGADOS EXITOSAMENTE... VOLVIENDO AL MENU ANTERIOR...\n" << endl;
    }

    ifstream archivo("estudiantes.txt");
    string linea;

    if (archivo.fail()) { //comprobacion por si las moscas
        cout << "no se pudo abrir";
        exit(1);
    }

    this->requerimientos->iniciarMatrices();

    while (getline(archivo, linea)) {

        stringstream stream(linea);

        string nombre;
        string rut;
        string nota1;
        string nota2;
        string nota3;
        string aprueba;
        string paralelo;
        string nLista;

        getline(stream, nombre, ',');
        getline(stream, rut, ',');
        getline(stream, nota1, ',');
        getline(stream, nota2, ',');
        getline(stream, nota3, ',');
        getline(stream, aprueba, ',');
        getline(stream, paralelo, ',');
        getline(stream, nLista, ',');

        rut.erase(remove_if(rut.begin(), rut.end(), ::isspace), rut.end()); //le quita los espacios al inicio
        aprueba.erase(remove_if(aprueba.begin(), aprueba.end(), ::isspace), aprueba.end()); //le quita los espacios al inicio

        transform(aprueba.begin(), aprueba.end(), aprueba.begin(), ::toupper);

        bool apruebaB;

        if (aprueba == "VERDADERO")
        {
            apruebaB = true;
        }
        else
        {
            apruebaB = false;
        }
        
        this->requerimientos->añadirEstudianteSistema(nombre, rut, stof(nota1), stof(nota2), stof(nota3), apruebaB, stoi(paralelo), stoi(nLista));
    }
    archivo.close();
}

void Principal::registrarNota()
{    
    if (!this->requerimientos->existeMatriz())
    {
        cout << "\nNO EXISTEN DATOS, PORFAVOR CARGUE LOS DATOS EN EL SISTEMA.\n" << endl;

        return;
    }

    string nota;
    string rut;
    string notaNuevaStr;
    float notaNueva;

    cout << ("--------->Registrar Nota Recuperativa<---------") << endl;
    cout << ("Ingrese el RUT del estudiante (Con . y -): ");
    getline(cin, rut);

    while (!this->requerimientos->existeRut(rut))
    {
        cout << ("Ha ocurrido un error al ingresar el rut, intentelo nuevamente.") << endl;
        cout << ("Ingrese el RUT del estudiante (Con . y -): ");
        getline(cin, rut);
    }


    cout << ("Ingrese el numero de la nota de catedra a cambiar: ");
    getline(cin, nota);

    int notaInt;
    while (true)
    {
        try
        {
            notaInt = stoi(nota);
            if (1 <= notaInt && notaInt <= 3)
            {
                break;
            }
            else 
            {
                cout << ("Ha ocurrido un error al seleccionar la catedra, intentelo nuevamente.") << endl;
                cout << ("Ingrese el numero de la nota de catedra a cambiar: ");
                getline(cin, nota);
            }
        }
        catch (...)
        {
            cout << ("Ha ocurrido un error al seleccionar la catedra, intentelo nuevamente.") << endl;
            cout << ("Ingrese el numero de la nota de catedra a cambiar: ");
            getline(cin, nota);
        }
    }

    cout << ("Ingrese la nota recuperativa: ");
    getline(cin, notaNuevaStr);

    while (true)
    {
        try
        {
            notaNueva = stof(notaNuevaStr);
            if (1.0 <= notaNueva && notaNueva <= 7.0)
            {
                break;
            }
            else
            {
                cout << ("Ha ingresado una nota invalida, por favor ingresela nuevamente.");
                cout << ("Ingrese la nota recuperativa: ");
                getline(cin, notaNuevaStr);
            }
        }
        catch (...)
        {
            cout << ("Ha ingresado una nota invalida, por favor ingresela nuevamente.");
            cout << ("Ingrese la nota recuperativa: ");
            getline(cin, notaNuevaStr);
        }
    }

    bool exito = this->requerimientos->registrarNota(rut, notaNueva, nota);

    if (exito)
    {
        cout << "\nEL CAMBIO FUE EXITOSO!.\n" << endl;
    }
}

void Principal::generarEstadisticas()
{
    if (!this->requerimientos->existeMatriz())
    {
        cout << "\nNO EXISTEN DATOS, PORFAVOR CARGUE LOS DATOS EN EL SISTEMA.\n" << endl;

        return;
    }

    int opcion = 0;

    while (opcion != 4)
    {
        int opcionInt;
        string opcionStr = "";

        cout << ("--------->Menu Generar Estadisticas<---------") << endl;
        cout << ("[1] Estudiantes por paralelo reprobando el taller.") << endl;
        cout << ("[2] Porcentaje de estudiantes que no aprueban el curso.") << endl;
        cout << ("[3] Promedio final de Catedra para cada estudiante.") << endl;
        cout << ("[4] Volver al menu anterior.") << endl;
        cout << ("Ingrese una opcion: ");
        getline(cin, opcionStr);
        opcionStr.erase(remove_if(opcionStr.begin(), opcionStr.end(), ::isspace), opcionStr.end());

        while (true)
        {
            try
            {
                opcionInt = stoi(opcionStr);
                if (1 <= opcionInt && opcionInt <=4)
                {
                    break;
                }
                else 
                {
                    cout << "\nHa ocurrido un error al seleccionar la opcion, intenta nuevamente.\n" << endl;
                    cout << ("--------->Menu Generar Estadisticas<---------") << endl;
                    cout << ("[1] Estudiantes por paralelo reprobando el taller.") << endl;
                    cout << ("[2] Porcentaje de estudiantes que no aprueban el curso.") << endl;
                    cout << ("[3] Promedio final de Catedra para cada estudiante.") << endl;
                    cout << ("[4] Volver al menu anterior.") << endl;
                    cout << ("Ingrese una opcion: ");
                    getline(cin, opcionStr);
                    opcionStr.erase(remove_if(opcionStr.begin(), opcionStr.end(), ::isspace), opcionStr.end());
                }
            }
            catch (...)
            {
                cout << "\nHa ocurrido un error al seleccionar la opcion, intenta nuevamente.\n" << endl;
                cout << ("--------->Menu Generar Estadisticas<---------") << endl;
                cout << ("[1] Estudiantes por paralelo reprobando el taller.") << endl;
                cout << ("[2] Porcentaje de estudiantes que no aprueban el curso.") << endl;
                cout << ("[3] Promedio final de Catedra para cada estudiante.") << endl;
                cout << ("[4] Volver al menu anterior.") << endl;
                cout << ("Ingrese una opcion: ");
                getline(cin, opcionStr);
                opcionStr.erase(remove_if(opcionStr.begin(), opcionStr.end(), ::isspace), opcionStr.end());
            }
        }
        opcion = opcionInt;

        switch (opcion)
        {
        case 1:
            cout << "\n" << endl;
            this->requerimientos->estudiantesReprobando();
            cout << "\n" << endl;
            break;

        case 2:
            cout << "\n" << endl;
            this->requerimientos->porcentajeRepruebanCursoTxt();
            this->requerimientos->porcentajeRepruebanCursoSistema();
            cout << "\n" << endl;
            break;

        case 3:
            cout << "\n" << endl;
            this->requerimientos->promedioFinalCatedraEstudiantesTxt();
            cout << "\n" << endl;
            this->requerimientos->promedioFinalCatedraEstudiantesSistema();
            cout << "\n" << endl;
            break;
        case 4:
            cout << "\nVolviendo al menu anterior...\n" << endl;
            break;
        }
    }
}

void Principal::filtrarMatriz()
{
    if (!this->requerimientos->existeMatriz())
    {
        cout << "\nNO EXISTEN DATOS PREVIOS, PORFAVOR CARGUE LOS DATOS CON LA OPCION 1.\n" << endl;
        return;
    }

    cout << ("--------->Filtrar Matriz<---------") << endl;
    cout << "\nELIMINANDO ESTUDIANTES CON TALLER REPROBADO...\n" << endl;

    this->requerimientos->filtrarMatrizSistema();
}

void Principal::escribirArchivos()
{
    if (!this->requerimientos->existeMatriz())
    {
        cout << "\nNO EXISTEN DATOS, CERRANDO EL PROGRAMA..." << endl;
        cout << "MUCHAS GRACIAS POR USAR EL SISTEMA, ADIOS." << endl;
        return;
    }

    cout << "\nCERRANDO Y GUARDANDO DATOS..." << endl;
    cout << "MUCHAS GRACIAS POR USAR EL SISTEMA, ADIOS." << endl;
    this->requerimientos->guardarDatos();
}

void Principal::menuPrincipal()
{
    int opcion = 0;

    while (opcion != 5) {

        int opcionInt;
        string opcionStr = "";

        cout << ("--------->Menu Prueba Recuperativa Estudiantes de Programacion<---------") << endl;
        cout << ("[1] Cargar datos en el sistema.") << endl;
        cout << ("[2] Registrar nota recuperativa.") << endl;
        cout << ("[3] Generar estadisticas.") << endl;
        cout << ("[4] Filtrar matriz de datos.") << endl;
        cout << ("[5] Salir del sistema.") << endl;
        cout << ("Ingrese una opcion: ");
        getline(cin, opcionStr);
        opcionStr.erase(remove_if(opcionStr.begin(), opcionStr.end(), ::isspace), opcionStr.end());

        while (true) {
            try {
                opcionInt = stoi(opcionStr);
                if (1 <= opcionInt && opcionInt <= 5) {
                    break;
                }
                else {
                    cout << "\nHa ocurrido un error al seleccionar la opcion, intenta nuevamente.\n" << endl;
                    cout << ("--------->Menu Prueba Recuperativa Estudiantes de Programacion<---------") << endl;
                    cout << ("[1] Cargar datos en el sistema.") << endl;
                    cout << ("[2] Registrar nota recuperativa.") << endl;
                    cout << ("[3] Generar estadisticas.") << endl;
                    cout << ("[4] Filtrar matriz de datos.") << endl;
                    cout << ("[5] Salir del sistema.") << endl;
                    cout << ("Ingrese una opcion: ");
                    getline(cin, opcionStr);
                    opcionStr.erase(remove_if(opcionStr.begin(), opcionStr.end(), ::isspace), opcionStr.end());
                }
            }
            catch (...) {
                cout << "\nHa ocurrido un error al seleccionar la opcion, intenta nuevamente.\n" << endl;
                cout << ("--------->Menu Prueba Recuperativa Estudiantes de Programacion<---------") << endl;
                cout << ("[1] Cargar datos en el sistema.") << endl;
                cout << ("[2] Registrar nota recuperativa.") << endl;
                cout << ("[3] Generar estadisticas.") << endl;
                cout << ("[4] Filtrar matriz de datos.") << endl;
                cout << ("[5] Salir del sistema.") << endl;
                cout << ("Ingrese una opcion: ");
                getline(cin, opcionStr);
                opcionStr.erase(remove_if(opcionStr.begin(), opcionStr.end(), ::isspace), opcionStr.end());
            }
        }
        opcion = opcionInt;

        switch (opcion) {

        case 1:
            leerArchivos();
            break;

        case 2:
            registrarNota();
            break;

        case 3:
            generarEstadisticas();
            break;

        case 4:
            filtrarMatriz();
            break;

        case 5:
            escribirArchivos();
            break;

        }
    }
}
