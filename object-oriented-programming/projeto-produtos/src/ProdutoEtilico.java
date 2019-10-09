
public class ProdutoEtilico extends ProdutoAlimenticio{

	public ProdutoEtilico(String nome, double precoDeCusto, String generoAlimenticio) {
		super(nome, precoDeCusto, generoAlimenticio);
	}
	
	@Override
	double getValorEmMercadoria() {
		return this.estoque * (this.precoDeCusto*2);
	}

}
