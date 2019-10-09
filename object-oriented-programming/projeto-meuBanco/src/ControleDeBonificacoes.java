
public class ControleDeBonificacoes {
	private double totalDeBonificacoes=0;
	
	public void acumula(Funcionario f){
		this.totalDeBonificacoes += f.getBonificacao();
	}

	public double getTotalDeBonificacoes() {
		return totalDeBonificacoes;
	}
}
