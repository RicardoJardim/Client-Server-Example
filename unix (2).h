#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <time.h>
#include <signal.h>
#include <errno.h>
#include <pthread.h>
#include <semaphore.h>
#include <math.h>

typedef int boolean;
#define true 1
#define false 0

#define SIZE 512

int ASCII = 65;

#define KNRM  "\x1B[0m"		//normal
#define KRED  "\x1B[31m"	//vermelho
#define KGRN  "\x1B[32m"	//verde
#define KYEL  "\x1B[33m"	//amarelo
#define KBLU  "\x1B[34m"	//azul
#define KMAG  "\x1B[35m"	//magenta
#define KCYN  "\x1B[36m"	//ciao
#define KWHT  "\x1B[37m"	//branco

FILE* file;

#define UNIXSTR_PATH "/tmp/s.unixstr"
#define UNIXDG_PATH "/tmp/s.unixdg"
#define UNIXDG_TMP "/tmp/dg.XXXXXX"

void err_dump(char* msg)
{
	perror(msg);
}

char* ficheiro = "log";
char* ficheiro_leitura = "leitura";
char* ficheiro_estatisticas = "estatistica";