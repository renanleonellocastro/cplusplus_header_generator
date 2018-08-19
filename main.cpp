#include <iostream>
#include <vector>
#include <gerador.hpp>

using namespace std;

int main()
{
    GeradorCpp::Gerador gerador;

    //classes
    gerador.adicionarClasse("Drawable", true);
    gerador.adicionarClasse("Point", false);
    gerador.adicionarClasse("Figure", true);
    gerador.adicionarClasse("Square", false);

    //atributos
    gerador.getClassePorNome("Square")->adicionarAtributo("m_side","double");

    //metodos
    gerador.getClassePorNome("Drawable")->adicionarMetodo("draw","void");
    gerador.getClassePorNome("Figure")->adicionarMetodo("move","void");
    gerador.getClassePorNome("Square")->adicionarMetodo("setSide","void");

    //parametros
    gerador.getClassePorNome("Drawable")->adicionaParametro("draw","x","int");
    gerador.getClassePorNome("Drawable")->adicionaParametro("draw","y","int");
    gerador.getClassePorNome("Figure")->adicionaParametro("move","position","Point");
    gerador.getClassePorNome("Square")->adicionaParametro("setSide","side","double");

    //relacionamentos
    gerador.getClassePorNome("Figure")->adicionarRelacionamento(HERANCA, *gerador.getClassePorNome("Drawable"));
    gerador.getClassePorNome("Square")->adicionarRelacionamento(HERANCA, *gerador.getClassePorNome("Figure"));

    cout << "Codigo Gerado: "<< endl << endl;
    cout << gerador.gerarCodigo() << endl;
    return 0;
}
