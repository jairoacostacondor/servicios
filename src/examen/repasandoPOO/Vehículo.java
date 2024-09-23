package examen.repasandoPOO;

public  abstract class Vehículo {
	//Atributos
	
	private String marca;
	private String modelo;
	private int año;
	private Persona propietario;
	
	//Constructors	
	
	public Vehículo(String marca, String modelo, int año, Persona propietario) {
		super();
		this.marca = marca;
		this.modelo = modelo;
		this.año = año;
		this.propietario = propietario;
	}
	
	//Getters & Setters

	public String getMarca() {
		return marca;
	}

	public void setMarca(String marca) {
		this.marca = marca;
	}

	public String getModelo() {
		return modelo;
	}

	public void setModelo(String modelo) {
		this.modelo = modelo;
	}

	public int getAño() {
		return año;
	}

	public void setAño(int año) {
		this.año = año;
	}

	public Persona getPropietario() {
		return propietario;
	}

	public void setPropietario(Persona propietario) {
		this.propietario = propietario;
	}
	
	//Extra methods
	
	public abstract void numeroPuertas();
	public abstract void capacidadCarga();
	
	
	

	
	

}
