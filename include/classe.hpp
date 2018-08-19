#ifndef CLASSE_H
#define CLASSE_H

#include <iostream>
#include <vector>
#include <metodo.hpp>
#include <relacionamento.hpp>

struct Atributo
{
    std::string nome;
    std::string tipo;
};

class Classe
{
    public:

       /**
       * Construtor de Classe
       * @param nome: nome da classe que sera construida
       * @param ehClasseBase: indica se eh classe base ou nao
       */
        Classe(std::string nome, bool ehClasseBase);

       /**
       * Adiciona um metodo novo na classe
       * @param nome: nome do metodo que sera adicionado
       * @param tipo: tipo do metodo que sera adicionado
       */
        void adicionarMetodo(std::string nome, std::string tipo);

       /**
       * Adiciona um atributo novo na classe
       * @param nome: nome do atributo que sera adicionado
       * @param tipo: tipo do atributo que sera adicionado
       */
        void adicionarAtributo(std::string nome, std::string tipo);

       /**
       * Adiciona um relacionamento novo na classe
       * @param tipo: tipo de relacionamento que sera adicionado
       * @param classeRelacionada: indica com qual classe sera o relacionamento
       */
        bool adicionarRelacionamento(TipoRelacionamento tipo, Classe classeRelacionada);

       /**
       * Adiciona um parametro em um método da da classe
       * @param nomeMetodo: nome do metodo que sera adicionado um parametro
       * @param nomeParametro: nome do parametro que sera adicionado
       * @param tipoParametro: tipo do parametro que sera adicionado
       */
        bool adicionaParametro(std::string nomeMetodo, std::string nomeParametro, std::string tipoParametro);

       /**
       * Retorna um metodo de classe
       * @param posicao: posicao do vetor de metodos que contem esse metodo
       */
        const Metodo getMetodo(unsigned int posicao);

       /**
       * Retorna um atributo de classe
       * @param posicao: posicao do vetor de atributos que contem esse atributo
       */
        const Atributo getAtributo(unsigned int posicao);

       /**
       * Retorna um relacionamento de classe
       * @param posicao: posicao do vetor de relacionamentos que contem esse relacionamento
       */
        const Relacionamento getRelacionamento(unsigned int posicao);

       /**
       * Retorna o nome da classe
       */
        std::string getNome() const;

       /**
       * Retorna se a classe eh base ou nao
       */
        bool getBase() const;

       /**
       * Retorna a quantidade de metodos da classe
       */
        unsigned int getQtdMetodos() const;

       /**
       * Retorna a quantidade de atributos da classe
       */
        unsigned int getQtdAtributos() const;

       /**
       * Retorna a quantidade de relacionamentos da classe
       */
        unsigned int getQtdRelacionamentos() const;

    private:
        std::vector<Metodo> m_metodos;
        std::vector<Relacionamento> m_relacionamentos;
        std::vector<Atributo> m_atributos;
        std::string m_nome;
        bool m_base;
};

#endif // CLASSE_H
