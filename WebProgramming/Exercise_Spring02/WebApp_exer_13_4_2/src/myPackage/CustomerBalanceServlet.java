package myPackage;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.springframework.context.ApplicationContext;
import org.springframework.web.context.support.WebApplicationContextUtils;

/**
 * Servlet implementation class CustomerBalanceServlet
 */
@WebServlet("/CustomerBalanceServlet")
public class CustomerBalanceServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * @see HttpServlet#HttpServlet()
	 */
	public CustomerBalanceServlet() {
		super();
		// TODO Auto-generated constructor stub
	}

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		ApplicationContext context=WebApplicationContextUtils.
				getRequiredWebApplicationContext(getServletContext());

		CustomerLookup lookupService=(CustomerLookup)context.getBean("customerLookup");

		String id=request.getParameter("customerId");
		String address;
		Customer customer=lookupService.findCustomer(id);
		request.setAttribute("customer", customer);
		
		
		if(customer==null){
			request.setAttribute("id", id);
			address="unknown.jsp";
		}else if(customer.getBalance()<0){
			address="negative.jsp";
		}else if(customer.getBalance()<10000){
			address="normal.jsp";
		}else{
			address="vip.jsp";
		}
			
		address="/WEB-INF/jsp/"+address;
		
		RequestDispatcher dispatcher=request.getRequestDispatcher(address);
		dispatcher.forward(request, response);
	}

}
