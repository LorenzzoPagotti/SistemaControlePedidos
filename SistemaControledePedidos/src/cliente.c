
#include "cliente.h" 
#include <string.h>
#include <ctype.h>

// ====================
// Funções de Validação
// ====================

int valida_cpf(const char *cpf)
{
    if (cpf == NULL) // seguranca
        return 0;

    if (strlen(cpf) != 11) // seguranca
        return 0;

    for (int i = 0; i < 11; i++)
    {
        if (!isdigit(cpf[i]))
            return 0;
    }
    
    return 1; // CPF é valido
}

int valida_cnpj(const char *cnpj)
{
    if (cnpj == NULL)
        return 0; // seguranca

    if (strlen(cnpj) != 14)
        return 0; // seguranca

    for (int i = 0; i < 14; i++)
    {
        if (!isdigit(cnpj[i]))
            return 0;
    }
    
    return 1; // CNPJ é válido
}