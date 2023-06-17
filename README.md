# <i> Menu Interativo em C++</i>👨🏻‍💻

O código é um programa simples que exibe um menu interativo com cinco opções numeradas de 1 a 5 e permite que o usuário selecione uma opção usando as teclas direcionais do teclado, e selecionar uma opção usando a tecla ENTER. Vou descrever o que o código faz passo a passo:

1. Inclui as bibliotecas `stdlib.h`, `conio.h`, `iostream` e "hackthreat.h".

2. Declara a função `main()` como ponto de entrada do programa.

3. Declara duas variáveis inteiras: `pos` e `bot`. `pos` é usada para rastrear a posição atual do cursor no menu, e `bot` será usada para armazenar o código ASCII da tecla pressionada.

4. Inicia um loop `while (true)` que será executado continuamente até que uma condição de saída seja atendida.

5. Inicia um loop `do-while` para exibir o menu e aguardar a entrada do usuário. O loop continuará até que o usuário pressione a tecla Enter.

6. A função `pula(0, 0)` é chamada para posicionar o cursor no canto superior esquerdo da tela.

7. O programa exibe o menu com cinco opções. Se a opção atual selecionada pelo usuário for igual a `pos`, a função `colorizar(F_VERDE_C)` é chamada para imprimir o texto em verde com fundo colorido. Caso contrário, a função `colorizar(VERDE_C)` é chamada para imprimir o texto em verde sem fundo colorido.

8. A função `getch()` é chamada para obter a entrada do usuário e o código ASCII da tecla pressionada é armazenado em `bot`.

9. Se a tecla de seta para cima (`72`) for pressionada, `pos` é decrementada para mover a seleção para cima no menu.

10. Se a tecla de seta para baixo (`80`) for pressionada, `pos` é incrementada para mover a seleção para baixo no menu.

11. As verificações `if` garantem que `pos` permaneça dentro dos limites válidos (1 a 5). Se `pos` for menor que 1, ele é ajustado para 5. Se `pos` for maior que 5, ele é ajustado para 1.

12. Se a tecla Enter (`13`) for pressionada, o loop `do-while` é interrompido e o programa avança para a próxima etapa.

13. Se a tecla Esc (`27`) for pressionada, `exit(0)` é chamado para encerrar o programa.

14. Após sair do loop `do-while`, o programa exibe a mensagem "Entrando na opcao X." (onde X é o número da opção selecionada) e emite um sinal sonoro `\a`.

15. `getch()` é chamado para aguardar que o usuário pressione qualquer tecla antes de continuar para o próximo ciclo do loop.

O programa continuará exibindo o menu e permitindo ao usuário selecionar opções até que o programa seja encerrado manualmente.
