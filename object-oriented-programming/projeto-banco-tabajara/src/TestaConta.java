public class TestaConta {
	public static void main(String[] args) {
		//Conta da Heloíse
		Conta umaConta;
		umaConta = new Conta("Heloíse");
		umaConta.setNumero(123);
		umaConta.setAgencia(456);
		umaConta.deposita(5000);
		//Conta do MestreDosMagos
		Conta outraConta = new Conta(456,789,50,"Hítallo, mestre dos magos");
		
		//Transferencia (Helíse p/ Hítalo)
		umaConta.transferePara(outraConta,3000);

		System.out.println("Titular: "+umaConta.getTitular()
				+" - saldo: "+umaConta.getSaldo());
		
		System.out.println("Titular: "+outraConta.getTitular()
		+" - saldo: "+outraConta.getSaldo());
		
		if(! umaConta.saca(2001) )
			System.out.println(umaConta.getTitular()+ " você possui míseros "
		+umaConta.getSaldo()+" reais em conta");
		
		//mostrando sobrecarga
		System.out.println(OperacoesMatematicas.soma(5.7, 4));//3 (9.7)
		System.out.println(OperacoesMatematicas.soma(5, 4));//1 (9)
		System.out.println(OperacoesMatematicas.soma(5,4,(int) 3.5));//2 (12)
		
	}
}
