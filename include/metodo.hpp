#ifndef METODO_H
#define METODO_H

#include <iostream>
#include <vector>

struct Parametro {
    std::string nome;
    std::string tipo;
};

class Metodo
{
    public:

       /**
       * Construtor de metodo
       */
        Metodo();

      /**
       * Adiciona um novo parametro no metodo
       * @param nome: nome do parametro que sera adicionado
       * @param tipo: tipo do parametro que sera adicionado
       */
        void adicionarParametro(std::string nome, std::string tipo);

       /**
       * Retorna o nome do metodo
       */
        std::string getNome() const;

       /**
       * Retorna o tipo de retorno do metodo
       */
        std::string getTipoRetorno() const;

       /**
       * Retorna a quantidade de parametros que contem no metodo
       */
        unsigned int getQtdParametros() const;

       /**
       * Retorna um parametro do metodo
       * @param posicao: posicao do parametro no vetor de parametros
       */
        const Parametro getParametro(unsigned int posicao) const;

       /**
       * Coloca um nome no metodo
       * @param nome: nome que sera colocado no metodo
       */
        void setNome(std::string nome);

       /**
       * Coloca um valor tipo no tipo de retorno
       * @param tipo: tipo que sera atribuido ao tipo de retorno
       */
        void setTipoRetorno(std::string tipo);

     private:
        std::string m_nome;
        std::string m_tipoRetorno;
        std::vector<Parametro> m_parametros;

};

#endif // METODO_H
