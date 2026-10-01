#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CLIENTES 10
#define MAX_PEDIDOS 20
#define TAM_DESC 21

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char rua[50];
    char cidade[40];
    char estado[3];
    char cep[10];
} Endereco;

typedef struct {
    char cnpj[20];
    char nome[50];
    char razaoSocial[80];
    Endereco endereco;
    char inscricaoEstadual[20];
    char telefone[20];
    char email[60];
    char contato[50];
} Cliente;

typedef struct {
    int numeroPedido;
    char cnpj[20];
    Data dataPedido;
    Data dataEntrega;
    int previsaoEntrega;
    char descricao[6][TAM_DESC];
    int quantidade[6];
    float valorItem[6];
    float totalPedido;
    char formaPagamento[20];
    int quantidadeItens;
} Pedido;

void inserirClientes(Cliente clientes[], int *qtdClientes){
    if(*qtdClientes >= MAX_CLIENTES){
        printf("Limite de clientes atingido!\n");
        return;
    }

    printf("\nCLIENTE\n");

    printf("CNPJ: ");
    scanf("%19s", clientes[*qtdClientes].cnpj);
    getchar();

    printf("Nome: ");
    fgets(clientes[*qtdClientes].nome, 50, stdin);

    printf("Razao Social: ");
    fgets(clientes[*qtdClientes].razaoSocial, 80, stdin);

    printf("Inscricao Estadual: ");
    scanf("%19s", clientes[*qtdClientes].inscricaoEstadual);
    getchar();

    printf("Telefone: ");
    scanf("%19s", clientes[*qtdClientes].telefone);
    getchar();

    printf("E-mail: ");
    scanf("%59s", clientes[*qtdClientes].email);
    getchar();

    printf("Contato: ");
    fgets(clientes[*qtdClientes].contato, 50, stdin);

    printf("\nENDERECO DO CLIENTE\n");

    printf("Rua: ");
    fgets(clientes[*qtdClientes].endereco.rua, 50, stdin);

    printf("Cidade: ");
    fgets(clientes[*qtdClientes].endereco.cidade, 40, stdin);

    printf("Estado: ");
    scanf("%2s", clientes[*qtdClientes].endereco.estado);
    getchar();

    printf("CEP: ");
    scanf("%9s", clientes[*qtdClientes].endereco.cep);
    getchar();

    (*qtdClientes)++;
}

void excluirCliente(int posicaoRemover, Cliente clientes[], int *qtdClientes){
    if(posicaoRemover < 0 || posicaoRemover >= *qtdClientes){
        printf("Posicao invalida!\n");
        return;
    }

    for(int i = posicaoRemover; i < *qtdClientes - 1; i++){
        clientes[i] = clientes[i + 1];
    }

    (*qtdClientes)--;

    printf("Cliente removido!\n");
}

void consultarClientes(Cliente clientes[], int qtdClientes){
    if(qtdClientes < 1){
        printf("Nao ha clientes cadastrados para consultar!\n");
        return;
    }

    for(int i = 0; i < qtdClientes; i++){

        printf("\nCLIENTE\n");
        printf("CNPJ: %s\n", clientes[i].cnpj);
        printf("Nome: %s", clientes[i].nome);
        printf("Razao Social: %s", clientes[i].razaoSocial);
        printf("Inscricao Estadual: %s\n", clientes[i].inscricaoEstadual);
        printf("Telefone: %s\n", clientes[i].telefone);
        printf("E-mail: %s\n", clientes[i].email);
        printf("Contato: %s", clientes[i].contato);

        printf("\nENDERECO\n");
        printf("Rua: %s", clientes[i].endereco.rua);
        printf("Cidade: %s", clientes[i].endereco.cidade);
        printf("Estado: %s\n", clientes[i].endereco.estado);
        printf("CEP: %s\n", clientes[i].endereco.cep);

    }
}

