package mySpring_exer13_1;

public class employee {
	private int id;
	private String name;
		
	public employee(){
		
	}
	
	public employee(int id, String name){
		setId(id);
		setName(name);
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}
	
	public void printInfo(){
		System.out.println("id : " + id +" / " + "name :" + name);
	}
}
