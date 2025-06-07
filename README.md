# Nibbles Game em C

![Status](https://img.shields.io/badge/status-em%20desenvolvimento-blue)

Uma implementação simples e clássica do jogo "Nibbles" (também conhecido como Jogo da Cobrinha ou Snake) desenvolvida inteiramente em linguagem C. O jogo roda diretamente no terminal/console do Windows.


<br>


## ✨ Funcionalidades

-   Gameplay clássica do jogo Snake.
-   Controle da cobrinha utilizando as setas.
-   Sistema de pontuação que aumenta a cada fruta coletada.
-   Aumento do tamanho da cobra a cada fruta.
-   Detecção de colisão com as paredes e com o próprio corpo.
-   O jogo é executado diretamente no console do Windows.

### Limitações Atuais
-   Atualmente, **não há detecção de colisão da cobra com o próprio corpo**.
-   As frutas irão sempre aparecer nos mesmos locais.
  
## 🛠️ Tecnologias Utilizadas

-   **Linguagem:** C
-   **Bibliotecas:**
    -   `stdio.h`
    -   `stdlib.h`
    -   `time.h`
    -   `ncurses.h` (para manipulação livre do terminal)
    

## 🎮 Como Jogar

-   Use as setas do teclado para controlar a direção da cobra.
-   O objetivo é comer a fruta ('$') que aparece no mapa.
-   Evite colidir com as bordas do mapa (`#`) ou com o próprio corpo da cobra (`@`).
-   Pressione a tecla **X** para aumentar a velocidade de execução e **Z** para diminuir.

## 👨‍💻 Autor

-   **[JovemN00bl](https://github.com/JovemN00bl)**

## 📄 Licença

Este projeto é de código aberto. Sinta-se à vontade para usar, modificar e distribuir. Recomenda-se adicionar uma licença formal, como a [Licença MIT](https://opensource.org/licenses/MIT).
