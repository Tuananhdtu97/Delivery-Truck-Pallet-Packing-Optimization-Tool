<img src='https://sigarra.up.pt/feup/pt/imagens/LogotipoSI' width="30%"/>

<div align="center">
🌍 <a href="README.md">English</a> | 🇵🇹 <a href="README.pt.md">Português</a>
</div>

<h3 align="center">Licenciatura em Engenharia Informática e Computação<br> L.EIC016 - Desenho de Algoritmos<br> 2024/2025 </h3>

---
<h3 align="center"> Colaboradores &#129309 </h2>

<div align="center">

| Nome          | Número      |
|---------------|-------------|
| Bárbara Gomes | up202305089 |
| Tomás Morais  | up202304692 |
| Tomás Silva   | up202307796 |

Nota : 15,6

</div>

# Relatório da Ferramenta de Otimização de Carga de Paletes em Camiões

- [Diagrama de Classes](#diagrama-de-classes)  
- [Interface com o Utilizador](#interface-com-o-utilizador)  
- [Leitura do Dataset](#leitura-do-dataset)  
- [Abordagens de Programação](#abordagens-de-programação)  
  - [Força Bruta (Exaustiva)](#força-bruta-exaustiva)  
  - [Programação Dinâmica](#programação-dinâmica)  
  - [Aproximação (Abordagem Gulosa)](#aproximação-abordagem-gulosa)  
  - [Programação Linear Inteira](#programação-linear-inteira)  

<a id="diagrama-de-classes"></a>
## Diagrama de Classes

<div align="center">
<img width="1694" height="786" alt="Captura de ecrã de 2025-09-23 23-04-24" src="https://github.com/user-attachments/assets/77e01a75-7744-461c-88da-635eceafa60e" />
</div>

<a id="interface-com-o-utilizador"></a>
## Interface com o Utilizador

- ✅ Ao iniciar o programa, é mostrado um menu com as opções `Sair` (terminar o programa) e `Selecionar Ficheiros de Dados`;  
- ✅ Se for escolhida a segunda opção, todos os ficheiros disponíveis no mesmo diretório do código-fonte são listados;  
- ✅ Após a seleção do dataset, são mostradas as abordagens algorítmicas disponíveis, com a opção de regressar a `Selecionar Ficheiros de Dados`;  
- ✅ Depois de executar o algoritmo, a solução é apresentada (incluindo o lucro total) e é oferecida a opção de processar outro dataset.  

<a id="leitura-do-dataset"></a>
## Leitura do Dataset

Após a seleção dos ficheiros a processar:

- ✅ `pair<vector<int>, vector<int>> extractPalletValues(const string& palletsFileName)`  
  Abre e lê cada linha do ficheiro `Pallets`, extraindo o `peso` e o `lucro` de cada palete, armazenando-os nos vetores `weights` e `profits`. No final, devolve um `pair` com ambos os vetores.  

- ✅ `int extractTruckCapacity(const string& truckFileName)`  
  Extrai e devolve a capacidade máxima do camião a partir do ficheiro `Truck`.  

<a id="abordagens-de-programação"></a>
## Abordagens de Programação

<a id="força-bruta-exaustiva"></a>
### Força Bruta (Exaustiva)

- ✅ Itera por todos os subconjuntos de itens;  
- ✅ Para cada subconjunto, calcula o `peso` e o `lucro` total;  
- ✅ Se o peso total estiver dentro da capacidade e o lucro for superior ao melhor atual, atualiza a solução;  
- ✅ Apresenta os índices, pesos, lucros dos itens selecionados e o lucro máximo alcançável.  

**Complexidade Temporal:** `O(n 2^n)`  
**Complexidade Espacial:** `O(n)`  

**Estruturas de Dados:**  
- Entrada: 2 vetores (`profit`, `weight`) + inteiro (`capacidade máxima`).  
- Saída: os mesmos 2 vetores + vetor de índices selecionados + inteiro (`lucro máximo`).  

<a id="programação-dinâmica"></a>
### Programação Dinâmica

- ✅ Recebe como entrada lucros, pesos e capacidade do camião;  
- ✅ Constrói uma tabela DP para calcular o lucro máximo sem exceder a capacidade;  
- ✅ Faz backtracking na tabela para determinar os itens incluídos;  
- ✅ Apresenta os itens selecionados (índice, peso, lucro) e o lucro total;  
- ✅ Mais eficiente que a força bruta para inputs maiores.  

**Complexidade Temporal:** `O(nW)`  
**Complexidade Espacial:** `O(nW)`  

**Estruturas de Dados:**  
- Entrada: 2 vetores (`profit`, `weight`) + inteiro (`capacidade máxima`).  
- Saída: os mesmos 2 vetores + vetor de índices selecionados + inteiro (`lucro total`).  

<a id="aproximação-abordagem-gulosa"></a>
### Aproximação (Abordagem Gulosa)

**Algoritmo Guloso A**  
- ✅ Ordena por `peso/lucro` (ascendente).  
- ✅ Seleciona itens enquanto couberem no ca
