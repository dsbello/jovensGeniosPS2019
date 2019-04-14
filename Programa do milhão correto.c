#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int selecionador=0; //Variavel para o selecionador que sera utilizado para selecionar opções
    int contadorPremio=0; // Variavel que conta o valor do premio
    int boolean=0; //Boolean que sera utilizado para saber se o jogador parou de jogar (obs:Apesar de ter sido enunciado,acabou que nao foi de fato utilizado)
    int i,j,k,l; // Contadores auxiliares
    int randonNumber; //Variiavel do numero randomico
    //Contadores para as ajudas
    //Pular
    int contadorAjudaPular=3;
    int contadorNumeroDePulos=0;
    //Placas
    int probabilidadePlaca=50; //Obs: Esse valor simboliza a probabilidade da paleita acertar e pode ser mudado.Para ser mais realista,talvez fosse justo criar uma função que gerasse um valor aleatorio tendo como parametros o valor medio e o desvio padrão;
    int booleanAjudaPlacas=1;
    //Cartas
    int booleanAjudaCartas=1;
    int contadorLoop2=2;
    int contadorLoop2m=2;
    int contadorLoop2d=2;
    //Universitarios
    int booleanAjudaUniversitarios=1;
    int probabilidadeUniversitario=70; //Obs: Esse valor simboliza a probabilidade dos universitarios acertarem e pode ser mudado.Para ser mais realista,talvez fosse justo criar uma função que gerasse um valor aleatorio tendo como parametros o valor medio e o desvio padrão;
    //Vetores com os valores que serão mostrados ao usuario
    int numeroDaPergunta[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int valorPremio[]={1000,2000,3000,4000,5000,10000,20000,30000,40000,50000,100000,200000,300000,400000,500000};
    char nivelPergunta[]={'A','A','A','A','A','B','B','B','B','B','C','C','C','C','C'};
    //Banco de dados que guardara as perguntas faceis
    char* perguntasFaceis[]={
        "Em que estado brasileiro nasceu a apresentadora Xuxa?",
        "Vatapa eh uma comida tipica de qual estado?",
        "Qual era o apelido da cantora Elis Regina?",
        "Quem proclamou a republica no Brasil em 1889?",
        "Quem era o apresentador que reprovava os calouros tocando uma buzina?",
        "O churrasco eh considerado uma comida tipica de qual estado?",
        "Qual objeto eh usado como arma pelo Pinguim do Batman?",
        "Qual foi o nome dado ao movimento liderado por Tiradentes?",
        };
    char* alternativasPerguntasFaceis[]={
        "\n\n1 RIO DE JANEIRO\n2 RIO GRANDE DO SUL\n3 SANTA CATARINA\n4 GOIAS\n",
        "\n\n1 PARANA\n2 SANTA CATARINA\n3 SAO PAULO\n4 BAHIA\n",
        "\n\n1 GAUCHINHA\n2 PAULISTINHA\n3 PIMENTINHA\n4 ANDORINHA \n",
        "\n\n1 DUQUE DE CAXIAS\n2 MARECHAL RONDON\n3 DOM PEDRO II\n4 MARECHAL DEODORO \n",
        "\n\n1 RAUL GIL\n2 BOLINHA\n3 FLAVIO CAVALCANTI\n4 CHACRINHA \n",
        "\n\n1 CEARA\n2 RIO GRANDE DO SUL\n3 PARA\n4 MARANHAO \n",
        "\n\n1 GUARDA-CHUVA\n2 CHAPEU\n3 GALOCHA\n4 CAPA \n",
        "\n\n1 REVOLUÇAO FRANCESA\n2 GUERRA DOS EMBOABAS\n3 INCONFIDENCIA MINEIRA\n4 SEGUNDA GUERRA MUNDIAL \n",
        };
    char respostasPerguntasFaceis[]={
        2,
        4,
        3,
        4,
        4,
        2,
        1,
        3
        };

    //Banco de dados que guardará as perguntas medias
    char* perguntasMedias[]={
        "Como eh chamado quem nasce em Milao, na Italia?",
        "Como eh chamada a cantora que representa o papel principal em uma opera?",
        "Qual cantor ficou conhecido como 'O rei da voz'?",
        "Quem realizou a primeira cirurgia de ponte de safena no Brasil?",
        "Que metal avermelhado cria uma camada esverdeada em contato com a umidade?",
        "O que os filatelistas colecionam?",
        "Que animais são criados nas pocilgas?",
        "Quem disse a frase: “Vim, vi e venci”?"
    };
    char* alternativasPerguntasMedias[]={
        "\n\n1 MILANENSE\n2 MILANOSO\n3 MILISTA\n4 MILANES\n",
        "\n\n1 PRIMEIRA DAMA\n2 DONA-PRIMA\n3 PRIMA-DONA\n4 OBRA-PRIMA\n",
        "\n\n1 ORLANDO SILVA\n2 VICENTE CELESTINO\n3 FRANCISCO ALVES\n4 CARLOS GALHARDO\n",
         "\n\n1 DR. ZERBINI\n2 DR. FRITZ\n3 DR. JATENE\n4 DR. CALLIGARI\n",
         "\n\n1 FERRO\n2 COBRE\n3 MERCERIO\n4 ACO\n",
         "\n\n1 QUADROS\n2 MOEDAS\n3 SELOS\n4 FIGURINHAS\n",
         "\n\n1 CAMELOS\n2 BÚFALOS\n3 CARNEIROS\n4 PORCOS\n",
         "\n\n1 JULIO CESAR\n2 CALIGULA\n3 NERO\n4 MARCO ANTONIO\n"
    };
    char respostasPerguntasMedias[]={
        4,
        3,
        3,
        3,
        2,
        3,
        4,
        1
    };
    //Banco de dados que guardará as perguntas dificeis
    char* perguntasDificeis[]={
        "Onde foi conduzida a vitoria das forças aliadas na Segunda Guerra Mundial?",
        "Onde nasceu Van Gogh, o grande pintor impressionista?",
        "Qual presidente brasileiro instituiu o AI-5?",
        "Qual desses quatro pesos eh o mais leve?",
        "Os nazistas foram julgados em:",
        "Quem escreveu “Ulisses” em 1922?",
        "A Belgica é:",
        "De quem eh este verso: “A praça eh do povo, como o ceu eh do condor”?"
    };
    char* alternativasPerguntasDificeis[]={
        "\n\n1 CANNES\n2 NORMANDIA\n3 CAPRI\n4 MARSELHA\n",
        "\n\n1 POLONIA\n2 FRANÇA\n3 ITALIA\n4 HOLANDA\n",
        "\n\n1 COSTA E SILVA\n2 ERNESTO GEISEL\n3 JOAO FIGUEIREDO\n4 ITAMAR FRANCO\n",
        "\n\n1 10 ONCAS\n2 10 GRAMAS\n3 10 QUILOS\n4 10 LIBRAS\n",
        "\n\n1 BERLIM\n2 NUREMBERGUE\n3 MUNIQUE\n4 PARIS\n",
        "\n\n1 ERNEST HEMINGWAY\n2 MARCEL PROUST\n3 T.S. ELLIOT\n4 JAMES JOYCE\n",
        "\n\n1 UMA REPUBLICA\n2 UMA MONARQUIA CONSTITUCIONAL\n3 UM EMIRADO\n4 UM PRINCIPADO\n",
        "\n\n1 TOBIAS BARRETO\n2 DORIVAL CAIMI\n3 MACHADO DE ASSIS\n4 CASTRO ALVES\n"
    };
    char respostasPerguntasDificeis[]={
        2,
        4,
        1,
        2,
        2,
        4,
        2,
        4
    };

    setlocale(LC_ALL, "");
    srand(time(NULL));

    printf("\t\tBem vindo ao show do milhao!!");
    //Pergunta e mostra as intruções
    printf("\nDeseja ver as instrucoes:\n0-Nao\n1-Sim\n");
    scanf("%d",&selecionador);
    switch (selecionador)
    {
        case 0: break;
        case 1:
        printf("\nSerao feitas 16 perguntas:\n-5 do nivel A\n-5 do nivel B\n-5 do nivel C\n1 PERGUNTA DO MILHAO!");
        printf("\n\nCada pergunta consiste de 4 opcoes onde somente uma esta certa.\n\nSe o participante acertar,seu premio aumenta! Se errar,o premio atual eh diminuido pela metade.\nNo final de toda perguntaa,oparticipante pode decidir nao continuar e levar seu premio atual para casa.\natencao! Se o participante errar a pergunta do milhao,NAO LEVA NADA!");
        printf("\n\nHa tambem ajudas! Veja so:\n-PULOS:O participante pode ""pular"" a pergunta caso nao saiba a resposta. Esse recurso pode ser utilizado ate tres vezes.\n-UNIVERSITARIOS: Tres estudantes de diversas faculdades dao suas respostas a pergunta e cabe ao participante confiar ou nao.\n-PLACAS:Uma pequena plateia levanta placas numeradas, referentes a alternativa correta. Por exemplo, para a terceira alternativa, levantam a placa de numero 3. Cabe ao participante decidir se concorda com a maioria das alternativas ou nao.\n-CARTAS: Quatro cartas de baralho sao viradas e o participante escolhe uma. Se tirar o Rei, nenhuma alternativa errada eh eliminada. 'As' eliminava uma alternativa, 2 elimina duas alternativas e 3 elimina todas as tres alternativas erradas, restando apenas a correta.");
        printf("\n\n**PRESSIONE ENTER PARA COMECAR**");
        getchar();
        getchar();
        default:break;
    }
    //Perguntas faceis
    for(i=0;i-contadorNumeroDePulos<5;)
    {
        printf("\n\nPERGUNTA %d\nNIVEL %c\nVALENDO %d",numeroDaPergunta[i-contadorNumeroDePulos],nivelPergunta[i-contadorNumeroDePulos],valorPremio[i-contadorNumeroDePulos]);
        printf("\n***%s***",perguntasFaceis[i]);
        printf("%s",alternativasPerguntasFaceis[i]);
        printf("\n0-Responder pergunta\n1-Usar ajuda\n");
        scanf("%d",&selecionador);
        switch (selecionador)
        {
            case 0:
                printf("Selecione a resposta:");
                scanf("%d",&selecionador);
                if(selecionador==respostasPerguntasFaceis[i])
                {
                    printf("\nResposta correta!");
                    contadorPremio=valorPremio[i-contadorNumeroDePulos];
                    printf("\nO seu premio esta em %d",contadorPremio);
                    printf("\nDeseja continuar? 0-Sim 1-Nao\n\nAcertar a proxima: %d\nParar agora:%d\nErrar a proxima:%d\n",valorPremio[i-contadorNumeroDePulos+1],contadorPremio,contadorPremio/2);
                    scanf("%d",&selecionador);
                    switch (selecionador)
                    {
                        case 0: i++; break;
                        case 1: printf("O seu premio foi de %d",contadorPremio);

                                boolean=1;
                                break;
                    }
                }
                else
                {
                    printf("\nResposta errada!");
                    printf("A resposta correta eh:%d",respostasPerguntasFaceis[i]);
                        contadorPremio=contadorPremio/2;
                        boolean=1;
                        printf("\nO seu premio foi de %d para %d!",2*contadorPremio,contadorPremio);
                        printf("\n\nPuxa! Nao foi dessa vez!");
                        printf("\n\nMas nao fique assim!! Lembre-se que o mais importante eh o aprendizado que levamos,e todas as coisas que aprendemos no caminho!\nEstude um pouco mais e venha jogar de novo!");
                }
                break;

            case 1:
                printf("\nSelecione a ajuda:\n1-Pular pergunta (%d restante)\n2-Placas (%d restante)\n3-Cartas (%d restante)\n4-Universitarios (%d restante)\n",contadorAjudaPular,booleanAjudaPlacas,booleanAjudaCartas,booleanAjudaUniversitarios);
                scanf("%d",&selecionador);
                switch (selecionador)
                {
                    case 1:
                        if(contadorAjudaPular>0)
                        {
                        printf("\n**Voce pulou uma pergunta**");
                        contadorAjudaPular--;
                        printf("\nNumero de pulos restantes:%d",contadorAjudaPular);
                        contadorNumeroDePulos ++;
                        i++;
                        break;
                        }
                        else
                        {
                            printf("\n**Voce nao pode mais pular perguntas!**");
                            break;
                        }

                    case 2:
                        if(booleanAjudaPlacas==1)
                        {
                            booleanAjudaPlacas=0;
                            randonNumber=(rand()%100);
                            if(randonNumber<probabilidadePlaca)
                            {
                                printf("\nA RESPOSTA CORRETA EH:%d",respostasPerguntasFaceis[i]);
                            }
                            else
                            {
                                if( (randonNumber%4+1)!=respostasPerguntasFaceis[i])
                                {
                                printf("\nA RESPOSTA CORRETA EH:%d",(randonNumber%4+1));
                                }
                                else
                                {
                                    printf("\nA RESPOSTA CORRETA EH:%d",( (randonNumber+1)%4+1));
                                }

                            }
                            printf("\n*Agora que voce usou a ajuda das placas,pressione enter e responda a pergunta!*");
                            getchar();
                            getchar();
                            break;
                        }
                        else
                        {
                            printf("\n**Voce ja usou essa ajuda!** \nPressione enter e responda a pergunta!");
                            getchar();
                            getchar();
                            break;
                        }
                    case 3:
                            if(booleanAjudaCartas==1)
                            {

                                booleanAjudaCartas=0;
                                randonNumber=rand();
                                if(randonNumber%4==0)
                                {
                                    printf("\nA carta escolida foi o Rei!");
                                    printf("\n**Nenhuma alternativa sera retirada**");
                                    printf("\nAgora que voce usou a ajuda das cartas,pressione enter e responda a pergunta!!");
                                    getchar();
                                    getchar();
                                    break;
                                }
                                else
                                {
                                    if(randonNumber%4==1)
                                    {
                                        randonNumber=rand();
                                        printf("\nA carta escolhida foi o As!");
                                        if( (randonNumber%4+1) !=respostasPerguntasFaceis[i] )
                                        {
                                            printf("\n**ELIMINE A ALTERNATIVA %d**",randonNumber%4+1);
                                            printf("\nAgora que voce usou a ajuda das cartas,pressione enter e responda a pergunta!!");
                                            getchar();
                                            getchar();
                                            break;
                                        }
                                        else
                                        {
                                            printf("\n**ELIMINE A ALTERNATIVA %d**",(randonNumber+1)%4 +1);
                                            printf("\nAgora que voce usou a ajuda das cartas,pressione enter e responda a pergunta!!");
                                            getchar();
                                            getchar();
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        if(randonNumber%4==2)
                                        {
                                            randonNumber=rand();
                                            printf("\nA carta escolhida foi o 2!");
                                        for(j=0;contadorLoop2>0;j++)
                                            {
                                                if( (j+1)!=respostasPerguntasFaceis[i])
                                                {
                                                    printf("\n**ELIMINE A ALTERNATIVA %d",j+1);
                                                    contadorLoop2--;
                                                }
                                            }
                                            printf("\nAgora que voce usou a ajuda das cartas,pressione enter e responda a pergunta!!");
                                            getchar();
                                            getchar();
                                            break;
                                        }
                                        else
                                        {
                                            if(randonNumber%4==3)
                                            {
                                                printf("\nA carta escolhida foi o 3!");
                                                for(j=0;j<4;j++)
                                                {
                                                    if( (j+1)!=respostasPerguntasFaceis[i])
                                                    {
                                                    printf("\n**ELIMINE A ALTERNATIVA %d",j+1);
                                                    }
                                                }
                                            printf("\nAgora que voce usou a ajuda das cartas,pressione enter e responda a pergunta!!");
                                            getchar();
                                            getchar();
                                            break;
                                            }
                                        }
                                    }
                                }
                            }
                            else
                            {
                                printf("\n**Voce ja usou essa ajuda!** \nPressione enter e responda a pergunta!");
                                getchar();
                                getchar();
                                break;
                            }

                    case 4:
                         if(booleanAjudaUniversitarios==1)
                        {
                            booleanAjudaUniversitarios=0;
                            randonNumber=(rand()%100);
                            if(randonNumber<probabilidadeUniversitario)
                            {
                                printf("\nA RESPOSTA CORRETA EH:%d",respostasPerguntasFaceis[i]);
                            }
                            else
                            {
                                if( (randonNumber%4+1)!=respostasPerguntasFaceis[i])
                                {
                                printf("\nA RESPOSTA CORRETA EH:%d",(randonNumber%4+1));
                                }
                                else
                                {
                                    printf("\nA RESPOSTA CORRETA EH:%d",( (randonNumber+1)%4+1));
                                }

                            }
                            printf("\n*Agora que voce usou a ajuda dos universitarios,pressione enter e responda a pergunta!*");
                            getchar();
                            getchar();
                            break;
                        }
                        else
                        {
                            printf("\n**Voce ja usou essa ajuda!** \nResponda a pergunta:");
                            break;
                        }
                }

             default:
            break;
        }
        if(boolean==1){break;}
        if(i-contadorNumeroDePulos==5){break;};
    }
    //Perguntas medias
    if(i-contadorNumeroDePulos==5)
    {
    printf("\n***PARABENS,VOCE CHEGOU AS PERGUNTAS DO NIVEL B!!***\nPremio atual:%d\nPulos restantes:%d\nOutras ajudas restantes:%d",contadorPremio,contadorAjudaPular,booleanAjudaCartas+booleanAjudaPlacas+booleanAjudaUniversitarios);
    for(j=0;j<8;)
    {
        printf("\n\nPERGUNTA %d\nNIVEL %c\nVALENDO %d",numeroDaPergunta[i-contadorNumeroDePulos],nivelPergunta[i-contadorNumeroDePulos],valorPremio[i-contadorNumeroDePulos]);
        printf("\n***%s***",perguntasMedias[j]);
        printf("%s",alternativasPerguntasMedias[j]);
        printf("\n0-Responder pergunta\n1-Usar ajuda\n");
        scanf("%d",&selecionador);
        switch (selecionador)
        {
            case 0:
                printf("Selecione a resposta:");
                scanf("%d",&selecionador);
                if(selecionador==respostasPerguntasMedias[j])
                {
                    printf("\nResposta correta!");
                    contadorPremio=valorPremio[i-contadorNumeroDePulos];
                    printf("\nO seu premio esta em %d",contadorPremio);
                    printf("\nDeseja continuar? 0-Sim 1-Nao\n\nAcertar a proxima: %d\nParar agora:%d\nErrar a proxima:%d\n",valorPremio[i-contadorNumeroDePulos+1],contadorPremio,contadorPremio/2);
                    scanf("%d",&selecionador);
                    switch (selecionador)
                    {
                        case 0: i++;j++; break;
                        case 1: printf("O seu premio foi de %d",contadorPremio);
                                printf("Obrigador por jogar!");
                                boolean=1;
                                break;
                    }
                }
                else
                {
                    printf("\nResposta errada!");
                    printf("A resposta correta eh:%d",respostasPerguntasMedias[j]);
                        contadorPremio=contadorPremio/2;
                        boolean=1;
                        printf("\nO seu premio foi de %d para %d!",2*contadorPremio,contadorPremio);
                        printf("\n\nPuxa! Nao foi dessa vez!");
                        printf("\n\nMas nao fique assim!! Lembre-se que o mais importante é o aprendizado que levamos,e todas as coisas que aprendemos no caminho!\nEstude um pouco mais e venha jogar de novo!");
                }
                break;

            case 1:
                printf("\nSelecione a ajuda:\n1-Pular pergunta (%d restante)\n2-Placas (%d restante)\n3-Cartas (%d restante)\n4-Universitarios (%d restante)\n",contadorAjudaPular,booleanAjudaPlacas,booleanAjudaCartas,booleanAjudaUniversitarios);
                scanf("%d",&selecionador);
                switch (selecionador)
                {
                    case 1:
                        if(contadorAjudaPular>0)
                        {
                        printf("\n**Voce pulou uma pergunta**");
                        contadorAjudaPular--;
                        printf("\nNumero de pulos restantes:%d",contadorAjudaPular);
                        contadorNumeroDePulos ++;
                        i++;
                        j++;
                        break;
                        }
                        else
                        {
                            printf("\n**Voce nao pode mais pular perguntas!**");
                            break;
                        }

                    case 2:
                        if(booleanAjudaPlacas==1)
                        {
                            booleanAjudaPlacas=0;
                            randonNumber=(rand()%100);
                            if(randonNumber<probabilidadePlaca)
                            {
                                printf("\nA RESPOSTA CORRETA EH:%d",respostasPerguntasMedias[j]);
                            }
                            else
                            {
                                if( (randonNumber%4+1)!=respostasPerguntasMedias[j])
                                {
                                printf("\nA RESPOSTA CORRETA EH:%d",(randonNumber%4+1));
                                }
                                else
                                {
                                    printf("\nA RESPOSTA CORRETA EH:%d",( (randonNumber+1)%4+1));
                                }

                            }
                            printf("\n*Agora que voce usou a ajuda das placas,pressione enter e responda a pergunta!*");
                            getchar();
                            getchar();
                            break;
                        }
                        else
                        {
                            printf("\n**Voce ja usou essa ajuda!** \nPressione enter e responda a pergunta!");
                            getchar();
                            getchar();
                            break;
                        }
                    case 3:
                            if(booleanAjudaCartas==1)
                            {

                                booleanAjudaCartas=0;
                                randonNumber=rand();
                                if(randonNumber%4==0)
                                {
                                    printf("\nA carta escolida foi o Rei!");
                                    printf("\n**Nenhuma alternativa sera retirada**");
                                    printf("\nAgora que voce usou a ajuda das cartas,pressione enter e responda a pergunta!!");
                                    getchar();
                                    getchar();
                                    break;
                                }
                                else
                                {
                                    if(randonNumber%4==1)
                                    {
                                        randonNumber=rand();
                                        printf("\nA carta escolhida foi o As!");
                                        if( (randonNumber%4+1) !=respostasPerguntasMedias[j] )
                                        {
                                            printf("\n**ELIMINE A ALTERNATIVA %d**",randonNumber%4+1);
                                            printf("\nAgora que voce usou a ajuda das cartas,pressione enter e responda a pergunta!!");
                                            getchar();
                                            getchar();
                                            break;
                                        }
                                        else
                                        {
                                            printf("\n**ELIMINE A ALTERNATIVA %d**",(randonNumber+1)%4 +1);
                                            printf("\nAgora que voce usou a ajuda das cartas,pressione enter e responda a pergunta!!");
                                            getchar();
                                            getchar();
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        if(randonNumber%4==2)
                                        {
                                            randonNumber=rand();
                                            printf("\nA carta escolhida foi o 2!");
                                        for(k=0;contadorLoop2m>0;k++)
                                            {
                                                if( (k+1)!=respostasPerguntasMedias[j])
                                                {

                                                    printf("\n**ELIMINE A ALTERNATIVA %d",k+1);
                                                    contadorLoop2m--;
                                                }
                                            }
                                            printf("\nAgora que voce usou a ajuda das cartas,pressione enter e responda a pergunta!!");
                                            getchar();
                                            getchar();
                                            break;
                                        }
                                        else
                                        {
                                            if(randonNumber%4==3)
                                            {
                                                printf("\nA carta escolhida foi o 3!");
                                                for(k=0;k<4;k++)
                                                {
                                                    if( (k+1)!=respostasPerguntasMedias[j])
                                                    {
                                                    printf("\n**ELIMINE A ALTERNATIVA %d",k+1);
                                                    }
                                                }
                                            printf("\nAgora que voce usou a ajuda das cartas,pressione enter e responda a pergunta!!");
                                            getchar();
                                            getchar();
                                            break;
                                            }
                                        }
                                    }
                                }
                            }
                            else
                            {
                                printf("\n**Voce ja usou essa ajuda!** \nPressione enter e responda a pergunta!");
                                getchar();
                                getchar();
                                break;
                            }

                    case 4:
                         if(booleanAjudaUniversitarios==1)
                        {
                            booleanAjudaUniversitarios=0;
                            randonNumber=(rand()%100);
                            if(randonNumber<probabilidadeUniversitario)
                            {
                                printf("\nA RESPOSTA CORRETA EH:%d",respostasPerguntasMedias[j]);
                            }
                            else
                            {
                                if( (randonNumber%4+1)!=respostasPerguntasMedias[j])
                                {
                                printf("\nA RESPOSTA CORRETA EH:%d",(randonNumber%4+1));
                                }
                                else
                                {
                                    printf("\nA RESPOSTA CORRETA EH:%d",( (randonNumber+1)%4+1));
                                }

                            }
                            printf("\n*Agora que voce usou a ajuda dos universitarios,pressione enter e responda a pergunta!*");
                            getchar();
                            getchar();
                            break;
                        }
                        else
                        {
                            printf("\n**Voce ja usou essa ajuda!** \nResponda a pergunta:");
                            break;
                        }
                }

             default:
            break;
        }
        if(boolean==1){break;}
        if(i-contadorNumeroDePulos==10){break;};
    }
    }
    //Perguntas Dificeis
    if(i-contadorNumeroDePulos==10)
    {
    printf("\n***PARABENS,VOCE CHEGOU AS PERGUNTAS DO NIVEL C!!***\nPremio atual:%d\nPulos restantes:%d\nOutras ajudas restantes:%d",contadorPremio,contadorAjudaPular,booleanAjudaCartas+booleanAjudaPlacas+booleanAjudaUniversitarios);
    for(k=0;k<8;)
    {
        printf("\n\nPERGUNTA %d\nNIVEL %c\nVALENDO %d",numeroDaPergunta[i-contadorNumeroDePulos],nivelPergunta[i-contadorNumeroDePulos],valorPremio[i-contadorNumeroDePulos]);
        printf("\n***%s***",perguntasDificeis[k]);
        printf("%s",alternativasPerguntasDificeis[k]);
        printf("\n0-Responder pergunta\n1-Usar ajuda\n");
        scanf("%d",&selecionador);
        switch (selecionador)
        {
            case 0:
                printf("Selecione a resposta:");
                scanf("%d",&selecionador);
                if(selecionador==respostasPerguntasDificeis[k])
                {
                    printf("\nResposta correta!");
                    contadorPremio=valorPremio[i-contadorNumeroDePulos];
                    printf("\nO seu premio esta em %d",contadorPremio);
                    printf("\nDeseja continuar? 0-Sim 1-Nao\n\nAcertar a proxima: %d\nParar agora:%d\nErrar a proxima:%d\n",valorPremio[i-contadorNumeroDePulos+1],contadorPremio,contadorPremio/2);
                    scanf("%d",&selecionador);
                    switch (selecionador)
                    {
                        case 0: i++;k++; break;
                        case 1: printf("O seu premio foi de %d",contadorPremio);
                                printf("\n\nPuxa! Nao foi dessa vez!");
                                printf("\n\nMas nao fique assim!! Lembre-se que o mais importante é o aprendizado que levamos,e todas as coisas que aprendemos no caminho!\nEstude um pouco mais e venha jogar de novo!");
                                boolean=1;
                                break;
                    }
                }
                else
                {
                    printf("\nResposta errada!");
                    printf("A resposta correta eh:%d",respostasPerguntasDificeis[k]);
                        contadorPremio=contadorPremio/2;
                        boolean=1;
                        printf("\nO seu premio foi de %d para %d!\n\nObrigado por jogar!",2*contadorPremio,contadorPremio);
                }
                break;

            case 1:
                printf("\nSelecione a ajuda:\n1-Pular pergunta (%d restante)\n2-Placas (%d restante)\n3-Cartas (%d restante)\n4-Universitarios (%d restante)\n",contadorAjudaPular,booleanAjudaPlacas,booleanAjudaCartas,booleanAjudaUniversitarios);
                scanf("%d",&selecionador);
                switch (selecionador)
                {
                    case 1:
                        if(contadorAjudaPular>0)
                        {
                        printf("\n**Voce pulou uma pergunta**");
                        contadorAjudaPular--;
                        printf("\nNumero de pulos restantes:%d",contadorAjudaPular);
                        contadorNumeroDePulos ++;
                        i++;
                        k++;
                        break;
                        }
                        else
                        {
                            printf("\n**Voce nao pode mais pular perguntas!**");
                            break;
                        }

                    case 2:
                        if(booleanAjudaPlacas==1)
                        {
                            booleanAjudaPlacas=0;
                            randonNumber=(rand()%100);
                            if(randonNumber<probabilidadePlaca)
                            {
                                printf("\nA RESPOSTA CORRETA EH:%d",respostasPerguntasMedias[k]);
                            }
                            else
                            {
                                if( (randonNumber%4+1)!=respostasPerguntasMedias[k])
                                {
                                printf("\nA RESPOSTA CORRETA EH:%d",(randonNumber%4+1));
                                }
                                else
                                {
                                    printf("\nA RESPOSTA CORRETA EH:%d",( (randonNumber+1)%4+1));
                                }

                            }
                            printf("\n*Agora que voce usou a ajuda das placas,pressione enter e responda a pergunta!*");
                            getchar();
                            getchar();
                            break;
                        }
                        else
                        {
                            printf("\n**Voce ja usou essa ajuda!** \nPressione enter e responda a pergunta!");
                            getchar();
                            getchar();
                            break;
                        }
                    case 3:
                            if(booleanAjudaCartas==1)
                            {

                                booleanAjudaCartas=0;
                                randonNumber=rand();
                                if(randonNumber%4==0)
                                {
                                    printf("\nA carta escolida foi o Rei!");
                                    printf("\n**Nenhuma alternativa sera retirada**");
                                    printf("\nAgora que voce usou a ajuda das cartas,pressione enter e responda a pergunta!!");
                                    getchar();
                                    getchar();
                                    break;
                                }
                                else
                                {
                                    if(randonNumber%4==1)
                                    {
                                        randonNumber=rand();
                                        printf("\nA carta escolhida foi o As!");
                                        if( (randonNumber%4+1) !=respostasPerguntasDificeis[k] )
                                        {
                                            printf("\n**ELIMINE A ALTERNATIVA %d**",randonNumber%4+1);
                                            printf("\nAgora que voce usou a ajuda das cartas,pressione enter e responda a pergunta!!");
                                            getchar();
                                            getchar();
                                            break;
                                        }
                                        else
                                        {
                                            printf("\n**ELIMINE A ALTERNATIVA %d**",(randonNumber+1)%4 +1);
                                            printf("\nAgora que voce usou a ajuda das cartas,pressione enter e responda a pergunta!!");
                                            getchar();
                                            getchar();
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        if(randonNumber%4==2)
                                        {
                                            randonNumber=rand();
                                            printf("\nA carta escolhida foi o 2!");
                                        for(l=0;contadorLoop2d>0;l++)
                                            {
                                                if( (l+1)!=respostasPerguntasDificeis[k])
                                                {

                                                    printf("\n**ELIMINE A ALTERNATIVA %d",l+1);
                                                    contadorLoop2d--;
                                                }
                                            }
                                            printf("\nAgora que voce usou a ajuda das cartas,pressione enter e responda a pergunta!!");
                                            getchar();
                                            getchar();
                                            break;
                                        }
                                        else
                                        {
                                            if(randonNumber%4==3)
                                            {
                                                printf("\nA carta escolhida foi o 3!");
                                                for(l=0;l<4;l++)
                                                {
                                                    if( (l+1)!=respostasPerguntasDificeis[k])
                                                    {
                                                    printf("\n**ELIMINE A ALTERNATIVA %d",l+1);
                                                    }
                                                }
                                            printf("\nAgora que voce usou a ajuda das cartas,pressione enter e responda a pergunta!!");
                                            getchar();
                                            getchar();
                                            break;
                                            }
                                        }
                                    }
                                }
                            }
                            else
                            {
                                printf("\n**Voce ja usou essa ajuda!** \nPressione enter e responda a pergunta!");
                                getchar();
                                getchar();
                                break;
                            }

                    case 4:
                         if(booleanAjudaUniversitarios==1)
                        {
                            booleanAjudaUniversitarios=0;
                            randonNumber=(rand()%100);
                            if(randonNumber<probabilidadeUniversitario)
                            {
                                printf("\nA RESPOSTA CORRETA EH:%d",respostasPerguntasDificeis[k]);
                            }
                            else
                            {
                                if( (randonNumber%4+1)!=respostasPerguntasDificeis[k])
                                {
                                printf("\nA RESPOSTA CORRETA EH:%d",(randonNumber%4+1));
                                }
                                else
                                {
                                    printf("\nA RESPOSTA CORRETA EH:%d",( (randonNumber+1)%4+1));
                                }

                            }
                            printf("\n*Agora que voce usou a ajuda dos universitarios,pressione enter e responda a pergunta!*");
                            getchar();
                            getchar();
                            break;
                        }
                        else
                        {
                            printf("\n**Voce ja usou essa ajuda!** \nResponda a pergunta:");
                            break;
                        }
                }

             default:
            break;
        }
        if(boolean==1){break;}
        if(i-contadorNumeroDePulos==15){break;};
    }
    }
    //Pergunta do Milhão!!!
    while(i-contadorNumeroDePulos==15)
    {
        printf("\n\n\n*****BEM-VINDO A PERGUNTA DO MILHÃO!!!****");
        printf("\nRelembrando as regras:\n-Nao é permitido pular ou utilizar ajudas na pergunta do milhao\n-Acertando,você leva para ca UM MILHAO DE REAIS\n-Errando,Nao LEVA NADA.");
        printf("\n\nCERTEZA QUE QUER CONTINUAR??\n-0 Levar para casa 500,000\n-1 ARRISCAR TUDO\n");
        scanf("%d",&selecionador);
        switch (selecionador)
        {
            case 0:
                printf("\nVocê levou para casa R$500,000!\nParabens!");
                printf("\nObrigado por jogar!");
                break;

            case 1:
                printf("\n\n\n****Pergunta do Milhao****");
                printf("\n\nQual eh o nome da empresa que nos ultimos anos,atraves do aprendizado individualizado,estudo divertido e novas tecnologias,busca transformar o cenario da educaçao brasileira??");
                printf("\n1 Jovens trabalhadores\n2 Mentes brilhantes\n3 Jovens aprendiz\n4 Jovens Genios\n");
                scanf("%d",&selecionador);
                switch (selecionador)
                {
                    case 1:
                    case 2:
                    case 3:
                        printf("\n\nPuxa! Nao foi dessa vez!");
                        printf("\n\nMas nao fique assim!! Lembre-se que o mais importante é o aprendizado que levamos,e todas as coisas que aprendemos no caminho!\nEstude um pouco mais e venha jogar de novo!");
                        i++;
                        break;

                    case 4: printf("\n\nRESPOSTA CORRETA!!!");
                            printf("\n\n*****VOCE GANHOU R$1,000,000!!!*****");
                            printf("\n\nMAH OEE HI HI");
                            contadorPremio=1000000;
                            i++;

                }
        }
    }
    //Final do jogo
    printf("\n\nFINAL DO JOGO\nPontuacao:%d\nNumero de pulos usados:%d\nPedidos de ajuda as placas:%d\nPedidos de ajuda as cartas:%d\nPedidos de ajuda aos universitarios:%d",contadorPremio,contadorNumeroDePulos,1-booleanAjudaPlacas,1-booleanAjudaCartas,1-booleanAjudaUniversitarios);
    printf("\n\n\nConheça mais da Jovens Geninos em https://jovensgenios.com/ !");
    getchar();
    getchar();
    getchar;
    return 0;
}
