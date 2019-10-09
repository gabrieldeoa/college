public class Conta {
	// Atributos
	protected int agencia; // get e set
	protected int numero; // get e set
	protected Cliente titular;// = new Cliente(); //get e set
	protected double saldo; // get
	protected static int contador = 0;
	
	public void atualiza(double taxa){
		this.saldo-=taxa;
	}

	public Cliente getTitular() {
		return titular;
	}

	public void setTitular(Cliente titular) {
		this.titular = titular;
	}

	public static int getContador() {
		return Conta.contador;
	}

	public Conta(int agencia, int numero, double saldo) {
		//this();
		this();
		//this.titular = new Cliente();
		this.agencia = agencia;
		this.numero = numero;
		this.saldo = saldo;
		//Conta.contador++;
	}

	public Conta(Cliente titular) {
		this.titular = titular;
		Conta.contador++;
	}

	public Conta() {
		this.titular = new Cliente();
		this.contador++;
	}

	// Métodos acessórios (get e set)
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

	public double getSaldo() {
		return saldo;
	}

	// Comportamento
	public boolean transferePara(Conta contaDestino, double valor) {
		if (this.saca(valor) == true) {
			if (contaDestino.deposita(valor) == true) // vai retornar true
				return true;
			else
				return false;
		} else {
			return false;
		}
	}

	protected boolean validaDeposito(double valor) {
		if (valor >= 0)
			return true;
		return false;
	}

	public boolean deposita(double valor) {
		if (this.validaDeposito(valor)) {
			this.saldo += valor;
			return true;
		}
		return false;
	}

	public boolean saca(double valor) {// assinatura
		if (valor > 0 && valor <= this.saldo) {
			this.saldo -= (valor + 0.01);
			return true;
		} else
			return false;
	}

}
