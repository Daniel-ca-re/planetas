#include "txtinfo.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

txtinfo::txtinfo()
{

}

txtinfo::txtinfo(std::string donde)
{
    txt=donde;
    std::string data="";

    // Abre el archivo en modo lectura
    ifstream infile;

    // Se pone de manera explicita la ruta relativa donde se encuentra el archivo
    infile.open(donde);

    // Se comprueba si el archivo fue abierto exitosamente
    if (!infile.is_open())
    {
      cout << "Error abriendo el archivo" << endl;
      exit(1);
    }
    string x;
    auto i= info.begin();
    do
    {
        x=data;
        infile >> data;
        cout << data << endl;
        if (data!="")
        {
            std::vector<float> resultado;

            std::string::const_iterator itBegin = x.begin();
            std::string::const_iterator itEnd   = x.end();

            int numItems = 1;
            for( std::string::const_iterator it = itBegin; it!=itEnd; ++it )
              numItems += *it==',';

            resultado.reserve(numItems);

            for( std::string::const_iterator it = itBegin; it!=itEnd; ++it )
            {
              if( *it == ',' )
              {
                resultado.push_back(stof(std::string(itBegin,it)));
                itBegin = it+1;
              }
              else if(it+1==itEnd)
              {
                  resultado.push_back(stof(std::string(itBegin,it+1)));
              }
            }

            if( itBegin != itEnd )
              info.push_back(resultado);
              resultado.clear();


        }
    }
    while(x!=data);



    infile.close();
}

void txtinfo::saveinfo()
{

    // abrir un archivo en modo escritura
    ofstream outfile;

    // Se pone de manera explicita la ruta relativa donde se encuentra el archivo
    outfile.open(txt,ios::out);

    // Se comprueba si el archivo fue abierto exitosamente
    if (!outfile.is_open())
    {
      cout << "Error abriendo el archivo" << endl;
      exit(1);
    }


    for(auto i=info.begin();i!=info.end();i++)
    {
        for(int ii=0;ii!=(*i).size();ii++)
        {
            std::ostringstream x;
            x << (*i)[ii];
            outfile << x.str() ;
            if(ii+1!=(*i).size())
            {
                outfile << ',';
            }
        }
        if(++i!=info.end())
        {
            outfile << '\n';
        }
        i--;

    }
    // Se cierra el archivo
    outfile.close();
}

void txtinfo::add_new_info(std::vector<float> x)
{
    info.push_back(x);
}

std::array<float,2> txtinfo:: txtinfo::getarray(int i,int ii )
{

    std::array<float,2> result;
    auto I= info.begin();
    advance(I,i);
    result[0]=(*I)[ii];
    result[1]=(*I)[ii+1];
    return result;
}
