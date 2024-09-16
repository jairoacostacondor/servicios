package practica0;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Usuario {
	
	//Atributos

	private String idUsuario;
	private String nombre;
	private String telefono;
	private String email;
	private List<Prestamo>prestamos = new ArrayList<Prestamo>();
	
	//Constructors	
	public Usuario(String idUsuario, String nombre, String telefono, String email, List<Prestamo> prestamos) {
		super();
		this.idUsuario = idUsuario;
		this.nombre = nombre;
		this.telefono = telefono;
		this.email = email;
		this.prestamos = prestamos;
	}
	
	
	//Getters & Setters
	
	
	public String getIdUsuario() {
		return idUsuario;
	}



	public void setIdUsuario(String idUsuario) {
		this.idUsuario = idUsuario;
	}



	public String getNombre() {
		return nombre;
	}



	public void setNombre(String nombre) {
		this.nombre = nombre;
	}



	public String getTelefono() {
		return telefono;
	}



	public void setTelefono(String telefono) {
		this.telefono = telefono;
	}



	public String getEmail() {
		return email;
	}



	public void setEmail(String email) {
		this.email = email;
	}



	public List<Prestamo> getPrestamos() {
		return prestamos;
	}



	public void setPrestamos(List<Prestamo> prestamos) {
		this.prestamos = prestamos;
	}



	//Extra Methods
	public void registrar() {
		Scanner teclado=new Scanner(System.in);
		
		System.out.println("Introduce el idUsuario");
		idUsuario = teclado.nextLine();
		
		System.out.println("Introduce el nombre");
		nombre = teclado.nextLine();
		
		System.out.println("Introduce el telefono");
		telefono = teclado.nextLine();
		
		System.out.println("Introduce el email");
		email = teclado.nextLine();
		
	}

	

	public void actualizarInfo(String nombre, String telefono, String email) {
		this.nombre=nombre;
		this.telefono=telefono;
		this.email=email;
	}
	public void consultarPrestamos() {
	for(int i=0; i<prestamos.size(); i++) {
		System.out.println(prestamos.get(i));
	}
		
	}
	
	
	
	

	
}
