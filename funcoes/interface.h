


matriz m;

int opcao;
void logo(){
    FILE *arquivo;
    system("cls");
	arquivo = fopen("logo.txt", "r");
	if (arquivo == NULL){
		printf("\t\t\t\t\t\t\tNao abriu");
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
	printf("\t\t\t\t\t\t\t1.Jogar\n\t\t\t\t\t\t\t2.Instrucoes\n\t\t\t\t\t\t\t3.Recordes.");

	printf("\n\t\t\t\t\t\t\tDIGITE A OPCAO: ");
    scanf("%d", &opcao);
	switch (opcao){
    case 1:
        jogar();
        break;
    case 2:
        instrucoes();
        break;
    case 3:
        printf("Recordes.");
        break;
    default:
        printf("\t\t\t\t\t\t\tReinicie o jogo e escolha uma opcao valida");
	}
	getch();
}
void jogar(){
    logo();
    printf("\t\t\t\t\t\t\t1.Player\n\t\t\t\t\t\t\t2.I.A\n\t\t\t\t\t\t\t3.Player vs IA\n\t\t\t\t\t\t\t4.Voltar para o menu.");

    printf("\n\t\t\t\t\t\t\tDigite a opcao: ");
    scanf("%d", &opcao);
    switch(opcao){
    	case 1:
    		player(m,arquivo);
    		voltarMenu();
    		break;
    	case 2:
			IA(m);
			voltarMenu();
			break;
		case 3:
			player(m,arquivo);
			IA(m);
			break;
		case 4:
            voltarMenu();
		default:
			printf("\t\t\t\t\t\t\tReinicie o jogo e entre com uma opcao valida");
	}







}
void instrucoes(){
    logo();
    printf("\t\t\t\t\t\t\t 1. Voce nao pode retorna a mesma casa\n");
    printf("\t\t\t\t\t\t\t 2.Voce nao pode colocar numero maior que a quantidade de casas\n");
    printf("\t\t\t\t\t\t\t 3. Voce tem 12s para fazer uma escolha, apos isso sua escolha nao sera valida \n");
    char c;
    voltarMenu();
};
void sair(){
    system("exit");

};

