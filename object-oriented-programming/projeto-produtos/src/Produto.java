
public abstract class Produto {
	protected String nome;
	protected double precoDeCusto;
	protected Fornecedor fornecedorDoProduto;
	protected int estoque = 10;
	
	public Produto(String nome, double precoDeCusto) {
		this.nome = nome;
		this.precoDeCusto = precoDeCusto;
		this.fornecedorDoProduto = new Fornecedor();
	}
	
	public Produto(String nome) {
		this.nome = nome;
		this.fornecedorDoProduto = new Fornecedor();
	}
	
	abstract double getValorEmMercadoria(); 
	
	public int getEstoque() {
		return estoque;
	}

	public void setEstoque(int estoque) {
		this.estoque = estoque;
	}

	public Fornecedor getFornecedorDoProduto() {
		return fornecedorDoProduto;
	}
	
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	public double getPrecoDeCusto() {
		return precoDeCusto;
	}
	public void setPrecoDeCusto(double precoDeCusto) {
		this.precoDeCusto = precoDeCusto;
	}

	
}
