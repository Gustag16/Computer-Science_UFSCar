import numpy as np
import time

# função que cria um array inicializado com zeros
def zeros(n):
    vetor_zero = []
    for i in range(0, n):
        vetor_zero.append(0)
    return vetor_zero

# função que implementa o countingsort
def countingsort(L, n, k):
    C = zeros(k)                    # cria um array com k zeros
    S = zeros(n)                    # array que irá armazenar o vetor final ordenado

    for i in range(n):
        C[L[i]] += 1                # conta número de ocorrências
    for i in range(1, k):
        C[i] += C[i-1]              # soma acumulada
    for i in range(n-1, -1, -1):
        C[L[i]] -= 1
        S[C[L[i]]] = L[i]
    return S

# ===== CÓDIGO PRINCIPAL =====

valores_n = [1000000, 2000000, 3000000]
valores_k = [100, 10000, 100000]

print("Iniciando testes do Counting Sort...\n")

for n in valores_n:
    for k in valores_k:
        # gera 'n' votos aleatórios, onde cada voto é um número entre 0 e k-1
        V = np.random.randint(0, k, size=n).tolist()
        
        inicio = time.perf_counter()
        S = countingsort(V, n, k)
        fim = time.perf_counter()
        
        print(f"n = {n} | k = {k} | Tempo: {fim - inicio:.6f} segundos")
