

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class exer01_1106
 */
@WebServlet("/exer01_1106")
public class exer01_1106 extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public exer01_1106() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		String first_param = request.getParameter("firstName");
		String second_param = request.getParameter("lastName");
		String third_param = request.getParameter("eMail");
		String fourth_param = request.getParameter("phoneNum");
		
		//response.setContentType("text/html");
		PrintWriter out = response.getWriter();

		String first_error="";
		String second_error="";
		String third_error="";
		String fourth_error="";

		if(first_param==""){
			first_error = "Enter first name";
		}
		if(second_param==""){
			second_error = "Enter last name";
		}
		if(third_param==""){
			third_error = "Enter e-mail";
		}
		if(fourth_param==""){
			fourth_error = "Enter phone number";
		}


		if(first_param==null && second_param==null && third_param==null && fourth_param==null){
			out.println(
					"<!DOCTYPE html>\n" +
							"<html>\n" +
							"<head><title>Exercise 9.1</title></head>\n" +
							"<body><H2>Registration</H2>" + 
							"<FORM ACTION='http://localhost:8080/myServlet/exer01_1106'>" + 
							"<TABLE border='0'>" + 
							"<TR><TD>" + 
							"<LABEL>First name : </LABEL></TD><TD><INPUT TYPE='TEXT' NAME='firstName'></TD></TR>" + 
							"<TR><TD>" + 
							"<LABEL>Last name : </LABEL></TD><TD><INPUT TYPE='TEXT' NAME='lastName'></TD></TR>" +
							"<TR><TD>" + 
							"<LABEL>E-mail : </LABEL></TD><TD><INPUT TYPE='TEXT' NAME='eMail'></TD></TR>" + 
							"<TR><TD>" + 
							"<LABEL>Phone number : </LABEL></TD><TD><INPUT TYPE='TEXT' NAME='phoneNum'></TD></TR>" + 
							"</TABLE>" + 							
							"<INPUT TYPE='SUBMIT' VALUE='Search' align='center'>" +
							"</FORM>\n" +
							"</body></html>"
					);
		}

		else{
			out.println(
					"<!DOCTYPE html>\n" +
							"<html>\n" +
							"<head><title>Exercise 9.1</title></head>\n" +
							"<body><H2>Registration</H2>" + 
							"<FORM ACTION='http://localhost:8080/myServlet/exer01_1106'>" + 
							"<TABLE border='0'>" + 
							"<TR><TD>" + 
							"<LABEL>First name : </LABEL></TD><TD><INPUT TYPE='TEXT' NAME='firstName' value='"+first_param+"'></TD><TD><font color='red'>"+first_error+"</font></TD></TR>" + 
							"<TR><TD>" + 
							"<LABEL>Last name : </LABEL></TD><TD><INPUT TYPE='TEXT' NAME='lastName' value='"+second_param+"'></TD><TD><font color='red'>"+second_error+"</font></TD></TR>" +
							"<TR><TD>" + 
							"<LABEL>E-mail : </LABEL></TD><TD><INPUT TYPE='TEXT' NAME='eMail' value='"+third_param+"''></TD><TD><font color='red'>"+third_error+"</font></TD></TR>" + 
							"<TR><TD>" + 
							"<LABEL>Phone number : </LABEL></TD><TD><INPUT TYPE='TEXT' NAME='phoneNum' value='"+fourth_param+"'></TD><TD><font color='red'>"+fourth_error+"</font></TD></TR>" + 
							"</TABLE>" + 
							"<INPUT TYPE='SUBMIT' VALUE='Search' align='center'>" +
							"</FORM>\n" +
							"</body></html>"
					);
		}
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
	}

}
