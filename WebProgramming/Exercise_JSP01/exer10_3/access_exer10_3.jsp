<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>access_for_exer10_3</title>
</head>
<body>
	<%@ page import="java.util.Date"%>

	<%!int accessCount = 0;
	Date previousDate = null;
	String previousHost = "<i>no previous host<i>";%>


	<%
		previousHost = request.getRemoteHost();
	%>

	<p>
		accessCount :
		<%=accessCount++%></p>
	<p>
		prevDate :
		<%=previousDate%></p>
	<p>
		prevHost :
		<%=previousHost%></p>

	<%
		previousDate = new Date();
	%>
</body>
</html>