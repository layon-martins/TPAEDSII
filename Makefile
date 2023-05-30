make all:
		gcc Main/main.c  Patricia/Patricia.c Tratamento_Arquivos/TratamentoDeArquivos.c Indice_Invertido/IndiceInvertido.c -o ex `pkg-config --cflags --libs gtk+-3.0` -lm
		./ex
