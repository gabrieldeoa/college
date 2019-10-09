
public class ContaPoupanca extends Conta{
	@Override
	public void atualiza(double taxa) {
		this.saldo-=(taxa*3);
	}
	
	public void mostraSaldo(){
		System.out.println("O saldo desta conta é "+this.saldo);
	}
}
