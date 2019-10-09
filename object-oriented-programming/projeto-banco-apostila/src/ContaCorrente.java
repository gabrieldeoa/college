
public class ContaCorrente extends Conta{
	
	protected void atualiza(double taxa) {
		this.saldo -= (taxa*2);
	}
	
	public boolean saca(double valor) {
		if(valor > 0 && valor <= (this.saldo + this.limite)) {
			this.saldo -= valor - 0.10;
			return true;
		}
		
		return false;
	}
}
