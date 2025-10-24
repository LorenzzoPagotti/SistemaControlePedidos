# Sistema de Controle de Pedidos (SCP)

Este projeto é um sistema de software para controle de pedidos, desenvolvido em linguagem C para a disciplina de Técnicas de Programação. O sistema permite o gerenciamento de clientes, produtos e os pedidos associados a eles, utilizando uma interface de terminal baseada em `ncurses`.

## 📜 Visão Geral

O objetivo é criar um sistema robusto para registrar e controlar pedidos de clientes de uma empresa. Todas as informações são salvas em arquivos de texto no formato `.csv`.

**Lógica de Persistência:**
1.  **Ao Iniciar:** O sistema carrega todos os dados dos arquivos (`Clientes.csv`, `Produtos.csv`, `Pedidos.csv`) para arrays na memória.
2.  **Durante o Uso:** Todas as operações (cadastrar, remover, listar) são realizadas diretamente nesses arrays.
3.  **Ao Finalizar:** O sistema salva o conteúdo completo dos arrays de volta para os arquivos `.csv`, sobrescrevendo os dados antigos.

## ✨ Funcionalidades (Módulos)

O sistema é dividido em três módulos principais de gerenciamento:

* **Clientes:**
    * Cadastrar novo cliente (Pessoa Física ou Jurídica)
    * Remover cliente
    * Consultar cliente por ID
    * Listar todos os clientes cadastrados
* **Produtos:**
    * Cadastrar novo produto
    * Remover produto
    * Consultar produto por ID
    * Listar todos os produtos cadastrados
* **Pedidos:**
    * Cadastrar novo pedido (associando um cliente e produtos)
    * Remover pedido
    * Consultar pedido por ID
    * Listar todos os pedidos cadastrados

## 🛠️ Tecnologias Utilizadas

* **Linguagem:** C
* **Interface:** Biblioteca `ncurses` (para a interface de usuário no terminal)
* **Persistência:** Arquivos de texto `.csv`
* **Compilação:** `make` (utilizando um Makefile multiplataforma)
* **Plataforma:** Desenvolvido para Linux, com suporte a Windows (via MinGW/PDCurses)
