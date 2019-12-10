
matriz m;
int dificuldade;
int opcao,cidade;
int nivel;

void logo(){
    FILE *arquivo;
    system("cls");
	arquivo = fopen("funcoes/logo.txt", "r");
	if (arquivo == NULL){
		printf("\t\t\t\t\t\t\tNao abriu!");
	}system("color 4");
	char ch = fgetc(arquivo);
	system("color 4");
	while (ch != EOF){
		printf("%c", ch);
		ch = fgetc(arquivo);
	}
}
void voltarMenu(){
    printf("\n\t\t\t\t\t\t\tVoltar para o menu? (s/n): ");
    fflush(stdin);
    char c;
    scanf("%c", &c);
    if (c == 's'){
        menu();
    }
    getch();
}
void menu(){
    logo();
	printf("\t\t\t\t\t\t\t1.Jogar\n\t\t\t\t\t\t\t2.Instrucões\n\t\t\t\t\t\t\t3.Recordes.");

	printf("\n\t\t\t\t\t\t\tDIGITE A OPÇÃO: ");
    scanf("%d", &opcao);
	switch (opcao){
    case 1:
        jogar();
        break;
    case 2:
        instrucoes();
        break;
    case 3:
        break;
    default:
        printf("\t\t\t\t\t\t\tReinicie o jogo e escolha uma opção válida");
	}
	getch();
}
void jogar(){
    logo();
    printf("\t\t\t\t\t\t\t1.Player\n\t\t\t\t\t\t\t2.I.A\n\t\t\t\t\t\t\t3.Player vs IA\n\t\t\t\t\t\t\t4.Voltar para o menu.");

    printf("\n\t\t\t\t\t\t\tDigite a opção: ");
    scanf("%d", &opcao);
    switch(opcao){
    	case 1:
            system("color 2");
    	    printf("\t\t\t\t\t\t\tEscolha a cidade: \n\n\t\t\t\t\t\t\t1.cidade 1\n\t\t\t\t\t\t\t2.cidade 2\n\t\t\t\t\t\t\t3.cidade 3\n\t\t\t\t\t\t\t4.cidade 4\n\t\t\t\t\t\t\t5.cidade 5\n");
    	    printf("\n\t\t\t\t\t\t\tDigite a opção: ");
    	    scanf("%d", &cidade);
    	    switch(cidade){
                case 1:
                    ler_arquivo(&m,"cidades/cidade1.txt");
                    interface_Matriz(m,"cidades/cidade_Jogador1.txt");
                    player(m);
                    break;
                case 2:
                    ler_arquivo(&m,"cidades/cidade2.txt");
                    interface_Matriz(m,"cidades/cidade_Jogador2.txt");
                    player(m);
                    break;
                case 3:
                    ler_arquivo(&m,"cidades/cidade2.txt");
                    interface_Matriz(m,"cidades/cidade_Jogador3.txt");
                    player(m);
                    break;
                case 4:
                    ler_arquivo(&m,"cidades/cidade2.txt");
                    interface_Matriz(m,"cidades/cidade4.txt");
                    player(m);
                    break;
                case 5:
                    ler_arquivo(&m,"cidades/cidade2.txt");
                    interface_Matriz(m,"cidades/cidade5.txt");
                    player(m);
                    break;
                default:
                    printf("\nEscolha uma cidade válida!\n");
    	    }

    		voltarMenu();
    		break;

    	case 2:

    	    system("color 3");
            printf("\t\t\t\t\t\t\tEscolha a cidade: \n\n\t\t\t\t\t\t\t1.cidade 1\n\t\t\t\t\t\t\t2.cidade 2\n\t\t\t\t\t\t\t3.cidade 3\n\t\t\t\t\t\t\t4.cidade 4\n\t\t\t\t\t\t\t5.cidade 5\n");
    	    printf("\n\t\t\t\t\t\t\tDigite a opção: ");
    	    scanf("%d", &cidade);
    	    switch(cidade){
                case 1:
                    ler_arquivo(&m,"cidades/cidade1.txt");

                    printf("\t\t\t\t\t\t\t1.FÁCIL\n\t\t\t\t\t\t\t2.MÉDIO\n\t\t\t\t\t\t\t3.DIFÍCIL\n");
                    printf("\n\t\t\t\t\t\t\tDigite a opção: ");
                    scanf("%d", &nivel);
                    switch(nivel){
                        case 1:
                            dificuldade = 50000;
                            interface_Matriz(m,"cidades/cidade_Jogador1.txt");
                            IA(m,dificuldade);
                        break;
                        case 2:
                            dificuldade = 75000;
                            interface_Matriz(m,"cidades/cidade_Jogador1.txt");
                            IA(m,dificuldade);
                        break;
                        case 3:
                            dificuldade = 100000;
                            interface_Matriz(m,"cidades/cidade_Jogador1.txt");
                            IA(m,dificuldade);
                        break;
                        default: printf("\nREINICIE E ESCOLHA UMA DIFICULDADE!\n");
                        break;
                    }
                     break;
                case 2:
                    ler_arquivo(&m,"cidades/cidade2.txt");

                    printf("\t\t\t\t\t\t\t1.FÁCIL\n\t\t\t\t\t\t\t2.MÉDIO\n\t\t\t\t\t\t\t3.DIFÍCIL\n");
                    printf("\n\t\t\t\t\t\t\tDigite a opção: ");
                    scanf("%d", &nivel);
                    switch(nivel){
                        case 1:
                            dificuldade = 50000;
                            interface_Matriz(m,"cidades/cidade_Jogador2.txt");
                            IA(m,dificuldade);
                        break;
                        case 2:
                            dificuldade = 75000;
                            interface_Matriz(m,"cidades/cidade_Jogador2.txt");
                            IA(m,dificuldade);
                        break;
                        case 3:
                            dificuldade = 100000;
                            interface_Matriz(m,"cidades/cidade_Jogador2.txt");
                            IA(m,dificuldade);
                        break;
                        default: printf("\nRENICIE E ESCOLHA UMA DIFICULDADE!\n");
                        break;
                    }

                    break;
                case 3:
                    ler_arquivo(&m,"cidades/cidade2.txt");

                    printf("\t\t\t\t\t\t\t1.FÁCIL\n\t\t\t\t\t\t\t2.MÉDIO\n\t\t\t\t\t\t\t3.DIFÍCIL\n");
                    printf("\n\t\t\t\t\t\t\tDigite a opção: ");
                    scanf("%d", &nivel);
                    switch(nivel){
                        case 1:
                            dificuldade = 50000;
                            interface_Matriz(m,"cidades/cidade_Jogador3.txt");
                            IA(m,dificuldade);
                        break;
                        case 2:
                            dificuldade = 75000;
                            interface_Matriz(m,"cidades/cidade_Jogador3.txt");
                            IA(m,dificuldade);
                        break;
                        case 3:
                            dificuldade = 100000;
                            interface_Matriz(m,"cidades/cidade_Jogador3.txt");
                            IA(m,dificuldade);
                        break;
                        default: printf("\nREINICIE E ESCOLHA UMA DIFICULDADE!\n");
                        break;
                    }
                    break;
                case 4:
                    ler_arquivo(&m,"cidades/cidade4.txt");

                    printf("\t\t\t\t\t\t\t1.FÁCIL\n\t\t\t\t\t\t\t2.MÉDIO\n\t\t\t\t\t\t\t3.DIFÍCIL\n");
                    printf("\n\t\t\t\t\t\t\tDigite a opção: ");
                    scanf("%d", &nivel);
                    switch(nivel){
                        case 1:
                            dificuldade = 50000;
                            interface_Matriz(m,"cidades/cidade4.txt");
                            IA(m,dificuldade);
                        break;
                        case 2:
                            dificuldade = 75000;
                            interface_Matriz(m,"cidades/cidade4.txt");
                            IA(m,dificuldade);
                        break;
                        case 3:
                            dificuldade = 100000;
                            interface_Matriz(m,"cidades/cidade4.txt");
                            IA(m,dificuldade);
                        break;
                        default: printf("\nREINICIE E ESCOLHA UMA DIFICULDADE!\n");
                        break;
                    }

                    break;
                case 5:
                    ler_arquivo(&m,"cidades/cidade5.txt");

                    printf("\t\t\t\t\t\t\t1.FÁCIL\n\t\t\t\t\t\t\t2.MÉDIO\n\t\t\t\t\t\t\t3.DIFÍCIL\n");
                    printf("\n\t\t\t\t\t\t\tDigite a opção: ");
                    scanf("%d", &nivel);
                    switch(nivel){
                        case 1:
                            dificuldade = 50000;
                            interface_Matriz(m,"cidades/cidade5.txt");
                            IA(m,dificuldade);
                        break;
                        case 2:
                            dificuldade = 75000;
                            interface_Matriz(m,"cidades/cidade5.txt");
                            IA(m,dificuldade);
                        break;
                        case 3:
                            dificuldade = 100000;
                            interface_Matriz(m,"cidades/cidade5.txt");
                            IA(m,dificuldade);
                        break;
                        default: printf("\nREINICIE E ESCOLHA UMA DIFICULDADE!\n");
                        break;
                    }
                    break;
                default:
                    printf("\nEscolha uma cidade válida!\n");
    	    }


			voltarMenu();
			break;

		case 3:

            system("color 5");
            printf("\t\t\t\t\t\t\tEscolha a cidade: \n\n\t\t\t\t\t\t\t1.cidade 1\n\t\t\t\t\t\t\t2.cidade 2\n\t\t\t\t\t\t\t3.cidade 3\n\t\t\t\t\t\t\t4.cidade 4\n\t\t\t\t\t\t\t5.cidade 5\n");
    	    printf("\n\t\t\t\t\t\t\tDigite a opcão: ");
    	    scanf("%d", &cidade);
    	    switch(cidade){
                case 1:
                    ler_arquivo(&m,"cidades/cidade1.txt");

                    printf("\t\t\t\t\t\t\t1.FÁCIL\n\t\t\t\t\t\t\t2.MÉDIO\n\t\t\t\t\t\t\t3.DIFÍCIL\n");
                    printf("\n\t\t\t\t\t\t\tDigite a opção: ");
                    scanf("%d", &nivel);
                    switch(nivel){
                        case 1:
                            dificuldade = 50000;
                            interface_Matriz(m,"cidades/cidade_Jogador1.txt");
                            player_IA(m,arquivo,dificuldade);
                        break;
                        case 2:
                            dificuldade = 75000;
                            interface_Matriz(m,"cidades/cidade_Jogador1.txt");
                            player_IA(m,arquivo,dificuldade);
                        break;
                        case 3:
                            dificuldade = 100000;
                            interface_Matriz(m,"cidades/cidade_Jogador1.txt");
                            player_IA(m,arquivo,dificuldade);
                        break;
                        default: printf("\nREINICIE E ESCOLHA UMA DIFICULDADE!\n");
                        break;
                    }
                     break;
                case 2:
                    ler_arquivo(&m,"cidades/cidade2.txt");

                    printf("\t\t\t\t\t\t\t1.FÁCIL\n\t\t\t\t\t\t\t2.MÉDIO\n\t\t\t\t\t\t\t3.DIFÍCIL\n");
                    printf("\n\t\t\t\t\t\t\tDigite a opção: ");
                    scanf("%d", &nivel);
                    switch(nivel){
                        case 1:
                            dificuldade = 50000;
                            interface_Matriz(m,"cidades/cidade_Jogador2.txt");
                            player_IA(m,arquivo,dificuldade);
                        break;
                        case 2:
                            dificuldade = 75000;
                            interface_Matriz(m,"cidades/cidade_Jogador2.txt");
                            player_IA(m,arquivo,dificuldade);
                        break;
                        case 3:
                            dificuldade = 100000;
                            interface_Matriz(m,"cidades/cidade_Jogador2.txt");
                            player_IA(m,arquivo,dificuldade);
                        break;
                        default: printf("\nREINICIE E ESCOLHA UMA DIFICULDADE!\n");
                        break;
                    }

                    break;
                case 3:
                    ler_arquivo(&m,"cidades/cidade2.txt");

                    printf("\t\t\t\t\t\t\t1.FÁCIL\n\t\t\t\t\t\t\t2.MÉDIO\n\t\t\t\t\t\t\t3.DIFÍCIL\n");
                    printf("\n\t\t\t\t\t\t\tDigite a opção: ");
                    scanf("%d", &nivel);
                    switch(nivel){
                        case 1:
                            dificuldade = 50000;
                            interface_Matriz(m,"cidades/cidade_Jogador3.txt");
                            player_IA(m,arquivo,dificuldade);
                        break;
                        case 2:
                            dificuldade = 75000;
                            interface_Matriz(m,"cidades/cidade_Jogador3.txt");
                            player_IA(m,arquivo,dificuldade);
                        break;
                        case 3:
                            dificuldade = 100000;
                            interface_Matriz(m,"cidades/cidade_Jogador3.txt");
                            player_IA(m,arquivo,dificuldade);
                        break;
                        default: printf("\nREINICIE E ESCOLHA UMA DIFICULDADE!\n");
                        break;
                    }
                    break;
                case 4:
                    ler_arquivo(&m,"cidades/cidade4.txt");

                    printf("\t\t\t\t\t\t\t1.FÁCIL\n\t\t\t\t\t\t\t2.MÉDIO\n\t\t\t\t\t\t\t3.DIFÍCIL\n");
                    printf("\n\t\t\t\t\t\t\tDigite a opção: ");
                    scanf("%d", &nivel);
                    switch(nivel){
                        case 1:
                            dificuldade = 50000;
                            interface_Matriz(m,"cidades/cidade4.txt");
                            player_IA(m,arquivo,dificuldade);
                        break;
                        case 2:
                            dificuldade = 75000;
                            interface_Matriz(m,"cidades/cidade4.txt");
                            player_IA(m,arquivo,dificuldade);
                        break;
                        case 3:
                            dificuldade = 100000;
                            interface_Matriz(m,"cidades/cidade4.txt");
                            player_IA(m,arquivo,dificuldade);
                        break;
                        default: printf("\nREINICIE E ESCOLHA UMA DIFICULDADE!\n");
                        break;
                    }

                    break;
                case 5:
                    ler_arquivo(&m,"cidades/cidade5.txt");

                    printf("\t\t\t\t\t\t\t1.FÁCIL\n\t\t\t\t\t\t\t2.MÉDIO\n\t\t\t\t\t\t\t3.DIFÍCIL\n");
                    printf("\n\t\t\t\t\t\t\tDigite a opção: ");
                    scanf("%d", &nivel);
                    switch(nivel){
                        case 1:
                            dificuldade = 50000;
                            interface_Matriz(m,"cidades/cidade5.txt");
                            player_IA(m,arquivo,dificuldade);
                        break;
                        case 2:
                            dificuldade = 75000;
                            interface_Matriz(m,"cidades/cidade5.txt");
                            player_IA(m,arquivo,dificuldade);
                        break;
                        case 3:
                            dificuldade = 100000;
                            interface_Matriz(m,"cidades/cidade5.txt");
                            player_IA(m,arquivo,dificuldade);
                        break;
                        default: printf("\nREINICIE E ESCOLHA UMA DIFICULDADE!\n");
                        break;
                    }
                    break;
                default:
                    printf("\nEscolha uma cidade válida!\n");
    	    }

		case 4:
            voltarMenu();
		default:
			printf("\t\t\t\t\t\t\tReinicie o jogo e entre com uma opção válida");
	}

}
void instrucoes(){
    logo();
    printf("\t\t\t\t\t\t\t 1.Você não pode retorna a mesma casa.\n");
    printf("\t\t\t\t\t\t\t 2.Você não pode colocar número maior que a quantidade de casas.\n");
    printf("\t\t\t\t\t\t\t 3.Você tem 12s para fazer uma escolha, após isso sua escolha não será válida. \n");
    char c;
    voltarMenu();
};
void sair(){
    system("exit");

};

