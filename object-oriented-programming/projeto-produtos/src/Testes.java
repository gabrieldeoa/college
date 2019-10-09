
public class Testes {

	public static void main(String[] args) {
		ProdutoAlimenticio pa = new ProdutoAlimenticio("Trufa", 5.5, "chocolate");
		ProdutoManufaturado pm = new ProdutoManufaturado("Camisa de Sistemas", 30);
		ProdutoManufaturado pm2 = new ProdutoManufaturado("Casaco de Sistemas", 170);
		ProdutoEtilico pe = new ProdutoEtilico("Cerveja", 10,"Bebidas");
		
		CalculadoraDePrecoDeVendas calculadora = new CalculadoraDePrecoDeVendas();
		calculadora.acumulaValorDosProdutos(pa);//71.5
		calculadora.acumulaValorDosProdutos(pm);//450
		calculadora.acumulaValorDosProdutos(pm2);//2550
		calculadora.acumulaValorDosProdutos(pe);//200
		
		System.out.println("O valor de todos os produtos "
				+ "em estoque é "+calculadora.getTotalDeProdutosEmEstoque());
	}

}
