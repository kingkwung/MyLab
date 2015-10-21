

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Enumeration;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class exer02_1106
 */
@WebServlet("/exer02_1106")
public class exer02_1106 extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * @see HttpServlet#HttpServlet()
	 */
	public exer02_1106() {
		super();
		// TODO Auto-generated constructor stub
	}

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		PrintWriter out = response.getWriter();

		String bg_color = "navy";
		String ft_color = "white";

		Enumeration<String> headerNames = request.getHeaderNames();
		while(headerNames.hasMoreElements()){
			String name = (String)headerNames.nextElement();
			String cname = name.substring(0,1).toUpperCase() +name.substring(1);
			if(cname.equalsIgnoreCase("User-agent")){
				if(request.getHeader(name).contains("MSIE")){
					bg_color = "yellow";
					ft_color = "red";
					break;
				}
			}
		}
		out.println( "<!DOCTYPE html>\n" +
				"<html>\n" +
				"<head><title>Exercise 9.2</title></head>\n" +
				"<body>" + 
				"<body text='" + ft_color + "' bgcolor='" + bg_color + "'>" + 
				"<H1>Hello!</H1>" + 
				"<H2>Hello!</H2>" + 
				"<H3>Hello!</H3>" + 
				"</body></html>");
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
	}

}