void alterarCliente(int posicaoAlterar, Cliente clientes[], int qtdClientes){

    char alterar;

    if(posicaoAlterar < 0 || posicaoAlterar >= qtdClientes){
        printf("Posicao invalida!\n");
        return;
    }

    printf("Deseja alterar o nome? (S/N) ");
    scanf(" %c", &alterar);
    getchar();

    if(alterar == 'S'){
        printf("Nome: ");
        fgets(clientes[posicaoAlterar].nome, 50, stdin);
    }

    printf("Deseja alterar a razao social? (S/N) ");
    scanf(" %c", &alterar);
    getchar();

    if(alterar == 'S'){
        printf("Razao Social: ");
        fgets(clientes[posicaoAlterar].razaoSocial, 80, stdin);
    }

    printf("Deseja alterar a inscricao estadual? (S/N) ");
    scanf(" %c", &alterar);

    if(alterar == 'S'){
        printf("Inscricao Estadual: ");
        scanf("%19s", clientes[posicaoAlterar].inscricaoEstadual);
    }

    printf("Deseja alterar o telefone? (S/N) ");
    scanf(" %c", &alterar);

    if(alterar == 'S'){
        printf("Telefone: ");
        scanf("%19s", clientes[posicaoAlterar].telefone);
    }

    printf("Deseja alterar o e-mail? (S/N) ");
    scanf(" %c", &alterar);

    if(alterar == 'S'){
        printf("E-mail: ");
        scanf("%59s", clientes[posicaoAlterar].email);
    }

    printf("Deseja alterar o contato? (S/N) ");
    scanf(" %c", &alterar);
    getchar();

    if(alterar == 'S'){
        printf("Contato: ");
        fgets(clientes[posicaoAlterar].contato, 50, stdin);
    }

    printf("\nENDERECO\n");

    printf("Deseja alterar a rua? (S/N) ");
    scanf(" %c", &alterar);
    getchar();

    if(alterar == 'S'){
        printf("Rua: ");
        fgets(clientes[posicaoAlterar].endereco.rua, 50, stdin);
    }

    printf("Deseja alterar a cidade? (S/N) ");
    scanf(" %c", &alterar);
    getchar();

    if(alterar == 'S'){
        printf("Cidade: ");
        fgets(clientes[posicaoAlterar].endereco.cidade, 40, stdin);
    }

    printf("Deseja alterar o estado? (S/N) ");
    scanf(" %c", &alterar);

    if(alterar == 'S'){
        printf("Estado: ");
        scanf("%2s", clientes[posicaoAlterar].endereco.estado);
    }

    printf("Deseja alterar o CEP? (S/N) ");
    scanf(" %c", &alterar);

    if(alterar == 'S'){
        printf("CEP: ");
        scanf("%9s", clientes[posicaoAlterar].endereco.cep);
    }

}

