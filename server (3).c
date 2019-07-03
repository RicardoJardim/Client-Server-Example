#include "server.h"


boolean existe_ficheiro = false, existe_estatistica = false;
boolean classe;
int estado = 0; // 1 = decorrer; 2 = pausa; 3 = terminar
int clientesN = 0, clientesN_media = 0, clientesP = 0, clientesP_media = 0, empregados = 1, desistencias = 0, alterar = 0, clientesAtuais = 0;
int tempoInicial, tempoFinal;
int media, media_prioritaria, media_total = 0, media_total_prioritaria = 0;

int num_produtos;
int* produtos;

void cria_produtos()
{
	produtos = (int*) malloc(num_produtos * sizeof(int));
	for(int i = 0; i < num_produtos; i++)
		produtos[i] = 0;
}

void escreveFicheiro(char* ficheiro, char* output)
{
    
	if(existe_ficheiro == false)
	{
		file = fopen(ficheiro, "w");
		existe_ficheiro = true;
	}
	else
		file = fopen(ficheiro, "a");
    fprintf(file,"%s", output);
    fclose(file);
}

void escreveFicheiro_stats(char* ficheiro, char* output)
{
   	if(existe_estatistica == false)
	{
		file = fopen(ficheiro, "w");
		existe_estatistica = true;
	}
	else
		file = fopen(ficheiro, "a");
    fprintf(file,"%s", output);
    fclose(file);
}

void mensagemBoasVindas()
{
	system("clear");
	printf("\nSimulador Loja\n\n");
	printf("1 - Começar Simulação \n");
	printf("2 - Sair \n");
	printf("3 - Estatisticas \n");
}

void mensagemFimSimulacao()
{
	system("clear");
	printf("\n\n-----------------------------------------------------------------------\n");
	printf("-                           Fim Programa                              -\n");
	printf("-----------------------------------------------------------------------\n");

}

int getClientes(int normal, int prioritario)
{
	return normal + prioritario;
}

void addMedia(int valor, boolean classe)
{
	if(classe == true)
	{
		media_total_prioritaria =  media_total_prioritaria + valor;
	}
	else
	{
		media_total = media_total + valor;
	}
}

double getMedia(boolean classe)
{
	if(classe == true)
	{
		if (clientesP_media == 0)
			return 0;
		else
			return (double)media_total_prioritaria/clientesP_media;
	}
	else
	{
		if (clientesN_media == 0)
			return 0;
		else
			return (double)media_total/clientesN_media;
	}
}

