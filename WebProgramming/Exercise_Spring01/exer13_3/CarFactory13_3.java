package mySpring_exer13_3;

import java.util.ArrayList;
import java.util.Map;
import java.util.TreeMap;

import mySpring_exer13_2.Car;

public class CarFactory13_3 {
	private static Map<String, String> matching = new TreeMap<String,String>(String.CASE_INSENSITIVE_ORDER);
	//map채워주어야함 1)사용자가 기존에 입력한 것을 저장시켜주는 방법이던지.. 2)내가 그냥 파워코딩으로 입력시켜놓는 것이든지.. 
	
	public static ArrayList<Car13_3> madeCar(Map<String, String> modelYearPair){
		initMap();
		ArrayList<Car13_3> carList = new ArrayList<Car13_3>();
		
		for(String key : modelYearPair.keySet()){
			carList.add(new Car13_3(key, Integer.parseInt(modelYearPair.get(key)), findMaker(key)));
		}
		
		return carList;
	}
	public static Car madeCar(String model, int year, String maker){
		return new Car(model, year, maker);
	}
	
	public static Car madeCar(String model, int year){
		initMap();
		return new Car(model, year, findMaker(model));
	}
	
	public static String findMaker(String model){
		initMap();
		return matching.get(model);
	}
	
	public static void initMap(){
		matching.put("Sonata", "Hyundai");
		matching.put("Santafe", "Hyundai");
		matching.put("Starex", "Hyundai");
		matching.put("Accent", "Hyundai");
		matching.put("Avante", "Hyundai");
		matching.put("Grandure", "Hyundai");
		matching.put("Genesis", "Hyundai");
		matching.put("Equus", "Hyundai");
		
		matching.put("Ray", "Kia");
		matching.put("Soul", "Kia");
		matching.put("Sorento", "Kia");
		matching.put("Carnival", "Kia");
		matching.put("Morning", "Kia");
		matching.put("Pride", "Kia");
		matching.put("k5", "Kia");

		matching.put("sm3", "Samsung");
		matching.put("sm5", "Samsung");
		matching.put("sm7", "Samsung");
		matching.put("qm5", "Samsung");

		matching.put("Korando", "Ssangyong");
		matching.put("Chairman", "Ssangyong");
		matching.put("Rexton", "Ssangyong");

	}
	
}
