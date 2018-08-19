#include "unittest.hpp"

UnitTest::UnitTest()
{
}

std::vector<bool> UnitTest::run()
{
    std::vector<bool> resultado;
    GeradorCpp::Gerador gerador1;
    GeradorCpp::Gerador gerador2;
    GeradorCpp::Gerador gerador3;
    GeradorCpp::Gerador gerador4;
    GeradorCpp::Gerador gerador5;
    GeradorCpp::Gerador gerador6;
    GeradorCpp::Gerador gerador7;
    std::string esperada1 = "class Teste1\n{\npublic:\nprivate:\n};\n\n";
    std::string esperada2 = "Teste2";
    std::string esperada3 = "class Teste3\n{\npublic:\nprivate:\n\tint atributo3;\n};\n\n";
    std::string esperada4 = "class Teste4\n{\npublic:\n\tint metodo4();\nprivate:\n};\n\n";
    std::string esperada5 = "class Teste5\n{\npublic:\n\tint metodo5(int parametro5);\nprivate:\n};\n\n";
    std::string esperada6 = "class Teste6: public Herdada\n{\npublic:\nprivate:\n};\n\nclass Herdada\n{\npublic:\nprivate:\n};\n\n";
    std::string esperada7 = "class Teste7\n{\npublic:\nprivate:\n\tComposicao m_Composicao;\n};\n\nclass Composicao\n{\npublic:\nprivate:\n};\n\n";

    //Teste 1 : Adicionar Classe
    gerador1.adicionarClasse("Teste1", false);
    if(gerador1.gerarCodigo() != esperada1) {
        resultado.push_back(false);
        return resultado;
    } else {
        resultado.push_back(true);
    }

    //Teste 2 : Retornar Classe
    gerador2.adicionarClasse("Teste2", false);
    if(gerador2.getClassePorNome("Teste2")->getNome() != esperada2) {
        resultado.push_back(false);
        return resultado;
    } else {
        resultado.push_back(true);
    }

    //Teste 3 : Adicionar Atributo
    gerador3.adicionarClasse("Teste3", false);
    gerador3.getClassePorNome("Teste3")->adicionarAtributo("atributo3", "int");
    if(gerador3.gerarCodigo() != esperada3) {
        resultado.push_back(false);
        return resultado;
    } else {
        resultado.push_back(true);
    }

    //Teste 4 : Adicionar Metodo
    gerador4.adicionarClasse("Teste4", false);
    gerador4.getClassePorNome("Teste4")->adicionarMetodo("metodo4", "int");
    if(gerador4.gerarCodigo() != esperada4) {
        resultado.push_back(false);
        return resultado;
    } else {
        resultado.push_back(true);
    }

    //Teste 5 : Adicionar Parametros ao Metodo
    gerador5.adicionarClasse("Teste5", false);
    gerador5.getClassePorNome("Teste5")->adicionarMetodo("metodo5", "int");
    gerador5.getClassePorNome("Teste5")->adicionaParametro("metodo5", "parametro5", "int");
    if(gerador5.gerarCodigo() != esperada5) {
        resultado.push_back(false);
        return resultado;
    } else {
        resultado.push_back(true);
    }

    //Teste 6 : Adicionar Heranca
    gerador6.adicionarClasse("Teste6", false);
    gerador6.adicionarClasse("Herdada", true);
    gerador6.getClassePorNome("Teste6")->adicionarRelacionamento(HERANCA, *gerador6.getClassePorNome("Herdada"));
    if(gerador6.gerarCodigo() != esperada6) {
        resultado.push_back(false);
        return resultado;
    } else {
        resultado.push_back(true);
    }

    //Teste 7 : Adicionar Composicao
    gerador7.adicionarClasse("Teste7", false);
    gerador7.adicionarClasse("Composicao", false);
    gerador7.getClassePorNome("Teste7")->adicionarRelacionamento(COMPOSICAO, *gerador7.getClassePorNome("Composicao"));
    if(gerador7.gerarCodigo() != esperada7) {
        resultado.push_back(false);
        return resultado;
    } else {
        resultado.push_back(true);
    }

    return resultado;
}

int main()
{
    UnitTest test;
    unsigned int i;
    std::vector<bool> teste = test.run();
    for(i = 0; i < teste.size(); ++i) {
        if(!teste[i]) {
            break;
        }
    }
    std::cout << ":\n" << ":OK (" << i << ")" << std::endl;
    return 0;
}
