# Informações sobre o banco de dados

### Existem 4 categorias, separadas em pastas:
- [Vetores com chaves aleatórias](aleatorios/)
- [Vetores com chaves quase ordenadas](quaseOrdenados/)
- [Vetores com chaves ordenadas](ordenados/)
- [Vetores com chaves inversamente ordenadas](inversamenteOrdenados/)

Em cada pasta, existem os arquivos nomeados como:
- ordemXXX.txt
onde XXX corresponde ao tamanho do vetor. O tamanho pode ser:
- 10
- 100
- 1000
- 10000
- 100000
- 1000000

Exemplo: [database/aleatorios/ordem100.txt](aleatorios/ordem100.txt)

O programa principal está configurado para ler o arquivo nessa nomenclatura. Caso ele não exista, ou esteja organizado de outra forma, o programa encontrará erro na leitura do banco de dados.