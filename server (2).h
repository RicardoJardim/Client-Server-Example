#include "unix.h"

void escreveFicheiro(char* ficheiro, char* output);
void cria_produtos();
void mensagemBoasVindas();
void mensagemFimSimulacao();
void mostrarEstatisticas();
int getClientes(int normal, int prioritario);
void addMedia(int valor, boolean classe);
double getMedia(boolean classe);
void *acontecimentos(void *arg);
void escreveFicheiro_stats(char* ficheiro, char* output);