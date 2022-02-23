#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>
int numlin;
//struct contendo as informações do endereço do cliente
struct endereco{
	char rua[35]
	int numero;
	int cep;
	char bairro[35];
};
//struct contendo as informações pessoais do cliente
struct agenda{
	char nome[35];
	int telefone;
	char email[35];
	int codigo;
	int idade;
	int cpf;
	char ocupacao[35];
	struct endereco info;
};
//funcao para impressão do menu principal
void menu()
{
    printf("Escolha uma opcao: \n");
    printf("\n(1) Incluir novo regristro");
    printf("\n(2) Alterar um registro existente");
    printf("\n(3) Excluir um registro");
    printf("\n(4) Consultar um registro");
    printf("\n(5) Listar todos os registros");
    printf("\n(6) Gravar no arquivo");
    printf("\n(7) Sair\n\n");
}
//função para alterar os dados de um registro existente
void alterar(struct agenda *ag, int end_i, char alt_nome[],int alt_telefone,char alt_email[],int alt_codigo,int alt_idade,int alt_cpf,char alt_ocupacao[],char alt_rua[],int alt_numero,int alt_cep,char alt_bairro[],int a1,int a2,int a3,int a4,int a5,int a6,int a7,int a8,int a9, int a10, int a11)
{
	int i;
	i = end_i;
	//dependendo do que escolher, uma informação existente recebe uma nova
	if(a1==1){
		strcpy(ag[i].nome,alt_nome);//como por exemplo aqui, nome recebe alt_nome, que é lido ao escolher trocar o nome
	}
	if(a2==1){
		ag[i].telefone = alt_telefone;
	}
	if(a3==1){
		strcpy(ag[i].email, alt_email);
	}
	if(a4==1){
		ag[i].codigo = alt_codigo;
	}
	if(a5==1){
		ag[i].idade = alt_idade;
	}
	if(a6==1){
		ag[i].cpf = alt_cpf;
	}
	if(a7==1){
		strcpy(ag[i].ocupacao,alt_ocupacao);
	}
	if(a8==1){
		strcpy(ag[i].info.rua,alt_rua);
	}
	if(a9==1){
		ag[i].info.numero = alt_numero;
	}
	if(a10==1){
		ag[i].info.cep = alt_cep;
	}
	if(a11==1){
		strcpy(ag[i].info.bairro,alt_bairro);
	}
}
//função para consultar um registro utilizando um código do cliente
void consultar(struct agenda *ag,int codigo_consulta)
{
	int i,aux=0;
	for(i=0;i<numlin;i++){ //percorre a estrutura, comparando o código fornecido com o código dos clientes armazenados na estrutura
		if(ag[i].codigo == codigo_consulta){ //se encontra o código, ele exibe as informações
			printf("\n Os dados do registro de codigo %d eh\n",ag[i].codigo);
			printf("Nome: %s\n",ag[i].nome);
			printf("Telefone: %d\n",ag[i].telefone);
			printf("Email: %s\n",ag[i].email);
			printf("Codigo: %d\n",ag[i].codigo);
			printf("Idade: %d\n",ag[i].idade);
			printf("Cpf: %d\n",ag[i].cpf);
			printf("Ocupacao: %s\n",ag[i].ocupacao);
			printf("Em relacao a residencia do cliente:\n");
			printf("Rua: %s\n",ag[i].info.rua);
			printf("Numero: %d\n",ag[i].info.numero);
			printf("Cep: %d\n",ag[i].info.cep);
			printf("Bairro: %s\n",ag[i].info.bairro);
			aux++;
        }
	}
	if(aux==0){ // se o codigo nao for encontrado na estrutura, exibe mensagem de erro
		printf("O codigo em questao (%d) nao foi encontrado\n",codigo_consulta);
	}
	system("pause");
	system("cls");
}
//funcao para excluir um cliente da estrutura
void excluir(struct agenda *ag,int codigo_exlcui)
{
	int i,j=0,achou=0;
    for(i=0;i<numlin;i++){ //procura o código inserido na estrutura
        if(codigo_exlcui == ag[i].codigo){ //se encontra, começa o processo de exclusao
            printf("Registro excluido\n");
            system("pause");
            system("cls");

			j=i;
			while(j < numlin){// O processo consiste em atribuir o proximo registro para o atual
				strcpy(ag[j].email, ag[j+1].email);
				strcpy(ag[j].info.bairro,ag[j+1].info.bairro);
				strcpy(ag[j].nome,ag[j+1].nome);
				ag[j].telefone = ag[j+1].telefone;
				ag[j].codigo = ag[j+1].codigo;
				ag[j].idade = ag[j+1].idade;
				ag[j].cpf = ag[j+1].cpf;
				strcpy(ag[j].ocupacao,ag[j+1].ocupacao);
				strcpy(ag[j].info.rua,ag[j+1].info.rua);
				ag[j].info.numero = ag[j+1].info.numero;
				ag[j].info.cep = ag[j+1].info.cep;
				j++;
			}
			achou++;
			numlin --;
			break;
        }
    }
     // se nao encontra o código, exibe mensagem de erro
        if(achou==0){
        	printf("Registro inexistente\n");
            system("pause");
            system("cls");	
		}
}
//funcao para listar os clientes na estrutura
void listar(struct agenda *ag)
{
	int i;
	if(numlin==0) //se não há nenhum elemento na estrutura, exibirá uma mensagem de erro
    {
        printf("Nao ha registros para listar\n\n");
    }
    for(i=0;i<numlin;i++){ //se existe algo na estrutura, ela será exibida
        printf("\n\t\t--------------------Cliente %d--------------------\n",i);
		printf("Nome: %s\n",ag[i].nome);
		printf("Telefone: %d\n",ag[i].telefone);
		printf("Email: %s\n",ag[i].email);
		printf("Codigo: %d\n",ag[i].codigo);
		printf("Idade: %d\n",ag[i].idade);
		printf("Cpf: %d\n",ag[i].cpf);
		printf("Ocupacao: %s\n",ag[i].ocupacao);
		printf("Em relacao a residencia do cliente:\n");
		printf("Rua:%s\n",ag[i].info.rua);
		printf("Numero: %d\n",ag[i].info.numero);
		printf("Cep: %d\n",ag[i].info.cep);
		printf("Bairro: %s\n",ag[i].info.bairro);
    }
    system("pause");
	system("cls");
}
//funcao para salvar a estrutura em um arquivo
void gravar(struct agenda *ag)
{
	FILE *file;
	file = fopen("bancodados.dat","w");
	if(file==NULL){
		printf("Erro ao abrir o arquivo\n");
	}
	int i,limitador=0,total;

	for(i=0;i<numlin;i++){
        
        //insere as informações dentro do arquivo
		fprintf(file,"%d\n",i);
        fprintf(file,"%s\n",ag[i].nome);
        fprintf(file,"%d\n",ag[i].telefone);
		fprintf(file,"%s\n",ag[i].email);
		fprintf(file,"%d\n",ag[i].codigo);
		fprintf(file,"%d\n",ag[i].idade);
		fprintf(file,"%d\n",ag[i].cpf);
		fprintf(file,"%s\n",ag[i].ocupacao);
		fprintf(file,"%s\n",ag[i].info.rua);
		fprintf(file,"%d\n",ag[i].info.numero);
        fprintf(file,"%d\n",ag[i].info.cep);
        fprintf(file,"%s\n",ag[i].info.bairro);

        limitador = limitador + 12; //cada cliente ocupa 12 linhas no arquivo
        total = (numlin *12);
        if(limitador==total){
            fclose(file);
            break;
        }
    }
    printf("Arquivo salvo com sucesso\nAperte uma tecla para voltar ao menu\n");
    system("pause");
    system("cls");
    fclose(file);
}
//função para contar quantas linhas tem no arquivo
int nlinhas(FILE *file)
{
    int contnlinhas=1;
	char var;
	while( (var = fgetc(file)) != EOF){
        if(var=='\n')
            contnlinhas++;
	}
	return contnlinhas;
}
//funcao para carregar os dados do arquivo
struct agenda* carregar()
{
	struct agenda *ag;
	char aux[20],aux2[20];
	int i=0,cont=0;
	char lixo[35];
	FILE *file;
	file = fopen("bancodados.dat","r");
	if(file==NULL){
		printf("Erro ao abrir o arquivo\n");
	}
	numlin = nlinhas(file);
	numlin = numlin/12; //conta quantos clientes tem no arquivo
	ag = (struct agenda*) malloc (numlin * sizeof ( struct agenda)); //aloca memoria
	rewind(file);
	while( i < numlin){ //le as informações do arquivo, enquanto nao ultrapassa a quantidade de clientes existentes
	    fscanf(file," %d",&cont);
		fscanf(file," %s",ag[i].nome);
		fscanf(file," %d",&ag[i].telefone);
		fscanf(file," %s",ag[i].email);
		fscanf(file," %d",&ag[i].codigo);
		fscanf(file," %d",&ag[i].idade);
		fscanf(file," %d",&ag[i].cpf);
		fscanf(file," %s",ag[i].ocupacao);
		fscanf(file," %s",ag[i].info.rua);
		fscanf(file," %d",&ag[i].info.numero);
		fscanf(file," %d",&ag[i].info.cep);
		fscanf(file," %s",ag[i].info.bairro);
		i++;
    }
	fclose(file);
    return ag;
}
//funcao para incluir um novo cliente na estrutura
struct agenda* incluir(struct agenda* ag,char aux_email[],char aux_nome[],char aux_rua[],char aux_bairro[], char aux_ocupacao[],int numero,int cep,int telefone,int codigo,int idade,int cpf)
{
	int i;
	numlin += 1;
	ag = (struct agenda*) realloc( ag , (numlin* sizeof(struct agenda)));
	i = numlin-1; // é feito isso pois o i começa com 0
    strcpy(ag[i].email, aux_email);
    strcpy(ag[i].info.bairro,aux_bairro);
    strcpy(ag[i].nome,aux_nome);
    ag[i].telefone = telefone;
    ag[i].codigo = codigo;
	ag[i].idade = idade;
	ag[i].cpf = cpf;
	strcpy(ag[i].ocupacao,aux_ocupacao);
	strcpy(ag[i].info.rua,aux_rua);
	ag[i].info.numero = numero;
	ag[i].info.cep = cep;
	return ag;

}