void mostrarEstatisticas()
{
	int aux = 0;
	char stats[SIZE];
	printf("\nEstatística da loja\n\n");
	sprintf(stats, "\nEstatística da loja\n\n");
	escreveFicheiro_stats(ficheiro_estatisticas, stats);
	
	if(estado == 1 || estado == 2)
	{
		printf("Simulação a decorrer.\n");
		sprintf(stats, "Simulação a decorrer.\n");
		escreveFicheiro_stats(ficheiro_estatisticas, stats);
		printf("------------------ \n");
		sprintf(stats, "------------------ \n");
		escreveFicheiro_stats(ficheiro_estatisticas, stats);
		printf("Clientes na loja: %d\n", clientesAtuais);
		sprintf(stats, "Clientes na loja: %d\n", clientesAtuais);
		escreveFicheiro_stats(ficheiro_estatisticas, stats);

		for(int i = 0; i < num_produtos; i++)
		{
			printf("Produto comprado %c: %d vezes\n", i+ASCII, produtos[i]);
			sprintf(stats, "Produto comprado %c: %d vezes\n", i+ASCII, produtos[i]);
			escreveFicheiro_stats(ficheiro_estatisticas, stats);
		}
		
		printf("Desistências: %d\n", desistencias);
		sprintf(stats, "Desistências: %d\n", desistencias);
		escreveFicheiro_stats(ficheiro_estatisticas, stats);
		printf("Alterações: %d\n", alterar);
		sprintf(stats, "Alterações: %d\n", alterar);
		escreveFicheiro_stats(ficheiro_estatisticas, stats);
		printf("Tempo médio de espera para clientes normais: %f\n", getMedia(false));
		sprintf(stats, "Tempo médio de espera para clientes normais: %f\n", getMedia(false));
		escreveFicheiro_stats(ficheiro_estatisticas, stats);
		printf("Tempo médio de espera para clientes prioritários: %f\n", getMedia(true));
		sprintf(stats, "Tempo médio de espera para clientes prioritários: %f\n", getMedia(true));
		escreveFicheiro_stats(ficheiro_estatisticas, stats);
		printf("------------------ \n");
		sprintf(stats, "------------------ \n");
		escreveFicheiro_stats(ficheiro_estatisticas, stats);
	}
	else if (estado == 0)
	{
		aux = 1;
		printf("Simulação ainda não começou.\n");
		sprintf(stats, "Simulação ainda não começou.\n");
		escreveFicheiro_stats(ficheiro_estatisticas, stats);
		printf("------------------ \n");
		sprintf(stats, "------------------ \n");
		escreveFicheiro_stats(ficheiro_estatisticas, stats);
	}
	else
	{
		aux = 2;
		printf("Simulação terminada.\n");
		sprintf(stats, "Simulação terminada.\n");
		escreveFicheiro_stats(ficheiro_estatisticas, stats);
		printf("------------------ \n");
		sprintf(stats, "------------------ \n");
		escreveFicheiro_stats(ficheiro_estatisticas, stats);
		printf("Tempo total: %d\n", tempoInicial + tempoFinal);
		sprintf(stats, "Tempo total: %d\n", tempoInicial + tempoFinal);
		escreveFicheiro_stats(ficheiro_estatisticas, stats);
		printf("Total de clientes: %d\n", getClientes(clientesN, clientesP));
		sprintf(stats, "Total de clientes: %d\n", getClientes(clientesN, clientesP));
		escreveFicheiro_stats(ficheiro_estatisticas, stats);
		printf("Clientes prioritários: %d\n", clientesP);
		sprintf(stats, "Clientes prioritários: %d\n", clientesP);
		escreveFicheiro_stats(ficheiro_estatisticas, stats);
		printf("Clientes normais: %d\n", clientesN);
		sprintf(stats, "Clientes normais: %d\n", clientesN);
		escreveFicheiro_stats(ficheiro_estatisticas, stats);

		for(int i = 0; i < num_produtos; i++)
		{
			printf("Produto comprado %c: %d vezes\n", i+ASCII, produtos[i]);
			sprintf(stats, "Produto comprado %c: %d vezes\n", i+ASCII, produtos[i]);
			escreveFicheiro_stats(ficheiro_estatisticas, stats);
		}
		
		printf("Desistências: %d\n", desistencias);
		sprintf(stats, "Desistências: %d\n", desistencias);
		escreveFicheiro_stats(ficheiro_estatisticas, stats);
		printf("Alterações: %d\n", alterar);
		sprintf(stats, "Alterações: %d\n", alterar);
		escreveFicheiro_stats(ficheiro_estatisticas, stats);
		printf("Tempo médio de espera para clientes normais: %f\n", getMedia(false));
		sprintf(stats, "Tempo médio de espera para clientes normais: %f\n", getMedia(false));
		escreveFicheiro_stats(ficheiro_estatisticas, stats);
		printf("Tempo médio de espera para clientes prioritários: %f\n", getMedia(true));
		sprintf(stats, "Tempo médio de espera para clientes prioritários: %f\n", getMedia(true));
		escreveFicheiro_stats(ficheiro_estatisticas, stats);
		printf("------------------ \n");
		sprintf(stats, "------------------ \n");
		escreveFicheiro_stats(ficheiro_estatisticas, stats);
		
	}

	
	if(aux == 1)	
	{
		printf("Prima enter para continuar...\n");
		getchar();
		system("clear");
		mensagemBoasVindas();
	}
	else if (aux == 2)
	{
		printf("Prima enter para continuar...\n");
		getchar();
		mensagemFimSimulacao();
	}
}

