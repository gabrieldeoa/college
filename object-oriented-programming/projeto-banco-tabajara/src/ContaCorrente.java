
public class ContaCorrente extends Conta{
	@Override
	public void atualiza(double taxa) {
		this.saldo-=(taxa*2);
	}
	
	@Override
	public boolean deposita(double valor) {
		if (this.validaDeposito(valor)) {
			this.saldo += valor;
			this.saldo-=0.10;
			return true;
		}
		return false;
	}
}
