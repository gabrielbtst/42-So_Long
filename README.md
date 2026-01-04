# 42-So_Long
📌 Sobre

so_long é um projeto em C desenvolvido com MiniLibX, focado em arquitetura de software, validação de dados e controle de estado.
O programa carrega mapas .ber, valida rigorosamente sua estrutura e regras, garante a existência de um caminho válido e executa a lógica do jogo por meio de um loop de eventos.

⚙️ Funcionalidades

Parsing e validação de mapas .ber

Verificação de:

Formato retangular

Paredes fechadas

Caracteres válidos

Elementos obrigatórios (P, E, C)

Validação de caminho usando flood fill

Renderização por tiles com MiniLibX

Controle de movimentação por teclado

Contagem de passos e condição de vitória

🧱 Arquitetura

O estado do jogo é centralizado em uma estrutura (t_game), que concentra:

Mapa carregado em memória

Posição do jogador

Contadores de estado

Recursos gráficos e contexto da MiniLibX

O código é organizado em blocos claros: leitura, validação, inicialização, renderização, input e lógica.

🛠 Tecnologias

Linguagem: C

Biblioteca gráfica: MiniLibX

Sistema: Linux

Projeto desenvolvido como parte do currículo da 42 School.

▶️ Execução
make
./so_long maps/exemplo.ber

📝 Observação

Apesar do contexto gráfico, o projeto aplica conceitos diretamente transferíveis ao desenvolvimento backend, como validação de entrada, regras de negócio e controle de estado.