void inserirPedido(Pedido pedidos[], int *qtdPedidos){

    int contItem = 0;
    int i, opcaoPagamento;
    float totalPedido = 0;
    char adicionarItem = 'S';

    if(*qtdPedidos >= MAX_PEDIDOS){
        printf("Limite de pedidos atingido!\n");
        return;
    }

    pedidos[*qtdPedidos].quantidadeItens = 0;

    printf("\nPEDIDO\n");

    printf("Numero do Pedido: ");
    scanf("%d", &pedidos[*qtdPedidos].numeroPedido);

    printf("CNPJ do Cliente: ");
    scanf("%19s", pedidos[*qtdPedidos].cnpj);

    printf("Data do Pedido (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &pedidos[*qtdPedidos].dataPedido.dia, &pedidos[*qtdPedidos].dataPedido.mes, &pedidos[*qtdPedidos].dataPedido.ano);

    printf("Data da Entrega (dd/mm/aaaa ou 0/0/0 se ainda nao entregue): ");
    scanf("%d/%d/%d", &pedidos[*qtdPedidos].dataEntrega.dia, &pedidos[*qtdPedidos].dataEntrega.mes, &pedidos[*qtdPedidos].dataEntrega.ano);

    printf("Previsao de Entrega: ");
    scanf("%d", &pedidos[*qtdPedidos].previsaoEntrega);
    getchar();

    printf("\nItem %d\n", contItem + 1);
    printf("Descricao: ");
    fgets(pedidos[*qtdPedidos].descricao[contItem], TAM_DESC, stdin);
    printf("Quantidade: ");
    scanf("%d", &pedidos[*qtdPedidos].quantidade[contItem]);
    printf("Valor: ");
    scanf("%f", &pedidos[*qtdPedidos].valorItem[contItem]);
    contItem++;
    pedidos[*qtdPedidos].quantidadeItens += 1;

    while(adicionarItem != 'N' && contItem < 6){
        printf("\nAdicionar mais um item? (S/N) ");
        scanf(" %c", &adicionarItem);
        getchar();

        if(adicionarItem == 'S'){
            printf("\nItem %d\n", contItem + 1);
            printf("Descricao: ");
            fgets(pedidos[*qtdPedidos].descricao[contItem], TAM_DESC, stdin);
            printf("Quantidade: ");
            scanf("%d", &pedidos[*qtdPedidos].quantidade[contItem]);
            printf("Valor: ");
            scanf("%f", &pedidos[*qtdPedidos].valorItem[contItem]);
            contItem++;
            pedidos[*qtdPedidos].quantidadeItens += 1;
        }
    }

    for(i = 0; i < pedidos[*qtdPedidos].quantidadeItens; i++){
        totalPedido += pedidos[*qtdPedidos].quantidade[i] * pedidos[*qtdPedidos].valorItem[i];
    }

    pedidos[*qtdPedidos].totalPedido = totalPedido;

    printf("\nValor total: %.2f\n", pedidos[*qtdPedidos].totalPedido);

    printf("Formas de Pagamento:\n");
    printf("1 - A vista\n");
    printf("2 - Duplicata\n");
    printf("Opcao: ");
    scanf("%d", &opcaoPagamento);

    if(opcaoPagamento == 1){
        strcpy(pedidos[*qtdPedidos].formaPagamento, "A vista");
       
    } else if(opcaoPagamento == 2){
        strcpy(pedidos[*qtdPedidos].formaPagamento, "Duplicata");
    }

    (*qtdPedidos)++;
}

void alterarPedido(int posicaoAlterar, Pedido pedidos[], int qtdPedidos){
    char alterar;
    char alterarItem = 'S';
    int posicaoItem = 0;
    int quantidadeAntiga;
    int opcaoPagamento;
    int itemAlterado = 0;
    float valorAntigo;

    if(posicaoAlterar < 0 || posicaoAlterar >= qtdPedidos){
        printf("Posicao invalida!\n");
        return;
    }

    while(alterarItem != 'N'){
        printf("Deseja alterar algum item? (S/N) ");
        scanf(" %c", &alterarItem);

        if(alterarItem == 'S'){
            posicaoItem = 0;

            while(posicaoItem < 1 || posicaoItem > pedidos[posicaoAlterar].quantidadeItens){
                printf("Qual item deseja alterar? 1 a %d\n", pedidos[posicaoAlterar].quantidadeItens);
                scanf("%d", &posicaoItem);
            }

            printf("Deseja alterar a descricao? (S/N) ");
            scanf(" %c", &alterar);
            getchar();

            if(alterar == 'S'){
                printf("Descricao: ");
                fgets(pedidos[posicaoAlterar].descricao[posicaoItem - 1], TAM_DESC, stdin);
                itemAlterado = 1;
            }

            printf("Deseja alterar a quantidade? (S/N) ");
            scanf(" %c", &alterar);

            if(alterar == 'S'){
                quantidadeAntiga = pedidos[posicaoAlterar].quantidade[posicaoItem - 1];
                printf("Quantidade: ");
                scanf("%d", &pedidos[posicaoAlterar].quantidade[posicaoItem - 1]);
                pedidos[posicaoAlterar].totalPedido += (pedidos[posicaoAlterar].quantidade[posicaoItem - 1]*pedidos[posicaoAlterar].valorItem[posicaoItem - 1]) - (quantidadeAntiga*pedidos[posicaoAlterar].valorItem[posicaoItem - 1]);
                itemAlterado = 1;
            }

            printf("Deseja alterar o valor? (S/N) ");
            scanf(" %c", &alterar);

            if(alterar == 'S'){
                valorAntigo = pedidos[posicaoAlterar].valorItem[posicaoItem - 1];
                printf("Valor: ");
                scanf("%f", &pedidos[posicaoAlterar].valorItem[posicaoItem - 1]);
                pedidos[posicaoAlterar].totalPedido += (pedidos[posicaoAlterar].quantidade[posicaoItem - 1]*pedidos[posicaoAlterar].valorItem[posicaoItem - 1]) - (valorAntigo*pedidos[posicaoAlterar].quantidade[posicaoItem - 1]);
                itemAlterado = 1;
            }

            if(itemAlterado == 1){
                printf("\nItem alterado com sucesso!\n");
            }
        }

    }

    printf("Deseja alterar a data da entrega? (S/N) ");
    scanf(" %c", &alterar);

    if(alterar == 'S'){
        printf("Data da Entrega (dd/mm/aaaa ou 0/0/0 se ainda nao entregue): ");
        scanf("%d/%d/%d", &pedidos[posicaoAlterar].dataEntrega.dia, &pedidos[posicaoAlterar].dataEntrega.mes, &pedidos[posicaoAlterar].dataEntrega.ano);
    }

    printf("Deseja alterar a previsao de entrega? (S/N) ");
    scanf(" %c", &alterar);

    if(alterar == 'S'){
        printf("Previsao de Entrega: ");
        scanf("%d", &pedidos[posicaoAlterar].previsaoEntrega);
    }

    printf("\nValor total: %.2f\n", pedidos[posicaoAlterar].totalPedido);

    printf("Deseja alterar a forma de pagamento? (S/N) ");
    scanf(" %c", &alterar);

    if(alterar == 'S'){
        printf("Formas de Pagamento:\n");
        printf("1 - A vista\n");
        printf("2 - Duplicata\n");
        printf("Opcao: ");
        scanf("%d", &opcaoPagamento);

        if(opcaoPagamento == 1){
            strcpy(pedidos[posicaoAlterar].formaPagamento, "A vista");
        
        } else if(opcaoPagamento == 2){
            strcpy(pedidos[posicaoAlterar].formaPagamento, "Duplicata");
        }
    }

}

void excluirPedido(int posicaoRemover, Pedido pedidos[], int *qtdPedidos){
    if(posicaoRemover < 0 || posicaoRemover >= *qtdPedidos){
        printf("Posicao invalida!\n");
        return;
    }

    for(int i = posicaoRemover; i < *qtdPedidos - 1; i++){
        pedidos[i] = pedidos[i + 1];
    }

    (*qtdPedidos)--;

    printf("Pedido removido!\n");
}

void consultarPedidosCliente(Pedido pedidos[], int qtdPedidos, char cnpj[]){
    int i, j;
    for(i = 0; i < qtdPedidos; i++){
        if(strcmp(pedidos[i].cnpj, cnpj) == 0){
            printf("\nPEDIDO\n");
            printf("Numero do pedido: %d\n", pedidos[i].numeroPedido);
            printf("CNPJ do cliente: %s\n", pedidos[i].cnpj);
            printf("Data do pedido: %d/%d/%d\n", pedidos[i].dataPedido.dia, pedidos[i].dataPedido.mes, pedidos[i].dataPedido.ano);
            printf("Data da entrega: %d/%d/%d\n", pedidos[i].dataEntrega.dia, pedidos[i].dataEntrega.mes, pedidos[i].dataEntrega.ano);
            printf("Previsao de entrega: %d dias\n", pedidos[i].previsaoEntrega);

            for(j = 0; j < pedidos[i].quantidadeItens; j++){
                printf("\nItem %d\n", j+1);
                printf("Descricao: %s", pedidos[i].descricao[j]);
                printf("Quantidade: %d\n", pedidos[i].quantidade[j]);
                printf("Valor: %.2f\n", pedidos[i].valorItem[j]);
            }

            printf("\nValor total do pedido: %.2f\n", pedidos[i].totalPedido);
            printf("Forma de pagamento: %s\n", pedidos[i].formaPagamento);
        }
    }
}

int converteData(Data data){
    return data.ano * 10000 + data.mes * 100 + data.dia;
}

void consultarPedidosIntervalo(Pedido pedidos[], int qtdPedidos, Data dataInicial, Data dataFinal){
    int dataInicio = converteData(dataInicial);
    int dataFim = converteData(dataFinal);
    int dataPedido;
    int i, j;

    for(i = 0; i < qtdPedidos; i++){
        dataPedido = converteData(pedidos[i].dataPedido);
        if(dataPedido >= dataInicio && dataPedido <= dataFim){
            printf("\nPEDIDO\n");
            printf("Numero do pedido: %d\n", pedidos[i].numeroPedido);
            printf("CNPJ do cliente: %s\n", pedidos[i].cnpj);
            printf("Data do pedido: %d/%d/%d\n", pedidos[i].dataPedido.dia, pedidos[i].dataPedido.mes, pedidos[i].dataPedido.ano);
            printf("Data da entrega: %d/%d/%d\n", pedidos[i].dataEntrega.dia, pedidos[i].dataEntrega.mes, pedidos[i].dataEntrega.ano);
            printf("Previsao de entrega: %d dias\n", pedidos[i].previsaoEntrega);

            for(j = 0; j < pedidos[i].quantidadeItens; j++){
                printf("\nItem %d\n", j+1);
                printf("Descricao: %s", pedidos[i].descricao[j]);
                printf("Quantidade: %d\n", pedidos[i].quantidade[j]);
                printf("Valor: %.2f\n", pedidos[i].valorItem[j]);
            }

            printf("\nValor total do pedido: %.2f\n", pedidos[i].totalPedido);
            printf("Forma de pagamento: %s\n", pedidos[i].formaPagamento);
        }
    }
}

void consultarPedidosAPartirDe(Pedido pedidos[], int qtdPedidos, Data dataEntrada){
    int dataInicio = converteData(dataEntrada);
    int dataEntrega;
    int i, j;

    for(i = 0; i < qtdPedidos; i++){
        dataEntrega = converteData(pedidos[i].dataEntrega);
        if(dataEntrega >= dataInicio){
            printf("\nPEDIDO\n");
            printf("Numero do pedido: %d\n", pedidos[i].numeroPedido);
            printf("CNPJ do cliente: %s\n", pedidos[i].cnpj);
            printf("Data do pedido: %d/%d/%d\n", pedidos[i].dataPedido.dia, pedidos[i].dataPedido.mes, pedidos[i].dataPedido.ano);
            printf("Data da entrega: %d/%d/%d\n", pedidos[i].dataEntrega.dia, pedidos[i].dataEntrega.mes, pedidos[i].dataEntrega.ano);
            printf("Previsao de entrega: %d dias\n", pedidos[i].previsaoEntrega);

            for(j = 0; j < pedidos[i].quantidadeItens; j++){
                printf("\nItem %d\n", j+1);
                printf("Descricao: %s", pedidos[i].descricao[j]);
                printf("Quantidade: %d\n", pedidos[i].quantidade[j]);
                printf("Valor: %.2f\n", pedidos[i].valorItem[j]);
            }

            printf("\nValor total do pedido: %.2f\n", pedidos[i].totalPedido);
            printf("Forma de pagamento: %s\n", pedidos[i].formaPagamento);
        }
    }    
}

Data calculaDataPrevista(Data dataPedido, int dias){
    Data dataPrevista = dataPedido;
    int diasNoMes;

    while(dias > 0){
        if(dataPrevista.mes == 2){
            if((dataPrevista.ano % 400 == 0) ||
            (dataPrevista.ano % 4 == 0 && dataPrevista.ano % 100 != 0)){
                diasNoMes = 29;
            } else {
                diasNoMes = 28;
            }
        } else if(dataPrevista.mes == 4 || dataPrevista.mes == 6 ||
            dataPrevista.mes == 9 || dataPrevista.mes == 11){
            diasNoMes = 30;
        } else {
            diasNoMes = 31;
        }

        dataPrevista.dia++;

        if(dataPrevista.dia > diasNoMes){
            dataPrevista.dia = 1;
            dataPrevista.mes++;
        }

        if(dataPrevista.mes > 12){
            dataPrevista.mes = 1;
            dataPrevista.ano++;
        }
        dias--;
    }
    return dataPrevista;
}

void consultarPedidosEmAberto(Pedido pedidos[], int qtdPedidos){
    int dataEntrega, dataPrevistaConvertida, dataAtualConvertida;
    Data dataPrevista, dataAtual;
    int i, j;
    time_t agora = time(NULL);
    struct tm *dataSistema = localtime(&agora);

    dataAtual.dia = dataSistema->tm_mday;
    dataAtual.mes = dataSistema->tm_mon + 1;
    dataAtual.ano = dataSistema->tm_year + 1900;

    printf("\nPEDIDO EM ABERTO ATRASADOS\n");

    for(i = 0; i < qtdPedidos; i++){
        dataEntrega = converteData(pedidos[i].dataEntrega);
        if(dataEntrega == 0){

            dataPrevista = calculaDataPrevista(pedidos[i].dataPedido, pedidos[i].previsaoEntrega);
            dataPrevistaConvertida = converteData(dataPrevista);
            dataAtualConvertida = converteData(dataAtual);
            
            if(dataPrevistaConvertida < dataAtualConvertida){
                printf("\nPEDIDO\n");
                printf("Numero do pedido: %d\n", pedidos[i].numeroPedido);
                printf("CNPJ do cliente: %s\n", pedidos[i].cnpj);
                printf("Data do pedido: %d/%d/%d\n", pedidos[i].dataPedido.dia, pedidos[i].dataPedido.mes, pedidos[i].dataPedido.ano);
                printf("Data da entrega: Ainda nao entregue\n");
                printf("Previsao de entrega: %d dias\n", pedidos[i].previsaoEntrega);

                for(j = 0; j < pedidos[i].quantidadeItens; j++){
                    printf("\nItem %d\n", j+1);
                    printf("Descricao: %s", pedidos[i].descricao[j]);
                    printf("Quantidade: %d\n", pedidos[i].quantidade[j]);
                    printf("Valor: %.2f\n", pedidos[i].valorItem[j]);
                }

                printf("\nValor total do pedido: %.2f\n", pedidos[i].totalPedido);
                printf("Forma de pagamento: %s\n", pedidos[i].formaPagamento);
            }
        }
    }

    printf("\nPEDIDO EM ABERTO NO PRAZO\n");

    for(i = 0; i < qtdPedidos; i++){
        dataEntrega = converteData(pedidos[i].dataEntrega);
        if(dataEntrega == 0){

            dataPrevista = calculaDataPrevista(pedidos[i].dataPedido, pedidos[i].previsaoEntrega);
            dataPrevistaConvertida = converteData(dataPrevista);
            dataAtualConvertida = converteData(dataAtual);
            
            if(dataPrevistaConvertida >= dataAtualConvertida){
                printf("\nPEDIDO\n");
                printf("Numero do pedido: %d\n", pedidos[i].numeroPedido);
                printf("CNPJ do cliente: %s\n", pedidos[i].cnpj);
                printf("Data do pedido: %d/%d/%d\n", pedidos[i].dataPedido.dia, pedidos[i].dataPedido.mes, pedidos[i].dataPedido.ano);
                printf("Data da entrega: Ainda nao entregue\n");
                printf("Previsao de entrega: %d dias\n", pedidos[i].previsaoEntrega);

                for(j = 0; j < pedidos[i].quantidadeItens; j++){
                    printf("\nItem %d\n", j+1);
                    printf("Descricao: %s", pedidos[i].descricao[j]);
                    printf("Quantidade: %d\n", pedidos[i].quantidade[j]);
                    printf("Valor: %.2f\n", pedidos[i].valorItem[j]);
                }

                printf("\nValor total do pedido: %.2f\n", pedidos[i].totalPedido);
                printf("Forma de pagamento: %s\n", pedidos[i].formaPagamento);
            }
        }
    }   
}

void consultarMediaMensalCliente(Pedido pedidos[], int qtdPedidos, char cnpj[]){
    float totalMes[20][12] = {0};
    int anos[20] = {0};
    int i, j;
    int contMeses = 0;
    int contAnos = 0;
    float somaMeses = 0;
    float media;

    for(i = 0; i < qtdPedidos; i++){
        if(strcmp(pedidos[i].cnpj, cnpj) == 0){
            int indiceAno = -1;

            for(j = 0; j < contAnos; j++){
                if(anos[j] == pedidos[i].dataPedido.ano){
                    indiceAno = j;
                    break;
                }
            }

            if(indiceAno == -1){
                anos[contAnos] = pedidos[i].dataPedido.ano;
                indiceAno = contAnos;
                contAnos++;
            }
            totalMes[indiceAno][pedidos[i].dataPedido.mes - 1] += pedidos[i].totalPedido;
        }
    }

    for(i = 0; i < contAnos; i++){
        for(j = 0; j < 12; j++){
            if(totalMes[i][j] > 0){
                contMeses++;
                somaMeses += totalMes[i][j];
            }
        }
    }

    if(contMeses > 0){
        media = somaMeses/contMeses;
        printf("Media mensal do cliente: %.2f\n", media);
    } else{
        printf("Nao ha valores para esse cliente!\n");
    }

}

void carregarClientes(Cliente clientes[], int *qtdClientes){
    FILE *arquivo;
    arquivo = fopen("Cliente.dat", "rb");

    if(arquivo == NULL){
        *qtdClientes = 0;
        return;
    }

    while(*qtdClientes < MAX_CLIENTES && fread(&clientes[*qtdClientes], sizeof(Cliente), 1, arquivo) == 1){
        (*qtdClientes)++;
    }

    fclose(arquivo);
}

void salvarClientes(Cliente clientes[], int qtdClientes){
    FILE *arquivo;
    arquivo = fopen("Cliente.dat", "wb");
    int i;

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    for(i = 0; i < qtdClientes; i++){
        fwrite(&clientes[i], sizeof(Cliente), 1, arquivo);
    }

    printf("Dados gravados com sucesso!\n");

    fclose(arquivo);

}

void carregarPedidos(Pedido pedidos[], int *qtdPedidos){
    FILE *arquivo;
    arquivo = fopen("Pedido.dat", "rb");

    if(arquivo == NULL){
        *qtdPedidos = 0;
        return;
    }

    while(*qtdPedidos < MAX_PEDIDOS && fread(&pedidos[*qtdPedidos], sizeof(Pedido), 1, arquivo) == 1){
        (*qtdPedidos)++;
    }

    fclose(arquivo);
}

void salvarPedidos(Pedido pedidos[], int qtdPedidos){
    FILE *arquivo;
    arquivo = fopen("Pedido.dat", "wb");
    int i;

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    for(i = 0; i < qtdPedidos; i++){
        fwrite(&pedidos[i], sizeof(Pedido), 1, arquivo);
    }

    printf("Dados gravados com sucesso!\n");

    fclose(arquivo);

}

int main(){
    Cliente clientes[MAX_CLIENTES];
    Pedido pedidos[MAX_PEDIDOS];

    int qtdClientes = 0;
    int qtdPedidos = 0;

    carregarClientes(clientes, &qtdClientes);
    carregarPedidos(pedidos, &qtdPedidos);

    int opcao = -1;
    int opcaoCliente = -1;
    int opcaoPedido = -1;
    int posicao;
    char cnpj[20];
    Data dataInicial, dataFinal;

    while(opcao != 0){
        printf("\nMENU\n");
        printf("1 - Clientes\n");
        printf("2 - Pedidos\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        if(opcao == 1){
            opcaoCliente = -1;
            while(opcaoCliente != 0){
                printf("\nMENU CLIENTES\n");
                printf("1 - Inserir cliente\n");
                printf("2 - Consultar clientes\n");
                printf("3 - Alterar cliente\n");
                printf("4 - Excluir cliente\n");
                printf("0 - Voltar\n");
                printf("Opcao: ");
                scanf("%d", &opcaoCliente);

                if(opcaoCliente == 1){
                    inserirClientes(clientes, &qtdClientes);
                    salvarClientes(clientes, qtdClientes);
                } else if(opcaoCliente == 2){
                    consultarClientes(clientes, qtdClientes);
                } else if(opcaoCliente == 3){
                    printf("Posicao do cliente que deseja alterar (a partir do 1): ");
                    scanf("%d", &posicao);
                    alterarCliente(posicao - 1, clientes, qtdClientes);
                    salvarClientes(clientes, qtdClientes);
                } else if(opcaoCliente == 4){
                    printf("Posicao do cliente que deseja excluir (a partir do 1): ");
                    scanf("%d", &posicao);
                    excluirCliente(posicao - 1, clientes, &qtdClientes);
                    salvarClientes(clientes, qtdClientes);
                }
            }
        } else if(opcao == 2){
            opcaoPedido = -1;
            while(opcaoPedido != 0){
                printf("\nMENU PEDIDOS\n");
                printf("1 - Inserir pedido\n");
                printf("2 - Alterar pedido\n");
                printf("3 - Excluir pedido\n");
                printf("4 - Consultar pedidos de um cliente\n");
                printf("5 - Consultar pedidos entre duas datas\n");
                printf("6 - Consultar pedidos entregues a partir de uma data\n");
                printf("7 - Consultar pedidos em aberto\n");
                printf("8 - Media mensal de valores comprados pelo cliente\n");
                printf("0 - Voltar\n");
                printf("Opcao: ");
                scanf("%d", &opcaoPedido);

                if(opcaoPedido == 1){
                    inserirPedido(pedidos, &qtdPedidos);
                    salvarPedidos(pedidos, qtdPedidos);
                } else if(opcaoPedido == 2){
                    printf("Posicao do pedido que deseja alterar (a partir do 1): ");
                    scanf("%d", &posicao);
                    alterarPedido(posicao - 1, pedidos, qtdPedidos);
                    salvarPedidos(pedidos, qtdPedidos);
                } else if(opcaoPedido == 3){
                    printf("Posicao do pedido que deseja excluir (a partir do 1): ");
                    scanf("%d", &posicao);
                    excluirPedido(posicao - 1, pedidos, &qtdPedidos);
                    salvarPedidos(pedidos, qtdPedidos);
                } else if(opcaoPedido == 4){
                    printf("CNPJ do cliente: ");
                    scanf("%19s", cnpj);
                    consultarPedidosCliente(pedidos, qtdPedidos, cnpj);
                } else if(opcaoPedido == 5){
                    printf("Data inicial (dd/mm/aaaa): ");
                    scanf("%d/%d/%d", &dataInicial.dia, &dataInicial.mes, &dataInicial.ano);
                    printf("Data final (dd/mm/aaaa): ");
                    scanf("%d/%d/%d", &dataFinal.dia, &dataFinal.mes, &dataFinal.ano);
                    consultarPedidosIntervalo(pedidos, qtdPedidos, dataInicial, dataFinal);
                } else if(opcaoPedido == 6){
                    printf("Data inicial (dd/mm/aaaa): ");
                    scanf("%d/%d/%d", &dataInicial.dia, &dataInicial.mes, &dataInicial.ano);
                    consultarPedidosAPartirDe(pedidos, qtdPedidos, dataInicial);
                } else if(opcaoPedido == 7){
                    consultarPedidosEmAberto(pedidos,qtdPedidos);
                } else if(opcaoPedido == 8){
                    printf("CNPJ do cliente: ");
                    scanf("%19s", cnpj);
                    consultarMediaMensalCliente(pedidos, qtdPedidos, cnpj);
                }
            }
        }
    }
}