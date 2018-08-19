#include "gerador.hpp"

#include <sstream>

namespace GeradorCpp
{

Gerador::Gerador() : m_classeErro("erro", false)
{
}

void Gerador::adicionarClasse(std::string nome, bool classeBase)
{
    Classe c(nome, classeBase);
    m_classes.push_back(c);
}

std::string Gerador::gerarCodigo()
{
    unsigned int i;
    unsigned int j;
    unsigned int k;
    std::stringstream retorno;

    for (i = 0; i < m_classes.size(); ++i) {

        bool primeiraHeranca = false;
        retorno << "class " << m_classes[i].getNome();

        for (j = 0; j < m_classes[i].getQtdRelacionamentos(); ++j) {

            if (m_classes[i].getRelacionamento(j).getTipo() == HERANCA) {
                if (!primeiraHeranca) {
                    primeiraHeranca = true;
                    retorno << ": public " << m_classes[i].getRelacionamento(j).getNomeClasseRelacionada();
                } else {
                    retorno << ", public " << m_classes[i].getRelacionamento(j).getNomeClasseRelacionada();
                }
            }
        }

        retorno << "\n{\npublic:\n";

        for (j = 0; j < m_classes[i].getQtdMetodos(); ++j) {

            retorno << "\t" + m_classes[i].getMetodo(j).getTipoRetorno() << " " <<
                m_classes[i].getMetodo(j).getNome() << "(";

            for (k = 0; k < m_classes[i].getMetodo(j).getQtdParametros(); ++k) {

                retorno << m_classes[i].getMetodo(j).getParametro(k).tipo << " " <<
                    m_classes[i].getMetodo(j).getParametro(k).nome;

                if (k != m_classes[i].getMetodo(j).getQtdParametros() - 1) {
                    retorno << ", ";
                }
            }

            retorno << ");\n";
        }

        retorno << "private:\n";

        for (j = 0; j < m_classes[i].getQtdRelacionamentos(); ++j) {
            if (m_classes[i].getRelacionamento(j).getTipo() != HERANCA) {
                retorno << "\t" << m_classes[i].getRelacionamento(j).getNomeClasseRelacionada() <<
                    " " << "m_" << m_classes[i].getRelacionamento(j).getNomeClasseRelacionada() <<
                    ";" << "\n";
            }
        }

        for (j = 0; j < m_classes[i].getQtdAtributos(); ++j) {
            retorno << "\t" + m_classes[i].getAtributo(j).tipo << " " << m_classes[i].getAtributo(j).nome << ";" << "\n";
        }
        retorno << "};\n\n";
    }
    return retorno.str();
}

Classe *Gerador::getClassePorNome(std::string nome)
{
    unsigned int i;
    bool achou = false;
    for (i = 0; i < m_classes.size(); ++i) {
        if (m_classes[i].getNome() == nome) {
            achou = true;
            break;
        }
    }
    if (achou) {
        return &m_classes[i];
    } else {
        std::cout << "Classe nao encontrada!" << std::endl;
        return &m_classeErro;
    }
}
}
