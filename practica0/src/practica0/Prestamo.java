package practica0;

public class Prestamo {
	
	//Atributos
	private String idPréstamo;
	private int fechaPréstamo;
	private int fechaDevolucion;
	
	//Constructors
	public Prestamo(String idPréstamo, int fechaPréstamo, int fechaDevolucion) {
		super();
		this.idPréstamo = idPréstamo;
		this.fechaPréstamo = fechaPréstamo;
		this.fechaDevolucion = fechaDevolucion;
	}
	
	//Getters & Setters

	public String getIdPréstamo() {
		return idPréstamo;
	}

	public void setIdPréstamo(String idPréstamo) {
		this.idPréstamo = idPréstamo;
	}

	public int getFechaPréstamo() {
		return fechaPréstamo;
	}

	public void setFechaPréstamo(int fechaPréstamo) {
		this.fechaPréstamo = fechaPréstamo;
	}

	public int getFechaDevolucion() {
		return fechaDevolucion;
	}

	public void setFechaDevolucion(int fechaDevolucion) {
		this.fechaDevolucion = fechaDevolucion;
	}
	
	
	
	
	
	

}
