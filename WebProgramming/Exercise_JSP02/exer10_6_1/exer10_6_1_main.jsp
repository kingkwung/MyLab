<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Exercise10_6</title>
</head>
<body>
	<H2>Registration</H2>


	<FORM ACTION='http://localhost:8089/myEL_1120/exer10_6_1_servlet'>

		<TABLE border='0'>

			<TR>
				<TD><LABEL>First name : </LABEL></TD>
				<TD><INPUT TYPE='TEXT' NAME='firstName' value='${firstName}'></TD>
				<TD><font color='red'>${firstError}</font></TD>
			</TR>

			<TR>
				<TD><LABEL>Last name : </LABEL></TD>
				<TD><INPUT TYPE='TEXT' NAME='lastName' value='${secondName}'></TD>
				<TD><font color='red'>${secondError}</font></TD>
			</TR>

			<TR>
				<TD><LABEL>E-mail : </LABEL></TD>
				<TD><INPUT TYPE='TEXT' NAME='eMail' value='${email}'></TD>
				<TD><font color='red'>${emailError}</font></TD>
			</TR>

			<TR>
				<TD><LABEL>Phone number : </LABEL></TD>
				<TD><INPUT TYPE='TEXT' NAME='phoneNum' value='${phone}'></TD>
				<TD><font color='red'>${phoneError}</font></TD>
			</TR>

		</TABLE>
		<INPUT TYPE='SUBMIT' VALUE='Search' align='center'>
	</FORM>
</body>
</html>