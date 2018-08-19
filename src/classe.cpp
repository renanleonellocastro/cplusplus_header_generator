#include "classe.hpp"

Classe::Classe(std::string nome, bool ehClasseBase) : m_nome(nome), m_base(ehClasseBase)
{
}

void Classe::adicionarMetodo(std::string nome, std::string tipo)
{
    Metodo m;
    m.setNome(nome);
    if (m_base) {
        m.setTipoRetorno("virtual " + tipo);
    } else {
        m.setTipoRetorno(tipo);
    }
    m_metodos.push_back(m);
}

void Classe::adicionarAtributo(std::string nome, std::string tipo)
{
    Atributo a;
    a.nome = nome;
    a.tipo = tipo;
    m_atributos.push_back(a);
}

bool Classe::adicionarRelacionamento(TipoRelacionamento tipo, Classe classeRelacionada)
{
    if (tipo == HERANCA) {
        if (classeRelacionada.getBase()){
            for (unsigned int i = 0; i < classeRelacionada.getQtdMetodos(); ++i) {
                m_metodos.push_back(classeRelacionada.getMetodo(i));
            }
        } else {
            std::cout << "Classe nao pode ser herdada pois não é uma classe Base!" << std::endl;
            return false;
        }
    } else if ((tipo == ASSOCIACAO) || (tipo == AGREGACAO) || (tipo == COMPOSICAO)) {
    } else {
        std::cout << "Tipo de relacionamento não existe! Opcoes = heranca, associacao, agregacao e composicao" << std::endl;
        return false;
    }
    Relacionamento r(tipo, classeRelacionada.getNome());
    m_relacionamentos.push_back(r);
    return true;
}

bool Classe::adicionaParametro(std::string nomeMetodo, std::string nomeParametro, std::string tipoParametro)
{
    unsigned int i;
    bool achou = false;
    for (i = 0; i < m_metodos.size(); ++i) {
        if (m_metodos[i].getNome() == nomeMetodo) {
            achou = true;
            break;
        }
    }
    if (achou) {
        m_metodos[i].adicionarParametro(nomeParametro, tipoParametro);
        return true;
    } else {
        std::cout << "Metodo nao encontrado na classe!" << std::endl;
        return false;
    }
}

std::string Classe::getNome() const
{
    return m_nome;
}

bool Classe::getBase() const
{
    return m_base;
}

unsigned int Classe::getQtdMetodos() const
{
    return m_metodos.size();
}

unsigned int Classe::getQtdAtributos() const
{
    return m_atributos.size();
}

unsigned int Classe::getQtdRelacionamentos() const
{
    return m_relacionamentos.size();
}

const Metodo Classe::getMetodo(unsigned int posicao)
{
    if ((posicao >= 0) && (posicao < m_metodos.size())) {
       return m_metodos[posicao];
    } else {
        Metodo m;
        m.setNome("erro");
        m.setTipoRetorno("erro");
        return m;
    }
}

const Atributo Classe::getAtributo(unsigned int posicao)
{
    if ((posicao >= 0) && (posicao < m_atributos.size())) {
       return m_atributos[posicao];
    } else {
        Atributo a;
        a.nome = "erro";
        a.tipo = "erro";
        return a;
    }
}

const Relacionamento Classe::getRelacionamento(unsigned int posicao)
{
    if ((posicao >= 0) && (posicao < m_relacionamentos.size())) {
       return m_relacionamentos[posicao];
    } else {
        Relacionamento r(ERRO, "erro");
        return r;
    }
}