void *acontecimentos(void *arg)
{
	int sockfd = *((int*) arg);
	int n, numComandos, acontecimento, tempo, aux1, aux2, aux3, aux4;	

	char buffer[SIZE];

	while(1)
	{    
		if((n = recv(sockfd, buffer, sizeof(buffer), 0)) <= 0)         
		{
			if(n < 0)                 
				perror("recv");             
		}    
		else         
		{
			buffer[n] = '\0';             
			numComandos = sscanf(buffer, "%d %d %d %d %d %d", &tempo, &acontecimento, &aux1, &aux2, &aux3, &aux4);             
			if(numComandos > 0)             
			{

				if (tempo < 0)	tempo = abs(tempo);

				switch(acontecimento)                 
				{                     
					case 1:
						num_produtos = aux1;
						tempoInicial = tempo;
						cria_produtos();                  
						printf(KRED "%d -> A loja abriu aos clientes.\n" KWHT, tempo);                         
						sprintf(buffer, "%d ->A loja abriu aos clientes.\n", tempo);                      
						break;
					case 2:                         
						printf(KRED "A loja não aceita mais clientes.\n" KWHT);
						sprintf(buffer, "A loja não aceita mais clientes.\n");
						break;                     
					case 3:
						tempoFinal = tempo;                       
						printf(KRED "-%d -> A loja fechou.\n" KWHT, tempo);
						sprintf(buffer, "-%d -> A loja fechou.\n", tempo);                         
						estado = 3;
						system("clear");                         
						mostrarEstatisticas();                    
						break;                     
					case 4:                                                     
						clientesN++;
						clientesAtuais++;
						printf(KCYN "%d -> Entrou o cliente nº %d.\n" KWHT, tempo, aux1);
						sprintf(buffer, "%d -> Entrou o cliente nº %d.\n", tempo, aux1);
						break;
					case 5:
						clientesP++;
						clientesAtuais++;
						printf(KCYN "%d -> Entrou o cliente nº %d | prioritário.\n" KWHT, tempo, aux1);
						sprintf(buffer, "%d -> Entrou o cliente nº %d | prioritário.\n", tempo, aux1);
						break;
					case 6:
						alterar++;
						printf("%d -> Cliente nº %d alterou para o produto %c.\n", tempo, aux1, aux2+ASCII);
						sprintf(buffer, "%d -> Cliente nº %d alterou para o produto %c.\n", tempo, aux1, aux2+ASCII);
						break;
					case 7:
						desistencias++;
						clientesAtuais--;
						printf(KYEL "%d -> Cliente nº %d desistiu.\n" KWHT, tempo, aux1);
						sprintf(buffer, "%d -> Cliente nº %d desistiu.\n", tempo, aux1);
						break;
					case 8:
						if (aux3 == 1)
						{
							addMedia(aux2, true);
							clientesP_media++;
						}
						else
						{
							addMedia(aux2, false);
							clientesN_media++;
						}
						clientesAtuais--;
						produtos[aux4]++;
						printf(KYEL "%d -> Cliente nº %d saiu da loja.\n" KWHT, tempo, aux1);
						sprintf(buffer, "%d -> Cliente nº %d saiu da loja.\n", tempo, aux1);
						break;
					case 9:
						printf("%d -> Cliente nº %d escolheu o produto %c.\n", tempo, aux1, aux2+ASCII);
						sprintf(buffer, "%d -> Cliente nº %d escolheu o produto %c.\n", tempo, aux1, aux2+ASCII);
						break;
					case 10:						
						if(aux2 == 1)
						{
							printf(KGRN "%d -> Empregado nº %d ao balcão.\n" KWHT, tempo, aux1);
							sprintf(buffer, "%d -> Empregado nº %d ao balcão.\n", tempo, aux1);
						}
						else
						{
							printf(KGRN "%d -> Empregado prioritário nº %d ao balcão.\n" KWHT, tempo, aux1);
							sprintf(buffer, "%d -> Empregado prioritário nº %d ao balcão.\n", tempo, aux1);
						}

						break;
					case 11:
						if(aux2 == 1)
						{
							printf(KGRN "%d -> Empregado nº %d saiu.\n" KWHT, tempo, aux1);
							sprintf(buffer, "%d -> Empregado nº %d saiu.\n", tempo, aux1);
						}
						else
						{
							printf(KGRN "%d -> Empregado prioritário nº %d saiu.\n" KWHT, tempo, aux1);
							sprintf(buffer, "%d -> Empregado prioritário nº %d saiu.\n", tempo, aux1);
						}
						break;
					case 12:
						printf(KGRN "%d -> Reposição do produto %c.\n" KWHT, tempo, aux1+ASCII);
						sprintf(buffer, "%d -> Reposição do produto %c.\n", tempo, aux1+ASCII);
						break;
					default:
						break;			
				
				}				
				escreveFicheiro(ficheiro, buffer);
			}

		}
	}
}


int main(int argc, char *argv[])
{
	
	char opcao[3];
	int sockfd, newsockfd, clilen, servlen;
	struct sockaddr_un cli_addr, serv_addr;
	
	//Cria socket stream

	if ((sockfd = socket(AF_UNIX,SOCK_STREAM,0)) < 0)
		err_dump("server: can't open stream socket");
	bzero((char *)&serv_addr, sizeof(serv_addr));
	serv_addr.sun_family = AF_UNIX;
	strcpy(serv_addr.sun_path, UNIXSTR_PATH);
	
	servlen = strlen(serv_addr.sun_path) + sizeof(serv_addr.sun_family);
	unlink(UNIXSTR_PATH);	
	
	if (bind(sockfd, (struct sockaddr *) &serv_addr, servlen) < 0)
		err_dump("server, can't bind local address");

	listen(sockfd, 1);
  	
	clilen = sizeof(cli_addr);
	newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
	if (newsockfd < 0) err_dump("server: accept error");

	pthread_t thread;
	pthread_create(&thread, NULL, &acontecimentos, &newsockfd);
	

	mensagemBoasVindas();

	while (estado != 3)
	{	
		fgets(opcao, sizeof(opcao), stdin);

		if(write(newsockfd, opcao, sizeof(opcao)) == -1)
		{
			perror("send");
			exit(1);
		}

		switch(atoi(opcao)) 
		{
			case 1: // Correr
				estado = 1;
				break;
			case 2: // Sair
				estado = 3;			
				break;
			case 3: // Mostrar estatística
				mostrarEstatisticas();
				break;
			default:
			{
				printf("\nOpção inválida!!\n");
			}
		}
	}
	
	system("clear");
	mostrarEstatisticas();
	close(sockfd);
	return 0;
  	
  	
}