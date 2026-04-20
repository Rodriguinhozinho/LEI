
// .trocar o fundo com o topo mantendo a ordem original da pilha
PNodoPilha trocarInicioFim(PNodoPilha S){
	if (S == NULL || S ->Prox == NULL) return S;
	PNodoPilha AUX = NULL;
	DadosPilha Topo, Fim;
	Topo = S->Elemento;
	S = pop(S);
	while (S->Prox != NULL){
		AUX = push(S->Elemento,AUX);
		S = pop (S);
	}
	Fim = S->Elemento;
	S = pop(S);
	S = push(topo(Topo),S);
	while ( Aux != NULL){
		S = push(Aux->Elemento,S);
		Aux = pop(Aux);
	}
	S = push(topo(Fim),S);
	return S;
}

//funcao que remove todas as faturas  de um NIF e soma o valor delas
Float RemoverSomarFatura (PNodoPilha *S, int X){
	if (S == NULL) return S;
	PNodoPilha AUX=NULL;
	float soma = 0,0;
	DadosPilha atual;
	while(S->Ant != NULL){
		atual = (*S)->Elemento
		if(S->Elemento.NIF == X){
			soma += *S->Elemento.valor;
			*S = pop(*S);
		}
		else{
			Aux = push ((*S)->Elemento,AUX);
			*S = pop(*S);
	}
	while(AUX != NULL){
		*S=push(AUX->Elemento,S);
		AUX = pop(AUX);
	}
	return soma;				
}

//mover o mais velho para o topo mantenod a ordem original da pilha
PNodoPilha moverVelhoTopo(PNodoPilha S){
	PNodoPilha AUX = NULL;
	DadosPilha velho;
	if(S == NULL || S->Ant == NULL) return S;
	velho = S->Elemento;
	while(S->Ant !=NULL){
		if( S->Elemento.Idade > velho.idade){
			velho = S->Elemento;}
		else{
			AUX = push(S->Elemento,AUX);
			S=pop(S);
	}



//remover todos os impares mantendo os pares na ordem original
PNodoPilha filtrarApenasPares (PNodoPilha S){
	PNodoPilha AUX = NULL;
	while (S!=NULL){
		if(S->Elemento % 2 ==0){
			AUX = push(S->Elemento , AUX);
		}
		S = pop(S);
	}
	while(AUX!=NULL){
		S = push(topo(AUX), S);
		AUX = pop(AUX);
	}
	return S;
}
