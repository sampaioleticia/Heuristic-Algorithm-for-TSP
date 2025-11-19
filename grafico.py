import matplotlib.pyplot as plt

dados = {
    10: 0.000035,
    100: 0.000213,
    1000: 0.003038,
    10000: 0.193289
}

x = list(dados.keys())
y = list(dados.values())

plt.figure(figsize=(8, 5))  
plt.plot(x, y, marker='o', linestyle='-', color='r', label='Dados')  
plt.xscale('log') 
plt.yscale('log')  
plt.xlabel('Tamanho do Problema')
plt.ylabel('Tempo (segundos)')
plt.title('Desempenho do Algoritmo') 
plt.grid(True)  
plt.legend()  
plt.tight_layout()  
plt.show()  
