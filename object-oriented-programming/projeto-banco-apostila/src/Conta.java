
public class Conta {
	protected double saldo, limite;
	protected Cliente cliente;
	
	public Conta() {
		this.cliente = new Cliente();
	}
	
	public double getLimite() {
		return limite;
	}



	public void setLimite(double limite) {
		this.limite = limite;
	}



	public double getSaldo() {
		return saldo;
	}



	public Cliente getCliente() {
		return cliente;
	}


	public boolean deposita(double valor) {
		if(valor >0) {
			this.saldo += valor;
			return true;
		}
		
		return false;			
	}
	
	public boolean saca(double valor) {
		if(valor > 0 && valor <= (this.saldo + this.limite)) {
			this.saldo -= valor;
			return true;
		}
		
		return false;
	}
	
	public boolean transferePara(Conta contaDestino, double valor) {
		Conta contaOrigem = this;
		if(contaOrigem.saca(valor)) {
			return contaDestino.deposita(valor);
		}
		
		return false;
	}
	
	protected void atualiza(double taxa) {
		this.saldo -= taxa;
	}
}
