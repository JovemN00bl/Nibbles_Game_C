# Nibbles Game em C

![Status](https://img.shields.io/badge/status-conclu%C3%ADdo-green)

Uma implementação simples e clássica do jogo "Nibbles" (também conhecido como Jogo da Cobrinha ou Snake) desenvolvida inteiramente em linguagem C. O jogo roda diretamente no terminal/console do Windows.


<br>

## 📸 Screenshot

*(Recomendação: Tire um screenshot do jogo rodando no seu terminal e adicione aqui para um visual mais atrativo. Você pode usar o seguinte markdown para isso: `![Gameplay do Jogo](./screenshot.png)`)*

![Imagem de Exemplo do Jogo da Cobrinha](https://user-images.githubusercontent.com/3997799/103986095-7f999500-5149-11eb-9169-216991789c0a.png)

## ✨ Funcionalidades

-   Gameplay clássica do jogo Snake.
-   Controle da cobrinha utilizando as setas.
-   Sistema de pontuação que aumenta a cada fruta coletada.
-   Aumento do tamanho da cobra a cada fruta.
-   Detecção de colisão com as paredes e com o próprio corpo.
-   O jogo é executado diretamente no console do Windows.

## 🛠️ Tecnologias Utilizadas

-   **Linguagem:** C
-   **Bibliotecas:**
    -   `stdio.h`
    -   `stdlib.h`
    -   `time.h`
    -   `ncurses.h` (para manipulação livre do terminal)
    

## ⚙️ Pré-requisitos

Para compilar e executar este projeto, você precisará de:

-   **Sistema Operacional:** Windows.
-   **Compilador C:** Um compilador como o **MinGW (GCC)**. Você pode instalá-lo através do [MinGW-w64](https://www.mingw-w64.org/downloads/) ou de ambientes de desenvolvimento como [Code::Blocks](http://www.codeblocks.org/downloads) ou [Dev-C++](https://sourceforge.net/projects/orwelldevcpp/).

## 🚀 Como Compilar e Executar

1.  **Clone o repositório:**
    ```bash
    git clone [https://github.com/JovemN00bl/Nibbles_Game_C.git](https://github.com/JovemN00bl/Nibbles_Game_C.git)
    ```

2.  **Navegue até o diretório do projeto:**
    ```bash
    cd Nibbles_Game_C
    ```

3.  **Compile o código-fonte:**
    Use o compilador GCC (MinGW) para criar o arquivo executável.
    ```bash
    gcc main.c -o nibbles.exe
    ```

4.  **Execute o jogo:**
    Após a compilação, execute o arquivo gerado.
    ```bash
    ./nibbles.exe
    ```

Pronto! O jogo será iniciado no seu terminal.

## 🎮 Como Jogar

-   Use as setas do teclado para controlar a direção da cobra.
-   O objetivo é comer a fruta ('$') que aparece no mapa.
-   Evite colidir com as bordas do mapa (`#`) ou com o próprio corpo da cobra (`@`).
-   Pressione a tecla **X** para aumentar a velocidade de execução e **Z** para diminuir.

## 👨‍💻 Autor

-   **[JovemN00bl](https://github.com/JovemN00bl)**

## 📄 Licença

Este projeto é de código aberto. Sinta-se à vontade para usar, modificar e distribuir. Recomenda-se adicionar uma licença formal, como a [Licença MIT](https://opensource.org/licenses/MIT).
