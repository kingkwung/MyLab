<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Exercise10_1</title>
</head>
<body>
	<H2>Registration</H2>

	<%
		String first_param;
		String second_param;
		String third_param;
		String fourth_param;

		String first_error = "";
		String second_error = "";
		String third_error = "";
		String fourth_error = "";

		first_param = request.getParameter("firstName");
		second_param = request.getParameter("lastName");
		third_param = request.getParameter("eMail");
		fourth_param = request.getParameter("phoneNum");

		if (first_param == null && second_param == null
				&& third_param == null && fourth_param == null) {
			first_param = "";
			second_param = "";
			third_param = "";
			fourth_param = "";
		} else {
			if (first_param == "") {
				first_error = "Enter first name";
			}
			if (second_param == "") {
				second_error = "Enter last name";
			}
			if (third_param == "") {
				third_error = "Enter e-mail";
			}
			if (fourth_param == "") {
				fourth_error = "Enter phone number";
			}
		}
	%>


	<FORM ACTION='http://localhost:8080/myJsp_1113/exer10_1.jsp'>

		<TABLE border='0'>

			<TR>
				<TD><LABEL>First name : </LABEL></TD>
				<TD><INPUT TYPE='TEXT' NAME='firstName' value=<%=first_param%>></TD>
				<TD><font color='red'><%=first_error%></font></TD>
			</TR>

			<TR>
				<TD><LABEL>Last name : </LABEL></TD>
				<TD><INPUT TYPE='TEXT' NAME='lastName' value=<%=second_param%>></TD>
				<TD><font color='red'><%=second_error%></font></TD>
			</TR>

			<TR>
				<TD><LABEL>E-mail : </LABEL></TD>
				<TD><INPUT TYPE='TEXT' NAME='eMail' value=<%=third_param%>></TD>
				<TD><font color='red'><%=third_error%></font></TD>
			</TR>

			<TR>
				<TD><LABEL>Phone number : </LABEL></TD>
				<TD><INPUT TYPE='TEXT' NAME='phoneNum' value=<%=fourth_param%>></TD>
				<TD><font color='red'><%=fourth_error%></font></TD>
			</TR>

		</TABLE>
		<INPUT TYPE='SUBMIT' VALUE='Search' align='center'>
	</FORM>
</body>
</html>