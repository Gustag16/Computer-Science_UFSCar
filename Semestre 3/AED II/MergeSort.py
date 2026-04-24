import numpy as np
import time
import sys

# aumentar o limite de recursão do Python para lidar com vetores gigantes
sys.setrecursionlimit(10000000)

intervalo = np.arange(1000, 10000000) # define um intervalo de 1.000 a 9.999.999

# cria vetores que contém números aleatórios não repetidos e contidos no intervalo definido
vetor1 = np.random.choice(intervalo, size=1000000, replace=False).tolist()
vetor2 = np.random.choice(intervalo, size=2000000, replace=False).tolist()
vetor3 = np.random.choice(intervalo, size=3000000, replace=False).tolist()

def merge(A, low, q, high):
    # número de elementos das sublistas esquerda (n_L) e direita (n_R)
    n_L = q - low + 1
    n_R = high - q

    # criação dos arrays temporários L e R
    L = [0] * n_L
    R = [0] * n_R

    # copia os dados para as sublistas
    for i in range(n_L):
        L[i] = A[low + i]
        
    for j in range(n_R):
        R[j] = A[(q + 1) + j]

    # inicialização dos índices
    i = 0
    j = 0
    k = low

    # mescla as sublistas de volta em A[low..high]
    while i < n_L and j < n_R:
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1
        k += 1

    # copia os elementos restantes de L, se houver
    while i < n_L:
        A[k] = L[i]
        i += 1
        k += 1

    # copia os elementos restantes de R, se houver
    while j < n_R:
        A[k] = R[j]
        j += 1
        k += 1
    
def mergesort(A, low, high):
    if low >= high: # lista tem zero ou um elemento
        return
    q = (low + high) // 2
    mergesort(A, low, q)
    mergesort(A, q + 1, high)
    merge(A, low, q, high)

# ===== CÓDIGO PRINCIPAL ======
print('Tempo de ordenação do MergeSort:')

print('n = 1 milhão: ')
inicio = time.perf_counter()
mergesort(vetor1, 0, len(vetor1) - 1)
fim = time.perf_counter()
print(f"Tempo de execução: {fim - inicio:.6f} segundos")

print('n = 2 milhões: ')
inicio = time.perf_counter()
mergesort(vetor2, 0, len(vetor2) - 1)
fim = time.perf_counter()
print(f"Tempo de execução: {fim - inicio:.6f} segundos")

print('n = 3 milhões: ')
inicio = time.perf_counter()
mergesort(vetor3, 0, len(vetor3) - 1)
fim = time.perf_counter()
print(f"Tempo de execução: {fim - inicio:.6f} segundos")