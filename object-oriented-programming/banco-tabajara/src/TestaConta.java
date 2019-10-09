
public class TestaConta {
	public static void main(String[] args) {
		// Conta origem
		Conta conta = new Conta(189, 123, 5000, "Gabriel");
	
		// Conta destino
		Conta outraConta = new Conta("Pedro Cubo");
		outraConta.setAgencia(001);
		outraConta.setNumero(987);

		
		// transferir origem -> destino
		conta.transferePara(outraConta, 1000);
		
		System.out.println("Titular " + conta.getTitular() + ", Saldo: " + conta.getSaldo() );
		
		System.out.println("Titular " + outraConta.getTitular() + ", Saldo: " + outraConta.getSaldo() );
		
		if(!conta.saca(10000))
			System.out.println("Saldo inválido, " + conta.getTitular() + " você possui somente " + conta.getSaldo());
		
		
	}
}
