import numpy as np
import time
import sys

# aumentar o limite de recursão do Python para lidar com vetores gigantes
sys.setrecursionlimit(10000000)

intervalo = np.arange(1000, 10000000) # define um intervalo de 1.000 a 9.999.999

# cria vetores que contém números aleatórios não repetidos e contidos no intervalo definido
vetor1_naive = np.random.choice(intervalo, size=1000000, replace=False).tolist()
vetor2_naive = np.random.choice(intervalo, size=2000000, replace=False).tolist()
vetor3_naive = np.random.choice(intervalo, size=3000000, replace=False).tolist()

vetor1_median = vetor1_naive.copy()
vetor2_median = vetor2_naive.copy()
vetor3_median = vetor3_naive.copy()

# função que troca dois valores de posição em um vetor
def swap(L, i, j):
    aux = L[i]
    L[i] = L[j]
    L[j] = aux

# função que particiona o vetor, separando os elementos menores e maiores que o pivô
def partition_naive(L, low, high):
    x = L[high]                     # definição do pivô (último elemento da lista)
    i = low - 1                     # maior indice do lado esquerdo
    for j in range(low, high):
        if L[j] <= x:
            i += 1
            swap(L, i, j)           # adiciona no lado esquerdo se for menor ou igual ao pivô
    swap(L, i+1, high) 
    return i + 1                    # retorna o indice do pivô
    
# implementação do quicksort usando o último elemento como pivô
def quicksort_naive(L, low, high):
    if low < high:
        q = partition_naive(L, low, high)
        quicksort_naive(L, low, q-1)
        quicksort_naive(L, q+1, high)

# função que particiona o vetor, separando os elementos menores e maiores que o pivô
def partition_median(L, low, high):
    # definição do pivô (heurística mediana de três)
    mid = (low + high) // 2
    
    # encontra a mediana
    if L[low] > L[mid]:
        swap(L, low, mid)
    if L[low] > L[high]:
        swap(L, low, high)
    if L[mid] > L[high]:
        swap(L, mid, high)
 
    # esconde o pivô no final
    swap(L, mid, high)
    x = L[high]
    i = low - 1
    for j in range(low, high):
        if L[j] <= x:
            i += 1
            swap(L, i, j)
    swap(L, i+1, high) 
    return i + 1

# implementação do quicksort usando o último elemento como pivô
def quicksort_median(L, low, high):
    if low < high:
        q = partition_median(L, low, high)
        quicksort_median(L, low, q-1)
        quicksort_median(L, q+1, high)


# ========= CÓDIGO QUICKSORT NAIVE =========
print('Tempo Quicksort usando o último elemento como pivô:')

print('n = 1 milhão: ')
inicio = time.perf_counter()
quicksort_naive(vetor1_naive, 0, len(vetor1_naive) - 1)
fim = time.perf_counter()
print(f"Tempo de execução: {fim - inicio:.6f} segundos")

print('n = 2 milhões: ')
inicio = time.perf_counter()
quicksort_naive(vetor2_naive, 0, len(vetor2_naive) - 1)
fim = time.perf_counter()
print(f"Tempo de execução: {fim - inicio:.6f} segundos")

print('n = 3 milhões: ')
inicio = time.perf_counter()
quicksort_naive(vetor3_naive, 0, len(vetor3_naive) - 1)
fim = time.perf_counter()
print(f"Tempo de execução: {fim - inicio:.6f} segundos")

# ========= CÓDIGO QUICKSORT MEDIAN =========
print('\nTempo Quicksort usando a heurística de mediana de três:')

print('n = 1 milhão: ')
inicio = time.perf_counter()
quicksort_median(vetor1_median, 0, len(vetor1_median) - 1)
fim = time.perf_counter()
print(f"Tempo de execução: {fim - inicio:.6f} segundos")

print('n = 2 milhões: ')
inicio = time.perf_counter()
quicksort_median(vetor2_median, 0, len(vetor2_median) - 1)
fim = time.perf_counter()
print(f"Tempo de execução: {fim - inicio:.6f} segundos")

print('n = 3 milhões: ')
inicio = time.perf_counter()
quicksort_median(vetor3_median, 0, len(vetor3_median) - 1)
fim = time.perf_counter()
print(f"Tempo de execução: {fim - inicio:.6f} segundos")