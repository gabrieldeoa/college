
public class ProdutoManufaturado extends Produto{

	public ProdutoManufaturado(String nome, double precoDeCusto) {
		super(nome, precoDeCusto);
	}

	@Override
	double getValorEmMercadoria() {
		return this.estoque * (this.precoDeCusto*1.5);
	}

}
