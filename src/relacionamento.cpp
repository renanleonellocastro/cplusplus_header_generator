#include "relacionamento.hpp"

Relacionamento::Relacionamento(TipoRelacionamento tipo, std::string classeRelacionada) :
    m_tipo(tipo), m_nomeClasseRelacionada(classeRelacionada)
{
}

TipoRelacionamento Relacionamento::getTipo() const
{
    return m_tipo;
}

std::string Relacionamento::getNomeClasseRelacionada() const
{
    return m_nomeClasseRelacionada;
}
