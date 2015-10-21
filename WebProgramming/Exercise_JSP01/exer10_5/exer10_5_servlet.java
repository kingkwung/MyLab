package pack_exer10_5;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class exer10_5_servlet
 */
@WebServlet("/exer10_5_servlet")
public class exer10_5_servlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public exer10_5_servlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		
		
		String stateFullName = request.getParameter("stateName");
		exer10_5_lookup lookup = new exer10_5_lookup();
		String result = lookup.findAbbrev(stateFullName);
		
		
		String address;
		
		request.setAttribute("stateFullName", stateFullName);
		if(result==null){ // result���� null �� ��� 
			if(stateFullName.equalsIgnoreCase("")){
				//�ٵ� input���� �� ���� ��� 
				address = "empty_exer10_5.jsp";
				//System.out.println("no input! / "  + result);
			}
			else{
				//input ���� �ִµ� ������ ���� ���
				address = "noInform_exer10_5.jsp";
				//System.out.println("no information! / "  + result);
			}
		}
		else{
			//�� ã�� ���
			address = "find_exer10_5.jsp";
			//System.out.println("find! / " + result);
			
			exer10_5_bean pair= new exer10_5_bean();
			pair.setStateFull(stateFullName);
			pair.setStateAbbrev(result);
			
			request.setAttribute("find", pair);
			
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
