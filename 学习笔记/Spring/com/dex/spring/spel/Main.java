package com.dex.spring.spel;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class Main {

	public static void main(String[] args) {
		
		ApplicationContext ctx = new ClassPathXmlApplicationContext("beans-spel.xml");
		
		Address add = (Address) ctx.getBean("address");
		System.out.println(add);
		
		Car car = (Car) ctx.getBean("car");
		System.out.println(car);
		
		Person person = (Person)ctx.getBean("person");
		System.out.println(person);
	}

}
