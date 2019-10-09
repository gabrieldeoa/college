
public class Data {
	private String dia;
	private String mes;
	private String ano;
	
	public Data() {
	}
	
	public Data(String dia, String mes, String ano) {
		this.dia = dia;
		this.mes = mes;
		this.ano = ano;
	}
	
	public String getDia() {
		return dia;
	}
	public void setDia(String dia) {
		this.dia = dia;
	}
	public String getMes() {
		return mes;
	}
	public void setMes(String mes) {
		this.mes = mes;
	}
	public String getAno() {
		return ano;
	}
	public void setAno(String ano) {
		this.ano = ano;
	}
	
	public String getDataFormatoBrasileiro() {
		return this.dia + "/" + this.mes + "/" + this.ano;
	}
	
	
}
