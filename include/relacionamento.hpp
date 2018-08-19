#ifndef RELACIONAMENTO_H
#define RELACIONAMENTO_H

#include <iostream>

enum TipoRelacionamento
{
    HERANCA,
    COMPOSICAO,
    AGREGACAO,
    ASSOCIACAO,
    ERRO
};

class Relacionamento
{
    public:

       /**
       * Construtor de relacionamento
       * @param tipo: tipo de relacionamento que sera construido
       * @param classeRelacionada: classe que sera relacionada neste relacionamento
       */
        Relacionamento(TipoRelacionamento tipo, std::string classeRelacionada);

       /**
       * Retorno o tipo do relacionamento
       */
        TipoRelacionamento getTipo() const;

       /**
       * Retorna o nome da classe que está sendo relacionada
       */
        std::string getNomeClasseRelacionada() const;

    private:
        TipoRelacionamento m_tipo;
        std::string m_nomeClasseRelacionada;
};

#endif // RELACIONAMENTO_H
