package com.dex.spring.beans;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class Main {
	
	public static void main(String[] args) {
		
		//浼犵粺鏂规硶
		HelloWorld hello = new HelloWorld();
		hello.setName("youcaihua");
		hello.hello();
		
		//1.鍒涘缓spring鐨処OC瀹瑰櫒瀵硅薄
		//ApplicationContext浠ｈ〃IOC瀹瑰櫒
		//ClassPathXmlApplicationCOntext鏄疉pplicationContxt鐨勬帴鍙ｅ疄鐜扮被
		ApplicationContext ctx = new ClassPathXmlApplicationContext("ApplicationContext.xml");
		
		//2.浠嶪OC瀹瑰櫒涓幏鍙朆ean瀹炰緥
		//鍒╃敤ID瀹氫綅鍒癐OC瀹瑰櫒涓殑bean
		HelloWorld hello2 = (HelloWorld)ctx.getBean("helloWorld");
		
		//鍒╃敤绫诲瀷杩斿洖IOC瀹瑰櫒涓殑Bean锛屼絾瑕佹眰IOC瀹瑰櫒涓繀椤诲彧鑳芥湁涓�釜璇ョ被鍨嬬殑Bean
		//HelloWorld hell = ctx.getBean(HelloWorld.class);
		
		hello2.hello();
		
		
		Car car = (Car)ctx.getBean("car");
		System.out.println("\r\n" + car);
		
		Car car2 = (Car)ctx.getBean("car2");
		System.out.println("\r\n" + car2);
		
		Car car3 = (Car)ctx.getBean("car2");
		System.out.println("\r\n" + car3);
		
		Person per =(Person)ctx.getBean("person");
		System.out.println("\r\n" + per);
		
		Person per2 =(Person)ctx.getBean("person2");
		System.out.println("\r\n" + per2);
	}
	
}
