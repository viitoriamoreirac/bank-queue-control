
gcc src/main.c src/menu.c src/fila.c src/cliente.c src/transacoes.c src/relatorio.c -o bin/executar

if [ $? -eq 0 ]; then
    ./bin/executar
else
    echo "Erro na compilação."
fi
