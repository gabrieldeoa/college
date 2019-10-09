
public class Conta {
	private int agencia;
	private int numero;
	private String titular;
	private double saldo;
	
	public Conta() {}
	
	public Conta(String titular) {
		this.titular = titular;
	}
	
	public Conta(int agencia, int numero, int saldo, String titular) {
		this(titular);
		this.agencia = agencia;
		this.numero = numero;
		this.saldo = saldo;
	}


	public int getAgencia() {
		return agencia;
	}

	public void setAgencia(int agencia) {
		this.agencia = agencia;
	}

	public int getNumero() {
		return numero;
	}

	public void setNumero(int numero) {
		this.numero = numero;
	}

	public String getTitular() {
		return titular;
	}

	public void setTitular(String titular) {
		this.titular = titular;
	}

	public double getSaldo() {
		return saldo;
	}
	
	public boolean transferePara(Conta contaDestino, double valor) {
		 return (this.saca(valor)) ? contaDestino.deposita(valor) : false;
	}
	
	private boolean validaDeposito(double valor) {
		return (valor <= 0) ? false : true;
	}
	
	public boolean deposita(double valor) {
		if(! this.validaDeposito(valor))
			return false;
		
		this.saldo += valor;
		return true;
		
	}
	
	public boolean saca(double valor) {
		if(valor <= 0 || valor > this.saldo) return false;
		
		this.saldo -= valor;
		
		return true;
	}
	
}
