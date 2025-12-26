# Controle de Estoque em C

![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)

##  Descrição

O **Controle de Estoque em C** é um programa de linha de comando (CLI) desenvolvido em linguagem C que permite gerenciar um estoque de forma simples e eficiente diretamente pelo terminal.

O projeto tem como objetivo principal praticar conceitos fundamentais de programação em C, como:
- Entrada e saída de dados
- Manipulação de arquivos
- Estruturas de controle
- Organização de código

### Funcionalidades principais:
- Adicionar itens ao estoque
- Remover itens do estoque
- Listar todos os itens cadastrados
- Armazenar os dados em arquivo de texto (`estoque.txt`)

---

## 🖥️ Captura de Tela / Demonstração

Como se trata de um projeto **CLI (Command Line Interface)**, abaixo está um exemplo de execução no terminal:

==================================
Controle de Estoque
Adicionar Item

Remover Item

Listar Estoque

Sair
Opção: 1

Digite o nome do item: Notebook
Digite a quantidade: 10
Item adicionado com sucesso!


Esse exemplo demonstra o funcionamento básico do sistema diretamente no terminal.

![Demonstração do controle de estoques](assets/demo.png)

---

## ⚙️ Instalação e Pré-requisitos

### Pré-requisitos
Para executar este projeto, é necessário ter:
- Um compilador C (GCC recomendado)
- Sistema operacional Windows, Linux ou macOS
- Terminal ou Prompt de Comando

### Instalação

1. Clone o repositório ou faça o download do projeto:
```bash
git clone https://github.com/SEU_USUARIO/controle-estoque-c.git
Acesse a pasta do projeto:


cd controle-estoque-c
Compile o programa:

gcc main.c -o estoque
Execute o programa:


./estoque
# Uso e Exemplos de Comando
Após executar o programa, o menu principal será exibido:


1. Adicionar Item
2. Remover Item
3. Listar Estoque
4. Sair
Exemplo 1: Adicionar Item

Digite o nome do item: Caneta
Digite a quantidade: 50
Item adicionado com sucesso!
Exemplo 2: Remover Item

Digite o nome do item: Caneta
Digite a quantidade a ser removida: 10
Quantidade atualizada com sucesso!
Exemplo 3: Listar Estoque

Nome: Caneta
Quantidade: 40
Exemplo 4: Sair

Obrigado por usar o Controle de Estoques! Até a próxima.
# Estrutura do Projeto

controle-estoque-c/
│── main.c
│── estoque.txt
│── README.md
│── LICENSE
Explicação dos arquivos principais
main.c
Contém todo o código-fonte do programa, incluindo o menu, as funções de adicionar, remover e listar itens do estoque.

estoque.txt
Arquivo responsável por armazenar os dados do estoque. Cada item ocupa duas linhas:

Nome do item

Quantidade disponível

README.md
Documento de documentação do projeto, explicando seu funcionamento, uso e estrutura.

LICENSE
Define os direitos de uso, modificação e distribuição do projeto.
