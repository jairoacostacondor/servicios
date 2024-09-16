package practica0;

public class Libro {
	
	//Atributos
	private String isbn;
	private String titulo;
	private String autor;
	private int anioPublicacion;
	private boolean disponible;
	
	//Constructors	
	public Libro(String isbn, String titulo, String autor, int anioPublicacion, boolean disponible) {
		super();
		this.isbn = isbn;
		this.titulo = titulo;
		this.autor = autor;
		this.anioPublicacion = anioPublicacion;
		this.disponible = true;
	}
	
	//Getters & Setters

	public String getIsbn() {
		return isbn;
	}

	public void setIsbn(String isbn) {
		this.isbn = isbn;
	}

	public String getTitulo() {
		return titulo;
	}

	public void setTitulo(String titulo) {
		this.titulo = titulo;
	}

	public String getAutor() {
		return autor;
	}

	public void setAutor(String autor) {
		this.autor = autor;
	}

	public int getAnioPublicacion() {
		return anioPublicacion;
	}

	public void setAnioPublicacion(int anioPublicacion) {
		this.anioPublicacion = anioPublicacion;
	}

	public boolean isDisponible() {
		return disponible;
	}

	public void setDisponible(boolean disponible) {
		this.disponible = disponible;
	}
	
	//Extra Methods
	
	 public void prestamo() {
	        if (disponible) {
	            disponible = false;
	            System.out.println("El libro " + titulo + " ha sido prestado.");
	        } else {
	            System.out.println("El libro " + titulo + " no está disponible para préstamo.");
	        }
	    }

	    public void devolucion() {
	        if (!disponible) {
	            disponible = true;
	            System.out.println("El libro " + titulo + " ha sido devuelto.");
	        } else {
	            System.out.println("El libro " + titulo + " ya estaba disponible.");
	        }
	    }

	    public String informacion() {
	        return "ISBN: " + isbn + ", Título: " + titulo + ", Autor: " + autor + ", Año de Publicación: " + anioPublicacion +
	                ", Disponible: " + (disponible ? "Sí" : "No");
	    }
	
	
	

	
	

}