int main(){
	struct agenda *ag;
	int op=0,end_i,i,codigo_alteracao,codigo_exclui,codigo_consulta,op_cad,numero,cep,telefone,codigo,idade,cpf,alt_esc=10;
	char aux_email[35],aux_rua[35],aux_bairro[35],aux_ocupacao[35],aux_nome[35];
	char alt_nome[35],alt_email[35],alt_ocupacao[35],alt_rua[35],alt_bairro[35];
	int	alt_telefone,alt_codigo,alt_idade,alt_cpf,alt_numero,alt_cep;
	int a1=0,a2=0,a3=0,a4=0,a5=0,a6=0,a7=0,a8=0,a9=0,a10=0,a11=0,existe=0;

	ag = carregar(); //carrega os dados do arquivo
	system ("color F1"); // Alterar a cor
	while(op!=7)
    {
        menu(); //abre o menu principal
        scanf("%d",&op); //le a opcao do menu
        if(op<=0 || op>=8){
            printf("\nEscolha invalida! pressione um botao para tentar novamente.\n\n");
            system("pause");
            system("cls");
        }
        if(op==1){ //inclui novo registro
            system("cls");
			do{
                printf("Incluir novo registro\n\n");
				printf("Nome: ");
                fflush(stdin);
                gets(aux_nome);
                fflush(stdin);
				printf("\nTelefone: ");
                scanf("%d",&telefone);
				printf("\nEmail: ");
                fflush(stdin);
                gets(aux_email);
	            fflush(stdin);
				printf("\nCodigo: ");
				scanf("%d",&codigo);
				printf("\nIdade: ");
				scanf("%d",&idade);
				printf("\nCPF: ");
				scanf("%d",&cpf);
				printf("\nOcupacao: ");
				fflush(stdin);
				gets(aux_ocupacao);
	            fflush(stdin);
				printf("\nEm relacao a residencia:\n");
				printf("\nRua: ");
                fflush(stdin);
				gets(aux_rua);
	            fflush(stdin);
				printf("\nNumero: ");
				scanf("%d",&numero);
				printf("\nCEP: ");
				scanf("%d",&cep);
				printf("\nBairro: ");
				fflush(stdin);
				gets(aux_bairro);
		        fflush(stdin);
		        ag = incluir(ag, aux_email,aux_nome,aux_rua,aux_bairro,aux_ocupacao,numero,cep,telefone,codigo,idade,cpf);
				printf("\n\nDeseja cadastrar mais alguem?\n1-Sim\n2-Nao\n");
				scanf("%d",&op_cad);
				system("cls");
				}while(op_cad!=2);
    	}
    	if(op==2){ //altera dados de um cliente
            system("cls");
    		printf("Escreva um cogigo de um resgistro para realizar a altercao\n");
    		scanf("%d",&codigo_alteracao);
			for(i=0;i<numlin;i++){
				if(ag[i].codigo == codigo_alteracao){ //percorre a estrutura a procura do código digitado
					existe++;
					while(alt_esc != 0){
						printf(" Os dados do registro de codigo %d eh\n",ag[i].codigo);
						printf("(1)  Nome: %s\n",ag[i].nome);
						printf("(2)  Telefone: %d\n",ag[i].telefone);
						printf("(3)  Email: %s\n",ag[i].email);
						printf("(4)  Codigo: %d\n",ag[i].codigo);
						printf("(5)  Idade: %d\n",ag[i].idade);
						printf("(6)  Cpf: %d\n",ag[i].cpf);
						printf("(7)  Ocupacao: %s\n",ag[i].ocupacao);
						printf("     Em relacao a residencia do cliente:\n");
						printf("(8)  Rua: %s\n",ag[i].info.rua);
						printf("(9)  Numero: %d\n",ag[i].info.numero);
						printf("(10) Cep: %d\n",ag[i].info.cep);
						printf("(11) Bairro: %s\n",ag[i].info.bairro);
						printf("\n\nEscreva qual dos dados voce deseja alterar 1-11 ou escreva 0 para encerrar as alteracoes\n");
						scanf("%d",&alt_esc);
						system("cls");
						if(alt_esc==1){
							printf("Novo nome:\n");
							fflush(stdin);
							gets(alt_nome);
					        fflush(stdin);
					        a1++;
						}
						if(alt_esc==2){
							printf("Novo telefone:\n");
							scanf("%d",&alt_telefone);
							a2++;
						}
						if(alt_esc==3){
							printf("Novo email:\n");
							scanf("%s",&alt_email);
							a3++;
						}
						if(alt_esc==4){
							printf("Novo codigo:\n");
							scanf("%d",&alt_codigo);
							a4++;
						}
						if(alt_esc==5){
							printf("Nova idade:\n");
							scanf("%d",&alt_idade);
							a5++;
						}
						if(alt_esc==6){
							printf("novo CPF:\n");
							scanf("%d",&alt_cpf);
							a6++;
						}
						if(alt_esc==7){
							printf("Nova ocupacao:\n");
							fflush(stdin);
							gets(alt_ocupacao);
					        fflush(stdin);
							a7++;
						}
						if(alt_esc==8){
							printf("Nova rua:\n");
							fflush(stdin);
							gets(alt_rua);
					        fflush(stdin);
							a8++;
						}
						if(alt_esc==9){
							printf("Novo numero residencial:\n");
							scanf("%d",&alt_numero);
							a9++;
						}
						if(alt_esc==10){
							printf("Novo CEP:\n");
							scanf("%d",&alt_cep);
							a10++;
						}
						if(alt_esc==11){
							printf("Novo bairro:\n");
							scanf("%s",&alt_bairro);
							a11++;
						}
						if(alt_esc==0){
							end_i = i;
							alt_esc = 1000;
							alterar(ag,end_i,alt_nome,alt_telefone,alt_email,alt_codigo,alt_idade,alt_cpf,alt_ocupacao,alt_rua,alt_numero,alt_cep,alt_bairro,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11);
							system("cls");
							break;
						}
					}
				}
			}
            if(existe==0){
                printf("O codigo nao foi achado\n");
                printf("Aperte uma tecla para voltar ao menu\n");
                system("pause");
                system("cls");
            }
		}
		if(op==4){ //consultar dados de um cliente
		    system("cls");
			printf("Escreva um cogigo de resgistro para realizar a consulta\n");
	    	scanf("%d",&codigo_consulta);
	    	consultar(ag,codigo_consulta);
		}
		if(op==3){ //chama a funcao para excluir os dados de um cliente
		    system("cls");
			printf("Escreva um cogigo de resgistro para realizar a exclusao do mesmo\n");
	    	scanf("%d",&codigo_exclui);
	    	excluir(ag,codigo_exclui);
		}
		if(op==5){ //chama a funcao para listar os registros
		    system("cls");
			listar(ag);
		}
		if(op==6){ //chama a funcao para gravar em arquivo
		    system("cls");
			gravar(ag);
		}
	}
    return 0;
}