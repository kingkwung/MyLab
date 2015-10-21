package mySpring_exer13_3;

import java.util.ArrayList;

public class Employee13_3 {
	private int id;
	private String name;
	private ArrayList<Car13_3> carList;

	public ArrayList<Car13_3> getCarList() {
		return carList;
	}

	public void setCarList(ArrayList<Car13_3> carList) {
		this.carList = carList;
	}

	public Employee13_3(){

	}

	public Employee13_3(int id, String name, ArrayList<Car13_3> carList){
		setId(id);
		setName(name);
		setCarList(carList);
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
		System.out.print("id : " + id +" , " + "name :" + name + " , ");
		for(Car13_3 car : carList){
			System.out.print("("+car.getModel() + "/" + car.getYear() + "/" + car.getMaker()+") ");
		}
		System.out.println();
	}
}
