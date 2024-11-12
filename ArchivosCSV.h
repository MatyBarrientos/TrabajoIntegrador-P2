#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>


using namespace std;
class ArchivosCSV
{
    private:
        string _nombreArchivo;
        vector<string> _encabezados;

    public:
        ArchivosCSV(string nombreArchivo, vector<string> encabezados);
        virtual ~ArchivosCSV();
        bool escribirFilaCliente();
        bool escribirFilaVendedor();
        bool escribirFilaProdcuto();

};
