package pack_10_6;

import java.io.IOException;
import java.util.Enumeration;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class exer10_6_2_servlet
 */
@WebServlet("/exer10_6_2_servlet")
public class exer10_6_2_servlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       exer10_6_2_bean bean = null;
    /**
     * @see HttpServlet#HttpServlet()
     */
    public exer10_6_2_servlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		
		if(bean == null){
			bean = new exer10_6_2_bean();
		}
		
		Enumeration<String> headerNames = request.getHeaderNames();
		
		while(headerNames.hasMoreElements()){
			String name = (String)headerNames.nextElement();
			String cname = name.substring(0,1).toUpperCase() + name.substring(1);
			
			bean.setHeaderName(cname);
			bean.setHeaderValue(request.getHeader(name));
		}
		
		ServletContext application = getServletContext();
		application.setAttribute("bean", bean);
		
		RequestDispatcher dispatcher = request.getRequestDispatcher("exer10_6_2_result.jsp");
		dispatcher.forward(request, response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
	}

}
