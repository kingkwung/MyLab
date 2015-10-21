package pack_10_6;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class exer10_6_servlet
 */
@WebServlet("/exer10_6_1_servlet")
public class exer10_6_1_servlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * @see HttpServlet#HttpServlet()
	 */
	public exer10_6_1_servlet() {
		super();
		// TODO Auto-generated constructor stub
	}

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		String firstName = request.getParameter("firstName");
		String secondName = request.getParameter("lastName");
		String email = request.getParameter("eMail");
		String phone = request.getParameter("phoneNum");

		String firstError = "";
		String secondError = "";
		String emailError = "";
		String phoneError = "";

		String address = "exer10_6_1_main.jsp";

		if(firstName==null && secondName==null && email==null&&phone==null){
			firstName="";
			secondName="";
			email="";
			phone="";
		}
		else{
			if(firstName.equals("")){
				firstError="Input the first name";
			}
			if(secondName.equals("")){
				secondError="Input the second name";
			}
			if(email.equals("")){
				emailError = "Input the email";
			}
			if(phone.equals("")){
				phoneError = "Input the phone number";
			}
		}
		request.setAttribute("firstName", firstName);
		request.setAttribute("secondName", secondName);
		request.setAttribute("email", email);
		request.setAttribute("phone", phone);

		request.setAttribute("firstError", firstError);
		request.setAttribute("secondError", secondError);
		request.setAttribute("emailError", emailError);
		request.setAttribute("phoneError", phoneError);

		if(!firstName.equals("") && !secondName.equals("") && !email.equals("") && !phone.equals("")){

			address = "exer10_6_1_result.jsp";
		}


		RequestDispatcher dispatcher = request.getRequestDispatcher(address);
		dispatcher.forward(request, response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
	}

}
