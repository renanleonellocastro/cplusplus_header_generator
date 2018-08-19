#ifndef GERADOR_H
#define GERADOR_H

#include <iostream>
#include <vector>
#include <classe.hpp>

namespace GeradorCpp
{

class Gerador
{
    public:

       /**
       * Construtor de gerador
       */
        Gerador();

       /**
       * Adiciona uma nova classe ao gerador
       * @param nome: nome da classe que sera adicionada
       * @param classeBase: indica se sera classe base ou nao
       */
        void adicionarClasse(std::string nome, bool classeBase);

       /**
       * Gera codigo com todas as classes criadas
       * Retorna uma string com o código gerado
       */
        std::string gerarCodigo();

       /**
       * Retorna uma classe criada
       * @param nome: nome da classe que deseja que seja retornada
       */
        Classe *getClassePorNome(std::string nome);

    private:
        std::vector<Classe> m_classes;
        Classe m_classeErro;
};
}

#endif // GERADOR_H
