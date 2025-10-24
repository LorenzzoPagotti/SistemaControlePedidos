# Sistema de Controle de Pedidos (SCP)

Este projeto é um sistema de software para controle de pedidos, desenvolvido em linguagem C para a disciplina de Técnicas de Programação. O sistema permite o gerenciamento de clientes, produtos e os pedidos associados a eles, utilizando uma interface de terminal baseada em `ncurses`.

## 📜 Visão Geral

[cite_start]O objetivo é criar um sistema robusto para registrar e controlar pedidos de clientes de uma empresa. [cite_start]Todas as informações são salvas em arquivos de texto no formato `.csv`.

**Lógica de Persistência:**
1.  [cite_start]**Ao Iniciar:** O sistema carrega todos os dados dos arquivos (`Clientes.csv`, `Produtos.csv`, `Pedidos.csv`) para arrays na memória.
2.  [cite_start]**Durante o Uso:** Todas as operações (cadastrar, remover, listar) são realizadas diretamente nesses arrays.
3.  [cite_start]**Ao Finalizar:** O sistema salva o conteúdo completo dos arrays de volta para os arquivos `.csv`, sobrescrevendo os dados antigos.

## ✨ Funcionalidades (Módulos)

[cite_start]O sistema é dividido em três módulos principais de gerenciamento:

* **Clientes:**
    * [cite_start]Cadastrar novo cliente (Pessoa Física ou Jurídica) 
    * Remover cliente
    * Consultar cliente por ID
    * [cite_start]Listar todos os clientes cadastrados 
* **Produtos:**
    * [cite_start]Cadastrar novo produto 
    * Remover produto
    * Consultar produto por ID
    * [cite_start]Listar todos os produtos cadastrados 
* **Pedidos:**
    * [cite_start]Cadastrar novo pedido (associando um cliente e produtos) 
    * Remover pedido
    * Consultar pedido por ID
    * [cite_start]Listar todos os pedidos cadastrados 

## 🛠️ Tecnologias Utilizadas

* **Linguagem:** C
* [cite_start]**Interface:** Biblioteca `ncurses` (para a interface de usuário no terminal) 
* [cite_start]**Persistência:** Arquivos de texto `.csv` 
* **Compilação:** `make` (utilizando um Makefile multiplataforma)
* [cite_start]**Plataforma:** Desenvolvido para Linux, com suporte a Windows (via MinGW/PDCurses) 

## 🗂️ Estrutura de Arquivos

O projeto segue uma arquitetura modular para separação de responsabilidades:

SistemaControlePedidos/ │ ├── include/ # Arquivos de cabeçalho (.h) │ ├── cliente.h │ ├── produto.h │ ├── pedido.h │ ├── interface.h │ └── persistencia.h │ ├── src/ # Arquivos de código-fonte (.c) │ ├── cliente.c # (Lógica de validação de cliente) │ ├── produto.c │ ├── pedido.c │ ├── interface.c # (Código de tela, menus, ncurses) │ ├── persistencia.c # (Funções de salvar/carregar CSV) │ └── main.c # (Orquestrador principal, loop de menus) │ ├── data/ # Arquivos de dados (devem existir) │ ├── Clientes.csv │ ├── Produtos.csv │ └── Pedidos.csv │ ├── build/ # (Pasta criada pelo make para arquivos .o) │ ├── Makefile # Arquivo de compilação └── README.md # Este arquivo


## 🚀 Como Compilar e Executar

Este projeto utiliza um `Makefile` para automatizar a compilação em diferentes sistemas operacionais.

**Requisitos:**
* **Linux:** `gcc` e `ncurses` (`sudo apt-get install build-essential libncurses-dev`)
* **Windows:** `MinGW` (com `gcc` e `make`) e `PDCurses` (o Makefile do projeto-guia já inclui o `pdcurses.c`)

### 1. Compilar o Projeto

No terminal, na pasta raiz do projeto, execute:

```bash
make
Isso irá compilar todos os arquivos .c da pasta src/ e criar o executável final (scp.exe no Windows ou scp no Linux) na pasta raiz.

2. Executar o Sistema
Bash

make run
(Ou execute diretamente: ./scp no Linux ou .\scp.exe no Windows)

3. Limpar Arquivos Compilados
Para remover o executável e os arquivos .o da pasta build/:

Bash

make clean
