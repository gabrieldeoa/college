
public class CalculadoraDePrecoDeVendas {
	private double totalDeProdutosEmEstoque=0;

	public void acumulaValorDosProdutos(Produto p){
		this.totalDeProdutosEmEstoque += p.getValorEmMercadoria();
	}
	
	public double getTotalDeProdutosEmEstoque() {
		return totalDeProdutosEmEstoque;
	}
}
