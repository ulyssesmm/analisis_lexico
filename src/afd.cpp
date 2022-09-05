#include "afd.hpp"


Afd::Afd(string filename)
{
    open_file(filename);
    //TODO: Agregar las transiciones de acuerdo a la tabla obtenida en clase
    afd = {
        
    };

    // TODO: Agregar las columnas para los símbolos
    cols = {
        
    };

    // TODO: Agregar los estados de aceptación
    accept = {

    };
}

TOKEN Afd::yylex()
{
    edo = 0;        
    string buffer="";
    map<int, int>::iterator row;
    map<int, bool>::iterator acc;    
    map<char, int>::iterator col;
    while(true){
        col = cols.find(c);
        row = afd[edo].find(col->second);
        if(c==EOF) return FIN;
        if(row != afd[edo].end()){
            buffer += c;
            edo = row->second;
            c = get_char();            
        }else{
            acc = accept.find(edo);
            //c = d;
            if(acc != accept.end()){
                if(acc->second){
                    token_value = buffer;
                    switch (edo)
                    {
                    // TODO: Agregar los casos para que se retornen correctamente los tokens
                    case 1:                        
                        //return CADENA;
                    
                    }
                }
            }else
                return ERROR;            
        }
    }
}
string Afd::get_token_value()
{

}
void Afd::error(string msg)
{
    cout<<msg<<endl;
    close_file();
    exit(EXIT_FAILURE);
}

void Afd::close_file(){
    if(file.is_open()) file.close();
}

char Afd::get_char()
{
    if(!file.eof()){
        return file.get();
    }
    return EOF;
}

void Afd::open_file(string filename)
{
    file.open(filename, ios::in);
    if(!file.is_open()) error("El archivo no se encuentra");
}