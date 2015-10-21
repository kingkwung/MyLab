package mySpring_exer13_2;

import mySpring_exer13_1.employee;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class CarMain {
	public static void main(String[] args){
		ApplicationContext context = new ClassPathXmlApplicationContext("/applicationContext_exer13_2.xml");

		Car car1 = (Car)context.getBean("car1");
		Car car2 = (Car)context.getBean("car2");
		Car car3 = (Car)context.getBean("car3");
		Car car4 = (Car)context.getBean("car4");
		
		
		car1.printInfo();
		car2.printInfo();
		car3.printInfo();
		car4.printInfo();
	}
}
