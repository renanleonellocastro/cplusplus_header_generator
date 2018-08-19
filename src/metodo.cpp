#include "metodo.hpp"

Metodo::Metodo() : m_nome(""), m_tipoRetorno("")
{
}

void Metodo::adicionarParametro(std::string nome, std::string tipo)
{
    Parametro p;
    p.nome = nome;
    p.tipo = tipo;
    m_parametros.push_back(p);
}

std::string Metodo::getNome() const
{
    return m_nome;
}

std::string Metodo::getTipoRetorno() const
{
    return m_tipoRetorno;
}

unsigned int Metodo::getQtdParametros() const
{
    return m_parametros.size();
}

const Parametro Metodo::getParametro(unsigned int posicao) const
{
    if ((posicao >= 0) && (posicao < m_parametros.size())) {
       return m_parametros[posicao];
    } else {
        Parametro p;
        p.nome = "erro";
        p.tipo = "erro";
        return p;
    }
}

void Metodo::setNome(std::string nome)
{
    m_nome = nome;
}

void Metodo::setTipoRetorno(std::string tipo)
{
    m_tipoRetorno = tipo;
}
