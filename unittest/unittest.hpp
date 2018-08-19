#ifndef UNITTEST_HPP
#define UNITTEST_HPP

#include <../include/gerador.hpp>

#include <vector>

class UnitTest
{
    public:
       /**
       * Construtor de gerador
       */
        UnitTest();

      /**
       * Metodo run para executar testes unitarios
       * Retorna um vetor com as aprovacoes/reprovacoes
       */
        std::vector<bool> run();

    private:

};

#endif // UNITTEST_HPP
