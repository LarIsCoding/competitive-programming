int MAXN = 100;
int bit[MAXN][MAXN]; // vetor que guarda as posições da BIT

int sum(int x, int y){
		
	// resposta começa com valor zero
	int resp=0;
	
	// percorro as linhas da BIT que representam as linhas desejadas
	for(int i=x;i>0;i-=i&-i){
		
		// e dentro da BIT que representa as linhas que estou percorrendo
		// uso o mesmo algoritmo para somar apenas as colunas que me interessam
		for(int j=y;j>0;j-=j&-j){
			
			// somando o valor de cada uma delas a resp
			resp+=bit[i][j];
		}
	}
	
	// por fim, retorno resposta
	return resp;
}

void update(int x, int y, int delta){
		
	// percorro as linhas da BIT que representam as linhas desejadas
	for(int i=x;i<MAXN;i+=i&-i){
		
		// e dentro da BIT que representa as linhas que estou percorrendo
		// uso o mesmo algoritmo para acessar apenas as colunas que me interessam
		for(int j=y;j<MAXN;j+=j&-j){
			
			// somando o valor de delta a cada uma delas
			bit[i][j]+=delta;
		}
	}
}
