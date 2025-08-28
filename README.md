# 🎰 Roleta em C (Lista Encadeada Circular)

Simulação de uma **roleta** usando **lista encadeada circular** em linguagem C.

## ✨ O que o projeto demonstra
- Estruturas de dados (lista encadeada circular)
- Alocação dinâmica e liberação de memória
- Uso de `rand()`/`time()` para simulação
- Entrada/validação básica de usuário
- Organização de código em funções

## 🧠 Regras/Ideia
- A roleta é composta por `n` casas numeradas de **1..n** (padrão `36`).
- O jogador escolhe um número.
- A roleta “gira”: é calculado um número de **passos** (voltas completas + casas extras).
- A bolinha para na casa onde o ponteiro terminou.
- Se a casa for igual ao número escolhido → **vitória**.

## ▶️ Como compilar e executar
```bash
gcc roleta.c -o roleta
./roleta
```
> Se preferir, altere o número de casas no início da execução (ou digite `0` para manter 36).

## 📌 Exemplo de execução
```
=== Roleta (Lista Encadeada Circular) ===
Defina o numero de casas (padrao 36). Digite 0 para usar 36: 0
Escolha um numero entre 1 e 36: 7

Giro: 131 passos (voltas=3, extras=23)
A bolinha parou no numero: 7
🎉 Voce ganhou!
```

## 🗂 Estrutura
```
roleta-em-c/
├── roleta.c
└── README.md
```

## 🚀 Ideias de melhoria
- Apostas em múltiplos números / pares-impares
- Interface de texto mais rica (menu, múltiplas rodadas)
- Semente de aleatoriedade configurável
- Versão em **Python** para comparação de abordagens
