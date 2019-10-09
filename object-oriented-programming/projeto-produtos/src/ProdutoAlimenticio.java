
public class ProdutoAlimenticio extends Produto{
	private String generoAlimenticio;

	//Construtor
	public ProdutoAlimenticio(String nome,double precoDeCusto, String generoAlimenticio) {
		super(nome,precoDeCusto);
		this.generoAlimenticio = generoAlimenticio;
	}
	//get e set
	public String getGeneroAlimenticio() {
		return generoAlimenticio;
	}
	public void setGeneroAlimenticio(String generoAlimenticio) {
		this.generoAlimenticio = generoAlimenticio;
	}
	@Override
	double getValorEmMercadoria() {
		return this.estoque * (this.precoDeCusto*1.3);
	}
}
