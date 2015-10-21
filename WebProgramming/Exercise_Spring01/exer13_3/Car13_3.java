package mySpring_exer13_3;

public class Car13_3 {
	private String model;
	private int year;
	private String maker;

	public Car13_3(){

	}

	public Car13_3(String model, int year, String maker){
		setModel(model);
		setYear(year);
		setMaker(maker);
	}

	public void printInfo(){
		System.out.println("model : " + model +" / " + "year :" + year + " / " + "maker : " + maker);
	}

	public String getModel() {
		return model;
	}

	public void setModel(String model) {
		this.model = model;
	}

	public int getYear() {
		return year;
	}

	public void setYear(int year) {
		this.year = year;
	}

	public String getMaker() {
		return maker;
	}

	public void setMaker(String maker) {
		this.maker = maker;
	}
}
