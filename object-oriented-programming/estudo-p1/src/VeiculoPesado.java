
public class VeiculoPesado extends Veiculo{
	private int quantidadeDeEixos;
	private final double VALOR_POR_EIXO = 20.0;
	
	//construtor
	public VeiculoPesado(String modelo) {
		super(modelo);
	}
	
	//setters
	public void setQuantidadeDeEixos(int quantidadeDeEixos) { this.quantidadeDeEixos = quantidadeDeEixos; }
	
	//getters
	public int getQuantidadeDeEixos() { return this.quantidadeDeEixos; }
	
	//reescrita - no caso o da super classe nao tem implementação e delegou pras filhas implementarem
	public double getGastosComImpostos() {
		return ((this.valorDeMercado * 0.20) + this.obterAdicionalPorEixos());
	}
	
	//auxiliares
	private double obterAdicionalPorEixos() {
		return (this.quantidadeDeEixos * VALOR_POR_EIXO);
	}
}
