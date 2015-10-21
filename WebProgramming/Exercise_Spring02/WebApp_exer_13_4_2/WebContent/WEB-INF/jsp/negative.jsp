<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
<ul>
<h2>Your Account is negative..</h2>
	<li>ID: ${customer.id}</li>
	<li>First name: ${customer.firstName}</li>
	<li>Last name: ${customer.lastName}</li>  
	<li>Balance: $ ${customer.balance}</li>
</ul>
</body>
</html>