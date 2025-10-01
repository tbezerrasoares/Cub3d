# 🎮 Cub3D

![42 School Badge](https://img.shields.io/badge/42-School-000000?style=flat-square&logo=42&logoColor=white)
![C Badge](https://img.shields.io/badge/C-A8B9CC?style=flat-square&logo=c&logoColor=white)
![Linux Badge](https://img.shields.io/badge/Linux-FCC624?style=flat-square&logo=linux&logoColor=black)
![MinilibX Badge](https://img.shields.io/badge/MinilibX-Graphics-blue?style=flat-square)
![Grade Badge](https://img.shields.io/badge/Grade-✓-success?style=flat-square)

Um motor de raycasting 3D inspirado no clássico jogo **Wolfenstein 3D**, desenvolvido como parte do currículo da **42 School**. Este projeto implementa um renderizador 3D em tempo real usando a técnica de raycasting para criar uma experiência de jogo em primeira pessoa.

## 📋 Índice

- [Sobre o Projeto](#-sobre-o-projeto)
- [Características](#-características)
- [Pré-requisitos](#-pré-requisitos)
- [Instalação](#-instalação)
- [Como Usar](#-como-usar)
- [Formato do Mapa](#-formato-do-mapa)
- [Controles](#-controles)
- [Estrutura do Projeto](#-estrutura-do-projeto)
- [Algoritmo de Raycasting](#-algoritmo-de-raycasting)
- [Autores](#-autores)

## 🎯 Sobre o Projeto

O **Cub3D** é uma implementação de um motor gráfico 3D usando a técnica de **raycasting**. O projeto recria a sensação dos primeiros jogos FPS (First Person Shooter) como Wolfenstein 3D, onde o jogador navega por um labirinto visto de uma perspectiva em primeira pessoa.

### Objetivos de Aprendizagem

- 📐 Compreender os conceitos básicos de gráficos computacionais
- 🧮 Implementar algoritmos matemáticos complexos (raycasting)
- 🖼️ Trabalhar com a biblioteca gráfica MinilibX
- 📄 Processar e validar arquivos de configuração
- 🏗️ Desenvolver uma arquitetura de software robusta

## ✨ Características

- 🎮 **Renderização 3D em tempo real** usando raycasting
- 🗺️ **Sistema de mapas personalizáveis** com formato `.cub`
- 🖼️ **Texturas das paredes** com orientação (Norte, Sul, Leste, Oeste)
- 🎨 **Cores personalizáveis** para chão e teto
- 🚶 **Movimento fluido** do jogador (WASD)
- 🔄 **Rotação da câmera** com as setas do teclado
- 🏃 **Detecção de colisões** com paredes
- 🔍 **Validação rigorosa** dos arquivos de mapa
- 🎯 **Gestão de memória** eficiente

## 🔧 Pré-requisitos

### Sistema Operacional
- **Linux** (Ubuntu, Debian, etc.)
- **macOS** (com algumas adaptações)

### Dependências
```bash
# Ubuntu/Debian
sudo apt-get update
sudo apt-get install gcc make xorg libxext-dev libbsd-dev

# Para compilar a MinilibX
sudo apt-get install libx11-dev libxext-dev libxrandr-dev libxinerama-dev libxcursor-dev libxfixes-dev
```

## 🚀 Instalação

1. **Clone o repositório:**
```bash
git clone https://github.com/tbezerrasoares/Cub3d.git
cd Cub3d
```

2. **Compile o projeto:**
```bash
make
```

3. **Execute o jogo:**
```bash
./cub3d Maps/example.cub
```

## 🎮 Como Usar

### Execução Básica
```bash
./cub3d [arquivo_do_mapa.cub]
```

### Exemplos
```bash
# Mapa de exemplo
./cub3d Maps/example.cub

# Mapa personalizado
./cub3d Maps/example2.cub

# Testar mapas válidos
./cub3d Maps/valid/map01.cub
```

## 🗺️ Formato do Mapa

Os mapas são definidos em arquivos `.cub` com a seguinte estrutura:

```
NO texture/north_wall.xpm
SO texture/south_wall.xpm
WE texture/west_wall.xpm
EA texture/east_wall.xpm

F 220,100,0
C 225,30,0

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000000001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N01
11110111 1110101 101111010001
11111111 1111111 111111111111
```

### Componentes do Arquivo

| Elemento | Descrição |
|----------|-----------|
| `NO` | Textura da parede Norte (arquivo .xpm) |
| `SO` | Textura da parede Sul (arquivo .xpm) |
| `WE` | Textura da parede Oeste (arquivo .xpm) |
| `EA` | Textura da parede Leste (arquivo .xpm) |
| `F` | Cor do chão (R,G,B) |
| `C` | Cor do teto (R,G,B) |

### Símbolos do Mapa

| Símbolo | Significado |
|---------|-------------|
| `1` | Parede |
| `0` | Espaço vazio (chão) |
| `N` | Posição inicial do jogador (olhando para o Norte) |
| `S` | Posição inicial do jogador (olhando para o Sul) |
| `E` | Posição inicial do jogador (olhando para o Leste) |
| `W` | Posição inicial do jogador (olhando para o Oeste) |

## 🎮 Controles

| Tecla | Ação |
|-------|------|
| `W` | Mover para frente |
| `A` | Mover para a esquerda |
| `S` | Mover para trás |
| `D` | Mover para a direita |
| `←` | Girar câmera para a esquerda |
| `→` | Girar câmera para a direita |
| `ESC` | Sair do jogo |
| `X` (botão da janela) | Fechar o jogo |

## 📁 Estrutura do Projeto

```
Cub3d/
├── 📄 cub3d.c              # Arquivo principal
├── 📄 Makefile             # Script de compilação
├── 📄 README.md            # Documentação
├── 📁 include/             # Arquivos de cabeçalho
│   ├── 📄 cub3d.h         # Header principal
│   └── 📁 mlx/            # Biblioteca MinilibX
├── 📁 libft/              # Biblioteca de funções úteis
├── 📁 Utils/              # Funções utilitárias
│   ├── 📄 loading.c       # Carregamento de mapas
│   ├── 📄 rendering.c     # Sistema de renderização
│   ├── 📄 moving.c        # Sistema de movimento
│   ├── 📄 validating.c    # Validação de mapas
│   └── 📄 ...            # Outras funções
├── 📁 Maps/               # Mapas de exemplo
│   ├── 📄 example.cub     # Mapa básico
│   ├── 📁 valid/          # Mapas válidos
│   └── 📁 invalid_maps/   # Mapas inválidos (para testes)
└── 📁 texture/            # Texturas das paredes
    ├── 🖼️ north_wall.xpm
    ├── 🖼️ south_wall.xpm
    ├── 🖼️ west_wall.xpm
    └── 🖼️ east_wall.xpm
```

## 🔬 Algoritmo de Raycasting

O **raycasting** é a técnica principal utilizada neste projeto. Aqui está uma visão geral simplificada:

### 1. Conceito Básico
```
Jogador → Raio → Parede
```

### 2. Processo de Renderização
1. **Para cada coluna de pixels na tela:**
   - Calcular a direção do raio
   - Seguir o raio até encontrar uma parede
   - Determinar a distância até a parede
   - Calcular a altura da parede na tela
   - Aplicar a textura correspondente

### 3. Algoritmo DDA (Digital Differential Analyzer)
- Usado para percorrer o grid do mapa eficientemente
- Determina qual célula do mapa cada raio intersecta
- Otimizado para evitar cálculos desnecessários

### 4. Correção de Distorção
- Aplica correção de perspectiva ("fish-eye correction")
- Garante que as paredes apareçam retas na tela

## 🛠️ Funcionalidades Técnicas

### Validação de Mapas
- ✅ Verificação de formato de arquivo
- ✅ Validação de texturas existentes
- ✅ Verificação de mapa fechado (flood fill)
- ✅ Validação de posição inicial do jogador
- ✅ Verificação de cores RGB válidas

### Gestão de Memória
- 🧹 Liberação automática de recursos
- 🔒 Proteção contra vazamentos de memória
- ⚡ Alocação eficiente de estruturas

### Performance
- 🚀 Renderização otimizada
- 📐 Cálculos matemáticos eficientes
- 🔄 Loop de jogo responsivo

## 🧪 Testes

### Mapas de Teste
```bash
# Testar mapa válido
./cub3d Maps/valid/map01.cub

# Testar detecção de erros
./cub3d Maps/invalid_maps/wrong_extension.cube
./cub3d Maps/invalid_maps/missing_texture.cub
./cub3d Maps/invalid_maps/open_map.cub
```

### Casos de Teste Cobertos
- ✅ Arquivos inexistentes
- ✅ Extensões incorretas
- ✅ Texturas faltantes
- ✅ Mapas não fechados
- ✅ Múltiplas posições de jogador
- ✅ Cores RGB inválidas
- ✅ Caracteres inválidos no mapa

## 🔧 Comandos Make

| Comando | Descrição |
|---------|-----------|
| `make` | Compila o projeto |
| `make clean` | Remove arquivos objeto |
| `make fclean` | Remove arquivos objeto e executável |
| `make re` | Recompila tudo do zero |

## 🚨 Tratamento de Erros

O programa trata diversos tipos de erro:

- 📁 **Arquivo não encontrado**
- 🔧 **Formato de arquivo inválido**
- 🖼️ **Texturas inexistentes**
- 🗺️ **Mapa malformado**
- 🎨 **Cores RGB inválidas**
- 🚪 **Mapa não fechado**
- 👤 **Posição de jogador inválida**

## 🏆 Critérios de Avaliação (42 School)

- ✅ **Norma 42** - Código segue os padrões da escola
- ✅ **Sem vazamentos** - Gestão perfeita de memória
- ✅ **Tratamento de erros** - Cobertura completa de casos extremos
- ✅ **Makefile funcional** - Compilação sem warnings
- ✅ **Funcionalidade completa** - Todos os requisitos atendidos

## 👥 Autores

- **João Ribeiro** - [@joao-rib](https://github.com/joao-rib) - Desenvolvimento inicial
- **Thiago Bezerra** - [@tbezerrasoares](https://github.com/tbezerrasoares) - Desenvolvimento e melhorias

## 📚 Recursos de Aprendizagem

### Documentação Útil
- [Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html)
- [MinilibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- [42 School Subjects](https://github.com/42School/norminette)

### Conceitos Abordados
- 📐 **Matemática**: Trigonometria, geometria analítica
- 🖥️ **Programação**: Ponteiros, estruturas, gestão de memória
- 🎮 **Gráficos**: Pixel manipulation, texturas, perspectiva
- 🏗️ **Arquitetura**: Modularização, design patterns

## 📄 Licença

Este projeto foi desenvolvido como parte do currículo da **42 School** e está disponível para fins educacionais.

---

<div align="center">

**Desenvolvido com ❤️ na 42 Porto**

![42 Porto](https://img.shields.io/badge/42-Porto-blue?style=for-the-badge)

</div>